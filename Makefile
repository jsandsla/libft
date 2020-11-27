
NAME=libft.a

SRC=\
ft_memset.c\
ft_memset4.c\
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
ft_double.c\
ft_modf.c\
ft_modf_rounded.c\
ft_sqrt.c\
ft_ctype.c
OBJ=$(SRC:.c=.o)
PART1_SRC=\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c
PART1_OBJ=$(PART1_SRC:.c=.o)
FD_SRC=\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c
FD_OBJ=$(FD_SRC:.c=.o)
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
ft_minit.c\
ft_mwrite.c\
ft_mappend.c\
ft_mmove.c\
ft_mcut.c\
ft_m.c\
ft_ainit.c\
ft_aappend.c\
ft_aremove.c\
ft_a.c\
ft_sinit.c\
ft_sappend.c\
ft_smove.c\
ft_scut.c\
ft_sreverse.c\
ft_s.c\
ft_s_itoa.c\
ft_dinit.c\
ft_dexpand.c\
ft_dappend.c\
ft_dfree.c\
ft_dainit.c\
ft_daexpand.c\
ft_daappend.c\
ft_danew.c\
ft_daremove.c\
ft_da.c\
ft_dafree.c\
ft_dsinit.c\
ft_dsexpand.c\
ft_dsappend.c\
ft_dsfree.c\
ft_ddinit.c\
ft_ddnew.c\
ft_ddappend.c\
ft_ddremove.c\
ft_ddfree.c\
ft_ddsinit.c\
ft_ddsappend.c\
ft_dds.c\
ft_ddsfree.c\
ft_dds_len.c\
ft_dds_spread.c\
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
VMATH_SRC=\
ft_usev3.c\
ft_usev4.c\
ft_m3.c\
ft_m4.c\
ft_make_v.c\
ft_invm4.c\
ft_opv3.c\
ft_opvsv3.c\
ft_opv4.c\
ft_opvsv4.c\
ft_identity_m.c
VMATH_OBJ=$(VMATH_SRC:.c=.o)
VMATH_EXT_SRC=\
ft_make_m3rot.c\
ft_extv.c
VMATH_EXT_OBJ=$(VMATH_EXT_SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	cc -Wall -Werror -Wextra -c $< -o $@ $(DEBUG)

$(NAME): $(OBJ)
	ar rc $(NAME) $?

part1: $(NAME)
part1: $(PART1_OBJ)
	ar rc $(NAME) $?

fd: $(NAME)
fd: $(FD_OBJ)
	ar rc $(NAME) $?

list: $(NAME)
list: $(LIST_OBJ)
	ar rc $(NAME) $?

d: $(NAME)
d: $(D_OBJ)
	ar rc $(NAME) $?

vmath: $(NAME)
vmath: $(VMATH_OBJ)
	ar rc $(NAME) $?

vmath_ext: $(NAME)
vmath_ext: $(VMATH_EXT_OBJ) $(VMATH_OBJ)
	ar rc $(NAME) $?

clean:
	rm -rf $(OBJ)
	rm -rf $(PART1_OBJ)
	rm -rf $(FD_OBJ)
	rm -rf $(LIST_OBJ)
	rm -rf $(D_OBJ)
	rm -rf $(VMATH_OBJ)
	rm -rf $(VMATH_EXT_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
