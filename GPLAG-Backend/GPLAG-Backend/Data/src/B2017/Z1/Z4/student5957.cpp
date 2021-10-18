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
using std::cout;
using std::cin;
using std::string;
using std::vector;

string IzmjeniRecenicu(string s,string rijec,int br,bool istina){
	if(istina){
		for(int i(0);i<rijec.size();i++){
			s.insert(s.begin()+br,rijec.at(i));
		}
	}
	else{
		int k(0);
		for(int i(br);i<=br+rijec.size()/2;i++){
			s.at(br+rijec.size()-1-k)=s.at(i);
			k++;
		}
	}
	return s;
}

string DaLiMoze(string s,string rijec,int j,bool istina){
	if(rijec.length()>s.length()) return s;
	if(s.length()==1 && rijec.length()==1 && s==rijec){
		s.push_back(rijec.at(0));
		return s;
	}
	if(j==0){
		for(int i(0);i<rijec.length();i++){
			if(s.at(i)==rijec.at(i)){
				if(i==rijec.length()-1 && i==s.length()-1){
					if(istina){
						s=IzmjeniRecenicu(s,rijec,i+1,true);
						return s;
					}
					else{
						s=IzmjeniRecenicu(s,rijec,j,false);
						return s;
					}
				}
				else if((s.at(i+1)==' ' || s.at(i+1)==',' || s.at(i+1)=='.') && (i==rijec.length()-1)){
					if(istina){
						s=IzmjeniRecenicu(s,rijec,i+1,true);
						return s;
					}
					else{
						s=IzmjeniRecenicu(s,rijec,j,false);
						return s;
					}
				}
				else if(i==rijec.length()-1) return s;
			}
			else return s;
		}
	}
	if(j==s.length()-1 && s.at(j-1)==' ' && rijec.length()==1){
		if(istina){
			s=IzmjeniRecenicu(s,rijec,j+1,true);
			return s;
		}
		else{
			s=IzmjeniRecenicu(s,rijec,j,false);
			return s;
		}
	}
	if((s.at(j-1)==' ' || s.at(j-1)==',' || s.at(j-1)=='.') && (j+rijec.length()==s.length())){
		int k(0);
		for(int i(j);i<rijec.length()+j;i++){
			if(s.at(i)==rijec.at(k)){
				if(i==rijec.length()+j-1){
					if(istina){
						s=IzmjeniRecenicu(s,rijec,j+rijec.length(),true);
						return s;
					}
					else{
						s=IzmjeniRecenicu(s,rijec,j,false);
						return s;
					}
				}
				k++;
			}
		}
	}
	if((s.at(j-1)==' ' || s.at(j-1)==',' || s.at(j-1)=='.') && (j+rijec.length()<s.length())){
		int k(0);
		for(int i(j);i<rijec.length()+j;i++){
			if(s.at(i)==rijec.at(k)){
				if((i==rijec.length()+j-1) && (s.at(i+1)==' ' || s.at(i+1)==',' || s.at(i+1)=='.')){
					if(istina){
						s=IzmjeniRecenicu(s,rijec,j+rijec.length(),true);
						return s;
					}
					else{
						s=IzmjeniRecenicu(s,rijec,j,false);
						return s;
					}
				}
				k++;
			}
		}
	}
	return s;
}

string NapraviPalindrom(string s,vector<string> v){
	if(v.size()==0 || s.length()==0) return s;
	for(int i(0);i<v.size();i++){
		for(int j(0);j<s.length();j++){
			if(s.at(j)==v.at(i).at(0)){
				s=DaLiMoze(s,v.at(i),j,true);
			}
		}
	}
	return s;
}

string NapraviPoluPalindrom(string s,vector<string> v){
	if(v.size()==0 || s.length()==0) return s;
	for(int i(0);i<v.size();i++){
		for(int j(0);j<s.length();j++){
			if(s.at(j)==v.at(i).at(0)){
				if(s==v.at(i) && s.length()==1) return s;
				else
				s=DaLiMoze(s,v.at(i),j,false);
			}
		}
	}
	return s;
}

int main ()
{
	string recenica,s1,s2;
	cout<<"Unesite recenicu: ";
	std::getline(cin,recenica);
	cout<<"Unesite fraze: ";
	vector<string> fraze;
	for(;;){
		string s;
		char c1(std::cin.get());
		int n(1);
		if(c1!='\n'){
			s.push_back(c1);
		}
		else break;
		while(n){
			c1=std::cin.get();
			if(c1=='\n') n=0;
			else s.push_back(c1);
		}
		fraze.push_back(s);
	}
	s1=NapraviPalindrom(recenica,fraze);
	s2=NapraviPoluPalindrom(recenica,fraze);
	cout<<"Recenica nakon Palindrom transformacije: "<<s1<<std::endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: "<<s2;

	return 0;
}