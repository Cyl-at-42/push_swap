#include "push_swap.h"

void	stackop_pb(t_stacks *stacks)
{
	write(1, "pb\n", 3);
	if (!stacks->stack_a.height)
		return ;
	stack_push(stack_pull(&stacks->stack_a), &stacks->stack_b);
}

void	stackop_rb(t_stacks *stacks)
{
	write(1, "rb\n", 3);
	stack_rotate(&stacks->stack_b);
}

void	stackop_rrb(t_stacks *stacks)
{
	write(1, "rrb\n", 4);
	stack_rrotate(&stacks->stack_b);
}

void	stackop_sb(t_stacks *stacks)
{
	write(1, "sb\n", 3);
	stack_swap(&stacks->stack_b);
}

void	stackop_rrr(t_stacks *stacks)
{
	write(1, "rrr\n", 4);
	stack_rrotate(&stacks->stack_a);
	stack_rrotate(&stacks->stack_b);
}
