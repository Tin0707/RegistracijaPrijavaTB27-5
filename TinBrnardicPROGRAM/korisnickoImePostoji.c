#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>

int korisnickoImePostoji(const char* korisnickoIme) {
    FILE* file = fopen("korisnici.bin", "rb");
    if (!file) return 0;
    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnickoIme) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
