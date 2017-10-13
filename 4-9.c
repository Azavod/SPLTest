#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char** string_splitter(const char* const string);

int main(int argc, char* argv[])
{
    char* string = "      one      two       three       four    five    six      ";
    printf("A string is \"%s\" \n", string); 
    char** answer = string_splitter(string);
    for (int i = 0; 6 > i; ++i)
    {
        printf("%d-th word is \"%s\" \n", i+1, answer[i]);
        free(answer[i]);
    }
    free(answer);
}

char** string_splitter(const char* const string)
{
    char** answer = malloc(sizeof(char*));
    int words = 0, letters = 0, offset = 0, i = 0;
    for (;;)
    {
        if (string[i] != ' ' && string[i] != 0) letters++;
        else offset++; // redunant space in the string
        if ((string[i] == ' ' || string[i] == 0) && letters > 0) 
        {
            char* word = calloc(letters+1, sizeof(char));
            strncpy(word, string+offset-1, letters);
            word[letters] = 0;
            offset+=letters*sizeof(char);
            words++;
            letters=0;
            char** tmp = answer;
            answer = calloc(words, sizeof(char*));
            int last = words-1;
            for (int j = 0; last > j; ++j) answer[j] = tmp[j];
            answer[last] = word;
            free(tmp);
        }
        if (string[i++] == 0) break;
    }
    return answer;
}