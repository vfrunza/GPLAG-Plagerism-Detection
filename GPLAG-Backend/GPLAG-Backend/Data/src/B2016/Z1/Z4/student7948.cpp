#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

string ObrniFraze (string str, vector<string> vec) {
    string novi=str;
    for(int i=0; i<vec.size(); i++) {
        string obrnuti=vec[i];
        std::reverse(obrnuti.begin(), obrnuti.end());
        int vel=obrnuti.length();
        for(int j=0; j<str.length()-1; j++) {
            if(((str[i]<'A' && str[i]>'Z') || (str[i]<'a' && str[i]>'z')) && ((str[i]>='A' && str[i]<='Z') || (str[i+1]>='a' && str[i+1]<='z'))) {
                j++;
                string temp=str.substr(j, vel);
                if(temp==vec[i]) novi.replace(j, vel, obrnuti);
            }
            else if(((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) && ((str[i]>='A' && str[i]<='Z') || (str[i+1]>='a' && str[i+1]<='z'))) {
                string temp=str.substr(j, vel);
                if(temp==vec[i]) novi.replace(j, vel, obrnuti);
            }
        }
    }
    return novi;
}

string PigLatin (string str, vector<string> vec) {
     string novi=str;
    for(int i=0; i<vec.size(); i++) {
        string obrnuti=vec[i];
        std::reverse(obrnuti.begin(), obrnuti.end());
        int vel=obrnuti.length();
        for(int j=0; j<str.length()-1; j++) {
            if(((str[i]<'A' && str[i]>'Z') || (str[i]<'a' && str[i]>'z')) && ((str[i]>='A' && str[i]<='Z') || (str[i+1]>='a' && str[i+1]<='z'))) {
                j++;
                string temp=str.substr(j, vel);
                if(temp==vec[i]) novi.replace(j, vel, obrnuti+'a'+'y');
            }
            else if(((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) && ((str[i]>='A' && str[i]<='Z') || (str[i+1]>='a' && str[i+1]<='z'))) {
                string temp=str.substr(j, vel);
                if(temp==vec[i]) novi.replace(j, vel, obrnuti+'a'+'y');
            }
        }
    }
    return novi;
}

int main ()
{
    cout << "Unesite recenicu: ";
    string str;
    getline(cin, str);
    vector<string> vec;
    cout << "Unesite fraze: ";
    cin.clear();
    cin.ignore(1000, '\n');
    do {
        string temp;
        getline(cin, temp);
        vec.push_back(temp);
    } while(!(vec[vec.size()-1].empty()));
    for(int i=0; i<vec.size(); i++) {
        if(vec[i].empty()) vec.resize(vec.size()-1);
    }
    string pig(PigLatin(str, vec)), obr(ObrniFraze(str,vec));
    cout << "Recenica nakon PigLatin transformacije: ";
    cout << pig;
    cout << endl << "Recenica nakon obrtanja fraza: ";
    cout << obr;
	return 0;
}