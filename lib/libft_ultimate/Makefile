OS =		$(shell uname)
SHELL =		/bin/sh
NAME =		libft.a

.SUFFIXES =	.c .o .h .a

SRCDIR =	src
INCDIR =	inc
LIBDIR =	lib
OBJDIR =	.obj

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			abs\
			atoi\
			atoi_u\
			atol\
			atol_u\
			atoll\
			atoll_u\
			beep\
			bzero\
			calloc\
			destroy_array\
			getchar\
			isalnum\
			isalpha\
			isascii\
			isdigit\
			islower\
			isprint\
			ispunct\
			isspace\
			isupper\
			itoa\
			itoa_u\
			lltoa\
			lltoa_u\
			ltoa\
			ltoa_u\
			memccpy\
			memcdup\
			memchr\
			memcmp\
			memcpy\
			memdup\
			memfind\
			memjoin\
			memmove\
			memndup\
			mempcpy\
			putchar\
			putchar_fd\
			putendl\
			putendl_fd\
			putllong\
			putllong_fd\
			putlong\
			putlong_fd\
			putnbr\
			putnbr_fd\
			putstr\
			putstr_fd\
			rplchr\
			split\
			stpcpy\
			stpncpy\
			strcasecmp\
			strcasestr\
			strcat\
			strcdup\
			strcjoin\
			strchr\
			strcmp\
			strcpy\
			strdup\
			strerase\
			strinsert\
			strisalnum\
			strisalpha\
			strisascii\
			strisdigit\
			strislower\
			strisprint\
			strisspace\
			strisupper\
			strjoin\
			strlcat\
			strlcpy\
			strlen\
			strmap\
			strmapi\
			strncasecmp\
			strncat\
			strncmp\
			strncpy\
			strndup\
			strnlen\
			strnstr\
			strntrim\
			strrchr\
			strreplace\
			strreplace_first\
			strstr\
			strtrim\
			substr\
			swap\
			tolower\
			toupper\
			wrdlen)
INC =		$(addsuffix $(word 3, $(.SUFFIXES)),\
			libft)
LIB =		$(addsuffix $(word 4, $(.SUFFIXES)),\
			)
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 2, $(.SUFFIXES)))

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -I $(INCDIR)
LCFLAGS =	$(addprefix -L, $(LIBDIR)) $(addprefix -l, $(LIB))

ifeq ($(OS), Darwin)
	KNRM =		\x1B[0m
	KRED =		\x1B[31m
	KGRN =		\x1B[32m
	KYEL =		\x1B[33m
	KBLU =		\x1B[34m
	KMAG =		\x1B[35m
	KCYN =		\x1B[36m
	KWHT =		\x1B[37m
else
	KNRM =		\e[39m
	KRED =		\e[31m
	KGRN =		\e[32m
	KYEL =		\e[33m
	KBLU =		\e[34m
	KMAG =		\e[35m
	KCYN =		\e[36m
	KWHT =		\e[37m
endif

all: $(OBJDIR) $(NAME)
	@printf "$(KGRN)\`$(NAME)\` is up to date.\n$(KNRM)"

$(OBJDIR):
	@printf "$(KYEL)➤ "
	mkdir $@
	@printf "$(KNRM)"

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@printf "$(KCYN)[  Linking  ]\n➤ "
	ranlib $@
	@printf "$(KNRM)"

$(OBJDIR)/%$(word 2, $(.SUFFIXES)): $(SRCDIR)/%$(word 1, $(.SUFFIXES)) $(addprefix $(INCDIR)/, $(INC))
	@printf "$(KMAG)[  Compiling  ]\n➤ "
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "➤ "
	ar rc $(NAME) $@
	@printf "$(KNRM)"

clean:
	@printf "$(KRED)➤ "
	rm -rf $(OBJDIR)
	@printf "$(KNRM)"

fclean: clean
	@printf "$(KRED)➤ "
	rm -f $(NAME)
	@printf "$(KNRM)"

re: fclean all
