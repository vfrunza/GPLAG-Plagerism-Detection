//B 2017/2018, Zadaća 1, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string NapraviPalindrom (string s, vector<string>fraze){
	string krajnja_recenica(s);
	for (int i=0; i<fraze.size(); i++){
	    string prva (fraze.at(i)); 
		for (int j=0; j<s.length()-1; j++){
			if (j+prva.length() > s.length()) break;
			string druga (s.substr(j, prva.length()));
			bool pom (true);
			
			if (j+prva.length() != s.length())
			    pom = (s.at(j+prva.length()) < 'A' || (s.at(j+prva.length()) > 'Z' && s.at(j+prva.length()) < 'a') || s.at(j+prva.length()) > 'z');
			    
			if (prva == druga && pom){
				krajnja_recenica ="";
				krajnja_recenica += s.substr(0, j+prva.length());
				for (int m=0; m<prva.length(); m++)
				    krajnja_recenica.push_back(prva.at(prva.length()-m-1));
				krajnja_recenica += s.substr(j+prva.length(), s.length()-j-prva.length());
				s = krajnja_recenica;
			}
		}
	}
	return krajnja_recenica;
}

string NapraviPoluPalindrom (string s, vector<string>fraze){
	string krajnja_recenica(s);
	for (int i=0; i<fraze.size(); i++){
		string prva (fraze.at(i));
		for (int j=0; j<s.length()-1; j++){
			if (j+prva.length() > s.length()) break;
			string druga (s.substr(j, prva.length()));
			bool pom (true);
			
			if (j+prva.length() != s.length())
			    pom = (s.at(j+prva.length()) < 'A' || (s.at(j+prva.length()) > 'Z' && s.at(j+prva.length()) < 'a') || s.at(j+prva.length()) > 'z');
			    
			if (prva == druga && pom){
				krajnja_recenica = "";
				krajnja_recenica += s.substr(0, j+(prva.length()+1)/2);
				for (int m=0; m<(prva.length()-(prva.length()+1)/2); m++)
				    krajnja_recenica.push_back(prva.at(prva.length()-(prva.length()+1)/2-m-1));
				krajnja_recenica += s.substr(j+prva.length(), s.length()-j-prva.length());
				s = krajnja_recenica;
			}    
		}
	}
	return krajnja_recenica;
}


int main (){
	
	cout << "Unesite recenicu: ";
	string s;
	getline(cin,s);
	cout << "Unesite fraze: ";
	int br(1);
	bool vrijednost (true);
	vector<string>v;
	
	while (vrijednost){
		v.resize(++br);
		getline(cin, v.at(br-1));
		if (v.at(br-1).length()==0){ //Prazan string -> kraj programa
			v.resize(--br);
			vrijednost = false;
		}
	}
	cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s,v);
	cout << "\nRecenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s,v);
	
	return 0;
}