NAME = converter

COMP = c++
FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
       ScalarConverter.cpp
	
OBJ = $(SRC:.cpp=.o)

HEADER = ScalarConverter.hpp

all : $(NAME)

$(NAME) : $(OBJ) 
	$(COMP) $(FLAGS) $^ -o $@

%.o : %.cpp $(HEADER)
	$(COMP) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all