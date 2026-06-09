all: 
	make all -C ../
	cc -Wall -Wextra -Werror -c main.c
	cc main.o ../libftprintf.a -o printf_test
	./printf_test

clean:
	rm -f main.o

fclean: clean
	rm -f printf_test

re: fclean all
