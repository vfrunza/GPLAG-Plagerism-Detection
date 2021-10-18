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

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::getline;

string reverse(string word) {
	string newword;
	int i(0);
	while(i != word.length()) 
		newword += word.at(word.length() - 1 - i++);
	return newword;
}

vector<int> seeker3(string rijec, vector<string> fraza) {
	vector<int> posall;
	for(int i = 0; i < fraza.size(); i++) {
		if(rijec.length() < fraza.at(i).length()) continue;
		for(int j = 0; j <= rijec.length() - fraza.at(i).length(); j++) 
			if(rijec.substr(j, fraza.at(i).length()) == fraza.at(i)) posall.push_back(j);
	}
	return posall;
}

string replace(int startpos, int dellength, string input, string source) {
	source.erase(startpos, dellength);
	source.insert(startpos, input);
	return source;
}

string makeword(string word) {
	string mod(word);
	mod.erase(mod.length()/2, mod.length());
	word.erase(word.length()-word.length()/2, word.length());
	word.insert(word.length(), reverse(mod));
	return word;
}

string NapraviPalindrom(string recenica, vector<string> fraze) {
	for(int i = 0; i < fraze.size(); i++) {
	vector<string> tefraze;
	tefraze.push_back(fraze.at(i) + reverse(fraze.at(i)));
	tefraze.push_back(fraze.at(i));
	vector<int> positions = seeker3(recenica, tefraze);
	if(!positions.empty()) 
		for(int j = 0; j < positions.size(); j++) 
			if(recenica.length() >= positions.at(j) + fraze.at(i).length())
				if(recenica.length() == positions.at(j)+fraze.at(i).length()) {
					recenica.insert(recenica.length(), reverse(fraze.at(i)));
					positions = seeker3(recenica, tefraze);
				}
				else if(recenica.at(positions.at(j)+fraze.at(i).length()) == ' ' || recenica.at(positions.at(j)+fraze.at(i).length()) == ',' || recenica.at(positions.at(j)+fraze.at(i).length()) == '.') {
					recenica.insert(positions.at(j) + fraze.at(i).length(), reverse(fraze.at(i)));
					positions = seeker3(recenica, tefraze);
				}
					
	}
	return recenica;
}

string NapraviPoluPalindrom(string recenica, vector<string> fraze) {
	for(int i = 0; i < fraze.size(); i++) {
	vector<string> tefraze;
	tefraze.push_back(reverse(fraze.at(i).substr(0, fraze.at(i).length()/2)));
	tefraze.push_back(fraze.at(i));
	vector<int> positions = seeker3(recenica, tefraze);
	if(!positions.empty()) 
		for(int j = 0; j < positions.size(); j++) 
			if(recenica.length() >= positions.at(j) + fraze.at(i).length())
				if(recenica.length() == positions.at(j)+fraze.at(i).length()) {
					recenica = replace(positions.at(j) + (fraze.at(i).length()-fraze.at(i).length()/2), fraze.at(i).length()/2, reverse(fraze.at(i).substr(0,fraze.at(i).length()/2)), recenica);
					positions = seeker3(recenica, tefraze);
				}
				else if(recenica.at(positions.at(j)+fraze.at(i).length()) == ' ' || recenica.at(positions.at(j)+fraze.at(i).length()) == ',' || recenica.at(positions.at(j)+fraze.at(i).length()) == '.') {
					recenica = replace(positions.at(j) + (fraze.at(i).length()-fraze.at(i).length()/2), fraze.at(i).length()/2, reverse(fraze.at(i).substr(0,fraze.at(i).length()/2)),recenica);
					positions = seeker3(recenica, tefraze);
				}
	}
	return recenica;
}

int main() {
	cout << "Unesite recenicu: ";
	string recenica;
	getline(cin,recenica);	
	cout << "Unesite fraze: ";
	vector<string> fraze;
	string input = "not empty";
	while(!input.empty()) {
		getline(cin, input);
		if(input.empty()) { getline(cin,input);
		if(input.empty()) break;}
		fraze.push_back(input);
	}
	cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze) << endl << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
	return 0;
}