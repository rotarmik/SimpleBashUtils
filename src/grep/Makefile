СС = gcc
Flags = -Werror -Wextra -Wall


s21_grep:
	$(CC)  $(Flags) processing.c -o s21_grep

run_tests:
	bash ../grep_tests/grep_test.sh

clean:
	rm -rf s21_grep
	
rebuild: clean s21_grep