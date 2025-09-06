#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fp = NULL;

    // Open file or use stdin
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "Cannot open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    } else {
        fp = stdin;
    }

    int ch;
    int n_lines = 0;
    int n_words = 0;
    int n_chars = 0;
    int inside_word = 0;

    while ((ch = fgetc(fp)) != EOF) {
        n_chars++;

        if (ch == '\n') {
            n_lines++;
        }

        if (isalpha(ch)) {
            if (!inside_word) {
                inside_word = 1;
                n_words++;
            }
        } else {
            inside_word = 0;
        }
    }

    if (fp != stdin) {
        fclose(fp);
    }

    printf("Lines: %d  Words: %d  Characters: %d\n", n_lines, n_words, n_chars);
    return EXIT_SUCCESS;
}