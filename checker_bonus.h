#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "gnl_bonus.h"

# define APPRETCODE_OK 0
# define APPRETCODE_ARG 1
# define APPRETCODE_DOUBLE 2
# define APPRETCODE_MALLOC 3
# define APPRETCODE_INSTR 4

typedef struct s_stack
{
	int	*values;
	int	height;
}	t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		max_height;
}	t_stacks;

typedef struct s_input_values
{
	int		*values;
	int		count;
}	t_input_values;

void	stack_rotate(t_stack *stack);
void	stack_rrotate(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_push(int v, t_stack *stack);
int		stack_pull(t_stack *stack);
void	stackop_pa(t_stacks *stacks);
void	stackop_ra(t_stacks *stacks);
void	stackop_rr(t_stacks *stacks);
void	stackop_rra(t_stacks *stacks);
void	stackop_sa(t_stacks *stacks);
void	stackop_pb(t_stacks *stacks);
void	stackop_rb(t_stacks *stacks);
void	stackop_rrb(t_stacks *stacks);
void	stackop_sb(t_stacks *stacks);
void	stackop_rrr(t_stacks *stacks);
void	stackop_ss(t_stacks *stacks);
char	*get_next_line(int fd);
void	varstr_init(t_varstr *varstr);
char	*varstr_free(t_varstr *varstr);
char	*varstr_add(t_varstr *varstr, char *str2_start, char *str2_end);
char	*parse_int(int *res_int, bool *res_valid, char *str);
bool	alloc_stacks(t_stacks *stacks, int max_height);
void	free_stacks(t_stacks *stacks);
bool	stacks_populate_stack_a(t_stacks *stacks, char **inputvalues_table);
bool	stacks_check_doubles_stack_a(t_stacks *stacks);
bool	stacks_check_issorted_stack_a(t_stacks *stacks);

#endif
