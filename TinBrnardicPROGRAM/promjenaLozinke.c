#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int promjenaLozinke(Korisnik* korisnik) {
    char izbor;
    printf("\nZelite li unijeti vlastitu lozinku (U) ili da program generira jaku lozinku za vas (G)? ");
    scanf(" %c", &izbor);
    ocistiBuffer();

    if (izbor == 'G' || izbor == 'g') {
        generirajLozinku(korisnik->lozinka, MAX_LEN);
        printf("Generirana lozinka: %s\n", korisnik->lozinka);
    }
    else if (izbor == 'U' || izbor == 'u') {
        printf("Unesite novu lozinku (ili * za povratak): ");
        scanf("%s", korisnik->lozinka);
        ocistiBuffer();
        if (strcmp(korisnik->lozinka, "*") == 0) return 0;
    }
    else {
        printf("\n~Neispravan odabir~\n");
        return 0;
    }

    printf("Jacina lozinke: %s\n", provjeriJacinuLozinke(korisnik->lozinka));

    FILE* file = fopen("korisnici.bin", "rb+");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke~\n\n");
        return 0;
    }

    long int trenutna_pozicija;
    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnik->korisnickoIme) == 0) {
            trenutna_pozicija = ftell(file) - sizeof(Korisnik);
            fseek(file, trenutna_pozicija, SEEK_SET);
            strcpy(korisnik->lozinka, korisnik->lozinka);
            fwrite(korisnik, sizeof(Korisnik), 1, file);
            break;
        }
    }
    fclose(file);

    return 1;
}
