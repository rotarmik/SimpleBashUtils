### This project was developed as an educational assignment for the main education program at [School 21](https://21-school.ru/).
---

#### It is an implementation of my own utilities [cat](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/) and [grep](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/ ) in C language.

#### The repository, in the src folder, contains 4 folders:
- cat: files with the implementation of the cat utility
- cat_tests: bash scripts for testing the cat utility
- grep: files with implementation of the grep utility
- grep_tests: bash scripts for testing the grep utility
---
#### Build:
```
git clone https://github.com/rotarmik/SimpleBashUtils.git
cd SimpleBashUtils/src/
```
 ##### in the cat folder:
 just for build program:
 ```
 make s21_cat 
 ```
 to start programm testing:
 ```
 make run_tests 
 ```

##### in the grep folder:
 just for build program:
 ```
 make s21_grep
 ```
 to start programm testing:
 ```
 make run_tests 
 ```
![Tests](https://github.com/rotarmik/SimpleBashUtils/blob/develop/assest/runtests.gif)

#### Task's requirements:

- The programs must be developed in C language of C11 standard using gcc compiler.
- The program code of the cat and grep must be located on the develop branch in the src/cat/ and src/grep/ folders, respectively
- Do not use outdated and legacy language constructions and library functions. Pay attention to the legacy and obsolete marks in the official documentation on the language and the libraries used. Use the POSIX.1-2017 standard.
- When writing code it is necessary to follow the Google style
- The programs must be executable files with command line arguments
- The programs must be built with Makefile with appropriate targets: s21_cat, s21_grep
- If third-party libraries are used, there must be build scripts in makefile to connect/load them
- Integration tests must cover all flag variants and input values, based on a comparison with the behavior of real Bash utilities
The programs must be developed according to the principles of structured programming
- Code duplication must be avoided, common modules must be reused between the utilities. Common modules can be moved to a separate folder src/common
- You can use standard and non-standard C libraries, or you can use your own developed libraries from other projects
The statement of the message in the case of an error does not matter
- Input via stdin is not required to be supported

##### cat: 
- Support of all flags (including GNU versions) specified above
- The source, header, and build files must be placed in the src/cat/ directory
- The resulting executable file must be placed in the directory src/cat/ and named s21_cat

##### grep:
- Support of the following flags: -e, -i, -v, -c, -l, -n, -h, -s, -f, -o
- Only pcre or regex libraries can be used for regular expressions
- The source, header and make files must be placed in the src/grep/ directory
- The resulting executable file must be placed in the directory src/- grep/ and named s21_grep
- Only pcre or regex libraries can be used for regular expressions
- The resulting executable file must be placed in the directory src/grep/ and named s21_grep
- Support of all flags, including their pair combinations (e.g. -iv, -in)

