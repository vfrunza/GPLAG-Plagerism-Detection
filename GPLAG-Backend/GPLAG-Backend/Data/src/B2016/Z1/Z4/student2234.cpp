/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
typedef std::vector<std::string>Vektorstringova;
std::string ObrniFraze(std::string s,Vektorstringova vek){
	for(int i(0);i<vek.size();i++){
	std::string str=vek[i];
	int broj(0);
	for(int k(0);k<vek[i].size();k++)broj++;
	for (int j(0);j<s.length();j++){
		int poc(0);
		if(s[j]==str[poc]){
			int pom(j);
			int vel(poc);
			while(s[pom]==str[vel]){
				pom++;
				vel++;
				if(pom==s.length())break;
				if(vel==broj)break;
			}	if(broj==pom-j){
				pom--;
				while(j<pom){
					char kalup;
					kalup=s[j];
					s[j]=s[pom];
					s[pom]=kalup;
					j++;
					pom--;
			}
		}
	}
	}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s,Vektorstringova vek){
	for(int i(0);i<vek.size();i++){
		std::string str=vek[i];
		for(int k(0);k<str.size();k++){
			if(!(str[k]>='A' && str[k]<='Z') && !(str[k]>='a' && str[k]<='z')) throw std::domain_error("Nekorektan izbor rijeci");
		}
		int broj(vek[i].size());
		for(int j(0);j<s.length();j++){
			int poc(0);
			if(s[j]==str[poc]){
				int pom(j);
				int vel(poc);
				while(s[pom]==str[vel]){
					pom++;
					vel++;
					if(pom==s.length())break;
					if(vel==broj)break;
				}
				if(broj==pom-j){
					pom--;
					s.insert(s.begin()+pom+1,s[j]);
					s.erase(s.begin()+j);
					char a='a';
					char b='y';
					s.insert(s.begin()+pom+1,b);
					s.insert(s.begin()+pom+1,a);
				}
			}
		}
	}
	return s;
}
int main (){
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	Vektorstringova vek;
	try{
	for(;;){
		std::string fraza;
		std::getline(std::cin,fraza);
		vek.push_back(fraza);
		if(std::cin.peek()=='\n')break;
	}
	std::string pig;
	pig=IzmijeniUPigLatin(recenica,vek);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<pig<<std::endl;
	}
	catch(std::domain_error greska){
		std::cout<<"Izuzetak: "<<greska.what();
	}
	std::string obrni;
	obrni=ObrniFraze(recenica,vek);
	std::cout<<"Recenica nakon obrtanja fraza: "<<obrni;
	return 0;
}