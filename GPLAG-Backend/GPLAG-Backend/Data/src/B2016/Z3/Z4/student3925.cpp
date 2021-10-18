/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <list>
#include <set>

std::vector<int> brojclanovautimu(int n, int k){ // k broj timova, n broj ljudi
    std::vector<int> v;
    int o=n%k;
    for(int i(0);i<o;i++){
        v.push_back(int(n/k)+1);
    }
    o=k-o;
    for(int i(0);i<o;i++){
        v.push_back(int(n/k));
    }
    return v;
}

bool dalijeslovo(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
    return false;
}

bool dalijebroj(char c){
    return c>='0' && c<='9';
}

int brojslovaimena(std::string s){
    int br(0);
    for(int i(0);i<s.size();i++){
        if(!(dalijebroj(s[i])) && !(dalijeslovo(s[i]))) br++;
    }
    return s.size()-br;
}


std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vs, int k){ //k je broj timova
if(k<1 || k>vs.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> l;
    int brojclanova=vs.size();
    std::vector<int> v(brojclanovautimu(brojclanova,k)); // v[0] brojclanova 1. tima, v[1] drugog...
    std::vector<std::set<std::string>> w(k); //ovo vracam, push_back(w[j]);
    int j(0);
    for(int i(0);i<vs.size();i++){
        l.push_back(vs[i]);
    }
    int s;
    auto it=l.begin();
    int x(0);
    while(l.size()!=0){
        s=brojslovaimena(*it);
        w[j].insert(*it);
        if(it==l.end()) it=l.begin();
        it=l.erase(it);
        if(it==l.end()) it=l.begin();
        x++;
        if(x==v[j]){
            x=0;
            j++;
        }
        for(int i(0);i<s-1;i++){
            it++;
            if(it==l.end()) it=l.begin();
        }
        
    }
    
    
    return w;
    
}


int main ()
{
    std::cout << "Unesite broj djece: ";
    int a;
    std::cin >> a;
    std::vector<std::string> v ;
    std::string s;
    std::cout << "Unesite imena djece:" << std::endl;
    std::cin.ignore(10000,'\n');
    for(int i(0);i<a;i++){
        std::getline(std::cin,s);
        v.push_back(s);
    }
    
    std::cout << "Unesite broj timova: ";
    int n;
    std::cin>> n;
    try{
    auto vs=Razvrstavanje(v,n);
    for(int i(0);i<vs.size();i++){
        std::cout << "Tim "<<i+1<<": ";
        bool prvi=true;
        for(auto j:vs[i]){
            if(prvi) prvi=false;
            else std::cout << ", ";
            std::cout << j ;
    }
    std::cout <<  std::endl;
    }
    }
    catch(std::logic_error izuzetak){
        std::cout <<"Izuzetak: "<< izuzetak.what();
    }
	return 0;
}