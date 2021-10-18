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
#include <stdexcept>

using std::cin;
using std::cout;
using std::string;

bool JeLiSlovo(char c) {
	if((c>='a' && c<='z') || (c>='A' && c<='Z')) return true;
	return false;
}

string NapraviPalindrom(string s, std::vector<string> fraze) {
	
	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(fraze.at(i)==s.substr(j,fraze.at(i).length()) && JeLiSlovo(s[j+fraze.at(i).length()])==false) {
				for(int k=0; k<fraze.at(i).length(); k++) {
					int pomi=j+fraze.at(i).length()+k;
					string pomocni=s.substr(j+fraze.at(i).length()-k-1,1);
					s.insert(pomi, pomocni);
				}
			}
		}
	}
	return s;
}

string NapraviPoluPalindrom(string s, std::vector<string> fraze) {

	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(fraze.at(i)==s.substr(j, fraze.at(i).length()) && JeLiSlovo(s[j+fraze.at(i).length()])==false) {
			
				if((fraze.at(i).length())%2!=0) {
					for(int k=0; k<(fraze.at(i).length())/2; k++) {
						int pomi=j+(fraze.at(i).length())/2+k+1;
					string tmp=s.substr(pomi-2-k-k,1);
					
					s.erase(s.begin()+pomi);
					s.insert(pomi, tmp);
					}
				}
				else {
				for(int k=0; k<(fraze.at(i).length())/2; k++) {
				
					int pomi=j+(fraze.at(i).length())/2+k;
					string tmp=s.substr(pomi-1-k-k,1);
					
					s.erase(s.begin()+pomi);
					s.insert(pomi, tmp);
				}
				}
			}
			
		}
	}
	return s;
}

int main ()
{
	string recenica;
	cout<<"Unesite recenicu: ";
	std::getline(cin, recenica);
	std::vector<string> fraze;
	cout<<"Unesite fraze: ";
	string s;

		for(;;) {
	std::getline(cin, s);
	fraze.push_back(s);
	if(s.length()==0) break;
	}

	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, fraze)<<std::endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, fraze);

	
	return 0;
}