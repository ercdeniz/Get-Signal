NAME		= get_signal

CC			=	cc
RM			=	rm -rf
MLXPATH		=	./minilibx
OBJDIR		=	.objFiles

SRC			=	get_signal

OBJ			= $(addprefix $(OBJDIR)/, $(SRC:=.o))

all: $(NAME)

$(NAME): $(OBJ)
	clear
	@echo "\033[95m    - Compiling $(NAME)...\033[0m\n"
	@if [ -d "$(MLXPATH)" ]; then make -C $(MLXPATH); fi
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit
	clear
	@echo "\033[92m    - Compilation Over.✅\033[0m"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

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
