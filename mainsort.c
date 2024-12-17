#include "push_swap.h"

static void	mainsort_phase1_presort2(t_stacks *stacks)
{
	int	sv;
	int	sv_min;
	int	sv_med;
	int	sv_max;

	sv_min = 1;
	sv_med = stacks->max_height >> 1;
	sv_max = stacks->max_height;
	while (stacks->stack_a.height > 3)
	{
		sv = stacks->stack_a.values[0];
		if ((sv != sv_min) && (sv != sv_med) && (sv != sv_max))
		{
			stackop_pb(stacks);
			if (sv > sv_med)
				stackop_rb(stacks);
		}
		else
			stackop_ra(stacks);
	}
}

static void	mainsort_phase1_presort1(t_stacks *stacks, int sv_med)
{
	int	i;
	int	sv;
	int	sv_med1;
	int	sv_med2;

	sv_med1 = (1 + sv_med) >> 1;
	sv_med2 = (sv_med + stacks->max_height) >> 1;
	i = -1;
	while (++i < (stacks->max_height))
	{
		sv = stacks->stack_a.values[0];
		if ((sv != 1) && (sv != sv_med) && (sv != stacks->max_height))
		{
			if ((sv >= sv_med1) && (sv <= sv_med2))
			{
				stackop_pb(stacks);
				if (sv > sv_med)
					stackop_rb(stacks);
			}
			else
				stackop_ra(stacks);
		}
		else
			stackop_ra(stacks);
	}
}

void	mainsort_phase4(t_stacks *stacks)
{
	int	i;
	int	rcount;
	int	rrcount;

	rcount = 0;
	rrcount = 0;
	i = 0;
	while (i < (stacks->stack_a.height))
	{
		if (stacks->stack_a.values[i] == 1)
		{
			rcount = i;
			rrcount = stacks->stack_a.height - i;
			break ;
		}
		i++;
	}
	if (rcount <= rrcount)
		while (rcount--)
			stackop_ra(stacks);
	else
		while (rrcount--)
			stackop_rra(stacks);
}

void	mainsort(t_stacks *stacks)
{
	t_genmoves	moves;
	int			i;

	if (stacks->max_height >= 250)
		mainsort_phase1_presort1(stacks, stacks->max_height >> 1);
	mainsort_phase1_presort2(stacks);
	simplesort_3(stacks);
	while (stacks->stack_b.height)
	{
		moves.prev_bestmovecount = 0x7fffffff;
		i = 0;
		while (i < stacks->stack_b.height)
			mainsort_phase3_compute_moves(stacks, &moves, i++);
		mainsort_phase3_apply_moves(stacks, &moves,
			(moves.res_ra <= moves.res_rra));
		stackop_pa(stacks);
	}
	mainsort_phase4(stacks);
}
