/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cstring>

using namespace std;

bool DaLiJeJednaka(string mojarijec, vector<string> rijeci){
    for(int i=0;i<rijeci.size();i++){
        if(mojarijec==rijeci[i]) return 1;
    }
    return 0;
}

map<string,set<int>> KreirajIndeksPojmova (string mojstring){
    map<string,set<int>> mojamapa;
    vector<string> rijeci;
    string mojarijec;
    int j=0;
    mojstring.c_str();
    while(j<mojstring.size()){
        if(mojstring[j]>='A' && mojstring[j]<='Z') mojstring[j]+=32;
        j++;
    }
    

    for(int i=0;i<mojstring.size();i++){
    
   
    while(( mojstring[i]<'0' || (mojstring[i]>'9'&& mojstring[i]<'a') || mojstring[i]>'z') && i<mojstring.size()) 
    i++;  
    while(((mojstring[i]>='0' && mojstring[i]<='9') || (mojstring[i]>='a' && mojstring[i]<='z' )) && i<mojstring.size())
    {
        mojarijec.push_back(mojstring[i]); i++;
    }
        if(DaLiJeJednaka(mojarijec,rijeci)==0 && mojarijec.size()!=0) rijeci.push_back(mojarijec);
        mojarijec="";
        
    }
    
    
    for(int i=0;i<rijeci.size();i++){
        set<int> skupindeksa;
        for(int j=0;j<mojstring.size();j++){
            string rijeckojutrazim;
            int s=j;
            while( ((mojstring[j]>='0' && mojstring[j]<='9') || (mojstring[j]>='a' && mojstring[j]<='z')) && mojstring[j]!='\0'){
                rijeckojutrazim.push_back(mojstring[j]);
                j++;
            }
            if(rijeckojutrazim==rijeci[i]) skupindeksa.insert(s);
            
        }
        
        mojamapa.insert(make_pair(rijeci[i],skupindeksa));
        
        
    }
    
    return mojamapa;
}





set<int> PretraziIndeksPojmova(string mojstring, map<string,set<int>> mojamapa){
    set<int> skupindeksa;

auto it(mojamapa.find(mojstring));
if(it==mojamapa.end()) throw logic_error("Pojam nije nadjen");
else skupindeksa=(it->second);

return skupindeksa;
}


void IspisiIndeksPojmova(map<string,set<int>> mojamapa){
    for(auto it=mojamapa.begin(); it!=mojamapa.end();it++){
        cout<<it->first<<": ";
        int brojac=0;
        for(auto x: it->second){
            brojac++;
            if(brojac!=(it->second.size())) cout<<x<<",";
            else cout<<x;
        }
        cout<<endl;
        }
    }
    



int main ()
{
    try{
cout<<"Unesite tekst: ";
string s;
getline(cin,s);

map<string,set<int>> mapaa;
mapaa=KreirajIndeksPojmova(s);
IspisiIndeksPojmova(mapaa);
string f;
do{
  cout<<"Unesite rijec: ";
  
  getline(cin,f);
  
  if(f==".") break;
  set<int> rez;
  int brojac1=0;
  for(auto it=mapaa.begin();it!=mapaa.end();it++){
      if(f!=(it->first)) brojac1++;
  }
  
  if(brojac1!=mapaa.size()){
  rez=PretraziIndeksPojmova(f,mapaa);
  for(auto x:rez) cout<<x<<" ";
  cout<<endl; }
  else  cout<<"Unesena rijec nije nadjena!"<<endl;
    
}while(f!=".");
    
    }catch(logic_error izuzetak){cout<<izuzetak.what();}
	return 0;
}