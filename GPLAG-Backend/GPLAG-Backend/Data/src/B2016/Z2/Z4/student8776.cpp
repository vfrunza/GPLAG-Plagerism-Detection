#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


int PotencijalniKrivci (char** &spisak, std::vector<std::string> struktura)
{
	spisak = nullptr;
	try
	{
		spisak = new char* [struktura.size()];
		for (int i{};i<struktura.size();i++)
			spisak[i] = nullptr;
		
	}
	catch (...)
	{
		delete [] spisak;
		spisak = nullptr;
		
		std::bad_alloc e;
		throw e;
	}
	
	try
	{
		for (int i{};i<struktura.size();i++)
			spisak[i] = new char [struktura[i].size()+1];
	}
	catch (...)
	 {
	 	for (int i{};i<struktura.size();i++)
	 		delete [] spisak[i];
	 	delete [] spisak;
	 	spisak = nullptr;
	 	
	 	std::bad_alloc e;
	 	throw e;
	 }
	
	
	for (int i{};i<struktura.size();i++)
		{
			for (int j{};j<struktura[i].size();j++)
				spisak[i][j] = struktura[i][j];
			
			spisak[i][struktura[i].size()] = '\0';
		}
	
	
	return struktura.size();
	
}

int OdbaciOptuzbu (char** &spisak, int n, std::string ime)
{
	
	bool pronadjen = false;
	for (int i{};i<n;i++)
		{
			int broj_slova = 0;
			
			while(true)
				{
					if (spisak[i][broj_slova] == '\0')
						break;
						
					broj_slova++;
				}
				
			if (broj_slova == ime.length())
				{
					bool isti = true;
					for (int j{};j<broj_slova;j++)
						{
							if (spisak[i][j] != ime[j])
								isti = false;
						}
						
					if (isti == true)
						{
							pronadjen = true;
							
							delete [] spisak[i];
							spisak[i] = nullptr;
							
							i = n;
							
						}
				}
				
			
		}
	
	if (pronadjen == false)
		{
			std::string tekst = "Osoba sa imenom " + ime + " nije bila optuzena";
			throw std::domain_error (tekst);
		}
	
	
	int broj_praznih = 0;
	int broj_upisanih = 0;
	
	for (int i{};i<n;i++)
		{
			if (spisak[i] == nullptr)
				broj_praznih++;
			else
				broj_upisanih++;
		}
	
	
	if (broj_praznih > 10)
		{
			char **novi = nullptr;
			bool neuspjeh = false;
			try
			{
				novi = new char* [broj_upisanih];
				for (int i{};i<broj_upisanih;i++)
					novi[i] = nullptr;
			}
			catch (...)
			{
				neuspjeh = true;
				delete [] novi;
				novi = nullptr;
			}
			
			if (neuspjeh == true)
				return n;
				
			int k = 0;
			for (int i{};i<n;i++)
				{
					if (spisak[i] != nullptr)
						novi[k++] = spisak[i];
				}
				
			delete [] spisak;
			spisak = novi;
			n = broj_upisanih;
		}
	
	
	return n;
}

int DodajOptuzbu (char** &spisak, int n, std::string ime)
{
	char *upis = nullptr;
	try
	{
		upis = new char [ime.length()+1];
	}
	catch(...)
	{
		delete [] upis;
		upis = nullptr;
		
		std::bad_alloc e;
		throw e;
	}
	
	for (int i{};i<ime.length();i++)
		upis[i] = ime[i];
	upis[ime.length()] = '\0';
	
	
	bool upisan = false;
	for (int i{};i<n;i++)
		{
			if (spisak[i] == nullptr)
				{
					spisak[i] = upis;
					upisan = true;
					upis = nullptr;
				}
		}
		
	if (upisan == true)
		return n;
		
		
	char** novi = nullptr;
	try
	{
		novi = new char* [n+1];
		for (int i{};i<n+1;i++)
			novi[i] = nullptr;
	}
	catch(...)
	{
		delete [] novi;
		novi = nullptr;
		delete [] upis;
		upis = nullptr;
		
		std::bad_alloc e;
		throw e;
	}
	
	for (int i{};i<n;i++)
		novi[i] = spisak[i];
	novi[n] = upis;
	
	upis = nullptr;
	delete [] spisak;
	spisak = novi;
	n++;
	
	
	return n;
}

void IzlistajOptuzbu (char** spisak, int n)
{
	for (int i{};i<n;i++)
		{
			if (spisak[i] != nullptr)
				std::cout<<spisak[i]<<std::endl;
		}
}




int main ()
{
	try
	{
	char** spisak = nullptr;
	int n = 0;
	
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int pomocna;
	std::cin>>pomocna;
	std::cin.ignore(10000, '\n');
	
	std::cout<<std::endl<<"Unesite potencijalne krivce: ";
	for (int i{};i<pomocna;i++)
		{
			std::string s;
			std::getline(std::cin,s);
			n = DodajOptuzbu(spisak,n,s);
		}
		
	while (true)
		{
			std::cout<<std::endl;
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
			int odabir;
			std::cin>>odabir;
			std::cin.ignore(1000000, '\n');
			
			std::cout<<std::endl;
			
			if (odabir == 0)
				break;
				
			if (odabir == 1)
				{
					std::cout<<"Unesite ime novog optuzenog: ";
					std::string s;
					std::getline(std::cin,s);
					
					n = DodajOptuzbu(spisak,n,s);
				}
			
			if (odabir == 2)
				{
					std::cout<<"Unesite ime koje zelite izbaciti: ";
					std::string s;
					std::getline(std::cin,s);
					
					n = OdbaciOptuzbu(spisak,n,s);
				}
				
			if (odabir == 3)
				IzlistajOptuzbu(spisak,n);
				
		}
		
	for (int i{};i<n;i++)
		delete [] spisak[i];
	delete [] spisak;
	spisak = nullptr;
	}
	catch (std::domain_error e)
	{
		std::cout<<e.what();
	}
	catch (std::bad_alloc)
	{
		std::cout<<"Nedovoljno memorije!";
	}
	
	
	
	
	return 0;
}