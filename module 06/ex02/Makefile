NAME = Data

COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Serializer.cpp
	
OBJ = $(SRCS:.cpp=.o)

HEADER = Serializer.hpp Data.hpp

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


# change it tomorow