/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <new>
#include <vector>
#include <set>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

int duzina_imena(std::string s){
    int br(0);
    for(int i=0; i<s.length(); i++)
        if((s[i]>47 && s[i]<58) || ( s[i]>64 && s[i]<91) || (s[i]>96 && s[i]<123)) br++;
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje (const std::vector<std::string> &v, int k){
    int n(v.size());
    if(k>n || k<1) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    std::vector<std::set<std::string>> timovi(k);
    try {
        for(int i=0; i<n; i++){
            Dijete *novo(new Dijete);
            novo->ime = v[i];
            novo->sljedeci=nullptr;
            if(!pocetak) pocetak=novo;
            else prethodni->sljedeci=novo;
            prethodni=novo;
        }
        if (prethodni) prethodni->sljedeci=pocetak;
        Dijete *p=pocetak;
        
        for(int i=0; i<k; i++){
            int tim_i(0);
            if(i<n%k) tim_i=n/k + 1;
            else tim_i=n/k;
            for(int j=0; j<tim_i; j++){
                timovi[i].insert(p->ime);
                int brslova(duzina_imena(p->ime));
                if(prethodni->sljedeci==pocetak) pocetak=pocetak->sljedeci;
                if(prethodni->sljedeci==prethodni){ delete prethodni->sljedeci; prethodni=nullptr; p=nullptr; pocetak=nullptr; break;}
                p=p->sljedeci;
                delete prethodni->sljedeci;
                prethodni->sljedeci=p;
                for(int l=1; l<brslova; l++) {
                    p=p->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
            }
        }
    }
    catch (std::bad_alloc) {
        if(pocetak){
            Dijete *p=pocetak;
            while (p->sljedeci != pocetak){
                prethodni=p->sljedeci;
                delete p;
                p=prethodni;
            }
            delete p;
        }
        throw;
    }
    return timovi;
    
}


int main ()
{
    try{
        int djece, timova;
        std::cout << "Unesite broj djece: " ;
        std::cin>>djece;
        std::cout << "Unesite imena djece: " << std::endl;
        std::vector<std::string> imena;
        imena.resize(djece);
        for(int i=0; i<imena.size(); i++){ std::getline(std::cin>>std::ws, imena[i]);  }
        std::cout << "Unesite broj timova: " ;
        std::cin>>timova;
        auto rez(Razvrstavanje(imena, timova));
        for(int i=0; i<rez.size(); i++) {
            std::cout << "Tim "<<i+1<<": " ;
            auto skup_it(rez[i].begin());
            for(int k=0; k<rez[i].size(); k++){
                std::cout << *skup_it;
                if(k!=rez[i].size()-1) std::cout<<", ";
                skup_it++;
            }
            std::cout << std::endl;
        }
    }
    catch (std::bad_alloc){
        std::cout << "Nema memorije" << std::endl;
    }
    catch(std::logic_error i){
        std::cout << i.what() << std::endl;
    }
	return 0;
}