/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <stdexcept>
#include <list>

int BrojSlova(std::string s){
    int br(0);
        for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            br++;
        }
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, int k){
    int n(s.size());
    std::vector<int> v(n);
    if(k<1 || k>n){
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    for(int i=1;i<=k;i++){
    if(n%k==0){
        v[i]=n/k;
    }
    if(n%k!=0){
        if(i<=n%k){
            v[i]=n/k+1;
        }
        if (i>n%k) {
            v[i]=n/k;
        }
    }
}

std::list<std::string> l;
std::vector<std::set<std::string>> skupovi;
for(int i=0;i<s.size();i++)
l.push_back(s[i]);
for (auto it(l.begin());;it++) {
    if(it==l.end())
    it=l.begin();
    int br(0);
    for(int i=0;i<k;i++){
        br=BrojSlova(*it);
        std::advance(it,br);
        for(int j=0;j<v[i];j++){
            skupovi.push_back(*it);
            it=l.erase(it);
        }
    }
}
return skupovi;
}
int main ()
{
    try{
    int n,k;
    std::cout <<"Unesite broj djece: ";
    std::cin>>n;
    std::vector<std::string>v(n);
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
   auto f=Razvrstavanje(v,k);
   for(int i=0;i<k;i++){
       std::cout<<f[i]<<" ";
   }
    }
    catch(std::logic_error Greska){
        std::cout<<Greska.what();
    }
	return 0;
}