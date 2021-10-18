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
#include <stdexcept>


bool ista_osim_engleskog_alafabeta(std::vector<std::string> provjera)
{
	for(int i=0;i<provjera.size();i++)
	{
		std::string temp;
		temp=provjera[i];
		for(int j=0;j<temp.length();j++)
		if(temp[j]!='\n')
		if(temp[j]<'A' || (temp[j]>'Z' && temp[j]<'a') || temp[j]>'z')
		return true;

	}
	return false;
}



std::vector<std::string> Unos_fraza()
{
	std::vector<std::string >vrati ;
	char znak1,znak2;
	int i=0;
	std::string temp;
	while (1) {
		znak1=std::cin.get();
		
		if(znak1=='\n')
		{	znak2=std::cin.get();
			vrati.resize(i+1);
			vrati[i]=temp;
			i++;
			temp.resize(0);
			if(znak2=='\n')
			break;
			temp.push_back(znak2);
		}
		if(znak1!='\n')
		temp.push_back(znak1);
	}
	if(vrati.size()==1 && vrati[0].length()==0)
	vrati.resize(0);
	
	return vrati;
}


bool da_li_je_alfabet_slovo(char s)
{
	
	if(s<'A' || (s>'Z' && s<'a') || s>'z')
	return false;
	return true;
	
}


std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>popis)
{
	if(popis.size()==0)
	{
		for(int i=0;i<s.size();i++)
		{
		if(i==0 || (da_li_je_alfabet_slovo(s[i-1])==false && da_li_je_alfabet_slovo(s[i])==true) )
		{
			
			char slovo(s[i]);
			s.erase(s.begin()+i);
			while (da_li_je_alfabet_slovo(s[i])==true && i<s.size()) 
			{
				i++;
			}
			s.insert(s.begin()+i,slovo);
			s.insert(s.begin()+i+1,'a');
			s.insert(s.begin()+i+2,'y');
		}
	}
	
	return s;
	
	}
	
	if(ista_osim_engleskog_alafabeta(popis)==true)
		{
			throw std::domain_error("Nekorektan izbor rijeci");
		
		}
		
	int poklapa=1;
	std::string temp_string;
	int temp_broj;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<popis.size();j++)
		{	temp_string=popis[j];
			
			if(s[i]==temp_string[0] &&(i==0 || da_li_je_alfabet_slovo(s[i-1])==false))
			{	poklapa=1;
				temp_broj=i;
				for(int k=0;k<temp_string.length();k++)
				{
					if(s[temp_broj]!=temp_string[k])
					poklapa=0;
					if(temp_broj<s.length())
					temp_broj++;
				}
				
				if(poklapa==1)
				{
					char slovo;
					slovo=s[i];
					s.insert(s.begin()+temp_broj,slovo);
					s.insert(s.begin()+temp_broj+1,'a');
					s.insert(s.begin()+temp_broj+2,'y');
					s.erase(s.begin()+i);
					i--;
				}
			}
		}
	}
	
	return s;
}

std::string ObrniFraze(std::string s, std::vector<std::string>popis)
{
	int poklapa=1;
	std::string temp_string;
	int temp_broj;
	
	
		for(int j=0;j<popis.size();j++)
		{	temp_string=popis[j];
			
			for(int i=0;i<s.size();i++)	
			{
				
				if(s[i]==temp_string[0])
				{
					poklapa=1;
					temp_broj=i;
					for(int k=0;k<temp_string.length();k++)
					{
						if(s[temp_broj]!=temp_string[k])
						poklapa=0;
						if(temp_broj<s.length())
						temp_broj++;
					}
				
					if(poklapa==1)
					{
					temp_broj--;
					while (i<=temp_broj) 
					{
						char slovo;
						slovo=s[i];
						s[i]=s[temp_broj];
						s[temp_broj]=slovo;
						i++;
						temp_broj--;
						
					}
				}
				
				}
			}	
	   }
	return s;
}


int main ()
{

	std::string tekst;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,tekst);
	std::cout<<"Unesite fraze: ";
	auto fraze=Unos_fraza();
    try{
   	auto ispis2=IzmijeniUPigLatin(tekst,fraze);
  	std::cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i=0;i<ispis2.size();i++)
	std::cout<<ispis2[i];
    }
    catch(std::domain_error izuzetak){
    	std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	std::cout<<"\n";
	std::cout<<"Recenica nakon obrtanja fraza: ";
	auto ispis=ObrniFraze(tekst,fraze);
	for(int i=0;i<tekst.size();i++)
	std::cout<<ispis[i];
	
	return 0;
	
}