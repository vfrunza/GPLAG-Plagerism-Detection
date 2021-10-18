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

std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	int pronasao(0),vel(0),k(0);
	if(v.size()==0) return s;
	else{
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.at(i).size(); j++){
			vel=v.at(i).size();
			while(k<s.size()){
				if(k<s.size()-1 && j<v.at(i).size() && v.at(i).at(j)!=s.at(k)) k++;
				while(k<s.size()-1 && j<v.at(i).size() && v.at(i).at(j)==s.at(k)){
				j++;
				k++;
				if(k<=s.size()-1 && j==v.at(i).size()-1 && v.at(i).at(j)==s.at(k)){
					if(k-vel+1==0 || s.at(k-vel)==' '){
						if(k==s.size()-1 || (k+1<=s.size()-1 && s.at(k+1)==' ') || (k+1==s.size()-1 && (s.at(k+1)==' ' || s.at(k+1)=='.' || s.at(k+1)=='?' || s.at(k+1)=='!' || s.at(k+1)==',')) || (k+1<=s.size()-1 && k+2<=s.size()-1 && s.at(k+2)==' ' && (s.at(k+1)=='.' || s.at(k+1)=='?' || s.at(k+1)=='!' || s.at(k+1)==','))){
					pronasao=1;
					s.resize(s.size()+vel);
					for(int a=s.size()-1; a>k; a--){
						s.at(a)=s.at(a-vel);
					}
					int b=k+1;
					while(b<k+1+vel){
					for(int a=vel-1; a>=0; a--){
						s.at(b)=v.at(i).at(a);
						b++;
					}
					}
				}}}
				if(pronasao){
					pronasao=0;
					j=0;
					k+=vel; 
					break;
				}
				}
				j=0;
				k++;
			}
		}
		k=0;
	}
	std::string s1;
	s1=s;
	return s1;
}
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){
	int pronasao(0),vel(0),k(0);
	if(v.size()==0) return s;
	else{
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.at(i).size(); j++){
			vel=v.at(i).size();
			while(k<s.size()){
				if(k<s.size()-1 && j<v.at(i).size() && v.at(i).at(j)!=s.at(k)) k++;
				while(k<s.size()-1 && j<v.at(i).size() && v.at(i).at(j)==s.at(k)){
				j++;
				k++;
				if(k<=s.size()-1 && j==v.at(i).size()-1 && v.at(i).at(j)==s.at(k)){
					if(k-vel+1==0 || s.at(k-vel)==' '){
						if(k==s.size()-1 || (k+1<=s.size()-1 && s.at(k+1)==' ') || (k+1==s.size()-1 && (s.at(k+1)==' ' || s.at(k+1)=='.' || s.at(k+1)=='?' || s.at(k+1)=='!' || s.at(k+1)==',')) || (k+1<=s.size()-1 && k+2<=s.size()-1 && s.at(k+2)==' ' && (s.at(k+1)=='.' || s.at(k+1)=='?' || s.at(k+1)=='!' || s.at(k+1)==','))){
					pronasao=1;
					vel=v.at(i).size();
					int b=k;
					while(b>k-vel/2){
					for(int a=0; a<v.at(i).size()/2; a++){
						s.at(b)=v.at(i).at(a);
						b--;
					}
					}
				}}}
				if(pronasao){
					pronasao=0;
					j=0;
					k++;
					break;
				}
				}
				j=0;
				k++;
			}
		}
		k=0;
	}
	std::string s1;
	s1=s;
	return s1;
}
}
int main ()
{
	std::vector<std::string> rijeci;
	std::string recenica,palindrom,polupalindrom,rijec;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica,'\n');
	std::cout<<"Unesite fraze: ";
	do{
		std::getline(std::cin,rijec,'\n');
		if(rijec.size()==0) break;
		rijeci.push_back(rijec);
	}
	while(char(std::cin.peek())!='\n');
	palindrom=NapraviPalindrom(recenica,rijeci);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<palindrom<<std::endl;
	polupalindrom=NapraviPoluPalindrom(recenica,rijeci);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<polupalindrom<<std::endl;
	return 0;
}