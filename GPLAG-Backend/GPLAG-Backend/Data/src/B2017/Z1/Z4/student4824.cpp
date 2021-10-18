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
std::string NapraviPalindrom (std:: string recenica, std::vector<std::string> popis) {
	int isti(0),k(0),brojac(0),kraj(0);
	std::string pomocni;
	char pomoc;
	for(int j=0;j<popis.size();j++) {
		int i=0;
		while(i<recenica.length()) {
		while(k<popis.at(j).size() && i<recenica.length()) {
			if(recenica.at(i)==popis.at(j).at(k)) {
				
				isti++;
				i++;
				k++;
				brojac++;
				
			}
			else if(recenica.at(i)!=popis.at(j).at(k) && i<recenica.length()) {
				while(((recenica.at(i)>='a' && recenica.at(i)<='z')  && (i+1)<recenica.length()) || ((recenica.at(i)>='A' && recenica.at(i)<='Z') &&  (i+1)<recenica.length())) {
					i++;
					brojac++;
				}
				i++;
				brojac++;
				k=0;
				isti=0;
			}
			else {
				isti=0;
				i++;
				brojac++;
				k=0;
			}
			
		}
		
		if((isti==popis.at(j).size() && i==recenica.length()) || (isti==popis.at(j).size() && (!((recenica.at(i)>='a' && recenica.at(i)<='z') || (recenica.at(i)>='A' && recenica.at(i)<='Z')))))
		{
			
			
			kraj=brojac;
			
				for ( k=0;k<popis.at(j).length();k++){
				pomocni.push_back(popis.at(j).at(k));
				}
				for(int p=0;p<pomocni.length()/2;p++){
					pomoc=pomocni.at(p);
					pomocni.at(p)=pomocni.at(pomocni.length()-p-1);
					pomocni.at(pomocni.length()-p-1)=pomoc;
					
				}
				for(int s=0;s<pomocni.length();s++){
					recenica.insert(recenica.begin()+kraj , pomocni.at(s));
					kraj++;
				}
			pomocni.resize(0);
			k=0;
			
			isti=0;
			i++;
			brojac++;
		}
		else {
			isti=0;
			i++;
			brojac++;
			k=0;
		} 
			
		}
		brojac=0;

	}
	return recenica;

}
std::string NapraviPoluPalindrom ( std::string recenica, std::vector<std::string> popis) {

int isti(0),s(0),k(0),kraj(0),brojac(0);
	for(int j=0;j<popis.size();j++){
		int i=0;
		brojac=0;
		while(i<recenica.length()){
		while(k<popis.at(j).size() && i<recenica.length()) {
			if (recenica.at(i)==popis.at(j).at(k)){
				isti++;
				i++;
				k++;
				brojac++;
			}
				
			else if(recenica.at(i)!=popis.at(j).at(k) && i<recenica.length()) {
				
				while (((recenica.at(i)>='a' && recenica.at(i)<='z') && (i+1)<recenica.length()) || ((recenica.at(i)>='A' && recenica.at(i)<='Z') &&  (i+1)<recenica.length() )) {
					i++;
					brojac++;
					}
				i++;
				brojac++;
				k=0;
				isti=0;
				}
				else {
					isti=0;
				i++;
				brojac++;
				k=0;
				}
		}
		int novi_kraj(0);
			if ((isti==popis.at(j).size() && i==recenica.length()) || (isti==popis.at(j).size() && (!((recenica.at(i)>='A' && recenica.at(i)<='Z') || (recenica.at(i)>='a' && recenica.at(i)<='z'))))){
				s=brojac-isti;
				kraj=brojac-1;
				if (kraj%2==0) novi_kraj=(kraj-isti/2+1);
				if(kraj%2!=0) novi_kraj=(kraj-isti/2);
				while(s<=novi_kraj){
					recenica.at(kraj)=recenica.at(s);
					s++;
					kraj--;
				}
				isti=0;
				i++;
				brojac++;
				k=0;
				
			}
				else {
		isti=0;
		i++;
		brojac++;
		k=0;
	}
		
	}
	}
	
	return recenica;

}
int main ()
{
std::string recenica, nova_recenica;
	std::string fraza;
	std::vector<std::string> fraze;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica); 
	std::cout<<"Unesite fraze: ";
	while (std::cin.peek()!='\n'){
		std::getline(std::cin, fraza);
		fraze.push_back(fraza);
	}
	std::cin.clear();
	std::cin.ignore(1000,'\n');
	nova_recenica=NapraviPalindrom(recenica, fraze);
	recenica=NapraviPoluPalindrom(recenica, fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	for(int j=0;j<nova_recenica.length();j++){
		std::cout<<nova_recenica.at(j);
	}
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	for(int i=0;i<recenica.length();i++){
	std::cout<<recenica.at(i);
		
	}
	std::cout<<std::endl;
	return 0;
}