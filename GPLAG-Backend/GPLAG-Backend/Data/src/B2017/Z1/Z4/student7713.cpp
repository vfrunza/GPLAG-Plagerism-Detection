/*B 2017/2018, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> v)
{
    int l(0);
    if(recenica.size()==0 || v.size()==0) return recenica;
    std::string palindrom(recenica);
    int j(0);
    for(int i=0; i<v.size(); i++) {
        l=palindrom.size()-v.at(i).size()+1;
        if(j>=l) continue;
        for(j=0; j<l; j++) {
            if(palindrom.substr(j,v.at(i).size())==v.at(i) && (j+v.at(i).size()==palindrom.size() || palindrom.at(j+v.at(i).size())<'A' || (palindrom.at(j+v.at(i).size())>'Z' && palindrom.at(j+v.at(i).size())<'a') || palindrom.at(j+v.at(i).size())>'z') && (j==0 || palindrom.at(j-1)<'A' || (palindrom.at(j-1)>'Z' && palindrom.at(j-1)<'a') || palindrom.at(j-1)>'z')) {
                for(int k=0; k<v.at(i).size(); k++)
                    palindrom.insert(palindrom.begin() + (j+v.at(i).size()), v.at(i).at(k));
                j+=2*v.at(i).size()-1;
                if(j>=palindrom.size()-v.at(i).size()) break;
            }
            l=palindrom.size()-v.at(i).size()+1;
        }
        j=0;
    }
    return palindrom;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> v)
{
    int l(0);
    if(recenica.size()==0 || v.size()==0) return recenica;
    std::string palindrom(recenica);
    int j(0);
    for(int i=0; i<v.size(); i++) {
        l=palindrom.size()-v.at(i).size()+1;
        if(j>=l) continue;
        for(j=0; j<l; j++) {
            if(palindrom.substr(j,v.at(i).size())==v.at(i) && (j+v.at(i).size()==palindrom.size() || palindrom.at(j+v.at(i).size())<'A' || (palindrom.at(j+v.at(i).size())>'Z' && palindrom.at(j+v.at(i).size())<'a') || palindrom.at(j+v.at(i).size())>'z') && (j==0 || palindrom.at(j-1)<'A' || (palindrom.at(j-1)>'Z' && palindrom.at(j-1)<'a') || palindrom.at(j-1)>'z')) {
                if(v.at(i).size()%2==0) {
                    for(int k=0; k<v.at(i).size()/2; k++)
                        palindrom.erase(palindrom.begin() + (j+v.at(i).size()/2));
                    for(int k=0; k<v.at(i).size()/2; k++)
                        palindrom.insert(palindrom.begin() + (j+v.at(i).size()/2), v.at(i).at(k));
                    j+=v.at(i).size()-1;
                    if(j>=palindrom.size()-v.at(i).size()) break;
                } else {
                    for(int k=0; k<(v.at(i).size()-1)/2; k++)
                        palindrom.erase(palindrom.begin() + (j+(v.at(i).size()+1)/2));
                    for(int k=0; k<(v.at(i).size()-1)/2; k++)
                        palindrom.insert(palindrom.begin() + (j+(v.at(i).size()+1)/2), v.at(i).at(k));
                    j+=v.at(i).size()-1;
                    if(j>=palindrom.size()-v.at(i).size()) break;
                }
            }
            l=palindrom.size()-v.at(i).size()+1;
        }
        j=0;
    }
    return palindrom;
}
int main ()
{
    std::string recenica;
    std::vector<std::string> fraze;
    int i(-1);
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::cout<<"Unesite fraze: ";
    do {
        i++;
        fraze.resize(fraze.size()+1);
        std::getline(std::cin, fraze.at(i));
    } while(fraze.at(i).size()!=0);
    fraze.erase(fraze.begin()+fraze.size()-1);
    std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze);
    return 0;
}