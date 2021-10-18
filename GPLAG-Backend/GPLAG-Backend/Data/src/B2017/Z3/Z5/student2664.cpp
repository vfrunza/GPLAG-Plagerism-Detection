/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <map>

enum class Boje{Pik, Tref, Herc, Karo};
using std::string;
using std::multimap;
typedef multimap<Boje, string> Multimapa;
struct Karta{
    Boje boja;
    string vrijednost;
};

struct Cvor{
    Karta karta;
    Cvor* sljedeci;
};

Cvor* KreirajSpil(){
    Boje boje[4]{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    string vrijednosti[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    Cvor *pocetak(nullptr), *prethodni;
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            Cvor* novi(new Cvor{{boje[i], vrijednosti[j]}, nullptr});
            if(!pocetak) pocetak = novi;
            else prethodni->sljedeci = novi;
            prethodni = novi;
            if(i==3 && j==12) novi->sljedeci = pocetak;
        }
    }
    
    
    return pocetak;
}
//referenca na pokazivač jer fja mijenja sadržaj pokazivača a ne objekta na koji pokazuje
/*IzbaciKarte(Cvor* &pocetak, Multimapa &mm){
    
    for(auto mit = mm.begin(); mit != mm.end(); mit++){
        for(Cvor *p=pocetak; p != ; p = p->sljedeci){
            Cvor* lp(pocetak);
            lp = Nadji()
        }
        
    }
    
}*/


int main (){
    
	return 0;
}
