#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>

void brisanjeKorisnickogRacuna(Korisnik* korisnik) {
    FILE* file = fopen("korisnici.bin", "rb");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke\n\n");
        return;
    }

    FILE* temp = fopen("temp.bin", "wb");
    if (!temp) {
        perror("\n~Greska prilikom otvaranja privremene datoteke\n\n");
        fclose(file);
        return;
    }

    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnik->korisnickoIme) != 0) {
            fwrite(&k, sizeof(Korisnik), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("korisnici.bin");
    rename("temp.bin", "korisnici.bin");
}
