/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::logic_error;
using std::shared_ptr;
using std::make_shared;

struct Dijete{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

vector<set<string>> Razvrstavanje(vector<string> imena,int broj_timova){
    if(broj_timova<1 || broj_timova>imena.size()){
        throw logic_error("Razvrstavanje nemoguce");
    }
    shared_ptr<Dijete> pocetak(nullptr);
    shared_ptr<Dijete> prethodni;
    try{
        for(int i=0;i<imena.size();i++){
            shared_ptr<Dijete> novi(new Dijete);
            novi->ime=imena[i];
            novi->sljedeci=nullptr;
            if(!pocetak){
                pocetak=novi;
            }
            else{
                prethodni->sljedeci=novi;
            }
            prethodni=novi;
        }
        prethodni->sljedeci=pocetak;
    }
    catch(...){
        throw;
    }
    vector<set<string>> v;
    vector<int> brojac;
    for(int i=0;i<imena.size()%broj_timova;i++){
        brojac.push_back(imena.size()/broj_timova+1);
    }
    for(int i=imena.size()%broj_timova;i<broj_timova;i++){
        brojac.push_back(imena.size()/broj_timova);
    }
    auto it(pocetak);
    int ukupan_broj(imena.size());
    for(int i=0;i<broj_timova;i++){
        set<string> skup;
        for(int j=0;j<brojac[i];j++){
            skup.insert(it->ime);
            int duzina((it->ime).length());
            string s(it->ime);
            for(int l=0;l<s.length();l++){
                if(!((s[l]>='A' && s[l]<='Z') || (s[l]>='a' && s[l]<='z') || (s[l]>='0' && s[l]<='9'))){
                    duzina--;
                }
            }
            if(ukupan_broj>2){
                it=it->sljedeci;
                prethodni->sljedeci=it;
                ukupan_broj--;
                for(int k=0;k<duzina-1;k++){
                    it=it->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
            }
            else if(ukupan_broj==2){
                it=it->sljedeci;
                it->sljedeci=nullptr;
                ukupan_broj--;
            }
            else if(ukupan_broj==1){
                it=nullptr;
                ukupan_broj--;
                break;
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
        vector<set<string>> v;
        try{
            v=Razvrstavanje(imena,broj_timova);
        }
        catch(...){
            throw;
        }
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