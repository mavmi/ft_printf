NAME		=		libftprintf.a
LIBFT_DIR	=		libft
LIBFT_MAKE	=		Makefile_libft


LIBFT_SRCS	=	 	$(addprefix $(LIBFT_DIR)/, ft_itoa.c ft_strchr.c ft_strdup.c\
					ft_atoi.c ft_memset.c ft_strlen.c ft_isdigit.c ft_putstr_fd.c\
					ft_strjoin.c ft_putchar_fd.c ft_substr.c ft_numlen.c) 
LIBFT_OBJS	=		$(LIBFT_SRCS:.c=.o)
LIBFT_HDRS	=		$(LIBFT_DIR)/libft.h


SRCS		= 		ft_printf.c string_handler.c struct_creator.c printer.c\
					print_char.c print_ptr.c print_str.c print_num.c utils.c str_utils.c
OBJS		=		$(SRCS:.c=.o)
HDRS		=		ft_printf.h


FLAGS		=		-Wall -Wextra -Werror
CC			=		gcc
GCC			=		$(CC) $(FLAGS)


all:				$(NAME)

%.o:				%.c $(HDRS) $(LIBFT_HDRS)
					$(GCC) -c -o $@ $<
 
$(NAME):			$(OBJS) $(LIBFT_OBJS)
					ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

clean:				libft_clean
					rm -f $(OBJS)

fclean:				clean libft_clean
					rm -f $(NAME)


libft_clean:		
					rm -f $(LIBFT_OBJS)


re:					fclean $(NAME)

.PHONY:				all clean fclean re
