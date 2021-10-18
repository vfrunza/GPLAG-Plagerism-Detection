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
#include <string>
#include <vector>

/*
std::string NapraviPalindrom (std::string rec, std::vector<std::string> popis_fraza) {
	int duzina;
	for(int i=0; i<popis_fraza.size();i++) {
		 duzina=popis_fraza.at(i).length();
		for(int j=0; j<rec.length();j++) {
			if((((j==0 || j<rec.length()) || (j>0 && rec.at(j-1)==' ')) && ((rec.at(j)>='a'&& rec.at(j)<='z') || (rec.at(j)>='A'&& rec.at(j)<='Z')))) {
				std::string provjera(rec.substr(j,duzina));
				if(provjera.compare(popis_fraza.at(i))) {
					std::string izvrnuta{""};
					for(int k=0; k<duzina/2;k++) 
						izvrnuta.at(k)=popis_fraza.at(i).at(duzina/2-k);
					rec=rec.substr(0, j+duzina/2)+izvrnuta+" "+rec.substr(j+duzina,rec.length());
				}
			}
		}
	}
	return rec;
}

std::string NapraviPoluPalindrom (std::string rec, std::vector<std::string> popis_fraza) {
	for(int i=0; i<popis_fraza.size();i++) {
		int duzina(popis_fraza.at(i).length());
		for(int j=0; j<rec.length();j++) {
			if(((j==0 || (j>0 && rec.at(j-1)==' ')) && ((rec.at(j)>='a'&&rec.at(j)<='z')||(rec.at(j)>='A'&&rec.at(j)<='Z')))&& rec.at(j+duzina)<=rec.length()) {
				if(rec.substr(j,duzina)==popis_fraza.at(i)) {
					std::string izvrnuta(0);
					for(int k=0; k<duzina/2; k++)
						izvrnuta.at(k)=popis_fraza.at(i).at(duzina/2-k);
					rec=rec.substr(0,j+duzina/2)+izvrnuta+" "+rec.substr(j+duzina, rec.length());
				}
				j--;
			} 
		}
	}
	return rec;
}
*/


std::string ObrniRijec(std::string s)
{
	std::string pom;
	for(int i=1; i<=s.length(); i++)
		pom+=s.at(s.length()-i);
	return pom;
}

std::string NapraviPalindrom (std::string rijec, std::vector<std::string> popis_fraza)
{
	std::string fraza, s, k(rijec);
	int duzina(0);
	for(int i=0; i<popis_fraza.size(); i++)
	{
		s=k;
		fraza=popis_fraza.at(i);
		duzina=fraza.length();
		for(int j=0; j<s.length(); j++)
			if((j==0 || s.at(j-1)==' ') && ((s.at(j)>='a' && s.at(j)<='z') || (s.at(j)>='A' && s.at(j)<='Z')))
				if(s.substr(j,duzina)==fraza && (s.at(j+duzina)==' ' || (j+duzina)==s.length())) {
					std::string obrnuta(ObrniRijec(k.substr(j,duzina)));
					s=k.substr(0,j+duzina)+obrnuta+k.substr(j+duzina,k.length());
					k=s;
				}
	}
	return k;
}

std::string NapraviPoluPalindrom (std::string rijec, std::vector<std::string> popis_fraza)
{
	std::string fraza, s, k(rijec);
	int duzina(0);
	for(int i=0; i<popis_fraza.size(); i++)
	{
		s=k;
		fraza=popis_fraza.at(i);
		duzina=fraza.length();
		for(int j=0; j<s.length(); j++)
			if(((s.at(j)>='a' && s.at(j)<='z') || (s.at(j)>='A' && s.at(j)<='Z')) && (j==0 || s.at(j-1)==' '))
				if(s.substr(j,duzina)==fraza && (s.at(j+duzina)==' ' || j+duzina==s.length()))
				{
					if(duzina%2==0)
						s=k.substr(0,j)+k.substr(j,duzina/2)+ObrniRijec(k.substr(j,duzina/2))+k.substr(j+duzina,k.length());
					else
						s=k.substr(0,j)+k.substr(j,duzina/2+1)+ObrniRijec(k.substr(j,duzina/2))+k.substr(j+duzina,k.length());
				
				k=s;
				}
				
	//	k=s;
	}
	return k;
}

int main ()
{

	std::cout<<"Unesite recenicu: ";
	std::string rec;
	std::getline(std::cin, rec);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> popis_fraza(0);
	std::string fraza;
	for(;;) {
		std::getline(std::cin, fraza);
		if(fraza=="") break;
		popis_fraza.push_back(fraza);
		
	}


	std::cout<<"Recenica nakon Palindrom transformacije: ";
	if (rec!="" && rec.size()!=0 && popis_fraza.size()!=0) {
	std::string pal(NapraviPalindrom(rec,popis_fraza));
	std::cout<<pal;
	}
	else if(popis_fraza.size()==0) std::cout<<rec;
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	if (rec!="" && rec.size()!=0 && popis_fraza.size()!=0) {
	std::string polupal(NapraviPoluPalindrom(rec,popis_fraza));
	std::cout<<polupal;
	} 
	else if(popis_fraza.size()==0) std::cout<<rec;

	return 0;
}