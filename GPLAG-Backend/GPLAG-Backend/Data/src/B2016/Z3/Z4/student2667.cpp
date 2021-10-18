/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vektor, int brtimova)
{
    if(brtimova<1 || brtimova>vektor.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vracamo;
    vracamo.resize(brtimova);
    int l=0;
    std::list<std::string> lista;
    for(int i=0; i<vektor.size(); i++)
    {
        lista.push_back(vektor[i]);
    }
    std::vector<int> brojclanova;
    brojclanova.resize(brtimova);
    
    for(int i=0; i<brtimova; i++)
    {
        while(i<vektor.size()%brtimova)
        {
            brojclanova[i]=int(vektor.size()/brtimova)+1;
            i++;
        }
        brojclanova[i]=int(vektor.size()/brtimova);
    }
    int i=0;
    auto x=lista.begin();
    vracamo[l].insert(*x);
    auto a=(*x);
    int brojac=0;
    for(int i=0; i<a.size(); i++)
    {
        if( (a[i]>=48 && a[i]<=57) || ( a[i]>=65 && a[i]<=90 ) || ( a[i]>=97 && a[i]<=122)) brojac++;
        
    }
    x=lista.erase(x);
    int b=0;
    while(lista.size()!=0)
    {
        if(i==0) b++;
        else b=0;
        for(int j=b; j<brojclanova[i]; j++)
        {
            if(lista.size()!=1)
            {
                if(x==lista.end()) x=lista.begin();
                
                for(int k=0; k<brojac-1; k++)
                {
                    x++;
                    if(x==lista.end()) x=lista.begin();
                }
                brojac=0;
                
                vracamo[l].insert(*x);
                
                a=(*x);
                
                for(int i=0; i<a.size(); i++)
                {
                    if((a[i]>=48 && a[i]<=57) || (a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122)) brojac++;
                }
                x=lista.erase(x);
                
            }
            else {
                if(x==lista.end()) x=lista.begin();
                vracamo[l].insert(*x);
                x=lista.erase(x);
                break;
            }
        }
        l++;
        i++;
    }
    return vracamo;
}
int main ()
{
    int broj;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::vector<std::string> vektor;
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<broj; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        vektor.push_back(s);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj;
    std::vector<int> brelemenata;
    brelemenata.resize(broj);
    try{
        auto skupovi= Razvrstavanje(vektor, broj);
        
        for(int i=0; i<skupovi.size(); i++)
        {
            std::cout<<"Tim "<<i+1<<": ";
            for(auto x=skupovi[i].begin(); x!=skupovi[i].end(); x++)
            {
                if(x!=(--skupovi[i].end())) std::cout<< *x<<", ";
                else std::cout<< *x;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error k)
    {
        std::cout<<k.what()<<std::endl;
    }
	return 0;
}