#include "tests.h"

MunitTest test_tests[] = {
	IT("/should_pass", should_pass, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	IT("/should_fail", should_fail, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	IT("/should_skip", should_skip, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	END_IT
};

static const MunitSuite suite = {
	(char *)"/test_tests_suite",   	/* name */
	test_tests,						/* tests */
	NULL,							/* suites */
	1,								/* iterations */
	MUNIT_SUITE_OPTION_NONE			/* options */
};

int main(int argc, char** argv) 
{
	return munit_suite_main(&suite, NULL, argc, argv);
}
