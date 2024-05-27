#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdlib.h>
#include <time.h>

#define DG 7
#define GG 20

void generirajLozinku(char* lozinka, size_t velicina) {
    const char* znakovi = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    size_t duljina = rand() % (GG - DG + 1) + DG;
    for (size_t i = 0; i < duljina; ++i) {
        lozinka[i] = znakovi[rand() % strlen(znakovi)];
    }
    lozinka[duljina] = '\0';
}
