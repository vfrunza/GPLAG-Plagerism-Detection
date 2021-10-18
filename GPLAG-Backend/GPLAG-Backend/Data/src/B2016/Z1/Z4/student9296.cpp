/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
std::string ObrniFraze(std::string recenica, std::vector<std::string> spisak){
	for(int i=0; i<spisak.size(); i++){
		for(int j=0; j<spisak[i].length(); j++){
			if(spisak[i][j]<'A' || spisak[i][j]>'z') throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	std::string nova_recenica(recenica);
	for(int i=0; i<recenica.length(); i++){
		std::string pomoc;
		for(int k=0; k<spisak.size(); k++){
			if(spisak[k][0]==recenica[i]){
				for(int j=i; j<spisak[k].length(); j++) pomoc.push_back(recenica[j]);
				if(pomoc==spisak[k]){
					char jos_jedna_pomoc;
					for(int n=i; n<pomoc.length()/2; n++){
						jos_jedna_pomoc=nova_recenica[i];
						nova_recenica[i]=nova_recenica[pomoc.length()-n-1];
						nova_recenica[pomoc.length()-n-1]=jos_jedna_pomoc;
					}
				}
			}
		}
	}
	return nova_recenica;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> spisak){
	for(int i=0; i<spisak.size(); i++){
		for(int j=0; j<spisak[i].length(); j++){
			if(spisak[i][j]>'z' || spisak[i][j]<'A') throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	char slovo;
	if(spisak.size()==0){
		int i(0);
		while(i<recenica.length()){
			if(recenica[i]==' ') i++;
			else{
				while(recenica[i]!=' ' && i<recenica.length()-1){
					slovo=recenica[i];
					recenica[i]=recenica[i+1];
					i++;
				}
				recenica.insert(recenica.begin()+i, slovo);
				recenica.insert(recenica.begin()+i, 'ay');
				i++;
			}
		}
	}
	for(int i=0; i<spisak.size(); i++){
		for(int j=0; j<recenica.length()-spisak[i].length(); j++){
			if(recenica.substr(j,spisak[i].length())==spisak[i]){
				slovo=recenica[j];
				for(int k=j; k<spisak[i].length()-1; k++) recenica[k]=recenica[k+1];
				recenica.insert(recenica.begin()+j, slovo);
				recenica.insert(recenica.begin()+j, 'ay');
			}
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
	std::vector<std::string> spisak;
	std::string fraza;
	for(;;){
		std::getline(std::cin, fraza);
		if(fraza=="") break;
		spisak.push_back(fraza);
	}
	std::string nova_recenica1;
	try{
		nova_recenica1=ObrniFraze(recenica, spisak);
	}
	catch(std::domain_error od_obrni){
		std::cout<<od_obrni.what();
	}
	std::string nova_recenica2;
	try{
		nova_recenica2=IzmijeniUPigLatin(recenica, spisak);
	}
	catch(std::domain_error od_pig_latin){
		std::cout<<od_pig_latin.what();
	}
	std::cout<<"Recenica nakon PigLatin transformacije: "<<nova_recenica2<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<nova_recenica1;
	return 0;
}