
/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> nazivi {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
std::vector<std::string> vektorBoja  {"Pik", "Tref", "Herc", "Karo"};
std::string dajBoju (Boje boja) {
     for (int i=0; i<4; i++){
         if (boja==Boje(i)) return vektorBoja.at(i);
     }

}
int dajIndexBoje (Boje boja) {
    for (int i=0; i<4; i++){
         if (boja==Boje(i)) return i;
     }
}
int dajIndexNaziva (std::string naziv) {
    for (int i=0; i<13; i++){
         if (naziv==nazivi.at(i)) return i;
     }
}


bool domenvrijednosti (std::string v) {
    for (int i=0; i<13; i++){
        if (v==nazivi.at(i)) return true;
    }
    return false;
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

struct Karta {
  Boje boja;
  std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci ;
};
Karta DajNovuKartu () {
    static int i (-1);
    i++;
    if (i==52) return { Boje(i/13), "0"};
    return { Boje(i/13), nazivi.at(i%13)};
}
Cvor* KreirajSpil () {
Cvor* pocetak(nullptr), *prethodni;

    for(;;) {
    Karta k (DajNovuKartu());
    if (k.vrijednost == "0") break;
    Cvor *novi(new Cvor {k, nullptr});
    if(!pocetak) pocetak = novi;// Prvi čvor...
    else prethodni->sljedeci = novi; // Svi osim prvog...
    prethodni = novi;
}
prethodni->sljedeci=pocetak;
return pocetak;
}

bool daLiJeKruzna (Cvor* &c) {
    auto pocetak (c);
    auto it (pocetak);
    Cvor* pomocna (nullptr);
    for ( ;;  ){
           if (it == pomocna) return 1;
           if (it == nullptr) return 0;
       // std::cout<<dajBoju((*it).karta.boja)<<" "<<(*it).karta.vrijednost<<"\n";
        pomocna = pocetak;
        it=it->sljedeci;
    }
}
int dajBrojElListe (Cvor* &c) {
    auto pocetak (c);
    auto it (pocetak);
    Cvor* pomocna (nullptr);
    int broj(0);
    for ( ;;  ){
           if (it == pomocna) return broj;
         //  if (it == nullptr) return 0;
       // std::cout<<dajBoju((*it).karta.boja)<<" "<<(*it).karta.vrijednost<<"\n";
        pomocna = pocetak;
        it=it->sljedeci;
        broj++;
    }


}

bool Validno (Cvor* &c) {

    auto pocetak (c);
    auto it (pocetak);
    Cvor* pomocna (nullptr);
    for ( ;;  ){
           if (it == pomocna) break;
      if (!domenBoje((*it).karta.boja) || !domenvrijednosti((*it).karta.vrijednost)) return false;
        pomocna = pocetak;
        it=it->sljedeci;
    }

    std::vector<int> v;
    pocetak = c;
    it = pocetak;
    pomocna = nullptr;
    for (; ; ) {
        if (it == pomocna) break;
        int x(0);
        v.push_back(x);
        auto it1 (pocetak);
        Cvor* pomocna1 (nullptr);
        for (; ;) {
            if (it1 == pomocna1) break;
            if (((*it).karta.boja == (*it1).karta.boja) && ((*it).karta.vrijednost == (*it1).karta.vrijednost)   ) *(v.end()-1)++;
            pomocna1 = pocetak;
            it1=it1->sljedeci;
        }
       pomocna = pocetak;
        it=it->sljedeci;
    }
    for (auto k : v)
     if (k>1) return false;

    return true;
}

bool Sortirano (Cvor* &c ) {
    // spil.sort ( [] (element x, element y) { return index(x.first) >= index(y.first); } );
   //spil.sort ( [] (element x, element y) { if  (index(x.first) != index(y.first)) return true; return indexv(x.second) < indexv(y.second); } );
    int n (dajBrojElListe(c));
    auto it (c);

    for (int i=0 ;  i<n-1; i++  ){

        if  ( dajIndexBoje  ( (it->karta ).boja )
              > dajIndexBoje  ( (it->sljedeci->karta ).boja ) ) return 0;

        if   (  ( dajIndexNaziva ( (it->karta ).vrijednost )
              >   dajIndexNaziva ( (it->sljedeci->karta ).vrijednost ) ) && (
                dajIndexBoje  ( (it->karta ).boja )
             == dajIndexBoje  ( (it->sljedeci->karta ).boja )
               )  )  return 0;

        it=it->sljedeci;
    }


    return 1;
}


void IzbaciKarte ( Cvor* &c, std::multimap<Boje, std::string> &multimapa ){
     if (!daLiJeKruzna(c) || dajBrojElListe(c)>52 || !Validno(c)  ||
          !Sortirano (c)  ) throw std::logic_error ("Neispravna lista");
          int n (dajBrojElListe(c));
    for (auto it = multimapa.begin(); it!=multimapa.end(); it++){
        auto tu ( -1 );
        auto its1 (c);

        for (int i = 0; i != n ; i++){
            if  ( ( (its1->karta).boja == (*it).first)  &&
              ( (its1->karta).vrijednost == (*it).second))
            {
                tu = i;
            }
        if (tu != -1 ) {
         multimapa.erase (it);
          auto p (its1->sljedeci);
          auto pocetni (c);
          if (tu==0)  {
              if (dajBrojElListe(c) == 1) {
                  delete c;
                  c->sljedeci = nullptr;
                  continue;
              }
              else c = c->sljedeci;
              tu = n;
          }
          while (tu!=1) {
              pocetni = pocetni->sljedeci;
              tu--;
          }
            delete pocetni->sljedeci;
            pocetni->sljedeci = p;

        }
        its1=its1->sljedeci;
    }
}
}
void Vrati ( Cvor* &it){
    int n(dajBrojElListe(it));
    for (int i=0; i<n-1; i++)
        it = it->sljedeci;

}

void Obrisi (Cvor* &c, Cvor* &brisi) {
     auto tu ( -1 );
 auto its1 (c);
 int n (dajBrojElListe(c));
for (int i = 0; i != n ; i++){
            if  ( ( (its1->karta).boja == (brisi->karta).boja ) &&
              ( (its1->karta).vrijednost == (brisi->karta).vrijednost)  )
            {
                tu = i;
            }
        if (tu != -1 ) {
          auto p (its1->sljedeci);
          auto pocetni (c);
          if (tu==0)  {
              if (dajBrojElListe(c) == 1) {
                  delete c;
                 c = nullptr;
                 return;
              }
            //  else c = c->sljedeci;
              tu = n;
          }
          while (tu!=1) {
              pocetni = pocetni->sljedeci;
              tu--;
          }
            delete pocetni->sljedeci;
            pocetni->sljedeci = p;
            return;

        }
        its1=its1->sljedeci;
    }
}







std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem ( Cvor* &c, short int &r, const int &b)
{
    if (!daLiJeKruzna(c) || dajBrojElListe(c)>52 || !Validno(c)  ||
          !Sortirano (c)  ) throw std::logic_error ("Neispravna lista");
    if (r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int b1(b);
    int r1(r);

    std::stack<std::pair<std::string, std::string>> stek;
    auto it (c);
    for (; ; ) {
    bool obrisan (0);
        if (r1==1){
            std::string boja  (vektorBoja.at(dajIndexBoje((it->karta).boja)));
            stek.push({boja, (it->karta).vrijednost});
            auto pomocna (it);
             it=it->sljedeci;
            Obrisi (c, pomocna);
            r1 = r+1;
            b1--;
            obrisan =1;
        }
        r1--;
        if (b1==0) break;
        if (!obrisan) it=it->sljedeci;

    }

    return stek;
}
bool validirajStek (std::stack<std::pair<std::string, std::string>> stek) {
    while (!stek.empty()) {
         auto it1 (std::find(vektorBoja.begin(), vektorBoja.end(), stek.top().first) );
         auto it2 (std::find(nazivi.begin(), nazivi.end(), stek.top().second) );
         if (it1 == vektorBoja.end() || it2 == nazivi.end()) return false;
        stek.pop();
}
return true;
}
bool daLiJeTu (Cvor* &c, Cvor* &novi) {
    int n (dajBrojElListe(c));
    Cvor* cvor (c);
    for (int i=0; i<n ; i++) {
        if (  (cvor->karta).boja == (novi->karta).boja  &&
              (cvor->karta).vrijednost == (novi->karta).vrijednost
            ) {return true; }
    cvor = cvor->sljedeci;
    }
    return false;
}

void dodajCvor (Cvor* &c, Cvor* novi ){
    if (c == nullptr) c = novi; //ako je lista prazna bila!
    auto it (c);
    int n (dajBrojElListe(c));
    for (int i=0 ;  i<n; i++  ){
           bool dodati1(0), dodati2(0), dodati3(0);
           auto indexBojeIt   ( dajIndexBoje  ( (it->karta ).boja)  ) ;
           auto indexBojeNove   ( dajIndexBoje  ( (novi->karta ).boja ) );
           auto indexBojeNaredne (  dajIndexBoje  ( (it->sljedeci->karta ).boja )) ;
           auto indexNazivaIt (  dajIndexNaziva ( (it->karta ).vrijednost )  ) ;

           int indexNazivaNove = dajIndexNaziva((novi->karta ).vrijednost);
           auto indexNazivaNaredne  (dajIndexNaziva ( (it->sljedeci->karta ).vrijednost) );

        if (   (indexBojeIt==indexBojeNaredne) &&
               (indexBojeIt==indexBojeNove)  &&
               (indexNazivaIt<indexNazivaNove) &&
               (indexNazivaNaredne>indexNazivaNove)  )dodati1=1;

        if (   (indexBojeIt!=indexBojeNaredne) &&
               (indexBojeNaredne==indexBojeNove)  &&
               (indexNazivaNaredne>indexNazivaNove)  )dodati2=1;

        if (   (indexNazivaIt==11) &&
               (indexNazivaNove==12) &&
               (indexBojeIt == indexBojeNove)
                 )dodati3=1;


        if (dodati1 || dodati2 || dodati3) {
            auto pomocna (it->sljedeci );
            it->sljedeci = novi;
            novi->sljedeci = pomocna;
            return;
        }
           it=it->sljedeci;

    }


}
void IspisiSpil (Cvor* &c) {
    int n(dajBrojElListe(c));
    std::cout<<"U spilu trenutno ima "<<n<<" karata, i to:\n";
for (auto i=0; i<n ; i++){
     std::cout<<"Pik: ";
     while  ((c->karta).boja == Boje::Pik && i!=n ) { std::cout<< (c->karta).vrijednost<< " " ; i++; c = c->sljedeci; }
     std::cout<<"\n";
     std::cout<<"Tref: ";
     while  ((c->karta).boja == Boje::Tref && i!=n ) { std::cout<< (c->karta).vrijednost<< " " ; i++; c = c->sljedeci;  }
     std::cout<<"\n";
     std::cout<<"Herc: ";
     while  ((c->karta).boja == Boje::Herc && i!=n ) { std::cout<< (c->karta).vrijednost<< " " ; i++; c = c->sljedeci; }
     std::cout<<"\n";
     std::cout<<"Karo: ";
     while  ((c->karta).boja == Boje::Karo && i!=n ) { std::cout<< (c->karta).vrijednost<< " " ; i++; c = c->sljedeci; }
     std::cout<<"\n";
     if (n==i) break;
     c = c->sljedeci;
}

}
void VratiPosljednjihNKarata (Cvor* &c, std::stack<std::pair<std::string, std::string>> &stek, int n){
    if (n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n> stek.size()) throw std::range_error ("Nedovoljno karata u steku!");
    if (!validirajStek (stek)) throw std::logic_error ("Neispravne karte!");
    if (!daLiJeKruzna(c) || dajBrojElListe(c)>52 || !Validno(c)  ||
          !Sortirano (c)  ) throw std::logic_error ("Neispravna lista");
   while (n!=0) {
            int x = std::find (vektorBoja.begin(), vektorBoja.end(), stek.top().first ) - vektorBoja.begin();
            Cvor* novi = new Cvor {  {Boje(x), stek.top().second}, nullptr}; //Kreiran pomocni par samo da se pretvori string->Boja
         if (daLiJeTu(c, novi) == 0) { //Nema ga vec u mapi, onda dodaji
             dodajCvor (c, novi);
             n--;
         }
         else delete novi;
        stek.pop();

      //  IspisiSpil(c);
}

}

void UnistiSpil ( Cvor* &p) {
    if (p == nullptr) return ;
    int n(dajBrojElListe(p));
    while (n !=0 ){
    auto pomocna (p);
    for (int i=0; i<n-2; i++){
       pomocna = pomocna->sljedeci;
    }
    if (n!=1 )delete pomocna->sljedeci;
    if (n==1) delete pomocna;
    n--;
    }
}






int main ()
{
    auto l (KreirajSpil());
try {

std::cout<<"Unesite korak razbrajanja: ";
short int r;
int b;
std::cin>>r;
std::cout<<"Unesite broj karata koje zelite izbaciti: ";
std::cin>>b;
auto izbacene (IzbaciKarteRazbrajanjem (l, r, b) );

IspisiSpil(l);

//std::cout<< !daLiJeKruzna(l) << (dajBrojElListe(l)>52) <<  !Validno(l)  <<
  //        !Sortirano (l)   ;

int n;
std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
std::cin>>n;
VratiPosljednjihNKarata(l, izbacene, n);
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

UnistiSpil(l);


	return 0;
}
