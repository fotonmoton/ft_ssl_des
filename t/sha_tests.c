#include "tests.h"
#include "ft_sha.h"
#include "libft.h"

TEST_RESULT should_init_ctx_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);
	t_sha256_ctx ctx;

	ft_sha256_init(&ctx);

	munit_assert_uint(ctx.a, ==, 0x6a09e667);
	munit_assert_uint(ctx.b, ==, 0xbb67ae85);
	munit_assert_uint(ctx.c, ==, 0x3c6ef372);
	munit_assert_uint(ctx.d, ==, 0xa54ff53a);
	munit_assert_uint(ctx.e, ==, 0x510e527f);
	munit_assert_uint(ctx.f, ==, 0x9b05688c);
	munit_assert_uint(ctx.g, ==, 0x1f83d9ab);
	munit_assert_uint(ctx.h, ==, 0x5be0cd19);
	munit_assert_true(ctx.bit_len == 0);
	for (int i = 0; i < 64; i++)
		munit_assert_uchar(ctx.block[i], ==, 0);

	return MUNIT_OK;
}

TEST_RESULT should_init_ctx_sha224(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);
	t_sha256_ctx ctx;

	ft_sha224_init(&ctx);

	munit_assert_uint(ctx.a, ==, 0xc1059ed8);
	munit_assert_uint(ctx.b, ==, 0x367cd507);
	munit_assert_uint(ctx.c, ==, 0x3070dd17);
	munit_assert_uint(ctx.d, ==, 0xf70e5939);
	munit_assert_uint(ctx.e, ==, 0xffc00b31);
	munit_assert_uint(ctx.f, ==, 0x68581511);
	munit_assert_uint(ctx.g, ==, 0x64f98fa7);
	munit_assert_uint(ctx.h, ==, 0xbefa4fa4);
	munit_assert_true(ctx.bit_len == 0);
	for (int i = 0; i < 64; i++)
		munit_assert_uchar(ctx.block[i], ==, 0);

	return MUNIT_OK;
}

TEST_RESULT decode_string_to_int_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	BYTE1 block[FT_SHA256_BLOCK_SIZE];
	BYTE4 words[FT_SHA256_WORDS_COUNT];

	ft_bzero(block, FT_SHA256_BLOCK_SIZE);
	block[0] = 'a';
	block[1] = 'b';
	block[2] = 'c';

	ft_sha256_decode(words, block);

	munit_assert_uint(words[0], ==, 0x61626300);

	return MUNIT_OK;
}

TEST_RESULT encode_len_to_string_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	BYTE8 len;
	BYTE1 bits[FT_SHA256_MESSAGE_LENGTH_BYTE];

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

	ft_sha256_encode_len(bits, len);

	munit_assert_uchar(bits[0], ==, (BYTE1)((len >> 56) & 0xff));
	munit_assert_uchar(bits[7], ==, (BYTE1)(len & 0xff));
	munit_assert_uchar(bits[6], ==, (BYTE1)((len >> 8) & 0xff));

	return MUNIT_OK;
}

TEST_RESULT encode_register_to_string_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	BYTE1 digest_part[4];
	BYTE4 reg;

	reg = 0xba7816bf;

	ft_sha256_encode_register(digest_part, reg);

	munit_assert_uchar(digest_part[0], ==, 0xba);
	munit_assert_uchar(digest_part[1], ==, 0x78);
	munit_assert_uchar(digest_part[2], ==, 0x16);
	munit_assert_uchar(digest_part[3], ==, 0xbf);

	return MUNIT_OK;
}

TEST_RESULT update_bit_count_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	t_sha256_ctx ctx;
	BYTE1 message[] = "abc";

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));

	munit_assert_uint(ctx.bit_len, ==, sizeof(message) * 8);

	return MUNIT_OK;
}

TEST_RESULT fill_buffer_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	t_sha256_ctx ctx;
	BYTE1 message[] = "abc";

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));

	munit_assert_string_equal((const char *)message, (const char *)ctx.block);

	return MUNIT_OK;
}

