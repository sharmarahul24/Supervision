#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *file;
    char ch;
    char prev_char = ' ';
    bool in_word = false;
    int word_count = 0;

    file = fopen("document.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        if ((ch == ' ' || ch == '\n' || ch == '\t') && in_word)
        {

            in_word = false;
            word_count++;
        }
        else if (ch != ' ' && ch != '\n' && ch != '\t')
        {

            in_word = true;
        }
        prev_char = ch;
    }

    if (in_word)
    {
        word_count++;
    }

    fclose(file);

    printf("Number of words in document.txt: %d\n", word_count);

    return 0;
}
