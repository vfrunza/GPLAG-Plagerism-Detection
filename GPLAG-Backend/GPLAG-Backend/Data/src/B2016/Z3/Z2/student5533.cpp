/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>

using std::logic_error;

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m) {
    if (!m.count(s)) throw logic_error("Pojam nije nadjen");
    return m[s];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m) {
    for (auto i = m.begin(); i != m.end(); i++) {
        std::cout << i -> first << ": ";
        auto it ((i -> second).begin());
        if (it != (i -> second).end()) it++;
        for (auto j = (i -> second).begin(); j != (i -> second).end(); j++) {
            std::cout << *j;
            if (it != (i -> second).end()) {
                std::cout << ",";
                it++;
            }
        }
        std::cout << std::endl;
    }
}

bool slovo(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> m;
    int pozicija(0);
    std::string temp;
    for (int i = 0; i != s.size();) {
        while (!slovo(s[i])) {
            i++;
            if (i == s.size()) break;
        }
        if (i == s.size()) break;
        temp = "";
        pozicija = i;
        while (slovo(s[i])) {
            temp = temp + s[i];
            i++;
            if (i == s.size()) break;
        }
        std::transform(temp.begin(), temp.end(), temp.begin(), [](char c) {if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a'; return c;});
        if (temp.size() != 0) m[temp].insert(pozicija);
    }
    return m;
}

int main () {
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s, '\n');
    std::map<std::string, std::set<int>> m;
    m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    for (;;) {
        std::cout<<"Unesite rijec: ";
        std::string a;
        std::cin >> a;
        if (a == ".") return 0;
        try {
            std::set<int> se;
            se = PretraziIndeksPojmova(a, m);
            std::for_each(se.begin(), se.end(), [](int a) {std::cout << a << " ";});
            std::cout << std::endl;
        }
        catch(logic_error e){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}