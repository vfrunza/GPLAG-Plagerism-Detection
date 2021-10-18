/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

bool SlovoIliCifra (char znak){
    return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'));
}


std::vector<std::set<std::string>> Razvrstavanje (const std::vector<std::string> &v, int k){
    if(k<1 || k>v.size())
      throw std::logic_error ("Razvrstavanje nemoguce");
      
    int n(v.size());
    std::vector<int> niz(k);
    for(int i=0; i<k; i++){
        if(i<(n%k))
          niz[i] = (n/k) + 1;
        else
          niz[i] = (n/k);
    }
    std::vector<std::set<std::string>> v_skup(k);
    Dijete *pocetak(nullptr), *prethodni;
    for(int i=0; i<v.size(); i++){
        Dijete *novi(new Dijete);
        novi->ime = v[i];
        
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    if(pocetak)
     prethodni->sljedeci = pocetak;
    int br(0);
    int brojac(0);
    while(brojac<k){
        int br_igraca(0);
        while (br_igraca<niz[brojac]) {
            int s = std::count_if(pocetak->ime.begin(), pocetak->ime.end(), SlovoIliCifra );
            v_skup[brojac].insert(pocetak->ime);
            br_igraca++;
            br++;
            auto trenutni(pocetak->sljedeci);
            prethodni->sljedeci = trenutni;
            
            delete pocetak;
           if(br==v.size() ) break;
            pocetak = trenutni;
            int a(1);
            while(a<s){
                pocetak = pocetak->sljedeci;
                prethodni = prethodni->sljedeci;
                a++;
            }
        }
        brojac++;
    }
return v_skup;
}



int main ()

{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    std::vector<std::string> v(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++)
      std::getline(std::cin, v[i]);
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    try{
    auto v_skup(Razvrstavanje(v, k));
    int brojac(1);
    for(auto skup : v_skup){
        std::cout<<"Tim "<<brojac<<": ";
        int b(0);
        for(auto x : skup){
            std::cout<<x;
            if(b!=skup.size() - 1)
               std::cout<<", ";
           b++; 
        }
        std::cout<<std::endl;
        brojac++;
    }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}