/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
//#include<list>
#include<string>
#include<vector>
#include<set>
#include<cmath>
#include<stdexcept>
#include<memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int Duzina(std::string ime) {
    int n(0);
    for (auto i : ime) {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
            n++;
        }
    }
    return n;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int k){
    std::vector<std::set<std::string>> rez;
    int n=imena.size();
    if(k<1 || k>n) throw std::logic_error("Razvrstavanje nemoguce");
    rez.resize(k);
    //std::list<std::string> krug;
    std::shared_ptr<Dijete> poc(nullptr), prethodni, p;
    for(int i=0;i<imena.size();i++){
       std::shared_ptr<Dijete> novi = std::make_shared<Dijete>();
       novi->ime=imena[i];
       novi->sljedeci=nullptr;
       if(!poc) poc=novi;
       else prethodni->sljedeci=novi;
       prethodni=novi;
    }
    prethodni->sljedeci=poc;

    std::vector<int> brojevi_el;
    for(int i=0; i < k; i++){
        if (i < (n%k)){
             brojevi_el.push_back(int(n/k)+1);
        }
        else {
            brojevi_el.push_back(int(n/k));
        }
    }
    
    int br(0), koliko(0), a(0);
    //std::list<std::string>::iterator pom(krug.begin());
    
    p = poc;
    while (br < n) {
        while (koliko > 0) {
            p=p->sljedeci;
            koliko--;
        }
        koliko = Duzina(p->ime) - 1;
        rez[a].insert(p->ime);
        br++;
        
        if (rez[a].size() == brojevi_el[a]) {
            a++;
        }
        auto pom(p), pom2(p);
        while (pom->sljedeci != p) {
            pom=pom->sljedeci;
        }
        p=p->sljedeci;
        pom->sljedeci=p;
        //delete pom2;
    }
    p->sljedeci=nullptr;
    return rez;
}



int main ()
{
    try{  
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(10000000,'\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        std::vector<std::string> imena;
        for(int i=0;i<n;i++){
            std::string ime;
            std::getline(std::cin, ime);
            imena.push_back(ime);
        }
        std::cout<<"Unesite broj timova: ";
        int k;
        std::cin>>k;
        
        std::vector<std::set<std::string>> timovi_djece;
        timovi_djece=Razvrstavanje(imena, k);
        for(int i=0;i<timovi_djece.size();i++){
            std::cout<<"Tim "<<i+1<<": ";
            for(auto j=timovi_djece[i].begin();j!=timovi_djece[i].end();j++){
                if(j!=--timovi_djece[i].end())
                    std::cout<<*j<<", ";
                else
                    std::cout<<*j;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
	return 0;
}