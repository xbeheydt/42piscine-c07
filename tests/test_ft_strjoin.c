#include "tests.h"
#include <c07.h>
#include <cunits42.h>
#include <stdlib.h>
#include <string.h>

cunits42_t test_ft_strjoin(void)
{
	char	*strs[] = {
		"Hello",
		"World",
		"",
		"!"
	};
	int		size = 4;
	char	*strjoin = NULL;

	strjoin = ft_strjoin(size, strs, ";");
	UNIT_TEST(strcmp(strjoin, "Hello;World;;!"), ==, 0);
	free(strjoin);
	UNIT_TEST(ft_strjoin(0, strs, " "), == , NULL);
	return (CUNITS42_OK);
}
