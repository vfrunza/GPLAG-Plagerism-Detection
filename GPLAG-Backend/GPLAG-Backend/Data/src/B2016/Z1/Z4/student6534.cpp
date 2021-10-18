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

std::string IzvrniString(std::string rijec){
	std::string obrnuta;
	obrnuta.resize(rijec.length());
	for(int i=0;i<(rijec.length()/2)+1;i++){
		char pomoc(rijec.at(i));
		obrnuta.at(i)=rijec.at(rijec.length()-1-i);
		obrnuta.at(rijec.length()-1-i)=pomoc;
	}
	return obrnuta;
}
std::string ObrniFraze (std::string glavni,std::vector<std::string> izbaci){
	for(int i=0;i<izbaci.size();i++){
		for(char x:izbaci[i]){
			if(x <'A' or (x >'Z' and x <'a') or x >'z')
			throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	for(int i=0;i<izbaci.size();i++){
		std::string pomoc(izbaci.at(i));
		for(int j=0;j<glavni.length();j++){
			if(glavni.substr(j,pomoc.size())==pomoc) {
					std::string obrnuta(IzvrniString(pomoc));
					for(int k=0;k<obrnuta.length();k++){
						glavni[k+j]=obrnuta.at(k);
					}
				}
			}
		}
	return glavni;
}
std::string IzmijeniUPigLatin(std::string glavni, std::vector<std::string> zamijeni){
	if(glavni.length()==0) return glavni;
	char x('a'),y('y');
	for(int i=0;i<zamijeni.size();i++){
		for(char x:zamijeni.at(i)){
			if(x<'A' or (x>'Z' and x<'a') or x>'z')
			throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(zamijeni.size()==0){
		for(int i=0;i<glavni.length();i++){
			int pomoc(i);
			if (glavni.at(i)==' ') continue;
		
			pomoc.push_back(pomoc.at(0));
			pomoc.erase(pomoc.begin()+0);
			for(int j=i-pomoc.size();j<i;j++){
				int m(0);
				glavni.at(j)=pomoc.at(m);
				m++;
			}
			glavni.insert(glavni.begin()+i,x);
			glavni.insert(glavni.begin()+i+1,y);
			i=i+1;
		}
		return glavni;
	}
	for(int i=0;i<zamijeni.size();i++){
		for(int j=0;j<glavni.length();j++){
			if(zamijeni.at(i)==glavni.substr(j,zamijeni.at(i).length())){
				if(j!=0 and ((glavni.at(j-1)>'A' and glavni.at(j-1)<'Z') or (glavni.at(j-1)>'a' and glavni.at(j-1)<'z'))) continue;
				char pomoc(glavni.at(j+zamijeni.at(i).length()-1));
				glavni.at(j+zamijeni.at(i).length()-1)=glavni.at(j);
				for(int k=0;k<j+zamijeni.at(i).length();k++){
					if(k==j+zamijeni.at(i).length()-2){
						zamijeni.at(k)=pomoc;
						break;
					}
					zamijeni.at(k)=zamijeni.at(k+1);
				}
				glavni.insert(glavni.begin()+j+zamijeni.at(i).length(),x);
				glavni.insert(glavni.begin()+j+zamijeni.at(i).length(), y);
			}
		}
	}
	return glavni;
}

int main ()
{
	std::vector<std::string> a;
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline (std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	for(int i=0;i<3;i++){
		std::string b;
		std::getline(std::cin,b);
		a.push_back(b);
	}
	try{
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,a)<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;		
	}
	
	try{
		std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,a);
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}