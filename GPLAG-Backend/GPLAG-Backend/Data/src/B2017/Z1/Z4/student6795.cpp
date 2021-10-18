#include <iostream>
#include <string>
#include <vector>

using std::cout;
typedef std::vector<std::string> StrVector;

//Funkcija koja od rijeci pravi palindrom
std::string Palindrom(std::string s)
{
    std::string nova;
    for(int i(s.length() - 1); i>=0; i--) nova.push_back(s.at(i));

    return nova;
}

//Funkcija koja od rijeci pravi polupalindrom
std::string PoluPalindrom(std::string s)
{

    std::string polu;

    if(s.length() % 2 == 0) {
        for(int i(0); i<(s.length()/2); i++) polu.push_back(s.at(i)); //Pola fraze uzima i upisuje u novi string
        for(int i(s.length()/2 - 1); i>=0; i--) polu.push_back(s.at(i));
    }
    if(s.length() % 2 != 0) {
        for(int i(0); i<(s.length()/2 + 1); i++) polu.push_back(s.at(i)); //Pola fraze uzima i upisuje u novi string
        for(int i(s.length()/2 - 1); i>=0; i--) polu.push_back(s.at(i));
    }

    return polu;
}

//Funkcija za izbacivanje pocetnog i krajnjeg razmaka
std::string IzbaciRazmake(std::string s1){
   std::string s2;
    s2 = "";
    
    for(int s(0); s<s1.length() - 1; s++){
        if(s == 0 && s1.at(s) == ' ') continue;
        s2.push_back(s1.at(s));
    }
    
    return s2;
}

//Funkcija iz zadatka
std::string NapraviPalindrom(std::string s1, StrVector v)
{
    if(v.size() == 0) return s1;
    std::string s2;
    std::string temp;
    s1+=" ";
    s1=" " + s1;
    //IDI OD PRVE FRAZE PA DO ZADNJE
    for(int i(0); i<v.size(); i++) {
        int fraze_size(v.at(i).size()); //Velicina i-te fraze

        //OVOM PETLJOM "HODAMO" PO RECENICI
        for(int s(0); s<s1.length(); s++) {
            temp = s1.substr(s, fraze_size);

            if(s > 0) {
                if(temp == v.at(i) && (((s1.at(s - 1) != ' ') || (s1.at(s + fraze_size) != ' ')) && ((s1.at(s - 1) != ',') && (s1.at(s + fraze_size) != '.') && (s1.at(s + fraze_size) != ',')&& (s1.at(s + fraze_size) != '!') && (s1.at(s + fraze_size) != '?'))) ) {
                    continue;
                }
            }

            if(temp == v.at(i)) {
                s2 = s1.substr(0, s + fraze_size);
                s2 += Palindrom(temp);
                s2 += s1.substr(s + fraze_size, s1.length());
                s = fraze_size * 2;
            } else continue;
            s1 = s2;
        }
    }
    s1 = IzbaciRazmake(s1);
    return s1;
}

//Funkcija iz zadatka
std::string NapraviPoluPalindrom(std::string s1, StrVector v)
{
    if(v.size() == 0) return s1;
    std::string s2;
    std::string temp;
    s1+=" ";
    s1=" " + s1;
    //IDI OD PRVE FRAZE PA DO ZADNJE
    for(int i(0); i<v.size(); i++) {
        int fraze_size(v.at(i).size()); //Velicina i-te fraze

        //OVOM PETLJOM "HODAMO" PO RECENICI
        for(int s(0); s<s1.length(); s++) {
            temp = s1.substr(s, fraze_size);

            if(s != 0) {
                if(temp == v.at(i) && (((s1.at(s - 1) != ' ') || (s1.at(s + fraze_size) != ' ')) && ((s1.at(s - 1) != ',') && (s1.at(s + fraze_size) != '.') && (s1.at(s + fraze_size) != ',')&& (s1.at(s + fraze_size) != '?') && (s1.at(s + fraze_size) != '!'))) ) {
                    continue;
                }
            }

            if(temp == v.at(i)) {
                s2 = s1.substr(0, s);
                s2 += PoluPalindrom(temp);
                s2 += s1.substr(s + fraze_size, s1.length());
                //s++;
            } else continue;

            s1 = s2;
        }
    }
    
    s1 = IzbaciRazmake(s1);
    return s1;
}

int main ()
{
    StrVector fraze;
    std::string temp;
    std::string recenica;

    cout<<"Unesite recenicu: ";
    std::getline(std::cin, recenica);

    cout<<"Unesite fraze: ";
    while(1) {
        std::getline(std::cin, temp);
        if(temp != "")
            fraze.push_back(temp);
        if(temp == "") break;
    }
    cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, fraze);
    cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, fraze);

    return 0;
}