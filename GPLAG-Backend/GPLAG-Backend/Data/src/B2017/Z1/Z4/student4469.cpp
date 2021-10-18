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


bool slovo(char a) {
	
	if((a>='a' && a<='z')||(a>='A'&& a<='Z'))return true;
	
	return false;
}


std::string NapraviPalindrom(std::string recenica, std::vector<std::string>vektor) {

for(int i=0;i<vektor.size();i++) {
	
	for(int j=0;j<recenica.size();j++) {
      
      for(int k=j+1;k<=recenica.size();k++)	 {

	if(vektor.at(i)==recenica.substr(j,k-j)  &&(k==recenica.size() || !slovo(recenica.at(k)) )) {    //ako se poklapaju i k pokazuje na mjesto poslije rijeci
		
		
		std::string pomocni=recenica.substr(j,k-j);
		for(int l=0;l<pomocni.size();l++) {
			
			recenica.insert(recenica.begin()+k,pomocni.at(l));   //ubacivanje izvrnute rijeci
			
		}
		k+=pomocni.size(); 
		j=k; 
	}
	
	
          }
	}
	
}

return recenica;

}


std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vektor) {

for(int i=0;i<vektor.size();i++) {

for(int j=0;j<recenica.size();j++) {
	for(int k=j+1;k<=recenica.size();k++) {
	
	
	if(vektor.at(i)==recenica.substr(j,k-j) && (k==recenica.size() || !slovo(recenica.at(k))) ){   //ako se poklapaju i k pokazuje na mjesto poslije rijeci
	
	for(int l=0;l<(k-j)/2;l++) {                   //broj koraka je polovina duzine rijeci
	                                                  
	recenica.at(k-1-l)=recenica.at(j+l);
	
	}
	
	}
	
	}
}
	

}
return recenica;
}



int main ()
{
	
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	
	std::vector<std::string> vektor;
	std::string rijec;
char znak;
std::cout<<"Unesite fraze: ";


	while(1) {
		
		std::getline(std::cin,rijec);
		if(rijec.size()==0) break;          //ako getline odmah ucita '\n', ona prestaje sa radom i rijec se smijesta samo nul granicnik, sto ga cini praznim stringom
		vektor.push_back(rijec);
	
		znak=std::cin.peek();    //ako je nakon rijeci jos jednom unesen "enter", unos fraza se prekida
		if(znak=='\n')break;
	}
	
	std::string recenica1,recenica2;
	recenica1=NapraviPalindrom(recenica,vektor);
	recenica2=NapraviPoluPalindrom(recenica,vektor);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<recenica1<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<recenica2<<std::endl;
	
	
	
	return 0;
}