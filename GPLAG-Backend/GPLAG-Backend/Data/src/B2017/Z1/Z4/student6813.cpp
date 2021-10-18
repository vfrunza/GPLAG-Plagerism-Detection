#include <iostream>
#include<vector>
#include<string>

std::string IzvrniString(std::string s)
{

    for(int i=0; i<((int)s.size()/2); i++) {
        char pomocna(std::move(s[0+i]));
        s[i]=std::move(s[s.size()-1-i]);
        s[s.size()-1-i]=std::move(pomocna);
    }
    return s;
}


bool DaLiJeSlovo(char c)
{
    if(c>='a' && c<='z' || c>='A' && c<='Z') return true;
    return false;
}
std::string NapraviPalindrom(std::string recenica,std::vector<std::string>rijeci)
{


    for(int i=0; i<rijeci.size(); i++) {

        for(int j=0; j<recenica.length(); j++) {
            if(((j+rijeci.at(i).length())<=recenica.length()) && (rijeci.at(i)==recenica.substr(j,rijeci.at(i).length()))) {

                if(j==0 && j+rijeci.at(i).size()!=recenica.size() && DaLiJeSlovo(recenica.at(j+rijeci.at(i).size()))) continue;
                if(j!=0 && j+rijeci.at(i).size()!=recenica.size() && (DaLiJeSlovo(recenica.at(j-1)) ||  DaLiJeSlovo(recenica.at(j+rijeci.at(i).size())))) continue;

                if(j!=0 && j+rijeci.at(i).size()==recenica.size() && DaLiJeSlovo(recenica.at(j-1))) continue;
                std::string s=(IzvrniString(rijeci.at(i)));

                // recenica=recenica.substr(0,j) + s + recenica.substr(j,recenica.length());
                recenica.insert(j+rijeci.at(i).size(),s);
                j=j+rijeci.at(i).size()*2;
                
            }
        }

    }
    return recenica;
}


std::string NapraviPoluPalindrom(std::string recenica,std::vector<std::string>rijeci)
{

    for(int i=0; i<rijeci.size(); i++) {
        for(int j=0; j<recenica.length(); j++) {
            if(((j+rijeci.at(i).length())<=recenica.length()) && (rijeci.at(i)==recenica.substr(j,rijeci.at(i).length()))) {
                if(j==0 && j+rijeci.at(i).size()!=recenica.size() && DaLiJeSlovo(recenica.at(j+rijeci.at(i).size()))) continue;
                if(j!=0 && j+rijeci.at(i).size()!=recenica.size() && (DaLiJeSlovo(recenica.at(j-1)) ||  DaLiJeSlovo(recenica.at(j+rijeci.at(i).size())))) continue;
                if(j!=0 && j+rijeci.at(i).size()==recenica.size() && DaLiJeSlovo(recenica.at(j-1))) continue;

                if(rijeci.at(i).size()%2==0) {
                                        int kraj=j+rijeci.at(i).size();

                    j=j+rijeci.at(i).size()/2;
                    int k=j-1;
                    while(j<kraj) {
                        
                        recenica.at(j)=recenica.at(k);
                        j++;
                        k--;
                        if(j==recenica.size() || k<0) break;
                    }
                    j--;
                } else {
                                        int kraj=j+rijeci.at(i).size();

                    j=j+rijeci.at(i).size()/2;
                    int k=j;
                    while(j<kraj){
                        recenica.at(j)=recenica.at(k);
                        j++;
                        k--;
                        if(k<0 || j==recenica.size()) break;
                    }
                    j--;
                }



            }
        }

    }
    return recenica;
}


int main ()
{
    std::cout<<"Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin,recenica);

    std::cout<<"Unesite fraze: ";
    std::vector<std::string>rijeci;
    std::string unos;
    do {
        std::getline(std::cin,unos);
        if(unos.length()==0) break;
        rijeci.push_back(unos);
    } while(unos.length()!=0);
    std::string s1(NapraviPalindrom(recenica,rijeci));
   std::cout<<"Recenica nakon Palindrom transformacije: "<<s1<<std::endl;


    std::string s2(NapraviPoluPalindrom(recenica,rijeci));
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<s2;

    return 0;
}