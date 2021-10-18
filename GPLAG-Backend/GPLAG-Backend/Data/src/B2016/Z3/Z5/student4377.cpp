/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <set>

struct Dijete
{
    std::string ime;
    Dijete *sljedeci = nullptr;
};

struct Lista
{
    Dijete *pocetak = nullptr;
    Dijete *kraj = nullptr;
    int broj_elemenata = 0;
};

void ListPushBack(Lista &lista, const std::string &ime)
{
    auto novi = new Dijete();
    if(lista.broj_elemenata == 0)
    {
        lista.pocetak = novi;
        lista.kraj = novi;
        novi->ime = ime;
        novi->sljedeci = lista.pocetak;
    }
    else
    {
        novi->ime = ime;
        novi->sljedeci = lista.pocetak;
        lista.kraj->sljedeci = novi;
        lista.kraj = novi;
    }
    lista.broj_elemenata++;
}

Dijete* Indeksiraj(const Lista &lista, int n)
{
    auto p(lista.pocetak);
    for(int i=0; i<n; i++) p = p->sljedeci;
    return p;
}

Dijete *ListErase(Lista &lista, Dijete *pok)
{
    Dijete *pok2;
    lista.broj_elemenata--;
    if(pok != lista.pocetak)
    {
        for(int i=0; i < lista.broj_elemenata; i++)
        {
            pok2 = Indeksiraj(lista, i);
            if(pok2->sljedeci == pok) 
            pok2->sljedeci = pok->sljedeci;
        }
        auto ret(pok->sljedeci);
        //delete pok; pok = nullptr;
        return ret;
    }
    else
    {
        lista.pocetak = pok->sljedeci;
        lista.kraj->sljedeci = lista.pocetak;
        //delete pok; pok = nullptr;
        return lista.pocetak;
    }
}

int DuzinaImena(const std::string &ime)
{
    int brojac(0);
    for(int i=0; i<ime.size(); i++) 
    if((ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9'))
    brojac++;
    return brojac;
}

int OdrediKapacitet(int br_djece, int br_timova, int *visak)
{
    int kap (br_djece/br_timova);
    if(*visak > 0){ kap++; (*visak)--;}
    return kap;
}

Dijete *Broj(Lista &djeca, Dijete* it, int broj_iteracija)
{
    if(djeca.broj_elemenata == 0) return it;
    for(int i=1; i<broj_iteracija; i++)
    it = it->sljedeci;
    return it;
}

Dijete *ListBegin(const Lista &lista)
{
    return lista.pocetak;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &imena, int br_timova)
{
    if(imena.size() < br_timova || br_timova < 1) throw std::logic_error("Razvrstavanje nemoguce");
    Lista djeca;
    for(int i=0; i<imena.size(); i++) ListPushBack(djeca, imena[i]);
    int visak = imena.size()%br_timova; auto *p = &visak;
    std::vector<std::set<std::string>> tim(br_timova, std::set<std::string>{});
    auto it_subjekt(ListBegin(djeca));
    for(int l=0; l<br_timova; l++)
    {
        int kapacitet_tima = OdrediKapacitet(imena.size(), br_timova, p);
        for(int i=0; i<kapacitet_tima; i++)
        {
            int broj_iteracija(DuzinaImena(it_subjekt->ime));
            tim[l].insert(it_subjekt->ime);
            if(djeca.broj_elemenata == 1) it_subjekt->sljedeci = nullptr;
            if(it_subjekt == djeca.kraj) djeca.kraj = Indeksiraj(djeca, djeca.broj_elemenata-2);
            auto del_boy(it_subjekt);
            it_subjekt = ListErase(djeca ,it_subjekt);
            delete del_boy;
            it_subjekt = Broj(djeca, it_subjekt, broj_iteracija);
        }
    }
    return tim;
}

int main ()
{
    try
    {
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    if(n < 1) throw std::logic_error("Razvrstavanje nemoguce");
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> imena(n);
    for(int i=0; i<n; i++)
    std::getline(std::cin, imena[i]);
    std::cout << "\nUnesite broj timova: ";
    int br;
    std::cin >> br;
    
        auto m = Razvrstavanje(imena, br);
        for(int i=0; i<m.size(); i++)
        {
            std::cout << "Tim " << i+1 << ": ";
            for(auto j = m[i].begin(); j != m[i].end(); j++)
            {
                std::cout << *j;
                auto c(m[i].end()); c--;
                if(j != c) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error a) {std::cout << "Izuzetak: " << a.what() << std::endl;}
	return 0;
}