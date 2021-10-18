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

typedef vector<string> VekStr;

string Obrni(string s){
	string pom=s;
	
	int vel(pom.length());
	int duz=2*vel;
		pom.resize(duz);
		int p(0);
		for(int j=duz-1; j>=vel; j--){
			pom.at(j)=pom.at(p);
			p++;
		}
	
	return pom;
}

string NapraviPaliandrom(string s1, VekStr v){
	string s=s1;
	int jest=false;
	for(int i=0; i<v.size(); i++){
		string rijec(v.at(i));
		if(poc-1==' ' && kraj+1==' ') jest=true;
		bool nadjeno=false;
		int poc(0), kraj(0), a(0);//a- da gledam odakle pocinje rijec
		int k(0);
		
		for(int j=0; j<s.length(); j++){
			k=0;
			a=j;
			while(rijec.at(k)==s.at(j)){
				k++;
				j++;
				if(k>rijec.length()-1) break;
				if(j==s.length()) break;
			}
			
			if(k==rijec.length()){
				nadjeno=true;
				poc=a;
				kraj=a+k;
			}
			if(nadjeno==true){
				s=s.substr(0, poc)+Obrni(rijec)+s.substr(kraj, s.length());
			}
			nadjeno=false;
		}
	}
	return s;
}


int main ()
{
	VekStr vs;
	string str, s;
	cout<<"Unesite recenicu: ";
	getline(cin,str);
	
	cout<<"Unesite frazu: ";
	//cin.ignore(10000, '\n');
	cin.clear();
	for(;;){
		getline(cin, s);
		if(s.length()==0) break;
		else vs.push_back(s);
	}
	
	cout<<"Recenica nakon Palindrom transformacije: ";
	cout<<NapraviPaliandrom(str, vs);
	
	return 0;
}