C = gcc -Wall -Werror -Wextra
OBJ = main.o s21_grep.o 

s21_cat: $(OBJ)
	$(C) $(OBJ) -o s21_cat
%.o:%.c
	gcc -c $< -o $@

clean: 
	rm -rf  *.o s21_grep
