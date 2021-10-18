/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
using std::set;
using std::list;
using std::vector;
using std::string;

vector<set<string>> Razvrstavanje (vector<string> v_djece, int br_timova) {
    if (br_timova<1 || br_timova>v_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    vector<set<string>> v_timova(br_timova);
    list<string> l_djece;
    for (int i=0; i<v_djece.size(); i++)
        l_djece.push_back(v_djece[i]);
    auto it=l_djece.begin();
    for (int i=0; i<v_djece.size()%br_timova; i++) {
        int brojac(0);
        while (brojac<v_djece.size()/br_timova+1) {
            v_timova[i].insert(*it);
            brojac++;
            int duzina(0);
            for (int j=0; j<(*it).length(); j++) {
                if (((*it)[j]>='A' && (*it)[j]<='Z') || ((*it)[j]>='a' && (*it)[j]<='z') || ((*it)[j]>='0' && (*it)[j]<='9'))
                    duzina++;
            }
            it=l_djece.erase(it);
            if (l_djece.begin()==l_djece.end())
                break;
            if (it==l_djece.end())
                it=l_djece.begin();
            for (int j=0; j<duzina-1; j++) {
                it++;
                if (it==l_djece.end())
                    it=l_djece.begin();
            }
            if (it==l_djece.end())
                it=l_djece.begin();
        }
    }
    for (int i=v_djece.size()%br_timova; i<br_timova; i++) {
        int brojac(0);
        while (brojac<v_djece.size()/br_timova) {
            v_timova[i].insert(*it);
            brojac++;
            int duzina(0);
            for (int j=0; j<(*it).length(); j++) {
                if (((*it)[j]>='A' && (*it)[j]<='Z') || ((*it)[j]>='a' && (*it)[j]<='z') || ((*it)[j]>='0' && (*it)[j]<='9'))
                    duzina++;
            }
            it=l_djece.erase(it);
            if (l_djece.begin()==l_djece.end())
                break;
            if (it==l_djece.end())
                it=l_djece.begin();
            for (int j=0; j<duzina-1; j++) {
                it++;
                if (it==l_djece.end())
                    it=l_djece.begin();
            }
            if (it==l_djece.end())
                it=l_djece.begin();
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