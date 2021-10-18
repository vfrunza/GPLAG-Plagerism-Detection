/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>

std::string Obrni(std::string s){
	std::string f;
	for(int i=s.size();i>=0;i--){
		f+=s[i];
	}
	return f;
}

std::string ObrniPoPig(std::string a){
	std::string novi;
	if(a.size()==0) return {};
	for(int i=1;i<a.size();i++){
		novi+=a[i];
	}
	novi+=a[0];
	novi+='a';
	novi+='y';
	
	return novi;
}

std::string ObrniFraze(std::string s,std::vector<std::string> v){
	std::string novi;
	
	for(int i=0;i<v.size();i++){
		for(int j=0;j<s.size();j++){
			
			if(v[i]==s.substr(j,v[i].length()) && s[j+v[i].length()]==' ' && s[j-1]==' '){
					int brojac(0);
				std::string pom(Obrni(s.substr(j,v[i].length())));
				for(int k=j;k<j+v[i].size();k++){
					s[k]=pom[brojac+1];
						brojac++;
				}
				
			}
		
			
		}
	}
	
	return s;
}

bool SamoSlova(char a){
	char b(toupper(a));
	if(b<'A' || b>'Z') return false;
	return true;
}

std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				if(SamoSlova(v[i][j])==false) {
					throw std::domain_error("Nekorektan izbor rijeci");
				}
			}
		
	}
	
	std::string novi;
	if(v.size()==0){
		for(int i=0;i<s.size();i++){
			 std::string pom;
                std::string pom1;
                for(int j=i;j<s.size();j++){
       if(s[j]==' ' || s[j]==',' || s[j]=='.'){
                break;
       }
                   pom1+=s[j];
                    i++;
                }
                
	 pom=ObrniPoPig(pom1);
            novi+=pom;
                novi+=s[i];
	}
	}
	else{	
		
	for(int i=0;i<s.size();i++){
		for(int j=0;j<v.size();j++){
				std::string rijec(v[j]);
			if(v[j]==s.substr(i,v[j].length()) && s[i+rijec.length()]==' ' && s[i-1]==' ' ){
				std::string pom(ObrniPoPig(s.substr(i,v[j].length()))); 
				novi+=pom;
				i=i+v[j].length();
			}
			
			
		}
		novi+=s[i];
	}
	}
	return novi;	
}






int main ()
{
	try{
			std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::vector<std::string> v;
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::string rijec;
		std::getline(std::cin,rijec);
		if(rijec.size()==0) break;
		v.push_back(rijec);
		
	}
	try{

	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,v)<<std::endl;
	}
	catch(std::domain_error izuzetak){	
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
		std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,v);
}
	catch(...){	
	
	}
	return 0;
}