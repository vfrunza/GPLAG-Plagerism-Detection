//B 2016/2017, Zadaća 1, Zadatak 4

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;
using std::getline;

// Funkcija IzmijeniUPigLatin modifikuje rijeci stringa recenica 
// koje se nalaze u vektoru stringova fraze po pravilu PigLatin
string IzmijeniUPigLatin(string recenica, vector<string> fraze)
{
	for(int i=0; i<fraze.size(); i++)
	{
		string rijec(fraze[i]);
		for(int j=0; j<rijec.length(); j++)
		{
			if(!((rijec[j]>='A' && rijec[j]<='Z') || (rijec[j]>='a' && rijec[j]<='z'))) 
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(fraze.size()==0)
	{
		bool nije_slovo(true);
		string rijec;

		for(int i=0; i<recenica.length(); i++)
		{
			if(!((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && nije_slovo) continue;
			if((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))
			{
				nije_slovo=false;
				rijec+=recenica[i];
			}
			if(!((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && nije_slovo==false) 
			{
				nije_slovo=true;
				fraze.push_back(rijec);
				rijec="";
			}
			if(i==recenica.length()-1 && ((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) 
			{
				nije_slovo=true;
				fraze.push_back(rijec);
			}
		}
	}
	
	for(int i=0; i<fraze.size(); i++)
	{
		int vel_fraz(fraze[i].size());
		bool pocetak(true);
		for(int j=0; j<recenica.length(); j++)
		{
			if((fraze[i]==recenica.substr(j, vel_fraz)) && vel_fraz>1)
			{
				if(!((recenica[j+vel_fraz]>='A' && recenica[j+vel_fraz]<='Z') || (recenica[j+vel_fraz]>='a' && recenica[j+vel_fraz]<='z')) && ((pocetak==false && !((recenica[j-1]>='A' && recenica[j-1]<='Z') || (recenica[j-1]>='a' && recenica[j-1]<='z'))) || (j+vel_fraz)==recenica.length()))
				{
					string temp(recenica.substr(j, 1));
				
					recenica.erase(recenica.begin()+j);
					recenica.insert(recenica.begin()+(vel_fraz+j-1), temp[0]);
					recenica.insert(recenica.begin()+(vel_fraz+j), 'a');
					recenica.insert(recenica.begin()+(vel_fraz+j+1), 'y');
				}
				if(pocetak)
				{
					string temp(recenica.substr(j, 1));
				
					recenica.erase(recenica.begin()+j);
					recenica.insert(recenica.begin()+(vel_fraz+j-1), temp[0]);
					recenica.insert(recenica.begin()+(vel_fraz+j), 'a');
					recenica.insert(recenica.begin()+(vel_fraz+j+1), 'y');
				}
			}
			if((fraze[i]==recenica.substr(j, vel_fraz)) && vel_fraz==1)
			{
				if(!((recenica[j+vel_fraz]>='A' && recenica[j+vel_fraz]<='Z') || (recenica[j+vel_fraz]>='a' && recenica[j+vel_fraz]<='z')) && ((pocetak==false && !((recenica[j-1]>='A' && recenica[j-1]<='Z') || (recenica[j-1]>='a' && recenica[j-1]<='z'))) || (j+vel_fraz)==recenica.length()))
				{
					recenica.insert(recenica.begin()+(vel_fraz+j), 'a');
					recenica.insert(recenica.begin()+(vel_fraz+j+1), 'y');
				}
				if(pocetak)
				{
					string temp(recenica.substr(j, 1));
				
					recenica.erase(recenica.begin()+j);
					recenica.insert(recenica.begin()+(vel_fraz+j-1), temp[0]);
					recenica.insert(recenica.begin()+(vel_fraz+j), 'a');
					recenica.insert(recenica.begin()+(vel_fraz+j+1), 'y');
				}
			}
			pocetak=false;
		}
	}
	return recenica;
}

// Funkcija ObrniFraze obrce sve podstringove iz vektora stringova 
// fraze koje pronadje u stringu recenica
string ObrniFraze(string recenica, vector<string> fraze)
{
	for(int i=0; i<fraze.size(); i++)
	{
		int vel_fraz(fraze[i].size());
		for(int j=0; j<recenica.length(); j++)
		{
			if(fraze[i]==recenica.substr(j, vel_fraz) && vel_fraz>1)
			{
				for(int k=0; k<vel_fraz/2; k++)
				{
					char temp(recenica[k+j]);
					recenica[k+j]=recenica[vel_fraz-1-k+j];
					recenica[vel_fraz-1-k+j]=temp;
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	string recenica;
	cout << "Unesite recenicu: ";
	getline(cin, recenica);

	string rijeci;
	vector<string> fraze;
	cout << "Unesite fraze: ";
	do
	{
		getline(cin, rijeci);
		if(rijeci!="") fraze.push_back(rijeci);
		
	} while(rijeci!="");
	
	try
	{
		string rec_pig(IzmijeniUPigLatin(recenica, fraze));
		cout << "Recenica nakon PigLatin transformacije: ";
		for(int i=0; i<rec_pig.length(); i++)
			cout << rec_pig[i];
	
		string rec_obrnuta(ObrniFraze(recenica, fraze));
		cout << endl <<"Recenica nakon obrtanja fraza: ";
	
		for(int i=0; i<rec_obrnuta.length(); i++)
		cout << rec_obrnuta[i];
	}
	catch(std::domain_error izuzetak)
	{
		cout << "Izuzetak: " << izuzetak.what() << endl;
		
		string rec_obrnuta(ObrniFraze(recenica, fraze));
		cout << endl <<"Recenica nakon obrtanja fraza: ";
	
		for(int i=0; i<rec_obrnuta.length(); i++)
		cout << rec_obrnuta[i];
	}
	return 0;
}
