/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <set>
#include <string>
#include <vector>
struct Dijete
{
    std::string ime;
    Dijete *veza;
};
std::vector<std::set<std::string>> Razvrstaj(std::vector<std::string> imena,int broj_timova)
{
    std::vector<std::set<std::string>> Vratiti(broj_timova);
    Dijete *pocetak(nullptr),*prethodni,*smece;
    for(auto i=0;i<imena.size();i++)
    {
        Dijete *novi(new Dijete);
        novi->ime=imena[i];
        novi->veza=nullptr;
        if(!pocetak)pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    prethodni->veza=pocetak;
    int j=0,timovi,ostatak,provjera_reda=0,provjera(imena.size());
    timovi=imena.size()/broj_timova;
    ostatak=imena.size()%broj_timova;
    for(auto i=0;i<imena.size();i++)
    {
        int duzina(0),k=0;
        int duzina1=imena[i].length();
        while(pocetak->ime[k]!='\0')
        {
            if((pocetak->ime[k]>='0' && pocetak->ime[k]<='9')||(pocetak->ime[k]>='a' && pocetak->ime[k]<='z')||(pocetak->ime[k]>='A' && pocetak->ime[k]<='Z'))
            {
                duzina++;
            }
            k++;
        }
        Vratiti[j].insert(pocetak->ime);
        provjera--;
        smece=pocetak;
        pocetak=pocetak->veza;
        prethodni->veza=pocetak;
        delete smece;
        while((duzina-1)!=0 && provjera>1)
        {
            prethodni=pocetak;
            pocetak=pocetak->veza;
            duzina--;
        }
        provjera_reda++;
        if(ostatak>0)
        {
            if(provjera_reda==(timovi+1))
            {
                j++;
                provjera_reda=0;
                ostatak--;
            }
        }
        else
        {
            if(provjera_reda==timovi)
            {
                provjera_reda=0;
                j++;
            }
        }
    }
    return Vratiti;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        std::vector<std::string> imena;
        for(auto i=0;i<n;i++)
        {
            std::string ime;
            std::getline(std::cin,ime);
            imena.push_back(ime);
        }
        std::cout<<"Unesite broj timova: ";
        int broj_timova;
        std::cin>>broj_timova;
        auto vraceni(Razvrstaj(imena,broj_timova));
        for(int i=0;i<vraceni.size();i++)
        {
            std::cout<<"Tim "<<i+1<<": ";
            auto granica(vraceni[i].end());
            granica--;
            for(auto j=vraceni[i].begin();j!=vraceni[i].end();j++)
            {
                if(j!=granica)std::cout<<*j<<", ";
                else std::cout<<*j;
            }
            std::cout<<std::endl;
        }
	return 0;
}