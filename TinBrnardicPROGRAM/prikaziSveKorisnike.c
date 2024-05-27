#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>

void prikaziSveKorisnike() {
    FILE* file = fopen("korisnici.bin", "rb");

    if (!file) {
        printf("\n~Nema niti jednog registriranog korisnika~\n\n");
        return;
    }else{
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        if (size == 0) {
            printf("\n~Nema niti jednog registriranog korisnika~\n\n");   
            return;
        }
       fseek(file, 0, SEEK_SET);
    }


    Korisnik k;
    printf("\nSvi registrirani korisnici:\n");
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        printf("\nIme: %s   Prezime: %s   Korisnicko ime: %s   Lozinka: %s\n", k.ime, k.prezime, k.korisnickoIme, k.lozinka);
    }
    printf("\n");

    fclose(file);
}
