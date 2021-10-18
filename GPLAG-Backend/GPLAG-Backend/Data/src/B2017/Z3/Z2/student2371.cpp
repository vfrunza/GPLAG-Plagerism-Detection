/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#include<stdexcept>
#include<tuple>

using namespace std;

typedef map<string,vector<string>> Knjiga;

int Slovo(char a){
    a=toupper(a);
    if(a>='A' && a<='Z') return 1;
    return 0;
}
int Broj(char a){
    if(a>='0' && a<='9') return 1;
    return 0;
}

bool SlovoiBroj(char a) {
    int s=Slovo(a);
    int b=Slovo(b);
    return (s==1 || b==1);
}

vector<string>izdvoji (string s){
    vector<string> rez;
    for(int i=0;i<s.size();i++){
        string pom;
        while(SlovoiBroj(s[i])) {pom.push_back(s[i]); i++;}
        if(pom.size()!=0) rez.push_back(pom);
    }
    return rez;
}

map<string,vector<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga k) {
    map<string,vector<tuple<string,int,int>>> rez;
    
    for(auto it=k.begin(); it!=k.end();it++)
        for(int i=0;i<(it->second).size();i++)
            for(int j=0;j<(it->second).at(i).size();j++)
            (it->second).at(i).at(j)=tolower((it->second).at(i).at(j));
            
    vector<string>rijeci;
    for(auto it=k.begin();it!=k.end();it++)
        for(auto i=0;i<(it->second).size();i++){
            vector<string>pom=izdvoji((it->second).at(i));
            for(int i=0;i<pom.size();i++){
                bool ima=false;
                for(int j=0;j<rijeci.size();j++)
                    if(rijeci[j]==pom[i]) ima=true;
                    if(!ima) rijeci.push_back(pom[i]);
            }
        }


for(int l=0;l<rijeci.size();l++){
    vector<tuple<string,int,int>>skup;
    for(auto it=k.begin();it!=k.end();it++)
        for(int i=0;i<(it->second).size();i++)
            for(int j=0;j<(it->second).at(i).size();j++)
            if(rijeci[l]==(it->second).at(i).substr(j,rijeci[l].size())){
                tuple<string,int,int>pom(it->first,i+1,j);
                skup.push_back(pom);
            }
            rez[rijeci[l]]=skup;
    }
return rez;
}
 vector<tuple<string,int,int>> PretraziIndeksPojmova(string s,map<string,vector<tuple<string,int,int>>>m)
 {
              if(m[s].size()==0)
                throw logic_error("Unesena rijec nije nadjena!");
     
        return m[s];
 }
 
 void IspisiIndeksPojmova(map<string,vector<tuple<string,int,int>>>m)
 {
     for(auto it=m.begin();it!=m.end();it++)
     {
         cout<<it->first<<": ";
        for(int i=0;i<(it->second).size();i++)
        {
            tuple<string,int,int>pom=(it->second).at(i);
            cout<<get<0>(pom)<<"/"<<get<1>(pom)<<"/"<<get<2>(pom);
            if(i==(it->second).size()-1)cout<<endl;
            else cout<<", ";
        }
       // cout<<endl;
         }
}





int main ()
{
    Knjiga k;
     while(1)
     {
          cout<<"Unesite naziv poglavlja: ";
          string s; getline(cin,s);
          if(s==".") break;
          vector<string> v;
          int br=1;
          while(1)
          {
               cout<<"Unesite sadrzaj stranice "<<br++<<": ";
               string pom;
               getline(cin,pom);
               if(pom==".") break;
               else v.push_back(pom);
          }
          k[s]=v;
     }
     map<string,vector<tuple<string,int,int>>> ind=KreirajIndeksPojmova(k);
     cout<<endl<<"Kreirani indeks pojmova:"<<endl;
     IspisiIndeksPojmova(ind);
     while(1)
     {
          cout<<"Unesite rijec: ";
          string pom; getline(cin,pom);
          if(pom==".") break;
          try{
          vector<tuple<string,int,int>>d=PretraziIndeksPojmova(pom,ind);
          for(int i=0; i<d.size(); i++)
               {
                    auto pom=d.at(i);
                    cout<<get<0>(pom)<<"/"<<get<1>(pom)<<"/"<<get<2>(pom)<<" ";
                    if(i==(d.size())-1) cout<<endl;
               }
          }catch(logic_error iz) {cout<<iz.what()<<endl; }
     }
	return 0;
}
