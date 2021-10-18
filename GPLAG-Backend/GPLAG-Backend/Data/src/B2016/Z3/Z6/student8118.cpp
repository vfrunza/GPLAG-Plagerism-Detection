/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <memory>
struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
int IzbrojiSlova (std::string s) {
    int brojac(0);
    for (int i=0; i<s.size(); i++) {
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        //if ((s[i]>='a' && s[i]<='z') || (s[i]='A' && s[i]<='Z'))
            brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n) {
    int broj, ostatak;
    if (n<1 || n>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    broj=v.size()/n;
    ostatak=v.size()%n;
    std::list<std::string>lista;
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni(nullptr),  p(nullptr);
   std::shared_ptr<Dijete>novi(nullptr);
    for (int i=0; i<v.size(); i++) {
        std::shared_ptr<Dijete>novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if (i==v.size()-1) {
            novi->sljedeci=pocetak;
            p=novi;
        }
        if(!pocetak)
            pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        novi=nullptr;
    }
    auto it(pocetak);
    std::vector<std::set<std::string>> skup(n);
    int brojac(0);
    bool imaostatka(false);
    int preostalo;
    for (int i=0; i<n; i++) {
        std::string temp;
        temp.resize(0);
        if (ostatak>0) imaostatka=true;
        else imaostatka=false;
        if(imaostatka) {
            preostalo=1;
            ostatak--;
        }
        else preostalo=0;
        for (int j=0; j<broj+preostalo; j++) {
            for (int k=0; k<brojac-1; k++) {
                it=it->sljedeci;
                p=p->sljedeci;
            }
            skup[i].insert(it->ime);
            temp=it->ime;
            brojac=IzbrojiSlova(temp);
            if (it==p) {
                temp=p->ime;
                p=nullptr;
                continue;
            }
            p->sljedeci=it->sljedeci;
           // it=nullptr;
            //if (p!=nullptr)
            it=nullptr;
            if (p!=nullptr)
            it=p->sljedeci;
        }
    }
    it->sljedeci=nullptr;
    //p->sljedeci=nullptr;
    return skup;
}
int main ()
{
    int n, brojtimova;
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
            for (int j=0; j<a[i].size()-1; j++){
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