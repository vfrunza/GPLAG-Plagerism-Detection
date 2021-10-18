/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 
#include <string>
using namespace std;

string ObrniString(string s){
   for(int i=0;i<s.size();i++){
      char temp(s[i]);
      s[i]=s[s.size()-1-i];
      s[s.size()-1-i]=temp;
   }
   return s;
}


string ObrniFraze(string s,vector<string> v){
   string s1;
   for(int i=0;i<v.size();i++){
      for(int j=0;j<s.size()-v[i].size();j++){
         string spom;
         if(s.substr(j,v[i].size())==v[i] ) {spom=ObrniString(s.substr(j,v[i].size())); s1+=spom; j+=v[i].size(); }
         else s1.push_back(s[j]);
      }
   }
   return s1;
}


int main ()
{
   string s;
   vector<string> v;
   string s1;
   cout<<"Unesite recenicu: ";
   getline(cin, s);
   cout<<"Unesite fraze: ";
   for(;;){
      getline(cin, s1);
      if(s1.size()==0) break;
      else v.push_back(s1);
   }
   
   s1=ObrniFraze(s,v);
   cout<<s1;
   /*cout<<"Recenica nakon PigLatin transformacije: "<<s;
   cout<<"Recenica nakon obrtanja fraza: "<<s;*/
   
   
	return 0;
}