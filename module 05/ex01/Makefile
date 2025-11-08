NAME = Bureaucrat

COMP = c++
FLAGS = -Wall -Wextra -Werror

SRC = Bureaucrat.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Bureaucrat.hpp

all : $(NAME)

$(NAME) : $(OBJ)
	$(COMP) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all