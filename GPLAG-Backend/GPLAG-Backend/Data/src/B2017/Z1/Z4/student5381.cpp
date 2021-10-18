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

bool jel_slovo(int a)
{
	if((a>='a' && a<='z') || (a>='A' && a<='Z')) return true;
	return false;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string rec(recenica);
	for (int i=0; i<fraze.size(); i++) {
		for(int j=0; j<rec.length()-1; j++) {
			int index(0);
			if(rec.at(j)==fraze.at(i).at(index)) {
				int pocetak(j); // pamtimo mjesto gdje pocinje podudaranje u stringu
				j++;
				index++;
				// ako naidjemo na podudaranje sa prvim znakom posmatrane fraze provjeravamo da li imamo potpuno podudaranje
				while(j<rec.length()-1 && index<fraze.at(i).length()-1) {
					if(rec.at(j)!=fraze.at(i).at(index)) {
						index=0;
						j--;
						break;
					} else {
						index++;
						j++;
					}
				}

				if(index==fraze.at(i).length()-1) {
					j++;                                                                            // ako smo pronasli cijelu frazu provjeravamo da li je ona samostalna u recenici
					if((j==rec.length() || !jel_slovo(rec.at(j))) && (pocetak==0 || !jel_slovo(rec.at(pocetak-1)))) {  // tj. odvojena nekim znakom, a ne u sastavu neke druge fraze
						for(int k=fraze.at(i).length()-1; k>=0; k--) {
							rec.insert(rec.begin()+j, fraze.at(i).at(k)); // dodavanje znakova u obrnutom redoslijedu na kraj pronadjene fraze u recenici
							j++;
						}
					}
				}
			}
		}

	}
	return rec;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string rec(recenica);
	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<rec.length(); j++) {
			int index(0);
			if(rec.at(j)==fraze.at(i).at(index)) {
				int pocetak(j);
				j++;
				index++;
				// na isti nacin kao i u prvoj f-ji provjeravamo da li je pronadjena fraza unutar recenice
				while(j<rec.length()-1 && index<fraze.at(i).length()-1) {
					if(rec.at(j)!=fraze.at(i).at(index)) {
						index=0;
						j--;
						break;
					} else {
						index++;
						j++;
					}
				}

				if(index==fraze.at(i).length()-1) {
					j++;
					if((j==rec.length() || !jel_slovo(rec.at(j))) && (pocetak==0 || !jel_slovo(rec.at(pocetak-1)))) {
						j--;
						for(int k=0; k<fraze.at(i).length()/2; k++) {
							rec.at(j)=fraze.at(i).at(k);             // mijenjanje znakova u drugoj polovini pronadjene fraze sa onima iz prve polovine
							j--;
						}
					}
				}
			}
		}
	}
	return rec;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);

	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string ulaz;
	for(;;) {
		std::getline(std::cin, ulaz);
		if(ulaz.length()==0) break;
		fraze.push_back(ulaz);

	}

	std::string palindromska(NapraviPalindrom(recenica, fraze));
	std::string polupalindormska(NapraviPoluPalindrom(recenica,fraze));
	std::cout << "Recenica nakon Palindrom transformacije: " << palindromska <<std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << polupalindormska;

	return 0;
}