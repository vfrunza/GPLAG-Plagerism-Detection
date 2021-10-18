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

void obrni(string &s){
	int i,j;
	for( i=0,j=s.length()-1;i<s.length()/2;i++,j--){
		char pom=s.at(i);
		s.at(i)=s.at(j);
		s.at(j)=pom;
	}
}
bool neslovo(char znak){
	if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z'))
	return false;
	return true;
}
	string NapraviPalindrom(string s, vector<string>v){
		string novi=s;
	if(v.size()==0){
		return novi;
	}

		for(int i=0;i<v.size();i++){
			string pom=v.at(i);
			string pom1=v.at(i);
			obrni(pom1);
			for(int j=0;j<s.length();j++){
				int k(0);
				int m=j;
					while(s.at(j)==pom.at(k) && k!=pom.length()){
						
						
						j++;
						k++;}
					if(k==pom.length() && ((m==0 && neslovo(s[j])) || (neslovo(s[m-1]) && j==s.length()) || (neslovo(s[m-1]) && neslovo(s[j])))){
						
						s.insert(j, pom1);
						
						
					}
				
			}
			
		}
		novi=s;
		return novi;
	}
	string obrnipola(string s){
		string rez;
		for(int i=0;i<s.length()/2;i++)
			rez.push_back(s[i]);
			int j=rez.length()-1;
			for(int i=0;i<rez.length()/2;i++)
			swap(rez[i], rez[j--]);
			
		return rez;
	}
	string NapraviPoluPalindrom(string s, vector<string>v){
		string novi=s;
	if(v.size()==0){
		return novi;
	}
	
		for(int i=0;i<v.size();i++){
			string pom=v.at(i);
			string pom2=v.at(i);
			int indeks=pom.length()/2;
			pom=obrnipola(pom);
			for(int j=0;j<s.length();j++){
				int k(0);
				int m=j;
				indeks=pom2.length()/2;
				if(pom2.length()%2==1)indeks++;
				while(k!=pom2.length() && s[j]==pom2[k]){
					j++;
					k++;
				}
				if(k==pom2.length() && ((m==0 && neslovo(s[j])) || (neslovo(s[m-1]) && j==s.length()) || (neslovo(s[m-1]) && neslovo(s[j])))){
					indeks+=m;
					for(auto c:pom)s[indeks++]=c;
				}
			}
		}
		novi=s;
		return novi;
	}

int main ()
{
	string s;
	cout<<"Unesite recenicu: ";
	
	getline(cin, s);
	vector<string>v;
	cout<<"Unesite fraze: ";
	do{
		string neki;
		getline(cin, neki);
		v.push_back(neki);
		
	}while(char(cin.peek())!='\n');
	string rez1=NapraviPalindrom(s, v);
	string rez2=NapraviPoluPalindrom(s, v);
		
		cout<<"Recenica nakon Palindrom transformacije: "<<rez1<<endl;
		cout<<"Recenica nakon PoluPalindrom transformacije: "<<rez2<<endl;
		return 0;

}





































