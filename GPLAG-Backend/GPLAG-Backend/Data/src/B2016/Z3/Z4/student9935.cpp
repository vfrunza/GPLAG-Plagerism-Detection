/B2016/2017: Zadaća 3, Zadatak 4
#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<set>
#include<stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, int k){
    if(k<1 || k>s.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    int n(s.size()%k);
    int n1((s.size()/k)+1);
    int n2(s.size()/k);
    std::vector<std::set<std::string>> v;
    std::list<std::string> l;
    for(int i=0; i<s.size(); i++)
        l.push_back(s[i]);
    std::set<std::string> skup1;
    std::set<std::string> skup2;
    auto it1(l.begin());
    for(;;){
        std::string pomocna(*it1);
        if(v.size()<n){
            if(skup1.size()<n1)
                skup1.insert(pomocna);
            if(skup1.size()==n1){
                v.push_back(skup1);
                skup1.clear();
            }
        }
        else{
            if(skup2.size()<n2)
                skup2.insert(pomocna);
            if(skup2.size()==n2){
                v.push_back(skup2);
                skup2.clear();
            }
        }
        it1=--l.erase(it1);
        for(int i=0; i<pomocna.size(); i++){
            if(pomocna[i]!=' ')
                it1++;
            if(it1==l.end())
                it1=l.begin();
        }
        if(it1==l.end())
            it1=l.begin();
        if(l.size()==0)
            break;
    }
    return v;
}
int main (){
    int n, k;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::vector<std::string> v;
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++){
        std::string ime;
        std::getline(std::cin, ime);
        v.push_back(ime);
    }
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
    try{
        std::vector<std::set<std::string>> timovi(Razvrstavanje(v,k));
        for(int i=0; i<timovi.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            auto it=timovi[i].begin();
            for(; it!=--timovi[i].end(); it++)
                std::cout<<*it<<", ";
            std::cout<<*it<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}