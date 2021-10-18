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

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::domain_error;


string ObrniFraze (string recenica, vector<string>niz)
{
	string obrnuto, temp;
	vector <string> kopija;
	int count, poc, kraj;
	char zamijeni;
		
	for (int m=0; m<niz.size(); m++)
	{
		for (int s=0; s<niz[m].size(); s++)
		{
			if ((niz[m][s]>=65 && niz[m][s]<=90)||(niz[m][s]>=97 && niz[m][s]<=122)||(niz[m][s]==32))
			{
				continue;
			}
			else throw domain_error("Nekorektan izbor rijeci");
		}
	}

	for (int k=0; k<niz.size(); k++)
	{
		temp=niz[k];
		count=0;
		
		for (int h=0; h<recenica.length(); h++)
		{
			if (temp[0]==recenica[h])
			{
				poc=h;
				int g=0;
				while (count<temp.length())
				{
					if (temp[g]==recenica[h+g])
					{
						count++;
					}
			
					else
					{
						count=0;
						break;
					}
					g++;
				}
				kraj=h+g-1;
				if (count==temp.length())
				{
					while (poc<kraj)
					{
						zamijeni=recenica[poc];
						recenica[poc]=recenica[kraj];
						recenica[kraj]=zamijeni;
						kraj--;
						poc++;
					}
				}
				count=0;
			}
		}
	}
	
	obrnuto=recenica;

	return obrnuto;
}


string IzmijeniUPigLatin (string recenica, vector<string>niz)
{
	string pig, temp, dod, prazno{" "}, prvo("a"), drugo("y");
	vector <string> kopija;
	unsigned int n;
		
	for (int m=0; m<niz.size(); m++)
	{
		for (int s=0; s<niz[m].size(); s++)
		{
			if ((niz[m][s]>=65 && niz[m][s]<=90)||(niz[m][s]>=97 && niz[m][s]<=122))
			{
				continue;
			}
			else throw domain_error("Nekorektan izbor rijeci");
		}
	}

	for (int i=0; i<recenica.length(); i++)
	{
	    if (recenica[i]>=65 && recenica[i]<=127)
		{
			for (int j=i; j<recenica.length(); j++)
			{
				if (recenica[j]>=65 && recenica[j]<=127)
				{
					temp.push_back(recenica[j]);
				}
				
				if (j==recenica.length()-1)
				{
					i=j;
					break;
				}
				
				if (recenica[j]==32)
				{
					i=j;
					break;
				}
			}
			kopija.push_back(temp);
			temp.clear();
		}
	}
	
	if (niz.size()==0)
	{
		niz=kopija;
	}
	
	for (int k=0; k<kopija.size(); k++)
	{
		for (int h=0; h<niz.size(); h++)
		{
			if (kopija[k]==niz[h])
			{
				temp=kopija[k];
				
				n=temp.length()-1;

				for (int l=0; l<temp.length(); l++)
				{
					if (l==n)
					{
						dod.push_back(temp[0]);
					}
					
					else
					{
						dod.push_back(temp[l+1]);
					}
				}
				dod.push_back(prvo[0]);
				dod.push_back(drugo[0]);
				kopija[k]=dod;
				dod.clear();
				temp.clear();
			}
		}
	}
	
	for (int y=0; y<kopija.size(); y++)
	{
		temp=kopija[y];
		for (int x=0; x<temp.size(); x++)
		{
			pig.push_back(temp[x]);
		}
		if (y!=kopija.size()-1)
		{
			pig.push_back(prazno[0]);
		}
		
	}

	
	return pig;
}

int main ()
{
	string recenica,temp,obrnirez, pig;
	vector<string> niz;
	int stuff(0);
	
	
		cout<<"Unesite recenicu: ";
		getline (cin,recenica);
		cout<<"Unesite fraze: ";
		while (stuff==0)
		{
			getline(cin,temp);
			if (temp=="")
			{
				stuff=1;
				break;
			}
			niz.push_back(temp);
		}
		
	try
	{
		pig=IzmijeniUPigLatin(recenica,niz);
		cout<<"Recenica nakon PigLatin transformacije: "<<pig<<endl;
	}
	
	catch (domain_error izuzetakrijec)
	{
		cout<<"Izuzetak: "<<pig;
		cout<<izuzetakrijec.what()<<endl;
	}
	
	try
	{
		obrnirez=ObrniFraze(recenica,niz);
		cout<<"Recenica nakon obrtanja fraza: "<<obrnirez;
	}
	
	catch (domain_error izuzetakrijec)
	{
		cout<<"Izuzetak: "<<obrnirez;
		cout<<izuzetakrijec.what()<<endl;
	}
	
	
	return 0;
}