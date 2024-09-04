NAME		:= libft.a
SRC_FILES	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_DIR 	:= src
B_SRC_FILES	:= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
B_SRC_DIR 	:= b_src

SRCS		+= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
B_SRCS		+= $(addprefix $(B_SRC_DIR)/, $(B_SRC_FILES))

OBJ_DIR 	:= obj
B_OBJ_DIR	:= $(OBJ_DIR)
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%.c=%.o))
B_OBJS		:= $(addprefix $(B_OBJ_DIR)/, $(B_SRC_FILES:%.c=%.o))

CC			:= cc
CFLAGS 		:= -Wall -Wextra -Werror

RM			:= rm -f
AR			:= ar rc

ifdef WITH_BONUS
	OBJS	+= $(B_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	make WITH_BONUS=1

clean:
	$(RM) $(OBJS) $(B_OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus