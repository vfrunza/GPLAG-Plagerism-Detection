#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

//Funkcija koja pretvara mala slova u velika
void PretvoriUVelika(std::string &s)
{
    for(int i = 0; i < s.length(); i++) {
        if(s.at(i) >= 'a' && s.at(i) <= 'z') s.at(i) -= 'a' - 'A';
    }
}
//Funkcija koja pretvara velika slova u mala
void PretvoriUMala(std::string &s)
{
    for(int i = 0; i < s.length(); i++) {
        if(s.at(i) >= 'A' && s.at(i) <= 'Z') s.at(i) += 'a' - 'A';
    }
}

//Implementacija funkcije "KreirajIndeksPojmova"
std::map<std::string, std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga k)
{
    //Deklaracija i inicijalizacija iteratora na pocetak objekta tipa Knjiga
    std::map<std::string, std::vector<std::string>>::iterator it(k.begin());

    //Deklaracija objekta koji se vraca kao rezultat iz funkcije
    std::map<std::string,std::set<std::tuple<std::string, int, int>>> mapa_koja_se_vraca;

    //Prolazak kroz knjigu
    while(it != k.end()) {

        //Deklaracija i inicijalizacija pomocnog vektora, vektorom stringova(sadrzajem stranica knjige)
        std::vector<std::string> pomocni_vektor(it->second);

        
        //Prolazak kroz prethodno definirani pomocni vektor stringova
        for(int i = 0; i < pomocni_vektor.size(); i++) {
            //Izdvajanje rijeci iz pomocnog stringa i smjestanje istih u promijenjivu pomocna_rijec

            //Deklaracija i inicijalizacija pomocnog stringa
            std::string pomocni_string(pomocni_vektor[i]);

            //Pretvorba svih malih slova unutar pomocnog stringa, u velika slova
            PretvoriUVelika(pomocni_string);

            //Deklaracija i inicijalizacija indexa rijeci(pozicija unutar stringa)
            int pocetak(0);

            //Prolazak kroz prethodno definirani pomocni string

            for(int j = 0; j < pomocni_string.length(); j++) {
                std::string pomocna_rijec;
                //Deklaracija skupa ciji su elementi trojke (naziv_poglavlja,redni_broj_stranice_index_rijeci)
                std::set<std::tuple<std::string,int,int>> skup_u_mapi;
                //Izdvajanje rijeci iz pomocnog stringa i smjestanje istih u promijenjivu pomocna_rijec
                if(j != 0 ) {
                    if(pomocni_string[j] >= 'A' && pomocni_string[j] <= 'Z' || (pomocni_string[j] >= 0 && pomocni_string[j] <= '9')) {
                        if(pomocni_string[j-1] == ' ' || (pomocni_string[j-1] < 'A' || pomocni_string[j-1] > 'Z')) {
                            pocetak = j;
                            while(pomocni_string[j] >= 'A' && pomocni_string[j] <= 'Z' || (pomocni_string[j] >= '0' && pomocni_string[j] <= '9')) {
                                pomocna_rijec.push_back(pomocni_string[j]);
                                j++;
                            }

                        }
                    }

                } else {
                    pocetak = j;
                    while(pomocni_string[j] >= 'A' && pomocni_string[j] <= 'Z' || (pomocni_string[j] >= '0' && pomocni_string[j] <= '9')) {
                        pomocna_rijec.push_back(pomocni_string[j]);
                        j++;
                    }

                }

                skup_u_mapi.insert(std::make_tuple(it->first,i+1,pocetak));
                for(int k = j; k < pomocni_string.size(); k++) {
                    if(pomocni_string[k] == pomocna_rijec[0] && (pomocni_string[k-1] == ' '
                            || pomocni_string[k-1] < 'A' || pomocni_string[k-1] > 'Z')) {
                        int l(0);
                        int pocetak1(k);
                        while(pomocni_string[k] == pomocna_rijec[l]) {
                            k++;
                            l++;
                            if(k == pomocni_string.size() - 1) break;
                            if(l == pomocna_rijec.size() - 1) break;
                        }
                        if(l == pomocna_rijec.size()-1) {
                            skup_u_mapi.insert(std::make_tuple(it->first,i+1,pocetak1));
                        }
                    }

                }
                PretvoriUMala(pomocna_rijec);
               
               mapa_koja_se_vraca.insert({pomocna_rijec,skup_u_mapi});
            }

        }
        
        it++;
    }
    return mapa_koja_se_vraca;
}

