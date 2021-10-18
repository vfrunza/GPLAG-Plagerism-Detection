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
#include <cmath>
std::string OkreniRijec(std::string s){
	std::string r;
	for(int i=s.length()-1;i>=0;i--){
		r.push_back(s.at(i));
	}	
		return r;
	}
std::string OkreniPola(std::string s){
	std::string r;
	for(int i=0;i<(s.length()/2);i++){
		r.push_back(s.at(i));
	}
	for(int j=((s.length()/2)-1);j>=0;j--){
		r.push_back(s.at(j));
	}
		return r;
	}
std::string NapraviPalindrom(std::string Recenica,std::vector<std::string> skup){
	std::string mer;
	for(int k=0;k<skup.size();k++){
		mer=skup.at(k);
	for(int i=0;i<Recenica.length();i++){
		int j=0;
		if(Recenica[i]==mer[j]){
			while(Recenica[i]==mer[j] && j<mer.length()){
				j++;
				i++;
			}
			if(j==mer.length()  && (Recenica[i]==' ' || i==Recenica.length() || Recenica[i]==',')){
	
				Recenica.insert(i,OkreniRijec(mer));
			}
		}}
	}
	
	return Recenica;
}
std::string NapraviPoluPalindrom(std::string Recenica,std::vector<std::string> skup){
	std::string mer;
	for(int k=0;k<skup.size();k++){
		mer=skup.at(k);
	for(int i=0;i<Recenica.length();i++){
		int j=0;
		if(Recenica[i]==mer[j]){
			int m=i;
			while(Recenica[m]==mer[j] && j<mer.length()){
				m++;
				j++;
			}
			if(j==mer.length()  && (Recenica[m]==' ' || m==Recenica.length() || Recenica[m]==',')){
				if(mer.length()%2==0){
				for(int l=0;l<(mer.length()/2);l++){
				Recenica.at(i)=mer.at(l);
				i++;
	}
				for(int j=(mer.length()/2)-1;j>=0;j--){
					Recenica.at(i)=mer.at(j);
					i++;
	}}			
				else{
				for(int l=0;l<=(mer.length()-1)/2;l++){
				Recenica.at(i)=mer.at(l);
				i++;
	}
				for(int j=((mer.length()-1)/2)-1;j>=0;j--){
					Recenica.at(i)=mer.at(j);
					i++;
		}
			
	}}}}}
	return Recenica;
}

int main ()
{
	std::vector<std::string> vektor;
	std::string recenica;
	std::string krejzi;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	while(std::cin.peek()!='\n'){
		std::getline(std::cin,krejzi);
		vektor.push_back(krejzi);
		std::cin.clear();
	}
	std::string ende=NapraviPoluPalindrom(recenica,vektor);
	recenica=NapraviPalindrom(recenica,vektor);
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout << recenica;
	std::cout <<"\n";
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::cout << ende;

	return 0;
}