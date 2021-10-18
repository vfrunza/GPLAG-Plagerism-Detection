/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <stdexcept>
#include <stack>
#include <iomanip>


enum class Boje
{
    Pik, Tref, Herc, Karo
};

const char* VrijednostKarte[13] {
    "2","3","4","5","6","7","8","9","10","J","Q","K","A"
};

const char* BojaKarte[4] {
    "Pik","Tref","Herc","Karo"
};


struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci=nullptr;
};

typedef std::multimap<Boje, std::string> multimapa;

int br_elem(Cvor* pocetak);
int daj_ID_Boje(std::string );
int daj_ID_Vrijednosti(std::string);

Cvor* KreirajSpil();
void UnistiSpil(Cvor*);
void IzbaciKarte(Cvor* &pocetak, multimapa m);
std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor* &pocetak, const short int&,const int&);
void VratiPosljednjihNKarata(Cvor* &,std::stack<std::pair<std::string,std::string>>&, int );


int main ()
{

Cvor* pocetak=nullptr;
try{
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        pocetak=KreirajSpil();
        auto stek_za_kasnije( IzbaciKarteRazbrajanjem(pocetak,r,b));
        std::cout<<"U spilu trenutno ima "<<br_elem(pocetak)<<" karata, i to:";
    for(int i=0; i<4; i++) {
        std::cout<<"\n"<<BojaKarte[i]<<": ";
        if(!pocetak)continue;
        for(Cvor* klizni=pocetak;;) {
            if(klizni->karta.boja==Boje(i)) {
                std::cout<<klizni->karta.vrijednost<<" ";
            }
            klizni=klizni->sljedeci;
            if(klizni==pocetak)break;
        }
    }
    
    
        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        // VratiPrvihNKarata(spil,za_kasnije,n);
        VratiPosljednjihNKarata(pocetak,stek_za_kasnije,n);
        std::cout<<"U spilu trenutno ima "<<br_elem(pocetak)<<" karata, i to:";
    for(int i=0; i<4; i++) {
        std::cout<<"\n"<<BojaKarte[i]<<": ";
        if(!pocetak)continue;
        for(Cvor* klizni=pocetak;;) {
            if(klizni->karta.boja==Boje(i)) {
                std::cout<<klizni->karta.vrijednost<<" ";
            }
            klizni=klizni->sljedeci;
            if(klizni==pocetak)break;
        }
    }
  
}catch(std::domain_error izuzetak)
    {
        std::cout <<"Izuzetak: "<< izuzetak.what();
    }
    catch(std::range_error izuzetak)
    {
        std::cout << "Izuzetak: " <<izuzetak.what();
    }
    catch( std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " <<izuzetak.what();
    }
    catch(...)
    {
        std::cout<<"Problemi s memorijom!";
    }
    UnistiSpil(pocetak);
    return 0;
}

