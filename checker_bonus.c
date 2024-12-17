#include "checker_bonus.h"

static unsigned int	parse_ps_command_get_chrindex(char chr)
{
	static const char	index[] = {"01             2 34"};

	if (chr == '\n')
		return (5);
	if ((chr >= 'a') && (chr <= 's'))
		if (index[chr - 'a'] != ' ')
			return (index[chr - 'a'] - '0');
	return (-1);
}

static int	parse_push_swap_command(char *ps_cmdstr)
{
	static const char	lextabl[] = {"..agd.bc.........A.....Bef..n......C"
		".....Dhi.j.......E.....Fkl.m.G.....H.....I.....J.....K"};
	unsigned int		state;
	unsigned int		nextstate;
	int					chrindex;
	int					i;

	i = 0;
	state = 0;
	while (i < 4)
	{
		chrindex = parse_ps_command_get_chrindex(ps_cmdstr[i]);
		if (chrindex == -1)
			return (-1);
		nextstate = lextabl[state * 6 + (unsigned int) chrindex];
		if (nextstate == '.')
			return (-1);
		if ((nextstate >= 'A') && (nextstate <= 'K'))
			return (nextstate - 'A');
		state = nextstate - 'a' + 1;
		i++;
	}
	return (-1);
}

static bool	play_push_swap_intructions(t_stacks *stacks)
{
	static void	(*pswinstsfp[])(t_stacks *) = {stackop_pa, stackop_pb,
		stackop_sa, stackop_sb, stackop_ra, stackop_rb, stackop_rr,
		stackop_rra, stackop_rrb, stackop_rrr, stackop_ss};
	char		*newline;
	int			psw_intr;

	newline = (char *) 1;
	while (newline)
	{
		newline = get_next_line(0);
		if (newline)
		{
			psw_intr = parse_push_swap_command(newline);
			free(newline);
			if (psw_intr == -1)
				return (false);
			pswinstsfp[psw_intr](stacks);
		}
	}
	return (true);
}

static int	mainsteps(int inputvaluescount, char **inputvalues_table)
{
	static const char	*res_str[2] = {"KO\n", "OK\n"};
	t_stacks			stacks;

	if (!alloc_stacks(&stacks, inputvaluescount))
		return (APPRETCODE_MALLOC);
	if (!stacks_populate_stack_a(&stacks, inputvalues_table))
		return (free_stacks(&stacks), APPRETCODE_ARG);
	if (!stacks_check_doubles_stack_a(&stacks))
		return (free_stacks(&stacks), APPRETCODE_DOUBLE);
	if (!play_push_swap_intructions(&stacks))
		return (free_stacks(&stacks), APPRETCODE_INSTR);
	write(1, res_str[stacks_check_issorted_stack_a(&stacks)
		&& (stacks.stack_b.height == 0)], 3);
	free_stacks(&stacks);
	return (APPRETCODE_OK);
}

int	main(int argc, char **argv)
{
	int	app_retcode;

	if (argc == 1)
		return (0);
	app_retcode = mainsteps(argc - 1, argv);
	if (app_retcode)
		write(2, "Error\n", 6);
	return (app_retcode);
}
