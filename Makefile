NAME				:= libftprintf.a

HEADER_PATH			:= ./includes
HEADER_FILES		:= ft_printf.h

LIBFT_PATH			:= ./libft
LIBFT				:= $(LIBFT_PATH)/libft.a

SOURCE_DIRS			:= buffer/ handlers/ utils/ variants/ flags/
SOURCE_PATH			:= ./sources $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= core.c ft_printf.c
SOURCE_FILES		+= handler_specifier_percent.c handler_specifier_string.c
SOURCE_FILES		+= handler_specifier_pointer.c handler_specifier_unsigned.c
SOURCE_FILES		+= handler_specifier_decimal.c handler_specifier_character.c
SOURCE_FILES		+= handler_specifier_hex.c
SOURCE_FILES		+= handler_flag_width.c handler_flag_precision.c
SOURCE_FILES		+= handler_flag_minus.c handler_flag_zero.c
SOURCE_FILES		+= handler_flag_hash.c handler_flag_space.c
SOURCE_FILES		+= handler_flag_plus.c
SOURCE_FILES		+= buffer_mutate.c buffer_append.c buffer_create.c
SOURCE_FILES		+= buffer_append_one.c buffer_flush.c buffer_reset_flags.c
SOURCE_FILES		+= buffer_insert_fill.c
SOURCE_FILES		+= error.c number_to_buffer.c get_number_length.c
SOURCE_FILES		+= has_flags.c fill_width.c fill_precision.c

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -Wall -Wextra# -Werror
IFLAGS				:= -I $(HEADER_PATH) -I $(LIBFT_PATH)/includes
LDFLAGS				:= -L $(LIBFT_PATH) -lft
REMOVE				:= rm -rf

ifdef C_DEBUG
	CFLAGS += -g3
endif

vpath				%.c $(SOURCE_PATH)
vpath				%.h $(HEADER_PATH)

all:				$(NAME)

$(NAME):			$(OBJECT_FILES) $(LIBFT)
					ar x $(LIBFT) --output $(OBJECT_PATH)
					ar rcs $@ $(OBJECT_PATH)/*.o

$(OBJECT_PATH)/%.o:	%.c $(HEADER_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
					mkdir -p $@

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

clean:
					$(REMOVE) $(OBJECT_PATH)

fclean:				clean
					$(REMOVE) $(NAME)

re:					fclean all

m:					mandatory

mandatory:			all

b:					bonus

bonus:				all

test:				all
					sh ./tests/ft_printf_tester/test b
					make -C tests/printfTester b

.PHONY:				all clean fclean re test m mandatory b bonus
