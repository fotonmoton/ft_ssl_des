#include "tests.h"
#include "tests_macros.h"
#include "ft_base64.h"

TEST_RESULT should_init_base64_ctx(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);
	t_base64_ctx ctx;
	char		alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	ft_base64_init(&ctx);

	for (int i = 0; i < FT_BASE64_BLOCK_SIZE; i++)
		munit_assert_uchar(ctx.block[i], ==, 0);

	for (int i = 0; i < FT_BASE64_CHARS_SIZE; i++)
		munit_assert_uchar(ctx.chars[i], ==, 0);

	munit_assert_string_equal(alphabet, (char *)ctx.alphabet);

	return MUNIT_OK;
}

TEST_RESULT should_fill_base64_buffer(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	t_base64_ctx	ctx;

	ft_base64_init(&ctx);

	t_byte1 data[] = "123";
	ft_base64_fill_buffer(&ctx, data, 3);

	munit_assert_memory_equal(3, ctx.block, data);
	return MUNIT_OK;
}

TEST_RESULT should_clean_base64_buffer(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	t_base64_ctx	ctx;

	ft_base64_init(&ctx);

	ft_base64_fill_buffer(&ctx, (t_byte1 *)"Man", 3);
	ft_base64_encode_buffer(&ctx, 3);
	for (int i = 0; i < FT_BASE64_BLOCK_SIZE; i++)
		munit_assert_uchar(ctx.block[i], ==, 0);
	return MUNIT_OK;
}

TEST_RESULT should_encode_base64_buffer(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	t_base64_ctx	ctx;

	ft_base64_init(&ctx);

	ft_base64_fill_buffer(&ctx, (t_byte1 *)"Man", 3);
	ft_base64_encode_buffer(&ctx, 3);
	munit_assert_string_equal((char *)ctx.chars, "TWFu");

	ft_base64_fill_buffer(&ctx, (t_byte1 *)"Ma", 2);
	ft_base64_encode_buffer(&ctx, 2);
	munit_assert_string_equal((char *)ctx.chars, "TWE=");

	ft_base64_fill_buffer(&ctx, (t_byte1 *)"M", 1);
	ft_base64_encode_buffer(&ctx, 1);
	munit_assert_string_equal((char *)ctx.chars, "TQ==");
	return MUNIT_OK;
}