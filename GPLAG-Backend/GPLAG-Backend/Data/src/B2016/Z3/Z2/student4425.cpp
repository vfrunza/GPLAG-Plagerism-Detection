#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <stdexcept>
#include <utility>
 
bool LetterOrNum (char c) {
    if ((std::toupper(c)>='A' && std::toupper(c)<='Z') || (c>='0' && c<='9')) return true;
    else return false;
}

void Loweruj (std::string &s) {
    auto it(s.begin());
    while (it!=s.end()) *it = std::tolower(*it), it++;
}

void SetOut (const std::set<int> &s) {
    auto it(s.begin());
    std::cout << *it++; while (it!=s.end()) std::cout << "," << *it++; 
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string text) {
    int i(0);
    std::map<std::string, std::set<int>> index;
    while (i < text.length()) {
        bool space(true);
        if (!LetterOrNum(text.at(i))) {
            space = true;
        } else if (space) {
            space = false;
            int j(i);
            while (i < text.length() && LetterOrNum(text.at(i))) i++;
            auto word(text.substr(j, i-j));
            Loweruj(word);
            auto it(index.find(word));
            if (it == index.end()) {
                std::set<int> empty_set;
                empty_set.insert(j);
                index.insert(std::make_pair(word,empty_set));
            } else (it->second).insert(j);
            i--;
        }
        i++;
    }
    return index;
}

std::set<int> PretraziIndeksPojmova (std::string word, const std::map<std::string,std::set<int>> &index) {
    Loweruj(word);
    auto it(index.find(word)); 
    if (it == index.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova (const std::map<std::string,std::set<int>> &index) {
    auto it(index.begin());
    while (it!=index.end()) {
        std::cout << it->first << ": "; SetOut(it->second); std::cout << std::endl;
        it++;
    }
}

int main () {
    std::cout << "Unesite tekst: ";
    std::string text;
    std::getline(std::cin, text);
    auto index = KreirajIndeksPojmova(text);
    IspisiIndeksPojmova(index);
    while(1) {
        std::cout << "Unesite rijec: ";
        std::string word, dot = ".";
        std::getline(std::cin, word);
        if (word == dot) return 0;
        try {
            auto skup = PretraziIndeksPojmova(word, index);
            for (auto x : skup) std::cout << x << " ";
            std::cout << std::endl;
        } catch(...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
}