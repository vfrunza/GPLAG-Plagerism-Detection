/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<list>
#include<set>
#include<algorithm>

using namespace std;

struct Dijete
{
    string ime;
    Dijete *sljedeci;
    
}

int duzinaimena(string p)
{
    int brojac(0);
    for(int i=0; i<p.length(); i++) {
        if((p[i]>='a' && p[i]<='z')|| (p[i]>='A' && p[i]<='Z') || (isdigit(p[i]))) brojac++;
    }

    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string> imena ,int k)
{
    std::list<string> lista;
    for(int i=0; i<imena.size(); i++) {
        lista.push_back(imena[i]);
    }
    vector<set<string>> timovi(k);
    int brojtima(0);
    int jedanvise=imena.size()%k;
    int clanovivise=(int)(imena.size()/k)+1;
   int clanovi=(int)(imena.size()/k);
    int ostali=k-jedanvise;
    int izbacivanje=duzinaimena(imena[0]);
    int brojac(1),brisanje(0),prviput(0);
    
    for(;;) {
        auto it=lista.begin();
        if(prviput==0){
            timovi[brojtima].insert(*it);
            izbacivanje=duzinaimena(*it);
               it=lista.erase(it);
               
            brisanje++;
            prviput=1;
        }
        while(it!=lista.end()) {
            if(brojac==izbacivanje) {
                if(brojtima<jedanvise) {
                    if(timovi[brojtima].size()<clanovivise) {
                        timovi[brojtima].insert(*it);


                    } else {
                        brojtima++;
                        timovi[brojtima].insert(*it);
                    }
                } else {
                    if(timovi[brojtima].size()<clanovi) {
                        timovi[brojtima].insert(*it);

                    } else {
                        brojtima++;
                        timovi[brojtima].insert(*it);
                    }
                }
                auto it2=it;
                izbacivanje=duzinaimena(*it2);
                cout<<izbacivanje<<endl;
                it=lista.erase(it);
                brojac=1;
                brisanje++;
            } else
            {
                brojac++;
                it++;
            }   
               
        } 
        if(brisanje==imena.size()) break;
    }
    return timovi;


}
int main ()
{
    int n=10;
    vector<string> v {"Damir","Ana","Muhamed","Marko","Ivan","Mirsad","Nikolina","Alen","Jasmina","Merima"};
    int k=3;
    vector<set<string>> razvrstan=Razvrstavanje(v,k);
    for(int i=0; i<razvrstan.size(); i++) {
        for(auto x:razvrstan[i])
            cout<<x<<" ";

        cout<<endl;
    }
    return 0;
}