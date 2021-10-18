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

std::string ObrniFrazu(std::string s, std::vector<std::string> spisak){
	std::string vrati(s);
	for(int i=0; i<spisak.size(); i++){
		for(int j=0; j<spisak[i].size(); j++){
			for(int k=0; k<vrati.size(); k++){
				if(vrati[k]==spisak[i][j]){
					int zapamti(k), br(0);
					while(vrati[k]==spisak[i][j]){
						br++;
						k++;
						j++;
						if(br==spisak[i].size()){
							char pomocna;
							for(int b=zapamti; b<j/2; b++){
								pomocna=vrati[b];
								vrati[b]=vrati[k];
								vrati[k]=pomocna;
							}
						}
						j=0;
						break;
					}
				}
				if(k==vrati.size()-1) break;
			}
			break;
		}
	
	}
	
	return vrati;
}








int main ()
{
	
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	//std::cin.ignore(10000, '\n');
	std::getline(std::cin, recenica);
	std::cout<<"Unesite skupinu rijeci, odnosno fraza: ";
	std::vector<std::string> spisak;
	for(;;){
		//std::cin.ignore(10000, '\n');
		std::string fraza;
		std::getline(std::cin, fraza);
		if(std::cin.peek()=='\n') break;
		else spisak.push_back(fraza);
	}
	
	std::string rez (ObrniFrazu(recenica, spisak));
	std::cout<<std::endl;
	for(int i=0; i<rez.size(); i++) std::cout<<rez[i];
	return 0;
}