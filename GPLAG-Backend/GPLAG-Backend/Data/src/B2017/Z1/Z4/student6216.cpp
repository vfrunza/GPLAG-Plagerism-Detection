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
using namespace std;
string NapraviPalindrom(string s, vector <string> v){
	string c;
    for(int i=0; i<v.size(); i++){
    	for(int j=0; j<s.length(); j++){
    		if(v.at(i) == s.substr(j, v.at(i).size()) && ((j+v.at(i).size() == s.length()) || !((s.at(j+v.at(i).size())>= 'A' && s.at(j+v.at(i).size())<='Z') || (s.at(j+v.at(i).size()) >= 'a' && s.at(j+v.at(i).size())<='z'))))
    		{ c = s.substr(j, v.at(i).length());
    		 int f(0);
    		 while(f < v.at(i).size()){ j++; f++; }
    		 int r(1);
    		 for(int k=0; k<c.length(); k++){
    		  /*	s.resize(r);
    		 	s.at(j) = c.at(k);*/
    		    s.insert(s.begin()+j, c.at(k));
    		 	
    		 }
    		}
    	}
    }
	
	return s;
	
}
string NapraviPoluPalindrom(string s, vector <string> v){
    string c;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<s.length(); j++){
            if(v.at(i) == s.substr(j, v.at(i).size()) && ((j+v.at(i).size() == s.length()) || !((s.at(j+v.at(i).size())>= 'A' && s.at(j+v.at(i).size())<='Z')||(s.at(j+v.at(i).size())>= 'a'&& s.at(j+v.at(i).size())<='z')))){
                c = s.substr(j, v.at(i).length());
                int f(0);
                while(f <= (c.length()-1)/2){
                    j++;  f++;
                }
                if(c.length() % 2 ==0) int z=(c.length()-1)/2;
                else int z=c.length()/2;
                for(int k=(c.length()-2)/2; k>=0; k--){
                    s.erase(s.begin()+j);
                    s.insert(s.begin()+j, c.at(k));
                    j++;
                }
              //  s.insert(s.begin()+j, ' ');
            }
        }
    }
    return s;
}
int main ()
{   string s, k;
    vector<string> v;
    cout << "Unesite recenicu: ";
    getline(cin,s);
    
    cout << "Unesite fraze: ";
    
    for(int i=0;;i++){
       getline(cin, k);
       if(k.length()==0) break;
       v.push_back(k);
    }
    cout << "Recenica nakon Palindrom transformacije: ";
    cout << NapraviPalindrom(s,v);
    cout << endl << "Recenica nakon PoluPalindrom transformacije: ";
    cout << NapraviPoluPalindrom(s,v);
	return 0;
}