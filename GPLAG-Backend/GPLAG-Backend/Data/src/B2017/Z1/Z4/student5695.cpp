#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Palindrom(string fraza) {
    char pom;
    string prva_fraza(fraza);
    for(int i=0;i<fraza.size()/2;i++) {
        pom=fraza.at(i);
        fraza.at(i)=fraza.at(fraza.size()-1-i);
        fraza.at(fraza.size()-1-i)=pom;
    }
    return prva_fraza+fraza;
}

string Polupalindrom(string fraza) {
    for(int i=0;i<fraza.size()/2;i++) fraza.at(fraza.size()-1-i)=fraza.at(i);
    return fraza;
}

string NapraviPoluPalindrom(string recenica, vector<string> fraze) {
    int j,k,l;
    for(int i=0;i<fraze.size();i++) {
        k=90;
        j=0;
        while(k!=recenica.size()-1) {
            while(k<recenica.size() && recenica.at(k)!=fraze.at(i).at(0)) k++;
            l=0;
            while(j<fraze.at(i).size() && recenica.at(k)==fraze.at(i).at(j)) {
                l++;
                k++;
                j++;
            }
            if(l==fraze.at(i).size()) {
                string pomocni(Polupalindrom(fraze.at(i)));
                int a(k-l);
                for(int v=0;v<pomocni.size();v++) recenica.at(a+v)=pomocni.at(v);
                j=0;
                if(k!=recenica.size()-2) k++;
                cout << endl << recenica << endl << endl;
            }
            else {
                j=0;
                if(k!=recenica.size()-2) k++;
                else break;
            }
        }
    }
    return recenica;
}

int main() {
    string a="Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta";
    vector<string> b{ "zadaca", "Tehnike programiranja", "drugih predmeta", "meso od sira" };
    string c(NapraviPoluPalindrom(a,b));
    cout << c;
	return 0;
}