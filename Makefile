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

.DEFAULT_GOAL := help
.DELETE_ON_ERROR:
.PHONY: all clean fclean re run

# OS Check
ifeq ($(OS), Windows_NT)
    CC := g++
    EXE := megaphone.exe
    OS_MSG := Windows
else
    CC := c++
    EXE := megaphone
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
SRCS := megaphone.cpp
OBJS := $(SRCS:.cpp=.o)
INC := $(wildcard includes/*.hpp)

# Check if any source files are newer than object files or the executable
NEEDS_BUILD := $(shell [ "$(OBJS)" -ot "$(SRCS)" ] && printf 1 || printf 0 )

# Messages
CHECK_MARK = \033[1;32m\xe2\x9c\x94\033[0m
X_MARK = \033[1;31m\xe2\x9c\x98\033[0m

CLN_MSG = ${HIDE}printf "${CHECK_MARK} Cleaning up ' .o ' files\n"
FCLN_MSG = ${HIDE}printf "${CHECK_MARK} Full clean-up: Removing ' .o ' files and executable\n"
MAKE_MSG = printf "${CHECK_MARK} Building the program for ' ${OS_MSG} ' OS\n"
NO_BUILD_MSG = printf "${X_MARK} Nothing to compile. Everything is up to date for: ' ${EXE} '\n"

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

# Display this help message
help:
	@printf "Usage: make \033[1;32m[target]\033[0m\n"
	@printf "\n"
	@printf "Targets:\n"
	@printf "  \033[1;36mall\033[0m      : Build the executable\n"
	@printf "  \033[1;33mclean\033[0m    : Remove object files\n"
	@printf "  \033[1;31mfclean\033[0m   : Remove object files and the executable\n"
	@printf "  \033[1;32mre\033[0m       : Remove all generated files and rebuild\n"
	@printf "  \033[1;34mrun\033[0m      : Clean and run the executable"
	@printf "  \033[1;37mhelp\033[0m     : Display this help message (default)\n"

# Generates output file
all: $(EXE)
	@if [ "$(NEEDS_BUILD)" -eq 1 ]; then \
		$(MAKE_MSG); \
	else \
		$(NO_BUILD_MSG); \
	fi

$(EXE): $(OBJS)
	$(HIDE)$(LINK_CMD)

# Compiles sources into objects
%.o: %.cpp $(INC)
	$(HIDE)$(COMPILE_CMD)

# Removes objects
clean:
	$(CLN_MSG)
	$(HIDE)$(RM) $(OBJS)
	${HIDE}NEEDS_BUILD=1

# Removes objects and executables
fclean: clean
	$(FCLN_MSG)
	$(HIDE)$(RM) $(EXE)
	${HIDE}NEEDS_BUILD=1

# Removes objects and executables and remakes
re: fclean
	${HIDE}NEEDS_BUILD=1 $(MAKE) -s all

# Run the executable
run: clean
	$(HIDE)./$(EXE)
