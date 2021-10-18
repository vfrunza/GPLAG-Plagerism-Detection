/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include <vector>
#include<string>
#include<set>
#include<iomanip>
using namespace std; 
typedef map<string, set<int>> Mapa; 
//POMOCNA 
//KREIRAJ
string IzdvojiRijec(string s, int a) {
 string novi; 
 for(int i=a;i<s.size(); i++)  
 { 
   int j=i; 
   int brojac=0; 
  
   while ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')) {
    brojac++; j++; 
   }
   
   novi=s.substr(a,brojac); 
   if(novi.size()!=0)
    return novi; 
  }
}

set<int> NadjiIste(string novi, string s) {
 set<int> skup; 
 for(int i=0; i<s.size(); i++) 
 { string pom; 
  if( i==0 || s[i-1]==' ') pom=IzdvojiRijec( s, i); 
  if(pom==novi )
   skup.insert(i); 
   
 }
 return skup; 
}
Mapa KreirajIndeksPojmova(string s)
 {
   
  Mapa m;
    
    for(int i=0; i<s.size(); i++) {
      set<int>pozicija;string novi;
       if( i==0 || s[i-1]==' ' )
      {
           novi=IzdvojiRijec(s,i);
           pozicija=NadjiIste(novi,s);
       }
       m.insert(make_pair(novi,pozicija));
    }
     return m; 
 }

set<int> PretraziIndeksPojmova(string s, Mapa m){
 set<int>setic; 
   
    for(auto it=m.begin(); it!=m.end(); it++ )
      if(s==it->first) 
         return it->second;
     throw range_error("Ne valja");    
      
 }
 
 //prvi element u mapi i string ako su ==
void IspisiIndeksPojmova(Mapa m)
{
 for(auto it=m.begin(); it!=m.end(); it++ )
   {   cout<<it->first<<": "; int brojac=0; 
        for(auto i=it->second.begin();i!=it->second.end(); i++){
         brojac++; 
         if(brojac==it->second.size()) cout<<*i; 
         else cout<<*i<<","; 
        }
       cout<<endl;       
   }     
}
int main ()
{ 
 map<string,set<int>> mainmapa;
 cout<<"Unesite tekst: "; 
 string text;
 getline(cin, text, '.'); 
 vector<string>v(mainmapa.size());
 v.push_back(text);
 mainmapa= KreirajIndeksPojmova(text); 
 IspisiIndeksPojmova(mainmapa);
  for(auto it=mainmapa.begin(); it!=mainmapa.end(); it++ )
    for(int i=0; i<v.size(); i++)
  if(v[i]==it->first) 
   for(auto i=it->second.begin(); i!=it->second.end(); i++) 
   cout<<*i;
 //else cout<<"Unesena rijec nije nadjena!";
   //IspisiIndeksPojmova(mainmapa);
	return 0;
}
