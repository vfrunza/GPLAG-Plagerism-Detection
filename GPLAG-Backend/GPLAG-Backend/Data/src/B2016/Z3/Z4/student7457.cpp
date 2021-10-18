/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int DuzinaImena(std::string s)
{
    int brojac(0);
    for(int i(0); i<s.size(); i++) {
        while(i<s.size() && s[i]==' ') i++;
        while(i<s.size() && s[i]!=' ') {
            brojac++;
            i++;
        }

    }
    return brojac;
}


std::vector<std::set<std::string>>  Razvrstavanje(std::vector<std::string> v, int k)
{
    if(k<1 || k>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i(0); i<v.size(); i++) {
        lista.push_back(v[i]);
    }

    std::vector<std::set<std::string>> z(k);
    int ostatak(0);
    int velicina(v.size()/k);
    ostatak=v.size()%k;
    int br_slova(0);
    int brojac_mjesta_tima(0); //redni broj tima, govori nam da li tim treba da ima velicinu +1 ili ne
    auto it(lista.begin()); //iterator kojim se krecemo kroz listu
    
    for(int i(0); i<k; i++) {
        if(brojac_mjesta_tima<ostatak) {
            while(z[i].size()<velicina+1) {
               for(int e(0); e<br_slova; e++){
                   it++;
                   if(it==lista.end()) it=lista.begin();
               }
                z[i].insert(*it);
                br_slova=DuzinaImena(*it);
                lista.erase(it);
            }
            brojac_mjesta_tima++;
        } else {
            while(z[i].size()<velicina) {
                for(int e(0); e<br_slova; e++){
                    it++;
                   if(it==lista.end()) it=lista.begin();
               }
                z[i].insert(*it);
                br_slova=DuzinaImena(*it);
                lista.erase(it);
            }
        }
    }
    
    return z;

}
int main ()
{
    int n, k;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::vector<std::string> v(n);
    for(int i(0); i<n; i++) {
        std::string temp;
        std::getline(std::cin, temp);
        v[i]=temp;
    }
    std::cout<<"\nUnesite broj timova: ";
    std::cin>>k;
    try {
        std::vector<std::set<std::string>> z(Razvrstavanje(v,k));
        for(int i(0); i<z.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            auto it(z[i].begin());
            for(int j(0); j<z[i].size(); j++){
                if(j+1==z[i].size()) std::cout<<*it<<std::endl;
                else std::cout<<*it++<<", ";
            }

            
        }
    } catch(std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    return 0;
}
