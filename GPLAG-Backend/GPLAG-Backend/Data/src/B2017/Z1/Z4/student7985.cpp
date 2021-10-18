/*B 2017/2018, Zadaća 1, Zadatak 4*/
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
typedef std::vector<string> Matrica;

bool Slovo(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
	return false;
}

string NapraviPalindrom(string s, Matrica fraze) {
	for(int i=0; i<fraze.size(); i++){
		string f(fraze.at(i)); 			//jedna mala fraza f
		for(int k=0; k<s.length(); k++){
			int j=0;
			bool pomjeri(false);
			while(j<f.length() && k<s.length() && s.at(k) == f.at(j)){
				pomjeri = true;
				k++;
				j++;
			}
			if(j == f.length()){
				if((k == s.length() && (k-f.length() == 0 || (k-f.length()-1 >= 0 && !Slovo(s.at(k-f.length()-1)))))	
				|| (k-f.length() == 0 && !Slovo(s.at(k)) /*&& k u dozv opsegu ??*/  ) 
				|| (k-f.length() > 0 && !Slovo(s.at(k-f.length()-1)) && k+1 < s.length() && !Slovo(s.at(k)))	){ // <==> cijeli string pronađen
					j--;
					for(; j>=0; j--, k++){
						s.insert(s.begin() + k, f.at(j));
					}
						
				} 
			}
			if(pomjeri) k--;
		}
	
	}
	return s;
}

string NapraviPoluPalindrom(string s, Matrica fraze) {
	for(int i=0; i<fraze.size(); i++){
		string f(fraze.at(i));
		for(int k=0; k<s.length(); k++){
			int j=0;
			while(j<f.length() && k<s.length() && s.at(k) == f.at(j)){
				k++; 
				j++;
			}
			if(j == f.length()){ 
				if((k == s.length() && (k-f.length() == 0 || (k-f.length()-1 >= 0 && !Slovo(s.at(k-f.length()-1)))))
				|| (k-f.length() == 0 && !Slovo(s.at(k)))
				|| (k-f.length() > 0 && !Slovo(s.at(k-f.length()-1)) && k+1 < s.length() && !Slovo(s.at(k)))	){
					for(j = f.length()/2 - 1; j >= 0; j--){
						s.at(k-(j+1)) = f.at(j);
					}
					k--;
				}
			}
		}
	}
	return s;
}

int main (){
	cout << "Unesite recenicu: ";
	string recenica;
	std::getline(cin, recenica);
	cout << "Unesite fraze: ";
	Matrica fraze;
	while(cin.peek() != '\n'){
		string s("");
		std::getline(cin, s); //kupi cijeli red i u s smjesta sve DO oznake '\n', iz ulaznog toka uklanja i '\n'
		if(s.length() != 0) fraze.push_back(s);
	}

	cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze) << endl;
	cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
	
	return 0;
}