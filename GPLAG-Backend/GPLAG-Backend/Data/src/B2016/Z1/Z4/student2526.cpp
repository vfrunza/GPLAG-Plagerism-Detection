#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

bool slovo(char c){
     if((c>='A'&&c<='Z')||(c>='a'&&c<='z')) return true;
     else return false;
}


std::string ObrniFraze(std::string final, std::vector<std::string> rijeci){

	for(int i=0;i<rijeci.size();i++){
	
		for(int j=0;j<final.length();j++){
			int m{},n{};
			bool nasao{true};
			if(rijeci[i][0]==final[j]){
				n=j;
				for(m=0;m<rijeci[i].length();m++){
					if(n!=final.length()&&rijeci[i][m]==final[n]){
						n++;
					}
					else{
						nasao=false;
						break;
					}
				}
	            
				if(nasao){
					n=j;
					// obrnimo ih
					for(int f=rijeci[i].length()-1;f>=0;f--){
						final[n]=rijeci[i][f];
						n++;
					}
					
				}
				m=0;
				n=0;
			}
		}
	}
	return final;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> rijeci){
	std::string final{s};
	if(rijeci.size()==0){
		for(int i=0;i<final.length();i++){
			while(i!=final.length()&&!slovo(final[i])) i++;
			int poc=i,kraj;
			if(i==final.length()) break;
			while(i!=final.length()&&slovo(final[i])) i++;
			kraj=i-1;
			char tmp=final[poc];
			// sada zamjena;
		    for(int z=poc;z<kraj;z++) final[z]=final[z+1];
		    final[kraj]=tmp;
		    final.insert(final.begin()+i,'a'); i++;
		    final.insert(final.begin()+i,'y'); i++;
		    
		}
		
	}
	else{
	for(int i=0;i<rijeci.size();i++){
		for(int j=0;j<rijeci[i].size();j++){
			 if(!slovo(rijeci[i][j])) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	for(int i=0;i<rijeci.size();i++){
	    
		for(int j=0;j<final.length();j++){
			int m{},n{};
			
			bool nasao{true};
		
			if(rijeci[i][0]==final[j]){
				n=j;
				for(m=0;m<rijeci[i].length();m++){
					
					if(n!=final.length()&&rijeci[i][m]==final[n]){
						n++;
					}
					else{
						nasao=false;
						break;
					}
				
	
				}
		        if(j==0&&n!=final.length()&&slovo(final[n])) nasao=false;
		        if(j!=0&&n!=final.length()&&(slovo(final[j-1])||slovo(final[n]))) nasao=false;
		        if(n==final.length()&&j!=0&&slovo(final[j-1])) nasao=false;
				if(nasao){
					n=j;
					// obrnimo ih
					for(int f=1;f<rijeci[i].length();f++){
						final[n]=rijeci[i][f];
						n++;
					}
					final[n]=rijeci[i][0];n++;
					final.insert(final.begin()+n,'a');n++;
					final.insert(final.begin()+n,'y');
					
				}
				m=0;
				n=0;
			}
		}
	}
	}
	return final;
}

int main ()
{
	
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s); 
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> rijeci;
	for(;;){
		std::string bla;
		std::getline(std::cin,bla);
		if(bla.size()==0) break;
		rijeci.push_back(bla);
	} 
	try{
    std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,rijeci)<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
    std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,rijeci);
	
	
	
	return 0;
}