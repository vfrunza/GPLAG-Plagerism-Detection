#include <set>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
using std::cout;
using std::cin;
using std::endl;
bool Znak(char c)
{
    if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'))
        return false;
    else return true;
}
std::string rijec(int i, std::string s)
{
    std::string p;
    while(i<s.size() && !Znak(s[i])) {
        p.push_back(tolower(s[i]));
        i++;
    }
    return p;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> M;
    int i {};
    while(i<s.size()) {
        while(Znak(s[i]) && i<s.size())
            i++;
        if(i==s.size())
            break;
        std::string p=rijec(i,s);
        auto it = M.find(p);
        if (it != M.end()) it->second.insert(i);
        else M.insert(std::make_pair(p,std::set<int>  {i}));
        i+=p.size();
    }
    return M;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> M)
{
    std::set<int> S;
    auto it = M.find(s);
    if (it != M.end()) {
        S=it->second;
    } else throw std::logic_error("Pojam nije nadjen");
    return S;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> M)
{
    for(auto it = M.begin(); it != M.end(); it++) {
        cout<<it->first<<": ";
        auto ita=it->second.begin();
        while(ita!=it->second.end()) {
            ita++;
            if(ita==it->second.end()) {
                ita--;
                cout<<*ita;
                break;
            } else {
                ita--;
                std::cout <<*ita<<",";
            }
            ita++;

        }

        cout<<endl;
    }
}
int main ()
{
    std::map<std::string, std::set<int>> M;
    cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    M=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(M);
    for(;;) {
        cout<<"Unesite rijec: ";
        std::string s;
        std::getline(std::cin, s);
        if(s==".")
            break;
        try {
            std::set<int> S;
            S=PretraziIndeksPojmova(s,M);
            for(auto it: S)
                cout<<it<<" ";
            cout<<endl;
        } catch(...) {
            cout<<"Unesena rijec nije nadjena!"<<endl;
            
        }
    }
    return 0;
}