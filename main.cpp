////////////////////////////////////////////////////////////
//
//    Rosetta Shell: main [направљен 18.06.2023.]
//    Copyright © 2023 Љубомир Мићић
//    Сва права су заштићена.
//
////////////////////////////////////////////////////////////

#ifndef BASIC_CPP
#define BASIC_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#endif

#define __SEZDESETCRTICAPATNJELOL__ "------------------------------------------------------------"
#define __HEDER_NOVIRED__ "\n|\t"
#define __NOVIRED__ "\n"
#define __NOVIPASUS__ "\n\n"
// #define DEBUG
#if defined _WIN32 || defined _WIN64
#define __TREECHAR__ "\\"
#define __PRIMER_FAJL__ "C:\\Users\\ljubo\\Desktop\\primer.txt"
#else
#define __TREECHAR__ "/"
#define __PRIMER_FAJL__ "/Users/ljubomir/Desktop/primer.txt"
#endif

#include "encrypt.cpp"
#include "decrypt.cpp"

#include "tipovi.hpp"
#include "version.hpp"

// GLOBALNE PROMENLJIVE
std::string filename;

CEBR main(CEBR broj_argumenata, KARAKTER* argumenti[]) {
    std::cout << APP_NAME << __NOVIRED__ << APP_COPYRIGHT << __NOVIRED__ << "Sva prava su zasticena." << __NOVIPASUS__;

    #ifdef DEBUG
    // std::ofstream primer(__PRIMER_FAJL__);
    // std::string az = "abcdefghijklmnopqrstuvwxyz";
    // for (char x : az) {
    //     for (char y : az) {
    //         primer << (encrypt::sl(&x, &y));
    //         primer << " ";
    //     }
    //     primer << std::endl;
    // }
    #endif

    if (broj_argumenata > 1) {
        filename = argumenti[1];
        std::cout << "Otvaram fajl:\t" << filename << std::endl;
    } else {
        std::cout << "Unesite adresu fajla za otvaranje:\t";
        std::getline(std::cin, filename);
        std::cout << "Otvaram fajl:\t" << filename << std::endl;
    }
    std::string ime_pre_tacke = slovo::je_siguran_string(filename.substr(filename.find_last_of(__TREECHAR__) + 1, filename.find('.') - filename.find_last_of(__TREECHAR__) - 1));

    if (filename.size() > 0) {
        try {
            if (filename.substr(filename.find_last_of(".")+1) != APP_EXTENZIJA) {
                std::cout << "Mod:\tENCRYPT" << std::endl;
                std::ifstream citac(filename.data());    // std::string.data(); -> char*
                std::ofstream zapis(filename + "." + APP_EXTENZIJA);

                KARAKTER* _slovo = (KARAKTER*) malloc(sizeof(KARAKTER));
                CEBR* broj = (CEBR*) malloc(sizeof(CEBR));
                *broj = 0;
                while ((*_slovo = citac.get()) != EOF) {
                    zapis << (encrypt::sl(_slovo, &ime_pre_tacke[((*broj)++) % ime_pre_tacke.length()]));
                }
                free(broj);
                free(_slovo);

                zapis.close();
                citac.close();
            } else {
                std::cout << "Mod:\tDECRYPT" << std::endl;
                std::ifstream citac(filename.data());
                std::ofstream zapis(filename.erase(filename.length() - 4));    // ukloniti APP_EXTENZIJA iz stringa + "."

                KARAKTER* _slovo = (KARAKTER*) malloc(sizeof(KARAKTER));
                CEBR* broj = (CEBR*) malloc(sizeof(CEBR));
                *broj = 0;
                while ((*_slovo = citac.get()) != EOF) {
                    zapis << (decrypt::sl(_slovo, &ime_pre_tacke[((*broj)++) % ime_pre_tacke.length()]));
                }
                free(broj);
                free(_slovo);
                
                zapis.close();
                citac.close();
            }
            // std::remove(filename.data());
        } catch (CEBR broj) {
            std::cout << "Uneseni put ne postoji!";
        }
    }
    
    return 0;
}
