/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
std::string Obrni (std::string recenica, std::string fraza, int pocetak){
	int k(0);
	std::string pom(fraza);
	for(int j=fraza.length() - 1; j>=0 ; j--) pom[k++]=fraza[j];
	for(int i=0 ; i<pom.length() ; i++) recenica[pocetak++] = pom[i];

	return recenica;

}



std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze){

	for(int i=0 ; i<fraze.size() ; i++){
		std::string pom = fraze[i];
    int provjera(0);
		for(int j=0 ; j<recenica.length() ; j++){
			//int brs(0);
			//if(j < recenica.length()) while(recenica[j]==' ' && j != recenica.length()) j++;
			//int tmp = j;
			//if(tmp < recenica.length()) while(recenica[tmp++]!= ' ' && tmp != recenica.length()) brs++;
			//if(tmp == recenica.length()) brs++;
			//if(brs==pom.length())
			//{
				if(pom[0]==recenica[j]){
					int br(0), pocetak(j);
					for(int k = 0 ; k<pom.length() ; k++){
						if(k>=recenica.length()) break;
						if(recenica[pocetak++]==pom[k]) br++;
					}
					if(br==pom.length()){
						recenica =  Obrni(recenica, pom, j);
						provjera++;
					}


				}
			//}
			//else {while(recenica[j] != ' ' && j != recenica.length()) j++;}
		}
		if(provjera != 0) {i--; provjera = 0;}
	}
	return recenica;
}

std::string Pig(std::string recenica, std::string fraza, int pocetak){
	std::string s1, s2, s3;
	for(int i=0 ; i<pocetak ; i++) s1.push_back(recenica[i]);

	for(int i=pocetak+fraza.length() ; i<recenica.length() ; i++) s3.push_back(recenica[i]);

	for(int i=1 ; i<fraza.length() ; i++) s2.push_back(fraza[i]);
	s2 = s2 + fraza[0] + "ay";

	recenica = s1 + s2 + s3;

	return recenica;

}


std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> fraze){
	for(int i=0 ; i<fraze.size() ; i++){
		std::string pom = fraze[i];
		for(int j=0 ; j<pom.length() ; j++){
			if(((pom[j]<65 || pom[j]>90) && (pom[j] > 32 || pom[j] < 32))
			&& ((pom[j]<97 || pom[j]>122) && (pom[j] > 32 || pom[j] < 32)))
                throw std::domain_error("Nekorektan izbor riječi");
		}
	}
		for(int i=0 ; i<fraze.size() ; i++){
        int provjera(0);
		std::string pom = fraze[i];
		for(int j=0 ; j<recenica.length() ; j++){
			//int brs(0);
			//if(j<recenica.length()) while(recenica[j]==' ' && j != recenica.length()) j++;
			//int tmp = j;
			//if(tmp < recenica.length()) while(recenica[tmp++]!= ' ' && tmp != recenica.length()) brs++;
			//if(tmp == recenica.length()) brs++;
			//if(brs==pom.length()){
				//if(pom[0]==recenica[j]){
					int br(0), pocetak(j);
					for(int k = 0 ; k<pom.length() ; k++){
						if(k>=recenica.length()) break;
						if(recenica[pocetak++]==pom[k]) br++;
					}
					if(br==pom.length()){
						recenica =  Pig(recenica, pom, j);
					}



				//}
			//}
			else {while(recenica[j] != ' ' && j != recenica.length()) j++;}
		}
		if(provjera != 0) {i--; provjera = 0;}
	}
	 return recenica;
}

int main ()
{
	std::string recenica, pomocna;
	std::vector<std::string> fraze;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	pomocna = recenica;
	while(1){
		std::string x;
		std::getline(std::cin, x);
		if(x.length()==0) break;
		else fraze.push_back(x);
	}
	try{
	pomocna = IzmijeniUPigLatin(recenica, fraze);

	std::cout<<"Recenica nakon PigLatin transformacije: "<<pomocna;
	}
	catch(std::domain_error izuzetak) {
      std::cout<<"\n"<<izuzetak.what() << std::endl;
	}
	recenica = ObrniFraze(recenica, fraze);

	std::cout<<"\nRecenica nakon obrtanja fraza: "<<recenica;

	return 0;
}
