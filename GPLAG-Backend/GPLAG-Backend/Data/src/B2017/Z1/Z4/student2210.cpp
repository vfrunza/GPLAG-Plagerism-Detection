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


string IzvrniString(string recenica){
   for(int i = recenica.length()-1,j=0;i>=0 && j<i;i-- && j++)
      swap(recenica.at(i),recenica.at(j));
      return recenica;
}

string DajPoluPalindrom(string s){ 
	string pomocni (IzvrniString(s)); 
	 string pali;
    int duzina=s.length();
    pali.resize(duzina);
    for(int i=0;i<s.length()/2;i++){
        pali.at(i)=s.at(i);
    }
    for(int i=s.length()/2;i<pali.length();i++) pali.at(i)=pomocni.at(i);
    return pali;
}


string NapraviPalindrom(string s, vector<string> v) {
	if(s.length()==0 || v.size()==0) return s;
		
	
	for(int i=0; i<v.size(); i++) {
		
		for(int j=0; j<(s.length()-v.at(i).length()); j++) {
	// Trazenje fraza u stringu		
	 if ((s.substr(j, v.at(i).length())==v.at(i))  && (s.at(j+ v.at(i).length())==' ') && (j==0 ||  ( j != 0 &&  s.at(j-1) == ' '))) {
			string temp = (s.substr(j, v.at(i).length()));
		
			int l = 0; // olaksava kretanje 
			for(int k = temp.length()-1; k>=0; k--) { // Prepisemo iz pomocnog unazad
				s.insert(s.begin() + j +temp.length() + l, temp.at(k));
				l++;
			}
				j += 2*temp.length();
         }
       }
	}
	
	return s;

}

string NapraviPoluPalindrom(string s, vector<string> v) {
	if(s.length()==0 || v.size()==0) return s;
	
		
	for(int i=0; i<v.size(); i++) {
		
		for(int j=0; j<(s.length()-v.at(i).length()); j++) {
			
			 if ((s.substr(j, v.at(i).length())==v.at(i))  && (s.at(j+ v.at(i).length())==' ') && (j==0 ||  ( j != 0 &&  s.at(j-1) == ' '))) {
	 				string temp = (s.substr(j, v.at(i).length()));
	 				string polp = DajPoluPalindrom(temp);
	 			//	int vel = polp.length();
	 				for(int k=0; k<polp.length(); k++) {
	 						s.at(j+k) = polp.at(k);
	 					
	 				}  
	 				j+= polp.length();
			 }
			
			
       }
	}
	
	return s;
	

}


int main ()
{
	
	vector<string> v;
	string recenica{""};
	cout << "Unesite recenicu: ";
	getline(cin, recenica);
	cout << "Unesite fraze: ";
    string fraze{""};
	cin.clear();
	for(;;) {
		getline(cin, fraze);
		cin.clear();
		if(fraze=="") break;
		
		v.push_back(fraze); }
	
	string palindrom (NapraviPalindrom(recenica, v));
	string polupalindrom (NapraviPoluPalindrom(recenica, v));
	
	cout << "Recenica nakon Palindrom transformacije: ";
	cout << palindrom;
	
		cout << "\nRecenica nakon PoluPalindrom transformacije: ";
	cout << polupalindrom;

	

	return 0;
}
