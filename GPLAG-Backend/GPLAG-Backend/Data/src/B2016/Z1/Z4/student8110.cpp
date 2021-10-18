#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

std::string ObrniFraze (std::string recenica, std::vector<std::string> rijeci) {
    for(auto x : rijeci) {
        for(int i=0; i<recenica.length(); i++) {
            for(int j=0; j<=recenica.length()-i; j++) {
                if(recenica.substr(i,j)==x) {
                    int pocetak = i;
                    int kraj = i+j-1;
                    while(pocetak<kraj) {
                        char znak = recenica[pocetak];
                        recenica[pocetak++] = recenica[kraj];
                        recenica[kraj--] = znak;
                    } 
                }
            }
        }
    }
    return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> rijeci) {
    if(rijeci.size()>0) {
        for(auto x : rijeci) {
            for(auto y : x) {
                if(!((y>='a' && y<='z') || (y>='A' && y<='Z'))) throw std::domain_error ("Nekorektan izbor rijeci");
            }
        }
    }
    
    if(rijeci.size()==0) {
        for(int i=0; i<recenica.length(); i++) {
            if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')) {
                char prvo_slovo = recenica[i];
                recenica.erase(recenica.begin()+i);
                while(((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')) && i<recenica.length()) i++;
                recenica.insert(recenica.begin()+i, prvo_slovo);
                recenica.insert(recenica.begin()+i+1, 'a');
                recenica.insert(recenica.begin()+i+2, 'y');
                while(((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')) && i<recenica.length()) i++;
                i--;
            }
        }
    }
    else {
        for(auto x : rijeci) {
            for(int i=0; i<recenica.length(); i++) {
                for(int j=0; j<=recenica.length()-i; j++) {
                    bool prva(false);
                    bool zadnja(false);
                    if(i==0) prva = true;
                    if(i+j == recenica.length()) zadnja = true;
                    if(recenica.substr(i,j)==x && (prva || !((recenica.at(i-1)>='a' && recenica.at(i-1)<='z') || 
                    (recenica.at(i-1)>='A' && recenica.at(i-1)<='Z'))) && (zadnja || !((recenica.at(i+j)>='a' && 
                    recenica.at(i+j)<='z') || (recenica.at(i+j)>='A' && recenica.at(i+j)<='Z')))) {
                        int pocetak = i;
                        int kraj = i+j-1;
                        char prvo_slovo = recenica[pocetak];
                        recenica.erase(recenica.begin()+pocetak);
                        recenica.insert(recenica.begin()+kraj, prvo_slovo);
                        recenica.insert(recenica.begin()+kraj+1, 'a');
                        recenica.insert(recenica.begin()+kraj+2, 'y');
                        i+=j;
                         
                    }
                }
            }
        }
    }
    return recenica;
}

int main () {
    std::cout << "Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin, recenica);
   

    std::cout << "Unesite fraze: ";
    std::vector<std::string> v;
   
    std::string rijec;
    for (; ;) {
        std::getline(std::cin, rijec);
        if(!(rijec.length()==0)) v.push_back(rijec);
        else break;
    }
    
    
    try {
    std::string s1 = IzmijeniUPigLatin(recenica, v);
    std::cout << "Recenica nakon PigLatin transformacije: ";
    std::cout << s1<< std::endl;
    }
    catch(std::domain_error e) {
        std::cout << "Izuzetak: " << e.what() <<std::endl;
    }
    std::cout << "Recenica nakon obrtanja fraza: ";
    std::cout << ObrniFraze(recenica, v) << std::endl;
	return 0;
}