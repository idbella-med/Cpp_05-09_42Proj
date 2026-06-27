NAME = RPN
CC = c++
FLAGS = -Wall -Wextra -Werror

SRC = main.cpp RPN.cpp
OBJ = ${SRC:.cpp=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all