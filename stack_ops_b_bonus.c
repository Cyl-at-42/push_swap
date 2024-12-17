#include "checker_bonus.h"

void	stackop_pb(t_stacks *stacks)
{
	if (!stacks->stack_a.height)
		return ;
	stack_push(stack_pull(&stacks->stack_a), &stacks->stack_b);
}

void	stackop_rb(t_stacks *stacks)
{
	stack_rotate(&stacks->stack_b);
}

void	stackop_rrb(t_stacks *stacks)
{
	stack_rrotate(&stacks->stack_b);
}

void	stackop_sb(t_stacks *stacks)
{
	stack_swap(&stacks->stack_b);
}
