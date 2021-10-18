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

//Obrnuti string
std::string Palindrom(std::string s){
	std::string nova;
	for(int i(s.length()-1); i>=0; i--)
	nova+=s.at(i);
	return nova;
}

std::string PoluPalindrom(std::string s){
	std::string nova1(Palindrom(s));
	return nova1;
}
//Pomocna f-ja kojom provjeravamo da li se fraza nalazi u recenici
bool Postoji(std::string s, std::string s1){
	bool postoji(false);
	int duzina(s1.length());
	int razmak(1);
	for(int i(0); i<(s.length()-s1.length()); i++){
		std::string rijec=s.substr(i,duzina);
		if(s.at(i)==' ') razmak=1;
		else{
			if(rijec==s1 && s.at(duzina+i)==' '){
				postoji=true;
				break;
			}
			rijec.clear();
			razmak=0;
		}
	}
	return postoji;
}

void DodajPalindrom(std::string &s, std::string s1){
	std::string novi; // pomocni string
	std::string dodaj(Palindrom(s1));
	int duzina(s1.length()), razmak(1),index,postoji(0);
	for(int i(0); i<(s.length()-s1.length()); i++){
		std::string rijec=s.substr(i,duzina);
		if(s.at(i)==' ') razmak=1;
		else{
			if(rijec==s1 && (s.at(duzina+i)==' ' )){
				index=i;
				postoji=1;
				break;
			}
			rijec.clear();
			razmak=0;
		}
	}
	
	novi=s.substr(0,index+dodaj.size()) + dodaj + s.substr(index+dodaj.size(), s.size()+dodaj.size());
	s=novi;
}
void DodajPoluPalindrom(std::string &s,std::string s1){
	std::string novi;
	std::string polu(s1);
	if(polu.size()%2!=0 )polu.erase(polu.size()/2+1,polu.size());
	else polu.erase(polu.length()/2,polu.length());
	std::string dodaj(PoluPalindrom(polu));
	int duzina(s1.length()), razmak(1), index, postoji(0);
	for(int i(0); i<(s.length()-duzina); i++){
		std::string rijec=s.substr(i,duzina);
		if(s.at(i)==' ') razmak=1;
		else{
			if(rijec==s1 && s.at(duzina+i)==' '){
				index=i; 
				postoji=1;
				break;
			}
			rijec.clear();
			razmak=0;
		}
	}
	s1.erase(s1.length()/2, s1.length());
	novi=s.substr(0,index) + s1+ dodaj + s.substr(index+duzina, s.size()+duzina);
	s=novi;
}
void NapraviPalindrom(std::string &recenica, std::vector<std::string> fraze){
    if(recenica.size()<1 || fraze.size()<1) return;
	for(int i(0); i<fraze.size(); i++){
		if(Postoji(recenica,fraze.at(i))) {
			DodajPalindrom(recenica,fraze.at(i));
			}
	}
}
void NapraviPoluPalindrom(std::string &recenica, std::vector<std::string> fraze){
	if(recenica.size()<1 || fraze.size()<1) return;
	for(int i(0); i<fraze.size(); i++){
		if(Postoji(recenica, fraze.at(i))){
			DodajPoluPalindrom(recenica,fraze.at(i));
		}
	}
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cin.ignore(10000, '\n');
	std::string fraze_recenice;
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::getline(std::cin,fraze_recenice);
		if(fraze_recenice.length()==0) break;
		if(fraze_recenice.length()!=0) fraze.push_back(fraze_recenice);
	}
	std::string recenica1(recenica);
	std::string recenica2(recenica);
	NapraviPalindrom(recenica1, fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<recenica1<<std::endl;
	NapraviPoluPalindrom(recenica2, fraze);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<recenica2<<std::endl;
	return 0;
}