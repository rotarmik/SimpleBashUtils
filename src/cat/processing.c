#include "processing.h"

#include <string.h>

void processing(struct options_struct *options_bool, char *filename,
                int *b_n_cnt) {
  int error_code = 0;
  FILE *fptr;
  fptr = fopen(filename, "r");

  if (fptr == NULL) {
    error_code = 1;
    printf("File open error");
    return;

  } else {
    char **lines = NULL;
    int lines_cnt = 0;

    char buffer_line[100000];
    while (fgets(buffer_line, sizeof(buffer_line), fptr) != NULL) {
      char **temp_lines = realloc(lines, (lines_cnt + 1) * sizeof(char *));
      if (temp_lines == NULL) {
        free(lines);
        error_code = 2;
        printf("Memory allocation error. Code: %d", error_code);
        return;
        fclose(fptr);
      } else {
        lines = temp_lines;
        lines[lines_cnt] = strdup(buffer_line);
        lines_cnt++;
      }
    }
    int flag_b_used = 0;
    int flag_e_used = 0;
    int flag_t_used = 0;
    if (options_bool->s == 1 && error_code == 0)
      s_processing(&lines, &lines_cnt, &error_code);
    if (options_bool->b == 1 && error_code == 0) {
      b_processing(&lines, &lines_cnt, &error_code, b_n_cnt);
      flag_b_used = 1;
    }
    if (options_bool->n == 1 && error_code == 0 && flag_b_used == 0)
      n_processing(&lines, &lines_cnt, &error_code, b_n_cnt);
    if (options_bool->e == 1 && error_code == 0) {
      e_processing(&lines, &lines_cnt, &error_code);
      flag_e_used = 1;
    }
    if (options_bool->E == 1 && error_code == 0 && flag_e_used == 0)
      E_processing(&lines, &lines_cnt, &error_code);
    if (options_bool->t == 1 && error_code == 0) {
      t_processing(&lines, &lines_cnt, &error_code);
      flag_t_used = 1;
    }
    if (options_bool->T == 1 && error_code == 0 && flag_t_used == 0)
      T_processing(&lines, &lines_cnt, &error_code);

    for (int i = 0; i < lines_cnt; i++) printf("%s", lines[i]);
    for (int i = 0; i < lines_cnt; i++) free(lines[i]);
    free(lines);

    fclose(fptr);
  }
}

void s_processing(char ***lines, int *lines_cnt, int *error_code) {
  int empty_flag = 0;

  for (int i = 0; i < *lines_cnt; i++) {
    if (strlen((*lines)[i]) == 1 && empty_flag == 1) {
      free((*lines)[i]);
      for (int j = i; j < *lines_cnt - 1; j++) {
        (*lines)[j] = (*lines)[j + 1];
      }
      i--;

      char **temp_lines = realloc(*lines, (*lines_cnt - 1) * sizeof(char *));
      if (*temp_lines == NULL) {
        free(*lines);
        (*error_code) = 3;
        printf("Memory allocation error. Code: %d", *error_code);
        return;
      } else {
        *lines = temp_lines;
        (*lines_cnt)--;
      }
    }
    if (strlen((*lines)[i]) == 1 && empty_flag == 0) empty_flag = 1;

    if (strlen((*lines)[i]) > 1) empty_flag = 0;
  }
}

void b_processing(char ***lines, int *lines_cnt, int *error_code,
                  int *b_n_cnt) {
  char buffer[100000];
  for (int i = 0; i < *lines_cnt; i++) {
    if (strlen((*lines)[i]) == 1 || (strlen((*lines)[i]) == 0)) {
      continue;
    } else {
      char *temp_lines =
          realloc((*lines)[i], (strlen((*lines)[i]) + 10) * sizeof(char));
      if (temp_lines == NULL) {
        (*error_code) = 4;
        free((*lines)[i]);
        printf("Memory allocation error. Code: %d", *error_code);
        return;
      } else {
        (*lines)[i] = temp_lines;
        strcpy(buffer, (*lines)[i]);
        sprintf((*lines)[i], "%6d\t%s%c", *b_n_cnt, buffer, '\0');
        (*b_n_cnt)++;
      }
    }
  }
}

