#include "tests.h"

TEST_RESULT should_pass(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);
    return MUNIT_OK;
}

TEST_RESULT should_fail(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);
    return MUNIT_SKIP;
    return MUNIT_FAIL;
}

TEST_RESULT should_skip(TEST_PARAMS, TEST_DATA)
{
    UNUSED(test_params);
    UNUSED(test_data);
    return MUNIT_SKIP;
}