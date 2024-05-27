#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <ctype.h>
#include <string.h>

const char* provjeriJacinuLozinke(const char* lozinka) {
    int MalaSlova = 0, VelikaSlova = 0, Brojevi = 0, Znakovi = 0;
    for (int i = 0; lozinka[i] != '\0'; ++i) {
        if (islower(lozinka[i])) MalaSlova = 1;
        else if (isupper(lozinka[i])) VelikaSlova = 1;
        else if (isdigit(lozinka[i])) Brojevi = 1;
        else Znakovi = 1;
    }
    if (MalaSlova && VelikaSlova && Brojevi && Znakovi) return "Najjaca";
    if ((MalaSlova && VelikaSlova && Brojevi) || (MalaSlova && VelikaSlova && Znakovi) ||(VelikaSlova && Brojevi && Znakovi) || (MalaSlova && Brojevi && Znakovi)) return "Jaka";
    if ((MalaSlova && Brojevi) || (MalaSlova && Znakovi) ||
        (VelikaSlova && Brojevi) || (VelikaSlova && Znakovi)) return "Slaba";
    return "Najslabija";
}
