NAME				:= libftprintf.a

HEADER_PATH			:= ./includes
HEADER_FILES		:= ft_printf.h

LIBFT_PATH			:= ./libft
LIBFT				:= $(LIBFT_PATH)/libft.a

SOURCE_DIRS			:= buffer/ handlers/ utils/ variants/
SOURCE_PATH			:= ./sources $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= ft_printf.c
SOURCE_FILES		+= handler_hex.c handler_percent.c handler_unsigned.c
SOURCE_FILES		+= handler_pointer.c handler_character.c handler_string.c
SOURCE_FILES		+= handler_decimal.c buffer_mutate.c buffer_append.c
SOURCE_FILES		+= core.c number_to_buffer.c error.c

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
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

.PHONY:				all clean fclean re