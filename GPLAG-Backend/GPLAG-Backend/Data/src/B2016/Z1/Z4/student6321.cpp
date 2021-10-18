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




std::string ObrniFraze(std::string recenica,std::vector<std::string> fraza){
	
	
		
	
	for(int i=0;i<fraza.size();i++){
		
		
		if(recenica.length()<fraza[i].length()) continue;
		
		for(int j=0;j<=(recenica.length()-fraza[i].length());j++){
			
		
			
			if(recenica.substr(j,fraza[i].length())==fraza[i]){
			//	std::cout<<j<<std::endl;
				
		
				
				std::string pomocna;
				
				for(int z=fraza[i].length()-1;z>=0;z--){
				
					pomocna.push_back(fraza[i][z]);
					
					
					
				}
				
			
			
				int p(0);
				for(int z=j;z<j+fraza[i].length();z++){
					recenica[z]=pomocna[p];
					p++;
					
				}
				
				

				
				
			}
		
		}
		
	
	}
	return recenica;


}

std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> rijeci){
	
	bool p(false);
	int k(1);
	if(rijeci.size()==0){
		
		for(int j=0;j<recenica.length();){
			
			
			if((recenica[j]>='A' && recenica[j]<='Z')|| (recenica[j]>='a' && recenica[j]<='z')){
		//	if(recenica[j]!=' ' && recenica[j]!='\n' && recenica[j]!='\t' && recenica[j]!='.' && recenica[j]!=',' && recenica[j]!='!' && recenica[j]!='?'){
			if(rijeci.size()==0){
					rijeci.resize(1);
			
			}
			
			if(p){
				k++;
				rijeci.resize(k);
				p=false;
			}
			
				rijeci[k-1].push_back(recenica[j]);
				j++;
				
			}else{
				if(rijeci.size()==0) {
					j++;
					continue;
				}
				
				p=true;
				j++;
				
				
			}
			
		

		}
		
	}
	
	for(int i=0;i<rijeci.size();i++){
		for(int j=0;j<rijeci[i].size();j++){
			if(rijeci[i][j]<'A' || (rijeci[i][j]>'Z' && rijeci[i][j]<'a') || rijeci[i][j]>'z'){
				
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		
			
		}

	}
	
	
	
	
	
	for(int i=0;i<rijeci.size();i++){
		
		if(recenica.length()<rijeci[i].length()) continue;
		
		
		
		for(int j=0;j<=(recenica.length()-rijeci[i].length());j++){
			
			if(recenica.substr(j,rijeci[i].length())==rijeci[i])
			{
			if(j==0 &&
			
			(recenica[rijeci[i].length()]==' ' || recenica[rijeci[i].length()]=='.' || recenica[rijeci[i].length()]==',' || recenica[rijeci[i].length()]=='\t' 
			|| recenica[rijeci[i].length()]=='!' || recenica[rijeci[i].length()]=='?' || recenica[rijeci[i].length()]==';' || recenica[rijeci[i].length()]==':'
			|| rijeci[i].length()==recenica.length()) ) goto pocetak;
				
				
				
				
				
			
			if(j!=0 && (recenica[j-1]==' ' || recenica[j-1]=='\t' || recenica[j-1]=='.' || recenica[j-1]==',' || recenica[j-1]=='(')   && 
			((recenica[j+rijeci[i].length()]==' ' || recenica[j+rijeci[i].length()]=='.' || recenica[j+rijeci[i].length()]==',' || recenica[j+rijeci[i].length()]=='\t' 
			|| recenica[j+rijeci[i].length()]==')' || recenica[j+rijeci[i].length()]=='!' || recenica[j+rijeci[i].length()]=='?' || recenica[j+rijeci[i].length()]==':' || recenica[j+rijeci[i].length()]==';') || 
			(j==(recenica.length()-rijeci[i].length()))) )            
			{
			
		
			pocetak:
			
				
				char pomocna(recenica[j]);
				
				for(int k=j;k<j+rijeci[i].length()-1;k++){
					recenica[k]=recenica[k+1];
					
				}
				
				recenica[j+rijeci[i].length()-1]=pomocna;
				
				std::string ay("ay");
				
				recenica.insert(recenica.begin()+(j+rijeci[i].length()),ay[0]);
				recenica.insert(recenica.begin()+(j+rijeci[i].length()+1),ay[1]);
				
			
				
				j=j+2-1;
			}
			
			
		}

		
		
		}	
	
	
	}
		
	
	return recenica;
	
	
	
}


int main ()


{
	  
	
	std::cout<<"Unesite recenicu: ";
	
	std::string recenica;
	
	std::getline(std::cin,recenica);
	
	std::vector<std::string>  fraze;
	std::string r;
	
	std::cout<<"Unesite fraze: ";
	for(;;)
	{
		std::getline(std::cin,r);
		if(r!=""){
		fraze.push_back(r);
		
			
		}else break;
		
		
	}
	


try{	
		
	
	
	
std::string	pigulatin{IzmijeniUPigLatin(recenica,fraze)};
	
	std::cout<<"Recenica nakon PigLatin transformacije: "<<pigulatin;
	
	
	}catch(std::domain_error poruka){
		
		std::cout<<"Izuzetak: "<<poruka.what();
	}
	
	
	
	  
	
  std::cout<<"\nRecenica nakon obrtanja fraza: ";
	
	std::cout<<ObrniFraze(recenica,fraze);

   
 return 0;   
 

}