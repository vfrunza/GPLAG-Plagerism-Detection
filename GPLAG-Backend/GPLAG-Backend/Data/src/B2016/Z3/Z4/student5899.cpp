/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <iterator>
#include <algorithm>


std::vector<int> Timovi(int brojdjece,int brojtimova)
{
    std::vector<int> timovi;
    int t;
    if(brojtimova<1 || brojtimova>brojdjece) throw std::logic_error("Razvrstavanje nemoguce");
    while(brojtimova!=0)
    {
        if((brojdjece%brojtimova)!=0)
        {
            t=(double(brojdjece)/brojtimova)+1;
            timovi.push_back(t);
            brojdjece-=t;
            brojtimova--;
        }
        else if((brojdjece%brojtimova)==0)
        {
            t=(double(brojdjece)/brojtimova);
            timovi.push_back(t);
            brojdjece-=t;
            brojtimova--;
        }
    }
    return timovi;
}

bool slovo(char s)
{
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s>='0' && s<='9'))
		return true;
	return false;
}

int BrojSlova(std::string s)
{
    int brojac(0);
    for(int i=0;i<s.length();i++)
    {
        if(!slovo(s[i]) || s[i]==' ') continue;
        
        brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int n)
{
    std::list<std::string> lista;
    std::list<std::string>::iterator pomoc;
    std::set<std::string> skup;
    std::vector<std::set<std::string>> novo;
    int broj(0);
    int counter(0);
    int brojac(0);
    auto timovi(Timovi(v.size(),n));
    
    //vektor u listu
    for(int i=0;i<v.size();i++)
        lista.push_back(v[i]);
    
    int s(0);
    
    //prolazimo kroz listu
    
    for(auto it=lista.begin();it!=lista.end();it++)
    {
        if((broj-counter)==1) counter=broj; //jer se u for vec it pomjeri
        if(counter!=broj) //ako smo dosli do kraja liste ali pomjeranje nije zavrseno
        {
            
            for(;;)
            {
                counter++;
                if(counter==broj) break;
                if(it!=lista.end()) it++;
                if(it==lista.end()) it=lista.begin();
            }
        }
        counter=0; //vracamo counter na 0 za sljedece pomjeranje
        brojac++; //koliko puta smo ubacili elemente u skup
        skup.insert(*it);
        broj=BrojSlova(*it)-1; //jer kad uradimo it=lista.erase(it) it prebacuje na sljedeci a nama treba od onog sto je izbrisan
        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
        if(brojac==timovi[s]){ novo.push_back(skup); skup.clear(); s++; brojac=0;}
        //ako je brojac jednak broju djece u tom timu to je nas skup
        for(;;)
        {
            counter++;
            it++;
            if(it==lista.end()) it=lista.begin();
            if(counter==broj) break;
        }
        counter=0;
        if(it==lista.end()) it=lista.begin();
        skup.insert(*it);
        broj=BrojSlova(*it)-1;
        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
        brojac++;
        if(brojac==timovi[s]){ novo.push_back(skup); skup.clear(); s++; brojac=0;}
        for(auto i=it;i!=lista.end();i++)
        {
            counter++;
            it++;
            if(counter==broj)
            {
                if(it==lista.end()) it=lista.begin();
                brojac++;
                skup.insert(*it);
                broj=BrojSlova(*it)-1;
                it=lista.erase(it);
                if(it==lista.end())it=lista.begin();
                if(brojac==timovi[s]) {novo.push_back(skup); skup.clear(); s++; brojac=0;}
                counter=0;
            }
            if(it==lista.end())
            {
                it=lista.begin();
                break;
            }
        }
        if(std::distance(lista.begin(),lista.end())==0) break;
        if(std::distance(lista.begin(),lista.end())==1)
        {
            skup.insert(*it);
            novo.push_back(skup);
            break;
        }
    }
    return novo;
}
int main()
{
   try
    {
    int broj_d;
    std::cout << "Unesite broj djece: ";
    std::cin>>broj_d;
    std::vector<std::string> v(broj_d);
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece:"<<std::endl;
    for(int i=0;i<v.size();i++)
    {
        std::getline(std::cin,v[i]);
    }
    std::cout << "Unesite broj timova: ";
    int broj_t;
    std::cin>>broj_t;
    //std::vector<std::string> v{"Marija","Dario","Noa","Zara","Armin","Kenan","Melisa","Adna","Merima","Leon","Ines","Tajra","Dzan","Adin"};
    auto k(Razvrstavanje(v,broj_t));
    
     int s(std::distance(k.begin(),k.end()));
    for(int j=0;j<s;j++)
    {
        int brojac(0);
        std::cout<<"Tim "<<j+1<<": ";
        for(auto it=k[j].begin();it!=k[j].end();it++)
        {
            brojac++;
            if(brojac==std::distance(k[j].begin(),k[j].end())) std::cout<<*it;
            else
            std::cout<<*it<<", ";
        }
        std::cout<<std::endl;
    }
    return 0;
    }
    catch(std::logic_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
    
}