void n_processing(char ***lines, int *lines_cnt, int *error_code,
                  int *b_n_cnt) {
  char buffer[100000];
  for (int i = 0; i < *lines_cnt; i++) {
    char *temp_lines =
        realloc((*lines)[i], (strlen((*lines)[i]) + 10) * sizeof(char));
    if (temp_lines == NULL) {
      (*error_code) = 5;
      free((*lines)[i]);
      printf("Memory allocation error. Code: %d", *error_code);
      return;
    } else {
      (*lines)[i] = temp_lines;
      strcpy(buffer, (*lines)[i]);
      sprintf((*lines)[i], "%6d\t%s%c", *b_n_cnt, buffer, '\0');
      (*b_n_cnt)++;
    }
  }
}

void e_processing(char ***lines, int *lines_cnt, int *error_code) {
  for (int i = 0; i < *lines_cnt; i++) {
    char buffer_for_saving[100000];
    char buffer_for_processing[100];
    char buffer_resulting[100000];
    memset(buffer_for_saving, '\0', sizeof(buffer_for_saving));
    memset(buffer_for_processing, '\0', sizeof(buffer_for_processing));
    memset(buffer_resulting, '\0', sizeof(buffer_resulting));
    strcpy(buffer_for_saving, (*lines)[i]);
    int j = 0;
    while (buffer_for_saving[j] != '\0') {
      if (buffer_for_saving[j] == '\n') {
        strcat(buffer_resulting, "$");
      }
      if (buffer_for_saving[j] < -96) {
        sprintf(buffer_for_processing, "M-^%c", buffer_for_saving[j] + 192);
      } else if (buffer_for_saving[j] < 0) {
        sprintf(buffer_for_processing, "M-%c", buffer_for_saving[j] + 128);
      } else if (buffer_for_saving[j] == 9 || buffer_for_saving[j] == 10) {
        sprintf(buffer_for_processing, "%c", buffer_for_saving[j]);
      } else if (buffer_for_saving[j] < 32) {
        sprintf(buffer_for_processing, "^%c", buffer_for_saving[j] + 64);
      } else if (buffer_for_saving[j] < 127) {
        sprintf(buffer_for_processing, "%c", buffer_for_saving[j]);
      } else {
        sprintf(buffer_for_processing, "%s", "^?");
      }
      strcat(buffer_resulting, buffer_for_processing);
      j++;
    }

    char *temp_lines =
        realloc((*lines)[i], (strlen(buffer_resulting) + 1) * sizeof(char));
    if (temp_lines == NULL) {
      (*error_code) = 5;
      free((*lines)[i]);
      printf("Memory allocation error. Code: %d", *error_code);
      return;
    } else {
      (*lines)[i] = temp_lines;
      sprintf((*lines)[i], "%s", buffer_resulting);
    }
  }
}

void E_processing(char ***lines, int *lines_cnt, int *error_code) {
  for (int i = 0; i < *lines_cnt; i++) {
    char buffer_for_saving[100000];
    char buffer_resulting[100000];
    memset(buffer_for_saving, '\0', sizeof(buffer_for_saving));
    memset(buffer_resulting, '\0', sizeof(buffer_resulting));
    strcpy(buffer_for_saving, (*lines)[i]);
    int j = 0;
    while (buffer_for_saving[j] != '\0') {
      if (buffer_for_saving[j] == '\n') {
        buffer_resulting[j] = '$';
        buffer_resulting[j + 1] = '\n';
        buffer_resulting[j + 2] = '\0';
        j += 3;
      }

      buffer_resulting[j] = buffer_for_saving[j];

      j++;
    }

    char *temp_lines =
        realloc((*lines)[i], (strlen(buffer_resulting) + 1) * sizeof(char));
    if (temp_lines == NULL) {
      free((*lines)[i]);
      (*error_code) = 6;
      printf("Memory allocation error. Code: %d", *error_code);
      return;
    } else {
      (*lines)[i] = temp_lines;
      sprintf((*lines)[i], "%s", buffer_resulting);
    }
  }
}

