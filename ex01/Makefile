NAME = RPN
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
SRC = .
OBJ = obj

SRCS = main.cpp src/RPN.cpp
OBJS = $(addprefix $(OBJ)/, $(notdir $(SRCS:.cpp=.o)))

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/src/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
