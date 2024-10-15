NAME		= get_signal

CC			=	cc
RM			=	rm -rf
MLXP		=	./minilibx
OBJDIR		=	.objFiles
CFLAGS		=	-w -g
SRC			=	get_signal

OBJ			=	$(addprefix $(OBJDIR)/, $(SRC:=.o))
MLX			=	$(MLXPATH)/libmlx.a

all: $(NAME)

MACOS_FLAG = -framework OpenGL -framework AppKit
LINUX_FLAG = -Imlx_linux -lXext -lX11 -lm -lz

LINUX_OBJ_FLAG = -Imlx_linux -O3 -DMAC_OS=0
MACOS_OBJ_FLAG = -Imlx -DMAC_OS=1

ifeq ($(shell uname), Linux)
	MLXFLAG = $(LINUX_FLAG)
	CFLAGS += $(LINUX_OBJ_FLAG)
	MLXPATH = $(addprefix $(MLXP)-,linux)
else
	MLXFLAG = $(MACOS_FLAG)
	CFLAGS += $(MACOS_OBJ_FLAG)
	MLXPATH = $(addprefix $(MLXP)-,macos)
endif

$(NAME): $(OBJ) $(MLX)
# clear
	@echo "\033[95m    - Compiling $(NAME)...\033[0m\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(MLXFLAG)
	@echo "\033[92m    - Compilation Over.✅\033[0m"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX) :
	@make -C $(MLXPATH)

clean:
	clear
	@make clean -C $(MLXPATH)
	@$(RM) $(OBJDIR) $(OBJ)
	@clear
	@echo "\033[95m    - ⛔️ Executable removed-> $(NAME)\033[0m\n"
	@sleep 0.3
	clear

fclean: clean
	@$(RM) $(NAME)
	@if [ -d "$(LIBFTPATH)" ]; then make fclean -C $(LIBFTPATH); fi
	@echo "\033[92m    - Cleanup Over.✅\033[0m"
	@sleep 0.5
	clear

re: fclean all

.PHONY: all clean fclean re
