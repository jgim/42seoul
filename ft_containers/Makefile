NAME = ft_container
SOURCES_FOLDER	= ./tester/
SOURCES			=	main.cpp
FLAGS 			= -Wall -Wextra -Werror --std=c++98

OBJECTS_FOLDER 	= ./tester/obj/

OBJECT			= $(SOURCES:.cpp=.o)
OBJECTS		 	= $(addprefix $(OBJECTS_FOLDER), $(OBJECT));

$(OBJECTS_FOLDER)%.o :	$(SOURCES_FOLDER)%.cpp
	@mkdir -p	$(OBJECTS_FOLDER)
	@echo "Compiling: $<"
	@clang++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@clang++ $(FLAGS) -o $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJECTS_FOLDER)"
	@rm -rf $(OBJECTS_FOLDER)

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)

re: fclean all

run: $(NAME)
	@./$(NAME)
