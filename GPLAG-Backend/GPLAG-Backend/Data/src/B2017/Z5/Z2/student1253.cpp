/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <map>

int main ()
{
    std::map<int, int> m;
    std::map<int, int> n;
    m.insert({3, 4});
    m.insert({5, 6});
    n.insert({9,9});
    n.insert({8,8});
    m = n;
    for(auto i = m.begin(); i != m.end(); i++) {
        i-first
    }
    
    for(auto i = m.begin(); i!=m.end() ;i++) {
        std::cout<<i->first<<" "<<i->second;
    }
    return 0;
}
