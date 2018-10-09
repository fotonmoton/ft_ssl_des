#ifndef TESTS
# define TESTS

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"
#include "tests_macros.h"

// test tests
CASE(should_pass);
CASE(should_skip);
CASE(should_fail);

#endif