// Include local header file(s)
#include "sound.h"

// Include standard libs
#include <stdlib.h>

/* 
Take 3 command line arguments 
main() function present here.
*/
int main (int argc, char *argv[])
{
    // Prompt the user with an error message once condition is avoided
    if (argc != 4)
    {
        printf("%s\n", USAGE_ERROR);
        return 1;
    }
    // Invoke the credentials function
    credentials(CREDS);

    // Specify file paths
    char *inputPath = argv[1], *outputPath = argv[2];

    // Load files and handle possible errors
    FILE *inputFile = fopen(inputPath, "r");
    FILE *outputFile = fopen(outputPath, "w");

    if (inputFile == NULL || outputPath == NULL)
    {
        // Detect file error and abort the program
        printf("%s\n", FILE_ERROR);
        return 2;
    }
    // Define the enhance factor from the command line input at index 3
    float factor = atof(argv[3]);

    // Call enhance function
    enhanceAudio(inputFile, outputFile, factor);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    // Completion prompt messages
    printf("Your task was completed!\n");
    printf("Path: %s\n", outputPath);

    // Return successful completion
    return 0;
}