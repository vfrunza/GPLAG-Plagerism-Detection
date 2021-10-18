/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include<algorithm>
using namespace std;
int BrojRijeci (string s){
    int brojac(0);
    for(int i(0);i<s.size();i++){
        while(s[i]==' ' && i!=s.size())
        i++;
        if(i==s.size())
        break;
        brojac ++;
        while(s[i]!=' ' && i<s.size()) i++;
    }
    return brojac;
}

string NadjiRijec(string s, int n){
    int brojac(0);
    for(int i(0);i<s.size();i++){
     while(s[i]==' ' && i!=s.size() ) i++;
     if(i==s.size())
     break;
     brojac++;
    
     int temp(i);
     int brojac1(0);
     while(s[i]!=' ' && i<s.size()){
         brojac1++;
         i++;
     }
     if(brojac==n){
         string pom(s.substr(temp,brojac1));
         return pom;
     
    }
    }
   }
  
  	void IzbaciDuple (vector<string>&v){
		
			
			for(int i(0);i<int(v.size());i++){ 
			for(int j(i+1);j<int(v.size());j++){
				if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
				}
				
			}
			
			//sort(v.begin(), v.end(),[](string x, string y) { return x > y; });
			}

		
   vector<string>SveRijeci(string s){
    vector<string>v;
    int n=BrojRijeci(s);
    for(int i(0);i<n;i++){
        string rijec=NadjiRijec(s,i);
        v[i].push_back(rijec);
    }
    return v;
    
}
   
/*map<string,set<int>>KreirajIndeksPojmova(string s){
    map<string,set<int>> mapa;
    string s1;
    set<int>skup;
    for(int i(0);i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z')
        s[i]+=32;
        
    }
 return mapa;
}*/

int main ()
{
    
	return 0;
}