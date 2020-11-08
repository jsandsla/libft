
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
ft_strnchr.c\
ft_strrchr.c\
ft_strnstr.c\
ft_strncpy.c\
ft_strncmp.c\
ft_atoi.c\
ft_toupper.c\
ft_tolower.c\
ft_strnlen.c\
ft_is_powof2.c\
ft_next_powof2.c\
ft_to_powof2.c\
ft_max.c\
ft_min.c\
ft_ctype.c
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
D_SRC=\
ft_ainit.c\
ft_aappend.c\
ft_aremove.c\
ft_a.c\
ft_sinit.c\
ft_sappend.c\
ft_scut.c\
ft_sreverse.c\
ft_s.c\
ft_dinit.c\
ft_dexpand.c\
ft_dappend.c\
ft_dfree.c\
ft_dainit.c\
ft_daappend.c\
ft_daremove.c\
ft_dalink.c\
ft_da.c\
ft_dafree.c\
ft_dsinit.c\
ft_dsappend.c\
ft_dslink.c\
ft_dsfree.c\
ft_ddinit.c\
ft_ddnew.c\
ft_ddappend.c\
ft_ddremove.c\
ft_ddlink.c\
ft_ddfree.c\
ft_ddsinit.c\
ft_ddsappend.c\
ft_dds.c\
ft_ddsfree.c\
ft_dds_len.c\
ft_vscreate.c\
ft_vssub.c\
ft_vsinc.c\
ft_vs.c\
ft_vsreset.c\
ft_vs_strtou.c\
ft_vs_strtol.c\
ft_vs_read_uint.c\
ft_vs_read_int.c
D_OBJ=$(D_SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	cc -Wall -Werror -Wextra -c $< -o $@ -g

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

d: $(NAME) d_add
d_add: $(D_OBJ)
	ar rc $(NAME) $?
	touch d_add

clean:
	rm -rf $(OBJ)
	rm -rf $(PART2_OBJ)
	rm -rf $(LIST_OBJ)
	rm -rf $(D_OBJ)
	rm -rf part2_add
	rm -rf list_add
	rm -rf d_add

fclean: clean
	rm -rf $(NAME)

re: fclean all
