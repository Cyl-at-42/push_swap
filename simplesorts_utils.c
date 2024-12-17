#include "push_swap.h"

int	get_seq4index(int n1, int n2, int n3, int n4)
{
	static const char	a[] = {"234243324342423432134143314341413431"
		"124142214241412421123132213231312321"};
	int					i;
	int					n;

	n2 += '0';
	n3 += '0';
	n4 += '0';
	i = 0;
	n = (n1 - 1) * 18;
	while (i < 6)
	{
		if ((a[n] == n2) && (a[n + 1] == n3) && (a[n + 2] == n4))
			return (n / 3);
		n += 3;
		i++;
	}
	return (42);
}

void	bring_1_to_top(t_stacks *stacks)
{
	if (stacks->stack_a.values[1] == 1)
		return (stackop_ra(stacks));
	if (stacks->stack_a.values[2] == 1)
		return (stackop_ra(stacks), stackop_ra(stacks));
	if (stacks->stack_a.values[3] == 1)
		return (stackop_rra(stacks), stackop_rra(stacks));
	if (stacks->stack_a.values[4] == 1)
		return (stackop_rra(stacks));
}
