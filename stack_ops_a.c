#include "push_swap.h"

void	stackop_pa(t_stacks *stacks)
{
	write(1, "pa\n", 3);
	if (!stacks->stack_b.height)
		return ;
	stack_push(stack_pull(&stacks->stack_b), &stacks->stack_a);
}

void	stackop_ra(t_stacks *stacks)
{
	write(1, "ra\n", 3);
	stack_rotate(&stacks->stack_a);
}

void	stackop_rr(t_stacks *stacks)
{
	write(1, "rr\n", 3);
	stack_rotate(&stacks->stack_a);
	stack_rotate(&stacks->stack_b);
}

void	stackop_rra(t_stacks *stacks)
{
	write(1, "rra\n", 4);
	stack_rrotate(&stacks->stack_a);
}

void	stackop_sa(t_stacks *stacks)
{
	write(1, "sa\n", 3);
	stack_swap(&stacks->stack_a);
}
