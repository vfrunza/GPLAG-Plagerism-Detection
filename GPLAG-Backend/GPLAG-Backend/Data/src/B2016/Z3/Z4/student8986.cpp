/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <stdexcept>

typedef std::vector<std::set<std::string>> VektorSkupovaStringova;

int Prebroji(std::string s) {
    int brojac(0);
    for(int i=0; i<s.length(); i++) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            brojac++;
    }
    
    return brojac;
}

VektorSkupovaStringova Razvrstavanje(std::vector<std::string> v, int br_timova) {
    if(br_timova<1 || br_timova>v.size())
        throw std::logic_error ("Razvrstavanje nemoguce");
    
    VektorSkupovaStringova timovi(br_timova);
    int br_djece(v.size());
    
    std::list<std::string> djeca;
    for(int i=0; i<v.size(); i++)
        djeca.push_back(v[i]);
        
    auto it(djeca.begin()); //iterator koji se krece kroz listu sa imenima djece
    
    for(int i=0; i<br_timova; i++) {
        int vel_tima;
        if(i+1<=br_djece%br_timova) vel_tima=(br_djece/br_timova)+1;
        else vel_tima=br_djece/br_timova;
        
        std::set<std::string> tim;
        
        for(int j=0; j<vel_tima; j++) {
            tim.insert(*it);
            int br(Prebroji(*it));
            it=djeca.erase(it);
            it--;
            if(djeca.size()==0) break;
            for(int k=0; k<br; k++) {
                it++;
                if(it==djeca.end()) it=djeca.begin();
            }
        }
        timovi[i]=tim;
    }
    return timovi;
}

int main ()
{

    std::vector<std::string> djeca;
    int n;
    
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::cout<<"Unesite imena djece:"<<std::endl;
    for(int i=0; i<n; i++) {
        std::string ime;
        std::getline(std::cin, ime);
        djeca.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int br_timova;
    std::cin>>br_timova;
    try {
        VektorSkupovaStringova timovi(Razvrstavanje(djeca, br_timova));
        for(int i=0; i<timovi.size(); i++) {
            std::set<std::string> tim(timovi[i]);
            auto it(tim.begin());
            std::cout<<"Tim "<<i+1<<": ";
            while(it!=tim.end()) {
                if((++it)--==tim.end())
                    std::cout<<*it;
                else
                    std::cout<<*it<<", ";
                it++;
            }
            std::cout<<std::endl;
        }
    }
    
    catch(std::logic_error greska) {
        std::cout<<"Izuzetak: "<<greska.what();
    }
    
    
	return 0;
}