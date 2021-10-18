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

	void IzvrniString(std::string &s){
		for(int i=0; i<s.length()/2; i++){
			char slovo = s[i];
			s[i] = s[s.length()-1-i];
			s[s.length()-1-i] = slovo;
		}
	}
  	
  std::string ObrniFraze(std::string s1, std::vector<std::string>s2){
  		std::vector<std::string>obrnut;
  		obrnut = s2;
  		
  		for(int i=0; i<obrnut.size(); i++)
  			IzvrniString(obrnut[i]);
  			
  		for(int i=0; i<s2.size(); i++){
  			for(int j=0; j<s1.length(); j++){
  				if(s2[i] == s1.substr(j,s2[i].size())){
  					int z(j);
  					for(int k=0; k<s2[i].size(); k++){
  						s1[z] =  obrnut[i][k];
  						z++;
  						}
  					}
  				}
  			}
  			return s1;
  		}
  		
  		
  		
  		void kodiraj(std::string &s){
  				s += s[0];
  				s.erase(s.begin());
  		}
  		
  		bool jesteslovo(char s){
  			bool jeste(true);
  			if((s>='a' && s<='z') || (s>='A' && s<='Z'))
  				jeste = false;
  			return jeste;
  		}
  		
  		std::string IzmijeniUPigLatin(std::string s1, std::vector<std::string>s2){
  			for(int i=0; i<s2.size(); i++){
  				for(int j=0; j<s2[i].size(); j++){
  					if(jesteslovo(s2[i][j]))
  					throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
  				}
  			}
  	
  			if(s2.size()==0){
  			std::vector<std::string> novi;
  			int pomocna(0);
  			for(int i=0; i<s1.length(); i++){
  				int brojac(0);
  				while(!jesteslovo(s1[i])){
  					brojac++;
  					i++;
  				}
  				novi.push_back(s1.substr(pomocna,brojac));
  				pomocna += brojac+1;
  			}
  			s2 = novi;
  		}
  			
  			std::vector<std::string>kodiran;
  			kodiran = s2;
  	
  			for(int i=0; i<kodiran.size(); i++)
  				kodiraj(kodiran[i]);
  				s1 += " ";
  				s1.insert(s1.begin(), ' ');
  				
			for(int i=0; i<s2.size(); i++){
				std::string pomocni;
				for(int j=0; j<s1.length(); j++){
  					if(((s2[i]==s1.substr(j,s2[i].size()) && jesteslovo(s1[j+s2[i].size()])) && (s2[i]==s1.substr(j,s2[i].size()) && s1[j-1] == ' ')) && (s2[i]==s1.substr(j,s2[i].size()))){
  						pomocni = s1.substr(j,s2[i].size());
	  					int z(j);
	  					for(int k=0; k<kodiran[i].size(); k++){
	  						s1[z] =  kodiran[i][k];
  							z++;
  						}
  					
  						int k = j + pomocni.length();
  						s1.insert(k+s1.begin(), 'a');
  						s1.insert(k+s1.begin()+1, 'y' );
  					}
  				}
  			}
  			s1.resize(s1.length()-1);
  			s1.erase(s1.begin());
  			return s1;
  		}
  		
  
  	

int main (){
	std::string recenica;
	std::cout<< "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string>fraze;
	std::cout<< "Unesite fraze: ";
	for(;;){
		if(std::cin.peek() == '\n') break;
		std::string fraza;
		std::getline(std::cin, fraza);
		fraze.push_back(fraza);
	}
	auto m = ObrniFraze(recenica,fraze);
	try{
	auto k = IzmijeniUPigLatin(recenica,fraze);
	std::cout<< "Recenica nakon PigLatin transformacije: ";
		std::cout<<k;
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	std::cout<<std::endl;
	std::cout<< "Recenica nakon obrtanja fraza: ";
	std::cout<<m;
	
 
	return 0;
}


