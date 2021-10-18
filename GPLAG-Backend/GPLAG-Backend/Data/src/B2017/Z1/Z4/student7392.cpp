#include <iostream>
#include <string>
#include <vector>
typedef std::vector<std::string> Vektor ;
int DaLiSePoklapa (std::string recenica, std::string rijec, int broj)   //Vraca broj ----> Mjesto poklapanja stringa i rijeci (Ako se ne poklapa vraca -1)
{  
     if (broj!=0) {
        if ((recenica.at(broj-1)>='a' && recenica.at(broj-1) <='z') || (recenica.at(broj-1)>='A' && recenica.at(broj-1) <='Z') ) return -1;
        }
    for (int i = broj ; i < recenica.length(); i++) {
        int j(0);
        while (recenica.at(i)==rijec.at(j) && j!=rijec.length()-1 && i!=recenica.length()-1) {
            i++;
            j++;
        }
        if(i!=recenica.length()-1){
        if ((recenica.at(i+1)>='a' && recenica.at(i+1) <='z') || (recenica.at(i+1)>='A' && recenica.at(i+1) <='Z')) return -1;
        }
       
        
        if (j==rijec.length()-1) return i;
    }
    return -1;
}
// MIJENJA FRAZE PALINDROMIMA
std::string UbaciPalindrom(std::string recenica, std::string palindrom_rijec, int n )  //BROJ ---> Mjesto poklapanja stringa i rijeci
{
    for (int i = 0; i < palindrom_rijec.size(); i++) {
       recenica.insert(recenica.begin() + n, palindrom_rijec.at(i));
    }
    return recenica;
}
std::string NapraviPalindrom(std::string recenica, Vektor neki_vektor)
{
    for (int i= 0; i < neki_vektor.size(); i++) {
        for (int j = 0; j < recenica.length(); j++) {
            if (DaLiSePoklapa(recenica, neki_vektor.at(i), j) != -1) {
                j=DaLiSePoklapa(recenica, neki_vektor.at(i), j)+1;
                recenica = UbaciPalindrom(recenica, neki_vektor.at(i), j);
            }
        }
    }
    return recenica;
}
std::string UbaciPoluPalindrom(std::string recenica, std::string rijec, int broj){
    int i(0);
    while (i != rijec.length()/2) {
        recenica.at(broj-1-i)=recenica.at(broj-rijec.length()+i);
        i++;
    }
    return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica, Vektor neki_vektor){
    for (int i= 0; i < neki_vektor.size(); i++) {
        for (int j = 0; j < recenica.length(); j++) {
            if (DaLiSePoklapa(recenica, neki_vektor.at(i), j) != -1) {
                j=DaLiSePoklapa(recenica, neki_vektor.at(i), j)+1;
                recenica = UbaciPoluPalindrom(recenica, neki_vektor.at(i), j);
            }

        }
    }
    return recenica;
}
int main ()
{
    std::string recenica, palindrom, polupalindrom;
    std::cout << "Unesite recenicu: " ;
    std::getline(std::cin, recenica);
    std::cout << "Unesite fraze: ";
    Vektor vektor_stringova;

    for (;;) {
        std::string fraza;
        std::getline(std::cin, fraza);
        if (fraza.length()==0) break;
        vektor_stringova.push_back(fraza);
        if (char(std::cin.peek() == '\n')) break;
    }
    palindrom=NapraviPalindrom(recenica, vektor_stringova);
    std::cout << "Recenica nakon Palindrom transformacije: "<< palindrom<< std::endl;
    polupalindrom=NapraviPoluPalindrom(recenica, vektor_stringova);
    std::cout << "Recenica nakon PoluPalindrom transformacije: "<< polupalindrom << std::endl;
    return 0;
}