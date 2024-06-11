#include <stdio.h>
#include <stdlib.h>

#include "options_struct.h"
void processing(struct options_struct *options_bool, char *filename,
                int *b_n_cnt);
void s_processing(char ***lines, int *lines_cnt, int *error_code);
void b_processing(char ***lines, int *lines_cnt, int *error_code, int *b_n_cnt);
void n_processing(char ***lines, int *lines_cnt, int *error_code, int *b_n_cnt);
void e_processing(char ***lines, int *lines_cnt, int *error_code);
void E_processing(char ***lines, int *lines_cnt, int *error_code);
void t_processing(char ***lines, int *lines_cnt, int *error_code);
void T_processing(char ***lines, int *lines_cnt, int *error_code);