#ifndef TESTS
# define TESTS

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"
#include "tests_macros.h"

// md5 tests
CASE(should_init_ctx);
CASE(update_should_change_count);
CASE(decode_string_to_int);
CASE(encode_bits_to_string);
CASE(encode_register);
CASE(create_digest);
CASE(create_string);

// sha tests
CASE(should_init_ctx_sha256);
CASE(decode_string_to_int_sha256);
CASE(encode_len_to_string_sha256);
CASE(encode_register_to_string_sha256);
CASE(update_bit_count_sha256);
CASE(fill_buffer_sha256);
CASE(add_right_padding_sha256);
CASE(compute_digest_sha256);
CASE(create_digest_string_sha256);


#endif