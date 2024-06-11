#include "processing.h"

int main(int argc, char **argv) {
  options_struct options_bool = processing(argc, argv);
  output(options_bool, argc, argv);
  return 0;
}

void usage() { printf("Incorrect usage of grep"); }

options_struct processing(int argc, char **argv) {
  int opt;
  options_struct options_bool = {0};

  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        options_bool.e = 1;
        pattern_add(&options_bool, optarg);
        break;
      case 'i':
        options_bool.i = REG_ICASE;
        break;
      case 'v':
        options_bool.v = 1;
        break;
      case 'c':
        options_bool.c = 1;
        break;
      case 'l':
        options_bool.c = 1;
        options_bool.l = 1;
        break;
      case 'n':
        options_bool.n = 1;
        break;
      case 'h':
        options_bool.h = 1;
        break;
      case 's':
        options_bool.s = 1;
        break;
      case 'f':
        options_bool.f = 1;
        regexp_from_file(&options_bool, optarg);
        break;
      case 'o':
        options_bool.o = 1;
        break;
    }
  }
  if (options_bool.len_pattern == 0) {
    pattern_add(&options_bool, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) {
    options_bool.h = 1;
  }
  return options_bool;
}

void pattern_add(options_struct *options_bool, char *pattern) {
  if (options_bool->len_pattern != 0) {
    strcat(options_bool->pattern + options_bool->len_pattern, "|");
    options_bool->len_pattern++;
  }
  options_bool->len_pattern += sprintf(
      options_bool->pattern + options_bool->len_pattern, "(%s)", pattern);
}

void regexp_from_file(struct options_struct *options_bool, char *filepath) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) {
    if (options_bool->s != 1) perror(filepath);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  int read = getline(&line, &memlen, f);
  while (read != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    pattern_add(options_bool, line);
    read = getline(&line, &memlen, f);
  }
  free(line);
  fclose(f);
}

void output(options_struct options_bool, int argc, char **argv) {
  regex_t re;
  int error = regcomp(&re, options_bool.pattern, REG_EXTENDED | options_bool.i);
  if (error) perror("Error with compiling regex");
  for (int i = optind; i < argc; i++) {
    process_file(&options_bool, argv[i], &re);
  }
  regfree(&re); 
}

void process_file(options_struct *options_bool, char *path, regex_t *re) {
  FILE *f = fopen(path, "r");
  if (f == NULL) {
    if (options_bool->s != 1) perror(path);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  int read = 0;
  int line_cnt = 1;
  int c = 0;
  read = getline(&line, &memlen, f);
  //?
  while (read != -1) {
    int result = regexec(re, line, 0, NULL, 0);
    if ((result == 0 && options_bool->v == 0) ||
        (options_bool->v == 1 && result == 1)) {
      if (options_bool->c == 0 && options_bool->l == 0) {
        if (options_bool->h == 0) printf("%s:", path);
        if (options_bool->n) printf("%d:", line_cnt);
        if (options_bool->o) {
          print_match(re, line);
        } else {
          output_line(line, read);
        }
      }
      c++;
    }
    read = getline(&line, &memlen, f);
    line_cnt++;
  }
  free(line);
  if (options_bool->c && options_bool->l == 0) {
    if (options_bool->h == 0) printf("%s:", path);
    printf("%d\n", c);
  }
  if (options_bool->l && c > 0) printf("%s\n", path);
  fclose(f);
}

void print_match(regex_t *re, char *line) {
  regmatch_t match;
  int offset = 0;
  while (1) {
    int result = regexec(re, line + offset, 1, &match, 0);
    if (result != 0) {
      break;
    }
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar(line[i]);
    }
    putchar('\n');
    offset += match.rm_eo;
  }
}

void output_line(char *line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') putchar('\n');
}