void t_processing(char ***lines, int *lines_cnt, int *error_code) {
  for (int i = 0; i < *lines_cnt; i++) {
    char buffer_for_saving[100000];
    char buffer_for_processing[100];
    char buffer_resulting[100000];
    memset(buffer_for_saving, '\0', sizeof(buffer_for_saving));
    memset(buffer_for_processing, '\0', sizeof(buffer_for_processing));
    memset(buffer_resulting, '\0', sizeof(buffer_resulting));
    strcpy(buffer_for_saving, (*lines)[i]);
    int j = 0;
    while (buffer_for_saving[j] != '\0') {
      if (buffer_for_saving[j] < -96) {
        sprintf(buffer_for_processing, "M-^%c", buffer_for_saving[j] + 192);
      } else if (buffer_for_saving[j] < 0) {
        sprintf(buffer_for_processing, "M-%c", buffer_for_saving[j] + 128);
      } else if ((buffer_for_saving[j] == 9 || buffer_for_saving[j] == 10) &&
                 buffer_for_saving[j] != '\t') {
        sprintf(buffer_for_processing, "%c", buffer_for_saving[j]);
      } else if (buffer_for_saving[j] < 32) {
        sprintf(buffer_for_processing, "^%c", buffer_for_saving[j] + 64);
      } else if (buffer_for_saving[j] < 127) {
        sprintf(buffer_for_processing, "%c", buffer_for_saving[j]);
      } else {
        sprintf(buffer_for_processing, "%s", "^?");
      }
      strcat(buffer_resulting, buffer_for_processing);
      j++;
    }

    char *temp_lines =
        realloc((*lines)[i], (strlen(buffer_resulting) + 1) * sizeof(char));
    if (temp_lines == NULL) {
      (*error_code) = 7;
      free((*lines)[i]);
      printf("Memory allocation error. Code: %d", *error_code);
      return;
    } else {
      (*lines)[i] = temp_lines;
      sprintf((*lines)[i], "%s", buffer_resulting);
    }
  }
}

void T_processing(char ***lines, int *lines_cnt, int *error_code) {
  for (int i = 0; i < *lines_cnt; i++) {
    char buffer_for_saving[100000];
    char buffer_for_processing[100];
    char buffer_resulting[100000];
    memset(buffer_for_saving, '\0', sizeof(buffer_for_saving));
    memset(buffer_for_processing, '\0', sizeof(buffer_for_processing));
    memset(buffer_resulting, '\0', sizeof(buffer_resulting));
    strcpy(buffer_for_saving, (*lines)[i]);
    int j = 0;
    while (buffer_for_saving[j] != '\0') {
      if ((buffer_for_saving[j] == 9 || buffer_for_saving[j] == 10) &&
          buffer_for_saving[j] != '\t') {
        sprintf(buffer_for_processing, "%c", buffer_for_saving[j]);
      } else if (buffer_for_saving[j] == '\t') {
        sprintf(buffer_for_processing, "^%c", buffer_for_saving[j] + 64);
      } else if (buffer_for_saving[j] < 127) {
        sprintf(buffer_for_processing, "%c", buffer_for_saving[j]);
      }
      strcat(buffer_resulting, buffer_for_processing);
      j++;
    }

    char *temp_lines =
        realloc((*lines)[i], (strlen(buffer_resulting) + 1) * sizeof(char));
    if (temp_lines == NULL) {
      (*error_code) = 8;
      (*lines)[i] = temp_lines;
      free((*lines)[i]);
      (*lines)[i] = NULL;
      printf("Memory allocation error. Code: %d", *error_code);
      return;
    } else {
      (*lines)[i] = temp_lines;
      sprintf((*lines)[i], "%s", buffer_resulting);
    }
  }
}