static void block_with_right_padding
(
	BYTE1 *message,
	BYTE8 message_len,
	BYTE1 padding[FT_SHA256_BLOCK_SIZE]
)
{
	ft_bzero(padding, FT_SHA256_BLOCK_SIZE);
	ft_memcpy(padding, message, message_len);
	padding[message_len] = 0x80;
}

TEST_RESULT add_right_padding_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	t_sha256_ctx ctx;
	BYTE1 message[] = "abc";
	BYTE8 buff_index;
	BYTE8 padding_len;
	BYTE1 padding[FT_SHA256_BLOCK_SIZE];
	BYTE1 block_with_message_and_pading[FT_SHA256_BLOCK_SIZE];

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));
	buff_index = (ctx.bit_len / 8) % 64;
	padding_len = (buff_index < 56) ? (56 - buff_index) : (120 - buff_index);
	ft_sha256_padding(padding);
	ft_sha256_update(&ctx, padding, padding_len);

	block_with_right_padding(message, sizeof(message),
		block_with_message_and_pading);
	munit_assert_memory_equal(FT_SHA256_BLOCK_SIZE, ctx.block,
	block_with_message_and_pading);

		return MUNIT_OK;
}

TEST_RESULT compute_digest_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	BYTE1			message[] = "abc";
	t_sha256_ctx	ctx;
	BYTE1			digest[FT_SHA256_DIGEST_LENGTH_BYTE];

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha256_final(digest, &ctx);


	munit_assert_uint32(ctx.a, ==, 0xba7816bf);
	munit_assert_uint32(ctx.b, ==, 0x8f01cfea);
	munit_assert_uint32(ctx.c, ==, 0x414140de);
	munit_assert_uint32(ctx.d, ==, 0x5dae2223);
	munit_assert_uint32(ctx.e, ==, 0xb00361a3);
	munit_assert_uint32(ctx.f, ==, 0x96177a9c);
	munit_assert_uint32(ctx.g, ==, 0xb410ff61);
	munit_assert_uint32(ctx.h, ==, 0xf20015ad);

	return MUNIT_OK;
}

TEST_RESULT compute_digest_sha224(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	BYTE1 message[] = "abc";
	t_sha256_ctx ctx;
	BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];

	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha224_final(digest, &ctx);

	munit_assert_uint32(ctx.a, ==, 0x23097d22);
	munit_assert_uint32(ctx.b, ==, 0x3405d822);
	munit_assert_uint32(ctx.c, ==, 0x8642a477);
	munit_assert_uint32(ctx.d, ==, 0xbda255b3);
	munit_assert_uint32(ctx.e, ==, 0x2aadbce4);
	munit_assert_uint32(ctx.f, ==, 0xbda0b3f7);
	munit_assert_uint32(ctx.g, ==, 0xe36c9da7);

	return MUNIT_OK;
}

TEST_RESULT create_digest_string_sha256(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	BYTE1 message[] = "abc";
	BYTE1 message_digest[] =
		"ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
	t_sha256_ctx ctx;
	BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_SHA256_STRING_SIZE_BYTE];

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha256_final(digest, &ctx);
	ft_sha256_digest_string(digest, digest_string);

	munit_assert_string_equal((const char *)message_digest,
								(const char *)digest_string);

	return MUNIT_OK;
}

TEST_RESULT create_digest_string_sha224(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_data);
	UNUSED(test_params);

	BYTE1 message[] = "abc";
	BYTE1 message_digest[] =
		"23097d223405d8228642a477bda255b32aadbce4bda0b3f7e36c9da7";
	t_sha256_ctx ctx;
	BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_SHA224_STRING_SIZE_BYTE];

	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha224_final(digest, &ctx);
	ft_sha224_digest_string(digest, digest_string);

	munit_assert_string_equal((const char *)message_digest,
							  (const char *)digest_string);

	return MUNIT_OK;
}