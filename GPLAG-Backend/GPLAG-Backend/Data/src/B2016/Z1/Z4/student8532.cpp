/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string obrniString(std::string str) {
	for(int i(0);i<str.length()/2;i++) {
		char tmp = str[i];
		str[i] = str[ str.length() - 1 - i ];
		str[ str.length() - 1 - i] = tmp;
	}
	return str;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze) {
	for(int i(0);i<fraze.size();i++) {
		for(int j(0);j<recenica.length();j++) {
			int len = fraze[i].length();
			if(fraze[i] == recenica.substr(j,len)) {
				auto tmpString = obrniString(recenica.substr(j,len));
				int tmp = j;
				for(int k(0);k<tmpString.length();k++) {
					recenica[j++]=tmpString[k];
				}
				j=tmp;
			}
		}
	}
	return recenica;
}

std::string PigLatinTransform(std::string str) {
	if(str.size())
		return str.substr(1,str.length()-1) + str[0] + "ay";
	else return "";
}

bool slovo(char c){
	return ( ((c>='a' && c<='z') || (c>='A' && c<='Z')) );
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci) {
	std::string retRecenica;
	for(int i(0);i<rijeci.size();i++) {
		for(int j(0);j<rijeci[i].length();j++)
			if( !((rijeci[i][j]>='a' && rijeci[i][j] <= 'z') || (rijeci[i][j]>='A' && rijeci[i][j]<='Z')) )  
				throw std::domain_error("Nekorektan izbor rijeci");
	}
	if(rijeci.size()) {
		for(int i(0);i<rijeci.size();i++) {
			for(int j(0);j<recenica.size();j++) {
				if( recenica.substr(j, rijeci[i].size()) == rijeci[i] ) {
					if(  ( j==0 || (j!=0 && !slovo(recenica[j-1])) ) && ( j+rijeci[i].size()==recenica.size()-1 || !slovo(recenica[j+rijeci[i].size()]) )  ) {
						std::string tmpString = recenica.substr(j,rijeci[i].size());
						recenica.erase(j, rijeci[i].size());
						tmpString = PigLatinTransform(tmpString);
						recenica.insert(j, tmpString);
					}	
				}
			}
		}
	}
	else {
		int i=0;
		while(i<recenica.size()) {
			int tmp = i;
			while(i<recenica.size() && slovo(recenica[i]))
				i++;
			std::cout<<"Pocetak: "<<tmp<<" Kraj: "<<i<<std::endl;
			
			std::string tmpString = recenica.substr(tmp, i-tmp);
			std::cout<<tmpString<<std::endl;
			recenica.erase(tmp, i-tmp);
			tmpString = PigLatinTransform(tmpString);
			recenica.insert(tmp, tmpString);
			while(slovo(recenica[i++]));
			while(i<recenica.size() && !slovo(recenica[i]))
				i++;	
		}
	}
	return recenica;
}


int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for(;;) {  
		std::string x;
		std::getline(std::cin, x);
		if(x=="") break;
		fraze.push_back(x);
	}
	try {
		std::string x = IzmijeniUPigLatin(recenica,fraze);
		std::cout<<"Recenica nakon PigLatin transformacije: "<< x <<std::endl;
		std::cout<<"Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze) ;
	}
	catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
		std::cout<<"Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);
	}
	return 0;
}