NAME				:= so_long
CC					:= gcc
CFLAGS				:= -Wextra -Wall -Werror -g
RM					:= rm -rf
#************************************************#
#                 PATHS TO FILES                 #
#************************************************#
LIBMLX				:= ./MLX42
OBJ_PATH			:= ./obj
LIBFT_PATH			:= ./ryusupov_h/libft
LIBFTPRINTF_PATH	:= ./ryusupov_h/printf
VALIDATION_PATH		:= ./validation
#************************************************#
#                 SOURCE FILES                   #
#************************************************#
INCS				:= -I ./include/MLX42 -I $(LIBMLX)/include/MLX42 -I $(LIBFT_PATH) -I $(LIBFTPRINTF_PATH)
LIBS				:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS				:=	main.c \
					validation/error_check_utils.c \
					validation/error_check.c \
					validation/error_free.c \
					validation/map_validation.c \
					validation/map_check.c \
					validation/struct.c \
					validation/indexing.c \
					validation/e_c_not_reachable.c \
					validation/way_check_utils.c

OBJS				:= $(patsubst %, $(OBJ_PATH)/%, $(SRCS:.c=.o))

LIBFT				:= $(LIBFT_PATH)/libft.a
LIBFTPRINTF			:= $(LIBFTPRINTF_PATH)/libftprintf.a

#************************************************#
#                  COMPILATIONS                  #
#************************************************#
all: $(LIBFT) $(LIBFTPRINTF) libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)/validation
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/validation:
	@mkdir -p $(OBJ_PATH)/validation

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null 2>&1

$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_PATH) > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(LIBFTPRINTF) $(INCS) -o $(NAME)
	$(ANIMATE_WELCOME)

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@$(MAKE) -C $(LIBFTPRINTF_PATH) clean > /dev/null 2>&1
	@$(RM) $(LIBMLX)/build
	$(ANIMATE_PROCESSING)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@$(MAKE) -C $(LIBFTPRINTF_PATH) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re libmlx

#************************************************#
#                   ANIMATIONS                   #
#************************************************#
define ANIMATE_WELCOME
	@printf "\n\033[1;32mStarting the build process"
	@sleep 0.1
	@bash -c 'for i in {1..3}; do \
		printf "."; \
		sleep 0.5; \
	done'
	@printf "\033[0m\n\n\n"
	@sleep 0.5
	@printf "\033[1;34mBuilding the project\033[0m\n"
	@bash -c 'for i in {1..5}; do \
		printf "\033[1;33mCompiling file %d of 5...\033[0m\n" $$i; \
		sleep 0.3; \
		printf "\033[1;32mDone!\033[0m\n"; \
		sleep 0.3; \
	done'
	@sleep 0.5
	@bash -c 'for i in {1..3}; do \
		printf "\033[1;35mLinking...\033[0m\n"; \
		sleep 0.5; \
	done'
	@printf "\033[1;32mBuild successful! 🎉\033[0m\n\n"
	@sleep 0.5
	@printf "\033[1;34mWelcome to the GAME !!!\033[0m\n\n"
	@sleep 0.5
	@for frame in $(FRAMES); do \
		printf "\033[1;35m%s\n\033[0m" "$$frame"; \
		sleep 0.1; \
	done
	@echo
endef

define ANIMATE_PROCESSING
	@printf "\n\033[1;31mCleaning up the mess"
	@sleep 0.5
	@bash -c 'for i in {1..3}; do \
		printf "."; \
		sleep 0.2; \
	done'
	@printf "\033[0m\n\n"
	@sleep 0.5
	@bash -c 'for i in {1..5}; do \
		printf "\033[1;33mRemoving object files %d of 5...\033[0m\n" $$i; \
		sleep 0.3; \
		printf "\033[1;32mGone!\033[0m\n"; \
		sleep 0.3; \
	done'
	@sleep 0.5
	@bash -c 'for i in {1..3}; do \
		printf "\033[1;35mSweeping...\033[0m\n"; \
		sleep 0.5; \
	done'
	@printf "\033[1;32mCleanup complete! 🧹\033[0m\n\n"
	@sleep 0.5
	@printf "\033[1;34mAll done! The workspace is clean.\033[0m\n"
	@sleep 0.5
	@echo
endef
#************************************************#
#               ANIMATIONS FRAMES                #
#************************************************#

FRAMES :=	"ssssss███████╗s██████╗sssssssss██╗ssssss██████╗s███╗sss██╗s██████╗sssssss"\
			"ssssss██╔════╝██╔═══██╗ssssssss██║sssss██╔═══██╗████╗ss██║██╔════╝sssssss"\
			"█████╗███████╗██║sss██║ssssssss██║sssss██║sss██║██╔██╗s██║██║ss███╗█████╗"\
			"╚════╝╚════██║██║sss██║ssssssss██║sssss██║sss██║██║╚██╗██║██║sss██║╚════╝"\
			"ssssss███████║╚██████╔╝███████╗███████╗╚██████╔╝██║s╚████║╚██████╔╝ssssss"\
			"ssssss╚══════╝s╚═════╝s╚══════╝╚══════╝s╚═════╝s╚═╝ss╚═══╝s╚═════╝sssssss"\
			"sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
