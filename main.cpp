#pragma warning(disable: 4996)
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<math.h>
#include <ctype.h>

/*
 * Name: Trevor Benyack
 * Date: 2020-06-20
 * Class: CIT-145-Z01B
 * Assignment 05p01
 * Notes: This program uses a random number generator to create sentences. The sentences are constructed
 * in the following order: article, noun, verb, preposition, article, noun. The program generates 20 sentences, with
 * the first letter capitalized.
 */

int rndNum(void);
int SENTENCE_SIZE = 35;

int main (void) {

    // sentence structure: <article> <noun> <verb> <prep> <article> <noun>.

    char article[5][6] = {"the ", "one ", "a ", "some ", "any "};
    char noun[5][6] = {"boy ", "girl ", "dog ", "town ", "car "};
    char verb[5][9] = {"drove ", "jumped ", "walked ", "ran ", "skipped "};
    char preposition[5][7] = {"to ", "from ", "over ", "under ", "on "};
    char sentence[SENTENCE_SIZE];

    // randomizer seed
    srand(time(NULL));



    for (int i = 0; i < 20; ++i) {

        memset(sentence, 0, SENTENCE_SIZE);

        strcat(sentence, article[rndNum()]);
        strcat(sentence, noun[rndNum()]);
        strcat(sentence, verb[rndNum()]);
        strcat(sentence, preposition[rndNum()]);
        strcat(sentence, article[rndNum()]);
        strcat(sentence, noun[rndNum()]);

        // converts first letter to uppercase
        sentence[0] = toupper(*sentence);

        // finds last space and replaces it with "."
        char* lastSpacePtr = strrchr(sentence, ' ');
        *lastSpacePtr = '.';

        printf("%s", sentence);
        puts("");

    }

    // UNCOMMENT THIS BEFORE SUBMITTING
    // system("pause");
    return 0;
}

int rndNum(void) {

    return rand() % 5;;
}