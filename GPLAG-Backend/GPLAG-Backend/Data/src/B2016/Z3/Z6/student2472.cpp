/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>

typedef std::vector<std::string> vektor;

using std::cout;
using std::cin;
using std::endl;

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

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
    std::shared_ptr<Dijete> pocetak;
    std::shared_ptr<Dijete> prethodni;

    for(int i=0; i<v.size(); i++){
      std::shared_ptr<Dijete> novi(new Dijete);
      novi->ime = v[i];
      novi->sljedeci = nullptr;
      if(!pocetak)pocetak = novi;
         else prethodni->sljedeci = novi;
      prethodni = novi;
    if(i == v.size()-1) prethodni->sljedeci = pocetak;
    }
   
    int br_znakova(0);
    std::vector<int> brt(Rasporedi(v.size(), bt));
    std::shared_ptr<Dijete> pici = pocetak;
    int br(v.size());
    for(;;){
        if(br == 0) break;
        while(br_znakova > 0){
            br_znakova--;
            prethodni = pici;
            pici = pici->sljedeci;
        }
        for(int i=0; i<bt; i++){
            if(brt[i] > 0){
                timovi[i].insert(pici->ime);
                brt[i]--;
                break;
            }
        }
        br_znakova = IzbrojZnakove(pici->ime) -1;
        prethodni->sljedeci = pici->sljedeci;
        pici = pici->sljedeci;
    if(br-1 == 0) pici->sljedeci = nullptr; //Smanjivanje brojaca pametnog pokazivaca
        br--;
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