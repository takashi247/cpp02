NAME		:= a.out

CXX			:= clang++

CXXFLAGS	:= -Wall -Wextra -Werror -MMD -MP -std=c++98

SRCSDIR		:= srcs/

OBJSDIR		:= objs/

SRCS		:= main.cpp \
				Fixed.cpp \
				Point.cpp \
				bsp.cpp

OBJS		:= $(addprefix $(OBJSDIR), $(SRCS:.cpp=.o))

DEPS		:= $(OBJS:.o=.d)

SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))

VPATH		:= $(SRCSDIR)

INCLUDE		:= -I./include

RM			:= rm -rf

DEBUG		:= -g# -fsanitize=address

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

$(OBJSDIR)%.o: %.cpp
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJSDIR)
	$(RM) *.dSYM

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

debug:		CXXFLAGS += $(DEBUG)
debug:		re

-include $(DEPS)

.PHONY:		all clean fclean re debug