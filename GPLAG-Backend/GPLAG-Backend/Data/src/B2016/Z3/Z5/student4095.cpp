/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>

bool DaLiJeSlovoIliBroj (char znak)
{
    if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'))
        return true;
    return false;
}

int DuzinaImena (std::string ime)
{
    int duzina(0);
    auto it(ime.begin());
    while (it!=ime.end())
    {
        if(DaLiJeSlovoIliBroj(*it))
            duzina++;
        it++;
    }
    return duzina;
}

struct Dijete 
{
    std::string ime;
    Dijete* sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int k)
{
    if(k<1 || k>imena.size())
        throw std::logic_error ("Razvrstavanje nemoguce");
    Dijete* pocetak(nullptr), *prethodni;
    int n(imena.size());
    for(int i=0; i<n; i++)
    {
        Dijete* novi(new Dijete);
        novi->ime=imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak)
            pocetak=novi;
        else
            prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    std::vector<int> br_po_timu(k);
    for(int i=1; i<=k; i++)
    {
        if(i<=n%k)
            br_po_timu[i-1]=n/k+1;
        else
            br_po_timu[i-1]=n/k;
    }
    std::vector<std::set<std::string>> rezultat(k);
    int duzina(DuzinaImena(pocetak->ime));
    rezultat[0].insert(pocetak->ime);
    prethodni->sljedeci=pocetak->sljedeci;
    delete pocetak;
    pocetak=prethodni->sljedeci;
    
    Dijete *p(pocetak);
    int i(0), j(1); //vjestacka petlja za unos u vektor
    for(int l=1; l<n; l++)
    {
        for(int m=0; m<duzina-2; m++)
            p=p->sljedeci;
        Dijete* q=p->sljedeci;
        duzina=DuzinaImena(q->ime);
        p->sljedeci=q->sljedeci;
        if (j>br_po_timu[i]-1)
        {
            i++;
            j=1;
            rezultat[i].insert(q->ime);
        }
        else
        {
            j++;
            rezultat[i].insert(q->ime);
        }
        p=p->sljedeci;
        delete q;
        
    }
    return rezultat;
}

int main ()
{
    int br_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    std::cin.ignore(10000,'\n');
    std::vector<std::string> imena(br_djece);
    std::cout<<"Unesite imena djece: ";
    for (std::string &ime: imena)
        std::getline(std::cin, ime);
    int n;
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>n;
    try{
        std::vector<std::set<std::string>> timovi(Razvrstavanje(imena, n));
        for (int i=0; i<timovi.size(); i++)
        {
            std::cout<<"Tim "<<i+1<<": ";
            for (auto it=timovi[i].begin(); it!=timovi[i].end(); it++)
            {
                if (*it==*timovi[i].rbegin())
                    std::cout<<*it;
                else
                    std::cout<<*it<<", ";
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error e)
    {
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
	return 0;
}