#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> pretvori_u_vektor (std::string s) {
    std::vector<std::string> vektor ;
    int d=0;
    for(int i=0;i<s.length();i++) {
        int k=i;
        while(s[i]!=' ') i++;
        std::string help;
        for(int j=k;j<i;j++) help.push_back(s[j]);
        while(s[i]==' ') i++;
        vektor[d]=help;
        d++;
    }
    return vektor;
}

int check (std::vector<std::string> v, int k) {
    for(int i=0;i<v.size();i++) {
        if(i==k) continue;
        if(v[i]==v[k]) return i;
    }
    return -1;
}

void izbaci_duplikate (std::vector<std::string> &v) {
    for(int i=0;i<v.size();i++) {
        int d=check(v,i);
        if(check(v,i)!=-1) {
            for(int j=d;j<v.size()-1;j++) {
                v[j]=v[j+1];
            }
            v.resize(v.size()-1);
            i--;
        }
    }
}

std::map<std::string,std::set<int>> KreirajIndexPojmova (std::string s) {
    auto v=izbaci_duplikate(s);
} 

int main () {
    std::cout << "Unesite rijec: " ;
    std::string s;
    std::getline(std::cin,s);
    auto mapica=KreirajIndexPojmova(s);
	
	return 0;
}