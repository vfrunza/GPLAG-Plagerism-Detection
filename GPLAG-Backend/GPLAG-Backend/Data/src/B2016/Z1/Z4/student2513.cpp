/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
using std::string;

bool neslovo(char x){
	if(x<'A' || (x>'Z' && x<'a') || x>'z') return true;
	return false;
}
bool slovo(char x){
		if((x>'A' && x<'Z') || (x>'a' && x<'z')) return true;
	return false;
}

string ObrniFraze(string s, std::vector<std::string>v){
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.size(); j++){
			if(s.substr(j,v[i].size())==v[i]){
				for(int k=0; k<(v[i].size())/2; k++){
					char pomocni=s[k+j];
					s[k+j]=s[v[i].size()-1+j-k];
					s[v[i].size()-1+j-k]=pomocni;
				}
			}
		}
	}
	return s;
}

string IzmijeniUPiglatin(string s, std::vector<std::string>v){
		for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++) if(slovo(v[i][j]==false)) 
		throw std::domain_error("Nekorektan izbor rijeci");
	}
	char a='a';
	char y='y';
	for (int i=0; i<v.size(); i++){
		for(int j=0; j<s.size(); j++){
			if((s.substr(j, v[i].size())==v[i]) && ((s[j]==s[0] || neslovo(s[j-1]==true)) 
			&& ( j+v[i].size()-1==s.size()-1 || neslovo(s[j+v[i].size()])==true))){
				s.insert(s.begin()+j+v[i].size(), s[j]);
				s.insert(s.begin()+j+v[i].size()+1 ,a);
				s.insert(s.begin()+j+v[i].size()+2 ,y);
				s.erase(s.begin()+j);
			}
		}
	}
	return s;
}

int main ()
{
	string s,s1;
	std::vector<string>v;
	
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	std::getline(std::cin,s1);
	while(s1.size()!=0){
		v.push_back(s1);
		std::getline(std::cin,s1);
	}
	try{
	std::cout << "Recenica nakon PigLatin transformacije: "<<IzmijeniUPiglatin(s,v);}
	catch (std:: domain_error izuzetak){
		std::cout<<"Izuzetak: "<< izuzetak.what()<<std::endl;
	}
	std::cout << std::endl << "Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	
	return 0;
	
}