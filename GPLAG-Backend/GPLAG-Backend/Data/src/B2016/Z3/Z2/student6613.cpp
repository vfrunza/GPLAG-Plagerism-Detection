/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<set>
#include<string>
#include<stdexcept>
#include<cstring>
using std::set;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
bool JeLiSlovo(char s){
    return ((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9'));
}
bool JeLiVelikoSlovo(char s){
    return(s>='A' && s<='Z');
}
string PretvoriUMala(string s1){
    for(int i=0; i<s1.size(); i++)
        if(JeLiVelikoSlovo(s1[i])) s1[i]=s1[i]+32;
    return s1;
}
map<string,set<int>> KreirajIndeksPojmova(string s){
    map<string,set<int>>mapa{};
    auto s1(PretvoriUMala(s));
    for(int i=0; i<s1.size(); i++){
        int j=i;
        if(JeLiSlovo(s1[i])){
            while(i<s1.size() && JeLiSlovo(s1[i])) i++;
            string rijec=s1.substr(j,i-j);
            mapa[rijec].insert(j);
        }
    }
    return mapa;
}
set<int> PretraziIndeksPojmova(string s, map<string, set<int>>mapa){
    auto s1(PretvoriUMala(s));
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
        if(s1==(it->first)) return mapa[s1];
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(map<string, set<int>>mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        cout<<it->first<<": ";
        for(auto it1=(it->second).begin(); it1!=(it->second).end(); it1++)
            if(it1==((it->second).begin())) cout<<*it1;
            else cout<<","<<*it1;
        cout<<endl;
    }
}
void IspisiSet(set<int>setic){
    for(auto it1=setic.begin(); it1!=setic.end(); it1++)
        cout<<*it1<<" "; 
    cout<<endl;
}
int main ()
{    
    string s;
    cout<<"Unesite tekst: ";
    std::getline(cin, s);
    try{
    map<string, set<int>>mapa;
    IspisiIndeksPojmova(mapa=KreirajIndeksPojmova(s));
    string rijec, tacka(".");
    while(1){
        cout<<"Unesite rijec: ";
        cin>>rijec;
        if(rijec==tacka) return 0;
        if(!(mapa.count(PretvoriUMala(rijec)))) cout<<"Unesena rijec nije nadjena!"<<endl;
        else IspisiSet(mapa[PretvoriUMala(rijec)]);
    }}
    catch(std::logic_error izuzetak){
        cout<<izuzetak.what()<<endl;
    }
	return 0;
}