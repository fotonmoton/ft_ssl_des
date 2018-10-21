#include "tests.h"
#include "ft_md5.h"
#include "libft.h"

TEST_RESULT should_init_ctx(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);
    t_md5_ctx ctx;

    ft_md5_init(&ctx);

	munit_assert_uint(ctx.a, ==, 0x67452301);
	munit_assert_uint(ctx.b, ==, 0xefcdab89);
    munit_assert_uint(ctx.c, ==, 0x98badcfe);
    munit_assert_uint(ctx.d, ==, 0x10325476);
    munit_assert_true(ctx.bit_len == 0);
    for (int i = 0; i < 64; i++)
        munit_assert_uchar(ctx.block[i], ==, 0);

    return MUNIT_OK;
}

TEST_RESULT decode_string_to_int(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);

    BYTE1 block[FT_MD5_BLOCK_SIZE];
    BYTE4 words[FT_MD5_WORDS_COUNT];

    ft_bzero(block, FT_MD5_BLOCK_SIZE);
    block[0] = 'a';
    block[9] = 'b';
    block[63] = 'c';

    ft_md5_decode(words, block);

    munit_assert_true((words[0] & 0xff) == 97);
    munit_assert_true(((words[2] >> 8) & 0xff) == 98);
    munit_assert_true(((words[15] >> 24) & 0xff) == 99);

    return MUNIT_OK;
}

TEST_RESULT update_should_change_count(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);
    t_md5_ctx ctx;
    char message[] = "hello, World!";
    BYTE8 size = ft_strlen(message);

    ft_md5_init(&ctx);
    ft_md5_update(&ctx, (BYTE1 *)message, size);

    munit_assert_true(size * 8 == ctx.bit_len);

    return MUNIT_OK;
}

TEST_RESULT encode_bits_to_string(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	BYTE8 len;
	BYTE1 bits[FT_MD5_MESSAGE_LENGTH_BYTE];

	/*
		1111 0000 : 63 - 56
		0000 0000 : 55 - 48
		0000 0000 : 47 - 40
		0000 0000 : 39 - 32
		0000 0000 : 31 - 24
		0000 0000 : 23 - 16
		0110 0000 : 15 - 8
		1001 0000 : 7  - 0
	*/
	len = 17293822569102729360U;

	ft_md5_encode_len(bits, len);

	munit_assert_true(bits[7] == (BYTE1)((len >> 56) & 0xff));
	munit_assert_true(bits[0] == (BYTE1)(len & 0xff));
	munit_assert_true(bits[1] == (BYTE1)((len >> 8) & 0xff));

	return MUNIT_OK;
}

TEST_RESULT encode_register(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	BYTE1 digest_part[4];
	BYTE4 reg;

	/*
		1000 0000 : 31 - 24
		1000 0000 : 23 - 16
		1000 0000 : 15 - 8
		1000 0000 : 7  - 0
	*/
	reg = 2155905152;

	ft_md5_encode_register(digest_part, reg);

	munit_assert_true(digest_part[0] == (BYTE1)(reg & 0xff));
	munit_assert_true(digest_part[1] == (BYTE1)((reg >> 8) & 0xff));
	munit_assert_true(digest_part[2] == (BYTE1)((reg >> 16) & 0xff));
	munit_assert_true(digest_part[3] == (BYTE1)((reg >> 24) & 0xff));

	return MUNIT_OK;
}

TEST_RESULT create_digest(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	t_md5_ctx	ctx;
	BYTE1		digest[FT_MD5_DIGEST_LENGTH_BYTE];
	BYTE1		digest_string[FT_MD5_STRING_SIZE_BYTE];

	BYTE1		case1[] = "";
	BYTE1		case2[] = "a";
	BYTE1		case7[] = "1234567890123456789012345678901234567\
891234567890123456789012345678901234567890";

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, case1, ft_strlen((const char *)case1));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);

	munit_assert_string_equal((const char *)digest_string,
								"d41d8cd98f00b204e9800998ecf8427e");

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, case2, ft_strlen((const char *)case2));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);

	munit_assert_string_equal((const char *)digest_string,
								"0cc175b9c0f1b6a831c399e269772661");

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, case7, ft_strlen((const char *)case7));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);

	munit_assert_string_equal((const char *)digest_string,
								"2580a0aff7ef5e80f6b5432666530926");

	return MUNIT_OK;
}

TEST_RESULT create_string(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_MD5_STRING_SIZE_BYTE];
	BYTE4 a;
	BYTE4 b;
	BYTE4 c;
	BYTE4 d;

	/* final registers values for empty input */
	a = 3649838548;
	b = 78774415;
	c = 2550759657;
	d = 2118318316;

	ft_md5_encode_register(digest, a);
	ft_md5_encode_register(&digest[4], b);
	ft_md5_encode_register(&digest[8], c);
	ft_md5_encode_register(&digest[12], d);

	ft_md5_digest_string(digest, digest_string);

	munit_assert_string_equal((const char *)digest_string, "d41d8cd98f00b204e9800998ecf8427e");

	return MUNIT_OK;
}