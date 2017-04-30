#include "list.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Drzewo *drzewo = new Drzewo;
    int iloscSlow=0, iloscZapytan=0;
    char slowo[100]={'\0'};
    while(cin>>iloscSlow){
        for(int i=0; i<iloscSlow; i++){
            cin>>slowo;
            drzewo->dodajSlowo(slowo);
        }
        cin>>iloscZapytan;
        for(int i=0; i<iloscZapytan; i++){
            bool czyWyswietlono=false;
            cin>>slowo;
            drzewo->wyswietlOdpowiedz(drzewo->korzen, slowo, czyWyswietlono);
            if(!czyWyswietlono)
                cout<<"-";
            cout<<endl;
        }
    }
    return 0;
}
