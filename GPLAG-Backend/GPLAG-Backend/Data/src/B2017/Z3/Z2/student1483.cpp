/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <utility>
#include <set>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <string>
#include <ctype.h>
using namespace std;
typedef map<string,vector<string>> Knjiga;

void PretvoriStringUMalaSlova(string &s){
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
}

map<string,set<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga K){
    map<string,set<tuple<string,int,int>>> mapa;
    int br_poglavlja(0);
    string poglavlje;
    for(pair<string,vector<string>> p: K){
        br_poglavlja++;                                // redni broj poglavlja
        poglavlje=p.first;                               // Ime prvog poglavlja
        for(int i=0;i<p.second.size();i++){
            string str=p.second[i];                  //uzimam jednu po jednu stranicu iz poglavlja
            PretvoriStringUMalaSlova(str);                   //pretvaram string tako da sva slova u stringu budu mala tj. u jednoj stranici
            int br_stranice=i+1;                                        //pamtim koja je stranica iz doredjenog poglavlja
            for(int j=0;j<str.length();j++){                                //prolazim kroz tu stranicu i trazim odgovarjuce rijeci
              string temp;
              int poz_rijeci;
              if((str[j]>='a' && str[j]<='z') || (str[j]>='0' && str[j]<='9')){
                poz_rijeci=j;
                while((str[j]>='a' && str[j]<='z') || (str[j]>='0' && str[j]<='9')){
                    temp.push_back(str[j]);
                    if(j>str.size()-1) break;
                    j++;                                      
                }
             }
             else{
                 continue;                            
             }
             if(mapa.find(temp)==mapa.end()){
             pair<string,set<tuple<string,int,int>>> pom;                      //pomocni par koji ubacujem u krajnju mapu koju vracam iz f-je
                tuple<string,int,int> trojka;
                get<0>(trojka)=poglavlje;
                get<1>(trojka)=br_stranice;
                get<2>(trojka)=poz_rijeci;
                pom.first=temp;
                pom.second.insert(trojka);                      //ubacujem informacije o pronadjenoj rijeci u skup koji je drugi element para koji opisuje rijec
                mapa.insert(pom);
             }  
             else{
                 auto it(mapa.find(temp));
                 tuple<string,int,int> trojka;
                 get<0>(trojka)=poglavlje;
                 get<1>(trojka)=br_stranice;
                 get<2>(trojka)=poz_rijeci;
                 it->second.insert(trojka);
             }
          }
        }
      }
      return mapa;
    }
set<tuple<string,int,int>> PretraziIndeksPojmova(string s, map<string,set<tuple<string,int,int>>> m){
    if(m.find(s)==m.end()) throw logic_error("Unesena rijec nije nadjena!");
    auto it(m.find(s));
    return it->second;
}
    
void IspisiIndeksPojmova(map<string,set<tuple<string,int,int>>> m){
    for(auto it1=m.begin();it1!=m.end();it1++){
        cout<<it1->first<<": ";
        for(auto it2=it1->second.begin(); it2!=it1->second.end(); it2++){
            auto tempit=it1->second.end();
            tempit--;
            cout<<get<0>(*it2)<<"/"<<get<1>(*it2)<<"/"<<get<2>(*it2);
            if(it2!=tempit){
            cout<<", ";
            }
        }
        cout<<endl;
    }
}

 int main (){
   Knjiga k;
    int i(1);
      for(;;){
         pair<string,vector<string>> par;
         cout<<"Unesite naziv poglavlja: ";
         string s1;
         getline(cin,s1);
         if(s1.size()==1 && s1[0]=='.') break;
         par.first=s1;
         for(;;){
         cout<<"Unesite sadrzaj stranice "<<i<<": ";
         string s2;
         getline(cin,s2);
         if(s2.size()==1 && s2[0]=='.'){
         i=1;
         break;
         }
         par.second.push_back(s2);
         i++;
         }
         k.insert(par);
    }
    cout<<endl;
    cout<<"Kreirani indeks pojmova:"<<endl;
    map<string,set<tuple<string,int,int>>> mapa;
    mapa=KreirajIndeksPojmova(k);
    IspisiIndeksPojmova(mapa);
    for(;;){
        cout<<"Unesite rijec: ";
        string s3;
        getline(cin,s3);
        if(s3.size()==1 && s3[0]=='.') break;
        set<tuple<string,int,int>> skup;
        PretvoriStringUMalaSlova(s3);
        try{
        skup=PretraziIndeksPojmova(s3,mapa);
        }
        catch(logic_error izuzetak){
            cout<<izuzetak.what();
        }
        for(auto it=skup.begin(); it!=skup.end(); it++){
            cout<<get<0>(*it)<<"/"<<get<1>(*it)<<"/"<<get<2>(*it)<<" ";
        }
        cout<<endl;
    }
   return 0;
} 
