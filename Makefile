RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = so_long
#************************************************#
#                 PATHS TO FILES                 #
#************************************************#
VALID_PATH = ./map_validation
# ERROR_PATH = ./
# SRC_PATH = ./
OBJ_PATH = ./obj

MLX_PATH = ./MLX_42
LIBFT_PATH = ./ryusupov_h/libft
LIBFTPRINTF_PATH = ./ryusupov_h/printf
GNL_PATH = ./ryusupov_h/get_next_line
#************************************************#
#                    COMMANDS                    #
#************************************************#
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
#************************************************#
#                  SOURCE FILES                  #
#************************************************#
VALID_SRC = $(VALID_PATH)/

# SRC_SRC = $(SRC_PATH)/


MAIN_SRC = main.c
#************************************************#
#                  OBJECT FILES                  #
#************************************************#
VALID_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(VALID_SRC)))
# SRC_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(SRC_SRC)))
MAIN_OBJ = $(OBJ_PATH)/main.o
#************************************************#
#                  SUB LIBRARIES                 #
#************************************************#
LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a
GNL = $(GNL_PATH)/get_lext_line.a
MLX = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
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
all: $(NAME)

$(NAME): $(MAIN_OBJ) $(VALID_OBJ) $(LIBFT) $(LIBFTPRINTF) $(GNL)
	@$(CC) $(CFLAGS) $^ -o $@
	$(ANIMATE_WELCOME)

$(OBJ_PATH)/%.o: $(VALID_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

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

$(GNL):
	@$(MAKE) -C $(GNL_PATH)

mlx:
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(LIBFTPRINTF_PATH) clean
	@$(MAKE) -C $(GNL_PATH) clean
	@$(RM) $(LIBMLX)/build
	$(ANIMATE_PROCESSING)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(LIBFTPRINTF_PATH) fclean
	@$(MAKE) -C $(GNL_PATH) fclean

re: fclean all

.PHONY: all clean fclean re mlx
#************************************************#
#               ANIMATIONS FRAMES                #
#************************************************#
