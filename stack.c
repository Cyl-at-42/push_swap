#include "push_swap.h"

void	stack_rotate(t_stack *stack)
{
	int	sv;
	int	i;

	if (!stack->height)
		return ;
	sv = stack->values[0];
	i = 0;
	while (i < (stack->height - 1))
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->height - 1] = sv;
}

void	stack_rrotate(t_stack *stack)
{
	int	sv;
	int	i;

	if (!stack->height)
		return ;
	sv = stack->values[stack->height - 1];
	i = stack->height - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = sv;
}

void	stack_swap(t_stack *stack)
{
	int	sv;

	if (stack->height <= 1)
		return ;
	sv = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = sv;
}

void	stack_push(int v, t_stack *stack)
{
	int	i;

	i = stack->height;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = v;
	stack->height++;
}

int	stack_pull(t_stack *stack)
{
	int	sv;
	int	i;

	sv = stack->values[0];
	i = 0;
	while (i < (stack->height - 1))
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->height - 1] = 0;
	stack->height--;
	return (sv);
}
