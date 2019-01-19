#include "tests.h"
#include "tests_macros.h"
#include "ft_base64.h"

TEST_RESULT should_init_base64_ctx(TEST_PARAMS, TEST_DATA)
{
	UNUSED(test_params);
	UNUSED(test_data);
	t_base64_ctx ctx;

	ft_base64_init(&ctx);

	munit_assert_true(ctx.block_bit_index == 0);
	for (int i = 0; i < FT_BASE64_BLOCK_SIZE; i++)
		munit_assert_uchar(ctx.block[i], ==, 0);

	return MUNIT_OK;
}