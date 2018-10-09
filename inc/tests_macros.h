#ifndef TESTS_MACROS
# define TESTS_MACROS

#include "munit.h"

#define UNUSED(x) (void)(x)

#define TEST_RESULT MunitResult
#define TEST_PARAMS const MunitParameter test_params[]
#define TEST_DATA void *test_data
#define CASE(f) TEST_RESULT f(TEST_PARAMS, TEST_DATA)

#define N(name) (char *)name
#define T(test_function) test_function
#define S(setup_function) setup_function
#define TD(tear_down_function) tear_down_function
#define O(options) options
#define P(paramenters) paramenters
#define IT(n, t, s, td, o, p) { N(n), T(t), S(s), TD(td), O(o), P(p) }
#define END_IT IT(NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL)

#endif