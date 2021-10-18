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
std::string IzvrniRijec(std::string s)
{
	for(int i=0,j=(s.length()-1); i<j; i++, j--) {
		char temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
	return s;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> vektorRijeci)
{
std::string nova;
	for(int j=0; j<vektorRijeci.size(); j++) {
		for(int i=0; i<recenica.length()-1; i++)	{
		//	std::cout<<vektorRijeci[j].size()<<std::endl;
			if(recenica.substr(i,vektorRijeci[j].size())==vektorRijeci[j])
				{
					
				std::string izvrnut=IzvrniRijec(recenica.substr(i, vektorRijeci[j].size()));
				for(int k=0; k<i; k++){
				nova[k].push_back(recenica[k]);
					}
					int z=0;
				for(int k=i; k<i+izvrnut.length()-1;k++)	{
					nova[k].push_back(izvrnut[z]);
					z++;
				}
				for(int k=izvrnut.length()-1; k<recenica.size()-izvrnut.length()-1-i; k++)
				nova[k].push_back(recenica[k]);
			
					// int z(0);
					// for(int k=i; k<izvrnut.length()+1; k++) {recenica[k]=izvrnut[z]; z++;
				
					}	std::cout<<std::endl<<nova;
		//	std::cout<<izvrnut;
			}
			
			

		}
//	}

	return recenica;
}


int main ()
{
	std::string recenica="Danas je divan dan";
	std::vector<std::string> vektorRijeci {"je", "divan"};
	std::string proba=ObrniFraze(recenica, vektorRijeci);

	// for(int i=0; i<recenica.length()-1; i++){
	// 	for(int j=0; j<vektorRijeci.size(); j++){

	// 			std::cout<<recenica.substr(i, vektorRijeci.size());
	// 			std::cout<<std::endl;




	// 	}
	// }


	// std::string s;
//std::cout<<"Unesite tekst: ";
//std::getline(std::cin, s);
//std::cout<<s<<std::endl;
//IzvrniRijec(s);
//std::cout<<s<<std::endl;
	return 0;
}