
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
typedef map<string,vector<tuple<string,int,int>>> Ind;
typedef vector<tuple<string,int,int>> Strana;

int val1(char slovo)
{
     return (toupper(slovo)>='A' && toupper(slovo)<='Z');
}

void IspisiIndeksPojmova(Ind mapa)
{
     for(auto it=mapa.begin(); it!=mapa.end(); it++)
     {
          cout<<it->first<<": ";
          for(int i=0; i<it->second.size(); i++)
          {
               auto temp=it->second.at(i);
               cout<<get<0>(temp)<<"/"<<get<1>(temp)<<"/"<<get<2>(temp);
               if(i==(it->second.size())-1) cout<<endl;
               else cout<<", ";
          }
          
     }
}

int val2(char slovo)
{
     return ((slovo)>='0'&&(slovo)<='9');
}



vector<string> sep(string s)
{
     vector<string>v;
     for(int i=0; i<s.size(); i++) {
          string s1;
          while(val1(s[i]) || val2(s[i]))
          {
               s1.push_back(s[i]); i++;
          }
          if(s1.size()!=0) v.push_back(s1);
     }
     return v;
}

Knjiga smanjislova(Knjiga k){
    for(auto it=k.begin(); it!=k.end(); it++)
          for(int i=0; i<it->second.size(); i++)
               for(int j=0; j<it->second.at(i).size(); j++) it->second.at(i).at(j)=tolower(it->second.at(i).at(j));
    return k;
}

bool dobar(string slovo, string s)
{
     if(s.size()==1) return true;
     for(int i=0; i<s.size()-slovo.size(); i++)
     {
          if(s.substr(i,slovo.size())==slovo)
          {
               if(i==0) {
                    if(val1(s[i+slovo.size()])|| val2(s[i+slovo.size()])) return false;
                    else return true;
               }
               else{
                    if(val1(s[i-1])|| val2(s[i-1] || val1(s[i+slovo.size()])|| val2(s[i+slovo.size()]))) return false;
                    return true;
               }
          }
     }
     return true;
}

void filter(Knjiga &k, vector<string> r, Ind &rez){
    for(int l=0; l<r.size(); l++)
     {
          Strana skup;
          for(auto it=k.begin(); it!=k.end(); it++)
            for(int i=0; i<(it->second).size(); i++)
                for(int j=0; j<(it->second).at(i).size(); j++)
                    if(r[l]==(it->second).at(i).substr(j,r[l].size()) && dobar(r[l],it->second.at(i))) skup.push_back(make_tuple(it->first,i+1,j));
          rez[r[l]]=skup;
     }
}

bool valja(vector<string> &v, string temp)
{
    
    for(int j=0; j<v.size(); j++) if(v[j]==temp) return false;
    return true;
}

Ind KreirajIndeksPojmova(Knjiga k)
{
     Ind rez;
     k=smanjislova(k);
     
     vector<string> r;
     for(auto it=k.begin(); it!=k.end(); it++){
          for(int i=0; i<it->second.size(); i++){
               auto temp=sep(it->second.at(i));
               for(int i=0; i<temp.size(); i++)
               {
                    if(valja(r,temp[i])) r.push_back(temp[i]);
               }
          }
     }
     filter(k,r,rez);
     return rez;
}

vector<tuple<string,int,int>> PretraziIndPojmova(string s, Ind mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) if(it->first==s) return it->second;
     throw logic_error("Unesena rijec nije nadjena!");
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
               string temp;
               getline(cin,temp);
               if(temp==".") break;
               else v.push_back(temp);
          }
          k[s]=v;
     }
     Ind ind=KreirajIndeksPojmova(k);
     cout<<endl<<"Kreirani indeks pojmova: "<<endl;
     IspisiIndeksPojmova(ind);
     while(1)
     {
          cout<<"Unesite rijec: ";
          string temp; getline(cin,temp);
          if(temp==".") break;
          try{
          Strana d=PretraziIndPojmova(temp,ind);
          for(int i=0; i<d.size(); i++)
               {
                    auto temp=d.at(i);
                    cout<<get<0>(temp)<<"/"<<get<1>(temp)<<"/"<<get<2>(temp)<<" ";
                   if(i==(d.size())-1) cout<<endl;
               }
          }catch(logic_error izuz) {cout<<izuz.what()<<endl; }
     }
	return 0;
}
