/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string ObrnutString(string x){
	string temp{x};
	int h=0;
    	for(int i=x.length()-1;i>=0;i--){
		 temp.at(h)=x.at(i);
		 h++;
    	}
	return temp;
}
string NapraviPalindrom(string s, vector<string> v){
	    string pom,temp;
	    int k=0,t=0;
	    for(int i=0;i<v.size();i++){
	    	pom=v.at(i);
	    	temp=pom;
	    	for(int j=0;j<s.length();j++){
	    		if(s.at(j)==pom.at(0)){
	    			while(k<pom.length()){
	    				if(pom.at(k)!=s.at(j)){
	    					break;
	    				}
	    				k++; j++;
	    				if(j>s.length()-1){
	    					break;
	    				}
	    			}
	    			if(k==pom.length()){
	    			 if((j==s.length()) || (!((s.at(j)>='a') && (s.at(j)<='z')) && (!((s.at(j)>='A') && (s.at(j)<='Z'))))){
	    		   	   pom=ObrnutString(pom);
	    		   	   s.resize(s.length()+pom.length());
	    		   	   for(int l=s.length()-1;l>=j+pom.length();l--){
	    		   	 	 s.at(l)=s.at(l-pom.length());
	    		   	   }
	    			   while(t<pom.length()){
	    				 s.at(j)=pom.at(t);
	    				 t++; j++;
	    				}
	    				pom=temp;
	    				t=0;
	    				}
	    		 	}
	    			k=0;
	    		}
	          }
	        }
  return s;
}
string NapraviPoluPalindrom(string s, vector<string> v){
	    string pom,temp,pomoc;
	    int k=0,t=0,m=0;
	    for(int i=0;i<v.size();i++){
	    	pom=v.at(i);
	    	temp=pom;
	    	for(int j=0;j<s.length();j++){
	    		if(s.at(j)==pom.at(0)){
	    			while(k<pom.length()){
	    				if(pom.at(k)!=s.at(j)){
	    					break;
	    				}
	    				k++; j++;
	    				if(j>s.length()-1){
	    					break;
	    				}
	    			}
	    			if(k==pom.length()){
	    				if((j==s.length()) || ((!((s.at(j)>='a') && (s.at(j)<='z'))) && (!((s.at(j)>='A') && (s.at(j)<='Z'))))){
	    		    	  pom=ObrnutString(pom);
	    		   	      if(pom.length()%2==0){
	    		   	 	  m=(pom.length()/2);
	    		   	      }
	    		   	      else{
	    		   	 	  m=((pom.length()/2)+1);
	    		   	 	  }
	    		   	      while(m<pom.length()){
	    		   	 	  pomoc.push_back(pom.at(m));
	    		   	 	  m++;
	    		   	      }
	    		   	      j=j-(pom.length()/2);
	    			 	  while(t<pomoc.length()){
	    					s.at(j)=pomoc.at(t);
	    					t++; j++;
	    				 }
	    				pom=temp;
	    				pomoc.resize(0);
	    				t=0; m=0;
	    				}
	    			  }
	    			k=0;
	    	   }
	      }
	   }
  return s;
}
int main (){
	string S,y;
	vector<string> W;
	cout<<"Unesite recenicu: ";
	getline(cin, S);
	cout<<"Unesite fraze: ";
	char znak(cin.peek());
	while (znak!='\n'){
		getline(cin, y);
	    W.push_back(y);
	    znak=cin.peek();
	}
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(S,W);
	cout<<endl<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(S,W);
	
	return 0;
}