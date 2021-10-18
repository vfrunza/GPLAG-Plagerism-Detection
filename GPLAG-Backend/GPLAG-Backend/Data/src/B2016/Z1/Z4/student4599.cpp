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

std::string IzmijeniUPigLatin(std::string r, std::vector<std::string> f){
	
	for(int i(0);i<f.size();i++){
		for(int j(0);j<f[i].size();j++){
			
			if(std::toupper(f[i][j])<'A' || std::toupper(f[i][j])>'Z'){
			
			throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
			
			}
		}
	}
	
	if(f.size()==0){
		
		std::vector<std::string> rijeci;
		
		for(int j(0);j<r.size();j++){
			
			
			if (std::toupper(r[j])>='A' && std::toupper(r[j])<='Z'){
				std::string s;
				
				while(std::toupper(r[j])>='A' && std::toupper(r[j])<='Z'){
					
					s.push_back(r[j]);
					j++;
				}
				
				rijeci.push_back(s);
				
			}
		
		}
		
		for(int i(0);i<rijeci.size();i++){
			for(int j(0);j<r.size();j++){
				
				if(rijeci[i][0]==r[j]){
				
				bool e(true);
				
				for(int k(0);k<rijeci[i].size();k++){
					
					if(rijeci[i][k]!=r[j]){
						e=false;
						break;
					}
					
					j++;
				}
				
				if(e==true)
			
				r=r.substr(0,j-rijeci[i].size())+r.substr(j-rijeci[i].size()+1,rijeci[i].size()-1)+r[j-rijeci[i].size()]+"ay"+r.substr(j,r.size()-1);
			}
		}
		}
		
	return r;
	}
	
	for(int i(0);i<f.size();i++){
		for(int j(0);j<r.size();j++){
			
			if(f[i][0]==r[j]){
				
				bool e(true);
				
				for(int k(0);k<f[i].size();k++){
					
			
						if(k==0 && (std::toupper(r[j-1])>='A' && std::toupper(r[j-1])<='Z')){
							e=false;
						}
			
						if(k==f[i].size()-1 &&(std::toupper(r[j+1])>='A' && std::toupper(r[j+1])<='Z')){
						e=false;
					}
					
					if(f[i][k]!=r[j]){
						
						e=false;
						break;
					}
					
					
					j++;
				}
				
				if(e==true){
				r=r.substr(0,j-f[i].size())+r.substr(j-f[i].size()+1,f[i].size()-1)+r[j-f[i].size()]+"ay"+r.substr(j,r.size()-1);
				
				}
			}
		}
	}
	
	return r;
}

std::string ObrniFraze(std::string r, std::vector<std::string> f){
	
	if(f.size()==0){
		
	}
	
	for(int i(0);i<f.size();i++){
		for(int j(0);j<r.size();j++){
			
			if(f[i][0]==r[j]){
				
				bool e(true);
				
				for(int k(0);k<f[i].size();k++){
						
					if(f[i][k]!=r[j]) { 
						e=false;
						break;
					}
					
					if(f[i][k]==r[j] )
					
					j++;
				}
				
				if(e==true){
					
					j=j-f[i].size();
					
					for(int l(f[i].size()-1); l>=0; l--){
						r[j]=f[i][l];
						j++;
					}
				}
			}
			
		}
	}
	
	
	return r;
}
int main ()
{
	
	std::string recenica;
	std::vector<std::string> fraze;
	
	std::cout<<"Unesite recenicu: ";
	getline(std::cin,recenica);
	
	std::cout<<"Unesite fraze: ";
	for(;;){
		
		std::string s;
		getline(std::cin,s);
		
		if(s.size()==0) break;
		
		fraze.push_back(s);

		
	}
	
	std::string nova1,nova2;
	try{
	nova1=IzmijeniUPigLatin(recenica,fraze);
	
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	
	std::cout<<nova1;
	std::cout<<std::endl;
	}
	
	
	catch(std::domain_error e){
		std::cout<<e.what();
		std::cout<<std::endl;
	}
	
	std::cout<<"Recenica nakon obrtanja fraza: ";
	nova2=ObrniFraze(recenica,fraze);
	
	std::cout<<nova2;
	
	
	
	return 0;
}