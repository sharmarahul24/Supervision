#include <stdio.h>

int main()
{
    char name[100];

    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);

    if (name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }

    FILE *file = fopen("output.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "Hello, %s with greeting !\n", name);

    fclose(file);

    printf("Message has been written to output.txt\n");

    return 0;
}