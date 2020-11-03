
NAME=libft.a

SRC=\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlen.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strchr.c\
ft_strrchr.c\
ft_strnstr.c\
ft_strncmp.c\
ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_strnlen_bonus.c
OBJ=$(SRC:.c=.o)
PART2_SRC=\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c
PART2_OBJ=$(PART2_SRC:.c=.o)
LIST_SRC=\
ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c
LIST_OBJ=$(LIST_SRC:.c=.o)
LINE_SRC=\
ft_lninit.c\
ft_lnexpand.c\
ft_lnappend.c\
ft_lnfree.c
LINE_OBJ=$(LINE_SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	cc -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $?

part2: $(NAME) part2_add
part2_add: $(PART2_OBJ)
	ar rc $(NAME) $?
	touch part2_add

list: $(NAME) list_add
list_add: $(LIST_OBJ)
	ar rc $(NAME) $?
	touch list_add

line: $(NAME) line_add
line_add: $(LINE_OBJ)
	ar rc $(NAME) $?
	touch line_add

clean:
	rm -rf $(OBJ)
	rm -rf $(PART2_OBJ)
	rm -rf $(LIST_OBJ)
	rm -rf $(LINE_OBJ)
	rm -rf part2_add
	rm -rf list_add
	rm -rf line_add

fclean: clean
	rm -rf $(NAME)

re: fclean all
