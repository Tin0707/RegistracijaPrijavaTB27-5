#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>

void promjenaKorisnickogImena(Korisnik* korisnik) {
    char novoIme[MAX_LEN];
    printf("\nUnesite novo korisnicko ime (ili * za povratak): ");
    scanf("%s", novoIme);
    ocistiBuffer();
    if (strcmp(novoIme, "*") == 0) return;

    if (korisnickoImePostoji(novoIme)) {
        printf("\n~Korisnicko ime je vec zauzeto~\n\n");
        return;
    }

    FILE* file = fopen("korisnici.bin", "rb+");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke~\n\n");
        return;
    }

    long int trenutna_pozicija;
    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnik->korisnickoIme) == 0) {
            trenutna_pozicija = ftell(file) - sizeof(Korisnik); // Zapamti trenutnu poziciju
            fseek(file, trenutna_pozicija, SEEK_SET); // Vrati se na po?etak zapisa
            strcpy(korisnik->korisnickoIme, novoIme); // Ažuriraj korisni?ko ime
            fwrite(korisnik, sizeof(Korisnik), 1, file);
            break;
        }
    }
    fclose(file);
}


