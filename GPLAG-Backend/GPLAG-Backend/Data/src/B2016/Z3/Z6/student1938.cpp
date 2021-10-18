#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <memory>
#include <stdexcept>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
void pomjer(std::shared_ptr<Dijete> &tmp,std::shared_ptr<Dijete> &tmpEnd){
    int n(-1);
    for(int i = 0; i < (tmp->ime).length(); i++)
        if((tmp->ime[i] >= '0' && tmp->ime[i] <= '9') || (tmp->ime[i] >= 'A' && tmp->ime[i] <= 'Z')
        || (tmp->ime[i] >= 'a' && tmp->ime[i] <= 'z' )) n++;
    tmpEnd->sljedeci = tmp->sljedeci;
    auto del(tmp);
    tmp = tmp-> sljedeci;
    if(tmp == tmpEnd) {del->sljedeci = nullptr; return;}
    del = nullptr;
    for(int i = 0; i < n; i++){
        tmp = tmp->sljedeci; tmpEnd = tmpEnd->sljedeci;
    }
}

void help(std::shared_ptr<Dijete> &tmp,std::shared_ptr<Dijete> &tmpEnd, int num, int pos, std::vector<std::set<std::string>> &ret){
    for(int i = 0; i < num; i++) {
        ret[pos].insert(tmp->ime);
        pomjer(tmp,tmpEnd);
    }
}
std::shared_ptr<Dijete> oGod(std::vector<std::string> &v){
    if(v.size() == 0) return nullptr;
        std::shared_ptr<Dijete> start(nullptr), prev;
    try{
        for(int i = 0; i < v.size(); i++){
            auto neww(std::make_shared<Dijete>());
            (*neww).ime = v[i]; 
            if(i == 0) start = neww;
            else prev->sljedeci = neww;
            if(i + 1 == v.size()) neww->sljedeci = start;
            prev = neww;
        }
    }catch(std::bad_alloc){
        if(start)
        start->sljedeci = nullptr;
        throw;
    }
    return start;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    if(k > v.size() || k < 1 ) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> ret(k); int n(v.size());
    auto tmp(oGod(v));
    std::shared_ptr<Dijete> tmpEnd;
    for(tmpEnd = tmp->sljedeci; tmpEnd->sljedeci != tmp; tmpEnd = tmpEnd->sljedeci);
    int prvi = n%k; int prviNum = n/k + 1;
    int drugi = k - n%k; int drugiNum = n/k;
    for(int i = 0; i < prvi; i++) help(tmp,tmpEnd, prviNum, i, ret);
    for(int i = 0; i < drugi; i++) help(tmp,tmpEnd,drugiNum,i+prvi,ret);
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
        std::cout << "Izuzetak: " << err.what();
    }
	return 0;
}