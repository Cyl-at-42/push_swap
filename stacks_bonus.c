#include "checker_bonus.h"

bool	alloc_stacks(t_stacks *stacks, int max_height)
{
	stacks->stack_a.values = (int *)malloc(max_height * sizeof(int));
	if (!stacks->stack_a.values)
		return (false);
	stacks->stack_b.values = (int *)malloc(max_height * sizeof(int));
	if (!stacks->stack_b.values)
	{
		free(stacks->stack_a.values);
		return (false);
	}
	stacks->max_height = max_height;
	stacks->stack_a.height = 0;
	stacks->stack_b.height = 0;
	return (true);
}

void	free_stacks(t_stacks *stacks)
{
	free(stacks->stack_a.values);
	free(stacks->stack_b.values);
}

bool	stacks_populate_stack_a(t_stacks *stacks, char **inputvalues_table)
{
	int		arg_index;
	char	*str;
	char	*result_str;
	int		*result_int_ptr;
	bool	result_valid;

	result_int_ptr = stacks->stack_a.values;
	arg_index = 1;
	while (arg_index <= stacks->max_height)
	{
		str = inputvalues_table[arg_index];
		result_str = parse_int(result_int_ptr, &result_valid, str);
		if (!result_valid)
			return (false);
		if (*result_str)
			return (false);
		result_int_ptr++;
		arg_index++;
	}
	stacks->stack_a.height = stacks->max_height;
	return (true);
}

bool	stacks_check_doubles_stack_a(t_stacks *stacks)
{
	int	i;
	int	j;

	if (stacks->stack_a.height == 1)
		return (true);
	i = 0;
	while (i < stacks->stack_a.height - 1)
	{
		j = i + 1;
		while (j < stacks->stack_a.height)
		{
			if (stacks->stack_a.values[i] == stacks->stack_a.values[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	stacks_check_issorted_stack_a(t_stacks *stacks)
{
	int	i;

	if (stacks->stack_a.height == 1)
		return (1);
	i = 0;
	while (i < (stacks->stack_a.height - 1))
	{
		if (stacks->stack_a.values[i] > stacks->stack_a.values[i + 1])
			return (0);
		i++;
	}
	return (1);
}
