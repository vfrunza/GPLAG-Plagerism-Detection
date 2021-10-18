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

std::string ObrniFraze (std::string s, std::vector<std::string> vs)
{
/*	for (int i=0; i<vs.size(); i++)
	{
		for (int j=0; j<s.length(); j++)
		{
			if (vs[i]==s[j])
			{
				for (int k=s[j].length(); k>=0; k--)
				{
					s[k]=temp;
					temp=
					
				}
			}
		}
	}*/
	return s;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::string fr;
	std::vector<std::string> fraze;
	std::cout << "Unesite fraze: ";
	do {
		std::getline(std::cin, fr) ;
		fraze.push_back(fr);
	} while ()
	
	std::cout << "Recenica nakon PigLatin transformacije: ";
	std::cout << IzmijeniUPigLatin (recenica, fraza);

	std::cout << std::endl;

	std::cout << "Recenica nakon obrtanja fraze: ";
	std::cout << ObrniFraze (recenica, fraza);
	
	return 0;
}





