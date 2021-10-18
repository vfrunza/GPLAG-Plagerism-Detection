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
#include<stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	for(std::string x: v){
		for(int i=0; i<s.size(); i++){
			while(s[i]==' ')
				i++;
			int j(0);
			int poc(0);
			poc=i;
			while(s[i]==x[j] && i<s.size() && j<x.size()){
				i++;
				j++;
			}
			int kraj(0);
			kraj=i;
			if(j==x.size()){
				if((kraj-poc)%2!=0){
					for(int k=0; k<=(kraj-poc)/2; k++){
						char temp(s[poc+k]);
						s[poc+k]=s[kraj-k-1];
						s[kraj-k-1]=temp;
					}
				}
				else{
					for(int k=0; k<(kraj-poc)/2; k++){
						char temp(s[poc+k]);
						s[poc+k]=s[kraj-k-1];
						s[kraj-k-1]=temp;
					}
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	for(std::string x: v){
		for(int i=0; i<x.size(); i++){
			if((x[i]>='A' && x[i]<='Z') || (x[i]>='a' && x[i]<='z')){
			}
			else{
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	if(v.size()>0){
		for(std::string x: v){
			for(int i=0; i<s.size(); i++){
				while(s[i]==' ')
					i++;
				int j(0);
				int poc(0);
				poc=i;
				while(poc>0 && s[poc-1]==' ' && s[i]==x[j] && i<s.size() && j<x.size()){
					i++;
					j++;
				}
				int kraj(0);
				kraj=i;
				char prvo_slovo;
				if(j==x.size()){
					prvo_slovo=s[poc];
					for(int k=poc; k<s.size()-1; k++){
						s[k]=s[k+1];
					}
					s.resize(s.size()-1);
					s.resize(s.size()+3);
					for(int l=s.size()-1; l>kraj; l--)
						s[l]=s[l-1];
					for(int l=s.size()-1; l>kraj; l--)
						s[l]=s[l-1];
					for(int l=s.size()-1; l>kraj; l--)
						s[l]=s[l-1];
					s[kraj-1]=prvo_slovo;
					s[kraj]='a';
					s[kraj+1]='y';
					s[kraj+2]=' ';
					
				}
			}
		}
	}
	else{
		//ako je v prazan vektor ??? ?????????????????????????????????????????????????????????????????
	}
	return s;
}

int main (){
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> v;
	std::string pomocni;
	std::cout<<"Unesite fraze: ";
	do{
		char znak;
		znak=std::cin.peek();
		if(znak=='\n')
			break;
		std::getline(std::cin, pomocni);
		v.push_back(pomocni);
	}while(1);
	try{
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s, v);
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s, v);
	return 0;
}