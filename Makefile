# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafond- <glafond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 03:12:43 by glafond-          #+#    #+#              #
#    Updated: 2021/04/15 14:14:45 by glafond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ****************
#	Varriables:

LIBNAME	=	libregex.a

AR		=	ar
ARFLAGS	=	rc

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
#FSAN	=	-g3 -fsanitize=address

SRCDIR	=	src
INCDIR	=	inc
OBJDIR	=	obj
SRCS	=	libft.needed.c \
			regex.alphabet.c \
			regex.api.array.c \
			regex.api.compile.c \
			regex.api.execute.c \
			regex.api.match.c \
			regex.api.nextmatch.c \
			regex.debug.c \
			regex.dfa.c \
			regex.dfa.utils.c \
			regex.map.c \
			regex.nfa.c \
			regex.nfa.link.c \
			regex.nfa.utils.c \
			regex.pattern.add.c \
			regex.pattern.parse.c \
			regex.pattern.utils.c \
			regex.set.c
OBJS	=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
DPDCS	=	$(OBJS:.o=.d)

OBJDIROBJCONTENT	=	$(shell ls $(OBJDIR)/*.o)
OBJDIRDPDCSCONTENT	=	$(shell ls $(OBJDIR)/*.d)

# ****************
#	Rules:

all: $(LIBNAME)

$(LIBNAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(LIBNAME) $(OBJS)
	@printf "[\e[32mOK\e[0m] %s\n" $@

-include $(DPDCS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(FSAN) -MMD -I$(INCDIR) -c $< -o $@
	@printf "[\e[32mOK\e[0m] %s\n" $@

clean: _clean

fclean: _clean
ifeq ($(shell ls -1 | grep $(LIBNAME)),$(LIBNAME))
	@rm -rf $(LIBNAME)
	@printf "[\e[31mCLEAN\e[0m] %s\n" $(LIBNAME)
endif

_clean:
ifeq ($(shell ls -1 | grep $(OBJDIR)),$(OBJDIR))
	@rm -rf $(OBJDIROBJCONTENT) $(OBJDIRDPDCSCONTENT)
	@printf "[\e[31mCLEAN\e[0m] %s\n" $(OBJDIROBJCONTENT)
	@rm -rf $(OBJDIR)
endif

re: fclean all

#test: all
#	@$(CC) $(CFLAGS) $(FSAN) -I$(INCDIR) main.c $(LIBNAME) -o a.out
#	@printf "[\e[32mOK\e[0m] %s\n" "a.out"
#
#test_clean: fclean
#	@rm a.out
#	@printf "[\e[31mCLEAN\e[0m] %s\n" "a.out"

