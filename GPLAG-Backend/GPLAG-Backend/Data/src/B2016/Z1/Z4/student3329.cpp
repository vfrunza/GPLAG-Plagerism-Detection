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

bool NijeSlovo(char c){
	if((c>='A'&&c<='Z') || (c>='a'&&c<='z')) return false;
	return true;
}
std::string ObrniFraze(std::string str, std::vector<std::string> fraze){
	std::string vrati=str;
	
	for(int k=0; k<fraze.size(); k++){
		for(int i=0; i<vrati.length(); i++){
			int brojac(0);
			for(int j=0; j<fraze[k].length(); j++){
				if(i+brojac!=vrati.length() && vrati[i+brojac]==fraze[k][j]) brojac++;
				else break;
			}
			if(brojac==fraze[k].length()){
				for(int m=0; m<brojac/2; m++){
					char temp=vrati[i+m];
					vrati[i+m]=vrati[i+brojac-1-m];
					vrati[i+brojac-1-m]=temp;
				}
				i=i+brojac-1;
			}
		}
	}
	return vrati;
}
std::string IzmijeniUPigLatin(std::string str, std::vector<std::string> popis){
	std::string vrati=str;
	bool trigger=false;
	int brojac(0);
	
	for(int i=0; i<popis.size(); i++){
		for(int j=0; j<popis[i].length(); j++){
			if(NijeSlovo(popis[i][j])) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	
	if(popis.size()){
		for(int k=0; k<popis.size(); k++){
			for(int i=0; i<vrati.length(); i++){
				if(brojac>0) trigger=false;
				brojac=0;
				if( NijeSlovo(vrati[i]) || i==0) trigger=true;
				for(int j=0; j<popis[k].length(); j++){
					if(i+brojac!=vrati.length() && trigger && vrati[i+brojac]==popis[k][j]){
						brojac++;
					}else break;
				}
				if(brojac==popis[k].length() && trigger){
					if((i+brojac==vrati.length() && NijeSlovo(vrati[i-1])) || (NijeSlovo(vrati[i+brojac]) && NijeSlovo(vrati[i-1]))){
						char temp=vrati[i];
						for(int m=0; m<brojac-1; m++)
							vrati[i+m]=vrati[i+m+1];
						vrati[i+brojac-1]=temp;
						vrati.insert(vrati.begin()+i+brojac, 'a');
						vrati.insert(vrati.begin()+i+brojac+1, 'y');
						i=i+brojac+1;
					}
				}
			}
		}
	}else{
		for(int i=0; i<vrati.length(); i++){
			if(!NijeSlovo(vrati[i])) trigger=true;
			else trigger=false;
			brojac=0;
			while(trigger && i+brojac<vrati.length()){
				if(!NijeSlovo(vrati[i+brojac])) brojac++;
				else trigger=false;
			}
			if(brojac>0){
				char temp=vrati[i];
				for(int m=0; m<brojac-1; m++)
					vrati[i+m]=vrati[i+m+1];
				vrati[i+brojac-1]=temp;
				vrati.insert(vrati.begin()+i+brojac, 'a');
				vrati.insert(vrati.begin()+i+brojac+1, 'y');
				i=i+brojac+1;
			}
		}
	}
	return vrati;
}

int main (){
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::string rij;
	std::vector<std::string> rijeci;
	do{
		std::getline(std::cin, rij);
		if(rij.length()) rijeci.push_back(rij);
	}while(rij.length()!=0);
	
	try{
	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, rijeci)<<std::endl;
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, rijeci);
	return 0;
}