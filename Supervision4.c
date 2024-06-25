#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    FILE *source_file, *destination_file;
    char buffer[MAX_SIZE];
    size_t bytes_read;

    source_file = fopen("source.txt", "r");
    if (source_file == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    destination_file = fopen("destination.txt", "w");
    if (destination_file == NULL)
    {
        perror("Error opening destination file");
        fclose(source_file);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0)
    {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File content copied successfully from source.txt to destination.txt\n");

    return 0;
}