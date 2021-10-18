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

int BrojSlova(std::string s, int index){
	int brojac(0);
	for(int i=index;i<s.length();i++){
		if(s[i]<'A' || (s[i]>'Z' && s[i]<'a') || s[i]>'z') break;
		brojac++;
	}
	return brojac;
}
bool alfabet(std::string s){
	for(int i=0;i<s.length();i++){
		if((s[i]>=0&&s[i]<'A' )|| (s[i]>'Z'&&s[i]<'a') || (s[i]>'z'&&s[i]<=127))
			return false;
	}
	return true;
}
bool EngSlova(std::string s){
	for(int i=0;i<s.length();i++){
		if(s[i]>127 || s[i]<0) return false;
	}	
	return true;
}
std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
	for(int j=0;j<fraze.size();j++){
		if(EngSlova(fraze[j])==false) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		for(int i=0;i<recenica.length();i++){
			if(recenica.substr(i,fraze[j].length())==fraze[j]){
				for(int k=0;k<fraze[j].length()/2;k++){
					char pomocni(recenica[i+k]);
					recenica[i+k]=recenica[i+fraze[j].length()-k-1];
					recenica[i+fraze[j].length()-k-1]=pomocni;
				}
				
			}
			
		}
		
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> rijeci){
	bool prazan_vektor=false;
	if(rijeci.size()==0){
		prazan_vektor=true;
		rijeci.resize(1);
	}

	for(int j=0;j<rijeci.size();j++){
		if(alfabet(rijeci[j])==false) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		for(int i=0;i<recenica.length();i++){
			if(recenica[i]!=' '){
				if(recenica.substr(i,BrojSlova(recenica,i))==rijeci[j] || prazan_vektor==true){
					char pomocni(recenica[i]);
					int k;
					for(k=i;k<i+BrojSlova(recenica,i)-1;k++)
						recenica[k]=recenica[k+1];
					recenica[k]=pomocni;
					recenica.insert(recenica.begin()+k+1,'a');
					recenica.insert(recenica.begin()+k+2,'y');
		
				}
		
				i+=BrojSlova(recenica,i);
			}
		}
		
	}
	return recenica;
}

int main (){
	std::string recenica;
	std::vector<std::string> fraze;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	
	for(int i=0;;i++){
		fraze.resize(i+1);
		std::getline(std::cin,fraze[i]);
		if(fraze[i]==""){
			fraze.resize(fraze.size()-1);
			break;
		}
	}
	try{
			std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,fraze)<<std::endl;
	}
	 catch(std::domain_error izuzetak){
	 	std::cout << izuzetak.what() << std::endl;
	 }
	try{
		std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,fraze);
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	return 0;
}