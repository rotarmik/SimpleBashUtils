#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "options_struct.h"

void usage();
options_struct processing(int argc, char **argv);
void pattern_add(options_struct *options_bool, char *pattern);
void regexp_from_file(struct options_struct *options_bool, char *filepath);
void output(options_struct options_bool, int argc, char **argv);
void process_file(options_struct *options_bool, char *path, regex_t *re);
void print_match(regex_t *re, char *line);
void output_line(char *line, int n);