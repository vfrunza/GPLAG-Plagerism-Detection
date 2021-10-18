#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;

bool DaLiJeIsto(string R, int pocetak, int kraj, string s){
	int j(pocetak);
	for(int i = 0; i < s.length(); i++){
		if(j == kraj) break;
		if(s.at(i) != R.at(j)) return false;
		j++;
	}
	return true;
}

string Obrni(string R, int pocetak, int kraj){
	string zavrsni;
	for(int i = kraj - 1; i > pocetak ; i--){
		zavrsni.push_back(R.at(i));
	}
	zavrsni.push_back(R.at(pocetak));
	return zavrsni;
}

string ObrniP(string R, int pocetak, int kraj){
	int i=pocetak; int j=kraj-1;
	while(i<j){
		if(i>=j)break;
		R.at(j)=R.at(i);
		i++;
		j--;
		
	}
	return R;
	
}
string NapraviPalindrom(string Recenica, vector<string> Rijeci){
	int pocetak(0), kraj(0);
	for(int j = 0; j < Rijeci.size(); j++){
	    for(int i = 0; i < Recenica.length(); i++){
        	int k(0);
        	if(Recenica.at(i) == Rijeci.at(j).at(0)){
            	pocetak = i;
            	while(Recenica.at(i) == Rijeci.at(j).at(k)){
                	k++;
                	i++;
                	if(i == Recenica.length()) break;
                	if(k == Rijeci.at(j).length()) break;
            	}
        	kraj = i;
        	}
        	if(k == Rijeci.at(j).length() && (i == Recenica.size() || Recenica.at(i) == ' '  || Recenica.at(i) == ',' || Recenica.at(i) == '.')){
            	string Palindrom(Obrni(Recenica, pocetak, kraj));
            	Recenica.insert(kraj, Palindrom);
        	}
    	}
	}
return Recenica;
}
string NapraviPoluPalindrom(string Recenica, vector<string> Rijeci){
	int pocetak(0), kraj(0);
	for(int j = 0; j < Rijeci.size(); j++){
	    for(int i = 0; i < Recenica.length(); i++){
	    	int k(0);
        	if(Recenica.at(i) == Rijeci.at(j).at(0)){
            	pocetak = i;
            	while(Recenica.at(i) == Rijeci.at(j).at(k)){
                	i++;
                	k++;
                	if(i == Recenica.length()) break;
                	if(k == Rijeci.at(j).length()) break;
            	}
        	kraj = i;
        	}
        	if(k == Rijeci.at(j).length() && (i == Recenica.size() || Recenica.at(i) == ' '  || Recenica.at(i) == ',' || Recenica.at(i) == '.')){
            	Recenica = ObrniP(Recenica, pocetak, kraj);
        	}
    	}
	}
return Recenica;
}

int main (){
	cout<<"Unesite recenicu: ";
	string s;
	getline(cin, s);
	vector<string> rijeci;
	string x;
	cout<<"Unesite fraze: ";
	while(1){
		getline(cin, x);
		if(x.length()==0) break;
		rijeci.push_back(x);
	}
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s, rijeci);
	cout<<endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s, rijeci);
	return 0;
}