#include "checker_bonus.h"

void	varstr_init(t_varstr *varstr)
{
	varstr->str = NULL;
	varstr->len = 0;
}

char	*varstr_free(t_varstr *varstr)
{
	free(varstr->str);
	varstr->str = NULL;
	varstr->len = 0;
	return (NULL);
}

char	*varstr_add(t_varstr *varstr, char *str2_start, char *str2_end)
{
	char	*result_str;
	char	*result_ptr;
	size_t	len;
	char	*str1_ptr;
	size_t	str1_len;

	len = str2_end - str2_start;
	if (!len)
		return (varstr->str);
	len += varstr->len;
	result_str = (char *) malloc((len + 1) * sizeof(char));
	if (!result_str)
		return (varstr_free(varstr));
	result_ptr = result_str;
	str1_ptr = varstr->str;
	str1_len = varstr->len;
	while (str1_len--)
		*result_ptr++ = *str1_ptr++;
	while (str2_start < str2_end)
		*result_ptr++ = *str2_start++;
	*result_ptr = 0;
	free(varstr->str);
	varstr->str = result_str;
	varstr->len = len;
	return (result_str);
}
