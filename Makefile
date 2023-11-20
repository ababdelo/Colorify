# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 13:22:16 by ababdelo          #+#    #+#              #
#    Updated: 2023/11/20 11:05:29 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.PHONY: all clean fclean re run

# Check OS
ifeq ($(OS), Windows_NT)
    CC := g++
    EXE := Colorify.exe
    OS_MSG := Windows
else
    CC := c++
    EXE := Colorify
    OS_MSG := Other
endif

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),FALSE)
	HIDE =
else
	HIDE = @
endif

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CFLAGS := -Wall -Werror -Wextra -std=c++98 -I.
RM := rm -rf

# Compilation commands
COMPILE_CMD = $(CC) $(CFLAGS) -c $< -o $@
LINK_CMD = $(CC) $(CFLAGS) $(OBJS) -o $@

# Dir and file names
SRCS := sources/main.cpp sources/Colors.cpp
OBJS := $(SRCS:.cpp=.o)
INC := $(wildcard includes/*.hpp)

# Messages
CHECK_MARK = \xe2\x9c\x94
CLN_MSG = ${HIDE}echo -e "${CHECK_MARK} Cleaning up ' .o ' files"
FCLN_MSG = ${HIDE}echo -e "${CHECK_MARK} Full clean-up: Removing ' .o ' files and executable"
MAKE_MSG = ${HIDE}echo -e "${CHECK_MARK} Building the program for ' ${OS_MSG} ' OS"

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

help:
	@echo -e "Usage: make \033[1;32m[target]\033[0m"
	@echo ""
	@echo "Targets:"
	@echo -e "  \033[1;36mall\033[0m      : Build the executable (default)"
	@echo -e "  \033[1;33mclean\033[0m    : Remove object files"
	@echo -e "  \033[1;31mfclean\033[0m   : Remove object files and the executable"
	@echo -e "  \033[1;32mre\033[0m       : Remove all generated files and rebuild"
	@echo -e "  \033[1;34mrun\033[0m      : Clean and run the executable"
	@echo -e "  \033[1;37mhelp\033[0m     : Display this help message"

all: $(EXE)
	$(MAKE_MSG)

# Generates output file
$(EXE): $(OBJS)
	$(HIDE)$(LINK_CMD)

# Compiles sources into objects
%.o: %.cpp $(INC)
	$(HIDE)$(COMPILE_CMD)

# Removes objects
clean:
	$(CLN_MSG)
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(FCLN_MSG)
	$(HIDE)$(RM) $(EXE)

# Removes objects and executables and remakes
re: fclean all

# Run the executable
run: clean
	$(HIDE)./$(EXE)
