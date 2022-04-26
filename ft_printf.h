#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

typedef struct s_code_struct {
	size_t	width;
	size_t	prec;
	int		is_width;
	int		is_prec;
	int		is_minus;
	int		is_zero;
	char	code;
}			t_flags;

int		ft_printf(const char *str, ...);
int		string_handler(const char *str, va_list args);
t_flags	get_struct(char *s, va_list args);
int		printer(t_flags data, va_list args);
int		print_str(t_flags data, char *str);
int		print_char(t_flags data, char c);
int		print_ptr(t_flags data, void *ptr);
int		print_num(t_flags data, long int num);
int		print_hex(t_flags data, unsigned int n);
int		add_zeros(char **str, int zeros_count);
int		add_zeros_num(char **num, int zeros_count);
int		add_space(char **str, size_t len, int is_minus);
int		get_num_str_len(char *str);
char	*hex_convert(uintptr_t num, int lower);
size_t	max_of(size_t a, size_t b);
char	*join_str2(char *s1, char *s2);
char	*str_sub(char *s1, unsigned int start, size_t len);

#endif