/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stdexcept>

std::vector<std::string> nazivi {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::pair<Boje, std::string> element;
std::vector<std::string> vektorBoja = {"Pik", "Tref", "Herc", "Karo"};
std::list<std::pair<Boje, std::string>> KreirajSpil () {
    std::list<std::pair<Boje, std::string>> spil;
    for (int i=0; i<4; i++){
        for (int j=0; j<13; j++ ){
            spil.push_back ({Boje(i), nazivi.at(j)});
        }
    }

return spil;
}
bool domenBoje (Boje boja ){
    for (int i=0; i<3; i++)
        if (boja== Boje::Pik
        || boja== Boje::Tref
        || boja== Boje::Herc
         || boja== Boje::Karo

        ) return true;


    return false;
}
bool domenvrijednosti (std::string v) {
    for (int i=0; i<13; i++){
        if (v==nazivi.at(i)) return true;
    }
    return false;
}

bool Validno (std::list<std::pair<Boje, std::string>> &spil) {
    for (auto it = spil.begin(); it!= spil.end(); it++) {
        if (!domenBoje((*it).first) || !domenvrijednosti((*it).second)) return false;
    }
    std::vector<int> v;

    for (auto it = spil.begin(); it!= spil.end(); it++) {
        int x(0);
        v.push_back(x);
        for (auto it1 = spil.begin(); it1!= spil.end(); it1++) {
            if (*it == *it1) *(v.end()-1)++;
    }
    }
    for (auto k : v)
     if (k>1) return false;

    return true;
}
int index (Boje boja) {


     if (   boja== Boje::Pik) return 0;
       if ( boja== Boje::Tref) return 1;
       if ( boja== Boje::Herc) return 2;
        if (boja== Boje::Karo) return 3;

}
int indexv (std::string rijec) {
    for (int i=0; i<13; i++)
        if (rijec==nazivi.at(i)) return i;

}
void IspisiSpil (std::list<element> &l ) {
    std::cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:\n";
for (auto it = l.begin(); it!=l.end() ; it++){
     std::cout<<"Pik: ";
     while  ((*it).first == Boje::Pik && it!=l.end() )  std::cout<< (*it++).second<< " " ;
     std::cout<<"\n";
     std::cout<<"Tref: ";
     while ((*it).first == Boje::Tref && it!=l.end()) std::cout<< (*it++).second<< " ";
     std::cout<<"\n";
     std::cout<<"Herc: ";
     while ((*it).first == Boje::Herc && it!=l.end())  std::cout<< (*it++).second<< " ";
     std::cout<<"\n";
     std::cout<<"Karo: ";
     while ((*it).first == Boje::Karo && it!=l.end() )  std::cout<< (*it++).second<< " ";
     std::cout<<"\n";
     if (it == l.end()) break;
}
}





bool Sortirano (std::list<element> &spil ){

    auto pomocna (spil); 
    
    pomocna.sort ( [] (element x, element y) { return  (index(x.first) >= index(y.first)); } );
   pomocna.sort ( [] (element x, element y) { if  (index(x.first) != index(y.first)) return true; return (indexv(x.second) < indexv(y.second) ); } );
if (pomocna == spil ) return true;

    return false;
}


void IzbaciKarte (std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &multimapa){
    if (spil.size()>52 || !Validno(spil) ||
          !Sortirano (spil)) throw std::logic_error ("Neispravna lista");
    for (auto it = multimapa.begin(); it!=multimapa.end(); it++){
        auto its (spil.end());
        for (auto its1 = spil.begin(); its1 != spil.end(); its1++){
            if  (   ((*its1).first == (*it).first )
             && ((*its1).second == (*it).second )
            ) its = its1;
        }
        if (its != spil.end()) {
            multimapa.erase (it);
            spil.erase (its);
        }
    }
}
std::queue<std::pair<std::string, std::string>>  IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &spil, short int &r, const int &b)  {
    if (r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");

 //   std::cout << (spil.size() > 52 )  << !Validno(spil) <<
   //       !Sortirano (spil) ;

    if (spil.size()>52 || !Validno(spil) ||
          !Sortirano (spil)) throw std::logic_error ("Neispravna lista");
    int b1(b); 
    int r1(r);
    std::queue<std::pair<std::string, std::string>> red;
    auto it (spil.begin());    
    for (;; ) {
        if (r1==1){
            bool kraj(0);
            std::string boja (vektorBoja.at(index(((*it).first)))); 
            red.push({boja, (*it).second});
            auto pomocna (it);
            if (it==spil.begin()) kraj = 1;
            if (kraj!= 1) it--;
            spil.erase(pomocna); 
            if (kraj == 1) break;
            r1 = r+1;
            b1--;
        }
        r1--;
        if (b1==0) break;
        auto zadnja (it);
        zadnja++;
        if(zadnja == spil.end()) it = spil.begin(); 
        else it++; 
    }
   
    return red;
}

bool validirajRed (std::queue<std::pair<std::string, std::string>> red) {
    while (!red.empty()) {
         auto it1 (std::find(vektorBoja.begin(), vektorBoja.end(), red.front().first) );
         auto it2 (std::find(nazivi.begin(), nazivi.end(), red.front().second) );
         if (it1 == vektorBoja.end() || it2 == nazivi.end()) return false;
        red.pop();
}
return true;
}

void VratiPrvihNKarata ( std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &red, int n ){
     if (n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n> red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    if (!validirajRed (red)) throw std::logic_error ("Neispravne karte!");
    if (spil.size()>52 || !Validno(spil) ||
          !Sortirano (spil)) throw std::logic_error ("Neispravna lista");
   while (n!=0) {
            int x = std::find (vektorBoja.begin(), vektorBoja.end(), red.front().first ) - vektorBoja.begin();
            std::pair<Boje, std::string> par = {Boje(x), red.front().second }; //Kreiran pomocni par samo da se pretvori string->Boja
         if (std::find (spil.begin(), spil.end(), par ) == spil.end() ) { //Nema ga vec u mapi, onda dodaji
             spil.push_back (par);
         }
        red.pop();
        n--;
}
   spil.sort ( [] (element x, element y) { return index(x.first) >= index(y.first); } );
   spil.sort ( [] (element x, element y) { if  (index(x.first) != index(y.first)) return true; return indexv(x.second) < indexv(y.second); } );

}

int main ()
{
try {
   auto l (KreirajSpil());
std::cout<<"Unesite korak razbrajanja: ";
short int r;
int b;
std::cin>>r;
std::cout<<"Unesite broj karata koje zelite izbaciti: ";
std::cin>>b;
auto izbacene (IzbaciKarteRazbrajanjem (l, r, b) );

IspisiSpil(l);

int n;
std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
std::cin>>n;
VratiPrvihNKarata(l, izbacene, n);
IspisiSpil(l);
}
catch (std::logic_error e) {
    std::cout<<"Izuzetak: "<<e.what();
}
catch (std::domain_error e) {
    std::cout<<"Izuzetak: "<<e.what();
}
catch (std::range_error e) {
    std::cout<<"Izuzetak: "<<e.what();
}
catch (...) {

std::cout<<"nesto drugo";

}
	return 0;
}



