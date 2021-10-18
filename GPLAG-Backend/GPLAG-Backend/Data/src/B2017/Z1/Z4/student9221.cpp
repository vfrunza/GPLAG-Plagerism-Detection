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
#include<vector>
#include<string>
using namespace std;
string NapraviPalindrom(string recenica,vector<string> spisakFraza){
	string rezultat(recenica);
	int dodani(0);
	for(int i(0);i<spisakFraza.size();i++) {
		for(int j(0);j<rezultat.size();j++){
			int brojac(0);
			while(brojac<spisakFraza.at(i).length()&&j+brojac<rezultat.length()&&spisakFraza.at(i).at(brojac)==rezultat.at(j+brojac)){
				brojac++;
			}
			if((brojac==spisakFraza.at(i).length()&&j+brojac==rezultat.length())||(brojac==spisakFraza.at(i).length()&&(rezultat.at(j+brojac)==','||rezultat.at(j+brojac)==' '))){
				string palindrom="";
				for(int k(j+brojac-1);k>=j;k--){
					palindrom+=rezultat.at(k);
				}
				rezultat=rezultat.substr(0,j+brojac)+palindrom+rezultat.substr(j+brojac,rezultat.length()-j-brojac);
				dodani+=brojac;
				j+=(brojac+dodani-1);
			}
		}
	}
	return rezultat;
						

}

bool JeLiSlovo(char s) {
	if((s<'A' || s>'Z') && (s<'a' || s>'z')) return false;
	return true;
}

string NapraviPoluPalindrom(string recenica,vector<string> spisakFraza){
	string rezultat(recenica);
	for(int i(0);i<spisakFraza.size();i++){ //idemo kroz fraze
		for(int j(0);j<recenica.size();j++){ //kroz recenicu

			int brojac(0);
			while(brojac<spisakFraza.at(i).length()&&j+brojac<recenica.length()&&spisakFraza.at(i).at(brojac)==recenica.at(j+brojac)){ 
				brojac++;
			}//brojac je iza rijeci za 1 i ima duzinu fraze
			if(j+spisakFraza.at(i).length() == recenica.length()) {
					 if(j+brojac==recenica.length()) {
					 		if(j==0 && brojac%2==0) {
					 				int brojacNaopako(j+brojac/2-1);
					 				for(int k(j+brojac/2); k<j+brojac;k++){
					 					rezultat.at(k)=recenica.at(brojacNaopako);
					 					brojacNaopako--;
					 				}
					 			return rezultat;
					 		}
							if(brojac%2==0 && j>0 && !JeLiSlovo(recenica.at(j-1))) {
							int brojacNaopako(j+brojac/2-1);
							for(int k(j+brojac/2); k<j+brojac;k++) {
								rezultat.at(k)=recenica.at(brojacNaopako);
								brojacNaopako--;
						}
							}
					 }
					}if(j+spisakFraza.at(i).length() == recenica.length()) {
					 	if(j+brojac==recenica.length()) {
					 		if(j==0 && brojac%2!=0) {
					 				int brojacNaopako(j+brojac/2-1);
					 				for(int k(j+brojac/2+1); k<j+brojac; k++) {
					 					rezultat.at(k)=recenica.at(brojacNaopako);
					 					brojacNaopako--;
					 				}
					 			return rezultat;
					 		}
							if(!JeLiSlovo(recenica.at(j-1))) {
							if(brojac%2 != 0) {
							int brojacNaopako(j+brojac/2-1);
							for(int k(j+brojac/2+1); k<j+brojac; k++){
								rezultat.at(k)=recenica.at(brojacNaopako);
								brojacNaopako--;
							}
						}
					}
					}
					}
					
			if(brojac==spisakFraza.at(i).length() && brojac+j<recenica.length()) { //dodo && JeLiSlovo(recenica.at(j+brojac)))
					
					if(brojac%2==0 && !JeLiSlovo(recenica.at(j+brojac))){
						int brojacNaopako(j+brojac/2-1); //suncan, brojacNaopako na n 
						for(int k(j+brojac/2);k<=j+brojac-1;k++){ //k je na c
							rezultat.at(k)=recenica.at(brojacNaopako); // suncan, sunnan, sunnun, sunnus
							brojacNaopako--;
						}
						j+=(brojac-1);
					}
					else if(brojac%2 != 0 && !JeLiSlovo(recenica.at(j+brojac))){
						int brojacNaopako(j+brojac/2-1); //lijep, brojacNaopako na i
						for(int k(j+brojac/2+1);k<=j+brojac-1;k++){ //k je na j
							rezultat.at(k)=recenica.at(brojacNaopako);
							brojacNaopako--;
						}
					j+=(brojac-1);	
					}
				}
			}
		}
		return rezultat;
	}

int main ()
{
	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin, recenica);
	cout<<"Unesite fraze: "; 
	vector<string> fraze; 
	string unos; 
	do{ 
		getline(cin, unos);
		if(unos.length() == 0) break;
		else fraze.push_back(unos);
	}while(1);
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, fraze)<<endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, fraze)<<endl;
	
	return 0;
}