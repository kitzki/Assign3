/*
  Word Count using dedicated lists
*/

#include <assert.h>
#include <getopt.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "word_count.h"

/* Global data structure tracking the words encountered */
WordCount *word_counts = NULL;

/* The maximum length of each word in a file */
#define MAX_WORD_LEN 64

/*
 * 3.1.1 Total Word Count
 *
 * Returns the total number of words found in infile.
 * A word is defined as a sequence of alphabetical characters
 * with length greater than 1.
 */
int num_words(FILE* infile) {
    int c;
    int in_word = 0;
    int word_len = 0;
    int total = 0;

    while ((c = fgetc(infile)) != EOF) {
        if (isalpha(c)) {
            if (!in_word) {
                in_word = 1;
                word_len = 1;
            } else {
                word_len++;
            }
        } else {
            if (in_word && word_len > 1) {
                total++;
            }
            in_word = 0;
            word_len = 0;
        }
    }

    if (in_word && word_len > 1) {
        total++;
    }

    rewind(infile);  // allow reuse of infile later
    return total;
}

/*
 * 3.1.2 Word Frequency Count (stubbed for now)
 */
void count_words(WordCount **wclist, FILE *infile) {
    // Future work: parse words and call add_word()
    (void) wclist;
    (void) infile;
}

static bool wordcount_less(const WordCount *wc1, const WordCount *wc2) {
    return strcmp(wc1->word, wc2->word) < 0;
}

// Display help message
static int display_help(void) {
    printf("Flags:\n"
           "--count (-c): Count the total amount of words in the file, or STDIN if no file is specified.\n"
           "--frequency (-f): Count the frequency of each word in the file (not yet implemented).\n"
           "--help (-h): Show this help message.\n");
    return 0;
}

int main (int argc, char *argv[]) {
    bool count_mode = true;
    bool freq_mode = false;
    int total_words = 0;

    FILE *infile = NULL;

    
    int opt;
    static struct option long_opts[] = {
        {"count", no_argument, 0, 'c'},
        {"frequency", no_argument, 0, 'f'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "cfh", long_opts, NULL)) != -1) {
        switch (opt) {
            case 'c':
                count_mode = true;
                freq_mode = false;
                break;
            case 'f':
                count_mode = false;
                freq_mode = true;
                break;
            case 'h':
                return display_help();
        }
    }

    if (!count_mode && !freq_mode) {
        printf("Please specify a mode.\n");
        return display_help();
    }

    /* Initialize word data structure */
    init_words(&word_counts);

    /* Open input file or default to stdin */
    if ((argc - optind) < 1) {
        infile = stdin;
    } else {
        infile = fopen(argv[optind], "r");
        if (!infile) {
            perror(argv[optind]);
            return 1;
        }
    }

    if (count_mode) {
        total_words = num_words(infile);
        printf("The total number of words is: %d\n", total_words);
    } else if (freq_mode) {
        count_words(&word_counts, infile);
        wordcount_sort(&word_counts, wordcount_less);
        printf("The frequencies of each word are:\n");
        fprint_words(word_counts, stdout);
    }

    if (infile != stdin) {
        fclose(infile);
    }

    return 0;
}
