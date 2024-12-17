#include "checker_bonus.h"

char	readbuffer_read(t_readbuffer *readbuffer, int fd)
{
	ssize_t	readbytes;

	if (readbuffer->linestart)
		return (*readbuffer->linestart != '\0');
	readbytes = read(fd, &readbuffer->buffer, BUFFER_SIZE);
	if (readbytes < 0)
		return (readbuffer->linestart = NULL, 0);
	if (readbytes < BUFFER_SIZE)
		readbuffer->buffer[readbytes] = '\0';
	readbuffer->linestart = &readbuffer->buffer[0];
	return (1);
}

char	readbuffer_has_eol(t_readbuffer *readbuffer, char **lineend_va)
{
	char	*buffer_ptr;
	char	*buffer_end;

	buffer_ptr = readbuffer->linestart;
	buffer_end = &readbuffer->buffer[0] + BUFFER_SIZE;
	while (buffer_ptr < buffer_end)
	{
		if (!*buffer_ptr)
			return (*lineend_va = buffer_ptr, 1);
		if (*buffer_ptr++ == '\n')
			return (*lineend_va = buffer_ptr, 1);
	}
	*lineend_va = buffer_end;
	return (0);
}

void	readbuffer_updatestart(t_readbuffer *readbuffer, char *linestart)
{
	char	*buffer_end;

	buffer_end = &readbuffer->buffer[0] + BUFFER_SIZE;
	if (linestart >= buffer_end)
		readbuffer->linestart = NULL;
	else
	{
		readbuffer->linestart = linestart;
		if (linestart && !*linestart)
			readbuffer->linestart = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_readbuffer	readbuffer;
	t_varstr			result_varstr;
	char				*buffer_lineend;
	char				has_eol;

	varstr_init(&result_varstr);
	while (readbuffer_read(&readbuffer, fd))
	{
		has_eol = readbuffer_has_eol(&readbuffer, &buffer_lineend);
		if (!varstr_add(&result_varstr, readbuffer.linestart, buffer_lineend))
			return (readbuffer_updatestart(&readbuffer, NULL),
				varstr_free(&result_varstr));
		if (has_eol)
			return (readbuffer_updatestart(&readbuffer, buffer_lineend),
				result_varstr.str);
		readbuffer_updatestart(&readbuffer, NULL);
	}
	return (varstr_free(&result_varstr));
}