void VratiPosljednjihNKarata(Cvor* &pocetak, std::stack<std::pair<std::string,std::string>>& stek, int n)
{
    if(n<0)throw std::domain_error("Broj n je besmislen!");
    if (n>static_cast<int>(stek.size())) {
        throw std::range_error("Nedovoljno karata u steku!");
    }
    int broj_elemenata(br_elem(pocetak));
    if(broj_elemenata==-1) {
        //bacanje izuzetka
        //preduga lista
        //nije kruzna
        throw std::logic_error("Neispravna lista!");
    }
    Cvor* klizni=pocetak;
    for(;klizni->sljedeci!=pocetak;)
    {
        if(!(daj_ID_Vrijednosti(klizni->karta.vrijednost)+1) || !(daj_ID_Vrijednosti(klizni->sljedeci->karta.vrijednost)+1) )throw std::logic_error("Neispravna lista!");
        if(klizni->karta.boja > klizni->sljedeci->karta.boja)throw std::logic_error("Neispravna lista!");
       if(klizni->karta.boja == klizni->sljedeci->karta.boja && daj_ID_Vrijednosti(klizni->karta.vrijednost) >= daj_ID_Vrijednosti(klizni->sljedeci->karta.vrijednost))
        throw std::logic_error("Neispravna lista!");
      klizni=klizni->sljedeci;
    }
    Cvor* temp(nullptr);
    Cvor* lijevi(nullptr);
    Cvor* desni(nullptr);

    
        for(int i=0; i<n; i++) {
            //provjera karti
                if(!(daj_ID_Vrijednosti(stek.top().second) +1) || !(daj_ID_Boje(stek.top().first)+1))
                throw std::logic_error("Neispravne karte!");
            //ovdje se vrsi provjera karti
            //kreiranje novog cvora
            temp=new Cvor();
            temp->karta.vrijednost=(stek.top()).second;
            temp->karta.boja=Boje(daj_ID_Boje(stek.top().first));

            if(!pocetak) {
                //nema karata
                //krecemo od nule
                pocetak=temp;
                pocetak->sljedeci=pocetak;
            } else {
                //postoji n karata , n>0
                if( pocetak->karta.boja > temp->karta.boja || (pocetak->karta.boja == temp->karta.boja && daj_ID_Vrijednosti(pocetak->karta.vrijednost)>daj_ID_Vrijednosti(temp->karta.vrijednost) ) ) {
                    //trebam na pocetak postaviti
                    temp->sljedeci=pocetak;
                    lijevi=pocetak;
                    for(;;) {
                        if(lijevi->sljedeci==pocetak)break;
                        lijevi=lijevi->sljedeci;
                    }
                    lijevi->sljedeci=temp;
                    pocetak=temp;
                    temp=nullptr;

                } else {
                    desni=pocetak;
                    lijevi=pocetak;
                    for(;;) {
                        if(lijevi->sljedeci == pocetak)break;
                        lijevi= lijevi->sljedeci;
                    }
                    desni=desni->sljedeci;
                    lijevi=lijevi->sljedeci;
                    for(;;) {
                        if ( (temp->karta.vrijednost ==desni->karta.vrijednost && temp->karta.boja == desni->karta.boja)||
                                (temp->karta.vrijednost ==lijevi->karta.vrijednost && temp->karta.boja == lijevi->karta.boja))
                                break;
                        if( (temp->karta.boja == lijevi->karta.boja &&
                                ( (temp->karta.boja == desni->karta.boja &&
                                   daj_ID_Vrijednosti(temp->karta.vrijednost)>daj_ID_Vrijednosti(lijevi->karta.vrijednost)
                                   && daj_ID_Vrijednosti(temp->karta.vrijednost) < daj_ID_Vrijednosti(desni->karta.vrijednost)
                                  )||(temp->karta.boja < desni->karta.boja &&  daj_ID_Vrijednosti(temp->karta.vrijednost)>daj_ID_Vrijednosti(lijevi->karta.vrijednost))
                                )
                            )
                                ||
                                ( temp->karta.boja > lijevi->karta.boja && temp->karta.boja < desni->karta.boja  )
                                ||
                                (  temp->karta.boja > lijevi->karta.boja && temp->karta.boja == desni->karta.boja && daj_ID_Vrijednosti(temp->karta.vrijednost)<daj_ID_Vrijednosti(desni->karta.vrijednost))
                                ||
                                desni==pocetak

                          ) {
                            //insert izmedju lijevog i desnog
                            lijevi->sljedeci=temp;
                            temp->sljedeci=desni;
                            temp=nullptr;
                            break;
                        }
                        lijevi=lijevi->sljedeci;
                        desni=desni->sljedeci;
                    }


                }
            }
            stek.pop();
        }
     
    
    
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor* &pocetak, const short int& r,const int& b)
{
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    int broj_elemenata(br_elem(pocetak));
    if(broj_elemenata==-1) {
        //bacanje izuzetka
        //preduga lista
        //nije kruzna
        throw std::logic_error("Neispravna lista!");
    }
    Cvor* klizni=pocetak;
    for(;klizni->sljedeci!=pocetak;)
    {
        if(!(daj_ID_Vrijednosti(klizni->karta.vrijednost)+1) || !(daj_ID_Vrijednosti(klizni->sljedeci->karta.vrijednost)+1) )throw std::logic_error("Neispravna lista!");
        if(klizni->karta.boja > klizni->sljedeci->karta.boja)throw std::logic_error("Neispravna lista!");
       if(klizni->karta.boja == klizni->sljedeci->karta.boja && daj_ID_Vrijednosti(klizni->karta.vrijednost) >= daj_ID_Vrijednosti(klizni->sljedeci->karta.vrijednost))
        throw std::logic_error("Neispravna lista!");
      klizni=klizni->sljedeci;
    }
    std::stack<std::pair<std::string,std::string>> stek ;
    if(!pocetak)return stek;
    Cvor *lijevi,*srednji,*desni;
    srednji=pocetak;

    desni=pocetak->sljedeci;
    lijevi=pocetak;

    for(;;) {
        if(lijevi->sljedeci == pocetak)break;
        lijevi= lijevi->sljedeci;
    }

    for(int i=0; i<b && pocetak ; i++) {
        for(int j=0; j<r-1 && srednji; j++) {
            srednji=srednji->sljedeci;
            desni=desni->sljedeci;
            lijevi=lijevi->sljedeci;
        }

        if(pocetak==lijevi && lijevi==desni) {
            stek.push(std::pair<std::string,std::string>(BojaKarte[static_cast<int>(pocetak->karta.boja)], pocetak->karta.vrijednost));
            delete pocetak;
            pocetak=nullptr;
            break;
        }
        //prvo treba spojiti lijevi i desni
        if(pocetak==srednji) {
            pocetak=desni;
            lijevi->sljedeci=desni;
            stek.push(std::pair<std::string,std::string>(BojaKarte[static_cast<int>(srednji->karta.boja)], srednji->karta.vrijednost));
            delete srednji;
            srednji=desni;
            desni=desni->sljedeci;
            // std::cout<<"\nIzbriso prvi\n";
        } else {
            lijevi->sljedeci=desni;
            stek.push(std::pair<std::string,std::string>(BojaKarte[static_cast<int>(srednji->karta.boja)], srednji->karta.vrijednost));
            delete srednji;
            srednji=desni;
            desni=desni->sljedeci;
            // std::cout<<"\nIzbriso neki\n";
        }

    }

    return stek;

}




