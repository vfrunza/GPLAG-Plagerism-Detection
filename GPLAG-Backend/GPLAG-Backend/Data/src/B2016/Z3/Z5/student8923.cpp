/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <new>
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::set;
struct Dijete
{
    string ime;
    Dijete *sljedeci;
};
int Prebroji(string ime)
{
    int brojac(0);
    
    for(int i=0;i<ime.size();i++)
    {
        if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9'))
        brojac++;
    }
    return brojac;
}
vector<set<string>> Razvrstavanje(vector<string> imena,int broj)
{
    vector<set<string>> ekipe;
    if(broj<1 || broj>imena.size())
    throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    try
    {
    int n=imena.size()/broj;
    int m=imena.size()%broj;
    set<string> skup;
    
        for(int i=0;i<imena.size();i++)
        {
            Dijete *novi(new Dijete);
            novi->ime=imena[i];
            novi->sljedeci=nullptr;
            if(!pocetak)
            {
                pocetak=novi;
            }
            else
            prethodni->sljedeci=novi;
            prethodni=novi;
        }
        prethodni->sljedeci=pocetak;
      Dijete *zadnji=prethodni;
  //    zadnji->sljedeci=pocetak;
      int pom(0);
        for(int i=0;i<imena.size();i++)
        {
           if(i==0)
           {
               skup.insert(pocetak->ime);
               Dijete *prosli(pocetak);
               pom=Prebroji(pocetak->ime);
               prosli->sljedeci=pocetak->sljedeci;
             zadnji->sljedeci=pocetak->sljedeci;
             Dijete *pocetak1(pocetak);
             pocetak=pocetak->sljedeci;
              delete pocetak1;
              
           }
           else
           {
               Dijete *prosli(pocetak);
               while(pom>1)
               {
                   prosli=pocetak;
                   pocetak=pocetak->sljedeci;
                   pom--;
               }
               skup.insert(pocetak->ime);
                pom=Prebroji(pocetak->ime);
               prosli->sljedeci=pocetak->sljedeci;
               if(pocetak==zadnji->sljedeci)
              zadnji->sljedeci=pocetak->sljedeci;
              Dijete *pocetak1(pocetak);
              pocetak=pocetak->sljedeci;
              if(pocetak1!=zadnji)
              delete pocetak1;
           }
          if((ekipe.size()<m && skup.size()==n+1) || (ekipe.size()>=m && skup.size()==n))
          {
          ekipe.push_back(skup);
          set<string> skup1;
          skup=skup1;
          }
        }
        if(imena.size()!=1)
        delete zadnji;
        return ekipe; 
   }
    catch(...)
    {
        Dijete *p;
        while(pocetak!=nullptr)
        {
            p=pocetak;
            pocetak=pocetak->sljedeci;
            delete p;
        }
        throw;
    }
    return ekipe;
}
int main ()
{
    cout<<"Unesite broj djece: ";
    int br;
    cin>>br;
    cout<<"Unesite imena djece: "<<std::endl;
    vector<string> imena;
    cin.ignore(10000,'\n');
    for(int i=0;i<br;i++)
    {
        string pom;
        std::getline(cin,pom);
        imena.push_back(pom);
    }
    cout<<"Unesite broj timova: ";
    int broj;
    cin>>broj;
    vector<set<string>> timovi;
    try
    {
        timovi=Razvrstavanje(imena,broj);
        int i(0);
            for(auto pom1: timovi)
            {
            i++;
            int brojac(0);
            cout<<"Tim "<<i<<": ";
            for(auto pom2: pom1)
            {
               if(brojac!=timovi[i-1].size()-1)
                cout<<pom2<<", ";
               else
              cout<<pom2;
              brojac++;
            }
            cout<<std::endl;
            }
    }
    catch(std::logic_error izuzetak)
    {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
	return 0;
}