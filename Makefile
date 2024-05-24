RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = so_long
#************************************************#
#                 PATHS TO FILES                 #
#************************************************#
MLX_PATH = MLX42
OBJ_PATH = ./obj
LIBFT_PATH = ./ryusupov_h/libft
LIBFTPRINTF_PATH = ./ryusupov_h/printf
MLX_SRC_PATH = $(shell find . -iname "*.c")
#************************************************#
#                    COMMANDS                    #
#************************************************#
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
#************************************************#
#                  SOURCE FILES                  #
#************************************************#
MAIN_SRC = main.c
#************************************************#
#                  OBJECT FILES                  #
#************************************************#
# VALID_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(VALID_SRC)))
# SRC_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(SRC_SRC)))
MAIN_OBJ = $(OBJ_PATH)/main.o
#************************************************#
#                     HEADERS                    #
#************************************************#
INC	:= -I ./include -I $(MLX_PATH)/include
#************************************************#
#                  SUB LIBRARIES                 #
#************************************************#
LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a
MLX = $(MLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm
#************************************************#
#                   ANIMATIONS                   #
#************************************************#
 define ANIMATE_WELCOME
     @printf "\n\033[1;32mProcessing"
     @sleep 0.1
     @for i in {1..10}; do \
         printf "."; \
         sleep 0.2; \
     done
     @printf "\033[0m\n\n\n"
     @sleep 0.5
     @for frame in $(FRAMES); do \
         printf "\x1b[35m%s\n\033[0m" $$frame; \
         sleep 0.1; \
     done
     @echo
 endef

 define ANIMATE_PROCESSING
     @printf "\n\033[1;31mCleaning"
     @sleep 0.5
     @for i in {1..10}; do \
         printf "."; \
         sleep 0.1; \
     done
     @printf "\033[0m\n\n"
 endef
#************************************************#
#                  COMPILATIONS                  #
#************************************************#
all: mlx $(NAME)

mlx:
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(NAME): $(MAIN_OBJ) $(LIBFT) $(LIBFTPRINTF) $(MLX) $(INC) $(MLX_SRC_PATH)
	@$(CC) $(CFLAGS) $^ -o $@
	$(ANIMATE_WELCOME)

# $(OBJ_PATH)/%.o: $(VALID_PATH)/%.c | $(OBJ_PATH)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
# 	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/main.o: $(MAIN_SRC) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

# $(GNL):
# 	@$(MAKE) -C $(GNL_PATH)

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(LIBFTPRINTF_PATH) clean
	@$(RM) MLX42/build
	$(ANIMATE_PROCESSING)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(LIBFTPRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re mlx
#************************************************#
#               ANIMATIONS FRAMES                #
#************************************************#

