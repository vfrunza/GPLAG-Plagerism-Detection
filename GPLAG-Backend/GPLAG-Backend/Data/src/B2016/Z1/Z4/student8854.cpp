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
#include <stdexcept>

bool slovo (char znak)
{
   return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z'));
}



std::string ObrniFraze (std::string ulaz, std::vector<std::string> tablica)
{
	for(int i=0;i<tablica.size();i++)
	{
		
			
			
			int brojac=0;
			int k=0;
			
			while(k<ulaz.size())
			{
			while(k<ulaz.size() && ulaz[k]!=tablica[i][0])
			{k++;}
			if(k==ulaz.size())
			continue;
			brojac=0;
			for(int j=0;j<tablica[i].size();j++)
			{
				if(k+j<ulaz.size() && ulaz[k+j]==tablica[i][j])
				brojac++;
			}
			if(brojac==tablica[i].size())
			{
				for(int j=tablica[i].size()-1;j>=0;j--)
				{
					ulaz[k+j]=tablica[i][tablica[i].size()-1-j];
					
				}
				
			}
			k++;
			}
	}
	

	return ulaz;
}


std::string IzmijeniUPigLatin(std::string ulaz,std::vector<std::string> tablica)
{
	for(int i=0;i<tablica.size();i++)
	{
		
			for(int j=0;j<tablica[i].size();j++)
			{
				
				if(!(slovo(tablica[i][j])))
				throw std::domain_error("Nekorektan izbor rijeci");
			}
	}
	if(tablica.size()==0)
	{
		for(int k=0;k<ulaz.size();k++)
		{
			
			int pocetni=0;
			while(k<ulaz.size() && !(slovo(ulaz[k])))
			k++;
			if(k<ulaz.size())
			pocetni=k;
			else
			return ulaz;
			while(k<ulaz.size() && (slovo(ulaz[k])))
			k++;
			
				char pocetak=ulaz[pocetni];
				for(int t=pocetni;t<k-1;t++)
				ulaz[t]=ulaz[t+1];
				ulaz[k-1]=pocetak;
				ulaz.resize(ulaz.size()+2);
				for(int t=ulaz.size()-1;t>k+1;t--)
				ulaz[t]=ulaz[t-2];
				ulaz[k++]='a';
				ulaz[k]='y';
			
			
		}
		return ulaz;
	}
	
	for(int k=0;k<ulaz.size();k++)
	{
		if(k>=1 && (slovo(ulaz[k-1])))
		continue;
		for(int i=0;i<tablica.size();i++)
		{
			if(tablica[i].size()==0)
			continue;
			int brojac(0);
			int j;
			for(j=0;j<tablica[i].size();j++)
			{
				
				if(k+j<ulaz.size() && ulaz[k+j]==tablica[i][j])
				brojac++;
				else
				break;
				
			}
			if(brojac==tablica[i].size() && (k+j>=ulaz.size() || !(k+j<ulaz.size() && (slovo(ulaz[k+j])))))
			{
				char prva=ulaz[k];
				for(int j=0;j<brojac-1;j++)
				ulaz[k+j]=ulaz[k+j+1];
				ulaz[k+brojac-1]=prva;
				ulaz.resize(ulaz.size()+2);
				for(int j=ulaz.size()-1;j>k+brojac-1;j--)
				ulaz[j]=ulaz[j-2];
				ulaz[k+brojac]='a';
				ulaz[k+brojac+1]='y';
				k+=2;
			}
		
		}
	}
	
	
	
	
	return ulaz;
}






int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string ulaz;
	std::getline(std::cin,ulaz);
	std::cin.clear();
	
	std::cout<<"Unesite fraze: ";
	std::string ubac;
	std::vector<std::string>tablica;
	while((std::getline(std::cin,ubac)) && ubac.size()!=0)
	tablica.push_back(ubac);
	try
	{
	std::string rec1=IzmijeniUPigLatin(ulaz,tablica);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<rec1;
	}
	catch(std::domain_error izuzetak)
	{
	std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::string rec2=ObrniFraze(ulaz,tablica);
	std::cout<<std::endl<< "Recenica nakon obrtanja fraza: "<<rec2;
	
	
	
	
	
	
	return 0;
}


