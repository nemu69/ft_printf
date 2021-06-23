# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/16 16:41:01 by nepage-l     #+#   ##    ##    #+#        #
#    Updated: 2019/11/16 06:36:43 by nepage-l    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

HEADER        =                    ft_printf.h

LIB            =                    libft.a

LIBS        =                    libft/libft.a

SRC_PATH    =                    .

SRCS_NAME    =  				ft_chartostr.c \
								ft_itoa.c \
								ft_printf.c \
								ft_printf_print.c \
								ft_unint_len.c \
								ft_utoa.c \
								utilsprintf.c \
								utilsprintf3.c \
								ft_base_len.c \
								ft_int_len.c \
								ft_itoa_base.c \
								ft_strcmp.c   \
								ft_uputnbr_fd.c \
								utilsprintf2.c \
								utilsprintf4.c \
								utilsprintf5.c


OBJS        =                     ${SRCS:.c=.o}

NAME        =                     libftprintf.a

RM            =                     rm -f

FLAGS         =                     -Wall -Wextra -Werror

SRCS         =                     $(addprefix $(SRC_PATH)/,$(SRCS_NAME))

all: $(LIB) $(NAME)

%.o: %.c $(HEADER) $(LIBS)
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIB):
	$(MAKE) -C libft all

bonus : all

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean:	clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
