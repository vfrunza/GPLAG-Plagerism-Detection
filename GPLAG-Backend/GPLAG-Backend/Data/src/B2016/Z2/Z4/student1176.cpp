#include<iostream> 
#include<vector>
#include<string>
int PotencijalniKrivci(char **&p, std::vector<std::string> vs){ 
	int br(0);
	try{ 
			p=new char*[vs.size()]; 
	        for(int i(0); i<vs.size(); i++){
	        	p[i]=new int[vs[i].size()];  
	        	br++;
	        } 
	        return br;
	}
	catch(...){
		std::cout << "Izuzetak: Neodovoljno memorije" << std::endl;
	}
}  
int OdbaciOptuzbu(char **&p, int n, std::string s){ 
	int br(0), br2(0);
	for(int i(0); i<n; i++){
		if(p[i]==s){
			delete[] p[i];
			p[i]=nullptr; 
			br++;
		}
	} 
	if(br==0) throw std::domain_error("Osoba sa imenom <" << s << "> nije bila optuzena");
	if(br>10){ 
		char *pok_na_niz[n];  
		for(int i(0); i<n; i++){
			if(p[i]!=nullptr){
				pok_na_niz[br2]=p[i];
				br2++;
			}
		}
	} 
	return br2;
} 
int DodajOptuzbu(char **&p, int n, std::string s){
	char *pok_na_niz[s.size()+1]; 
	for(int i(0); i<s.size(); i++){
		pok_na_niz[i]=s[i];
	} 
	pok_na_niz[s.size()]='\0'; 
	for(int i(0); i<n; i++){
		if(p[i]==nullptr){
			p[i]=pok_na_niz;
		}
	}
}
