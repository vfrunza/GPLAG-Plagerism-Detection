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
using std::string;
using std::vector;
using std::endl;

string UbaciPalindrom(string s, string fraza, int n){
	for(int i=0;i<fraza.length();i++){
		s.insert(s.begin()+n, fraza.at(i));
	}
	return s;
}

string MozeLiPalindrom(string s, string fraza, int j){
	if(s==fraza && s.length()==1 && fraza.length()==1){
		s.push_back(fraza.at(0));
		return s;
	}
	if(s.length()<fraza.length()){
		return s;
	}
	if(j==0){
		for(int i=0;i<fraza.length();i++){
			if(s.at(i)==fraza.at(i)){
				if(i==s.length()-1 && i==fraza.length()-1){
					s=UbaciPalindrom(s, fraza, i+1);
					return s;
				}
				else if((s.at(i+1)==',' || s.at(i+1)=='.' || s.at(i+1)==' ') && (i==fraza.length()-1)){
					s=UbaciPalindrom(s, fraza, i+1);
					return s;
				}
				else if(i==fraza.length()-1){
					return s;
				}
			}
			else{
				return s;
			}
		}
	}
	if((s.at(j-1)==',' || s.at(j-1)=='.' || s.at(j-1)==' ') && (j+fraza.length()==s.length())){
		int x(0);
		for(int i=j-1;i<fraza.length()+j;i++){
			if(fraza.at(x)==s.at(i)){
				if(i==fraza.length()+j-1){
					s=UbaciPalindrom(s, fraza, j+fraza.length());
					return s;
				}
				x++;
			}
		}
	}
	if((s.at(j-1)==',' || s.at(j-1)=='.' || s.at(j-1)==' ') && (j+fraza.length()<=s.length()-1)){
		int x(0);
		for(int i=j-1;i<fraza.length()+j;i++){
			if(fraza.at(x)==s.at(i)){
				if((s.at(i+1)==',' || s.at(i+1)=='.' || s.at(i+1)==' ') && (i==fraza.length()+j-1)){
					s=UbaciPalindrom(s, fraza, j+fraza.length());
					return s;
				}
				x++;
			}
		}
	}
	if(j==s.length()-1 && s.at(j-1)==' ' && fraza.length()==1){
		s=UbaciPalindrom(s, fraza, j+1);
		return s;
	}
    return s;
}

string UbaciPoluPalindrom(string s, string fraza, int n){
	int x(0);
	for(int i=n;i<=n+fraza.length()/2;i++){
		s.at(n+fraza.length()-x-1)=s.at(i);
		x++;
	}
	return s;
}

string MozeLiPoluPalindrom(string s, string fraza, int j){
	if(s==fraza && s.length()==1 && fraza.length()==1){
		s.push_back(fraza.at(0));
		return s;
	}
	if(s.length()<fraza.length()){
		return s;
	}
	if(j==0){
		for(int i=0;i<fraza.length();i++){
			if(s.at(i)==fraza.at(i)){
				if(i==s.length()-1 && i==fraza.length()-1){
					s=UbaciPoluPalindrom(s, fraza, j);
					return s;
				}
				else if((s.at(i+1)==',' || s.at(i+1)=='.' || s.at(i+1)==' ') && (i=fraza.length()-1)){
					s=UbaciPoluPalindrom(s, fraza, j);
					return s;
				}
				else if(i==fraza.length()-1){
					return s;
				}
			}
			else{
				return s;
			}
		}
	}
	if((s.at(j-1)==',' || s.at(j-1)=='.' || s.at(j-1)==' ') && (j+fraza.length()==s.length())){
		int x(0);
		for(int i=j-1;i<fraza.length()+j;i++){
			if(fraza.at(x)==s.at(i)){
				if(i==fraza.length()+j-1){
					s=UbaciPoluPalindrom(s, fraza, j);
					return s;
				}
				x++;
			}
		}
	}
	if((s.at(j-1)==',' || s.at(j-1)=='.' || s.at(j-1)==' ') && (j+fraza.length()<=s.length()-1)){
		int x(0);
		for(int i=j-1;i<fraza.length()+j;i++){
			if(fraza.at(x)==s.at(i)){
				if((s.at(i+1)==',' || s.at(i+1)=='.' || s.at(i+1)==' ') && (i==fraza.length()+j-1)){
					s=UbaciPoluPalindrom(s, fraza, j);
					return s;
				}
				x++;
			}
		}
	}
	if(j==s.length()-1 && fraza.length()==1 && s.at(j-1)==' '){
		s=UbaciPoluPalindrom(s, fraza, j);
		return s;
	}
	return s;
}

string NapraviPalindrom(string s, vector<string> VS){
	if(VS.size()==0 || s.length()==0){
		return s;
	}
	for(int i=0;i<VS.size();i++){
		for(int j=0;j<s.length();j++){
			if(s.at(j)==VS.at(i).at(0)){
				s=MozeLiPalindrom(s, VS.at(i), j);
			}
		}
	}
	return s;
}

string NapraviPoluPalindrom(string s, vector<string> VS){
	if(VS.size()==0 || s.length()==0){
		return s;
	}
	for(int i=0;i<VS.size();i++){
		for(int j=0;j<s.length();j++){
			if(s.at(j)==VS.at(i).at(0)){
				if(s.length()==1 && s==VS.at(i)){
					return s;
				}
				else{
					s=MozeLiPoluPalindrom(s, VS.at(i), j);
				}
			}
		}
	}
	return s;
}

int main ()
{
	string s;
	cout << "Unesite recenicu: ";
	std::getline(cin, s);
	vector<string> vs;
	cout << "Unesite fraze: ";
	for(;;){
		string p;
		std::getline(cin, p);
		if(p.length()==0){
			break;
		}
		else{
			vs.push_back(p);
		}
	}
	string recenica;
	if(vs.size()==0){
		recenica=s;
	}
	else{
		recenica=NapraviPalindrom(s,vs);
	}
	cout << "Recenica nakon Palindrom transformacije: " << recenica << endl;
	if(vs.size()==0){
		recenica=s;
	}
	else{
	    recenica=NapraviPoluPalindrom(s,vs);
	}
	cout << "Recenica nakon PoluPalindrom transformacije: " << recenica;
	return 0;
}