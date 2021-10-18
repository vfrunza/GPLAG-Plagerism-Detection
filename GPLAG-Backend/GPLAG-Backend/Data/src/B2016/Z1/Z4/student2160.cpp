/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
		OK!!!!!!!!!!!!!!
*/

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

std::string ObrniFraze(std::string vektor, std::vector<std::string> matrica)
{
	for(int i = 0; i < matrica.size(); i++)
	{
		int j = 0; 
		int k = 0;
	
		while(k < vektor.size())
		{
			int kopija = k;
			int indeks = k;
			while(j < matrica.at(i).size() && kopija < vektor.size() && matrica.at(i).at(j) == vektor.at(kopija))
			{
				j++;
				kopija++;
			}
		
			if(j == matrica.at(i).size() && kopija > indeks)
			{	
				for(int b = 0; b < (matrica.at(i).size() / 2); b++)
				{
					char temp(vektor.at(indeks));
					vektor.at(indeks) = vektor.at(kopija - 1);
					vektor.at(kopija - 1) = temp;
					indeks++;
					kopija--;
				}
			}
			j = 0;
			k++;
		}
	}
	return vektor;
}

bool slovo(char a)
{
	if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return true; // true - slovo
		
	return false; // false - nije
}
std::string IzmijeniUPigLatin(std::string vektor, std::vector<std::string> matrica)
{
	
	for(int i = 0; i < matrica.size(); i++)
		for(int j = 0; j < matrica.at(i).size(); j++)
			if((matrica.at(i).at(j) < 'A' || matrica.at(i).at(j) > 'Z') && (matrica.at(i).at(j) < 'a' || matrica.at(i).at(j) > 'z'))
				throw std::domain_error("Nekorektan izbor rijeci");
				
	if(matrica.size() == 0)
	{
		bool razmak = true;
		int i(0), p(0);
		
		while(i < vektor.size())
		{
			if(slovo(vektor.at(i)) == false)
				razmak = true;
				
			else if(razmak == true)
			{
				razmak = false;
				p = i;
				
				while(p < vektor.size() && slovo(vektor.at(p)) == true)
					p++;
					
				std::string s1 = vektor.substr(0, i);
				std::string s2 = vektor.substr(i, p - i);
				std::string s3 = vektor.substr(p);
				vektor = s1 + s2.substr(1) + s2.at(0) + "ay" + s3;
			}
			i++;
		}
	}
	
	else
	{
		for(int j = 0; j < matrica.size(); j++)
		{
			bool razmak = true;
			int i(0), p(0);
		
			while(i < vektor.size())
			{
				if(slovo(vektor.at(i)) == false)
					razmak = true;
					
				else if(razmak)
				{
					razmak = false;
					p = i;
					
					while(p < vektor.size() && slovo(vektor.at(p)) == true)
						p++;
						
					std::string s1 = vektor.substr(0, i);
					std::string s2 = vektor.substr(i, p - i);
					std::string s3 = vektor.substr(p);
					
					if(s2 == matrica.at(j))
						vektor = s1 + s2.substr(1) + s2.at(0) + "ay" + s3;
				}
				i++;
			}
		}
	}
	return vektor;
}

int main()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::vector<std::string> idk;
	std::cout << "Unesite fraze: ";
	for(; ;)
	{
		std::string vek;
		std::getline(std::cin, vek);
		
		if(vek == "")
			break;
			
		else
			idk.push_back(vek);
	}
	
	try
	{
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s, idk);
	}
	catch(...)
	{
		std::cout << "Izuzetak: Nekorektan izbor rijeci" << std::endl;;
	}
	
	std::cout << "\nRecenica nakon obrtanja fraza: " << ObrniFraze(s, idk) << std::endl;
	return 0;
}

int main_at()
{
	try
    {
        std::string s{"Svaka elementarna funkcija je neprekidna gdje je definisana."};
        std::cout <<  ObrniFraze (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
        std::cout <<  IzmijeniUPigLatin (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
}