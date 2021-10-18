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
std::string ObrniFraze(std::string s, std::vector<std::string> fraze){
	for(int i=0;i<fraze.size();i++){
		int duzina_fraze(fraze[i].length());
		for(int j=0;j<s.length()-fraze[i].length();j++){
				std::string s2(s.substr(j,duzina_fraze));
				if(s2==fraze[i]){
					while(duzina_fraze>j){
						char pomocni(s[j]);
						s[j]=s[duzina_fraze];
						s[duzina_fraze]=pomocni;
						j++;
						duzina_fraze--;
					}
				}
			}
		}
	return s;
}
std::string IzmjeniUPigLatin(std::string s, std::vector<std::string> fraze){
	
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica,'\n');
	std::string unos;
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for(;;){
		std::getline(std::cin,unos,'\n');
		if(unos!="") fraze.push_back(unos);
		else break;
	}
	std::string kopija(recenica);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::string PigLatin(IzmjeniUPigLatin(recenica,fraze));
	std::cout<<PigLatin<<std::endl;	
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string obrnuto(ObrniFraze(kopija,fraze));
	std::cout<<obrnuto<<std::endl;
	return 0;
}