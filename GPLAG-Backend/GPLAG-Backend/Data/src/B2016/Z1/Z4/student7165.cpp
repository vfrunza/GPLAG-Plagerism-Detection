/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
std::vector<std::string> VektorStringova(std::string str){
	std::vector<std::string> v;
	std::string pom;
	for(int i=0; i<str.size(); i++){
		if((str[i]>='A'&&str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
			while((str[i]>='A' && str[i]<='z' ) || (str[i]>='a' && str[i]<='z')){
				pom.push_back(str[i]);
				i++;
				if(i==str.size()) break;
			}
			v.push_back(pom);
			pom.resize(0);
		}
	}
	return v;
}
void ProvjeriVektor(std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if((v[i][j]<'A' || v[i][j]>'Z') && (v[i][j]<'a' || v[i][j]>'z')){
				if(v[i][j]==' ') continue;
				throw std::domain_error("Nekorektan izbor rijeci");
				
			}
		}
	}
}
std::string ZadnjeNaPrvo(std::string str){
	char pom=str[0];
	for(int i=0; i<str.size()-1; i++){
		str[i]=str[i+1];
	}
	str[str.size()-1]=pom;
	return str;
}
std::string ObrniStr(std::string str){
	for(int i=0; i<str.size()/2; i++){
		char temp=str[i];
		str[i]=str[int (str.size())-i-1];
		str[int(str.size())-i-1]=temp;
	}
	return str;
}
std::string ObrniFraze(std::string str, std::vector<std::string> v){
	ProvjeriVektor(v);
	for(int i=0; i<v.size(); i++){
		std::string obrnuta=ObrniStr(v[i]);
		for(int j=0; j<str.length()-v[i].length()+1; j++){
			if(str.substr(j,v[i].length()) == v[i]){
				int indeks=0;
				for(int k=j; k<j+v[i].length(); k++){
					str[k]=obrnuta[indeks];
					indeks++;
				}
			}
		}
	}
	return str;
}
std::string IzmijeniUPigLatin(std::string str, std::vector<std::string> v){
	if(v.size()==0) {v=VektorStringova(str);}
	ProvjeriVektor(v);
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<str.size()-v[i].length()+1; j++){
			if(str.substr(j,v[i].length())==v[i]){
				std::string temp=ZadnjeNaPrvo(v[i]);
				temp=temp+"ay";
				str=str.substr(0,j)+temp+str.substr(j+v[i].size(), str.size()-j-v[i].size());
			}
		}
	}
	return str;
}
int main()
{
	try{
		std::cout<<"Unesite recenicu: ";
		std::string recenica;
		std::getline(std::cin,recenica);
		std::cout<<"Unesite fraze: ";
		std::vector<std::string> v;
		while(true){
			std::string temp;
			std::getline(std::cin,temp);
			if(temp.length() == 0) break;
			v.push_back(temp);
		}
		auto piglatin=IzmijeniUPigLatin(recenica,v);
		std::cout<<"Recenica nakon PigLatin transformacije: "<< piglatin<<std::endl;
		auto obrnute_fraze=ObrniFraze(recenica,v);
		std::cout<<"Recenica nakon obrtanja fraza: "<< obrnute_fraze<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}
int main1(){
	
    try
    {
        std::string s{"Svaka elementarna funkcija je neprekidna gdje je definisana."};
        std::cout <<  ObrniFraze (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
        std::cout <<  IzmijeniUPigLatin (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
    return 0;
}