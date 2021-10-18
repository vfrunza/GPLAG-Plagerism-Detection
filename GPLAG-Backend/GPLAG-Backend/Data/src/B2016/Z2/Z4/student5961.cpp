#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <algorithm>
// Samo da napomenem da su skoro svi prgrami radeni u CLion-u
// zbog predivnog debugera (o_o)  i zbog toga sto
//  se u CLion-u tokom pisanja koda odmah prijavi greska ako
// fulim neko slovo........itd itd... pozdrav (*__*)
// Ne brinite ne prijavljuju se greske oko formiranja
// funkcija template i tako toga to se skonta tokom kompajliranja
// Provjera jednakosti dva imena
bool jednakaImena(char *ime1, std::string ime2){
    int i{};
    if(!ime1 || !ime2.length()) return false;
    while(*ime1 == ime2[i] && *ime1 != '\0' && i != ime2.length()){
        ime1++; i++;
    }
    if (*ime1 != '\0' || i != ime2.length()) return false;
    return true;
}
// Prebrojavanje null pokazivaca
int viseOdDesetObrisano(char **prodavaci, int duzina){
    int br_obrisanih(0);
    for(int i(0); i < duzina; i++){
        if(!prodavaci[i]) br_obrisanih++;
    }
    return br_obrisanih;
}
// Uredivanje liste pravljenjem nove
int DefragmentirajListu(char **&krivci, int duzina, int br_obrisanih){
    char **nova_lista(nullptr);
    try{
        nova_lista = (new char*[duzina-br_obrisanih]);
    }
    catch(std::bad_alloc){
        delete[] nova_lista;
        throw;
    }
    int brojac_nove_liste(0);
    for(int i(0); i < duzina; i++){
        int duzina_imena(0);
        if(krivci[i]){
            // Odredivanje duzine imena
            while(krivci[i][duzina_imena] != '\0'){
                duzina_imena++;
                if(krivci[i][duzina_imena] == '\0'){
                    duzina_imena++; break;
                }
            }
            nova_lista[brojac_nove_liste] = nullptr;
            // Alociranje memorije za ime
            try{
                nova_lista[brojac_nove_liste] = (new char[duzina_imena]);
            }
            catch(std::bad_alloc){  // U slucaju da padne alokacija nista se ne mijenja
                for(int k(0); k <= brojac_nove_liste; k++)
                    delete[] nova_lista[k];
                delete[] nova_lista;
                throw;
            }
            for(int j(0); j < duzina_imena+1; j++){  // Prepisivanje imena ukljucujuci i '\0'
                nova_lista[brojac_nove_liste][j] = krivci[i][j];
            }
            brojac_nove_liste++;  // Uvecavamo duzinu nove liste kad dopisemo novo ime
        }
    }
    for(int i(0); i < duzina; i++)
        delete[] krivci[i];
    delete[] krivci;
    krivci = nova_lista;
    return brojac_nove_liste;
}
// Upisivanje potencijalnih krivaca u kao listu u alociranu memoriju
int PotencijalniKrivci(char **&mat, std::vector<std::string> lista){
    mat = nullptr;  // Zbog sigurnosti kod lose alokacije
    try{
        mat = (new char*[lista.size()]); //Alocira se niz pokazivaca na znak(char)
    }
    catch(std::bad_alloc){
        delete[] mat;
        throw;
    }
    // Postavljanje pokazivaca na null sbog sigurnosti
    for(int i(0); i < lista.size(); i++){
        mat[i] = nullptr;
    }
    try{
        for(int i(0); i < lista.size(); i++)
            mat[i] = (new char[lista.at(i).length()+1]);   // Alociraju se nizovi charova
    }
    catch(std::bad_alloc){
        for(int i(0); i < lista.size(); i++)
            delete[] mat[i];   // brise se alocirana memorija
        delete[] mat;
        throw;
    }
    int duzina_liste(lista.size());
    for(int i(0); i < duzina_liste; i++){
        for(int j(0); j < lista.at(i).length()+1; j++){   // Ide se do duzine imena +1 zbog NULL znaka
            if(j == lista.at(i).length()){
                mat[i][j] = '\0'; break;    // Postavljanje NULL znaka na kraj char niza
            }
            mat[i][j] = lista.at(i).at(j);
        }

    }
    return duzina_liste;
}
// Brisanje zbog nedostatka dokaza (-_-)
int OdbaciOptuzbu(char **&prodavaci, int br_prodavaca, std::string osoba){
    int ima_ime(0);
    for(int i