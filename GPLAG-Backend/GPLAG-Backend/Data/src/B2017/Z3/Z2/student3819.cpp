/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga; //poglavlje 1,I,etc. <vector.at(stranicaPoglavlja) = text>
typedef std::multimap<std::string, std::vector<std::tuple<std::string, int, int>>> tjt; //rijec u txtu <poglavlje, stranica, indeks rijeci>

tjt KreirajIndeksPojmova(Knjiga k) {
    tjt aye;
    std::string word;
    for(auto it = k.begin(); it != k.end(); it++) {
        for(int i = 0; i < it->second.size(); i++) {
            for(int j = 0; j < it->second.at(i).size(); j++) {
                if((it->second.at(i).at(j) >= 65 && it->second.at(i).at(j) <= 90) || (it->second.at(i).at(j) >= 97 && it->second.at(i).at(j) <= 122)) {
                    word += it->second.at(i).at(j);
                    if(it->second.at(i).size() > j + 1)
                        if((it->second.at(i).at(j + 1) >= 65 && it->second.at(i).at(j + 1) <= 90) || (it->second.at(i).at(j + 1) >= 97 && it->second.at(i).at(j + 1) <= 122)) continue;
                    aye.insert(std::make_pair(word, std::make_tuple(it->first, i, j - word.size())));
                }
            }
        }
    }
    return aye;
}



int main ()
{
	return 0;
}
