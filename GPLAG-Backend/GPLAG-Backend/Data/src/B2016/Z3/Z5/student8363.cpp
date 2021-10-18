/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;
using std::set;
using std::cout;
using std::cin;
using std::endl;
int brojKoraka(string s){
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
        c++;
    }
    return c-1;
} 
struct Dijete{
    string ime;
    Dijete *sljedeci = nullptr;
};
void UnistiListu(Dijete *prvo){
    while (prvo) {
        //cout<<"Brisem "<<prvo->ime<<endl;
        auto tmp = prvo;
        prvo=prvo->sljedeci;
        delete tmp;
    }
}
Dijete *dajSljedeceg(Dijete *poz){
    int c=0;
    int n = brojKoraka(poz->ime);
    auto tmp = poz;
    while (tmp->sljedeci!=poz) {
        tmp=tmp->sljedeci;
        c++;
    }
    if(c){
        tmp->sljedeci = poz->sljedeci;
        delete poz;
        poz = tmp->sljedeci;
        for (int i = 0; i < n; i++) {
            poz = poz->sljedeci;
        }
    }
    return poz;
}
vector<set<string>> Razvrstavanje(vector<string> imena, int b){
    if(b<1 || b>imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *prvo = nullptr;
    Dijete *zadnje = nullptr;
    try{
        for (int i=0; i < imena.size(); i++) {
            if(!i){
                prvo = new Dijete;
                prvo->ime = imena[i];
                zadnje = prvo;
                continue;
            }
            zadnje->sljedeci = new Dijete;
            zadnje->sljedeci->ime = imena[i];
            zadnje = zadnje->sljedeci;
            if(i==imena.size()-1)zadnje->sljedeci = prvo;
        }
    }catch(...){
        UnistiListu(prvo);
        throw;
    }
    auto poz = prvo;
    vector<set<string>> izlaz;
    int prvih = imena.size()%b;
    int clanova = imena.size()/b;
    for (int i = 0; i < b; i++) {
        set<string> tmp;
        for (int j = 0; ((j<clanova ) || (j<clanova+1 && i<prvih)); j++) {
            //cout<<"Ubacujem u "<<i<<". tim "<<poz->ime<<endl;
            tmp.insert(poz->ime);
            poz = dajSljedeceg(poz);
        }
        izlaz.push_back(tmp);
    }
    delete poz;
    return izlaz;
}
int main ()
{
    vector<string> test;
    int n=0;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(1);
    cout<<"Unesite imena djece: \n";
    for (int i = 0; i < n; i++) {
        if(cin.peek()=='\n')cin.ignore(1);
        string s;
        std::getline(cin,s);
        test.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    cin>>n;
    try{
        auto rez = Razvrstavanje(test,n);
        for (int i = 0; i < rez.size(); i++) {
            cout<<"Tim "<<i+1<<": ";
            auto r = rez[i].begin();
            for (int j = 0; j < rez[i].size(); j++) {
                    cout<<*r;
                    if(j!=rez[i].size()-1)cout<<", ";
                    r++;
            }
            cout<<endl;
        }
    }catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}