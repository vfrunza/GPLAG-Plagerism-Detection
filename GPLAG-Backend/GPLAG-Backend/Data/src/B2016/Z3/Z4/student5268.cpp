#include <vector> 
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <utility>
std::vector<std::set<std::string> > Razvrstavanje(std::vector<std::string> v,int n){
    int djece=v.size();
    std::vector<int> brcla(n);
    int baza(djece/n);
    int visak(djece%n);
    for (int i = 0; i < n; i++) {
          brcla[i]=baza;
    }
    int i(0);
    while (visak!=0) {
        brcla[i]++;
        i++;
        visak--;
    }
    std::vector<int> Slova(djece);
    for(int i=0;i<djece;i++){
        auto s(v[i]);
        int b(0);
        for(int j=0;j<s.length();j++){
            if((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z')||(s[j]>='0' && s[j]<='9'))
            b++;
        }
        Slova[i]=b;
    }
    std::list<std::pair<std::string,int>> li;
    for (int i = 0; i < djece; i++) {
        li.push_back(std::make_pair(v[i],Slova[i]));
    }
    std::vector<std::set<std::string>> timovi(n);
       for(int i=0;i<n;i++){
           for(auto it(li.begin());;it++){
               if(it==li.end())
               it=li.begin();
               for(int j=0;j<brcla[i];j++)
               timovi[0].insert(it->first);
               auto pom(it);
               std::advance(it,it->second);
               pom=li.erase(pom);
           }
       }
       return timovi;
} 
int main(){
    std::vector<std::string> A{"ee","djjj","krfoo","zovko","cazim","jovo","KRKO","DAD","ZNO","CCAA","TOTOOTOT","DHDHDH"};
    auto v(Razvrstavanje(A,3));
     for(int i=0;i<A.size();i++)
     for(auto x : A[i])
     std::cout << x << std::endl;
    return 0;
}