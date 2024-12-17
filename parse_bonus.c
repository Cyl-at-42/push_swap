#include "checker_bonus.h"

char	*parse_int(int *res_int, bool *res_valid, char *str)
{
	unsigned int	nbr;
	char			*in_str;
	char			*msd_str;

	nbr = 0;
	in_str = str;
	str += (*str == '-' || *str == '+');
	*res_valid = (*str == '0');
	while (*str == '0')
		str++;
	if ((*str < '0' || *str > '9') && !*res_valid)
		return (in_str);
	msd_str = str;
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + (*str++ - '0');
	if (((str - msd_str) > 10) || ((str - msd_str) == 10 && *msd_str >= '4'))
		return (*res_valid = 0, str);
	if ((nbr == 2147483648) && (*in_str == '-'))
		return (*res_int = 0x80000000, *res_valid = 1, str);
	*res_valid = (nbr < 2147483648);
	return (*res_int = (int)nbr * (1 - ((*in_str == '-') << 1)), str);
}
