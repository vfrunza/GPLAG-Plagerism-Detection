#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


std::string ObrniRijec(std::string s) {
std::string g;
for (int i=s.size()-1;i>=0;i--) {
    g.push_back(s[i]);
}
return g;
}

std::string Transformisi (std::string s) {
    if(s.size() !=0 ) {
        std::string g;
        for(int j=1;j<s.size();j++)
            {
                g.push_back(s[j]);
            }
        g.push_back(s[0]);
        g = g + "ay";
        return g;
    }

}

std::string prosiri_i_pomakni_do(std::string s, int j) {
    s.push_back('*');
    s.push_back('*');
    for(int i=s.size() - 1;i>j;i--) {
        s[i] = s[i-2];
    }
    return s;
}

std::string pigLatin(std::string recenica, std::string rijec) {
    int j(0), i(0);
    while (j!= recenica.size()) {
        if (rijec[i]!=recenica[j]) {
            j++; i=0;
        }
        if (rijec[i]==recenica[j]) { j++; i++; }
        if (i==rijec.size()-1) {
            std::string novi=Transformisi(rijec);
            recenica = prosiri_i_pomakni_do(recenica,j);
            j = j - i;
            for (int k=0;k<novi.size();k++) {
                recenica[j]=novi[k];
                j++;
            }
            i=0;
        }
    }
    return recenica;
}


std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> v) {
    for(int i=0;i<v.size();i++) {
        recenica = pigLatin(recenica,v[i]);
    }
    return recenica;
}



std::string obrnifraze(std::string recenica,std::string rijec) {
int i(0),j(0),k(0);
std::string novi;
while (j!= recenica.size()) {
    if (rijec[i]!=recenica[j]) {
        j++; i=0;
    }
    if (rijec[i]==recenica[j]) { j++; i++; }
    if (i==rijec.size()-1) {
        novi=ObrniRijec(rijec);
        j=j-i;
        for (int k=0;k<rijec.size();k++) {
            recenica[j]=novi[k];
            j++;
        }
        i=0;
    }

}
return recenica;
}


std::string ObrniFraze(std::string recenica, std::vector<std::string> v) {
    for(int i=0;i<v.size();i++) {
        recenica = obrnifraze(recenica,v[i]);
    }
    return recenica;
}



int main () {
std::string s,rijec;
std::cout<<"Unesi neku recenicu: ";
std::getline(std::cin,s);
std::vector<std::string>v;
std::cout<<"Unesi vektor rijeci: ";
while(true){
std::getline(std::cin,rijec);
if(std::cin.peek()=='\n')break;
v.push_back(rijec);
}
std::string stara=IzmijeniUPigLatin(s,v);
std::cout<<stara;
std::string nova=ObrniFraze(s,v);
return 0;
}






