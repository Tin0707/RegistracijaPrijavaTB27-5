#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>

int prijava() {
    char korisnickoIme[MAX_LEN], lozinka[MAX_LEN];
    printf("\nUnesite korisnicko ime (ili * za povratak): ");
    fgets(korisnickoIme, MAX_LEN, stdin);
    korisnickoIme[strcspn(korisnickoIme, "\n")] = 0;
    if (strcmp(korisnickoIme, "*") == 0) return 0;

    printf("Unesite lozinku (ili * za povratak): ");
    fgets(lozinka, MAX_LEN, stdin);
    lozinka[strcspn(lozinka, "\n")] = 0;
    if (strcmp(lozinka, "*") == 0) return 0;

    FILE* file = fopen("korisnici.bin", "rb");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke\n\n");
        return 0;
    }

    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnickoIme) == 0 && strcmp(k.lozinka, lozinka) == 0) {
            fclose(file);
            printf("\n**Bok %s %s!**\n\n", k.ime, k.prezime);

            char unos[4];
            do {
                printf("1. Promjena korisnickog imena\n2. Promjena lozinke\n3. Brisanje korisnickog racuna\n4. Izlaz\n");
                printf("Odaberite opciju: ");
                fgets(unos, sizeof(unos), stdin);

                if (strchr(unos, '\n') == NULL) {
                    ocistiBuffer();
                }

                if (strlen(unos) != 2 || (unos[0] < '1' || unos[0] > '4')) {
                    printf("\n~Neispravan unos~\n\n");
                    continue;
                }

                switch (unos[0]) {
                case '1':
                    promjenaKorisnickogImena(&k);
                    printf("\n~Promjena korisnickog imena uspjesna~\n");
                    break;
                case '2':
                    promjenaLozinke(&k);
                    printf("\n~Promjena lozinke uspjesna~\n");
                    break;
                case '3':
                    brisanjeKorisnickogRacuna(&k);
                    printf("\n~Brisanje korisnickog racuna uspjesno~\n");
                    return 0;
                case '4':
                    printf("\n~Izlaz iz korisnickog izbornika~\n");
                    return 1;
                default:
                    printf("\n~Neispravan unos~\n");
                    break;
                }
            } while (1);
        }
    }
    fclose(file);
    printf("\n~Pogresno korisnicko ime ili lozinka~\n\n");
    return 0;
}
