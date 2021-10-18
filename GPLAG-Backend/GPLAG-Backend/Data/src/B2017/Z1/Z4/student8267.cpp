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
std::string NapraviPalindrom(std::string rec, std::vector<std::string> fraza)
{
	std::string NovaRec;
	if(fraza.size()==0) return rec;
	if(rec.length()==0) return NovaRec;
	for(int i(0);i<fraza.size();i++) {
		 std::size_t nadjen=rec.find(fraza.at(i));
		 if (nadjen <= rec.length()) {
			 std::string okrenuti=std::string(fraza.at(i).rbegin(), fraza.at(i).rend());
			 int startna=nadjen+fraza.at(i).length();
			 rec.insert(startna, okrenuti);
		 }
	}
	return rec;
}
std::string NapraviPoluPalindrom(std::string rec, std::vector<std::string> fraza)
{
	std::string NovaRec;
	if(fraza.size()==0) return rec;
	if(rec.length()==0) return NovaRec;
    for(int i(0);i<fraza.size();i++){
    	std::size_t nadjen=rec.find(fraza.at(i));
    	if(nadjen<=rec.length())
    	{
    		int duzina=fraza.at(i).length();
    		int pola=duzina/2;
    		std::string novi = std::string(fraza.at(i).substr(0, pola));
			std::string okrenuti=std::string(novi.rbegin(), novi.rend());
			int startna=pola+nadjen;
			rec.erase(startna, pola);
            rec.insert(startna, okrenuti);
            
    	}
    }
	return rec;
}
int main ()
{
	std::string s;
	std::vector<std::string> vf;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	while(1){
		std::string f;
		std::getline(std::cin,f);
		if(f=="") break;
		vf.push_back(f);
	}
	std::cout<<"Recenica nakon Polindrom transformacije: "<<NapraviPalindrom(s,vf);
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPolindrom transformacije: "<<NapraviPoluPalindrom(s,vf);
	return 0;
}