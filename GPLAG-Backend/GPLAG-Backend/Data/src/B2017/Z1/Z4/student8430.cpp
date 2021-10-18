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


bool Provjeri(std::string s, std::string p, int &k){
	std::string pomocni;
	for(int i=0; i<p.size(); i++){
	for(int j=k; j<s.size(); j++){
		if(p.at(i)==s.at(j)){
			pomocni.push_back(s.at(j));
			if(i==p.size()-1) goto tamo;
			i++;
			tamo:if(pomocni==p){
				k=j;
				i=0;
	    	return true;
	}
	}
	}
	}
	return false;
}

void NapraviPoluPalindrom(std::string &s, std::vector<std::string> vs){
	for(auto x:vs){
		int broj(0);
		ponovo: bool k=Provjeri(s, x, broj);
		if(k==true){
			int pocetak(broj-x.size()+1);
			int p(pocetak+(x.size()/2)-1);
			for(int i=p; i>=pocetak; i--){
				s.at(pocetak+(broj-i))=s.at(i);
			}
			if(k==true) goto ponovo;
		}else continue;
	}
}

void NapraviPalindrom(std::string &s, std::vector<std::string> vs){
	std::string pomocni;
	int mjesto(0);
	 for(auto x:vs){
	 	mjesto=0;
	 	ponovo: bool tacno=Provjeri(s, x, mjesto);
	 	if(tacno==true){
	 		for(int i=0; i<x.size(); i++){
	 			s.insert(s.begin()+(mjesto+1), x.at(i));
	 		}
	 		if(tacno==true) goto ponovo;
	 	}else continue;
	 }
}



int main (){
	std::string s;
	std::vector<std::string> vs;
	std::string clan;
 std::cout<<"Unesite recenicu: ";
 std::getline(std::cin, s);
 std::cout<<"Unesite fraze: ";
 while(std::cin.peek()!='\n'){
 	std::getline(std::cin, clan);
 	vs.push_back(clan);
 }
 std::string p=s;
 NapraviPalindrom(s, vs);
 std::cout<<"Recenica nakon Palindrom transformacije: ";
 std::cout<<s<<std::endl;
 NapraviPoluPalindrom(p, vs);
 std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
 std::cout<<p;
 return 0;
}