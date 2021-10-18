#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
#include <iterator>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vs, int n) {
    if(n<1 or n>vs.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int temp1(vs.size()%n), temp2(vs.size()/n);
    int x((vs.size()-temp1*(temp2+1))/temp2);
    std::vector<std::set<std::string>> vss(temp1+x);
    std::list<std::string> ls;
    for(int i(0); i<vs.size(); i++) ls.push_back(vs[i]);
    std::list<std::string>::iterator it(ls.begin());
    int i(0), broj_djece(0);
    while(ls.size()!=0) {
        if(it==ls.end()) it = ls.begin();
        int broj_pomjeranja(0);
        if(broj_djece<temp2+1 and i<temp1) {
            vss[i].insert(*it);
            broj_djece++;
        } else if(broj_djece==temp2+1 and i<temp1){
            broj_djece=0;
            i++;
            vss[i].insert(*it);
            broj_djece++;
        } else if(i>=temp1) {
            if(broj_djece<temp2) {
                vss[i].insert(*it);
                broj_djece++;
            } else if(broj_djece==temp2) {
                broj_djece=0;
                i++;
                vss[i].insert(*it);
                broj_djece++;
            }
        }
        for(int j(0); j<(*it).length(); j++)
            if(!((*it)[j]<'0' or ((*it)[j]>'9' and (*it)[j]<'A') or ((*it)[j]>'Z' and (*it)[j]<'a') or (*it)[j]>'z'))
                broj_pomjeranja++;
        broj_pomjeranja-=1;
        it=ls.erase(it);
        while(broj_pomjeranja>0) {
            if(it==ls.end()) it = ls.begin();
            it++; broj_pomjeranja--;
            if(it==ls.end()) it = ls.begin();
        }
    }
    return vss;
}

int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::vector<std::string> vs(n);
    std::cout << "Unesite imena djece:" << std::endl;
    std::cin.ignore(1000, '\n');
    for(int i(0); i<n; i++)
        std::getline(std::cin, vs[i]);
    int m;
    std::cout << "Unesite broj timova: ";
    std::cin >> m;
    try {
        std::vector<std::set<std::string>> vss = Razvrstavanje(vs, m);
        for(int i(0); i<vss.size(); i++) {
            std::cout << "Tim " << i+1 << ": ";
            for(auto it(vss[i].begin()); it!=vss[i].end(); it++) {
                if(*it==*(vss[i].rbegin())) {
                    std::cout << *it;
                    break;
                }
                std::cout << *it << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error a) {
        std::cout << "Izuzetak: " << a.what() << std::endl;
    }
	return 0;
}