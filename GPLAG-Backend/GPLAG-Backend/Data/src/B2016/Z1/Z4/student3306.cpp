/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>

void IzvrniString(std::string &s){
	char pom;
	for (int i=0;i<((int)(s.length()/2));i++){
		pom=s[i];
		s[i]=s[s.length()-i-1];
		s[s.length()-i-1]=pom;
	}
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> popis_rijeci){
	std::string nova_recenica;
	for (int i=0;i<recenica.size();i++){
		for (int j=0;j<popis_rijeci.size();j++){
			int br(0);
			if (recenica[i]==popis_rijeci[j][br]){
				int pocetak_rijeci(i);
				while(recenica[i]==popis_rijeci[j][br]){
					i++;
					br++;
					if (br==(popis_rijeci[j].size()-1))
						break;
				}
				if (br==popis_rijeci[j].size()-1)
					for (int k=br;k>=pocetak_rijeci;k--)
						nova_recenica.push_back(recenica[k]);

				
			}
			else{
				nova_recenica.push_back(recenica[i]);

			}
			
		}
		if (i==recenica.size()-1)
			break;
	}
	return nova_recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin,recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> vektor_fraza;
	std::string fraza1;
	while (1){
		char prvi;
		prvi=std::cin.peek();
		if (prvi=='\n')
			break;
		std::getline(std::cin,fraza1);
		vektor_fraza.push_back(fraza1);
	}
	std::string obrnuta_recenica;
	obrnuta_recenica=ObrniFraze(recenica, vektor_fraza);
	std::cout << "Recenica nakon obrtanja fraza: ";
	std::cout << obrnuta_recenica;
	return 0;
}