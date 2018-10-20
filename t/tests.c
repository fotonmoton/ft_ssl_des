#include "tests.h"

MunitTest md5_tests[] = {
	IT("/zeroes_ctx", should_init_ctx, NULL, NULL, 0, NULL),
	IT("/updates_ctx_count", update_should_change_count, NULL, NULL, 0, NULL),
	IT("/decode_string_to_int", decode_string_to_int, NULL, NULL, 0, NULL),
	IT("/encode_bits_to_string", encode_bits_to_string, NULL, NULL, 0, NULL),
	IT("/encode_register", encode_register, NULL, NULL, 0, NULL),
	IT("/creates_digest", create_digest, NULL, NULL, 0, NULL),
	IT("/creates_string", create_string, NULL, NULL, 0, NULL),
	END_IT
};

static const MunitSuite suite = {
	(char *)"/md5_suite",   		/* name */
	md5_tests,						/* tests */
	NULL,							/* suites */
	1,								/* iterations */
	MUNIT_SUITE_OPTION_NONE			/* options */
};

int main(int argc, char** argv)
{
	return munit_suite_main(&suite, NULL, argc, argv);
}