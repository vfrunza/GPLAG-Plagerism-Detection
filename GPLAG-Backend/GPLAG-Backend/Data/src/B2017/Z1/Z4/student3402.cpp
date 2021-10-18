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

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> Lista_fraza){
	for(int i=0; i<int(Lista_fraza.size()); i++){
		for(int j=0; j<int(recenica.length()); j++){
			if(Lista_fraza.at(i).at(0)==recenica.at(j)){
				if(j>0){
					if((recenica.at(j-1)>='A' && recenica.at(j-1)<='Z') || (recenica.at(j-1)>='a' && recenica.at(j-1)<='z'))
						continue;
				}
				bool IstaRijec=true;
				int brojac=1;
				if(j+1<recenica.length()) j++;
				for(int k=1; k<int(Lista_fraza.at(i).length()); k++){
					brojac++;
					if(recenica.at(j)!=Lista_fraza.at(i).at(k)){
						IstaRijec=false;
						break;
					}
					if(j+1<int(recenica.length())) j++;
					else break;
				}
				if(IstaRijec && int(Lista_fraza.at(i).length())==brojac){
					if(j<int(recenica.length())-1){
						if((recenica.at(j)>='A' && recenica.at(j)<='Z') || (recenica.at(j)>='a' && recenica.at(j)<='z')) continue;
					}
					if(j<int(recenica.length())-1) j--;
					for(int k=0; k<int(Lista_fraza.at(i).length()); k++){
						recenica.insert(recenica.begin()+j+1, Lista_fraza.at(i).at(k));	
					}
					j+=Lista_fraza.at(i).length();
				}
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> Lista_fraza){
	for(int i=0; i<int(Lista_fraza.size()); i++){
		for(int j=0; j<int(recenica.length()); j++){
			if(Lista_fraza.at(i).at(0)==recenica.at(j)){
				if(j>0){
					if((recenica.at(j-1)>='A' && recenica.at(j-1)<='Z') || (recenica.at(j-1)>='a' && recenica.at(j-1)<='z'))
						continue;
				}
				bool IstaRijec=true;
				int brojac=1;
				if(j+1<int(recenica.length())) j++;
				for(int k=1; k<int(Lista_fraza.at(i).length()); k++){
					brojac++;
					if(recenica.at(j)!=Lista_fraza.at(i).at(k)){
						IstaRijec=false;
						break;
					}
					if(j+1<int(recenica.length())) j++;
					else break;
				}
				if(IstaRijec && int(Lista_fraza.at(i).length())==brojac){
					if(j<int(recenica.length())-1){
						if((recenica.at(j)>='A' && recenica.at(j)<='Z') || (recenica.at(j)>='a' && recenica.at(j)<='z')) continue;
					}
					if(j<int(recenica.length())-1) j--;
					j+=1-Lista_fraza.at(i).length()/2;
					for(int k=int(Lista_fraza.at(i).length())/2-1; k>=0; k--){
						recenica.at(j)=Lista_fraza.at(i).at(k);
						if(j<int(recenica.length())-1) j++;
					}
				}
			}
		}
	}
	return recenica;
}
int main ()
{
	std::string recenica;
	std::vector<std::string> fraze;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	for(;;){
		std::string fraza;
		char znak;
			for(;;){
				znak=std::cin.get();
				if(znak=='\n') break;
				fraza.push_back(znak);
			}
		if(fraza.length()==0 && znak=='\n') break;
		fraze.push_back(fraza);
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze) << std::endl;
	return 0;
}