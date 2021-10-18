#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<stdexcept>

std::string ObrniFraze(std::string recenica,std::vector<std::string>fraze){
		for(int i=0;i<fraze.size();i++){
		std::string tmp=fraze[i];
		int duz=fraze[i].size();
		for(int j=0;j+duz<=recenica.size();j++){
			if(recenica.substr(j,duz)==tmp){
					for(int m=tmp.length()-1;m>=0;m--){
						recenica[j]=tmp[m];
						j++;
					}
				}
			}
		}
	return recenica;
}

bool PravaRijec(std::string s){
	int suma=0;
	for(int i=0;i<s.size();i++){
		if((s[i]>='A' && s[i]<='Z') || ( s[i]>='a' && s[i]<='z'))suma++;
	}
	if(s.size()==suma) return 1;
	return 0;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> spisak){
	 if(spisak.size()!=0){
	 	for(int p=0;p<spisak.size();p++) if(!PravaRijec(spisak[p])) throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
	 	for(int j=0;j<spisak.size();j++){
	 		std::string rijec=spisak[j];
	 		int vel=spisak[j].size();
	 		for(int i=0;i<recenica.size();i++){
	 		if(recenica.substr(i,vel)==rijec){
	 			if((i==0 || (recenica[i-1]<'A' || (recenica[i-1]>'Z' && recenica[i-1]<'a') || recenica[i-1]>'z')) &&
	 			  (recenica[i+vel]<'A' || (recenica[i+vel]>'Z' && recenica[i+vel]<'a') || recenica[i+vel]>'z' )){
	 			  	char tmp1=recenica[i];
					int indeks=i;
						while(i<indeks+vel && i<recenica.size()-1){
						recenica[i]=recenica[i+1];
						i++;
						}
					if(i!=recenica.size())i--;
					if(i==recenica.size())i--;
					recenica[i]=tmp1;
					i++;
					recenica.insert(recenica.begin()+i,'a');
					i++;
					recenica.insert(recenica.begin()+i,'y');
				}
	 		}
	 		}
	 	}
	 }
	 	return recenica;
	 }

int main ()
{	
	std::string recenica;
	std::string f;
	std::vector<std::string>popis ;
	std::vector<std::string>popis1 ;
	try{
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	for(;;){
		std::getline(std::cin,f);
		if(f=="")break;
		popis.push_back(f);
	}
	if(popis.size()==0){
		for(int i=0;i<recenica.size();i++){
			std::string rijec;
			int indeks=i;
			int vel;
			vel=0;
			while((recenica[i]>='A' && recenica[i]<='Z') ||(recenica[i]>='a' && recenica[i]<='z')){i++;vel++;}
			rijec=recenica.substr(indeks,vel);
			popis1.push_back(rijec);
		}
		std::cout << "Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,popis1);
		std::cout  << std::endl;
	}
	else {std::cout << "Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,popis);}
	std::cout << std::endl;
	}
	catch(std::domain_error greska){
		std::cout << greska.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,popis);
	return 0;
}


