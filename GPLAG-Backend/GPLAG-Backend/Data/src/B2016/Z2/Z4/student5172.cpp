#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>

int PotencijalniKrivci(char **&p, std::vector<std::string> imena){
	char **pok(nullptr);
	pok=new char *[imena.size()];
	p=pok;
	for(int i=0; i<imena.size(); i++) pok[i]=nullptr;
	try {
		for(int i=0; i<imena.size(); i++) pok[i]=new char[imena[i].size()+1];
	//p=pok1;
		for(int i=0; i<imena.size(); i++) {
			for(int j=0; j<imena[i].size(); j++) {
				pok[i][j]=imena[i][j];
			}
			pok[i][imena[i].size()+1]='\0';
		}
	} 
	catch(std::bad_alloc) {
		for(int i=0; i<imena.size(); i++) delete [] pok[i]; 
		delete [] pok; 
		throw;
	}
		return imena.size();
}
int OdbaciOptuzbu(char **&pok, int &vel, std::string s)
{
	int ima=0;
	int k=0;
//	char**pok=p;
	for(int i=0; i<vel; i++) {
		k=0;
		while( k<s.size() && *pok[i]==s[k]) {
			pok[i]++;
			k++;
		}
		if(*pok[i]=='\0') {
			ima=1; 
			pok[i]=pok[i]-k;
			*pok[i]='\0';
			pok[i]=nullptr;
			delete [] pok [i];
			pok[i]=nullptr;
		}
	}
	int br=0;
	for(int i=0; i<vel; i++) {
		if(pok[i]==nullptr) br++;
	}
	int novavel=vel;
	if(ima==0) throw std::domain_error("Osoba sa imenom  nije bila optuzena");
	if(br>10) {
		k=0; 
		try {
			char**pok1=new char*[vel-br];
			novavel=vel-br;
			for(int i=0; i<vel; i++) {
				if(pok[i]!=nullptr) {
					pok1[k]=pok[i];
					k++;
					
				}
			}
			for(int i=0; i<vel;i++)pok[i]=nullptr; 
			delete [] pok;
			pok=nullptr; 
			pok=pok1;
		} 
		catch (std::bad_alloc) {throw;}
	}
	return novavel;
}
int DodajOptuzbu(char **& pok, int &vel, std::string s){
	int zadnja1=0; 
	char *p(nullptr); 
	char **pok1(nullptr);
	int novavel1=vel;
	try{
		p=new char[s.length()+1]; 
		for(int i=0; i<s.length(); i++){
			p[i]=s[i];
		}
		p[s.length()+1]='\0'; 
		int b=0; 
		for(int i=0; i<vel; i++){
			if(pok[i]==nullptr){pok[i]=p; b=1; break; } 
		}
		if(b==0){
			
			try{
				
				pok1=new char *[vel+1]; 
				for(int i=0; i<vel; i++){
					pok1[i]=pok[i]; 
					pok[i]=nullptr; 
					delete [] pok[i]; 
				}
				pok1[vel+1]=p; 
				
				novavel1=novavel1+1; 
				pok=pok1;
				
			}
			catch (std::bad_alloc){
				delete [] p;
				throw; 
			}
		}
	}
		catch (std::bad_alloc){
		throw; 
	}

	return novavel1+1; 
}
void IzlistajOptuzbu(char **pok, int vel){
	for(int i=0; i<vel; i++){
		if(pok[i]!=nullptr){
		int j=0; 
			while (pok[i][j]!='\0'){
			 std::cout<<pok[i][j]; 
			 j++; 
			}
			std::cout<<std::endl; 
		}
	}
}
int main(){
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?";
	int n; 
	std::cin>>n; 
	char**pok; 
	std::cin.ignore(1000, '\n'); 
	std::vector<std::string> imena; 
	std::cout<<"Unesite potencijalne krivce: "; 
	for(int i=0; i<n; i++){
		std::string s; 
		std::getline(std::cin, s); 
		imena.push_back(s); 
	}
	try{
		int brojkrivaca=PotencijalniKrivci(pok, imena); 
	for(;;){
		std::cout<<"Odaberite opciju: 1 za novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenog, 0 za kraj: \n"; 
		int broj; 
		std::cin>>broj; 
		int br=0; 
		if(broj==1){
			std::cout<<"Unesite ime novog optuzenog: \n"; 
			std::cin.ignore(1000, '\n'); 
			std::string ime; 
			std::getline(std::cin, ime); 
			try{
				 brojkrivaca=DodajOptuzbu(pok, brojkrivaca,  ime); 
			}
			catch(std::bad_alloc){
				throw; 
			}
		}
		else if(broj==2){
				std::cout<<"Unesite ime koje zelite izbaciti: \n"; 
				std::cin.ignore(1000, '\n'); 
			std::string ime; 
			std::getline (std::cin, ime); 
			try{
				 brojkrivaca=OdbaciOptuzbu(pok, brojkrivaca, ime); 
			}
			catch(std::bad_alloc){
				throw; 
			}
			catch(std::domain_error iz){
				std::cout<<iz.what(); 
			}
		}
		else if (broj==3){
			try{
				IzlistajOptuzbu(pok, brojkrivaca); 
			}
			catch(std::bad_alloc){
				throw; 
			}
		}
		else if(broj==0) break; 
		
	}
}
	catch(std::bad_alloc){
		std::cout<<"Nema dovoljno memorije!"; 
	}
	return 0; 
}
