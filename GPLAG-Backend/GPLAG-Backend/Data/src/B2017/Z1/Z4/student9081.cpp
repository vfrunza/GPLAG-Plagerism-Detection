/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <string>

std::string NapraviPalindrom (std::string s, std::vector<std::string> v)
{
	//Prolazimo glavnom petljom onoliko puta koliko ima fraza.
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<s.length();)
		{
			//Pomocna varijabla indeks nam koristi da prolazimo kroz fraze koje su elementi vectora.
			int indeks(0);
			//Provjera da li se pocetak fraze iz vectora fraza slaze sa pocetkom neke fraze u stringu s.
			//Da bismo bili sigurno da smo i u stringu s na pocetku neke fraze, trazimo u uslovu da smo na pocetku stringa (j-1<0) ili da je prethodno bio razmak (s.at(j-1)==' ').
			if (s.at(j)==v.at(i).at(indeks) && (j-1<0 || s.at(j-1)==' '))
			{
				//Koristimo while petlji dokle god postoji slaganja u frazama.
				while (s.at(j)==v.at(i).at(indeks))
				{
					j++;
					indeks++;
					if (indeks==v.at(i).size() || j==s.length())
					break;
				}
				//Ako je ispunjen uslov da smo dosli na kraj fraze koja je clan vectora ali i uslov da smo dosli do kraja stringa s ili razmaka
				//to onda znaci da imamo potpuno poklapanje
				if (indeks==v.at(i).size() && (j==s.length() || !((s.at(j)>='A' && s.at(j)<='Z') || (s.at(j)>='a' && s.at(j)<='z')) || s.at(j-1)==' '))
				{
					//Kad smo sigurni da su fraze potpuno iste,na kraj fraze u stringu s, dodajemo frazu iz vectora ali krenuvsi od kraja do pocetku fraze
					for (int k=v.at(i).size()-1;k>=0;k--)
						{s.insert(s.begin()+j,v.at(i).at(k));
						j++;}
				}
			}
			else
			j++;
		}
	}
	return s;
}

std::string NapraviPoluPalindrom (std::string s,std::vector<std::string> v)
{
	//Funkcija radi istu stvar kao i prethodna,sve dok nismo sigurni da imamo potpuno poklapanje.
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<s.length();)
		{
			int indeks(0);
			if (s.at(j)==v.at(i).at(indeks) && (j-1<0 || s.at(j-1)==' '))
			{
				while (s.at(j)==v.at(i).at(indeks))
				{
					
					j++;
					indeks++;
					if (indeks==v.at(i).size() || j==s.length())
					break;
				}
				if (indeks==v.at(i).size () && (j==s.length() ||  !((s.at(j)>='A' && s.at(j)<='Z') || (s.at(j)>='a' && s.at(j)<='z'))))
				{
					//Ukoliko je ovaj uslov ispunjen, tj. radi se o identicnim frazama, prelazimo na glavni zadatak funkcije
					//Krenuvsi od kraja fraze koju smo pronasli u stringu s, brisemo pola njenog sadrzaja (od kraja prema pocetku)
					for (int k=v.at(i).size();k>v.at(i).size()/2 && v.at(i).size()!=1;k--)
					{
						s.erase(s.begin()+j-1);
						j--;
					}
					//Nakon brisanja,od sredine fraze u stringu dodajemo prvu polovinu fraze iz vectora, u obrnutom redoslijedu 
					for (int k=(v.at(i).size()+1)/2;k>0;k--)
					{
						s.insert(s.begin()+j,v.at(i).at(k-1));
						j++;
					}
				}
			}
			else
			j++;
		}
	}
	return s;
}


int main ()
{
	std::string s,unos;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";
	for(;;)
	{
		std::getline(std::cin,unos);
		if (unos.length()>0)
			fraze.push_back(unos);
		else
			break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,fraze);
	return 0;
}