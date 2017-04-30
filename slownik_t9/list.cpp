#include "list.hpp"

#define LITERA 'a'

using namespace std;

int wypiszDlugosc(char zapytanie[]){
    int x=0;
    while(zapytanie[x]!='\0'){
        x++;
    }
    return x;
}

char Drzewo::koduj(char znak){
    if(znak=='a' || znak=='b' || znak=='c')
        return '2';
    else if(znak=='d' || znak=='e' || znak=='f')
        return '3';
    else if(znak=='g' || znak=='h' || znak=='i')
        return '4';
    else if(znak=='j' || znak=='k' || znak=='l')
        return '5';
    else if(znak=='m' || znak=='n' || znak=='o')
        return '6';
    else if(znak=='p' || znak=='q' || znak=='r' || znak=='s')
        return '7';
    else if(znak=='t' || znak=='u' || znak=='v')
        return '8';
    else if(znak=='w' || znak=='x' || znak=='y' || znak=='z')
        return '9';
    else
        return '0';
}

bool Drzewo::czyIstnieje(ElemDrzewa *tmp, char znak){
    bool test=false;
    for(int i=0; i<ALFABET; i++){
        if(tmp->potomek[i]!=nullptr){
            if(tmp->potomek[i]->dana==znak){
                test=true;
            }
        }
    }
    return test;
}

void Drzewo::dodajSlowo(char slowo[]){
    ElemDrzewa *iterator=korzen;
    int x=0;
    while(slowo[x]!='\0'){
        if(!czyIstnieje(iterator, slowo[x])){
            ElemDrzewa *nowy = new ElemDrzewa;
            nowy->dana=slowo[x];
            nowy->kod=koduj(slowo[x]);
            if(slowo[x+1]=='\0'){
                nowy->czySlowo=true;
            }
            iterator->potomek[slowo[x]-LITERA]=nowy;
            iterator->potomek[slowo[x]-LITERA]->rodzic=iterator;
        }
        else{
            if(slowo[x+1]=='\0'){
                iterator->potomek[slowo[x]-LITERA]->czySlowo=true;
            };
        }
        iterator=iterator->potomek[slowo[x]-LITERA];
        x++;
    }
}


void Drzewo::wyswietlOdpowiedz(ElemDrzewa *iterator, char zapytanie[], bool &test){
    for(int i=0; i<ALFABET; i++){
        if(iterator->potomek[i]!=nullptr){
            if(iterator->potomek[i]->czySlowo){
                slowo(iterator->potomek[i], korzen, zapytanie, test);
                //if(czyNieKoniecGalezi(iterator->potomek[i])){
                    wyswietlOdpowiedz(iterator->potomek[i], zapytanie, test);
                //}
                continue;
            }
            else{
                wyswietlOdpowiedz(iterator->potomek[i], zapytanie, test);
            }
        }
    }
}


void Drzewo::wypiszSlowo(ElemDrzewa *tmp){
    int x=0, y=0, z=0;
    char wyraz[100]={'\0'}, kodWyrazu[100]={'\0'};
    char odpowiedz[100]={'\0'}, kodOdpowiedzi[100]={'\0'};
    
    while(tmp!=korzen){
        wyraz[x]=tmp->dana;
        kodWyrazu[x]=tmp->kod;
        tmp=tmp->rodzic;
        x++;
    }
    for(int i=99; i>=0; i--){
        if(wyraz[i]!='\0'){
            odpowiedz[y]=wyraz[i];
            y++;
        }
        if(kodWyrazu[i]!='\0'){
            kodOdpowiedzi[z]=kodWyrazu[i];
            z++;
        }
    }
    
    cout<<odpowiedz<<" ";
}

bool czyNieKoniecGalezi(ElemDrzewa *iterator){
    bool odpowiedz=false;
    for(int i=0; i<ALFABET; i++){
        if(iterator->potomek[i]!=nullptr){
            odpowiedz=true;
        }
    }
    return odpowiedz;
}

void slowo(ElemDrzewa *iterator, ElemDrzewa *korzen, char zapytanie[], bool &test){
    int x=0, y=0, z=0;
    char wyraz[100]={'\0'}, kodWyrazu[100]={'\0'};
    
    while(iterator!=korzen){
        wyraz[x]=iterator->dana;
        kodWyrazu[x]=iterator->kod;
        iterator=iterator->rodzic;
        x++;
    }
    
    char odpowiedz[100]={'\0'}, kodOdpowiedzi[100]={'\0'};
    
    for(int i=99; i>=0; i--){
        if(wyraz[i]!='\0'){
            odpowiedz[y]=wyraz[i];
            y++;
        }
        if(kodWyrazu[i]!='\0'){
            kodOdpowiedzi[z]=kodWyrazu[i];
            z++;
        }
    }
    
    int dlugoscKoduOdpowiedzi=wypiszDlugosc(kodOdpowiedzi), dlugoscZapytania=wypiszDlugosc(zapytanie);
    
    if(dlugoscZapytania<=dlugoscKoduOdpowiedzi){
        if(czyWypisac(kodOdpowiedzi, zapytanie, dlugoscZapytania)){
            cout<<odpowiedz<<" ";
            test=true;
        }
    }
}

bool czyWypisac(char kodOdpowiedzi[], char zapytanie[], int dlugoscZapytania){
    int i=0, odpowiedz=0;
    while(zapytanie[i]!='\0'){
        if(kodOdpowiedzi[i]==zapytanie[i]){
            odpowiedz++;
        }
        else{
            odpowiedz--;
        }
        i++;
    }
    if(odpowiedz!=dlugoscZapytania){
        return false;
    }
    else{
        return true;
    }
}
