#This makefile was auto generated, ain't no way I'm writing all that by hand
NAME=minishell
CC=clang
CFLAGS=-Wall -Werror -Wextra -I./includes/ -I/usr/include/ -O0 -ggdb -Wno-enum-compare
LINK=-L./libs/libft -lft -lreadline

CWD_SRC_PATH=./
SRC_UTILITIES_SRC_PATH=./src/utilities/
SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_SRC_PATH=./src/lexer_parser/lexer/lexeme_scanner/
SRC_LEXER_PARSER_PARSER_SRC_PATH=./src/lexer_parser/parser/
SRC_LEXER_PARSER_PARSER_INPUT_SRC_PATH=./src/lexer_parser/parser/input/
SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_SRC_PATH=./src/lexer_parser/parser/simple_command/
SRC_SIGNALS_SRC_PATH=./src/signals/
SRC_CORE_SRC_PATH=./src/core/
SRC_INPUT_SRC_PATH=./src/input/
SRC_VECARR_SRC_PATH=./src/vecarr/
SRC_DYNENV_SRC_PATH=./src/dynenv/
SRC_EXEC_BUILTINS_SRC_PATH=./src/exec/builtins/
SRC_EXEC_PIPE_EXEC_SRC_PATH=./src/exec/pipe_exec/
SRC_EXEC_CHECK_EXEC_SRC_PATH=./src/exec/check_exec/
SRC_EXEC_SIGNAL_SRC_PATH=./src/exec/signal/

CWD_SRC_FILES=main.c

SRC_UTILITIES_SRC_FILES=utils.c

SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_SRC_FILES=errors.c \
	input_utils.c \
	input_walker.c \
	literal_accumulator.c \
	scanner.c \
	cleanup_tokens.c \
	syntax_utils.c \
	token_list.c \
	identifier_expander.c \
	input_functions.c \
	scanner_methods.c \
	recursive_brace_match.c

SRC_LEXER_PARSER_PARSER_SRC_FILES=cmd.c

SRC_LEXER_PARSER_PARSER_INPUT_SRC_FILES=commander.c

SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_SRC_FILES=scmd.c \
	scmd_from_tokens.c \
	scmd_inserts.c

SRC_SIGNALS_SRC_FILES=sig_input.c

SRC_CORE_SRC_FILES=core.c \
	core_env.c

SRC_INPUT_SRC_FILES=heredoc.c \
	reader.c \
	utils.c

SRC_VECARR_SRC_FILES=all.c \
	delete.c \
	destroy.c \
	filter.c \
	find.c \
	init.c \
	join.c \
	map.c \
	mem_utils.c \
	pop.c \
	push.c \
	reverse.c \
	slice.c \
	some.c \
	string_utils.c \
	sum.c

SRC_DYNENV_SRC_FILES=get.c \
	insert.c \
	remove.c \
	replace.c \
	setup.c

SRC_EXEC_BUILTINS_SRC_FILES=exit.c \
	env.c \
	export.c \
	unset.c \
	cd.c \
	pwd.c \
	echo.c

SRC_EXEC_PIPE_EXEC_SRC_FILES=utils.c \
	redir.c \
	builtins_exec.c \
	multi_pipe.c \
	utils_2.c

SRC_EXEC_CHECK_EXEC_SRC_FILES=check_command_access.c \
	check_builtins.c \
	check_builtins_2.c \
	check_redir.c

SRC_EXEC_SIGNAL_SRC_FILES=handle_signal.c


CWD_FULL_PATH=$(addprefix $(CWD_SRC_PATH), $(CWD_SRC_FILES))
SRC_UTILITIES_FULL_PATH=$(addprefix $(SRC_UTILITIES_SRC_PATH), $(SRC_UTILITIES_SRC_FILES))
SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_FULL_PATH=$(addprefix $(SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_SRC_PATH), $(SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_SRC_FILES))
SRC_LEXER_PARSER_PARSER_FULL_PATH=$(addprefix $(SRC_LEXER_PARSER_PARSER_SRC_PATH), $(SRC_LEXER_PARSER_PARSER_SRC_FILES))
SRC_LEXER_PARSER_PARSER_INPUT_FULL_PATH=$(addprefix $(SRC_LEXER_PARSER_PARSER_INPUT_SRC_PATH), $(SRC_LEXER_PARSER_PARSER_INPUT_SRC_FILES))
SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_FULL_PATH=$(addprefix $(SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_SRC_PATH), $(SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_SRC_FILES))
SRC_SIGNALS_FULL_PATH=$(addprefix $(SRC_SIGNALS_SRC_PATH), $(SRC_SIGNALS_SRC_FILES))
SRC_CORE_FULL_PATH=$(addprefix $(SRC_CORE_SRC_PATH), $(SRC_CORE_SRC_FILES))
SRC_INPUT_FULL_PATH=$(addprefix $(SRC_INPUT_SRC_PATH), $(SRC_INPUT_SRC_FILES))
SRC_VECARR_FULL_PATH=$(addprefix $(SRC_VECARR_SRC_PATH), $(SRC_VECARR_SRC_FILES))
SRC_DYNENV_FULL_PATH=$(addprefix $(SRC_DYNENV_SRC_PATH), $(SRC_DYNENV_SRC_FILES))
SRC_EXEC_BUILTINS_FULL_PATH=$(addprefix $(SRC_EXEC_BUILTINS_SRC_PATH), $(SRC_EXEC_BUILTINS_SRC_FILES))
SRC_EXEC_PIPE_EXEC_FULL_PATH=$(addprefix $(SRC_EXEC_PIPE_EXEC_SRC_PATH), $(SRC_EXEC_PIPE_EXEC_SRC_FILES))
SRC_EXEC_CHECK_EXEC_FULL_PATH=$(addprefix $(SRC_EXEC_CHECK_EXEC_SRC_PATH), $(SRC_EXEC_CHECK_EXEC_SRC_FILES))
SRC_EXEC_SIGNAL_FULL_PATH=$(addprefix $(SRC_EXEC_SIGNAL_SRC_PATH), $(SRC_EXEC_SIGNAL_SRC_FILES))

