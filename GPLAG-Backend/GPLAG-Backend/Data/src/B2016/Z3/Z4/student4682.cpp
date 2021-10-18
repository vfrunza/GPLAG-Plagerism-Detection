/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> ulaz, int br);
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
    std::list<std::string> djeca; //(beskorisna informacija) da radi đ stavio bih ime đeca
    //kreiraj listu
    for(auto &x: ulaz)
        djeca.push_back(x);

    //kreiraj timove i pomocne varijable da se neke stvari ne racunaju više puta u petlji(br članova tima i koliko prvih timova će imati viška člana)
    std::vector<std::set<std::string>> tim(br);
    int i(0),duz1(ulaz.size()/br+1),duz2(ulaz.size()/br),rbrtima(ulaz.size()%br);
    
    //jedan iterator da ide kroz listu, drugi da briše elemenat koji nam ne treba
    auto it(djeca.begin()), it2(djeca.begin());
    //vrti petlji dok lista en bude prazna
    while(djeca.begin() != djeca.end()) {
        tim.resize(i+1);
        if(tim.size() <= rbrtima)   //unesi prvih nekoliko timova
            while(tim[i].size() < duz1) {
                
                //pomocne varijable, q je broj karaktera nekog imena
                int p(0),q(prebroj(*it));
                //ubaci u tim i postavi it2 na onaj objekat koji treba izbaciti iz liste
                tim[i].insert(*(it2 = it));
                while(p < q) {
                    p++;
                    //kreci se kroz listu
                    it++;
                    //s obzirom da se nije desilo izbacivanje ako naleti na isto dijete samo neka ga preskoci
                    if (it == it2)
                        it++;
                    //ako je došlo do kraja vrati na početak
                    if(it == djeca.end()){
                        it = djeca.begin();
                        //ako je prvi objekat dijete koje je trebalo biti izbačeno a while petlja se prekida neće imati priliku preskočiti onog što ne treba
                        //pa to radimo ovdje
                        if(it == it2)
                            it++;
                    }
                }
                //obriši
                djeca.erase(it2);
                
                //ako nema više djece prekini petlju
                if (djeca.size() == 0)
                    break;
            }

        else {
            //unesi ostale timove
            //isto se ponaša kao i za prve timove, jedina razlika je u veličini tima
            while(tim[i].size() < duz2) {
                int p(0),q(prebroj(*it));
                tim[i].insert(*(it2 = it));
                while(p < q) {
                    p++;
                    it++;
                    if(it == it2)
                        it++;

                    if(it == djeca.end()) {
                        it = djeca.begin();
                        if(it == it2)
                            it++;
                    }

                }
                djeca.erase(it2);
                if (djeca.size() == 0)
                    break;
            }
        }
        i++;
    }
    return tim;
}

bool jestotreba(char &p)
{
    //vrati true ako je karakter onaj koji nam treba
    if ((p >= 'a' && p <= 'z') ||(p>= '0' && p <= '9') ||(p>= 'A' && p<= 'Z'))
        return true;
    return false;
}
int prebroj(std::string unos)
{
    //prebroj "korisne" karaktere imena
    int br(0);
    for(int i(0); i < unos.length(); i++)
        if(jestotreba(unos[i]))
            br++;
    return br;
}