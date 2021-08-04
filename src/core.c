// Include libs
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define error message
#define USAGE_ERROR "Incorrect usage: './core INPUT_PATH OUTPUT_PATH ENHANCE_FACTOR'"
#define FILE_ERROR "Detected a problem loading your file(s), try it again."

// Ref.: https://docs.fileformat.com/audio/wav/
#define HEADER 44

// Define const of 8 bites / 1 byte
typedef uint8_t BYTE;

// Define const of 16 bites / 2 bytes
typedef int16_t DOUBLE_BYTE;

// Prototypes
void enhanceAudio(FILE *input, FILE *output, float f);

// Take 3 command line arguments
int main (int argc, char *argv[])
{
    // Prompt the user with an error message once condition is avoided
    if (argc != 4)
    {
        printf("%s\n", USAGE_ERROR);
        return 1;
    }

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
}

void enhanceAudio(FILE *input, FILE *output, float f)
{
    BYTE header[HEADER];
    fread(header, HEADER, 1, input);
    fwrite(header, HEADER, 1, output);

    // Process the audio
    DOUBLE_BYTE volume;
    while (fread(&volume, sizeof(DOUBLE_BYTE), 1, input))
    {
        // Multiply every second byte sound sample by the factor
        volume *= f;

        // Write new sample level to the output file
        fwrite(&volume, sizeof(DOUBLE_BYTE), 1, output);
    }
}