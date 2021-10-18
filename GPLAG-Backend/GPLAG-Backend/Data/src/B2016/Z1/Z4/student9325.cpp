#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v) {
    std::string temp;
    
    int brojac ;
    int k;
    
    for(int i = 0; i < v.size(); i++) {
        temp = v[i];
        
        for(int j = 0; j < s.length(); j++) {
            brojac = 0;
            
            if(temp[brojac] == s[j]) {
                k = j;

                while(temp[brojac] == s[k] && brojac < temp.length()) {
                    brojac++;
                    k++;
                }
                if(temp.length()  == brojac) {
                    for(int p = temp.length() - 1; p >= 0; p--) {
                        s[j] = temp[p];
                        j++;
                    }
                }
            }
        }
    }
    return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {
    std::string temp;
    for(int i = 0; i < v.size(); i++) {
        temp = v[i];
        for(int j = 0; j < temp.length(); j++) {
            if((temp[j] < 'A' || temp[j] > 'Z') && (temp[j] < 'a' || temp[j] > 'z')) 
                throw std::domain_error("Nekorektan izbor rijeci");
        }
    }
    
    if(v.size() == 0) {
        int pocetak;
        int duzina;
        std::string novi;
        std::string pig;
        
        for(int i = 0; i < s.length(); i++) {
            //s[i] == ' '
            //poslije
            if(!((s[i]>='A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z'))) {
                novi.push_back(s[i]);
                continue;
            }
            
            pocetak = i;
            duzina = 0;
            //!((s[i]>='A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z'))
            //while(s[i] != ' ' && i < s.length()) {
            //s[i] != ' ' && s[i] != '.' && s[i] != ',' && s[i] != '?'
            while( ((s[i]>='A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z')) && i < s.length()) {
                duzina++;
                i++;
            }
            i--;
            temp = s.substr(pocetak, duzina);
            novi += temp.substr(1,temp.length()) + temp[0] + "ay";
            //novi += pig;
            
        }
        return novi;
    }
    
    std::string uPig;
    
    int brojac;
    int k;
    
    for(int i = 0; i < v.size(); i++) {
        
        temp = v[i];
        uPig = temp.substr(1, temp.length()) + temp[0] + "ay";
        
        for(int j = 0; j < s.length(); j++) {
            brojac = 0;
            
            //if(temp[brojac] == s[j] && (s[j-1] == ' ' || s[0] == temp[0]))
            // (s[j-1] < 'A' || s[j-1] > 'Z') && (s[j-1] < 'a' || s[j-1] > 'z')
            if(temp[brojac] == s[j] && ((s[j-1] < 'A' || s[j-1] > 'Z') && ((s[j-1] < 'a' || s[j-1] > 'z') || s[0] == temp[0]))) {
                k = j;

                while(temp[brojac] == s[k] && brojac < temp.length()) {
                    brojac++;
                    k++;
                }
                if(temp.length()  == brojac) {
                    s = s.substr(0, j) + uPig + s.substr(brojac + j, s.length());
                    j = k;
                }
            }
        }
    }
    return s;
}

int main() {
    std::cout << "Unesite recenicu: ";
    std::string s;
    std::getline(std::cin, s);
    
    std::vector<std::string> v;
    
    std::cout <<"Unesite fraze: ";
    std::string fraza;
    
    while(true) {
        std::getline(std::cin, fraza);
        if(fraza == "") {
            break;
        }
        else v.push_back(fraza);
    }

    try {
        std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s,v);
        std::cout << std::endl;
        std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s,v);
    }
    catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
        std::cout << std::endl;
        std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s,v);
    }
    
    return 0;
}
