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

std::string DodajURecenicu(std::string S1, std::string S2, int pozicija){
	if(pozicija == S1.size() + S2.size() -1){
		return S1 + S2;	
	}
	std::string S3 = S1.substr(0, pozicija);
	std::string S4 = S1.substr(pozicija, S1.size() - pozicija);
	std::string S5 = S3  + S2 + S4;
	return S5;
}

std::string ObrniString(std::string S){
	std::string S1;
	for(int i = S.size() - 1; i>=0; i--){
		S1 += S.at(i);
	}
	return S1;
}

std::string NapraviPalindrom(std::string S, std::vector<std::string> PopisFraza) {
	if(S.size() == 0) return S;
	for(int i=0; i < PopisFraza.size(); i++){
		if(S.size() < PopisFraza.at(i).size()) continue;
		for(int j=0; j < S.size() - PopisFraza.at(i).size() + 1; j++){
			std::string S1;
			S1 = S.substr(j, PopisFraza.at(i).size());
			std::string Ss1;
			if(j + PopisFraza.at(i).size() < S.size()) Ss1 = S.substr(j + PopisFraza.at(i).size(), 1);
			
			if(S1 == PopisFraza.at(i) && (j + PopisFraza.at(i).size() == S.size() || Ss1 == " " || Ss1 == "," || Ss1 == ".")) {
				S = DodajURecenicu(S, ObrniString(PopisFraza.at(i)), j+PopisFraza.at(i).size());
				
			}
			
		}
		
	}
	return S;
}

std::string DajPolaRijeci(std::string S){
	std::string S1;
	S1 = S.substr(0, S.size() / 2); return S1;
}

std::string DodajURecenicuPolu(std::string S1, std::string S2, int pozicija, int velicina){
	std::string S3 = S1.substr(0, pozicija);
	S3 += ObrniString(DajPolaRijeci(S2));
	if(pozicija + velicina < S1.size()){
    	S3 += S1.substr(pozicija + velicina, S1.size()); return S3;
	}
	else {
		return S3;
	}
}

std::string NapraviPoluPalindrom(std::string S, std::vector<std::string> PopisFraza) {
	if(S.size() == 0) return S;
	for(int i = 0; i < PopisFraza.size(); i++){
		if(S.size() < PopisFraza.at(i).size()) continue;
		for(int j = 0; j < S.size() - (PopisFraza.at(i).size() / 2); j++){
			std::string Ss;
			Ss = S.substr(j, PopisFraza.at(i).size());
			std::string Ss1;
			if(j+ PopisFraza.at(i).size() < S.size()) Ss1 = S.substr(j + PopisFraza.at(i).size(),1);
			
			if(Ss == PopisFraza.at(i) && (j+PopisFraza.at(i).size() == S.size() || Ss1 ==" " || Ss1 == "," || Ss1 == ".")) {
				if(PopisFraza.at(i).size() % 2 == 0)
				{
					S = DodajURecenicuPolu(S, PopisFraza.at(i), j + (PopisFraza.at(i).size() / 2), (PopisFraza.at(i).size() / 2));
				}
				else 
				{
					S = DodajURecenicuPolu(S, PopisFraza.at(i), j + (PopisFraza.at(i).size() / 2) + 1, (PopisFraza.at(i).size() / 2));
				}
			}
			
		}
	}
	return S;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string R;
	std::getline(std::cin, R);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> V;
	for(;;){
		std::string F;
		std::getline(std::cin, F);
		
		if(F.size()==0) break;
		V.push_back(F);
		
	}

	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(R, V);
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(R, V);
	
	return 0;
}