#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::string> Fraze;

std::string ObrniRijec(std::string rijec) {
    std::string obrnuta;
    for (int i = rijec.size(); i > 0; i--) 
        obrnuta.push_back(rijec.at(i-1));
    return obrnuta;
}

std::string PolaRijeci(std::string rijec) {
    for (int i = 0; i < rijec.size()/2; i++)
        rijec.at(rijec.size()-1-i) = rijec.at(i);
    return rijec;
}

bool Slovo(char s) {
    return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z');
}

std::string NapraviPalindrom(std::string recenica, Fraze fraze) {
    for (int i = 0; i < fraze.size(); i++) {
        int d1(fraze.at(i).size());
        for (int j = 0; j < recenica.size(); j++) {
            if (j + d1 <= recenica.size()) {
                std::string rijec(recenica.substr(j, d1));
                if (rijec == fraze.at(i) && (j == 0 || (j > 0 && !Slovo(recenica.at(j-1))) 
                || !Slovo(rijec.at(0))) && (j + d1 == recenica.size() || (j + d1 < recenica.size() && !Slovo(recenica.at(j + d1))) 
                || !Slovo(rijec.at(d1-1)))) {
                    rijec = ObrniRijec(rijec);
                    recenica.insert(j + d1, rijec);
                    if (Slovo(rijec.at(0)) && j+ 2*d1 < recenica.size() && Slovo(recenica.at(j + 2*d1))) 
                            recenica.insert(recenica.begin() + j + 2*d1, ' ');
                }
            }
        }
    }
    return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, Fraze fraze) {
    for (int i = 0; i < fraze.size(); i++) {
        int d1(fraze.at(i).size());
        for (int j = 0; j < recenica.size(); j++) {
            if (j + d1 <= recenica.size()) {
                std::string rijec(recenica.substr(j, d1));
                if (rijec == fraze.at(i) && (j == 0 || (j > 0 && !Slovo(recenica.at(j-1))) 
                || !Slovo(rijec.at(0))) && (j + d1 == recenica.size() || (j + d1 < recenica.size() && !Slovo(recenica.at(j + d1))) 
                || !Slovo(rijec.at(d1-1)))) {
                    rijec = PolaRijeci(rijec);
                    for (int k = 0; k < d1; k++) recenica.at(j + k) = rijec.at(k);
                    if (Slovo(recenica.at(j+d1-1)) && j+d1 < recenica.size() && Slovo(recenica.at(j+d1))) 
                        recenica.insert(recenica.begin() + j + d1,' ');
                }
            }
        }
    }
    return recenica;
}

int main()
{
    std::string recenica, fraza;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin,recenica);
    std::vector<std::string> fraze;
    std::cout << "Unesite fraze: ";
    while (std::getline(std::cin, fraza), fraza != "") fraze.push_back(fraza);
    std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica,fraze) << std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica,fraze);
	return 0;
}