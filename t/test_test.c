#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

int main(int argc, char** argv) {
	(void)argc;
	(void)argv;
	assert_int(argc, ==, 1);
}
