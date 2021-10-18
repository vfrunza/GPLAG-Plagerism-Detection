/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <stdexcept>

int BrojSlovaUImenu(std::string s) {
    int broj{};
    for (int i=0; i<s.length(); i++) 
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))  
            broj++;
    return broj;
}

std::vector<int> BrojDjeceUTimu(int n, int k) {
    std::vector<int> v;
    int ostatak = n % k;
    for (int i=0; i<ostatak; i++) { int x = (n / k) + 1; v.push_back(x); }
    for (int i=ostatak; i<k; i++) { int x = n / k; v.push_back(x); }
    return v;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int broj) {
    std::vector<std::set<std::string>> tim(broj);
    
    if (broj < 1 || broj > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> djeca;
    for (auto x:v) djeca.push_back(x);
    
    std::vector<int> a = BrojDjeceUTimu(static_cast<int>(v.size()), broj);
    
    int br_slova{};
    
    auto it=djeca.begin();
    
    tim[0].insert(*it);
    br_slova = BrojSlovaUImenu(*it);
    it = djeca.erase(it);
    br_slova--;
    a[0]--;
       
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i]; j++) {
            while (br_slova != 0) {
                it++;
                br_slova--;
                if (it == djeca.end()) it = djeca.begin();
            } 
            tim[i].insert(*it);
            br_slova = BrojSlovaUImenu(*it);
            it = djeca.erase(it);
            br_slova--;
            if (it == djeca.end()) it = djeca.begin();
        }
    }
    
    return tim;
}

int main ()
{
    int n{};
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    
    std::vector<std::string> v;
    
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    std::cout<<"Unesite imena djece: \n";
    for (int i=0; i<n; i++) {
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    
    
    try {
        int broj{};
        std::cout<<"Unesite broj timova: ";
        std::cin>>broj;
    
        std::vector<std::set<std::string>> tim = Razvrstavanje(v, broj);
        for (int i=0; i<tim.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            auto x=tim[i].begin();
            for (auto f:tim[i]) {
                if (x != tim[i].begin()) std::cout<<", ";
                std::cout<<f;
                x++;
            }
        
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    
	return 0;
}






