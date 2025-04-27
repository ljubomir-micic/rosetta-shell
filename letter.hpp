////////////////////////////////////////////////////////////
//
//    Rosetta Shell: letter [направљен 10.07.2023.]
//    Copyright © 2023 Љубомир Мићић
//    Сва права су заштићена.
//
////////////////////////////////////////////////////////////

#ifndef LETTER_H
#define LETTER_H
#define __BROJ_KARAKTERA_U_AZ__ 26
#include "tipovi.hpp"

namespace slovo {
    std::string je_siguran_string(std::string);
    CEBR je_slovo(KARAKTER);
    bool je_veliko(KARAKTER);
    bool je_malo(KARAKTER);
    KARAKTER u_manje(KARAKTER);
    KARAKTER u_vece(KARAKTER);

    std::string je_siguran_string(std::string niska) {
        std::string a = "";
        for (char b : niska) if (je_slovo(b) == TACNO) a += b;
        return a;
    }

    CEBR je_slovo(KARAKTER slovo) {
        if (je_veliko(slovo) || je_malo(slovo)) return TACNO;
        return NETACNO;
    }

    bool je_veliko(KARAKTER slovo) {
        return (slovo > 64 && slovo < 91);
    }

    bool je_malo(KARAKTER slovo) {
        return (slovo > 96 && slovo < 123);
    }

    KARAKTER u_manje(KARAKTER slovo) {
        if (slovo < 65 || slovo > 90) return slovo;
        return (slovo + 32);
    }

    KARAKTER u_vece(KARAKTER slovo) {
        if (slovo < 97 || slovo > 122) return slovo;
        return (slovo - 32);
    }
}

#endif
