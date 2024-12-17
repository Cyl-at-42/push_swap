#include "checker_bonus.h"

void	stackop_pa(t_stacks *stacks)
{
	if (!stacks->stack_b.height)
		return ;
	stack_push(stack_pull(&stacks->stack_b), &stacks->stack_a);
}

void	stackop_ra(t_stacks *stacks)
{
	stack_rotate(&stacks->stack_a);
}

void	stackop_rra(t_stacks *stacks)
{
	stack_rrotate(&stacks->stack_a);
}

void	stackop_sa(t_stacks *stacks)
{
	stack_swap(&stacks->stack_a);
}
