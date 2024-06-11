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
![Tests](assets/runtests.gif)