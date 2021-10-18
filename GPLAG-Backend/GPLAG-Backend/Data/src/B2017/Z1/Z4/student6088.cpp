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
#include <algorithm>

std::string obrni(std::string rijec){
	std::reverse(rijec.begin(), rijec.end());
	return rijec;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> vek)
{
	
	unsigned int nPos(0);
	for(std::string x : vek)
	{
		while((unsigned int)(nPos=recenica.find(x, nPos+1))!=(unsigned int)std::string::npos)
		{
			nPos+=x.size();
			recenica.insert(nPos, obrni(x));
		}
	}
	return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vek)
{	
	std::string rec1=recenica;
	unsigned int nPos(0);
	for(std::string x : vek)
	{
		while((unsigned int)(nPos=recenica.find(x, nPos+1))!=(unsigned int)std::string::npos)
		{	
			if(x.size()%2==0){
			nPos+=x.size()/2;
			x.resize(x.size()/2);
			rec1.replace(nPos,x.size(), obrni(x));
			}
			else{
				nPos+=x.size()/2+1;
				x.resize((x.size()-1)/2);
				rec1.replace(nPos,x.size(), obrni(x));
			}
			
		}
	}
	return recenica;
}


int main ()
{	
	std::vector<std::string> fraze;
	std::string recen;
	std::string temp;
	
	std::cout<<"Unesite recenicu: ";
	
	std::getline(std::cin, recen);
	
	std::cout << "Unesite fraze: ";
	for(int i=0;;i++){
	std::getline(std::cin, temp);
	if(temp.length()==0) break;
	fraze.push_back(temp);
	temp.clear();
	
	}
	
	std::cout<<"Recenica nakon Palindrom transformacije: "<< NapraviPalindrom(recen, fraze) << "\n";
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recen,fraze);
	

	return 0;
}