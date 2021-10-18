#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::vector;
using std::string;

bool Slovo(char c){
	if((c>='a' && c<='z') || (c>='A' && c<='Z')) return true;
	return false; 
}

string NapraviPoluPalindrom(string x, vector<string> v){
	string y {x};
	bool valid {true};

	for(int i=0; i<v.size(); i++)
		for(int j=0,k=0; j<y.length(); j++,k=0) {
			if(j<y.length() && k<v.at(i).length() && y.at(j)==v.at(i).at(k) && Slovo(y.at(j)) && Slovo(v.at(i).at(k)) && v.at(i).length()>1) {
				if(j>0 && Slovo(y.at(j-1))) continue;
				j++; k++;
				while(j<y.length() && k<v.at(i).length() && y.at(j)==v.at(i).at(k)) {
					j++; k++;
				}
				
				if(k!=v.at(i).length() || (j<y.length() && Slovo(y.at(j)))) valid=false;
				else valid=true;
				if(!valid) j=j-k;
				if(valid) {
					bool paran {false};
					if(k%2==0) paran=true;
					k=(k/2)+1;
					int p=j-k+1;
					if(paran) j=j-k;
					else j=j-k-1;
					k=k-1;
					string s2;
					while(k>0) {
						s2.push_back(y.at(j));
						j--; k--;
					}
					for(k=0; k<s2.size(); k++,p++)
						y.at(p)=s2.at(k);
					j=p;
				}
			}
		}
	return y;
}

string NapraviPalindrom(string x, vector<string> v){
	string y {x};
	bool valid {true};

	for(int i=0; i<v.size(); i++)
		for(int j=0,k=0; j<y.length(); j++,k=0) {
			if(y.at(j)==v.at(i).at(k) && j<y.length() && k<v.at(i).length() && Slovo(y.at(j)) && Slovo(v.at(i).at(k)) && v.at(i).length()>1) {
				if(j>0 && Slovo(y.at(j-1))) continue;
				j++; k++;
				while(j<y.length() && k<v.at(i).length() && y.at(j)==v.at(i).at(k)) {
					j++; k++;
				}

				if(k!=v.at(i).length() || (j<y.length() && Slovo(y.at(j)))) valid=false;
				else valid=true;
				
				if(!valid) j=j-k;
				if(valid) {
					int p=j--;
					string s2;
					while(k>0) {
						s2.push_back(y.at(j));
						j--; k--;
					}
					y.insert(p,s2);
					j=p+s2.length();
				}
			}
		}
	return y;
}

int main (){
	cout << "Unesite recenicu: ";
	string s;
	std::getline(cin,s);
	cout << "Unesite fraze: ";
	vector<string> v;
	string s2;
	while(cin.peek()!='\n') {
		std::getline(cin,s2);
		v.push_back(s2);
	}
	cout << "Recenica nakon Palindrom transformacije: ";
	cout << NapraviPalindrom(s,v) << std::endl;
	cout << "Recenica nakon PoluPalindrom transformacije: ";
	cout << NapraviPoluPalindrom(s,v);
	return 0;
}