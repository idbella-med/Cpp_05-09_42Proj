NAME = identify

COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	Base.cpp
	
OBJ = $(SRCS:.cpp=.o)

HEADER = Base.hpp

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


# change it tomorow ll ?