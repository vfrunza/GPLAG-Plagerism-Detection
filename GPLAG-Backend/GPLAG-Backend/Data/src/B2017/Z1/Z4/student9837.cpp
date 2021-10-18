#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> stringvektor;
typedef std::string string;

string PalindromStringa (string s)
{
    string st="";
    for(int i=s.length(); i--; i>=0) {
        st=st+s.at(i);
    }
    return st;
}

string NapraviPalindrom (string s, stringvektor v)
{
    bool a=true;

    for(int i=0; i<v.size(); i++) {
        string rijec=v.at(i);
        for(int j=0; j<s.length(); j++) {
            if(rijec.at(0)==s.at(j)) {
                if(j+rijec.length()<=s.length()) {
                    for(int k=1; k<rijec.length(); k++) {
                        if(rijec.at(k)!=s.at(j+k))
                            a=false;
                    }
                    if(j+rijec.length()!=s.length()) {
                        if(s.at(j+rijec.length())!=' ' && s.at(j+rijec.length())!=',' &&
                                s.at(j+rijec.length())!='.' && s.at(j+rijec.length())!='!' && s.at(j+rijec.length())!='?') {
                            a=false;
                        }
                    }
                    if(a==true) {
                        s.insert(j+rijec.length(), PalindromStringa(rijec));
                        j=j+(rijec.length()*2);
                    }
                }
                a=true;
            }
        }
    }

    return s;
}


string NapraviPoluPalindrom(string s, stringvektor v)
{
    bool a=true;

    for(int i=0; i<v.size(); i++) {
        string rijec=v.at(i);
        for(int j=0; j<s.length(); j++) {
            if(rijec.at(0)==s.at(j)) {
                if(j+rijec.length()<=s.length()) {
                    for(int k=1; k<rijec.length(); k++) {
                        if(rijec.at(k)!=s.at(j+k))
                            a=false;
                    }
                    if(j+rijec.length()!=s.length()) {
                        if(s.at(j+rijec.length())!=' ' && s.at(j+rijec.length())!=',' &&
                                s.at(j+rijec.length())!='.' && s.at(j+rijec.length())!='!' && s.at(j+rijec.length())!='?') {
                            a=false;
                        }
                    }
                    if(a==true) {
                        string privrijec=rijec;
                        if(privrijec.length()%2==0) {
                            s.erase(j+(rijec.length()/2), rijec.length()/2);
                            privrijec=PalindromStringa(rijec);
                            privrijec.erase(0, rijec.length()/2);
                            s.insert(j+rijec.length()/2, privrijec);
                        } else {
                            s.erase(j+(rijec.length()/2+1), privrijec.length()/2);
                            privrijec=PalindromStringa(rijec);
                            privrijec.erase(0, rijec.length()/2+1);
                            s.insert(j+rijec.length()/2+1, privrijec);
                        }
                    }
                }
                a=true;
            }
        }
    }

    return s;
}

int main()
{
    string unos;
    stringvektor unosvekstring;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin, unos);

    std::cout<<"Unesite fraze: ";
    string priv;
    std::getline(std::cin, priv);

    while(priv.length()>0) {
        unosvekstring.push_back(priv);
        std::getline(std::cin, priv);
    }

    std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(unos,unosvekstring)<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(unos, unosvekstring)<<std::endl;

    return 0;
}