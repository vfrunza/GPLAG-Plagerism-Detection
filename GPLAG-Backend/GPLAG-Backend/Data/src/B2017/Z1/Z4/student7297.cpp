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
#include <vector>

bool RecenicaSadrziRijec(std::string rec, std::string v){
	int n(0);
	bool logic(false);
	for(int i=0; i<rec.length(); i++){
		for(int j=0; j<v.length(); j++){
			if(rec[i+j]==v[j]){
			 n++;
			 
			}
			else {
				n=0;
				continue;
			}
		}
		if(n==v.length()) logic=true;
	}
	return logic;
}

void Razmijeni(char &a, char &b){
	char pomocna(a);
	a=b;
	b=pomocna;
}

void OkreniString(std::string &s){
	int i(s.length()-1);
	int j(0);
	while(j<i){
		Razmijeni(s[j], s[i]);
		j++;
		i--;
	}
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	for(std::string jedan: v)
	{                bool l(RecenicaSadrziRijec(s, jedan));
	if(l==true){  
		int n(0), i, j;
		for( i=0; i<s.length(); i++){
			for(j=0; j<jedan.length(); j++){
				if(s[i]==s[j]){
					if(s[i+j]==s[j]) n++;
					else break;
			}
		}} if(n==jedan.length()){
                        for(int k=i+j; k<=jedan.length(); k++){
                        	OkreniString(jedan);
                        	for(int j=0; j<jedan.length(); j++){
                        		s[i+j]=jedan[j];
                  
                        		i++;
                        		j++;
                        	}
                        }
                        }
						}
					}
	return s;
}


int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);

std::cout<<"Unesite fraze: ";
std::vector<std::string> v;
std::string fraza;
do{
	std::getline(std::cin, fraza);
	v.push_back(fraza);
} while(!"\n\n");
	
	
	std::string g(NapraviPalindrom(recenica, v));
	std::cout<<"Recenica nakon Palindrom transformacije: "<<g;
	
	return 0;
}