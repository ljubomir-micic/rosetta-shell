////////////////////////////////////////////////////////////
//
//    Rosetta Shell: encrypt [направљен 18.06.2023.]
//    Copyright © 2023 Љубомир Мићић
//    Сва права су заштићена.
//
////////////////////////////////////////////////////////////

#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "tipovi.hpp"
#include "locktype.hpp"

KARAKTER vigenere_slovo(KARAKTER& prvi, KARAKTER& drugi) {    // prvi je karakter koji je u tekstu
    if (slovo::je_slovo(prvi) == NETACNO) return prvi;
    if (slovo::je_slovo(drugi) == NETACNO) return prvi;
    bool jPV = slovo::je_veliko(prvi);
    prvi = slovo::u_manje(prvi);
    drugi = slovo::u_manje(drugi);
    return (KARAKTER)((((CEBR)(prvi-97) + (CEBR)(drugi-97)) % __BROJ_KARAKTERA_U_AZ__) + 97 - (jPV ? 32 : 0));
}

#endif
