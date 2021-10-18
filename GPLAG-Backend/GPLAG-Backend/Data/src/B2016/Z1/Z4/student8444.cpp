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
std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	for(int i=0; i<v.size();i++){//kroz vektor rijeci
		
		for(int j=0;j<v[i].size();j++){//kroz slova rijeci
		
			for(int k=0; k<s.size();k++){//kroz recenicu
				
				int p=k;
				int br=0;
				while(s[k]==v[i][j] && k<s.size() && j<v[i].size()){//bez jednako
					k++;
					j++;
					br++;
				}
					if(j==v[i].size()){
						int q=--k;
						char pom;
						while(p<q){
							pom=s[p];
							s[p++]=s[q];
							s[q]=pom;
							q--;
						}//kraj while
					}//kraj ifa
					j=j-br;
					}//k petlja
					break;
				}//kraj j petlje
				
			}//kraj i petlje
		
		
		return s;
}
std::string IzmijeniRijec(std::string s){
	return s.substr(1,s.size())+s.substr(0,1)+"ay";
}

std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	std::string vrati;
	if(v.size()==0){
		for(int k=0; k<s.length();k++){
			int p=k;
			int br=0;
			while(k<=s.size()){
				k++;
				br++;
			}
			vrati+=IzmijeniRijec(s.substr(p,br))+" ";
			if(k==s.size()) return vrati;
		}
	}
	for(int i=0; i<v.size();i++){
		for(int j=0; j<v[i].size();j++){
			if(((v[i][j]<'A' || v[i][j]>'Z') && (v[i][j]<'a' || v[i][j]>'z'))) throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	for(int k=0; k<s.length();k++){
		for(int i=0; i<v.size();i++){
			for(int j=0; j<v[i].length();j++){
				if(s[k]!=v[i][j]) break;
				int p=k;
				int br=0;
				while(s[k]==v[i][j] && k<s.size() && j<v[i].size()){
					k++;
					j++;
					br++;
				}
				//if(j==v[i].size() && (s[k]!=' ' || k!=s.size()-1)) continue;
				if(j==v[i].size() && (s[k]==' ' || k==s.size()-1)) {//dodala ova 2 uslova
					int q=--k;
					vrati.resize(0);
					vrati=s.substr(0,p)+IzmijeniRijec(s.substr(p,v[i].size()))+s.substr(q+1,s.size());
					s=vrati;
				}
				if(k==s.size() && i!=v.size()){
					k=k-br;
				}
			}
			
		}
		while(s[k]!=' ' && k<s.size())k++;
		if(k==s.size())break;
	}
	return s;
}

int main ()
{
	std::string s;
	std::string pom;
	std::vector<std::string> v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	//std::cout<<s;
	std::cout<<"Unesite fraze: ";
	while(true){
		std::getline(std::cin,pom);
		v.push_back(pom);
		if(std::cin.peek()=='\n') break;
	}
	pom.resize(0);
	
	try{
	
	pom=IzmijeniUPigLatin(s,v);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<pom;
	pom.resize(0);
	std::cout<<"\n";
	std::cout<<"Recenica nakon obrtanja fraza: ";
	pom=ObrniFraze(s,v);
	std::cout<<pom;
	return 0;
}