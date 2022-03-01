#include "tests.h"
#include <cunits42.h>
#include <c07.h>
#include <stdlib.h>

cunits42_t	test_ft_ultimate_range(void)
{
	int	ret = 0;
	int	*range = NULL;
	int	i = 0, val = 0;

	ret = ft_ultimate_range(&range, -128, 0);
	val = -128;
	UNIT_TEST(ret, == , 0 - (-128));
	while (val < 0)
	{
		UNIT_TEST(val, == , range[i]);
		++val;
		++i;
	}
	free(range);

	ret = ft_ultimate_range(&range, 1, 1);
	UNIT_TEST(ret, == , -1);
	UNIT_TEST(range, == , NULL);
	free(range);

	ret = ft_ultimate_range(&range, 1, -124);
	UNIT_TEST(ret, == , -1);
	UNIT_TEST(range, == , NULL);
	free(range);
	return (CUNITS42_OK);
}
