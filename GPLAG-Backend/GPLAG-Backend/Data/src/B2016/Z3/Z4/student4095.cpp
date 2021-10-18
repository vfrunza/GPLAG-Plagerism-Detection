/B2016/2017: Zadaća 3, Zadatak 4
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

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int k) //k-broj grupa
{
    if(k<1 || k>imena.size())
        throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string>lista_imena;
    for (int i=0; i<imena.size(); i++)
        lista_imena.push_back(imena[i]);
    std::vector<int> br_po_timu(k);
    int n(imena.size());
    for(int i=1; i<=k; i++)
    {
        if(i<=n%k)
            br_po_timu[i-1]=n/k+1;
        else
            br_po_timu[i-1]=n/k;
    }
    std::vector<std::set<std::string>> rezultat(k);
    auto it(lista_imena.begin());
    int duzina(DuzinaImena(*it));
    rezultat[0].insert(*it);
    it=lista_imena.erase(it);
    int i(0), j(1); //vjestacka petlja za unos u vektor
    do{
        for(int i=0; i<duzina-1; i++)
        {
            it++;
            if(it==lista_imena.end())
                it=lista_imena.begin();
        }
        duzina=DuzinaImena(*it);
        //std::cout<<"Brise se: "<<*it<<" "<<duzina<<std::endl;
        if(j>br_po_timu[i]-1)
        {
            i++;
            j=1;
            rezultat[i].insert(*it);
        }
        else {
            rezultat[i].insert(*it);
            j++;
        }
        it=lista_imena.erase(it);
        if (it==lista_imena.end())
            it=lista_imena.begin();
    }while(lista_imena.begin()!=lista_imena.end());
    
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