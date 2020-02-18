##
## EPITECH PROJECT, 2019
## PSU_minishell1_2018
## File description:
## __Makefile__
##

CC	=	@gcc

MAKEFLAGS	+=	--no-print-directory

RM	=	rm -f

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;01;033m"
TEAL		=	"\033[1;01;35m"
RED			=	"\033[1;01;31m"
BLUE		=	"\033[1;01;34m"

CFLAGS	+=	-I./include

ML	=	./src/mini_lib/

BL	=	./src/building/

PI	=	./src/pipe/

RD	=	./src/redirection/

XE	=	./src/exec/

SP	=	./src/separator/

AL	=	./src/alias/

QU	=	./src/magic_quote/

BUILDING	=	$(BL)env.c			\
				$(BL)cmd_cd.c		\
				$(BL)cmd_exit.c		\
				$(BL)cmd_setenv.c	\
				$(BL)cmd_unsetenv.c	\
				$(BL)cmd_history.c	\
				$(BL)cmd_repeat.c	\
				./src/var/cmd_set.c		\
				./src/var/cmd_unset.c	\
				./src/var/var_gestion.c	\
				./src/var/get_env.c     \
				$(BL)building_own_env.c \
				$(BL)cmd_which.c        \
				$(BL)cmd_echo.c         \
				$(BL)cmd_echo_suit.c

PIP		=	$(PI)pipes.c		\
			$(PI)prepare_pipes.c\
			$(PI)broken_pipe.c

EXE		=	$(XE)my_exec.c		\
			$(XE)errormgt.c

ALIAS		=	$(AL)alias.c	\
			$(AL)cmd_alias.c	\
			$(AL)cmd_unalias.c	\
			$(AL)my_revstr.c	\
			$(AL)str_array_quote.c	\
			$(AL)str_array_alias.c	\
			$(AL)alias_bis.c

QUOTE		=	$(QU)quote.c    \
                $(QU)backticks.c

MINLIB		=	$(ML)free.c					\
				$(ML)get_next_line.c		\
				$(ML)my_getnbr.c			\
				$(ML)my_putstr.c			\
				$(ML)my_str_to_word_array.c	\
				$(ML)my_strcat_properly.c	\
				$(ML)my_strcmp.c			\
				$(ML)my_strdup.c			\
				$(ML)count_len.c			\
				$(ML)get_home.c				\
				$(ML)how_many_char.c		\
				$(ML)my_perror.c			\
				$(ML)change_my_value.c		\
				$(ML)check_arg.c			\
				$(ML)check_perm.c			\
				$(ML)check_that_dir.c		\
				$(ML)epuration.c			\
				$(ML)no_cmd.c				\
				$(ML)my_realloc.c			\
				$(ML)parsing_cmd.c			\
				$(ML)history.c				\
				$(ML)copy_cause_quotes.c    \
				list_lib/data_gestion.c		\
				list_lib/pops.c				\
				list_lib/pushs.c			\
				list_lib/utility_list.c

REDI		=	$(RD)redirections.c			\
				$(RD)redirection.c			\
				$(RD)double_redirections.c	\
				$(RD)search_redirect.c      \
				$(RD)pars_redirection.c

SEPA		=	$(SP)separator.c			\
				$(SP)separator_redirection.c    \
				$(SP)separator_more.c

SRC	=	./src/main.c			\
		./src/minishell.c		\
		$(BUILDING)				\
		$(MINLIB)				\
		$(PIP)					\
		$(EXE)					\
		$(REDI)					\
		$(SEPA)					\
		$(ALIAS)				\
		$(QUOTE)				\

TFILE	=	tests/tests_redirection.c	\
			tests/test_inhibitor.c		\
			tests/tests_count_len.c		\
			tests/tests_my_realloc.c	\
			tests/tests_display.c       \
			tests/test_gnl.c

NAME	=	42sh

OBJS	=	$(SRC:.c=.o)

TNAME	=	unit_test

FUNCT = ./src/minishell.c		\
		$(BUILDING)				\
		$(MINLIB)				\
		$(PIP)					\
		$(EXE)					\
		$(REDI)					\
		$(SEPA)					\
		$(QUOTE)				\
		$(ALIAS)

all		:	title $(NAME) endt
			@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : 42sh\n" $(DEFAULT)

endt:
			@$(ECHO) $(RED)"\n → [42SH CREATE]\n" $(DEFAULT)

$(NAME)		:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) &&			\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) $(CFLAGS) -c $< -o $@ &&				\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

tests_run:
			$(CC) -o $(TNAME) $(TFILE) $(FUNCT) --coverage -lcriterion -I./include
			./unit_test

tests_run_clean:
			$(RM) *.gc*
			$(RM) $(TNAME)
			$(RM) .tests_unit
			$(RM) my_file1
			$(RM) my_file2
			$(RM) test10
			$(RM) test2

clean:
			@$(RM) $(OBJS)

fclean:			clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
