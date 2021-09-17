// Include WAVEFORM (.wav) constants

// Include int constants lib
#include <stdint.h>

// Define macros
#define USAGE_ERROR "Incorrect usage: './core INPUT_PATH OUTPUT_PATH ENHANCE_FACTOR'"
#define FILE_ERROR "Detected a problem loading your file(s), try it again."

// Ref.: https://docs.fileformat.com/audio/wav/
#define HEADER 44

// Define credentials path
#define CREDS "data/credentials.txt"

// Define const of 8 bites / 1 byte
typedef uint8_t BYTE;

// Define const of 16 bites / 2 bytes
typedef int16_t DOUBLE_BYTE;