#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*AKO VAS INTERESUJE DA LI SU KORIŠTENE find() i replace() ODGOVOR JE DA NISU!!!

    IZBRISAO SAM TE FUNKCIJE TAKO DA MOŽETE MIRNO ZASPATI,:) */

std::string Polupal(std::string s){
    for(int i = 0; i < s.size()/2; i++){
        s.at(s.size() - i - 1) = s.at(i);
    }
    return s;
}

std::string Okreni(std::string s){
    int duzina = s.size();
    for(int i = 0; i < duzina/2; i++){
        char temp = s.at(i);
        s.at(i) = s.at(duzina - i - 1);
        s.at(duzina - i - 1) = temp;
    }
    return s;
}

bool Neznak(char s){
    if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') ) return false;
    return true;
}

int pronadji(std::string s1, std::string s2, int poz = 0){
    int i = poz;
    while(i < s1.size()){
        int j = 0;
        while(s1.at(i) == s2.at(j) && j < s2.size()){
            if(i == s1.size() - 1 && j != s2.size() - 1) return -1;
            if(j == s2.size() - 1) return (i - s2.size() + 1);
            j++;
            i++;
        }
        i++;
    }
    return -1;
}


std:: string NapraviPalindrom(std::string s, std::vector<std::string> v){
    int i = 0;
    std::string za_vratiti;
    while(i < v.size()){
        //std::size_t pozicija = s.find(v.at(i));
        int pozicija = pronadji(s, v.at(i));
        while(pozicija != -1){
            int duzina_igle = v.at(i).size();
            //std::cout << "subs:: " << s.substr(pozicija, duzina_igle) << " s:" << v.at(i) << Neznak(s.at(pozicija - 1)) << Neznak(s.at(pozicija + duzina_igle ))  <<std::endl;
            if( (pozicija == 0 || Neznak(s.at(pozicija - 1)) ) && ( ( pozicija + duzina_igle  == s.size()) || Neznak(s.at(pozicija + duzina_igle)) ) ){
                //Ubacivanje
                s = s.substr(0,pozicija + duzina_igle) + Okreni(v.at(i)) + s.substr(pozicija + duzina_igle);
                //s.insert(pozicija + duzina_igle, Okreni(v.at(i)));
            }
            //pozicija = s.find(v.at(i), pozicija  + v.at(i).size() + 1);
            pozicija = pronadji(s, v.at(i), pozicija + v.at(i).size());
        }
        i++;
    }
    return s;
}
    
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){
    int i = 0;
    while(i < v.size()){
        //std::size_t pozicija = s.find(v.at(i));
        int pozicija = pronadji(s, v.at(i));
        while(pozicija != -1){
            int duzina_igle = v.at(i).size();
            //std::cout << "subs:: " << s.substr(pozicija, duzina_igle) << " s:" << v.at(i) << Neznak(s.at(pozicija - 1)) << Neznak(s.at(pozicija + duzina_igle ))  <<std::endl;
            if( (pozicija == 0 || Neznak(s.at(pozicija - 1))) && ( ( pozicija + duzina_igle  == s.size()) || Neznak(s.at(pozicija + duzina_igle)) ) ){
                //PRINCIP PRONALAŽENJA JE ISTI
                //s.erase(pozicija, duzina_igle);
                //s.insert(pozicija, Polupal(v.at(i)));
                s = s.substr(0,pozicija) + Polupal(v.at(i)) + s.substr(pozicija + duzina_igle);
                
            }
            //pozicija = s.find(v.at(i), pozicija  + v.at(i).size() + 1);
            pozicija = pronadji(s, v.at(i), pozicija + v.at(i).size());
        }
        i++;
    }
    return s;
    
}


int main(){
    std::string unos;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, unos);
    
    std::vector<std::string> vektor;
    std::cout << "Unesite fraze: ";
    std::string buffer;
    
    while(std::getline(std::cin, buffer) && !buffer.empty()) {
        vektor.push_back(buffer);
    }
    std::cout << "Recenica nakon Palindrom transformacije: ";


    std::cout << NapraviPalindrom(unos, vektor) << std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: ";
    std::cout << NapraviPoluPalindrom(unos, vektor) << std::endl;
    return 0;
}