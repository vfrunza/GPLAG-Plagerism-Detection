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

using std::cout;
using std::cin;
using std::string;
using std::vector;


typedef vector<string> SVector;


string ObrniFraze(string recenica,SVector zbirka)
	{
				
				for (int i=0;i<zbirka.size();i++)
				{
					for(int j=0;j<recenica.length();j++)
					{
						string nadjeno;
						nadjeno=recenica.substr(j,zbirka[i].size());
						if (nadjeno==zbirka[i])
						{
							int b;
							b=j;
							for(int k=nadjeno.size()-1;k>=0;k--)
							{
									recenica[b]=nadjeno[k];
									b++;
							}
							
						}
					}
					
				}
		
			return recenica;
			}



int main ()
{
	string recenica;
	cout<<"Unesite recenicu: ";
	std::getline(cin,recenica);
	cout<<"Unesite fraze: ";
	SVector zbirka;
	for(int i=0;;i++)
	{
		string s;
		std::getline(cin,s);
		zbirka.push_back(s);
		if (s.length()==0)
			break;
	}
	string obrnuto;
	obrnuto=ObrniFraze(recenica,zbirka);
	cout<<"Recenica nakon obrtanja fraza: "<<obrnuto;
//	cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,zbirka);
	
	return 0;
}