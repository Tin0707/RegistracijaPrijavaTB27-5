#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Korisnik.h"


void prikaziIzbornik() {
    char unos[4];
    do {
        printf("1. Registracija\n2. Prijava\n3. Prikaz svih korisnika\n4. Izlaz\n");
        printf("Vas odabir: ");
        if (fgets(unos, sizeof(unos), stdin) == NULL) {
            continue;
        }

        if (strchr(unos, '\n') == NULL) {
            ocistiBuffer();
        }

        if (strlen(unos) != 2 || (unos[0] < '1' || unos[0] > '4')) {
            printf("\n~Neispravan unos~\n\n");
            continue;
        }

        switch (unos[0]) {
        case '1':
            if (registracija()) {
                printf("\n~Registracija uspjesna~\n\n");
            }
            else {
                printf("\n~~Povratak na pocetni izbornik~~\n\n");
            }
            break;
        case '2':
            if (prijava()) {
                printf("\n");
            }
            else {
                printf("\n~~Povratak na pocetni izbornik~~\n\n");
            }
            break;
        case '3':
            prikaziSveKorisnike();
            break;
        case '4':
            printf("\n~Izlaz iz programa~\n");
            return;
        default:
            printf("\n~Neispravan unos~\n\n");
            break;
        }
    } while (1);
}