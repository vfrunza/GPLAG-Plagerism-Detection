#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <list>
#include <set>

int BrojSlova (std::string ime_djeteta) {
    int brs(0);
    for (int i(0); i<ime_djeteta.length(); i++) {
        if ((ime_djeteta.at(i)>='A' && ime_djeteta.at(i)<='Z') || 
                (ime_djeteta.at(i)>='a' && ime_djeteta.at(i)<='z') ||
                    (ime_djeteta.at(i)>='0' && ime_djeteta.at(i)<='9'))
            brs++;
    }
    return brs;
}

std::vector<int> NapraviTimove (int broj_djece, int broj_timova) {
    std::vector<int> Timski;
    int prv(broj_djece%broj_timova);
    int A_T (int (broj_djece/broj_timova)+1);
    int help_tim(broj_timova);
    while (prv!=0) {
        Timski.push_back(A_T);
        prv--;
        help_tim--;
    }
    int B_T(int (broj_djece/broj_timova));
    while (help_tim!=0) {
        Timski.push_back(B_T);
        help_tim--;
    }
    return Timski;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> ime_djece, int broj_timova) {
    if (broj_timova>ime_djece.size() || broj_timova<1) 
        throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> tim;
    std::list<std::string> lista_id;
    for (int i(1); i<ime_djece.size(); i++) 
        lista_id.push_back(ime_djece.at(i));
    auto Vt_vektor(NapraviTimove(ime_djece.size()-1, broj_timova));
    auto it (lista_id.begin());
    while (lista_id.size()!=0) {
        for (int i(0); i<broj_timova; i++) {
            std::set<std::string> pomocni;
            for (int j(0); j<Vt_vektor.at(i);j++) {
                pomocni.insert(*it);
                int x = BrojSlova(*it);
                it=lista_id.erase(it);
                if (it==lista_id.end())
                    it=lista_id.begin();
                for (auto z(0); z<x-1; z++) {
                    it++;
                    if (it==lista_id.end())
                        it=lista_id.begin();
                }
            }
            tim.push_back(pomocni);
        }
    }
    return tim;
}

int main () {
    std::cout<<"Unesite broj djece: ";
    int brdj(0);
    try {
        std::cin>>brdj;
        if (!std::cin)
            throw;
    }
    catch (...) {
        return 0;
    }
    std::cout<<"Unesite imena djece: \n";
    std::vector<std::string> imena_djece;
    
    try {
        for (int i(0); i<=brdj; i++) {
            std::string pomocni;
            std::getline(std::cin, pomocni);
            imena_djece.push_back(pomocni);
        }
        std::cout<<"Unesite broj timova: ";
        int br_timova(0);
        std::cin>>br_timova; 
        auto timovi (Razvrstavanje(imena_djece, br_timova));
        for (int i(0); i<timovi.size(); i++) {
            std::cout << "Tim "<<i+1<<": ";
            int br(timovi.at(i).size());
            for (auto x : timovi.at(i)) {
                if (br!=1)
                    std::cout<<x<<", ";
                else 
                    std::cout<<x;
                br--;
            } 
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
} 