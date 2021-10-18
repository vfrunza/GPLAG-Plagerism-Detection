/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<utility>
#include<list>
using std::list;
using std::vector;
using std::set;
using std::string;
using std::cout;
using std::cin;

vector<int> NapraviTim(vector<string> &v,int k){
    int mod(v.size()%k),broj(0);
    broj=v.size()/k;
    vector<int> vect;
    for(int i(0);i<k;i++)
    vect.push_back(broj);
    for(int i(0);i<mod;i++)
    vect[i]=vect[i]+1;
    return vect;
}

vector<set<string>> Razvrstavanje(vector<string> &v,int k){
    vector<set<string>> skupovi;
    vector<int> igraci;
    igraci=NapraviTim(v,k);
    list<string> lista;
    for(int i(0);i<v.size();i++)
    lista.push_back(v[i]);
    list<string>::iterator it1,it2;
    int brojac(0),br(0),f(0),n(0);
    it2=lista.begin();
    f=(*it2).length();
    for(int i(0);i<k;i++){
        n=igraci[i];
        set<string> skup;
        while(br<n){
            f=(*it2).length();
            it1=it2;
            it1++;
            if(it1==lista.end()){
                skup.insert(*it2);
                it2=lista.erase(it2);
                it2=lista.begin();
            }
            else{
            skup.insert(*it2);
            it2=lista.erase(it2);
            }
            while(brojac<f-1){
                it2++;
                if(it2==lista.end()) it2=lista.begin();
                brojac++;
            }
            brojac=0;
            br++;
    }
    br=0;
    skupovi.push_back(skup);
    //for(auto x:skup) cout<<x<<" ";
    //cout<<"\n";
    }
    return skupovi;
}

int main ()
{
    int k(0),n(0);
    vector<string> v;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(10000, '\n');
    cout<<"Unesite imena djece: \n";
    for(int i(0);i<n;i++){
        string ime;
        getline(cin,ime);
        v.push_back(ime);
    }
    cout<<"Unesite broj timova: ";
    try{
        cin>>k;
        if(k<1 || k>n) throw std::logic_error("Razvrstavanje nemoguce");
    }
    catch(std::logic_error poruka){
        cout<<"Izuzetak: "<<poruka.what();
        return 0;
    }
    vector<set<string>> skupovi;
    set<string>::iterator it1,it2,it3;
    skupovi=Razvrstavanje(v,k);
    for(int x(0);x<skupovi.size();x++){
        cout<<"Tim "<<x+1<<": ";
        it2=skupovi[x].end();
        it3=it2;
        it3--;
        for(it1=skupovi[x].begin();it1!=it2;it1++){
            if(it3==it1){
                cout<<*it1;
                break;
            }
            else cout<<*it1<<", ";
        }
        cout<<"\n";
        
    }
    
	return 0;
}