NAME = libft.a

SRCS =  ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \
		ft_printf/ft_fprintf.c \
		ft_printf/ft_printf_utils_2.c \
		assert/assert.c \
		strings/ft_endswith.c \
		strings/ft_strcat.c \
		strings/ft_strset.c \
		strings/ft_strchr.c \
		strings/ft_strjoin.c \
		strings/ft_strcpy.c \
		strings/ft_strcspn.c \
		strings/ft_center.c \
		strings/ft_strsjoin.c \
		strings/ft_startswith.c \
		strings/ft_strcmp.c \
		strings/ft_zfill.c \
		strings/ft_swapcase.c \
		strings/ft_memchr.c \
		strings/ft_memmove.c \
		strings/ft_strstr.c \
		strings/ft_strcase.c \
		strings/ft_memset.c \
		strings/ft_count_words.c \
		strings/ft_strlen.c \
		strings/ft_memcmp.c \
		strings/ft_split.c \
		strings/ft_bzero.c \
		strings/ft_strsub.c \
		strings/ft_capitalize.c \
		strings/ft_strip.c \
		strings/ft_ccnt.c \
		strings/ft_strdup.c \
		strings/ft_strrev.c \
		strings/ft_split_lines.c \
		strings/ft_index.c \
		strings/ft_memcpy.c \
		strings/ft_replace.c \
		conversions/ft_itoa.c \
		conversions/ft_atoll.c \
		conversions/ft_toupper.c \
		conversions/ft_tolower.c \
		conversions/ft_atol.c \
		conversions/ft_atoi.c \
		sort/ascending_comparators.c \
		sort/descending_comparators.c \
		chartype/ft_isprint.c \
		chartype/ft_iscntrl.c \
		chartype/ft_isupper.c \
		chartype/ft_isgraph.c \
		chartype/ft_isascii.c \
		chartype/ft_isspace.c \
		chartype/ft_isblank.c \
		chartype/ft_isxdigit.c \
		chartype/ft_ispunct.c \
		chartype/ft_isalpha.c \
		chartype/ft_isalnum.c \
		chartype/ft_isdigit.c \
		chartype/ft_islower.c \
		memory/ft_memory.c \
		memory/realloc.c \
		lists/ft_lst_prepend.c \
		lists/ft_lst_last.c \
		lists/ft_lst_init.c \
		lists/ft_lst_append.c \
		lists/ft_lst_get.c \
		lists/ft_lst_reverse.c \
		lists/ft_lst_pop.c \
		lists/ft_lst_clear.c \
		lists/ft_lst_copy.c \
		lists/ft_lst_new.c \
		lists/ft_lst_insert.c \
		lists/ft_lst_remove.c \
		lists/ft_lst_count.c \
		lists/ft_lst_first.c \
		lists/ft_lst_index.c \
		file/read_file.c \
		file/read_n_bytes.c \
		file/file_size.c \
		put/ft_putchar.c \
		put/ft_putstr.c \
		put/ft_putendl.c \
		put/ft_putnbr.c \
		math/ft_factorial.c \
		math/ft_fibonacci.c \
		math/ft_abs.c \
		math/ft_round.c \
		math/ft_sqrt.c \
		math/ft_pow.c \
		math/ft_isprime.c \

OBJS := ${SRCS:.c=.o}

CC = clang

RM = rm -f

INC_DIR = includes

CFLAGS =  -Wall -Wextra -Werror -O2 -g3

.c.o:
	${CC} ${CFLAGS} -c -I ${INC_DIR} $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $(NAME) ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re