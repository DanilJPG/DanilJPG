#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void output(FILE* file);
void output_without_prefix(char** argv);
void number_nonblank(char** argv);
void number(char** argv);
void end_of_line(char** argv);
void tabulation(char** argv);
void squeeze_blank(char** argv);

int main(int argc, char* argv[]) {
  FILE* pfile;
  if (argc == 1) {
    pfile = stdin;
    output(pfile);
  } else if (argc > 1) {
    if ((pfile = fopen(argv[1], "r")) != NULL) {
      output_without_prefix(&argv[1]);
      fclose(pfile);
    } else {
      if (strcmp(argv[1], "-b") == 0) {
        number_nonblank(&argv[2]);
      } else if (strcmp(argv[1], "-n") == 0) {
        number(&argv[2]);
      } else if ((strcmp(argv[1], "-e") == 0) || (strcmp(argv[1], "-E") == 0) ||
                 (strcmp(argv[1], "-ev") == 0) ||
                 (strcmp(argv[1], "-ve") == 0)) {
        end_of_line(&argv[2]);
      } else if ((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-T") == 0) ||
                 (strcmp(argv[1], "-tv") == 0) ||
                 (strcmp(argv[1], "-vt") == 0)) {
        tabulation(&argv[2]);
      } else if ((strcmp(argv[1], "-s") == 0)) {
        squeeze_blank(&argv[2]);
      }
    }
  }
  return 0;
}

void output(FILE* file) {
  char string[1024];
  int n = sizeof(string) / sizeof(string[0]);
  while ((fgets(string, n, file)) != NULL) {
    fputs(string, stdout);
  }
}

void output_without_prefix(char** argv) {
  FILE* pfile;
  char string[1024];

  while (*argv) {
    if (strcmp(*argv, "-") == 0) {
      pfile = stdin;
    } else {
      pfile = fopen(*argv, "r");
      if (pfile == NULL) {
        perror(*argv);
        argv++;
      }
      while (fgets(string, sizeof(string), pfile)) {
        printf("%s", string);
      }
    }
    argv++;
    fclose(pfile);
  }
}

void number_nonblank(char** argv) {
  FILE* pfile;
  char string[1024];
  int number_string = 1;
  while (*argv) {
    if (strcmp(*argv, "-") == 0) {
      pfile = stdin;
    } else {
      pfile = fopen(*argv, "r");
      if (pfile == NULL) {
        perror(*argv);
        argv++;
      }
    }
    while (fgets(string, sizeof(string), pfile) != NULL) {
      if (strcmp(string, "\n") != 0) {
        printf("%6d\t%s", number_string++, string);
      } else if (strcmp(string, "\n") == 0) {
        printf("%s", string);
      }
    }
    fclose(pfile);
    argv++;
  }
}

void number(char** argv) {
  FILE* pfile;
  char string[1024];
  int number_string = 1;
  while (*argv) {
    if (strcmp(*argv, "-") == 0) {
      pfile = stdin;
    } else {
      pfile = fopen(*argv, "r");
      if (pfile == NULL) {
        perror(*argv);
        argv++;
      }
    }
      
      while (fgets(string, sizeof(string), pfile) != NULL) {
        printf("%6d\t%s", number_string++, string);
      }
    fclose(pfile);
    argv++;
  }
}

void end_of_line(char** argv) {
  FILE* pfile;
  char c = '$';
  char ch;
  while (*argv) {
    if (strcmp(*argv, "-") == 0) {
      pfile = stdin;
    } else {
      pfile = fopen(*argv, "r");
      if (pfile == NULL) {
        perror(*argv);
      }
    }
      while ((ch = fgetc(pfile)) != EOF) {
        if(ch == '\n' || ch == EOF){
          putchar(c);
          putchar('\n');
        }else{
        fputc(ch,stdout);
        }
      }
      argv++;
      fclose(pfile);
  }
}

void tabulation(char** argv) {
  FILE* pfile;
  char ch;
  while (*argv) {
    if (strcmp(*argv, "-") == 0) {
      pfile = stdin;
    } else {
      pfile = fopen(*argv, "r");
      if (pfile == NULL) {
        perror(*argv);
      }
    }
      while ((ch = fgetc(pfile)) != EOF) {
        if (ch == '\t') {
          printf("^I");
        } else {
          fputc(ch,stdout);
        }
      }
    argv++;
    fclose(pfile);
  }
}

void squeeze_blank(char** argv) {
  FILE* pfile;
  char string[1024];
  bool prev_blank = false;

  while (*argv) {
    if (strcmp(*argv, "-") == 0) {
      pfile = stdin;
    } else {
      pfile = fopen(*argv, "r");
      if (pfile == NULL) {
        perror(*argv);
        argv++;
      }
    }
      while (fgets(string, sizeof(string), pfile)) {
        if (strcmp(string, "\n") == 0) {
          if (!prev_blank) {
            printf("%s", string);
            prev_blank = true;
          }

        } else {
          printf("%s", string);
          prev_blank = false;
        }
      }
    fclose(pfile);
    argv++;
  }
}
