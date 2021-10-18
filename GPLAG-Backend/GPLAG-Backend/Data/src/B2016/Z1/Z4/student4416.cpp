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
std::string ObrniFraze(std::string recenica, std::vector<std::string> Stringovi){
	for(int i=0;i<Stringovi.size();i++){
		for(int j=0;j<recenica.length()-Stringovi.at(i).length()+1;j++){
			if(recenica.at(j)!=Stringovi[i][0])continue;
			if(Stringovi.at(i)==recenica.substr(j,Stringovi.at(i).length())){
				for(int k=0;k<Stringovi.at(i).length()/2;k++){
					char temp(recenica.at(j+k));
					recenica.at(j+k)=recenica.at(j+Stringovi.at(i).length()-1-k);
					recenica.at(j+Stringovi.at(i).length()-k-1)=temp;
				}
			}
		}
	}
	return recenica;
}
std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string>Stringovi){
	if(Stringovi.size()==0){
		int i,j;
		for(i=0;i<recenica.length();i++){
			while(i<recenica.length()){
				if((recenica.at(i)>='a'&&recenica.at(i)<='z')||(recenica.at(i)>='A'&&recenica.at(i)<='Z'))break;
				i++;
			}
			if(i==recenica.length())break;	
			j=i;
			while(j<recenica.length()){
				if(recenica.at(j)<'A'||(recenica.at(j)>'Z'&&recenica.at(j)<'a')||recenica.at(j)>'z')break;
				j++;
			}
			char temp(recenica.at(i));
			recenica.erase(recenica.begin()+i);
			recenica.insert(recenica.begin()+j-1,temp);
			recenica.insert(recenica.begin()+j,'a');
			j++;
			recenica.insert(recenica.begin()+j,'y');
			j++;
			i=j;
		}
	}
	else{
		for(int i=0;i<Stringovi.size();i++){
			for(int k=0;k<Stringovi.at(i).length();k++){
				if(Stringovi[i][k]<'A' || (Stringovi[i][k]>'Z'&&Stringovi[i][k]<'a')|| Stringovi[i][k]>'z')
					throw std::domain_error("Nekorektan izbor rijeci");
			}
			for(int j=0;j<recenica.length()-Stringovi.at(i).length()+1;j++){
				if(recenica.at(j)!=Stringovi[i][0]) continue;
				if(Stringovi.at(i)==recenica.substr(j,Stringovi.at(i).length())){
					bool izbaci(false);
					if(j==0){
						if(j+Stringovi.at(i).length()==recenica.length()) izbaci=true;
						else if(recenica.at(j+Stringovi.at(i).length())<'A'||(recenica.at(j+Stringovi.at(i).length())>'Z'&&recenica.at(j+Stringovi.at(i).length())<'a')||recenica.at(j+Stringovi.at(i).length())>'z') izbaci=true;
					}
					else if(j+Stringovi.at(i).length()==recenica.length()){
						if(recenica.at(j-1)<'A'||(recenica.at(j-1)>'Z'&&recenica.at(j-1)<'a')||recenica.at(j-1)>'z') izbaci=true;
					}
					else if((recenica.at(j-1)<'A'||(recenica.at(j-1)>'Z'&&recenica.at(j-1)<'a')||recenica.at(j-1)>'z')&&(recenica.at(j+Stringovi.at(i).length())<'A'||(recenica.at(j+Stringovi.at(i).length())>'Z'&&recenica.at(j+Stringovi.at(i).length())<'a')||recenica.at(j+Stringovi.at(i).length())>'z')) izbaci=true;
					if(izbaci){
						char temp(recenica.at(j));
						recenica.erase(recenica.begin()+j);
						recenica.insert(recenica.begin()+j+Stringovi.at(i).length()-1,temp);
						recenica.insert(recenica.begin()+j+Stringovi.at(i).length(),'a');
						recenica.insert(recenica.begin()+j+Stringovi.at(i).length()+1,'y');
					}
				} 
			}
		}
	}
	return recenica;
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string> Stringovi;
	std::cout<<"Unesite fraze: ";
	int brojac(0);
	while(std::cin.peek()!='\n'){
		Stringovi.resize(Stringovi.size()+1);
		std::getline(std::cin,Stringovi[brojac]);
		brojac++;
	}
	try{
	std::string a(IzmijeniUPigLatin(recenica,Stringovi));
	std::cout<<"Recenica nakon PigLatin transformacije: "<<a<<std::endl;
	}catch (std::domain_error a){
		std::cout<<"Izuzetak: "<<a.what()<<std::endl;
	}
	std::string a(ObrniFraze(recenica,Stringovi));
	std::cout<<"Recenica nakon obrtanja fraza: "<<a<<std::endl;
	return 0;
}