NAME = AForm

COMP = c++
FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp
	
OBJ = $(SRCS:.cpp=.o)

HEADER = Bureaucrat.hpp \
       AForm.hpp \
       ShrubberyCreationForm.hpp \
       RobotomyRequestForm.hpp \
       PresidentialPardonForm.hpp

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