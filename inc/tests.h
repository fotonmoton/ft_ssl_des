#ifndef TESTS
# define TESTS

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"
#include "tests_macros.h"

// md5 test tests
CASE(should_init_ctx);
CASE(update_should_change_count);
CASE(decode_string_to_int);
CASE(encode_bits_to_string);
CASE(encode_register);
CASE(create_digest);
CASE(create_string);

#endif