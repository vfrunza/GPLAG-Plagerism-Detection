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
int PocetakPodstringa(std::string s1, std::string s2, int start){
	int istina=1;
	for(int i=start; i<s1.size(); i++){
		if(s1.at(i)==s2.at(0)){
			for(int j=0; j<s2.size(); j++){
				if(s1.at(i+j)!=s2.at(j)){
					istina=0;
					break;
				}
			}
			if(istina) return i;
			istina=1;
		}
	}
	return -1;
}
int KrajPodstringa(std::string s1, std::string s2,int start){
	int istina=1;
	for(int i=start; i<s1.size(); i++){
		if(s1.at(i)==s2.at(0)){
			int j;
			for(j=0; j<s2.size(); j++){
				if(s1.at(i+j)!= s2.at(j)) {
					istina=0;
					break;
				}
			}
			if(istina) return i+j;
			istina=1;
		}
	}
	return -2;
}

void NapraviPolindrom(std::string s, std::vector<std::string> v){
	for(int k=0; k<v.size(); k++){
		std::string poms(v.at(k));
		for(int i=0; i<s.size(); i++){
			if(s.at(i)==poms.at(0)){
				int poc(PocetakPodstringa(s,poms,i)), kraj(KrajPodstringa(s,poms,i));
				if(poc!=-1 && kraj!=-2){
					int prosirenje(kraj-poc);
					//for(int j=0; j<prosirenje; j++) s.push_back(' '); //dodaje elemente
					//premjestiti razmake 
					int d=s.size();
					s.resize(d+prosirenje);
					for(int w=s.size()-1; w>=(kraj+ prosirenje); w--){
						s.at(w)=s.at(w-prosirenje);
					}
					int br=0;
					for(int z=kraj; z<kraj+prosirenje; z++){
						s.at(z)=s.at(z-1-2*br);
						br++;
					}
				}
			}
		}
	}
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string> vektor_stringova;
	std::cout<<"Unesite spisak rijeci, odnosno fraza (ENTER za novu rijec, dva puta ENTER za kraj): ";
	std::string pomocni;
	for(;;){
		std::getline(std::cin,pomocni);
		if(pomocni!=""){
			vektor_stringova.push_back(pomocni);
		} else break;
	}
	
	
	return 0;
}