// Sound Enhancer header file

// Include standard I/O
#include <stdio.h>

// Include constants
#include "constants.h"

// Prototypes
void enhanceAudio(FILE *input, FILE *output, float f);
void credentials(char *path);

// Include non-main functions
void enhanceAudio(FILE *input, FILE *output, float f)
{
    // Prompt the user
    printf("\nWorking on the task...\n");

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

// Show personal credentials
void credentials(char *path)
{
    // Create a byte buffer
    BYTE buffer;
    FILE *creds = fopen(path, "r");

    while (fread(&buffer, sizeof(BYTE), 1, creds))
    {
        // Receive bytes in int and convert to char
        char c_chr = (char)buffer;
        printf("%c", c_chr);
    }
    // Close the creds file
    fclose(creds);
}
