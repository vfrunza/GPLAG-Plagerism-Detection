#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

typedef std::vector<std::string> Vecstr;

bool JeLiSlovo (char slovo) {

    if(slovo>'z' || slovo<'A' || (slovo>'Z' && slovo<'a'))
        return false;

    return true;
}

void EngAlfabet(Vecstr vs) {

    for (int i = 0; i < vs.size(); i++) {
        for(int j=0; j < vs[i].size(); j++ ) {
            if(!JeLiSlovo(vs[i][j])){
                throw std::domain_error("Nekorektan izbor rijeci");
            }
        }
    }
}

string DajRijecPigLatin(string recenica, int odakle, int koliko) {

    string rijec{recenica.substr(odakle,koliko)};

    char prvo_slovo(rijec[0]);

    for(int i = 0; i<rijec.length()-1; i++) {
        rijec[i]=rijec[i+1];
    }
    rijec[rijec.length()-1]=prvo_slovo;

    rijec.push_back('a');
    rijec.push_back('y');

return  rijec;
}

void PrebaciUPigLatin(string &recenica, int odakle, int koliko) {

    recenica.resize(recenica.size()+2);
    string rijec{DajRijecPigLatin(recenica,odakle,koliko)};

    for(int i = recenica.length()-1; i>=odakle+2; i--) {
        recenica[i]= recenica[i-2];
    }

    for(int i = 0; i<koliko+2; i++) {
        recenica[odakle+i]=rijec[i];
    }
}

void PremjestiSlova(string &recenica, int odakle, int koliko) {

    char tmp;

    for (int i = 0; i <koliko/2; i++) {
        tmp=recenica[odakle+i];
        recenica[odakle+i]=recenica[odakle+koliko-1-i];
        recenica[odakle+koliko-1-i]=tmp;
    }
}

string ObrniFraze(string recenica, Vecstr vs) {             // GLAVNA 1.

    for (int i = 0; i < vs.size() ; i++) {
        for (int j = 0; j < recenica.size(); j++) {
            if(vs[i]==recenica.substr(j,vs[i].length())) {
                PremjestiSlova(recenica,j,vs[i].length());
            }
        }
    }
    return recenica;
}

string IzmijeniUPigLatin (string recenica, Vecstr vs) {     //GLAVNA 2.

    EngAlfabet(vs);
    int duz,poc;

    if(!vs.size()){
        for (int j = 0; j < recenica.size(); j++) {
            duz=0;
            if((j==0 && JeLiSlovo(recenica[j])) || !JeLiSlovo(recenica[j-1])) {
                poc=j;
                while(JeLiSlovo(recenica[j]) && j<recenica.size()) {
                    duz++;
                    j++;
                }
                PrebaciUPigLatin(recenica,poc,duz);
            }
        }
    }
    else{

        for (int i = 0; i < vs.size(); i++) {
            for (int j = 0; j < recenica.size(); j++) {
        
                if(vs[i]==recenica.substr(j,vs[i].length()) && (j==0 || !JeLiSlovo(recenica[j-1]))){
                    if(j + vs[i].length() == recenica.size() ||  !JeLiSlovo(recenica[j + vs[i].length()])) {
                    
                        PrebaciUPigLatin(recenica,j,vs[i].length());
                        j += vs[i].length()+2; // ovdje je greska ja mislim
                        //cout << j << endl; ///o
                    }
                }
            }
        }
    }
    return recenica;
}

int main ()
{
    std::cout << "Unesite recenicu: ";

    string recenica;
    std::getline(std::cin, recenica);

    std::cout << "Unesite fraze: ";
    string fraza;

    Vecstr vs;

    while(true) {
        std::getline(std::cin, fraza);
            if(fraza.length()>0)
                vs.push_back(fraza);
            else
                break;
    }
 
    try {
        std::string piglatin = IzmijeniUPigLatin(recenica,vs);
        std::cout << "Recenica nakon PigLatin transformacije: " << piglatin
            << std::endl;
    } catch (std::domain_error err) {
        std::cout << "Izuzetak: " << err.what() << std::endl;
    }

    std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,vs);

    return 0;
}
