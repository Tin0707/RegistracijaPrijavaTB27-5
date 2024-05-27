#include <stdio.h>

void ocistiBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
