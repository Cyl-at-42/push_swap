#include "push_swap.h"

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
	if ((nbr == 0x80000000) && (*in_str == '-'))
		return (*res_int = 0x80000000, *res_valid = 1, str);
	*res_valid = (nbr < 0x80000000);
	return (*res_int = (int)nbr * (1 - ((*in_str == '-') << 1)), str);
}

void	generate_push_swap_intructions(t_stacks *stacks)
{
	if (stacks->max_height == 2)
		return (simplesort_2(stacks));
	if (stacks->max_height == 3)
		return (simplesort_3(stacks));
	if (stacks->max_height == 4)
		return (simplesort_4(stacks));
	if (stacks->max_height == 5)
		return (simplesort_5(stacks));
	mainsort(stacks);
}

static int	mainsteps(int inputvaluescount, char **inputvalues_table)
{
	t_stacks	stacks;

	if (!alloc_stacks(&stacks, inputvaluescount))
		return (APPRETCODE_MALLOC);
	if (!stacks_populate_stack_a(&stacks, inputvalues_table))
		return (free_stacks(&stacks), APPRETCODE_ARG);
	if (stacks.max_height == 1)
		return (free_stacks(&stacks), APPRETCODE_OK);
	if (!stacks_check_doubles_stack_a(&stacks))
		return (free_stacks(&stacks), APPRETCODE_DOUBLE);
	if (stacks_check_issorted_stack_a(&stacks))
		return (free_stacks(&stacks), APPRETCODE_OK);
	stacks_reindex(&stacks);
	generate_push_swap_intructions(&stacks);
	free_stacks(&stacks);
	return (APPRETCODE_OK);
}

int	main(int argc, char **argv)
{
	int	app_retcode;

	if (argc == 1)
		return (APPRETCODE_OK);
	app_retcode = mainsteps(argc - 1, argv);
	if (app_retcode)
		write(2, "Error\n", 6);
	return (app_retcode);
}
