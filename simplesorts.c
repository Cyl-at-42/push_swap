#include "push_swap.h"

void	simplesort_2(t_stacks *stacks)
{
	if (stacks->stack_a.values[0] > stacks->stack_a.values[1])
		stackop_sa(stacks);
}

void	simplesort_3(t_stacks *stacks)
{
	int	n1_lt_n2;
	int	n1_lt_n3;
	int	n2_lt_n3;

	n1_lt_n2 = (stacks->stack_a.values[0] < stacks->stack_a.values[1]);
	n1_lt_n3 = (stacks->stack_a.values[0] < stacks->stack_a.values[2]);
	n2_lt_n3 = (stacks->stack_a.values[1] < stacks->stack_a.values[2]);
	if (n1_lt_n2)
	{
		if (n1_lt_n3 && !n2_lt_n3)
			return (stackop_rra(stacks), stackop_sa(stacks));
		if (!n1_lt_n3 && !n2_lt_n3)
			return (stackop_rra(stacks));
	}
	else
	{
		if (n1_lt_n3 && n2_lt_n3)
			return (stackop_sa(stacks));
		if (!n1_lt_n3 && n2_lt_n3)
			return (stackop_ra(stacks));
		if (!n1_lt_n3 && !n2_lt_n3)
			return (stackop_ra(stacks), stackop_sa(stacks));
	}
}

void	simplesort_4(t_stacks *stks)
{
	static const char	a[] = {".....urod.uod..urd..uld..ulod.o....lulodrrol."
		"r....urdr.lorr.ouod.ourd.orrolor...ll...rro..l....llor.lo..."
		"rol..oll..ollo."};
	int					o;
	int					n;
	int					i;

	o = (stks->stack_a.values[0] == 5) || (stks->stack_a.values[1] == 5)
		|| (stks->stack_a.values[2] == 5) || (stks->stack_a.values[3] == 5);
	n = get_seq4index(stks->stack_a.values[0] - o, stks->stack_a.values[1] - o,
			stks->stack_a.values[2] - o, stks->stack_a.values[3] - o) * 5;
	i = 0;
	while (i <= 4)
	{
		if (a[n + i] == 'u')
			stackop_pb(stks);
		if (a[n + i] == 'd')
			stackop_pa(stks);
		if (a[n + i] == 'l')
			stackop_ra(stks);
		if (a[n + i] == 'r')
			stackop_rra(stks);
		if (a[n + i++] == 'o')
			stackop_sa(stks);
	}
}

static char	*simplesort_5_specific(char **r, t_stacks *stacks)
{
	static const int	quints[8] = {23451, 51234, 21345, 54132, 25143,
		25413, 32514};
	static char			seqs[] = {"r.......l.......o.......ullordl."
		"luuloddllullordlouurddr."};
	int					n;
	int					i;

	n = stacks->stack_a.values[0] * 10000 + stacks->stack_a.values[1] * 1000;
	n += stacks->stack_a.values[2] * 100 + stacks->stack_a.values[3] * 10;
	n += stacks->stack_a.values[4];
	i = 0;
	while (i < 7)
	{
		if (n == quints[i])
			return (*r = seqs + (i << 3), *r);
		i++;
	}
	return (NULL);
}

void	simplesort_5(t_stacks *stacks)
{
	char	*seqstr;
	int		i;

	if (simplesort_5_specific(&seqstr, stacks))
	{
		i = 0;
		while (i < 8)
		{
			if (seqstr[i] == 'u')
				stackop_pb(stacks);
			if (seqstr[i] == 'd')
				stackop_pa(stacks);
			if (seqstr[i] == 'l')
				stackop_ra(stacks);
			if (seqstr[i] == 'r')
				stackop_rra(stacks);
			if (seqstr[i++] == 'o')
				stackop_sa(stacks);
		}
		return ;
	}
	bring_1_to_top(stacks);
	stackop_pb(stacks);
	simplesort_4(stacks);
	stackop_pa(stacks);
}
