#include "push_swap.h"

static int	minval(int val1, int val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

static void	find_count_ra_for_val(int *rcount, int *rrcount, t_stack *stack,
	int val)
{
	int	sv1;
	int	sv2;
	int	i;

	sv1 = stack->values[stack->height - 1];
	i = 0;
	while (i < (stack->height))
	{
		sv2 = stack->values[i];
		if (val > sv1 && val < sv2)
		{
			*rcount = i;
			*rrcount = stack->height - i;
			return ;
		}
		sv1 = sv2;
		i++;
	}
}

void	mainsort_phase3_apply_moves(t_stacks *stacks,
	t_genmoves *moves, int direction)
{
	if (moves->res_rr)
	{
		moves->res_ra -= moves->res_rr;
		moves->res_rra -= moves->res_rr;
		moves->res_rb -= moves->res_rr;
		if (direction)
			while (moves->res_rr--)
				stackop_rr(stacks);
		else
			while (moves->res_rr--)
				stackop_rrr(stacks);
	}
	if (direction)
		while (moves->res_ra--)
			stackop_ra(stacks);
	else
		while (moves->res_rra--)
			stackop_rra(stacks);
	if (moves->res_dirrb > 0)
		while (moves->res_rb--)
			stackop_rb(stacks);
	else
		while (moves->res_rb--)
			stackop_rrb(stacks);
}

void	mainsort_phase3_update_result(t_genmoves *moves, int std_movecount,
	int use_rr_movecount)
{
	if (std_movecount < moves->prev_bestmovecount)
	{
		moves->res_dirrb = moves->dir_rb;
		moves->res_rb = moves->count_rb;
		moves->res_ra = moves->count_ra;
		moves->res_rra = moves->count_rra;
		moves->res_rr = 0;
		moves->prev_bestmovecount = std_movecount;
	}
	if ((use_rr_movecount < moves->prev_bestmovecount) && (moves->count_rr > 0))
	{
		moves->res_dirrb = moves->dir_rb;
		moves->res_rb = moves->count_rb;
		moves->res_ra = moves->count_ra;
		moves->res_rra = moves->count_rra;
		moves->res_rr = moves->count_rr;
		moves->prev_bestmovecount = use_rr_movecount;
	}
}

void	mainsort_phase3_compute_moves(t_stacks *stacks,
	t_genmoves *moves, int i)
{
	int	rtotal1;
	int	rtotal2;

	find_count_ra_for_val(&moves->count_ra, &moves->count_rra, &stacks->stack_a,
		stacks->stack_b.values[i]);
	moves->dir_rb = -1 + ((i < (stacks->stack_b.height >> 1)) << 1);
	if (i < (stacks->stack_b.height >> 1))
		moves->count_rb = i;
	else
		moves->count_rb = ((int)stacks->stack_b.height - i - 1) + 1;
	if (moves->count_ra < moves->count_rra)
		rtotal1 = moves->count_rb + moves->count_ra;
	else
		rtotal1 = moves->count_rb + moves->count_rra;
	if (moves->dir_rb > 0)
	{
		rtotal2 = moves->count_rb + moves->count_ra;
		moves->count_rr = minval(moves->count_rb, moves->count_ra);
	}
	else
	{
		rtotal2 = moves->count_rb + moves->count_rra;
		moves->count_rr = minval(moves->count_rb, moves->count_rra);
	}
	mainsort_phase3_update_result(moves, rtotal1, rtotal2 - moves->count_rr);
}
