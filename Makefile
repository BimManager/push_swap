# push_swap & checker Makefile

CC := gcc
AR := ar
LD := ld
CFLAGS := -g -Wall -Werror -Wextra -c \
		-I./include -I./libft/include
ARFLAGS := -q -c
LDFLAGS := -lc -L./libft -lft \
			-e _main -arch x86_64 -macosx_version_min 10.13

INCDIR := include
SRCDIR := src
OBJDIR := build

SRCS_PS := $(addprefix $(SRCDIR)/, \
		push_swap.c ft_inputparse.c ft_sort.c \
		ft_isint.c ft_issorted.c ft_utils.c \
		ft_swapops.c ft_pushops.c ft_rotops.c \
		ft_rrotops.c ft_stacksput.c ft_presort.c \
		ft_selsort.c ft_qlikesort.c)

SRCS_CHK := $(addprefix $(SRCDIR)/, \
		checker.c ft_inputparse.c ft_check.c \
		ft_swapops.c ft_pushops.c ft_rotops.c \
		ft_rrotops.c ft_stacksput.c ft_issorted.c \
		ft_ops.c ft_isint.c ft_utils.c)

OBJS_PS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS_PS))
OBJS_CHK := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS_CHK))

NAME_PS := push_swap
NAME_CHK := checker

all : $(NAME_PS) $(NAME_CHK)

$(NAME_PS) : $(OBJS_PS)
	@if [[ ! -e ./libft/libft.a ]]; then make -C ./libft; fi
	$(LD) $(LDFLAGS) $^ -o $@

$(NAME_CHK) : $(OBJS_CHK)
	@if [[ ! -e ./libft/libft.a ]]; then make -C ./libft; fi
	$(LD) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@if [[ ! -e $(OBJDIR) ]]; then mkdir $(OBJDIR); fi
	@$(CC) $(CFLAGS) $< -o $@

.PNOHY : all clean fclean re

clean :
	@if [[ -e $(OBJDIR) ]]; then rm -rf $(OBJDIR); fi
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CHK)
	@make fclean -C ./libft

re : fclean all