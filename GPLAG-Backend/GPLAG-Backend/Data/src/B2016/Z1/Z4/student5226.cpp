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
std::string ObrniFraze (std::string recenica, std::vector<std::string> vek)
{
	int i,a;
	for(i=0;i<recenica.length();i++)
	{
		for(j=0;j<vek.size();j++)
		{
			if(recenica[i]==vek[j])
		{
			int k=i;
			while(recenica[k]==vek[j])
			{
				k++;
			}
			
		}
			}
			
			
		}
		
		if()
	}
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> vek)
{
	
}
int main ()
{
	std::string tekst.obrni, pretvori;
	std::cout<<"Unesite recenicu: ";
	std::cin.ignore();
	std::getline(std::cin, tekst);
	std::vector<std::string> v1.v2;
	int i;
	std::cout<<"Unesite spisak rijeci koje zelite obrnuti: ";
	for(i=0;i<v1.size();i++)
	{
		std::getline(std::cin,v1[i]);
	}
	
	std::cout<<"Unesite spisak rijeci: ";
	for(i=0;i<v2.size();i++)
	{
		std::getline(std::cin, v2[i]);
	}
	
	obrni=ObrniFraze(tekst,v1);
	std::cout<<"Novi string glasi: "<<obrni;
	std::cout<<std::endl;
	pretvori=IzmijeniUPigLatin(tekst,v2);
	std::cout<<"Novi string je: "<<pretvori;
	return 0;
}