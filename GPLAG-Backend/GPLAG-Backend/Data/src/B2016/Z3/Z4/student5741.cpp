/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::list;
using std::logic_error;

vector<set<string>> Razvrstavanje(vector<string> imena,int broj_timova){
    if(broj_timova<1 || broj_timova>imena.size()){
        throw logic_error("Razvrstavanje nemoguce");
    }
    list<string> lista(imena.size());
    auto it(lista.begin());
    for(int i=0;i<imena.size();i++){
        *it=imena[i];
        it++;
    }
    vector<set<string>> v;
    vector<int> brojac;
    for(int i=0;i<imena.size()%broj_timova;i++){
        brojac.push_back(imena.size()/broj_timova+1);
    }
    for(int i=imena.size()%broj_timova;i<broj_timova;i++){
        brojac.push_back(imena.size()/broj_timova);
    }
    it=lista.begin();
    for(int i=0;i<broj_timova;i++){
        set<string> skup;
        if(it==lista.end()){
            it=lista.begin();
        }
        for(int j=0;j<brojac[i];j++){
            if(it==lista.end()){
                it=lista.begin();
            }
            skup.insert(*it);
            int duzina((*it).length());
            string s(*it);
            for(int l=0;l<s.length();l++){
                if(!((s[l]>='A' && s[l]<='Z') || (s[l]>='a' && s[l]<='z') || (s[l]>='0' && s[l]<='9'))){
                    duzina--;
                }
            }
            it=lista.erase(it);
            if(it==lista.end()){
                it=lista.begin();
            }
            for(int k=0;k<duzina-1;k++){
                it++;
                if(it==lista.end()){
                    it=lista.begin();
                }
            }
        }
        v.push_back(skup);
    }
    return v;
}

int main ()
{
    try{
        int n;
        cout<<"Unesite broj djece: ";
        cin>>n;
        vector<string> imena;
        std::cin.ignore(1000,'\n');
        cout<<"Unesite imena djece: "<<endl;
        for(int i=0;i<n;i++){
            string s;
            std::getline(cin,s);
            imena.push_back(s);
        }
        int broj_timova;
        cout<<"Unesite broj timova: ";
        cin>>broj_timova;
        auto v(Razvrstavanje(imena,broj_timova));
        for(int i=0;i<v.size();i++){
            cout<<"Tim "<<i+1<<": ";
            auto it(v[i].begin());
            auto it1(v[i].end());
            it1--;
            while(it!=v[i].end()){
                if(it!=it1){
                    cout<<*it<<", ";
                }
                else if(it==it1){
                    cout<<*it;
                }
                it++;
            }
            cout<<endl;
        }
    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}