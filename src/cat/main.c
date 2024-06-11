#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "processing.h"

int main(int argc, char **argv) {
  int c;
  struct options_struct options_bool = {0, 0, 0, 0, 0, 0, 0};

  static struct option long_opt[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {0, 0, 0, 0}};

  while ((c = getopt_long(argc, argv, "bEnsTet", long_opt, 0)) != -1) {
    switch (c) {
      case 'b':
        options_bool.b = 1;
        break;
      case 'e':
        options_bool.e = 1;
        break;
      case 'n':
        options_bool.n = 1;
        break;
      case 's':
        options_bool.s = 1;
        break;
      case 't':
        options_bool.t = 1;
        break;
      case 'E':
        options_bool.E = 1;
        break;
      case 'T':
        options_bool.T = 1;
        break;
      default:
        printf("Usage of s21_cat: ./s21_cat [OPTION][FILENAME]\n");
    }
  }
  int b_n_cnt = 1;  // counter for numbering multiple files with -b and -n
  char *filename;
  if (optind < argc) {
    for (int i = optind; i < argc; i++) {
      filename = argv[i];
      processing(&options_bool, filename, &b_n_cnt);
      if (i < argc - 1) printf("\n");
    }
  } else if (optind == argc)
    printf("Usage of s21_cat: ./s21_cat [OPTION][FILENAME]\n");

  return 0;
}