////////////////////////////////////////////////////////////
//
//    Rosetta Shell: locktype [направљен 09.07.2023.]
//    Copyright © 2023 Љубомир Мићић
//    Сва права су заштићена.
//
////////////////////////////////////////////////////////////

#ifndef LOCKTYPE_H
#define LOCKTYPE_H

// Treba da postoji veci broj nacina za enkriptovanje
//     1. Obican [KORISTI SEMU SLOVA]
//          1.1. Obicna enkripcija slova
//          1.2. Enkripcija slova sa offsetom
//          1.3. Enkripcija slova sa ponavljanjem 5 puta
//     2. Fajl sa digitalnim kljucem
//     3. 

typedef enum {
    l_obican,
    l_kljuc,
    l_nesto_trece
} LT;
#endif
