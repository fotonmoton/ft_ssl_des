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

	munit_assert_string_equal(alphabet, (char *)ctx.alphabet);

	return MUNIT_OK;
}

TEST_RESULT should_transform_base64_block(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);

	t_base64_ctx	ctx;
	t_byte1			buff[FT_BASE64_DECODE_BLOCK_SIZE];

	ft_base64_init(&ctx);

	ft_base64_encode_transform(&ctx, (t_byte1 *)"Man", buff);
	munit_assert_string_equal((char *)buff, "TWFu");

	ft_base64_encode_transform(&ctx, (t_byte1 *)"LOL", buff);
	munit_assert_string_equal((char *)buff, "TE9M");
	return MUNIT_OK;
}