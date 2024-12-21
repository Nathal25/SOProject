all: leercadena.o demo_leercadena minishell

leercadena.o:
	gcc -c leercadena.c

demo_leercadena: leercadena.o
	gcc -o dummy demo_leercadena.c leercadena.o

minishell: leercadena.o
	gcc -o minishell minishell.c leercadena.o

clean:
	rm -f a.out dummy leercadena.o minishell
