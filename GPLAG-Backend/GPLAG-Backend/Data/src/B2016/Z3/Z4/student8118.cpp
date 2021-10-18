/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>
int IzbrojiSlova (std::string s) {
    int brojac(0);
    for (int i=0; i<s.length(); i++) {
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        //if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n) {
    int broj, ostatak;
    if (n<1 || n>v.size())
        throw std::logic_error ("Razvrstavanje nemoguce");
    broj=v.size()/n;
    ostatak=v.size()%n;
    std::list<std::string>lista;
    std::list<std::string>::iterator it(lista.begin());
    for (int i=0; i<v.size(); i++) {
        lista.push_back(v[i]);
    }
    it=lista.begin();
    std::vector<std::set<std::string>>skup(n);
    int brojac(0);
    it=lista.begin();
    bool imaostatka(false);
    int preostalo;
    for (int i=0; i<n; i++) {
        int j(0);
        std::string temp;
        temp.resize(0);
        if (ostatak>0) 
            imaostatka=true;
        else 
            imaostatka=false;
        if (imaostatka) {
            preostalo=1;
            ostatak--;
        }
        else
            preostalo=0;
        for (j=0; j<broj+preostalo;j++) {
            for (int k=0; k<brojac-1; k++) {
                it++;
                if (it==lista.end()) 
                    it=lista.begin();
            }   
            if (it==lista.end()) 
                it=lista.begin();
                temp=*it;
                skup[i].insert(temp);
                brojac=IzbrojiSlova(*it);
                it=lista.erase(it);
                if (it==lista.end()) 
                    it=lista.begin();
            }
        }
       return skup; 
}
int main ()
{
    int n,brojtimova;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::vector<std::string>djeca(n);
    std::cout<<"Unesite imena djece: ";
    std::cin.ignore(10000, '\n');
    for (int i=0; i<n; i++) {
        std::getline(std::cin, djeca[i]);
    }
    std::cout<<"\nUnesite broj timova: ";
    std::cin>>brojtimova;
    try {
        std::vector<std::set<std::string>>a(Razvrstavanje(djeca,brojtimova));
        for (int i=0; i<brojtimova; i++) {
            std::cout<<"Tim "<<i+1<<": ";
            auto imena(a[i].begin());
            for (int j=0; j<a[i].size()-1; j++) {
                std::cout<<*imena<<", ";
                imena++;
            }
            std::cout<<*imena<<std::endl;
        }
    }
    catch(std::logic_error a) {
        std::cout<<"Izuzetak: "<<a.what();
    }
	return 0;
}