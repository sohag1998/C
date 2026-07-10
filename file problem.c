#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;

    // Write to file
    fp = fopen("data.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    fprintf(fp, "Hello World!\n");
    fprintf(fp, "Welcome to C File Handling.");

    fclose(fp);

    // Read from file
    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("File Contents:\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}
