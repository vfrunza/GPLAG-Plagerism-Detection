#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};
void pomjer(Dijete* &tmp,Dijete* &tmpEnd){
    int n(-1);
    for(int i = 0; i < (tmp->ime).length(); i++)
        if((tmp->ime[i] >= '0' && tmp->ime[i] <= '9') || (tmp->ime[i] >= 'A' && tmp->ime[i] <= 'Z')
        || (tmp->ime[i] >= 'a' && tmp->ime[i] <= 'z' )) n++;
    tmpEnd->sljedeci = tmp->sljedeci;
    auto del(tmp);
    tmp = tmp-> sljedeci;
    if(tmp == tmpEnd) {delete del; return;}
    delete del;
    for(int i = 0; i < n; i++){
        tmp = tmp->sljedeci; tmpEnd = tmpEnd->sljedeci;
    }
}

void help(Dijete* &tmp,Dijete *&tmpEnd, int num, int pos, std::vector<std::set<std::string>> &ret){
    for(int i = 0; i < num; i++) {
        ret[pos].insert(tmp->ime);
        pomjer(tmp,tmpEnd);
    }
}
Dijete *oGod(std::vector<std::string> &v){
    int i;
        if(v.size() == 0) return nullptr;
        Dijete *start(nullptr), *prev;
    try{
        for( i = 0; i < v.size(); i++){
            Dijete *neww(new Dijete); neww->sljedeci = nullptr;
            (*neww).ime = v[i]; 
            if(i == 0) start = neww;
            else prev->sljedeci = neww;
            if(i + 1 == v.size()) neww->sljedeci = start;
            prev = neww;
        }
    }catch(std::bad_alloc){
        auto helper(start);
        for(int j = 0; j < i; j++){
            helper = start; start = start->sljedeci;
            delete helper;
        }
        throw;
    }
    return start;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    if(k > v.size() || k < 1) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> ret(k); int n(v.size());
    auto tmp(oGod(v));
    Dijete *tmpEnd;
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