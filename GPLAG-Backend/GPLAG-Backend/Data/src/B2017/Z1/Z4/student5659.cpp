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
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

string IzvrniString(string rijec){
	
	string s;
	
	for(int i = rijec.size() - 1; i >=0; i--)
		s.push_back(rijec.at(i));
		
	return s;
}

bool PronadjiString(string rec, string rijec){
	
	
}
string NapraviPalindrom(string s, vector <string> vektor_stringova){
	
	if(s.size() == 0) throw;
	
	
	
	for(int i = 0; i < vektor_stringova.size(); i++){
		
		if(vektor_stringova.size() == 0) throw;
		
		for(int j = 0; j < s.size() - vektor_stringova.at(i).size() + 1 ; j++){
			
			if(s.substr( j , vektor_stringova.at(i).size() ) == vektor_stringova.at(i) && (j + vektor_stringova.at(i).size() == s.size() || ( s.at(j + vektor_stringova.at(i).size()) < 65 || (s.at(j + vektor_stringova.at(i).size()) >90  && s.at(j + vektor_stringova.at(i).size()) < 97) || s.at(j + vektor_stringova.at(i).size()) > 122)) ){
			
				string izvrnuta_rijec(IzvrniString(vektor_stringova.at(i)));
				
				for(int k = 0; k < izvrnuta_rijec.size(); k++)
					s.insert(s.begin() + j + izvrnuta_rijec.size()+k , izvrnuta_rijec.at(k) );
				
				j = j + izvrnuta_rijec.size();
			}
		}
		
	}
	
	return s;
}

string NapraviPoluPalindrom(string s, vector <string> vektor_stringova){
	
	if(vektor_stringova.size() == 0 || s.size() == 0) return s;
	
	for(int i = 0; i < vektor_stringova.size(); i++){
		
		for(int j = 0; j < s.size() - vektor_stringova.at(i).size() + 1 ; j++){
			
			if(s.substr( j , vektor_stringova.at(i).size() ) == vektor_stringova.at(i) && (j + vektor_stringova.at(i).size() == s.size() || ( s.at(j + vektor_stringova.at(i).size()) < 65 || (s.at(j + vektor_stringova.at(i).size()) >90  && s.at(j + vektor_stringova.at(i).size()) < 97) || s.at(j + vektor_stringova.at(i).size()) > 122)) ){
				
				string izvrnuta_rijec(IzvrniString(vektor_stringova.at(i)));
				
				for(int k = izvrnuta_rijec.size() / 2 ; k < izvrnuta_rijec.size() ; k++)
					s.at(j + k) = izvrnuta_rijec.at(k);
			
			j = j + izvrnuta_rijec.size() / 2;
			
			}
		}
	}
	return s;
}

int main ()
{
	
	
	
	cout<<"Unesite recenicu: ";
	
	string s;
	getline(cin,s);
	
	vector<string> rijeci;
	
	cout<<"Unesite fraze: ";
	
	do{
		
		string r;
		
		getline(cin,r);
		
		rijeci.push_back(r);
		
	} while(cin.peek() != '\n');
	
	cout<<"Recenica nakon Palindrom transformacije: ";
		
	try{
	
		cout<<NapraviPalindrom(s,rijeci);
	
	}
	
	catch(...){}
	
	cout<<endl<<"Recenica nakon PoluPalindrom transformacije: ";
	
	try{
		
		cout<<NapraviPoluPalindrom(s,rijeci);
	
	}
	
	catch(...){}
	
	return 0;
}