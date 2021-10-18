#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;
using std::vector;

typedef unsigned long long int ullint;

string ReverseString(string s) {
    string toRet;

    for(int i = s.size()-1; i >= 0; i--) {
        toRet.push_back(s.at(i));
    }

    return toRet;
}

bool Slovo(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;
    return false;
}

//Fertsera
bool Find(string phrase, string s, ullint &idx){
    ullint pSize = phrase.size(), sSize = s.size();
    ullint i = idx, j = 0;
    
    if(sSize < pSize) return false;
    
    //i prolazi kroz string
    while(i <= sSize - pSize){
        //j se povecava dok je phrase substr s-a, ako se desi da je j == pSize
        //znaci da je phrase substr s-a
        if(j == pSize){
            //treba provjeriti da li je substr na pocetku s-a ili, ako nije, da li je ispred njega ' '
            //Ako ni jedan uslov nije zadovoljen, potrebno je nastaviti sa pretragom substr-a
            if(i > 0 && Slovo(s.at(i-1))){
                i += j;
                j = 0;
                continue;
            }
            
            //Kraj s stringa, substr nadjen
            if(i + j == sSize){
                idx = i;
                return true;
            }
            
            //Nije kraj stringa, pogledati da li je nakon substr-a ' '
            if(!Slovo(s.at(i+j))){
                idx = i;
                return true;
            }
            else{
                //Ako nije, ovaj substr koji smo nasli, nije zapravo fraza koju trazimo
                //te je potrebno nastaviti pretragu
                i += j;
                j = 0;
                continue;
            }
        }
        //Dok su phrase i s.substr jednaki, trazi phrase
        if(s.at(i+j) == phrase.at(j)){
            j++;
        }else{
            i += j + 1;
            j = 0;
        }
    }
    
    return false;
}

string NapraviPalindrom(string s, vector<string> v) {
    ullint idx = 0;
    
    for(string phrase : v){
        idx = 0;
        while(Find(phrase, s, idx)){
            s.insert(idx + phrase.size(), ReverseString(phrase));
            idx += phrase.size();
        }
    }
    
    return s;
}

string PoluString(string s){
    return s.substr(0, s.size()/2);
}

string NapraviPoluPalindrom(string s, vector<string> v) {
    ullint idx = 0;
    
    for(string phrase : v){
        idx = 0;
        while(Find(phrase, s, idx)){
            int shift = (phrase.size() % 2 != 0)? 1 : 0;
            s.erase(idx + phrase.size()/2 + shift, phrase.size()/2);
            s.insert(idx + phrase.size()/2 + shift, ReverseString(PoluString(phrase)));
            idx += phrase.size();
        }
    }
    
    return s;
}

int main () {
    
    string recenica, temp;
    vector<string> fraze;
    
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    
    
    std::cout << "Unesite fraze: ";
    while(true){
        std::getline(std::cin, temp);
        if(temp == "") break;
        fraze.push_back(temp);
    }
    
    std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze);
    std::cout << "\nRecenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
    
    return 0;
}