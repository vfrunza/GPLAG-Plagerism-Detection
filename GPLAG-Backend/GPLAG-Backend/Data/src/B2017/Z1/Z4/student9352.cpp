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
typedef std::vector<std::string> FRAZE;

void BrisanjeFrazaKojeNisuPodstringovi(std::string UnesenaRecenica,FRAZE &UneseneFraze)
{

	std::string TrazeniString=UnesenaRecenica;
	TrazeniString.resize(TrazeniString.length()+1);
	char PrvoSlovoFraze=0;
	char ZapamtiSlovo=0;


	for (int i = 0; i < UneseneFraze.size(); i++) {
		PrvoSlovoFraze=UneseneFraze.at(i).at(0);
		int j=0;
		bool IzbaciIzVektoraFraza=true;
		for (j = 0; j < TrazeniString.length(); j++) {
			int k=0;
			if(TrazeniString.at(j)==PrvoSlovoFraze) {
				if(j!=0) ZapamtiSlovo=TrazeniString.at(j-1);
				for(k=0; k<UneseneFraze.at(i).length(); k++) {
					if(TrazeniString.at(j)!=UneseneFraze.at(i).at(k)) break;
					j++;
					if(j==TrazeniString.length()) break;
				}

				if((ZapamtiSlovo<'A' || (ZapamtiSlovo>'Z' && ZapamtiSlovo<'a')||ZapamtiSlovo>'z')&& k==UneseneFraze.at(i).length()) {
					IzbaciIzVektoraFraza=false;
				}
				if(j<TrazeniString.length() && ( (TrazeniString.at(j)>='a' && TrazeniString.at(j)<='z')||( TrazeniString.at(j)>='A' && TrazeniString.at(j)<='Z' ) )) IzbaciIzVektoraFraza=true;

			}
			if(!(IzbaciIzVektoraFraza)) break;
		}
		if(IzbaciIzVektoraFraza) {
			UneseneFraze.erase(UneseneFraze.begin()+i);
			i--;
		}
	}

}

std::string NapraviPalindrom(std::string s,FRAZE FrazeIzMaina)
{

	BrisanjeFrazaKojeNisuPodstringovi(s,FrazeIzMaina);
    
    std::string TrazeniString=s;
    TrazeniString.resize(TrazeniString.length()+1);
	char ZapamtiSlovo=0;
	char PrvoSlovoFraze=0;

	for (int i = 0; i < FrazeIzMaina.size(); i++) {
		PrvoSlovoFraze=FrazeIzMaina.at(i).at(0);
		int j=0;
		bool IzbaciIzVektoraFraza=true;
		for (j = 0; j < TrazeniString.length(); j++) {
			int k=0;
			if(TrazeniString.at(j)==PrvoSlovoFraze) {
				if(j!=0) ZapamtiSlovo=TrazeniString.at(j-1);
				for(k=0; k<FrazeIzMaina.at(i).length(); k++) {
					if(TrazeniString.at(j)!=FrazeIzMaina.at(i).at(k)) break;
					j++;
					if(j==TrazeniString.length()) break;
				}
				if(j<TrazeniString.length() && ( (TrazeniString.at(j)>='a' && TrazeniString.at(j)<='z')||( TrazeniString.at(j)>='A' && TrazeniString.at(j)<='Z' ) )) continue;

				if((ZapamtiSlovo<'A' || (ZapamtiSlovo>'Z' && ZapamtiSlovo<'a')||ZapamtiSlovo>'z')&& k==FrazeIzMaina.at(i).length()) {
					//PravljenjePalindroma
					for(int l=FrazeIzMaina.at(i).length()-1; l>=0; l--) {
						TrazeniString.insert(TrazeniString.begin()+j,FrazeIzMaina.at(i).at(l));
						j++;
						if(j==TrazeniString.length()) break;
					}
				}
			}
		}
	}
	TrazeniString.resize(TrazeniString.length()-1);
	return TrazeniString;
}

std::string NapraviPoluPalindrom(std::string s,FRAZE FrazeIzMaina)
{

	BrisanjeFrazaKojeNisuPodstringovi(s,FrazeIzMaina);
    
    std::string TrazeniString=s;
    TrazeniString.resize(TrazeniString.length()+1);
	char ZapamtiSlovo=0;
	char PrvoSlovoFraze=0;

	for (int i = 0; i < FrazeIzMaina.size(); i++) {
		PrvoSlovoFraze=FrazeIzMaina.at(i).at(0);
		int j=0;
		bool IzbaciIzVektoraFraza=true;
		for (j = 0; j < TrazeniString.length(); j++) {
			int k=0;
			if(TrazeniString.at(j)==PrvoSlovoFraze) {
				if(j!=0) ZapamtiSlovo=TrazeniString.at(j-1);
				for(k=0; k<FrazeIzMaina.at(i).length(); k++) {
					if(TrazeniString.at(j)!=FrazeIzMaina.at(i).at(k)) break;
					j++;
					if(j==TrazeniString.length()) break;
				}
				if(j<TrazeniString.length() && ( (TrazeniString.at(j)>='a' && TrazeniString.at(j)<='z')||( TrazeniString.at(j)>='A' && TrazeniString.at(j)<='Z' ) )) continue;

				if((ZapamtiSlovo<'A' || (ZapamtiSlovo>'Z' && ZapamtiSlovo<'a')||ZapamtiSlovo>'z')&& k==FrazeIzMaina.at(i).length()) {
					//PravljenjePoluPalindroma
					if(FrazeIzMaina.at(i).length()%2==0) j=j-FrazeIzMaina.at(i).length()/2;
					else j=j-1-FrazeIzMaina.at(i).length()/2;
					for(int l=(FrazeIzMaina.at(i).length()-1)/2; l>=0; l--) {
						TrazeniString.at(j)=FrazeIzMaina.at(i).at(l);
						j++;
						if(j==TrazeniString.length()) break;
					}
				}
			}
		}
	}
	TrazeniString.resize(TrazeniString.length()-1);
	return TrazeniString;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string Recenica;
	std::getline(std::cin,Recenica);



	std::cout<<"Unesite fraze: ";
	std::string UnosFraze;
	FRAZE Fraze;

	do {
		std::getline(std::cin,UnosFraze);
		if(UnosFraze.length()==0) break;
		Fraze.push_back(UnosFraze);
	} while(UnosFraze.length()!=0);

	std::string PalindromString(NapraviPalindrom(Recenica,Fraze));
	std::cout<<"Recenica nakon Palindrom transformacije: "<<PalindromString<<std::endl;
	std::string PoluPalindromString(NapraviPoluPalindrom(Recenica,Fraze));
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<PoluPalindromString;





	return 0;
}