NAME				:= libftprintf.a

HEADER_PATH			:= ./includes
HEADER_FILES		:= ft_printf.h

LIBFT_PATH			:= ./libft
LIBFT				:= $(LIBFT_PATH)/libft.a

SOURCE_DIRS			:= buffer/ handlers/ utils/ variants/ flags/
SOURCE_PATH			:= ./sources $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= ft_printf.c
SOURCE_FILES		+= handler_specifier_percent.c handler_specifier_string.c
SOURCE_FILES		+= handler_specifier_pointer.c handler_specifier_unsigned.c
SOURCE_FILES		+= handler_specifier_decimal.c handler_specifier_character.c
SOURCE_FILES		+= handler_specifier_hex.c handler_flag_width.c core.c
SOURCE_FILES		+= error.c buffer_mutate.c buffer_append.c buffer_create.c
SOURCE_FILES		+= buffer_append_one.c buffer_flush.c buffer_reset_flags.c
SOURCE_FILES		+= number_to_buffer.c fill_width.c get_number_length.c

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

test:				b

m:					mandatory

mandatory:			all
					sh ./tests/ft_printf_tester/test m
					make -C tests/printfTester m

b:					bonus

bonus:				all
					sh ./tests/ft_printf_tester/test b
					make -C tests/printfTester b

.PHONY:				all clean fclean re test m mandatory b bonus
