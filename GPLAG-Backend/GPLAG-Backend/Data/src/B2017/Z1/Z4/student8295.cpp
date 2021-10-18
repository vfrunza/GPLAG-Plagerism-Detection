#include <iostream>
#include <string>
#include <vector>
#include <utility>


using std::cin;
using std::cout;
using std::endl;

void Okreni (std::string& str)
{
    int n=str.length()-1;
    for(int i=0; i<str.length()/2; i++) {
        std::swap(str[i],str[n]);
        n--;
    }
}

std::string NapraviPalindrom ( std::string recenica,  std::vector<std::string> fraze)
{
    for(int j=0; j<fraze.size(); j++) {
        for(int i=0; i<recenica.length()-1; i++) {

            if(recenica.substr(i,fraze.at(j).length())==fraze.at(j)) {
                Okreni(fraze.at(j));
                recenica.insert(i+fraze.at(j).length(), fraze.at(j));
                Okreni(fraze.at(j));
            }
        }
    }
    return recenica;
}

std::string NapraviPoluPalindrom ( std::string recenica,  std::vector<std::string> fraze)
{
    for(int j=0; j<fraze.size(); j++) {
        for(int i=0; i<recenica.length()-1; i++) {

            if(recenica.substr(i,fraze.at(j).length())==fraze.at(j)) {
                std::string fr(fraze.at(j));
                fr = fr.substr(0,((fraze.at(j).length())/2));
                Okreni(fr);

                for(int k=0; k<fr.length(); k++) {
                    if(fr.length()%2==0)
                        recenica.at(i+k+(fraze.at(j).length())/2+1)=fr.at(k);
                    else
                        recenica.at(i+k+(fraze.at(j).length()+1)/2)=fr.at(k);


                }
            }
        }
    }
    return recenica;
}



int main ()
{
    std::string s;
    cout<<"Unesite recenicu: ";
    std::getline(std::cin, s);
    std::vector<std::string> v;
    std::string s1;
    cout<<"Unesite fraze: ";

    do {
        std::getline(std::cin,s1);
        if(s1.size()<2) break;
        v.push_back(s1);
    } while (s1.size()!=0);


    std::string rec;
    cout<<"Recenica nakon Palindrom transformacije: ";
    rec=NapraviPalindrom(s,v);
    cout<<rec;
    cout<<endl;

    std::string rec1;
    cout<<"Recenica nakon PoluPalindrom transformacije: ";
    rec1=NapraviPoluPalindrom(s,v);
    cout<<rec1;


    return 0;
}
