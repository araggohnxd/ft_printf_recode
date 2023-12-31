NAME				:= libft.a
SO					:= $(NAME:.a=.so)

HEADER_PATH			:= ./includes
HEADER_FILES		:= libft.h ft_internals.h

SOURCE_DIRS			:= ctype string stdio stdlib
SOURCE_DIRS			+= custom non_standard linked_list hash_table
SOURCE_PATH			:= $(addprefix ./sources/, $(SOURCE_DIRS))

# ctype
SOURCE_FILES		:= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c
SOURCE_FILES		+= ft_isspace.c ft_isprint.c ft_tolower.c ft_toupper.c

# string
SOURCE_FILES		+= ft_bzero.c ft_memccpy.c ft_memchr.c ft_memrchr.c
SOURCE_FILES		+= ft_memcmp.c ft_memmove.c ft_mempcpy.c ft_memset.c
SOURCE_FILES		+= ft_strdup.c ft_strndup.c ft_strlen.c ft_strnlen.c
SOURCE_FILES		+= ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c
SOURCE_FILES		+= ft_strnstr.c ft_memcpy.c

# stdio
SOURCE_FILES		+= ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SOURCE_FILES		+= ft_putchar_fd.c

# stdlib
SOURCE_FILES		+= ft_atof.c ft_atoi.c ft_atoll.c ft_calloc.c

# custom
SOURCE_FILES		+= ft_gnl.c ft_gnl_multifd.c ft_memfree.c ft_free_matrix.c
SOURCE_FILES		+= ft_skip_chars.c ft_split.c ft_striteri.c ft_strmapi.c
SOURCE_FILES		+= ft_strjoin.c ft_strjoin_free.c ft_strjoin_free_null.c
SOURCE_FILES		+= ft_strtrim.c ft_strtrim_free.c ft_strtrim_free_null.c
SOURCE_FILES		+= ft_substr.c ft_stredit.c ft_splitsize.c ft_isfloat.c
SOURCE_FILES		+= ft_isnumber.c ft_isinrange_f.c ft_isinrange_i.c
SOURCE_FILES		+= ft_swap_set.c

# non_standard
SOURCE_FILES		+= ft_itoa_base.c ft_itoa.c ft_strlcat.c ft_strlcpy.c
SOURCE_FILES		+= ft_utoa.c

# linked_list
SOURCE_FILES		+= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c
SOURCE_FILES		+= ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c
SOURCE_FILES		+= ft_lstdelone.c ft_lstsize.c

# hash_table
SOURCE_FILES		+= ft_htadd.c ft_htclear.c ft_htdelone.c ft_htfree.c
SOURCE_FILES		+= ft_htnew.c ft_htsearch.c ft_hthasher.c

OBJECT_PATH			:= objects
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

vpath				%.c $(SOURCE_PATH)
vpath				%.h $(HEADER_PATH)

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
IFLAGS				:= -I $(HEADER_PATH)
REMOVE				:= rm -rf

ifdef DEBUG
	CFLAGS += -g3
else
	CFLAGS += -O3
endif

all:				$(NAME)

$(NAME):			$(OBJECT_FILES) $(OBJECT_PATH)
					ar -rcs $@ $(OBJECT_FILES)

so:					$(SO)

$(SO):				$(OBJECT_FILES) $(OBJECT_PATH)
					$(CC) $(CFLAGS) -nostartfiles -shared -o $@ $(OBJECT_FILES)

$(OBJECT_PATH)/%.o:	%.c $(HEADER_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
					mkdir -p $@

clean:
					$(REMOVE) $(OBJECT_PATH)

fclean:				clean
					$(REMOVE) $(NAME) $(SO)

re:					fclean all

.PHONY:				all clean fclean re so
