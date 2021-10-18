/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <string>
#include <set>
#include <cstring>
#include <map>

using namespace std;

typedef std::map<std::string, std::vector<std:: string>> Knjiga;
typedef map<string,vector<tuple<string,int,int>>> indeks;
typedef vector<tuple<string,int,int>> dio;

int broj(char a)
{
     return (toupper(a)>='0'&&toupper(a)<='9');
}

int slovo(char a)
{
     return (toupper(a)>='A' && toupper(a)<='Z');
}

vector<string> sep(string s)
{
     vector<string>v;
     for(int i=0; i<s.size(); i++) {
          string s1;
          while(slovo(s[i]) || broj(s[i]))
          {
               s1.push_back(s[i]); i++;
          }
          if(s1.size()!=0) v.push_back(s1);
     }
     return v;
}

bool izolirano(string a, string s)
{
     if(s.size()==1) return true;
     for(int i=0; i<s.size()-a.size(); i++)
     {
          if(s.substr(i,a.size())==a)
          {
               if(i==0) {
                    if(slovo(s[i+a.size()])|| broj(s[i+a.size()])) return false;
                    else return true;
               }
               else{
                    if(slovo(s[i-1])|| broj(s[i-1] || slovo(s[i+a.size()])|| broj(s[i+a.size()]))) return false;
                    return true;
               }
          }
     }
     return true;
}

indeks KreirajIndeksPojmova(Knjiga k)
{
     indeks rez;
     for(auto it=k.begin(); it!=k.end(); it++){
          for(int i=0; i<it->second.size(); i++)
               for(int j=0; j<it->second.at(i).size(); j++) it->second.at(i).at(j)=tolower(it->second.at(i).at(j));
     }
     vector<string> rijeci;
     for(auto it=k.begin(); it!=k.end(); it++){
          for(int i=0; i<it->second.size(); i++){
               vector<string> pom=sep(it->second.at(i));
               for(int i=0; i<pom.size(); i++)
               {
                    bool ima=false;
                    for(int j=0; j<rijeci.size(); j++) if(rijeci[j]==pom[i]) ima=true;
                    if(!ima) rijeci.push_back(pom[i]);
               }
          }
     }
     for(int l=0; l<rijeci.size(); l++)
     {
          dio skup;
          for(auto it=k.begin(); it!=k.end(); it++)
            for(int i=0; i<(it->second).size(); i++)
                for(int j=0; j<(it->second).at(i).size(); j++)
                    if(rijeci[l]==(it->second).at(i).substr(j,rijeci[l].size()) && izolirano(rijeci[l],it->second.at(i))) skup.push_back(make_tuple(it->first,i+1,j));
          rez[rijeci[l]]=skup;
     }
     return rez;
}

vector<tuple<string,int,int>> PretraziIndeksPojmova(string s, indeks m)
{
     auto it = m.find(s);
     if (it != m.end()) return m[s];
     throw logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(indeks m)
{
     for(auto it=m.begin(); it!=m.end(); it++)
     {
          cout<<it->first<<": ";
          for(int i=0; i<it->second.size(); i++)
          {
               auto pom=it->second.at(i);
               cout<<get<0>(pom)<<"/"<<get<1>(pom)<<"/"<<get<2>(pom);
               if(i==(it->second.size())-1) cout<<endl;
               else cout<<", ";
          }
          
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
     indeks ind=KreirajIndeksPojmova(k);
     cout<<endl<<"Kreirani indeks pojmova: "<<endl;
     IspisiIndeksPojmova(ind);
     while(1)
     {
          cout<<"Unesite rijec: ";
          string pom; getline(cin,pom);
          if(pom==".") break;
          try{
          dio d=PretraziIndeksPojmova(pom,ind);
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
