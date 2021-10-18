/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <string>
#include <stdexcept>

typedef std::string string;

string IzdvojiRijecPoRedu(string s, int n) {
    if(n<1) throw std::range_error("Pogresan redni broj rijeci!");
    
    int br_rijeci(0);
    bool rijec(false);
    
     for(int i{}; i<s.length(); i++){
        if(s[i] != ' ' && rijec == false){
            rijec = true;
            br_rijeci++;
            if(br_rijeci == n){
                string rezultat;
                for(int j{i}; j<s.length(); j++){
                    if(s[j] == ' ') break;
                    else rezultat.push_back(s[j]);
                }
                return rezultat;
            }
        }
        if(s[i] == ' ' && rijec == true) rijec = false;
    }
    if (n>br_rijeci || br_rijeci<0) throw std::range_error("IZUZETAK: pogresan broj rijeci!");
}

int main ()
{
    try{
        int n;
        std::cout<<"Unesite redni broj rijeci koju izbacujete: ";
        std::cin>>n;
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite recenicu: ";
        string s;
        std::getline(std::cin,s);
        string rijec=IzdvojiRijecPoRedu(s,n);
        std::cout<<"Rijec na poziciji "<<n<<" je: "<<rijec;
    }catch(std::range_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    
    
	return 0;
}
