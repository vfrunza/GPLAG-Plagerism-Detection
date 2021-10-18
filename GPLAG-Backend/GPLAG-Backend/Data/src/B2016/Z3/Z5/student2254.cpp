/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
struct Dijete {
    std::string ime;
    Dijete *sljedeci = nullptr; //radi delete postavi na nullptr
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> ulaz, int br);
Dijete *KreirajPovezanuListu(std::vector<std::string> &unos);
void UnistiListu(Dijete *pocetak);
bool jestotreba(char &p);
int prebroj(std::string unos);
int main ()
{
    try {
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite imena djece: ";
        std::vector<std::string> imena(n);
        std::cin.ignore(10000, '\n');
        for(int i(0); i < n; i++)
            std::getline(std::cin,imena[i]);

        std::cout<<std::endl<<"Unesite broj timova: ";
        std::cin>>n;

        auto timovi(Razvrstavanje(imena,n));
        for(int i(0); i < n; i++) {
            std::cout<<"Tim "<<i+1<<": ";
            for(auto it(timovi[i].begin()); it != timovi[i].end(); it++) {
                auto it2(timovi[i].end());
                if(it != --it2)
                    std::cout<<*it<<", ";
                else std::cout<<*it;
            }
            std::cout<<std::endl;
        }
    } catch(std::logic_error error) {
        std::cout<<"Izuzetak: "<<error.what();
    }

    return 0;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> ulaz, int br)
{
    if(br < 1 || br > ulaz.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    //kreiraj listu
    auto djeca(KreirajPovezanuListu(ulaz));
    
    //timovi te dodatne varijable da se manje puta racunaju neke stvari(br clanova tima i prvih koliko timova će imati viška igrača)
    std::vector<std::set<std::string>> tim(br);
    int i(0),duz1(ulaz.size()/br+1),duz2(ulaz.size()/br),rbrtima(ulaz.size()%br);
    
    //pokazivači,it da se kreće po listi, it2 da brise elemenat, poc da uvjek na pocetak pokazuje, it3 da pokazuje uvjek "iza" it2
    Dijete *it(djeca), *it2(djeca),*poc(djeca),*it3(djeca);
    while(poc != nullptr) {
        tim.resize(i+1);
        //za prvih nekoliko timova
        if(tim.size() <= rbrtima)
            while(tim[i].size() < duz1) {
                //dok se ne popuni tim ponavljaj
                
                
                //pomocne varijable, jednom sluzi da samo jednom brisemo isto dijete (te da se ne pomjeraju neki pokazivaci),q duzina imena izbacenog djeteta
                bool jednom(true);
                int p(0),q(prebroj(it->ime));
                //ubaci dijete
                tim[i].insert((it2 = it)->ime);
                if(poc->sljedeci == nullptr) {//ako je ubačeno u neki time zadnje dijete iz kruga, nema potreba za daljnim radom
                    delete poc; //obriši objekat
                    poc = nullptr;  //postavi na nullptr(radi glavne petlje)
                    break;  
                }
                while(p < q) {
                    p++;
                    //idi kroz povezano listu
                    it = it->sljedeci;
                    //ako treba izbaciti dijete na pocetku liste dovoljno je samo poc pomjeriti na slj elemenat i izbrisati prvo
                    if(it2 == poc && jednom) {
                        //pomjeranje poc-a
                        poc = it2->sljedeci;
                        //obriši objekat
                        delete it2;
                        jednom = false;
                        
                    } else if(jednom) {
                        //postavi it3 na početak liste
                        it3 = poc;
                        //pomjeraj it3 dok it3 ne bude pokazivao tačno iza it2 
                        while(it3->sljedeci != it2)
                            it3 = it3->sljedeci;;
                        //preusmjeri pokazivače    
                        it3->sljedeci = it2->sljedeci;
                        //obriši objekat koji treba biti obrisan
                        delete it2;
                        jednom = false;
                    }
                    //it = nullptr znači da smo na kraju liste, vrati na početak
                    if(it == nullptr)
                        it = poc;
                }
            }
        else {
            //unos ostalih nekoliko timova
            //Apsolutno se iste stvari dešavaju kao i u gornjem dijelu (mogla je pomocna funkcija ali mi je mrsko ispravljat eventualne bugove) sem što se ovdje unose manji timovi
            while(tim[i].size() < duz2) {
                bool jednom(true);
                int p(0),q(prebroj(it->ime));
                tim[i].insert((it2 = it)->ime);
                if(poc->sljedeci == nullptr) {
                    delete poc;
                    poc = nullptr;
                    break;
                }
                while(p < q) {
                    p++;
                    it = it->sljedeci;
                    if(it2 == poc && jednom) {
                        poc = it2->sljedeci;
                        delete it2;
                        jednom = false;
                    } else if(jednom) {
                        it3 = poc;
                        while(it3->sljedeci != it2)
                            it3 = it3->sljedeci;;
                        it3->sljedeci = it2->sljedeci;
                        delete it2;
                        jednom = false;
                    }

                    if(it == nullptr) {
                        it = poc;
                    }
                }
            }
        }
        i++;
    }

    return tim;
}

bool jestotreba(char &p)
{
    //ako je karakter slovo/broj vrati true
    if ((p >= 'a' && p <= 'z') ||(p>= '0' && p <= '9') ||(p>= 'A' && p<= 'Z'))
        return true;
    return false;
}
int prebroj(std::string unos)
{
    int br(0);
    for(int i(0); i < unos.length(); i++)
        if(jestotreba(unos[i])) //ako je karakter ono što nam treba inkrementiraj brojač
            br++;
    return br;
}
//modifikovani KreirajPovezanuListu sa tutorijala 8, prima vektor stringova umjesto znaka za prekidanje
Dijete *KreirajPovezanuListu(std::vector<std::string> &unos)
{
    //inicijaliziraj pokazivače
    Dijete *pocetak(nullptr),*prethodni;
    //ponovi petlju onoliko puta koliko je veličina vektora
    for(int i(0); i < unos.size(); i++) {
        //dinamički alociraj objekat
        Dijete *nov(new Dijete);
        //dodijeli atribute
        nov->ime = unos[i];
        nov->sljedeci = nullptr;
        //povezuj
        if(!pocetak) pocetak = nov;
        else prethodni->sljedeci = nov;
        prethodni = nov;
    }

    return pocetak;
}
