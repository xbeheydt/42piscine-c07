#include "tests.h"

#include <cunits42.h>

static cunits42_t	test_manual(void)
{
	return (CUNITS42_OK);
}

static cunits42_test_t	tests[] = {
	{ TEST_FCN(test_manual), NULL, NULL, CUNITS42_SKIP },
	{ TEST_FCN(test_ft_strdup), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_ft_range), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_ft_ultimate_range), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_ft_strjoin), NULL, NULL, CUNITS42_RUN },
	TEST_END
};

int	main(int argc, const char *argv[])
{
	return (main_test(tests, argc, argv));
}