CWD_OBJ=$(CWD_FULL_PATH:.c=.o)
SRC_UTILITIES_OBJ=$(SRC_UTILITIES_FULL_PATH:.c=.o)
SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_OBJ=$(SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_FULL_PATH:.c=.o)
SRC_LEXER_PARSER_PARSER_OBJ=$(SRC_LEXER_PARSER_PARSER_FULL_PATH:.c=.o)
SRC_LEXER_PARSER_PARSER_INPUT_OBJ=$(SRC_LEXER_PARSER_PARSER_INPUT_FULL_PATH:.c=.o)
SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_OBJ=$(SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_FULL_PATH:.c=.o)
SRC_SIGNALS_OBJ=$(SRC_SIGNALS_FULL_PATH:.c=.o)
SRC_CORE_OBJ=$(SRC_CORE_FULL_PATH:.c=.o)
SRC_INPUT_OBJ=$(SRC_INPUT_FULL_PATH:.c=.o)
SRC_VECARR_OBJ=$(SRC_VECARR_FULL_PATH:.c=.o)
SRC_DYNENV_OBJ=$(SRC_DYNENV_FULL_PATH:.c=.o)
SRC_EXEC_BUILTINS_OBJ=$(SRC_EXEC_BUILTINS_FULL_PATH:.c=.o)
SRC_EXEC_PIPE_EXEC_OBJ=$(SRC_EXEC_PIPE_EXEC_FULL_PATH:.c=.o)
SRC_EXEC_CHECK_EXEC_OBJ=$(SRC_EXEC_CHECK_EXEC_FULL_PATH:.c=.o)
SRC_EXEC_SIGNAL_OBJ=$(SRC_EXEC_SIGNAL_FULL_PATH:.c=.o)


$(NAME): $(CWD_OBJ) $(SRC_UTILITIES_OBJ) $(SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_OBJ) $(SRC_LEXER_PARSER_PARSER_OBJ) $(SRC_LEXER_PARSER_PARSER_INPUT_OBJ) $(SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_OBJ) $(SRC_SIGNALS_OBJ) $(SRC_CORE_OBJ) $(SRC_INPUT_OBJ) $(SRC_VECARR_OBJ) $(SRC_DYNENV_OBJ) $(SRC_EXEC_BUILTINS_OBJ) $(SRC_EXEC_PIPE_EXEC_OBJ) $(SRC_EXEC_CHECK_EXEC_OBJ) $(SRC_EXEC_SIGNAL_OBJ)
	make -C ./libs/libft
	$(CC) $(CFLAGS) -o $@ $^ $(LINK)

all: $(NAME)

clean:
	rm -f $(CWD_OBJ)
	rm -f $(SRC_UTILITIES_OBJ)
	rm -f $(SRC_LEXER_PARSER_LEXER_LEXEME_SCANNER_OBJ)
	rm -f $(SRC_LEXER_PARSER_PARSER_OBJ)
	rm -f $(SRC_LEXER_PARSER_PARSER_INPUT_OBJ)
	rm -f $(SRC_LEXER_PARSER_PARSER_SIMPLE_COMMAND_OBJ)
	rm -f $(SRC_SIGNALS_OBJ)
	rm -f $(SRC_CORE_OBJ)
	rm -f $(SRC_INPUT_OBJ)
	rm -f $(SRC_VECARR_OBJ)
	rm -f $(SRC_DYNENV_OBJ)
	rm -f $(SRC_EXEC_BUILTINS_OBJ)
	rm -f $(SRC_EXEC_PIPE_EXEC_OBJ)
	rm -f $(SRC_EXEC_CHECK_EXEC_OBJ)
	rm -f $(SRC_EXEC_SIGNAL_OBJ)
	make clean -C ./libs/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libs/libft

re: fclean all

default: all

.PHONY: default all re fclean clean