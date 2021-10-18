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

bool jelslovo(char s){
	if((s>='A' && s<='Z') || (s>='a' && s<='z')) 
	return true;
	return false;
}

bool jelsubstring(std::string rijec, std::string str){
//	if(rijec.size()>str.size()) return false;
	
	for(int i=0;i<str.size();i++){
		int j(0);
		if(rijec[i]==str[j]){
			while(rijec[i]==str[j] && j<rijec.size()){
				j++;
				i++;
			}
			if(j==rijec.size()) 
			return true;
		}
	}
	return false;
} 

void ObrniFraze(std::string &s, std::vector<std::string> rijeci){
	
	for(int i=0;i<rijeci.size();i++){
		for(int j=0;j<rijeci[i].size();j++){
		if(rijeci[i][j]==' ') break;
		if(jelslovo(rijeci[i][j])==false)
			throw std::domain_error("Nekorektan izbor rijeci");
     	}
	} 
	
    for(int i=0;i<rijeci.size();i++){
    	for(int j=0;j<s.length();j++){
    		
   		std::string pomocni;
		while(jelslovo(s[j])){
			pomocni.push_back(s[j]);
			j++;
		}
		
	/*		bool jel=false;
		std::string pom=rijeci[i];
		for(int w=0;w<pomocni.size();w++){
		int q(0);
		if(pom[w]==pomocni[q]){
			while(pom[w]==pomocni[q] && q<pom.size()){
				q++;
				w++;
			}
			if(q>1)
			jel=true;
		} 
		} */
    		if(jelsubstring(rijeci[i],pomocni)){
        	int br=0;
              for(int k=j-(rijeci[i].size());k<j-(rijeci[i].size()/2);k++){
              
              	char temp=s[k];
              	s[k]=s[j-br-1];
              	s[j-br-1]=temp;
              	br++;
              }
    		}
    	}
    }
}


void IzmijeniUPigLatin(std::string &s,std::vector<std::string> rijeci){
	
	for(int i=0;i<rijeci.size();i++){
		for(int j=0;j<rijeci[i].size();j++){
		if(jelslovo(rijeci[i][j])==false){
			throw std::domain_error("Nekorektan izbor rijeci"); 
		}
    	}
	}

     for(int i=0;i<rijeci.size();i++){
    	for(int j=0;j<s.length();j++){
    	std::string pomocni;
		while(jelslovo(s[j])){
			pomocni.push_back(s[j]);
			j++;
		}
    	if(rijeci[i]==pomocni){
    		
    		s.resize(s.size()+2);
    		for(int m=s.size()-2;m>=j;m--){
    			s[m+2]=s[m];
    		}
    		int temp=s[j-rijeci[i].size()];
    		
    		for(int k=j+1-rijeci[i].size();k<j;k++){
    			s[k-1]=s[k];
    		}
    		s[j-1]=temp;
    		s[j]='a';
    		s[j+1]='y';
    	}
    	}
     }
}

int main ()
{
		std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
    std::string temp(s);
	
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";
	std::string rijec;
	
	char jedan=std::cin.get();
	while(jedan!='\n'){
		std::getline(std::cin, rijec);
		rijec=jedan+rijec;
	   fraze.push_back(rijec);
	   jedan=std::cin.get();
	}
	
	try{
   try{
  
	IzmijeniUPigLatin(s,fraze);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<s;
   	
   }catch(std::domain_error izuzetak){
   	std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
   }

	ObrniFraze(temp,fraze);
	std::cout<<"\nRecenica nakon obrtanja fraza: ";
	std::cout<<temp<<std::endl;

  } 
   catch(std::domain_error izuzetak){
   	std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
   } 
	
	return 0;
}