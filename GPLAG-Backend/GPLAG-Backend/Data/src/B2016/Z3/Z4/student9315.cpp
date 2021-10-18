#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

void pomjer(std::list<std::string> &tmp, std::list<std::string>::iterator &eci){
    int n(-1);
    for(int i = 0; i < (*eci).length(); i++)
        if(((*eci)[i] >= '0' && (*eci)[i] <= '9') || ((*eci)[i] >= 'A' && (*eci)[i] <= 'Z') || ((*eci)[i] >= 'a' && (*eci)[i] <= 'z' ))
            n++;
    eci = tmp.erase(eci); if(eci == tmp.end()) eci = tmp.begin();
    for(int i = 0; i < n; i++){
        eci++;
        if(eci == tmp.end()) eci = tmp.begin();
    }
}
void help(std::list<std::string> &tmp, std::list<std::string>::iterator &eci, int num, int pos, std::vector<std::set<std::string>> &ret){
    for(int i = 0; i < num; i++) {
        ret[pos].insert(*eci);
        pomjer(tmp,eci);
    }
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    if(k> v.size() || k< 1) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> ret(k); int n(v.size());
    std::list<std::string> tmp;
    for(int i = 0; i < v.size(); i++) tmp.push_back(v[i]);
    std::list<std::string>::iterator it(tmp.begin());
    int prvi = n%k; int prviNum = n/k + 1;
    int drugi = k - n%k; int drugiNum = n/k;
    for(int i = 0; i < prvi; i++) help(tmp, it, prviNum, i, ret);
    for(int i = 0; i < drugi; i++) help(tmp,it,drugiNum,i+prvi,ret);
    return ret;
}

int main (){
    try{
        std::cout << "Unesite broj djece: "; 
        int n; std::cin >> n;
        std::cin.ignore(100,'\n');
        std::cout << "Unesite imena djece: \n";
        std::vector<std::string> v(n);
        for(int i = 0; i < n; i++) std::getline(std::cin, v[i]);
        std::cout << "Unesite broj timova: ";
        int k; std::cin >> k;
        auto ret(Razvrstavanje(v, k));
        for(int i = 0; i < k; i++){
            std::cout << "Tim " << i + 1 << ":";
            for(auto it = ret[i].begin();;){
                std::cout << " " << *it++;
                if(it == ret[i].end()) break;
                std::cout << ",";
            }
            std::cout << std::endl;
        }
    }catch(std::logic_error err){
        std::cout << "Izuzetak: " <<  err.what();
    }
	return 0;
}