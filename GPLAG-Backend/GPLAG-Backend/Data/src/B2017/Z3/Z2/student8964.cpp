/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::string PretvoriUMala (std::string s) {
    std::string mala_s(s);
    for(int i = 0; i < mala_s.length(); i++) 
        if((mala_s.at(i) >= 'A' && mala_s.at(i) <= 'Z') || (mala_s.at(i) >= 'a' && mala_s.at(i) <= 'z'))    mala_s.at(i) += 'a' - 'A'; 
    return mala_s;
}

std::map<std::string, std::multiset<std::tuple<std::string, int, int>>> KreirajIndeksPojmova (Knjiga book) {
    std::map<std::string, std::multiset<std::tuple<std::string, int, int>>> finalna;
    for(auto it(book.begin()); it != book.end(); it++) {
        for(auto it2(book[it].begin()); it2 != book[it].end(); it2++) {
            for(auto it3(book[it][it2].begin()); it3 != book[it][it2].end(); it3++) {
                while(!((*it3 >='A' && *it3 <= 'Z') || (*it3 >= 'a' && *it3 <= 'z') || (*it3 >= '0' && *it3 <= '9')) && it3 != book[it][it2].end())    it3++;
                if(((*it3 >='A' && *it3 <= 'Z') || (*it3 >= 'a' && *it3 <= 'z'))) {
                    std::string pomocni = '';
                    while(it3 != book[it][it2].end() && ((*it3 >='A' && *it3 <= 'Z') || (*it3 >= 'a' && *it3 <= 'z') || (*it3 >= '0' && *it3 <= '9'))) {
                        pomocni.push_back(*it3);
                        it3++;
                    }

                }
            }
        }
    }
}
    
    
    pomocna.insert(book->first, book->second);
    
}
    
    
    
    
    
    for(auto it1 = k.begin(); it1 != k.end(); it1++) { //poglavlje
        for(auto it2 = k[it1].begin(); it2 != k[it1].end(); it2++) { //i-ta stranica i-tog poglavlja 
            for(int i = 0; i < k[it1][it2].length(); i++) { //prvi string na i-toj stranici
                while(k -> second )
            t = std::make_tuple(*it1, *it2 + 1, )
            finalna.insert()
            }
        }
    }
}

int main ()
{
	return 0;
}
