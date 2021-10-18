/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<vector>
#include<string>
#include<set> 
#include<list>
#include<stdexcept>

using std::list;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::set;
using std::endl;
using std::logic_error;
using std::getline;
int Broj(string s){
    int broj=0;
    for (int i=0;i<s.size(); i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
        broj++;
    }
    return broj;
}



vector<set<string>> Razvrstavanje(vector<string>v, int timovi){
    vector<set<string>>novi(timovi);
    list<string> lista;
    int vel=v.size();
    int modul=vel%timovi;
    int prvih=(v.size()/timovi)+1;
    if (modul==0) prvih-=1;
    for(int i=0; i<v.size(); i++) lista.push_back(v[i]);
    list<string>::iterator it(lista.begin());
    int brojac=0;
    while (lista.size()>0){
        for(int k=0; k<timovi; k++){
            for (int i=0; i<prvih; i++) {
                list<string>::iterator temp(it);
                if (temp==lista.end()) temp=lista.begin();
                else temp++;
                std::string dijete(*it);
                int duzina(Broj(dijete));
                novi[k].insert(dijete);
                it=lista.erase(it);
                it=temp;
                for(int j=0; j<duzina; j++){
                    if (it==lista.end()){
                        it=lista.begin();
                    }
                    it++;
                }
                if (it!=lista.begin()) it--;
            }
            brojac++;
            if (brojac==modul) prvih=prvih-1;
        }
        
    }
    return novi;
}
void IspisiVektor(vector<set<string>> v){
    for(int i=0; i<v.size(); i++){
        cout<<"Tim "<<i+1<<": ";
        auto it(v[i].begin());
        auto it2(v[i].end());
        it2--;
        while(it!=it2){
            cout<<*it<<", ";
            it++;
        }
        cout<<*it<<endl;
    }
}


int main (){
    try{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(100000, '\n');
    vector<string> djeca;
    cout<<"Unesite imena djece: "<<endl;
    for(int i=0; i<n; i++){
        string jedno;
        getline(cin, jedno);
        djeca.push_back(jedno);
    }
    int timovi;
    cout<<"Unesite broj timova: ";
    cin>>timovi;
    if(timovi<1||timovi>n) throw std::logic_error ("Razvrstavanje nemoguce");
        vector<set<string>>svi(Razvrstavanje(djeca, timovi));
        IspisiVektor(svi);
    }
    catch(std::logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    
	return 0;
}