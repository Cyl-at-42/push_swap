#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

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

typedef struct s_genmoves
{
	int	count_rb;
	int	dir_rb;
	int	count_ra;
	int	count_rra;
	int	count_rr;
	int	res_ra;
	int	res_rra;
	int	res_dirrb;
	int	res_rb;
	int	res_rr;
	int	prev_bestmovecount;
}	t_genmoves;

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
char	*parse_int(int *res_int, bool *res_valid, char *str);
bool	alloc_stacks(t_stacks *stacks, int max_height);
void	free_stacks(t_stacks *stacks);
bool	stacks_populate_stack_a(t_stacks *stacks, char **inputvalues_table);
bool	stacks_check_doubles_stack_a(t_stacks *stacks);
bool	stacks_check_issorted_stack_a(t_stacks *stacks);
void	stacks_reindex(t_stacks *stacks);
int		get_seq4index(int n1, int n2, int n3, int n4);
void	bring_1_to_top(t_stacks *stacks);
void	simplesort_2(t_stacks *stacks);
void	simplesort_3(t_stacks *stacks);
void	simplesort_4(t_stacks *stacks);
void	simplesort_5(t_stacks *stacks);
void	mainsort(t_stacks *stacks);
void	mainsort_phase3_apply_moves(t_stacks *stacks,
			t_genmoves *moves, int direction);
void	mainsort_phase3_update_result(t_genmoves *moves, int std_movecount,
			int use_rr_movecount);
void	mainsort_phase3_compute_moves(t_stacks *stacks, t_genmoves *moves,
			int i);
#endif
