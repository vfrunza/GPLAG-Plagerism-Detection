/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <string>
std::string NapraviPalindrom(std::string recenica,std::vector<std::string> fraza){
int k,ima=0;
	for(int i=0;i<recenica.length();i++){
		ima=0;
		for(int j=0;j<fraza.size();j++){
			int h=0;
		k=0;
		std::string x;
		if(recenica[i]==fraza[j][h]) {
			int f=i;
			int r=j;
			int e=h;
			while(recenica[f]==fraza[r][e] && recenica[f]!='\0'){
		        f++;
		        e++;
		      
				
			}
			if((recenica[f]==' ' || recenica[f]=='\0' || recenica[f]==',' || recenica[f]=='.')&& fraza[r][e]=='\0') ima=1;
			if(ima) {
				while(recenica[i]==fraza[j][h] && recenica[i]!='\0'){
					x[k]=recenica[i];
					i++;
					k++;
					h++;
				}
				int d=recenica.size()-1;
					recenica.resize(recenica.size()+k);
					for(int g=recenica.size()-1;g>=i+k;g--){
						recenica[g]=recenica[d];
						d--;
					}
				for(int u=k-1;u>=0;u--){
					
					recenica[i]=x[u];
					i++;
					
				
			}
		
		}
		}
		}
	}
	return recenica;
	
}
std::string NapraviPoluPalindrom(std::string recenica,std::vector<std::string> fraza){
	
	
	for(int i=0;i<recenica.length();i++){
		for(int j=0;j<fraza.size();j++){
		
			int h=0,k=+0;
			int poc=i;
			int f=i;
			int paran=0;
			while(recenica[f]==fraza[j][h] && recenica[f]!='\0'){
		        k++;
		        f++;
		        h++;
			}
			
			if((recenica[f]==' ' || recenica[f]=='\0' || recenica[f]==',' || recenica[f]=='.') && fraza[j][h]=='\0'){
				i=f;
				int kraj=i-1;
				if(k%2==0) paran=1;
				if(!paran){
				while(kraj!=poc){
				   recenica[kraj]=recenica[poc];
				   kraj--;
				   poc++;
				}
				}
				else {
					while(kraj+1!=poc){
						recenica[kraj]=recenica[poc];
				   kraj--;
				   poc++;
						
					}
				}
		}
	}
}
return recenica;
}
int main ()
{
	std::cout <<"Unesite recenicu: ";
	std::string recenica;
	getline(std::cin,recenica);
	std::cout <<"Unesite fraze: ";
	std::string rijec;
	
	std::vector<std::string> fraza;
	std::getline(std::cin,rijec);
	while(rijec.length()!=0){
		fraza.push_back(rijec);
		std::getline(std::cin,rijec);
	}
	
	std::string s;
    s=NapraviPalindrom(recenica,fraza);
    std::string s2;
    s2=NapraviPoluPalindrom(recenica,fraza);
    std::cout <<"Recenica nakon Palindrom transformacije: "<<s<<std::endl;
    std::cout <<"Recenica nakon PoluPalindrom transformacije: "<<s2;
	return 0;
}