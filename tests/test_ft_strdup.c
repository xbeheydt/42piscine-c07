#include "tests.h"
#include <cunits42.h>
#include <c07.h>
#include <string.h>
#include <stdlib.h>

cunits42_t	test_ft_strdup(void)
{
	char	*strs[] = {
		"Ipsum Lorem",
		"Hello World",
		"",
		NULL
	};
	int		i = 0;
	char	*ret = NULL;

	while (strs[i])
	{
		ret = ft_strdup(strs[i]);
		UNIT_TEST(strcmp(ret, strs[i]), == , 0);
		free(ret);
		++i;
	}
	/* Special with NULL value */
	ret = ft_strdup(strs[i]);
	UNIT_TEST(ret, == , strs[i]);
	free(ret);
	return (CUNITS42_OK);
}