#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: %s <email> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen(*(argv + 2), "r");
    if (!fp)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    while (getline(&line, &len, fp) != -1)
    {
        if (strstr(line, *(argv + 1)))
        {
            printf("%s", line);
        }
    }

    if (ferror(fp))
    {
        puts("I/O error when reading");
    } else if (feof(fp))
    {
        puts("End of file reached successfully");
    }

    free(line);
    fclose(fp);
    return EXIT_SUCCESS;
}