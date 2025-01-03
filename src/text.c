#include "myheader.h"

Text create_text(double x, double y,char* displayText, ALLEGRO_FONT* font) {
    char *tmp = strdup(displayText);
    if (!tmp) {
        fprintf(stderr, "Failed to allocate memory for text.\n");
        exit(EXIT_FAILURE);
    }
    Text text = {x, y,tmp,font};
    return text;
}