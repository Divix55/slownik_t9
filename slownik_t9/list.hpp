#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <iostream>

#define ALFABET 26

struct ElemDrzewa{
    char kod;
    char dana;
    bool czySlowo;
    ElemDrzewa *rodzic;
    ElemDrzewa *potomek[ALFABET];
    ElemDrzewa(){
        kod=0;
        dana='\0';
        czySlowo=false;
        rodzic=nullptr;
        for(int i=0;i<ALFABET; i++) potomek[i]=nullptr;
    }
};

struct Drzewo{
    ElemDrzewa *korzen;
    
    char koduj(char);
    bool czyIstnieje(ElemDrzewa *, char);
    void dodajSlowo(char[]);
    void wyswietlOdpowiedz(ElemDrzewa *, char[], bool &);
    void wypiszSlowo(ElemDrzewa *);
    Drzewo(){
        korzen=new ElemDrzewa;
    }
};

void slowo(ElemDrzewa *, ElemDrzewa *, char[], bool &);
bool czyWypisac(char[], char[], int);
bool czyNieKoniecGalezi(ElemDrzewa *);
int wypiszDlugosc(char[]);

void wypiszSlowo(ElemDrzewa *);
#endif /* list_hpp */
