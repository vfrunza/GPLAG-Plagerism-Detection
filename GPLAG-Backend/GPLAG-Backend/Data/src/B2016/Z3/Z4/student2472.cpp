/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<std::string> vektor;
typedef std::list<std::string> lista;

int IzbrojZnakove(std::string s){
    int br(0);
    for(int i=0; i<s.length(); i++)
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            br++;
    return br;
}

std::vector<int> Rasporedi(int brojdjece, int bt){
    int br(brojdjece/bt);
    int ostatak(brojdjece%bt);
    std::vector<int> v(bt);
    for(int i=0; i<bt; i++){
        v[i] = br;
        if(ostatak > 0) v[i]++;
        ostatak--;
    }
    return v;
}

std::vector<std::set<std::string>> Razvrstavanje(vektor v, int bt){
    if(bt < 1 || bt > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi(bt);
    lista lis;
    for(int i=0; i<v.size(); i++)
        lis.push_back(v[i]);
    int br_znakova(0);
    std::vector<int> brt(Rasporedi(v.size(), bt));
    auto it=lis.begin();
    while(lis.size() > 0){
        if(it == lis.end()) it = lis.begin();
        while(br_znakova > 0){
            br_znakova--;
            it++;
            if(it == lis.end()) it = lis.begin();
            
        }
        for(int i=0; i<bt; i++){
            if(brt[i] > 0){
                timovi[i].insert(*it);
                brt[i]--;
                break;
            }
        }
        br_znakova = IzbrojZnakove(*it) -1;
        auto it2(it);
        it++;
        lis.remove(*it2);
        if(lis.size() == 0) break;
    }
    return timovi;
}

int main ()
{
   int brd, bt;
   cout << "Unesite broj djece: ";
   cin >> brd;
   vektor v(brd);
   cout << "Unesite imena djece: ";
   cin.ignore(1000, '\n');
   for(int i=0; i<brd; i++)
        getline(cin, v[i]);
    cout << endl << "Unesite broj timova: ";
    cin >> bt;
    try{
    std::vector<std::set<std::string>> vek(Razvrstavanje(v, bt));
    for(int i=0; i<bt; i++){
        cout << "Tim " << i+1 << ": ";
        for(auto it=vek[i].begin(); it!=vek[i].end(); it++){
            auto it2(it);
            it2++;
           if(it2 != vek[i].end()) cout << *it << ", ";
           else cout << *it;
        }
        cout << endl;
    }
    }catch(std::logic_error cigla){
        cout << "Izuzetak: " << cigla.what();
    }
	return 0;
}