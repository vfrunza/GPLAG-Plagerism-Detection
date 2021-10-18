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


void ObrniFraze(std::string &recenica, std::vector<std::string>& fraze){
	
	for(int i=0;i<fraze.size();i++){
		std::string fraza=fraze[i];
		
		for(int k=0;k<recenica.size();k++){
			int br=0,j=0;
			if(recenica[k]==fraza[j]){
				
				while(recenica[k]==fraza[j] && k<recenica.size() && j<fraza.size()){
					k++; j++; br++;
				}
				if(br==fraza.size() && (recenica[k]==' ' || recenica[k]=='\0')){
					k--; br--;
					
					int x=k;
					int y=k-br;
					
					for(int g=y;g<=(x+y)/2;g++){
						char pom=recenica[k];
						recenica[k]=recenica[g];
						recenica[g]=pom;
						k--;
					}
				}
			}
		}
	}

}
void IzmjeniUPigLatin(std::string &recenica,std::vector<std::string>&fraze){
	if(fraze.size()==0){
		
		for(int i=0;i<recenica.size();i++){
		
		
			if(recenica[i]!=' '){
				int br=0;
				while(recenica[i]!=' ' && i<recenica.size()){
					 br++;i++;
				}
		     
		  
				i--;
				br--;
			
				int g=i-br;
			 char slovo=recenica[g];
				
	      		recenica.insert(recenica.begin()+(i+1),slovo);
				recenica.insert(recenica.begin()+(i+2),'y');
				recenica.insert(recenica.begin()+(i+2),'a');
				recenica.erase(recenica.begin()+g);
				i+=2;
			     
				
				
				
				}
			
			
			}
		}
		else
		{
			
			for(int i=0;i<fraze.size();i++){
				std::string fraza=fraze[i];
				
				for(int k=0;k<recenica.size();k++){
					int br=0,j=0;
					if(recenica[k]==fraza[j]){
						while(recenica[k]==fraza[j]&& k<recenica.size()&& j<fraza.size()){
							k++;
							j++;
							br++;
						}
						if(br==fraza.size() && (recenica[k]==' ' || recenica[k]=='\0')){
							k--;
							br--;
							int g=k-br;
							char slovo=recenica[g];
							
							recenica.insert(recenica.begin()+(k+1),slovo);
							recenica.insert(recenica.begin()+(k+2),'y');
							recenica.insert(recenica.begin()+(k+2),'a');
							recenica.erase(recenica.begin()+g);
						}
					}
				}
			}
		}
	}
	




int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
    std::vector<std::string>fraze;
    std::string fraza;
	std::cout<<"Unesite fraze: ";

	
	for(;;){
		std::getline(std::cin,fraza);
		fraze.push_back(fraza);
		if(fraza=="")break;

		
	}
	
	std::string recenica1=recenica;
	
	IzmjeniUPigLatin(recenica,fraze);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<recenica<<std::endl;
	
	ObrniFraze(recenica1,fraze);
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<recenica1<<" ";

	return 0;
}