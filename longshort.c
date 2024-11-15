#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // checks if correct num of inputs
    if (argc < 4)
    {
        printf("Must supply a file to read from and two files to write from.\n");
        exit(1);
    }

    // open file for reading
    FILE *readFile = fopen(argv[1], "r");

    // prints error message if file isn't open
    if (!readFile)
    {
        printf("Can't open %s file for reading\n", argv[1]);
        exit(1);
    }

    // open file for writing
    FILE *shortFile = fopen(argv[2], "w");

    // prints error message if file isn't open
    if (!shortFile)
    {
        printf("Can't open %s file for writing\n", argv[2]);
        exit(1);
    }

    // open second file for writing
    FILE *longFile = fopen(argv[3], "w");

    // prints error message if file isn't open
    if (!longFile)
    {
        printf("Can't open %s file for writing\n", argv[3]);
        exit(1);
    }

    char str[256];
    int shortCount = 0;
    int longCount = 0;
    
    // checks if reached end of file
    while (fgets(str, 256, readFile) != NULL)
    {
        int length = strlen(str);
        if (length < 20)
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                // convert line to upper case
                str[i] = toupper(str[i]); 
            }
            // once converted write to short file
            fprintf(shortFile, "%s", str);
            shortCount++;
        }
        else 
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                // convert line to lower case
                str[i] = tolower(str[i]);
            }

            // once converted write to long file
            fprintf(longFile, "%s", str);
            longCount++;
        }
        
            
    }

    // close/deallocate
    fclose(readFile);
    fclose(shortFile);
    fclose(longFile);

    printf("%d lines written to %s\n", shortCount, argv[2]);
    printf("%d lines written to %s\n", longCount, argv[3]);
}