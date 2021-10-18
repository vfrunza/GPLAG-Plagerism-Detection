/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/ 
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
std::string ObrniFraze(std::string Recenica, std::vector<std::string> Fraze){
	for(int i=0;i<Fraze.size();i++){
		int DuzinaFraze(Fraze[i].length());
		for(int j=0;j<(Recenica.length()-DuzinaFraze); j++){
			if(Recenica.substr(j,DuzinaFraze)==Fraze.at(i)){
				char tmp;
				for(int k=j;k<(j+(DuzinaFraze/2));k++){
					tmp=Recenica.at(j+DuzinaFraze-1-k+j);
					Recenica.at(j+DuzinaFraze-1-k+j)=Recenica.at(k);
					Recenica.at(k)=tmp;
				}
			}																	
		}
	}
	return Recenica;
}
std::string IzmijeniUPigLatin(std::string Recenica, std::vector<std::string> Rijeci){
	for(auto x:Rijeci) for(auto y: x) if(!(toupper(y)>='A' && toupper(y)<='Z')) throw std::domain_error("Nekorektan izbor rijeci");
	if(Rijeci.size()==0){
		int i(0);
		while(i<Recenica.length()){
			if(toupper(Recenica.at(i))>='A' && toupper(Recenica.at(i))<='Z'){
				int pocetak(i);
				while(i<Recenica.length()) if(toupper(Recenica.at(i))>='A' && toupper(Recenica.at(i))<='Z') i++; else break;
				int kraj(i-1);
				char prvo(Recenica[pocetak]);
				int n(0);
				while(pocetak+n+1<=kraj){
					Recenica.at(pocetak+n)=Recenica.at(pocetak+1+n);
					n++;
				}
				Recenica.at(kraj)=prvo;
				Recenica.insert(Recenica.begin()+kraj+1,'a');
				Recenica.insert(Recenica.begin()+kraj+2,'y');
				i=kraj+3;
			}else if(i<Recenica.length()) i++;
		}
	} else{
		for(int k=0;k<Rijeci.size();k++){
			int i(0);
			while(i<Recenica.length()){
				if(toupper(Recenica.at(i))>='A' && toupper(Recenica.at(i))<='Z'){
					int pocetak(i);
					while(i<Recenica.length()) if(toupper(Recenica.at(i))>='A' && toupper(Recenica.at(i))<='Z') i++; else break;
					int kraj(i-1);
					if(Recenica.substr(pocetak,(kraj+1-pocetak))==Rijeci[k]){
						char prvo(Recenica[pocetak]);
						int n(0);
						while(pocetak+n+1<=kraj){
							Recenica.at(pocetak+n)=Recenica.at(pocetak+1+n);
							n++;
						}
						Recenica.at(kraj)=prvo;
						Recenica.insert(Recenica.begin()+kraj+1,'a');
						Recenica.insert(Recenica.begin()+kraj+2,'y');
						i=kraj+3;
					}
				}else if(i<Recenica.length()) i++;
			}
		}
	}
	return Recenica;
}

int main(){
	std::cout<<"Unesite recenicu: ";
	std::string Recenica;
	std::getline(std::cin, Recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> Fraze;
	for(;;){
		std::string x;
		std::getline(std::cin,x);
		Fraze.push_back(x);
		if(std::cin.peek()=='\n') break;
	}
	try{
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(Recenica,Fraze);
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<"\nRecenica nakon obrtanja fraza: "<<ObrniFraze(Recenica,Fraze);
	return 0;
}