#include "checker_bonus.h"

void	stackop_rr(t_stacks *stacks)
{
	stack_rotate(&stacks->stack_a);
	stack_rotate(&stacks->stack_b);
}

void	stackop_rrr(t_stacks *stacks)
{
	stack_rrotate(&stacks->stack_a);
	stack_rrotate(&stacks->stack_b);
}

void	stackop_ss(t_stacks *stacks)
{
	stack_swap(&stacks->stack_a);
	stack_swap(&stacks->stack_b);
}
