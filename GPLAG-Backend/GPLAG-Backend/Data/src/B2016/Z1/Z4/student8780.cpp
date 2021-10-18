#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdexcept>

std::string ObrniFraze (std::string s, std::vector<std::string> v)
{

	std::string recenica(s);
	std::string pomocni;
	std::string rijec;
	int q(0);

	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			rijec=v[i];

			bool isti (true);
			q=0;  // q je pomocni brojac

			for (int k=0; k<rijec.length(); k++) {

				if (recenica[j]==rijec[k]) {
					j++;
					q++;
				} else {
					isti=false;
					break;
				}

			}

			if (isti) {
				pomocni.resize(rijec.length());

				for (int k=0; k<rijec.length(); k++)

				{
					pomocni[k]=rijec[rijec.length()-1-k];

				}

				for (int k=0; k<pomocni.length(); k++)

				{
					recenica[abs(q-j)+k]=pomocni[k];
				}

			}
		}

	}
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica,std::vector<std::string> v)

{
	std::string slog = "ay";
	std::string rijec;
	std::string pomocni;
	std::string prvo_slovo;
	std::string razmak = " ";
	int q(0);
	int broj(recenica.size());
	std::vector<std::string>drugi_pomocni;
	int d(-1);
	int w(-1);
	std::string pomoc;

	if (v.size()==1) // jer se unosi sa dva znaka ENTER, tako da je u vektoru jedan znak '\n'
	{
		for (int i=0;i<=recenica.size();i++)
		    
		{  
		   w++;
			if (recenica[i]==razmak[0] && ((recenica[i+1]>'A' && recenica[i]<'Z') || (recenica[i+1]>'a' && recenica[i+1]<'z'))|| i==recenica.length())
			{      d++;
			
			v.resize(d);
			pomoc.resize(w);
				  // i-w je mjesto odakle pocinjemo brojati koliko slova ima u rijeci
				     for (int t=0;t<w;t++)
			{     if (recenica[abs(i-w+t)]<'A' || recenica[abs(i-w+t)]>'z') continue;
			
				  pomoc[t]=recenica[abs(i-w+t)]; // u pomocni ubacujemo sve rijeci
			        
				
			} v.push_back(pomoc);
				w=-1;
				pomoc.resize(0);
			}
		}  
		
		   
	}
	for (int i=0; i<v.size(); i++)
	{
		for (int j=0; j<recenica.length(); j++) 
		{
			rijec=v[i];
			bool isti(false);

			q=0;
           
             for (int p=0;p<rijec.length();p++)
             {
             	if (rijec[p]==razmak[0]) throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
             }
             
			if (rijec[0]==recenica[j] && (j==0 || recenica[j-1]==razmak[0]))
			{

				for (int k=0; k<rijec.length(); k++)
				{

					if (recenica[j]==rijec[k]) 
					{
						j++;
						q++;

						if (k==rijec.length()-1)
					{   if ((recenica[j]==' ' || recenica[j]=='.' || recenica[j]==':' || recenica[j]==',' || recenica[j]==recenica[recenica.length()]) )
							isti=true;
					}		
							

					}

					else 
					{

						break;
					}

				}
			}

			if (isti) 
			{
				pomocni.resize(rijec.length()+2);
				prvo_slovo=rijec[0];
				pomocni[rijec.length()-1]=rijec[0];

				for (int k=0; k<rijec.length()-1; k++) 
				{


					pomocni[k]=rijec[k+1];


				}

				pomocni[rijec.length()] = slog[0];
				pomocni[rijec.length()+1]=slog[1];

				recenica.resize(slog.length()+recenica.length());


				for (int k=recenica.length()-1; k>=j; k--)
				{
					recenica[k]=recenica[k-2];
				}

				for (int k=0; k<pomocni.length(); k++)
				{
					recenica[abs(q-j)+k]=pomocni[k];
				}
			}
		}
	}

	return recenica;
}
int main ()
{
	std::string recenica;
	std::string slova;
	std::vector<std::string> rijeci ;
	std::string obrnuta_recenica;
	int broj;
	std::string nl("\n\n");
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin,recenica);

	std::cout << "Unesite fraze: ";

	for (;;) 
	{
		std::getline(std::cin,slova);
		rijeci.push_back(slova);
		
		if (std::cin.peek()=='\n' && std::cin.peek()=='\n')
			break;
	}

	
	
	try
	 {
	 	std::string latin(IzmijeniUPigLatin(recenica,rijeci));

	std::cout << "Recenica nakon PigLatin transformacije: ";
	
	for (int i=0; i<latin.length(); i++) 
	{
		std::cout << latin[i];
	}
	
}
catch (std::domain_error izuzetak)
{
	std::cout << izuzetak.what();
}
std::cout << std::endl;

	obrnuta_recenica=ObrniFraze(recenica,rijeci);
	std::cout << "Recenica nakon obrtanja fraza: ";
	
	for (int i=0; i<obrnuta_recenica.length(); i++) 
	{
		std::cout << obrnuta_recenica[i];
	}


	return 0;
}