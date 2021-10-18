#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
typedef map<string, vector<string>> Knjiga;
map<string, set<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga k)
{
    map<string, set<tuple<string,int,int>>> m;
    for(auto it=k.begin(); it!=k.end(); it++) {
        for(int i=0; i<(it->second).size(); i++) {
            tuple<string,int,int> t;
            get<0>(t)=it->first;
            get<1>(t)=i+1;
            int neslovo(1);
            string str;
            for(int j=0; j<(it->second).at(i).length(); j++) {
                if(!((it->second).at(i).at(j)>='A' && (it->second).at(i).at(j)<='Z' || (it->second).at(i).at(j)>='a' && (it->second).at(i).at(j)<='z' || (it->second).at(i).at(j)>='0' && (it->second).at(i).at(j)<='9'))
                    neslovo=1;
                else if(neslovo==1) {
                    neslovo=0;
                    get<2>(t)=j;
                    while(j!=(it->second).at(i).length() && ((it->second).at(i).at(j)>='A' && (it->second).at(i).at(j)<='Z' || (it->second).at(i).at(j)>='a' && (it->second).at(i).at(j)<='z' || (it->second).at(i).at(j)>='0' && (it->second).at(i).at(j)<='9')) {
                        str.push_back((it->second).at(i).at(j));
                        j++;
                    }
                    j--;
                    for_each(str.begin(),str.end(),[](char &s){s=tolower(s);});
                    m[str].insert(t);
                }
                str="";
            }
        }
    }
    return m;
}
set<tuple<string,int,int>> PretraziIndeksPojmova(string str, map<string, set<tuple<string,int,int>>> m){
    set<tuple<string,int,int>> s;
    if(!m.count(str)) throw logic_error("Pojam nije nadjen");
    else s=m[str];
    return s;
}
void IspisiIndeksPojmova(map<string, set<tuple<string,int,int>>> m){
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<": ";
        for(auto iter=(it->second).begin();iter!=(it->second).end();iter++){
            cout<<get<0>(*iter)<<"/"<<get<1>(*iter)<<"/"<<get<2>(*iter);
            int razlika(distance(iter,(it->second).end()));
            if(razlika>1) cout<<", ";
        }
        cout<<endl;
    }
}
int main ()
{
    string poglavlje,pomocna;
    vector<string> v;
    while(1){
    cout<<"Unesite naziv poglavlja: ";
    getline(cin,pomocna);
    if(pomocna!=".") poglavlje=pomocna;
    else break;
    string sadrzaj;
    for(int i=1;;i++){
        cout<<"Unesite sadrzaj stranice "<<i<<": ";
        getline(cin,sadrzaj);
        if(sadrzaj!=".")
        v.push_back(sadrzaj);
        else break;
    }
    }
    cout<<endl<<"Kreirani indeks pojmova:"<<endl;
    Knjiga k{{poglavlje,v}};
    auto m(KreirajIndeksPojmova(k));
    IspisiIndeksPojmova(m);
    while(1){
        try{
        cout<<"Unesite rijec: ";
        string rijec;
        getline(cin,rijec);
        if(rijec!="."){
        set<tuple<string,int,int>> s(PretraziIndeksPojmova(rijec,m));
        for(auto it=s.begin();it!=s.end();it++){
            cout<<get<0>(*it)<<"/"<<get<1>(*it)<<"/"<<get<2>(*it)<<" ";
        }
        cout<<endl;
        }
        else break;
        }catch(logic_error izuzetak){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
    /*map<string, set<tuple<string,int,int>>> m;
    string s {"Nadija"};
    vector<string> v({"abc qwe stsda abc abc dhi qwe hrkw dhi"});
    Knjiga k {{s,v}};
    m=KreirajIndeksPojmova(k);
    auto it=m.begin();
    cout<<it->first<<endl;
    auto iter((it->second).begin());
    cout<<get<0>(*iter)<<endl<<get<1>(*iter)<<endl<<get<2>(*iter);*/
    //IspisiIndeksPojmova(m);
    return 0;
}
