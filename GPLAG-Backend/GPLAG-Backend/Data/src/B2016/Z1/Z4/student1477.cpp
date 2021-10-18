#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string>v){
	int d(s.length());
	for(int i=0; i<v.size(); i++){
		int e(v[i].length());
		for(int j=0; j<e; j++){
			for(int k=0; k<d; k++){
				if(s[k]==v[i][j]){
					char *pok;
					pok=&s[k];
					while( k!=d-1 && j!=e-1 && s[k]==v[i][j]){
						k++;
						j++;
					}
			
				    if(j==e-1 && v[i][j]==s[k]){
					    char *pok2;
						pok2=&s[k];
						while(pok2>=pok){
							*pok=v[i][j];
							j--;
							pok++;
					}
					}
			          j=0;  
			}
		if(k==d-1) break;
		}
		break;
	}
}
return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].length(); j++){
			if((v[i][j]<'a'&& v[i][j]>'Z') || v[i][j]<'A' || v[i][j]>'z') throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		}
	}
	int d(s.length());
	for(int i=0; i<v.size(); i++){
		int e(v[i].length());
		for(int j=0; j<e; j++){
			for(int k=0; k<d; k++){
				if((k==0 || s[k-1]==' ') && s[k]==v[i][j]){
					char *pok4;
					int pok;
					pok=k;
					pok4=&s[k];
					while(k!=d-1 && s[k]==v[i][j] && j!=e-1 ){
						k++;
						j++;
					}
				
					 if(j==e-1 && (k==d-1 || s[k+1]==' ')){
						s.insert(s.begin()+k+1, *pok4);
					    s.insert(s.begin()+k+2, 'a');
					    s.insert(s.begin()+k+3, 'y');
					    s.erase(s.begin() + pok);
							j=0;
					}
				}
				j=0;
				if(k==d-1) break;
			}
			break;
		}
	}
	return s;
}


int main ()
{
	
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string>v;
	std::string rijeci;
	std::string prazan;
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::getline(std::cin, rijeci);
		if(rijeci==prazan) break;
		v.push_back(rijeci);
		
	}
	try{
	std::string novi;
	novi=IzmijeniUPigLatin(s, v);
	std::cout<<"Recenica nakon PigLatin transformacije: "<< novi;
	}
		catch(std::domain_error izuzetak){
		   std::cout << izuzetak.what();

	}
	std::cout<<std::endl;
	std::string novi2;
	novi2=ObrniFraze(s, v);
	std::cout<<"Recenica nakon obrtanja fraza: "<<novi2;
	return 0;
}