NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = sources/main.c \
       sources/builtins.c \
       sources/prepare_cmds.c \
       sources/end_of_prog.c \
       sources/builtins/ft_cd.c \
       sources/builtins/ft_echo.c \
       sources/builtins/ft_env.c \
       sources/builtins/ft_exit.c \
       sources/builtins/ft_export.c \
       sources/builtins/ft_pwd.c \
       sources/builtins/ft_unset.c \
       sources/builtins/utils/ft_getenv.c \
       sources/builtins/utils/ft_setenv.c \
       sources/builtins/utils/ft_unsetenv.c \
       sources/builtins/utils/write_error.c \
       sources/parsing/browse_strings.c \
       sources/parsing/parse_redirs.c \
       sources/parsing/parsing.c \
       sources/parsing/redirs/analyze_redirs.c \
       sources/parsing/redirs/redir_utils.c \
       sources/parsing/redirs/entry/en_redir_tests.c \
       sources/parsing/redirs/entry/find_dirs_en.c \
       sources/parsing/redirs/exit/check_path_utils.c \
       sources/parsing/redirs/exit/ex_redir_tests.c \
       sources/parsing/redirs/exit/find_dirs_ex.c \
       sources/parsing/string_modif/create_strings.c \
       sources/parsing/string_modif/dequote.c \
       sources/parsing/string_modif/expand.c \
       sources/parsing/string_modif/expand_utils.c \
       sources/parsing/syntax_errors/opened_quotes.c \
       sources/parsing/syntax_errors/pipe_errors.c \
       sources/parsing/syntax_errors/prepare_err_msg.c \
       sources/parsing/syntax_errors/syntax_err_msgs.c \
       sources/parsing/syntax_errors/syntax_errors.c \
       sources/pipex/child_processes/analyze_cmd.c \
       sources/pipex/child_processes/child_process.c \
       sources/pipex/child_processes/entry_redirs.c \
       sources/pipex/child_processes/exit_redirs.c \
       sources/pipex/close_and_free.c \
       sources/pipex/cmds_caller.c \
       sources/pipex/errors.c \
       sources/pipex/pipes.c \
       sources/pipex/request_limiters.c \
       sources/pipex/utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBS = -L$(LIBFT_PATH) -lft -lreadline

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re