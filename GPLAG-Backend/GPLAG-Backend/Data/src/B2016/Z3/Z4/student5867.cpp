/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <stdexcept>

int duzina (std::string s)
{
    int razmak(0);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' || s[i] == '-')
            razmak++;
    }
    return razmak;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string>v, int k)
{
    if(k < 1 || k > v.size())
        throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    int visak = v.size() % k;
    //std::cout<<visak<<std::endl;
    std::vector<int>timovi;
    for(int i = 0; i < k; i++)
    {
        if(visak != 0)
        {
            timovi.push_back((int)(v.size()/k)+1);
            visak--;
            continue;
        }
        timovi.push_back(v.size()/k);
    }
    //for(auto x : timovi)
      // std::cout<<x<<" ";
     
    std::list<std::string>lista;
    std::vector<std::set<std::string>>vektor;
    
    std::set<std::string>skup;
    for(int i = 0; i < v.size(); i++)
    {
        lista.push_back(v[i]);
    }
    auto it = lista.begin();
    int brojac(0);
    bool hehe(false);
    int j(0);
    while(17)
    {
        if(timovi[j] > brojac)
        {
            std::string s;
            s = *it;
            //std::cout<<s<<std::endl;
            int vel(s.size());
            int razmak = duzina(s);
            if(razmak != 0)
                vel -= razmak;
            skup.insert(s);
     
            brojac++;  
            it = lista.erase(it);
            
            if(it == lista.end())
                it = lista.begin();
            if(it == lista.end() && --it == lista.end())
            {
                vektor.push_back(skup);
                break;
            }
            //std::cout<<*it<<"*"<<std::endl;
            int suma(0);
            for(auto iti = lista.begin(); iti != lista.end(); iti++)
            {
                suma++;
            }
            //std::cout<<suma<<" ";
            if(suma == timovi[timovi.size() - 1])
            {
                //it--;
                vektor.push_back(skup);
                auto iti(skup.begin());
                for(int i = 0; i < brojac; i++)
                    iti = skup.erase(iti);
                it = lista.begin();
                for(int k = 0; k < suma ; k++)
                {
                    skup.insert(*it);
                    it++;
                }
                vektor.push_back(skup);
                //std::cout<<"bla";
                hehe = true;
            }
            if(!hehe)
            {
            for(int i = 0; i < vel-1; i++)
            {
                if(it != lista.end())
                    it++;
                if(it == lista.end())
                    it = lista.begin();
            }
            }
        }
        if(hehe)
            brojac = timovi[j];
            //std::cout<<j<<"*";
            //std::cout<<brojac<<std::endl;
        if(brojac == timovi[j])
        {
            //std::cout<<hehe;
            /*for(auto x : skup)
            std::cout<<x<<" ";
            std::cout<<std::endl;*/
            if(hehe)
            {
                //vektor.push_back(skup);
                break;
            }
            vektor.push_back(skup);
            j++;
            //std::cout<<"*";
            auto iti(skup.begin());
            for(int i = 0; i < brojac; i++)
            {
                iti = skup.erase(iti);
            }
            brojac = 0;
           // for(auto x : skup)
            //   std::cout<<x<<" ";
           // std::cout<<std::endl;
        }
    }
    return vektor;
}
int main ()
{
	/*std::vector<std::string> v = {"ana marija", "harry james", "50 cent", "lea alma"};
	auto v1 = Razvrstavanje(v, 2);
	std::cout<<"main"<<std::endl;
    for(std::set<std::string> const &skup : v1)
    {
        for(const std::string i : skup)
            std::cout<<i<<" ";
        std::cout<<std::endl;
    }*/
    std::cout<<"Unesite broj djece: ";
    int broj_djece;
    std::cin>>broj_djece;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string>v;
    std::cin.ignore(1000, '\n');
    for(int i = 0; i < broj_djece; i++)
    {
        std::string s;
        std::getline(std::cin, s);
       // std::cin.ignore(10000, '\n');
        v.push_back(s);
    }
    //std::cout<<v.size();
    //for(auto x : v)
      //  std::cout<<x<<" ";
    std::cout<<std::endl<<"Unesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    try
    {
    auto v1 = Razvrstavanje(v, broj_timova);
    int i (1);
    for(std::set<std::string> const &skup : v1)
    {
        std::cout<<"Tim "<<i<<": ";
        int br(0), vel(0);
        for(auto it = skup.begin(); it != skup.end(); it++)
            vel++;
        for(const std::string j : skup)
        {
            if(br == vel-1)
                std::cout<<j;
            else
            //std::cout<<vel<<"*";
            std::cout<<j<<", ";
            br++;
        }
        std::cout<<std::endl;
        i++;
    }
    }
    catch(std::logic_error er1)
    {
        std::cout<<er1.what();
        return 0;
    }
    /*for(int i = 0; i < v1.size(); i++)
    {
        for(auto it = v[i].begin(); it != v[i].end(); it++)
            std::cout<<*it;
            std::cout<<std::endl;
    }*/

	return 0;
}