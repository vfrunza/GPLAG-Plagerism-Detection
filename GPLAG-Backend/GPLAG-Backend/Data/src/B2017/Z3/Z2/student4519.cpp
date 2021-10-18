#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <vector>
#include <utility>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::tuple<std::string, int, int>> IndeksPojmova;

bool LegalanZnak(char c)
{
    if(!((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')))
        return false;
    return true;

}

std::string MalaSlova(std::string s)
{
    std::string novi;
    for(int i=0; i<s.length(); i++)
        if(s.at(i)>='A' && s.at(i)<='Z')
            novi += 'A' - 'a';
        else novi+= s.at(i);
    return novi;
}

bool PorediRijeci(std::string s1,  std::string s2){
    if(MalaSlova(s1)==MalaSlova(s2))
        return true;
    return false;    
}

void /*std::vector<std::pair<std::string, std::vector>> */ RijeciIPozicije(std::string s)
{
    std::string kopija(s.length(), '0');

    for(int i=0; i<kopija.length(); i++)
        if(!LegalanZnak(s.at(i))) kopija.at(i) = '_';

    std::cout << std::endl << s << std::endl << kopija << std::endl;
//    std::vector<std::pair<std::string, std::vector>> vektor;
    
    int p=0;
    while(p<s.length()) {
        
        //preskace sve prije prve rijeci
        while(p<s.length() && kopija.at(p)=='_') {
            p++;
        }
        
        if(p==s.length()) break;
        
        std::string rijec;
        std::vector<int>v;
        
        while (p<kopija.length() && kopija.at(p)=='0') {
            rijec += s.at(p);
            kopija.at(p) = '_';
            p++;
        }
        
        v.push_back(p-rijec.length());
        
        for(int j=p; j<s.length()-rijec.length();j++) {
            if(PorediRijeci(rijec, s.substr(j,rijec.length())) && (j-1==0 || kopija.at(j-1)=='_') 
                    && (j+rijec.length()==s.length() || kopija.at(j+rijec.length())=='_')) {
                v.push_back(j);
                for(int z=j; z<j+rijec.length(); z++)
                    kopija.at(z) = '_';
            }
            
        }
        
        std::cout <<std::endl << rijec ;
        for(int br:v) std::cout <<  " " << br;
    
 //   vektor.push_back(std::make_pair(rijec, v));
    p++;
    }
        std::cout << std::endl << s << std::endl << kopija << std::endl;
    return;
}




int main()
{

    for(;;) {
        std::string naziv_poglavlja;
        std::cout << "Unesite naziv poglavlja: ";
        std::cin >> naziv_poglavlja;
        std::cin.get();
        if(naziv_poglavlja==".") break;
        std::vector<std::string> v;

        for(int i=0; ; i++) {
            std::string sadrzaj_stranice;
            std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            std::getline(std::cin, sadrzaj_stranice);
            if(sadrzaj_stranice==".") break;

            v.push_back(sadrzaj_stranice);
            RijeciIPozicije(sadrzaj_stranice);
        }
    }

}