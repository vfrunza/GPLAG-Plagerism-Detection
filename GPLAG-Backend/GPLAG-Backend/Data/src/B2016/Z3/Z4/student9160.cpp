#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

int DajKorakRazbrajanja (const std::string &ime) {
    auto itt(ime.begin()); int count(0);
    while (itt!=ime.end()) if ((std::toupper(*itt)>='A' && std::toupper(*itt)<='Z') || (*itt>='0' && *itt<='9')) count++, itt++;
    return count-1;
}

int DajBroj(const std::list<std::string> &lista) {
    auto it(lista.begin()); int broj(0);
    while (it!=lista.end()) broj++, it++;
    return broj;
}

void SetOut (const std::set<std::string> &s) {
    auto it(s.begin());
    std::cout << *it++; while (it!=s.end()) std::cout << ", " << *it++;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> n, int k) {
    if (k<1 || k>(int)(n.size())) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vrati;
    bool Is = false;
    std::list<std::string> kids; for (auto x : n) kids.push_back(x);
    int valuex(n.size()%k);
    int valuey(n.size()/k);
    std::deque<int> teams_num;
    int i(0), j(0);
    int odcount(valuex);
    while(i < k) {
        if(odcount!=0) {
            teams_num.push_back(valuey+1);
            odcount--;
            i++;
            continue;
        }
        teams_num.push_back(valuey);
        i++;
    }
    
    auto it(kids.begin());
    int count(0);
    std::set<std::string> team, empty;
    while (1) {
        
        if (count < teams_num.at(j)) {
            team.insert(*it);
            int korak = DajKorakRazbrajanja(*it);
            count++;
            it = kids.erase(it);
            if(it == kids.end()) it = kids.begin();
            int numero = DajBroj(kids);
            if (numero == teams_num[teams_num.size()-1]) {
                vrati.push_back(team);
                team = empty;
                it = kids.begin();
                for (int w = 0; w < numero; w++) team.insert(*it), it++;
                vrati.push_back(team);
                Is = true;
            }
            
            if(!Is) {
                for (int i = 0; i < korak; i++) {//korak - 1
                    it++;
                    if (it==kids.end()) it = kids.begin();
                }
            }
            
        }
        
        if (Is) {
            count = teams_num[j];
            if (count == teams_num[j]) {
                if (Is) break;
                vrati.push_back(team);
                j++;
                team = empty;
                count = 0;
            }
        }
        
        
    }
    
    return vrati;
}

int main () {
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> kids(n);
    for (int i = 0; i < n; i++) std::getline(std::cin, kids[i]);
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k; 
    try {
        auto ispisi(Razvrstavanje(kids, k));
        for (int i = 0; i < k; i++) {
            std::cout << "Tim " << i+1 << ": ";
            SetOut(ispisi[i]);
            std::cout << std::endl;
        }
    } catch(std::logic_error err) {
        std::cout << "Izuzetak: " << err.what();
    }
	return 0;
}