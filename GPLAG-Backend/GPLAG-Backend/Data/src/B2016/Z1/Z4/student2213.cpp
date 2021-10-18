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
using namespace std;


int DaLiSadrzi(string Uneseni, string Sadrzani)
{
	int rezultat = 0;
	int pozicija_sadrzanog = 0;
	int trazena_pozicija = Sadrzani.length() - 1;
	for(int i = 0; i < (Uneseni.length()-1); i++)
	{
		if(Uneseni[i] == Sadrzani[pozicija_sadrzanog])
		{
			pozicija_sadrzanog++;
			if(pozicija_sadrzanog == trazena_pozicija) rezultat = (i+1) - trazena_pozicija;
		}
		else
		{
			pozicija_sadrzanog = 0;
		}
	}
	
	return rezultat;
}

string Obrni(string Uneseni)
{
	string rezultat;
	int pos = 0;
	
	for(int i = (Uneseni.length()-1) ; i >= 0; i--)
	{
		rezultat = rezultat + Uneseni[i];
		pos++;
	}
	
	return rezultat;
}

string ObrniFraze(string Uneseni, vector<string> fraze)
{ 
	string rezultat;
	rezultat = Uneseni;
	int pos;
	string podniz;
	
	for(int i = 0; i < fraze.size(); i++)
	{ int brojac=0;
		pos = 0;
		
		do
		{
		pos = DaLiSadrzi(rezultat, fraze[i]);
		string fraza = fraze[i];
		
		
		if( (pos != 0)) 
		{
			
			
			podniz = rezultat.substr(pos, fraze[i].length());
			podniz = Obrni(podniz);
			
			
			for(int j = 0; j < fraze[i].length() ; j++)
			{
				
				rezultat[pos] = podniz[j];
				pos++; 
				
			}
		}
		else if(rezultat[0] == fraza[0])
		{
			bool provjera = true;
			for(int j = 0; j < fraza.length(); j++)
			{
				if(fraza[j] != rezultat[j]) provjera = false;
			}
			if(provjera)
			{
				podniz = rezultat.substr(pos, fraze[i].length());
				podniz = Obrni(podniz);
				
				for(int j = 0; j < fraze[i].length(); j++)
				{
					rezultat[pos] = podniz[j];
					pos++;
				}
			}
		}
		brojac++;
		}while(pos != 0 && brojac<5); 
	}
	
	return rezultat;
}

string IzmijeniUPigLatin(string Uneseni, vector<string> fraze)
{
	
	for(int i=0;i<fraze.size();i++){
		for(int j=0;j<fraze[i].length();j++){
			
			if(fraze[i][j]<'A'|| (fraze[i][j]> 'Z' && fraze[i][j]< 'a') || fraze[i][j]> 'z')
			throw
				std::domain_error("Nekorektan izbor rijeci\n");
				
			
		}
	}
	string rezultat;
	
	rezultat = Uneseni;
	
	int pos;
	
	string podniz;
	
	for(int i = 0; i < fraze.size(); i++)
	{
		pos = 0;
		
		do
		{
			
			pos = DaLiSadrzi(rezultat, fraze[i]);
			string fraza = fraze[i];
			
			if(pos != 0)
			{
				string pomocni;
				pomocni = fraza.substr(1, (fraza.length()-1));
				pomocni = pomocni + fraza[0];
				
				for(int j = 0; j < fraze[i].length(); j++)
				{
					rezultat[pos] = pomocni[j];
					pos++;
				}
				rezultat.insert(pos, "ay");
				
			}
			else if(fraza[0] == rezultat[0]) 
			{
			
				bool provjera = true;
				for(int j = 0; j < fraza.length(); j++)
				{
					if(fraza[j] != rezultat[j]) provjera = false;
				}
				
				if(provjera)
				{
					string pomocni; 
					pomocni = fraza.substr(1, (fraza.length()-1));
					pomocni = pomocni + fraza[0];
					
					for(int j = 0; j < fraze[i].length(); j++)
					{
						rezultat[pos] = pomocni[j];
						pos++;
					}
					
					rezultat.insert(pos, "ay");
				}
				
			}
			
		}while(pos != 0);
		
	}
	
	return rezultat;
}

int main ()
{
	
	cout << "Unesite recenicu: ";
	
	string recenica;
	getline(cin, recenica);
	
	vector<string> fraze;
	string temp = " ";
	
	cout << "Unesite fraze: ";
	while(temp.length() > 0)
	{
		getline(cin, temp);
		fraze.push_back(temp);
	}
	
	try{
	string PigLatin = IzmijeniUPigLatin(recenica, fraze);
		cout << "Recenica nakon PigLatin transformacije: " << PigLatin << endl;
		}

	catch(std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
		cout<<endl;
	}
	
	string Obrnuta = ObrniFraze(recenica, fraze);
	

	cout << "Recenica nakon obrtanja fraza: " << Obrnuta << endl;
	
	return 0;
}