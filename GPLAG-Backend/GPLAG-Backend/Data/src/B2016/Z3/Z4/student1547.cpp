/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <set>

using std::cout;
using std::cin;

bool DobarZnak(char x){
    return((x>='0' and x<='9') or(x>='A' and x<='Z') or (x>='a' and x<='z'));
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n){
    if(n<1 or n>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> rez(n);
    if(v.size()==0) return rez;
    int k(v.size()/n);
    std::list<std::string> imena;
    for(int i=0; i<v.size(); i++){
        imena.push_back(v[i]);
    }
    int mod(v.size()%n);
    std::vector<int> br_el_skupa(n);
    for(int i=0; i<n; i++){ 
        if(i<mod) br_el_skupa[i]=k+1;
        else br_el_skupa[i]=k;
    }
    int brojac(0), i(0);
    auto it(imena.begin());
    while(i<n){
        rez[i].insert(*it);
        brojac++;
        if(brojac==br_el_skupa[i]){
            i++;
            brojac=0;
            if(i==n) continue;
        }
        int velicina_imena(0);
        for(int j=0; j<(*it).size(); j++){
            if(DobarZnak((*it)[j])) velicina_imena++;
        }
        auto cuva_za_brisanje(it);
        it++;
        if(it==imena.end()) it=imena.begin();
        imena.erase(cuva_za_brisanje);
        for(int j=0; j<velicina_imena-1; j++){
            it++;
            if(it==imena.end()) it=imena.begin();
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