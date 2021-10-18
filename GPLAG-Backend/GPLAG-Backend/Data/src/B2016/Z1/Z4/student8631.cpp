#include <iostream>
#include <string>
#include <stdexcept>
#include<vector>
using namespace std; 

string ObrniFraze(string s, vector<string>v) {
    string s1=" "; 
    int sadasnji(0); 
    int prethodni(0); 
    for(int i=0; i<=s.size(); i++){
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') && (i==0 || s[i-1]==' '))
        s1=s.substr(sadasnji, prethodni-1); 
    
    }   
             for(unsigned int i=0; i<v.size(); i++){
			 	for(unsigned int j=0; j<v[i].size()/2; j++){
			     double temp=v[i][j];
                 v[i][j]=v[i][v[i].size()-j-1]; 
                 v[i][v[i].size()-j-1]=temp;
		      }
    }

     return s1; 
}
/* string IzmijeniUPigLatin(string s, vector<string>v){
    for(int i=0; i<v.size(); i++) 
    p=i;
    while (((s[i]<='A' && s[i]>='Z')||(s[i]<='a' && s[i]>='z')) && i<s.size())
    i++; 
    k=i; 
    string pom=s.substr(p, k-p); 
    bool postoji(false);
    for(int j=0; j<v.size(); j++) 
if(v[i]=pom)  pom=true; 

if(postoji){
 for(int i:s) {
  s1[i]=s.substr(p+1, k+p-1) +s[p]+'ay'+s[p];
  }
  i+=2; 
}  
    return s1;
}
*/
int main(){

   int n; cin>>n; 
    string s;
    for(int i=0; i<s.size(); i++) cin>>s[i];
    
    vector<string> r(n); 
    for(int j=0; j<r.size(); j++) cin>>r[j];
    std::vector<std::vector<int>>a ;
   // std::vector<std::vector<int>>b; 
   a=ObrniFraze(s,r);
  // b=IzmijeniUPigLatin()
cin>>a; 
    
   return 0 ;
}