СС = gcc
Flags = -Werror -Wextra -Wall


s21_cat:
	$(CC)  $(Flags) main.c processing.c -o s21_cat 

run_tests:
	bash ../cat_tests/cat_test.sh

clean:
	rm -rf s21_cat
	
rebuild: clean s21_cat