/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <memory>

using std::cout;
using std::cin;

bool DobarZnak(char x){
    return ((x>='0' and x<='9') or(x>='A' and x<='Z') or (x>='a' and x<='z'));
}


struct Dijete { 
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n){
    if(n<1 or n>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> rez(n);
    if(v.size()==0) return rez;
    int k(v.size()/n);
    int mod(v.size()%n);
    std::vector<int> br_el_skupa(n);
    for(int i=0; i<n; i++){
        if(i<mod) br_el_skupa[i]=k+1;
        else br_el_skupa[i]=k;
    }
    std::shared_ptr<Dijete> pocetak(nullptr);
    std::shared_ptr<Dijete> prethodni;
    for(int i=0;i<v.size();i++) {
        std::shared_ptr<Dijete> novi=std::make_shared<Dijete>();
        novi->ime = v[i];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci= novi;
        prethodni = novi;
    }
    prethodni->sljedeci=pocetak;
    int brojac(0), i(0);
    auto it(pocetak);
    while(i!=n){
        rez[i].insert(it->ime);
        brojac++;
        if(brojac==br_el_skupa[i]){
            i++;
            brojac=0;
        }
        if(i==n) break;
        int velicina_imena(0);
        for(int j=0; j<(it->ime).size(); j++){
            if(DobarZnak((it->ime)[j])) velicina_imena++;
        }
        it=it->sljedeci;
        prethodni->sljedeci=it;
        if(prethodni->ime==it->ime and prethodni->sljedeci==it->sljedeci){ 
            it->sljedeci=nullptr;
            continue;
        }
        for(int j=0; j<velicina_imena-1; j++){
            it=it->sljedeci;
            prethodni=prethodni->sljedeci;
        }
    }

    return rez;
}

int main ()
{
    int n;
    cout << "Unesite broj djece: ";
    cin >> n;
    cin.ignore(10000, '\n');
    cout <<"Unesite imena djece: \n";
    std::vector<std::string> imena(n);
    for(int i=0; i<n; i++){
        std::getline(cin, imena[i]);
    }
    int x;
    cout << "Unesite broj timova: ";
    cin >> x;
    try{
    std::vector<std::set<std::string>> rez(Razvrstavanje(imena, x));
    for(int i=0; i<x; i++){
        cout << "Tim "<< i+1 << ": ";
        int brojac(0);
        for(auto a: rez[i]){ 
            if(brojac==rez[i].size()-1){
                cout << a;
                break;
            } 
            cout << a << ", ";
            brojac++;
        }    
        cout << std::endl;
    }
    } catch( std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}