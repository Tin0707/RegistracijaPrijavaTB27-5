#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int registracija() {
    Korisnik noviKorisnik;
    printf("\nUnesite ime (ili * za povratak): ");
    scanf("%s", noviKorisnik.ime);
    ocistiBuffer();
    if (strcmp(noviKorisnik.ime, "*") == 0) return 0;

    printf("Unesite prezime (ili * za povratak): ");
    scanf("%s", noviKorisnik.prezime);
    ocistiBuffer();
    if (strcmp(noviKorisnik.prezime, "*") == 0) return 0;

    do {
        printf("Unesite korisnicko ime (ili * za povratak): ");
        scanf("%s", noviKorisnik.korisnickoIme);
        ocistiBuffer();
        if (strcmp(noviKorisnik.korisnickoIme, "*") == 0) return 0;
        if (korisnickoImePostoji(noviKorisnik.korisnickoIme)) {
            printf("\n~Korisnicko ime vec postoji, pokusajte ponovo~\n\n");
        }
    } while (korisnickoImePostoji(noviKorisnik.korisnickoIme));

    char izbor;
    int ispravanUnos = 0;
    do {
        printf("Zelite li unijeti vlastitu lozinku (U) ili da generiramo jaku lozinku za vas (G)? ");
        scanf(" %c", &izbor);
        ocistiBuffer();

        if (izbor == 'G' || izbor == 'g') {
            generirajLozinku(noviKorisnik.lozinka, MAX_LEN);
            printf("Generirana lozinka: %s\n", noviKorisnik.lozinka);
            ispravanUnos = 1;
        }
        else if (izbor == 'U' || izbor == 'u') {
            printf("Unesite lozinku (ili * za povratak): ");
            scanf("%s", noviKorisnik.lozinka);
            ocistiBuffer();
            if (strcmp(noviKorisnik.lozinka, "*") == 0) return 0;
            ispravanUnos = 1;
        }
        else {
            printf("\n~Neispravan unos~\n\n");
        }
    } while (!ispravanUnos);


    printf("~Jacina lozinke: %s~\n", provjeriJacinuLozinke(noviKorisnik.lozinka));

    FILE* file = fopen("korisnici.bin", "ab");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke~\n\n");
        return 0;
    }
    fwrite(&noviKorisnik, sizeof(Korisnik), 1, file);
    fclose(file);

    
    return 1;
}
