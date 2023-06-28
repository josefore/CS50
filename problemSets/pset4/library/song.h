// Definition of a song

#include <stdint.h>

typedef uint16_t DS;

typedef struct
{
    char title[64];
    char artst[64];
    char album[64];
    char label[32];
    char genre[32];
    DS year;
}
SONG;