/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <tuple>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>

using std::cin;
using std::cout;

typedef std::map<std::string, std::vector<std::string>> Knjiga;

/*void PretvoriUVeliko(Knjiga k) {
    for(auto it=k.begin(); it!=k.end(); it++) {
        auto vektor=it->second;
        for(auto i=vektor.begin(); i!=vektor.end(); i++) {
            for(auto &x:k[it][i]) tolower(x);
        }
    }
}*/

bool JeLiIspravno(char c) {
    return (c>='a'&& c<='z' || c>='0' && c<='9');  
}
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Pojmovi;
Pojmovi KreirajIndeksPojmova(Knjiga k) {
   // PretvoriUVeliko(k);
   Pojmovi povratni;
    for(auto it=k.begin(); it!=k.end(); it++) {
        auto skup=it->second;
        for(auto i=skup.begin(); i!=skup.end(); i++) {
            for(int j=0; j<k[it][i].length(); j++) {
                while(JeLiIspravno(k[it][i][j])) j++;
            }
        }
    }
}


int main ()
{
	return 0;
}