//Implementacija funckija "PretraziIndeksPojmova"
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string s, std::map<std::string, std::vector<std::string>> &Mapa)
{

    //Deklaracija skupa ciji su elementi trojke(naziv_poglavlja,index_stranice,index_rijeci)
    std::set<std::tuple<std::string,int,int>> skup;

    //Deklaracija i inicijalizacija iteratora na pocetak mape koja predstavlja index pojmova
    auto it(Mapa.begin());

    //Prolazak kroz mapu koja predstavlja index pojmova
    while(it != Mapa.end()) {

        //Deklaracija i inicijalizacija pomocnog vektora, na vektor stringova(sadrzaja stranica knjige)
        std::vector<std::string> pomocni_vektor(it->second);

        //Prolazak kroz prethodno definirani pomocni vektor
        for(int i = 0; i < pomocni_vektor.size(); i++) {

            //Deklaracija i inicijalizacija pomocnog stringa, na (i-ti) element pomocnog vektora
            std::string pomocni_string(pomocni_vektor[i]);

            //Prolazak kroz prethodno definirani pomocni string
            for(int j = 0; j < pomocni_string.size(); j++) {
                if(j != 0) {
                    if(pomocni_string[j] == s[0] && (pomocni_string[j-1] == ' '||
                                                     pomocni_string[j-1] < 'A' || pomocni_string[j-1] > 'Z')) {
                        int l(0);
                        int pocetak1(j);
                        while(pomocni_string[j] == s[l]) {
                            j++;
                            l++;
                            if(j == pomocni_string.size() - 1) break;
                            if(l == s.size() - 1) break;
                        }
                        if(l == s.size() - 1 && pomocni_string[j] >= 'A' && pomocni_string[j] <= 'Z')
                            throw std::logic_error("Unesena rijec nije nadjena!");
                        if(l == s.size() - 1) {
                            skup.insert(std::make_tuple(it->first,i+1,pocetak1));
                        }

                    }
                } else {
                    if(pomocni_string[j] == s[0]) {
                        int l(0);
                        int pocetak1(j);
                        while(pomocni_string[j] == s[l]) {
                            j++;
                            l++;
                            if(j == pomocni_string.size() - 1) break;
                            if(l == s.size() - 1) break;
                        }
                        if(l == s.size() - 1) {
                            skup.insert(std::make_tuple(it->first,i+1,pocetak1));
                        }
                    }

                }
                /*
                //Trazenje stringa s unutar pomocnog stringa
                if(pomocni_string[j] == s[0]) {
                    int k(0);
                    int pozicija(j);
                    while(pomocni_string[j] == s[k]) {
                        j++;
                        k++;
                    }
                    //Insertovanje trojke u skup(ukoliko je pronadjen trazeni string)
                    if(k == s.size() - 1) {
                        skup.insert(std::make_tuple(it->first,i,pozicija));
                    } else if(j = pomocni_string.size()) throw std::logic_error("Pojam nije nadjen");
                }
                */
            }

        }
        it++;
    }
    return skup;
}
//Implementacija funkcije "IspisiIndeksPojmova"
void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string,int,int>>> &IndexPojmova)
{

    for(auto x: IndexPojmova) {
        std::cout << x.first << ": ";
        int brojac_parova(0);
        for(auto y: x.second) {
            std::cout << std::get<0>(y) << "/" << std::get<1>(y) << "/" << std::get<2>(y);
            brojac_parova++;
            if(brojac_parova == x.second.size()) continue;
            std::cout << ", ";
        }
        std::cout << std::endl;
    }

}
int main ()
{

    std::string naziv_poglavlja;
    std::string sadrzaj;
    std::map<std::string, std::vector<std::string>> knjiga;
    std::vector<std::string> pomocni;
    do {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin,naziv_poglavlja);
        if(naziv_poglavlja == ".") break;
        int i(1);
        do {
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin,sadrzaj);
            if(sadrzaj == ".") break;
            pomocni.push_back(sadrzaj);
            i++;

        } while(sadrzaj != ".");
        knjiga.insert({naziv_poglavlja,pomocni});
    } while (naziv_poglavlja != ".");

    std::cout << "\nKreirani indeks pojmova:\n";
    std::map<std::string, std::set<std::tuple<std::string,int,int>>> indekspojmova(KreirajIndeksPojmova(knjiga));
    IspisiIndeksPojmova(indekspojmova);

    try {
        std::string rijec;
        do {
            std::cout << "Unesite rijec: ";
            std::getline(std::cin,rijec);
            if(rijec == ".") break;
            std::set<std::tuple<std::string,int,int>>pretraga(PretraziIndeksPojmova(rijec,knjiga));
            int brojac(0);
            for(auto x: pretraga) {
                std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x);
                brojac++;
                //brojac_parova++;
                //if(brojac_parova == x.second.size()) continue;
                std::cout << " ";
            }
            if(brojac == 0) std::cout << "Unesena rijec nije nadjena!";
            std::cout << std::endl;
        } while(rijec != ".");
    } catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
