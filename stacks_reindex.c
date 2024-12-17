#include "push_swap.h"

static void	stacks_reindex_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stacks->max_height - 1)
	{
		j = i + 1;
		while (j < stacks->max_height)
		{
			if (stacks->stack_a.values[i] > stacks->stack_a.values[j])
			{
				tmp = stacks->stack_a.values[i];
				stacks->stack_a.values[i] = stacks->stack_a.values[j];
				stacks->stack_a.values[j] = tmp;
				tmp = stacks->stack_b.values[i];
				stacks->stack_b.values[i] = stacks->stack_b.values[j];
				stacks->stack_b.values[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	stacks_reindex(t_stacks *stacks)
{
	int				i;
	unsigned int	n;

	i = 0;
	while (i < stacks->max_height)
	{
		stacks->stack_b.values[i] = i + 1;
		i++;
	}
	stacks_reindex_sort(stacks);
	n = 1;
	while (n <= (unsigned int) stacks->max_height)
	{
		stacks->stack_a.values[stacks->stack_b.values[n - 1] - 1] = n;
		n++;
	}
}
