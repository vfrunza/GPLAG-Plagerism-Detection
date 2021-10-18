/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>


std::string ObrniFraze(std::string s, std::vector<std::string>rijeci){
	for(int i=0; i<int(rijeci.size()); i++){
	   for( int j=0; j<int(s.length());j++){
	   	if(j<int(s.length()) && (s[j]==' ' || s[j]=='\n' || s[j]=='\t')) continue;
	   	int k=j; // k zadrzava pocetak rijeci
	   	while(j<int(s.length()) && s[j]!=' ' && s[j]!='\n' && s[j]!='\t') j++; // j je jedno mjesto iza rijeci
	    if(rijeci[i]==s.substr(k,j-k)){
	    	for(int m=0; m<(j-k)/2; m++){
	    		char temp=s[k+m];
	    		s[k+m]=s[j-1-m];
	    		s[j-1-m]=temp;
	    	}
	    }
	    j--;
	   }
}
return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>rijeci){
	//provjera da li su u stringu samo slova engl alfabeta
	for(int j=0;j<int(s.length())-1;j++){
		if(s.at(j)<'A' || s.at(j)<'z' || (s.at(j)>'Z' && s.at(j)<'a')) throw std::domain_error ("Nekorektan izbor riječi"); 
	}
	
	//ukoliko nema fraza okrece svaku rijec
	if(rijeci.size()==0){
	   for( int j=0; j<int(s.length());j++){
	   	if(j<int(s.length()) && (s[j]==' ' || s[j]=='\n' || s[j]=='\t')) continue;
	   	int k=j; // k zadrzava pocetak rijeci
	   	while(j<int(s.length()) && s[j]!=' ' && s[j]!='\n' && s[j]!='\t') j++; // j je jedno mjesto iza rijeci
	    	char temp(s.at(k));
	    	//pomjeras rijec mjesto unaprijed
	    	for(int m=k;m<j-1;m++){
	    		s.at(m)=s.at(m+1);
	    	}	
	    	s.at(j-1)=temp;
	    	s.insert(s.begin()+(j), 'a');
	    	s.insert(s.begin()+(j+1), 'y');
	    
	    	j++;
	    }
	    
	   
	   return s;
	   	
	  }
	//slucaj kad vektor fraza nije prazan
	for(int i=0; i<int(rijeci.size()); i++){
	   for( int j=0; j<int(s.length());j++){
	   		if(j<int(s.length()) && (s[j]==' ' || s[j]=='\n' || s[j]=='\t')) continue;
	   		int k=j; // k zadrzava pocetak rijeci
	   		while(j<int(s.length()) && s[j]!=' ' && s[j]!='\n' && s[j]!='\t') j++; // j je jedno mjesto iza rijeci
		 	if(rijeci[i]==s.substr(k,j-k)){
	    		char temp(s.at(k));
	    		//pomjeras rijec mjesto unaprijed
	    		for(int m=k;m<j-1;m++){
	    			s.at(m)=s.at(m+1);
	    		}	
	    		s.at(j-1)=temp;
	    		s.insert(s.begin()+(j), 'a');
	    		s.insert(s.begin()+(j+1), 'y');
	    
	    		j++;
	        }
	    
	   }
		
	}
	   return s;
	   
	   
}

int main(){
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string>fraze;
	std::string rijec;
	std::getline(std::cin,rijec);
	while(rijec.length()!=0){
		fraze.push_back(rijec);
		std::getline(std::cin, rijec);
	}
	try{
		auto piglatin=IzmijeniUPigLatin(s,fraze);
		std::cout<<"Recenica nakon PigLatin transformacije: "<<piglatin<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	auto izvrnuta=ObrniFraze(s,fraze);
	std::cout<<"Recenica nakon obrtanja fraza: "<<izvrnuta<<std::endl;
	
	return 0;
}