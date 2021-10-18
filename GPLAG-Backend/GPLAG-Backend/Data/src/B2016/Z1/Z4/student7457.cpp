/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

string ObrniFraze (string recenica, vector<string> fraze);
string IzmijeniUPigLatin (string recenica, vector<string> fraze);
string obrniString (string fraza);
string zamijeniFrazu (string recenica, string fraza, int pocetnaPozicija, int offset);
string pigLatinifaj (string recenica);
int pronadjiPodFrazu (string recenica, string fraza, int pocetakPotrage);
bool daLiJeFrazaKorektna (string fraza);
string pigLatinIzmijeniSveRijeci (string recenica);

int main () {
	cout << "Unesite recenicu: ";
	string recenica;
	getline(cin, recenica);
	vector<string> fraze(0);
	cout << "Unesite fraze: ";
	for(;;){
		string pom;
		getline(cin, pom);
		if(pom.length() == 0) {
			break;
		} else {
			fraze.push_back(pom);
		}
	}
	try {
	cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze) << "\n";
	} catch (std::domain_error e) {
	    cout << e.what() << endl;
	}
	cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);

    return 0;
}

string ObrniFraze (string recenica, vector<string> fraze) {
    for(string fraza : fraze) {
        try {
            //TODO: imas "i" koje vraca pronadjiFrazu koje pokazuje na kraj fraze za zamijenu
            //na osnovu toga zavrsi petlju i pazi na to odakle pocinje potraga za narednom frazom za razmjenu
            int sljedecaPozicija(pronadjiPodFrazu(recenica, fraza, 0));
            while(sljedecaPozicija <= recenica.length()) {
                recenica = zamijeniFrazu(recenica, obrniString(fraza), sljedecaPozicija - fraza.length(), 0);
                sljedecaPozicija = pronadjiPodFrazu(recenica, fraza, sljedecaPozicija);
            }

        } catch (int e) {
            continue;
        }
    }
    return recenica;
}
string obrniString (string fraza) {
    string rezultat;
    for(int i = fraza.length() - 1; 0 <= i; i--)
        rezultat.push_back(fraza.at(i));
    return rezultat;
}

string zamijeniFrazu (string recenica, string fraza, int pocetnaPozicija, int offset) {
    string rezultat(recenica.substr(0, pocetnaPozicija + offset));
    rezultat += fraza + recenica.substr(pocetnaPozicija + fraza.length() - offset, recenica.length());
    return rezultat;
}

int pronadjiPodFrazu (string recenica, string fraza, int pocetakPotrage) {
    //vraca index zadnjeg clana fraze u stringu poslije lokacije koja je specificirana varijablom
    //pocetakPotrage
    //ukoliko ne nadje frazu baca izuzetak tipa int i vrijednosti 0
    for(int i = pocetakPotrage; i < recenica.length(); i++) {
        bool frazaPronadjena(true);
        for(int j = 0; j < fraza.length() && i < recenica.length(); j++, i++) {
            if(i == recenica.length() - 1 && j < fraza.length() - 1) {
                throw 0;
            }
            if(fraza.at(j) != recenica.at(i)) {
                //TODO: ako dodje do kraja stringa, a nije cijela fraza identica treba da baci izuzetak
                //DONE
                frazaPronadjena = false;
                break;
            }
        }
        if(frazaPronadjena) {
            return i;
        }
    }
    throw 0;
}


string IzmijeniUPigLatin (string recenica, vector<string> fraze) {
    if(fraze.size() == 0) {
        recenica = pigLatinIzmijeniSveRijeci(recenica);
        return recenica;
    }
    for(string fraza : fraze) {
        if(!daLiJeFrazaKorektna(fraza)) {
            throw std::domain_error("Nekorektan izbor rijeci");
        }
        try {
            int sljedecaPozicija(pronadjiPodFrazu(recenica, fraza, 0));
            while(sljedecaPozicija <= recenica.length()) {
                recenica = zamijeniFrazu(recenica, pigLatinifaj(fraza), sljedecaPozicija - fraza.length() - 1, 1);
                sljedecaPozicija = pronadjiPodFrazu(recenica, fraza, sljedecaPozicija);
            }

        } catch (int e) {
            continue;
        }
    }
    return recenica;
}

string pigLatinifaj (string recenica) {
    //ukoliko je string prazan, vrati prazan string
    //duh
    if(recenica.length() == 0)
        return "";
    string rezultat(recenica.substr(1, recenica.length()));
    rezultat.push_back(recenica.at(0));
    rezultat += "ay";
    return rezultat;
}

bool daLiJeFrazaKorektna (string fraza) {
    for(int i = 0; i < fraza.length(); i++)
        if(!isalpha(fraza.at(i)))
            return false;
    return true;
}

string pigLatinIzmijeniSveRijeci (string recenica) {
    string rezultat(""), pom("");
    for(int i = 0; i < recenica.length(); i++) {
            //pomocna varijabla u kojoj smjestam pojedinacne rijeci
            //nadam se da su odvojene nealpha znakovima

        if(isalpha(recenica.at(i))) {
            pom.push_back(recenica.at(i));
        } else {
            rezultat += pigLatinifaj(pom) + recenica.at(i);
            pom.clear();
        }
        if(i == recenica.length() - 1)
            rezultat += pigLatinifaj(pom);
    }
    return rezultat;
}