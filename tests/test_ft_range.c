#include "tests.h"
#include <cunits42.h>
#include <c07.h>
#include <stdlib.h>

cunits42_t	test_ft_range(void)
{
	int	*ret = NULL;
	int	i = 0, val = 0;

	ret = ft_range(-128, 0);
	val = -128;
	while (val < 0)
	{
		UNIT_TEST(val, == , ret[i]);
		++val;
		++i;
	}
	free(ret);

	ret = ft_range(1, 1);
	UNIT_TEST(ret, == , NULL);
	free(ret);

	ret = ft_range(1, -241);
	UNIT_TEST(ret, == , NULL);
	free(ret);
	return (CUNITS42_OK);
}