Cvor* KreirajSpil()
{
    //povezati sve u cirkularnu listu i vratiti pokazivac na prvi
    Cvor* pocetak=nullptr;
    Cvor* klizni=nullptr;
    Cvor* novi=nullptr;
    try {
        for(int i=0; i<4; i++) {
            for(int j=0; j<13; j++) {
                novi= new Cvor();
                novi->karta.boja=Boje(i);
                novi->karta.vrijednost=std::string(VrijednostKarte[j]);
                if(i==0 && j==0) {
                    pocetak=novi;
                    klizni=novi;

                } else {
                    klizni->sljedeci=novi;
                    klizni=klizni->sljedeci;
                }

            }
        }
        klizni->sljedeci=pocetak;
    } catch(...) {
        ///brisanje liste
        UnistiSpil(pocetak);
    }
    return pocetak;
}

void UnistiSpil(Cvor* pocetak)
{
    if(!pocetak)return;
    for(Cvor* klizni = pocetak,*pomocni=pocetak->sljedeci; klizni;) {
        delete klizni;
        klizni=pomocni;
        if(pomocni==pocetak)break;
        pomocni=pomocni->sljedeci;
    }
}

void IzbaciKarte(Cvor* &pocetak, multimapa m)
{
    if(!pocetak)return;
    Cvor *lijevi,*srednji,*desni;
    srednji=pocetak;

    desni=pocetak->sljedeci;
    lijevi=pocetak;
    for(;;) {
        if(lijevi->sljedeci == pocetak)break;
        lijevi= lijevi->sljedeci;
    }
    //sad kad imamo trio fantastiko, mozemo krenuti sa izbacivanjem
    int posjeta(0);
    int broj_elemenata(br_elem(pocetak));
    if(broj_elemenata==-1) {
        //bacanje izuzetka
        //preduga lista
        //nije kruzna
        throw std::logic_error("Neispravna lista!");
    }
    Cvor* klizni=pocetak;
    for(;klizni->sljedeci!=pocetak;)
    {
        if(!(daj_ID_Vrijednosti(klizni->karta.vrijednost)+1) || !(daj_ID_Vrijednosti(klizni->sljedeci->karta.vrijednost)+1) )throw std::logic_error("Neispravna lista!");
        if(klizni->karta.boja > klizni->sljedeci->karta.boja)throw std::logic_error("Neispravna lista!");
       if(klizni->karta.boja == klizni->sljedeci->karta.boja && daj_ID_Vrijednosti(klizni->karta.vrijednost) >= daj_ID_Vrijednosti(klizni->sljedeci->karta.vrijednost))
        throw std::logic_error("Neispravna lista!");
      klizni=klizni->sljedeci;
    }

    for(;;) {
        //for petlja koja prolazi kroz listu
        if(!m.size())return;
        for (auto it = m.begin(); it != m.end(); it++) {
            /* code */
            if(it->first == srednji->karta.boja && it->second == srednji->karta.vrijednost) {
                //brisanje underway
                //special case
                if(pocetak==lijevi && lijevi==desni) {
                    delete pocetak;
                    pocetak=nullptr;
                    return;
                }
                //prvo treba spojiti lijevi i desni
                if(pocetak==srednji) {
                    pocetak=desni;
                    lijevi->sljedeci=desni;
                    delete srednji;
                    srednji=desni;
                    desni=desni->sljedeci;
                    posjeta++;
                    it=m.begin();
                    // std::cout<<"\nIzbriso prvi\n";
                } else {
                    lijevi->sljedeci=desni;
                    delete srednji;
                    srednji=desni;
                    posjeta++;
                    desni=desni->sljedeci;
                    it=m.begin();
                    // std::cout<<"\nIzbriso neki\n";
                }

            }
            auto it2=it;
            it2++;
            if(it2==m.end())posjeta++;
            //uslov prekida mi treba ovdje

        }
        // std::cout<<"\nPosjeta: "<<posjeta<<"\n";
        if(posjeta >= broj_elemenata)break;
        lijevi=srednji;
        srednji=desni;
        desni=desni->sljedeci;
        // posjeta++;

    }

}

int br_elem(Cvor* pocetak)
{
    int result(0);
    if(!pocetak)return result;
    Cvor* klizac(pocetak->sljedeci);
    for(;;) {
        result++;
        if(klizac==pocetak)break;
        if(klizac==nullptr)return -1;
        klizac=klizac->sljedeci;
    if(result>52)return -1;
    }
    return result;
}

int daj_ID_Boje(std::string a)
{
    for(int i=0; i<4; i++) {
        if(a == BojaKarte[i])return i;
    }
    return -1;
}

int daj_ID_Vrijednosti(std::string a)
{
    for(int i=0; i<13; i++) {
        if(a == std::string(VrijednostKarte[i]))return i;
    }
    return -1;
}
