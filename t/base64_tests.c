#include <unistd.h>
#include "tests.h"
#include "tests_macros.h"
#include "ft_base64.h"

TEST_RESULT should_init_base64_ctx(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);
	t_base64_ctx ctx;
	char		alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz0123456789+/";

	ft_base64_init(&ctx);

	munit_assert_true(ctx.input_fd == STDIN_FILENO);
	munit_assert_true(ctx.output_fd == STDOUT_FILENO);


	for (int i = 0; i < FT_BASE64_CHARS_SIZE; i++)
		munit_assert_uchar(ctx.chars[i], ==, 0);

	munit_assert_string_equal(alphabet, (char *)ctx.alphabet);

	return MUNIT_OK;
}

TEST_RESULT should_transform_base64_block(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	t_base64_ctx	ctx;

	ft_base64_init(&ctx);

	ft_base64_transform(&ctx, (t_byte1 *)"Man");
	munit_assert_string_equal((char *)ctx.chars, "TWFu");

	ft_base64_transform(&ctx, (t_byte1 *)"LOL");
	munit_assert_string_equal((char *)ctx.chars, "TE9M");
	return MUNIT_OK;
}