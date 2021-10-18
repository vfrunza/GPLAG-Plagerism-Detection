/B2016/2017: Zadaća 3, Zadatak 4
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<list>
#include<set>
#include<algorithm>
#include<cctype>
#include<iterator>

using namespace std;


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
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cin.ignore(1000,'\n');
    vector<string> v(n);
    cout<<"Unesite imena djece: ";
    for(int i=0;i<v.size();i++)
    {
        getline(cin,v[i]);
    }
    cout<<endl;
    cout<<"Unesite broj timova: ";
    int k;
    cin>>k;
  
    vector<set<string>> razvrstan=Razvrstavanje(v,k);
    auto brelvekotra(distance(razvrstan.begin(),razvrstan.end()));
    for(int j=0;j<brelvekotra;j++)
    {
    cout<<"Tim "<<j+1<<": ";
       int brojac(0);
       for(auto it1=razvrstan[j].begin();it1!=razvrstan[j].end();it1++)
       {
          brojac++;
          if(brojac==distance(razvrstan[j].begin(),razvrstan[j].end()))
          cout<<*it1<<" ";
          else
          cout<<*it1<<", ";
       }
       cout<<endl;
   }
   
   return 0;
}
