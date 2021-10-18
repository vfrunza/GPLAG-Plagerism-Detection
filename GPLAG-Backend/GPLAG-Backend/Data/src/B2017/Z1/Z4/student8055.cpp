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
#include <iomanip>
bool domen (char x) {

if (x>='A' && x<='Z') return true;
if (x>='a' && x<='z') return true;
return false;
}

std::vector<int> obrada (std::string fraza, std::string recenica){
	std::vector<int> pozicije;
	bool pocetak, kraj;
	int vel (fraza.size()); 
	for (int i=0; i<int(recenica.size())-vel+1; i++){
		if (i==0) pocetak=true;
		else pocetak = !domen(recenica.at(i-1));
		if (i==int(recenica.size())-vel) kraj=true;
		else kraj = !domen(recenica.at(i+vel));
		if (kraj && pocetak && fraza == recenica.substr(i,vel)) pozicije.push_back(i); 
	}
 	return pozicije;
}
std::string izvrni (std::string rijec){
	std::string pomocni; 
	for (int i=rijec.size()-1; i>=0; i--)
		pomocni.push_back(rijec.at(i)); 
return pomocni;
}
int pomjeri (std::vector<std::vector<int>> pozicije, std::vector<std::string> stringovi, int i, std::string recenica){
	for (int k=0; k<pozicije.size(); k++) {
		for (int l=0; l<pozicije.at(k).size(); l++)
			if (pozicije.at(k).at(l)==i) return stringovi.at(k).size(); 
	}
	return 0;
}
std::string dodatak (std::vector<std::vector<int>> pozicije, std::vector<std::string> stringovi, int i, std::string recenica){
	for (int k=0; k<pozicije.size(); k++) {
		for (int l=0; l<pozicije.at(k).size(); l++)
			if (pozicije.at(k).at(l)==i) return stringovi.at(k)+ izvrni (stringovi.at(k)); 
	}
	std::string d;
	return d;
}
std::string NapraviPalindrom (std::string recenica, std::vector<std::string> vektor) {
	std::string novi;
	std::vector<std::vector<int>> pozicije;
	std::vector<std::string> stringovi;
	for (int i=0; i<vektor.size(); i++){
		auto x (obrada(vektor.at(i), recenica)); 
		if (x.size() !=0){
			pozicije.push_back(x); 
			stringovi.push_back(vektor.at(i)); 
		}
	}

	for (int i=0; i<recenica.size(); i++){
		auto pomocna(dodatak(pozicije, stringovi, i, recenica));
		novi+=pomocna; 
		i+= pomjeri(pozicije, stringovi, i, recenica);
		if (i>=recenica.size()) break; 
		if (pomocna.size()==0) novi+=recenica.at(i); 
		if (i+ pomocna.size()/2 != recenica.size()  && pomocna.size()!=0) novi+=recenica.at(i); 
	}
	return novi; 
}
std::string dodatak1 (std::vector<std::vector<int>> pozicije, std::vector<std::string> stringovi, int i, std::string recenica){
	for (int k=0; k<pozicije.size(); k++) {
		for (int l=0; l<pozicije.at(k).size(); l++)
			if (pozicije.at(k).at(l)==i) return stringovi.at(k).substr(0, stringovi.at(k).size()/2)+ (izvrni (stringovi.at(k))).substr(stringovi.at(k).size()/2, stringovi.at(k).size()-stringovi.at(k).size()/2); 
	}
	std::string d;
	return d;
}


std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> vektor) {
	std::string novi;
	std::vector<std::vector<int>> pozicije;
	std::vector<std::string> stringovi;
	for (int i=0; i<vektor.size(); i++){
		auto x (obrada(vektor.at(i), recenica)); 
		if (x.size() !=0){
			pozicije.push_back(x); 
			stringovi.push_back(vektor.at(i)); 
		}
	}

	for (int i=0; i<recenica.size(); i++){
		auto pomocna(dodatak1(pozicije, stringovi, i, recenica));
		novi+=pomocna; 
		i+= pomjeri(pozicije, stringovi, i, recenica);
		if (i>=recenica.size()) break; 
		if (pomocna.size()==0) novi+=recenica.at(i); 
		if (i+ pomocna.size()/2 != recenica.size()  && pomocna.size()!=0) novi+=recenica.at(i); 
	}
	return novi; 
}
bool poklapanje (std::string a, std::string b){
	bool pocetak, kraj;
	int vel (a.size()); 
	for (int i=0; i<int(b.size())-vel+1; i++){ 
		if (i==0) pocetak=true;
		else pocetak = !domen(b.at(i-1));
		if (i==int(b.size())-vel) kraj=true;
		else kraj = !domen(b.at(i+vel));
		if (kraj && pocetak && a == b.substr(i,vel)) return true; 
	}
 	vel = b.size(); 
 	for (int i=0; i<int(a.size())-vel+1; i++){ 
		if (i==0) pocetak=true;
		else pocetak = !domen(a.at(i-1));
		if (i==int(a.size())-vel) kraj=true;
		else kraj = !domen(a.at(i+vel));
		if (kraj && pocetak && b == a.substr(i,vel)) return true; 
	}
 	
 	return false;
 	
}

int main ()
{
	std::cout<<"Unesite recenicu: "; 
	std::string recenica; 
	std::getline (std::cin, recenica);
	
	std::cout<<"Unesite fraze: "; 
	std::vector<std::string> fraze; 
	for(;;){
		std::string x; 
		std::getline (std::cin, x);
		if (x == "") break; 
	
		fraze.push_back (x); 
		
	}
	for (int i=0; i<fraze.size(); i++){
		for (int j=0; j<i; j++){
			if (poklapanje (fraze.at(i), fraze.at(j))) { 
				fraze.erase(fraze.begin()+i); 
				i--;
				break; 
			} 
		}
	}
	
		
	
	std::cout<<"Recenica nakon Palindrom transformacije: "; 
	std::cout<<NapraviPalindrom(recenica, fraze); 
	std::cout<<std::endl; 
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";  
	std::cout<<NapraviPoluPalindrom(recenica, fraze); 
	return 0;
}