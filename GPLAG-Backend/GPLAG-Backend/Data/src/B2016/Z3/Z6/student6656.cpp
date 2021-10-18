/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>
using std::set;
using std::vector;
using std::string;

struct Dijete {
    string ime;
    std::shared_ptr<Dijete> sljedeci;
};

vector<set<string>> Razvrstavanje (vector<string> v_djece, int br_timova) {
    if (br_timova<1 || br_timova>v_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    vector<set<string>> v_timova(br_timova);
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni(nullptr);
    for (int i=0; i<v_djece.size(); i++) {
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete> ());
        novi->ime=v_djece[i];
        novi->sljedeci=nullptr;
        if (!pocetak)
            pocetak=novi;
        else
            prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    for (int i=0; i<v_djece.size()%br_timova; i++) {
        int brojac(0);
        while (brojac<v_djece.size()/br_timova+1) {
            v_timova[i].insert(pocetak->ime);
            brojac++;
            int duzina(0);
            for (int j=0; j<pocetak->ime.length(); j++) {
                if (((pocetak->ime)[j]>='A' && (pocetak->ime)[j]<='Z') || ((pocetak->ime)[j]>='a' && (pocetak->ime)[j]<='z') || ((pocetak->ime)[j]>='0' && (pocetak->ime)[j]<='9'))
                    duzina++;
            }
            prethodni->sljedeci=pocetak->sljedeci;
            pocetak=prethodni->sljedeci;
            if (pocetak==prethodni)
                break;
            for (int j=0; j<duzina-1; j++) {
                pocetak=pocetak->sljedeci;
                prethodni=prethodni->sljedeci;
            }
        }
    }
    for (int i=v_djece.size()%br_timova; i<br_timova; i++) {
        int brojac(0);
        while (brojac<v_djece.size()/br_timova) {
            v_timova[i].insert(pocetak->ime);
            brojac++;
            int duzina(0);
            for (int j=0; j<pocetak->ime.length(); j++) {
                if (((pocetak->ime)[j]>='A' && (pocetak->ime)[j]<='Z') || ((pocetak->ime)[j]>='a' && (pocetak->ime)[j]<='z') || ((pocetak->ime)[j]>='0' && (pocetak->ime)[j]<='9'))
                    duzina++;
            }
            prethodni->sljedeci=pocetak->sljedeci;
            if (pocetak==prethodni) {
                pocetak->sljedeci=nullptr;
                break;
            }
            pocetak=prethodni->sljedeci;
            for (int j=0; j<duzina-1; j++) {
                pocetak=pocetak->sljedeci;
                prethodni=prethodni->sljedeci;
            }
        }
    }
    return v_timova;
}

int main ()
{
	try {
        int br_djece;
        std::cout << "Unesite broj djece: ";
        std::cin >> br_djece;
        std::cin.ignore (10000, '\n');
        vector<string> v_djece(br_djece);
        std::cout << "Unesite imena djece: " << std::endl;
        for (int i=0; i<br_djece; i++)
            std::getline (std::cin, v_djece[i]);
        int br_timova;
        std::cout << "Unesite broj timova: ";
        std::cin >> br_timova;
        vector<set<string>> timovi(Razvrstavanje(v_djece, br_timova));
        vector<vector<string>> pomocni(timovi.size());
        for (int i=0; i<timovi.size(); i++) {
            for (auto it=timovi[i].begin(); it!=timovi[i].end(); it++)
                pomocni[i].push_back(*it);
        }
        for (int i=0; i<pomocni.size(); i++) {
            std::cout << "Tim " << i+1 << ": ";
            for (int j=0; j<pomocni[i].size(); j++) {
                if (j<pomocni[i].size()-1)
                    std::cout << pomocni[i][j] << ", ";
                else
                    std::cout << pomocni[i][j];
            }
            std::cout << std::endl;
        }
    }
    catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}