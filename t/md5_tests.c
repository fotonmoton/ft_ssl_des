#include "tests.h"
#include "ft_md5.h"

TEST_RESULT should_init_ctx(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);
    t_md5_ctx ctx;

    ft_md5_init(&ctx);

    // munit_assert_true(ctx.a == 0x67452301);
    // munit_assert_uint(ctx.b, ==, 0xefcdab89);
    // munit_assert_uint(ctx.c, ==, 0x98badcfe);
    // munit_assert_uint(ctx.d, ==, 0x10325476);
    for (int i = 0; i < 64; i++)
        munit_assert_uchar(ctx.buffer[i], ==, 0);

    return MUNIT_OK;
}