/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>
struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> ulaz, int br);
std::shared_ptr<Dijete> KreirajPovezanuListu(std::vector<std::string> &unos);
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
    
    //kreairaj povezanu listu
    auto djeca(KreirajPovezanuListu(ulaz));
    
    //kreiraj timove
    std::vector<std::set<std::string>> tim(br);
    //dodatne varijable da ne racuna duzinu prvih i ostalih timova te koliko prvih timova će imati jednog igrača više svaki put u petlji
    int i(0),duz1(ulaz.size()/br+1),duz2(ulaz.size()/br),rbrtima(ulaz.size()%br);

    //inicijalizuj 3 pametna pokazivala, poc će uvjek pokazivat na pocetak, it će se kretati kroz povezanu listu, it2 onaj koji treba obrisat, it3 onaj koji se nalazi prije it2
    std::shared_ptr<Dijete> it(djeca), it2(djeca),poc(djeca),it3(djeca);
    //kada lista bude prazna poc će pokazivati na nullptr
    while(poc != nullptr) {
        tim.resize(i+1);
        //unosi prvih nekoliko timova
        if(tim.size() <= rbrtima)
            while(tim[i].size() < duz1) {
            //↑↑↑↑↑↑ dok je velicina tima manja od predviđene velicine
            
                //porebna bool varijable da ne bi vise puta istu osobu pokusavali brisati 
                bool jednom(true);
                //dodatne varijable, q predstvlja duzinu imena djeteta koje se izbacuje iz kruga
                int p(0),q(prebroj(it->ime));
                
                //U slucaju da nema vise djece odmah prekini petlju
                if(poc->sljedeci == nullptr) {
                    poc = nullptr;
                    break;
                }
                //pot
                //ubaci dijete u tim
                tim[i].insert((it2 = it)->ime);
                
                //eci-peci-pec
                while(p < q) {
                    p++;
                    //prebacuj na slj. dijete 
                    it = it->sljedeci;
                    //ako treba brisati prvo dijete dovoljno je samo pomjeriti pocetak i na slj dijete i obrisati ga ali samo jednom
                    if(it2 == poc && jednom) {
                    
                        poc = it2->sljedeci;
                        it2 = nullptr;
                        jednom = false;
                    }
                    //ako treba neko drugo dijete obrisat osim prvog
                    else if(jednom) {
                        it3 = poc;//postavi pokazivac na pocetak
                        //vrti petlji dok it3 ne bude pokazivao na elemenat "iza" it2
                        while(it3->sljedeci != it2)
                            it3 = it3->sljedeci;;
                        //neka prethodni element pokazuje na onaj ispred onog kojeg treba obrisati    
                        it3->sljedeci = it2->sljedeci;
                        //rijesi se objekta koji nam ne treba
                        it2 = nullptr;
                        jednom = false;
                    }
                    //ako je it nullptr znaci da smo dosli do kraja, idi na pocetak
                    if(it == nullptr)
                        it = poc;
                }
            }
        else {
            //dok je velicina tima manja od predviđene velicine
            while(tim[i].size() < duz2) {
        //sve ispod ponaša se potpuno isto kao i kod unosa prvih nekoliko timova(osim broja članova tima) (mogla se funkcija napraviti za ovo al nemam živaca popravljat eventalne bugove)
                bool jednom(true);
                int p(0),q(prebroj(it->ime));
                tim[i].insert((it2 = it)->ime);
                if(poc->sljedeci == nullptr) {
                    poc = nullptr;
                    break;
                }
                while(p < q) {
                    p++;
                    it = it->sljedeci;
                    if(it2 == poc && jednom) {
                        poc = it2->sljedeci;
                        it2 = nullptr;
                        jednom = false;
                    } else if(jednom) {
                        it3 = poc;
                        while(it3->sljedeci != it2)
                            it3 = it3->sljedeci;;
                        it3->sljedeci = it2->sljedeci;
                        it2 = nullptr;
                        jednom = false;
                    }

                    if(it == nullptr) {
                        it = poc;
                    }
                }
            }
        }
        //pređi na slj. tim
        i++;
    }

    return tim;
}

bool jestotreba(char &p)
{
    //ako je karakter p ono što nam treba vrati true
    if ((p >= 'a' && p <= 'z') ||(p>= '0' && p <= '9') ||(p>= 'A' && p<= 'Z'))
        return true;
    return false;
}
int prebroj(std::string unos)
{
    int br(0);
    
    for(int i(0); i < unos.length(); i++)
        if(jestotreba(unos[i])) //ako jeststotreba vrati true onda povecaj brojac za 1
            br++;
    return br;
}
//modifikovani KreirajPovezanuListu sa tutorijala 8, prima vektor stringova umjesto znaka za prekidanje
std::shared_ptr<Dijete> KreirajPovezanuListu(std::vector<std::string> &unos)
{
    //inicijaliziraj pametne pokazivače
    std::shared_ptr<Dijete> pocetak(nullptr),prethodni;
    //petlja se ponavlja onoliko puta koliku listu treba napraviti
    for(int i(0); i < unos.size(); i++) {
        //kreairaj dinamički objekat
        auto nov = std::make_shared<Dijete>();
        //dodijeli atribute
        nov->ime = unos[i];
        nov->sljedeci = nullptr;
        //povezuj listu
        if(!pocetak) pocetak = nov;
        else prethodni->sljedeci = nov;
        prethodni = nov;
    }

    return pocetak;
}
