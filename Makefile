NAME = test

SRCS_LIST = tests/List_test.cpp
SRCS_VEC = tests/Vector_test.cpp
SRCS_STACK = tests/Stack_test.cpp
SRCS_QUEUE = tests/Queue_test.cpp
SRCS_MAP = tests/Map_test.cpp

CFLAGS = -Wall -Werror -Wextra

OBJS_L = $(SRCS_LIST:.cpp=.o)
OBJS_V = $(SRCS_VEC:.cpp=.o)
OBJS_S = $(SRCS_STACK:.cpp=.o)
OBJS_Q = $(SRCS_QUEUE:.cpp=.o)
OBJS_M = $(SRCS_MAP:.cpp=.o)

all: list
	
list: $(OBJS_L)
	clang++ $(OBJS_L) -lm -o $(NAME) -g
	@echo "$(NAME) list created"

vector: $(OBJS_V)
	clang++ $(OBJS_V) -lm -o $(NAME) -fsanitize=address -g
	@echo "$(NAME) vector created"

stack: $(OBJS_S)
	clang++ $(OBJS_S) -lm -o $(NAME) -g
	@echo "$(NAME) stack created"

queue: $(OBJS_Q)
	clang++ $(OBJS_Q) -lm -o $(NAME) -g
	@echo "$(NAME) queue created"

map: $(OBJS_M)
	clang++ $(OBJS_M) -lm -o $(NAME) -g
	@echo "$(NAME) map created"

$(OBJS_L)/%.o: %.cpp Makefile
	clang++ $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -rf tests/*.o
	@echo "Object files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "binary deleted"

re : 
	@make fclean
	@make all

.PHONY: all, clean, fclean, re, all