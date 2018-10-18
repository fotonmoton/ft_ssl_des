#include "tests.h"

MunitTest md5_tests[] = {
	IT("/zeroes_ctx", should_init_ctx, NULL, NULL, 0, NULL),
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