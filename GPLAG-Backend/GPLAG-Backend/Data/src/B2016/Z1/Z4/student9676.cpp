/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
typedef std::vector<std::string> ena;
bool provjeri (ena rijeci){
	for (int i=0; i<rijeci.size(); i++){
		for(int j=0; j<rijeci[i].length(); j++){
			if (!((rijeci[i][j]>='a'&&rijeci[i][j]<='z')||(rijeci[i][j]>='A'&&rijeci[i][j]<='Z'))) 
			return false;
		}
	}
	return true;
}

std::string  ObrniFraze(std::string rec, ena rijeci){
	std::string vrati;
	for(unsigned int i = 0; i < rijeci.size(); i++){
		int j(0);
		while(j <int(rec.length())){
			if(rijeci[i] == rec.substr(j, rijeci[i].length())){
				int save = j;
				int k = j,x=j+rijeci[i].length();
				char temp;
				while (k < j + rijeci[i].length()/2){
					temp = rec[k];
					rec[k] = rec[x-1-k + save];
					rec[x-1-k+save]=temp;
					k++;
				}
				j = save;
			}
			j++;
		}
	}
	return rec;
}

bool je_alfabet (char alfa){
	return ((alfa>='a' && alfa<='z')||(alfa>='A'&&alfa<='Z'));
}

int rijec (std::string s, int loc){ //vraca duzinu rijeci ako je rijec 0 ako nije rijec
	bool start=false,end=false;
	int save{loc};
	
	if (loc==0 || !je_alfabet(s[loc-1])) start =true;
	while (loc<s.length() && je_alfabet(s[loc])){
		loc++;
	}
	if (loc==s.length()|| !je_alfabet(s[loc])) end=true;
	if (start && end) return (loc-save);
	return 0;
}

std::string IzmijeniUPigLatin(std::string rec, ena rijeci){
	if (!provjeri(rijeci)) throw std::domain_error ("Nekorektan izbor rijeci");
	int duzina = rijeci.size();
	
	if(rijeci.size() == 0){
		duzina = 1;
	
	}
	for(int i = 0; i < duzina; i++){
		int j(0);
		if(rijeci.size() == 0){
			while(j<rec.length()){
				int pomjeri(rijec(rec,j));
				if(pomjeri){
					char tmp(rec[j]);
					rec = rec.substr(0, j) + rec.substr(j+1, pomjeri -1) + tmp + "ay" + rec.substr(j+pomjeri, rec.length() - j - pomjeri);
				}
				j++;
			}
		}
		else{
			while(j < int(rec.length())){
				int pomjeri(rijec(rec,j));
				if(pomjeri && rijeci[i] == rec.substr(j, pomjeri)){
					char tmp(rec[j]);
					rec = rec.substr(0,j) + rec.substr(j +1, pomjeri - 1) + tmp + "ay" + rec.substr(j + pomjeri, rec.length() - j - pomjeri);
				}
				j++;
			}
		}
	}
	return rec;
}



int main (){
	
	std::cout<<"Unesite recenicu: ";
	std::string rec;
	std::getline(std::cin, rec);
	std::cout<<"Unesite fraze: ";
	ena rijeci;
	std::string s;
	while (std::cin.peek()!='\n'){
		std::getline(std::cin, s);
		rijeci.push_back(s);
	}
	
	try{
	std::string s(IzmijeniUPigLatin(rec,rijeci));
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<s<<std::endl;
	
	} catch (std::domain_error greska){
	std::cout<<"Izuzetak: "<<greska.what()<<std::endl;
}

	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<ObrniFraze(rec,rijeci);

	return 0;
}