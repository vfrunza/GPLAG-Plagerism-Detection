#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


string ObrniString(string recenica){
	for(int i=0; i<recenica.size()/2; i++){
		char pomocna(recenica.at(i));
		recenica.at(i)=recenica.at(recenica.size()-1-i);
		recenica.at(recenica.size()-1-i)=pomocna;
	}
	return recenica;
}

bool JeLiSlovo(char znak){
	if((znak>='A' and znak<='Z') or (znak>='a' and znak<='z'))
		return true;
	return false;
}

bool JeLiRijec(string recenica, int indeks, int duzina){
	int prava(recenica.size());
	if(indeks==0 || (indeks+duzina+1)>=recenica.size())
		return true;				//Pocetak i kraj stringa
	
	if(!JeLiSlovo(recenica.at(indeks-1)) and !JeLiSlovo(recenica.at(indeks+duzina)))
		return true;
	return false;
}

string NapraviPalindrom(string recenica, vector<string> fraze){
	for(string fraza : fraze){
		int duzina(fraza.length());
		for(int i=0; i<recenica.size(); i++){
			string podstring(recenica.substr(i,duzina));
			if(JeLiRijec(recenica,i,duzina) and podstring== fraza){
				
				recenica.insert(i+duzina,ObrniString(podstring));
				i+=duzina*2-1;
			}
		}
	}
	return recenica;
}

string NapraviPoluPalindrom(string recenica, vector<string> fraze){
	for(string fraza : fraze){
		int duzina(fraza.length());
		for(int i=0; i<recenica.size(); i++){
			string podstring(recenica.substr(i,duzina));
			if(JeLiRijec(recenica,i,duzina) and podstring== fraza){
				
				for(int j=0; j<duzina/2; j++){
					recenica.at(i+duzina-1-j)=recenica.at(i+j);
				}
				i+=duzina-1;
			}
		}
	}
	return recenica;
}


int main ()
{

	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	cout<<"Unesite fraze: ";
	vector<string> fraze;
	string fraza;
	do{
		
		getline(cin,fraza);
		if(fraza.length()>0) fraze.push_back(fraza);
	}while(fraza.length()>0);
	
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze)<<endl;
	
	return 0;

}