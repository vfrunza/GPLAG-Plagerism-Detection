#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

std::string ObrniFraze(std::string recenica, std::vector<std::string>fraze){
	
	for(int i=0;i<fraze.size();i++){
	    for(int j=0;j<recenica.length();j++){
	        std::string rijec=fraze[i];
	       if(rijec==recenica.substr(j,rijec.size())){
	           
	           // int poc=j;
	           //int kraj=j+rijec.size();
	           
	           int kraj=j+rijec.size();
	           int l=rijec.size()-1;
	           
	           for(int k=j;k<kraj;k++){
	              recenica[k]=rijec[l--];
	           }
	           j--;
	           
	       }
	        
	        
	    }
	}
	return recenica;
}


std::string IzmijeniUPigLatin(std::string s,std::vector<std::string>popisrijeci){
    
   
    
            for(int i=0;i<popisrijeci.size();i++){
                for(int j=0;j<popisrijeci[i].size();j++){
                    
                   char element=popisrijeci[i][j];
                   if((element<'A' || element>'Z') || (element<'a' || element>'z')){
                       throw std::domain_error("Nekorektan izbor rijeci");
                   }
                    
                    
                    
                }
            }
    
    
    
    
    
    
    
    
    return s;
}



int main ()
{

   
    std::string recenica;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    
    std::vector<std::string> brojfraza;
    std::cout<<"Unesite fraze: ";
    
     for(;;){
        
        std::string s1;
        std::getline(std::cin,s1);
        brojfraza.push_back(s1);
       
        if(std::cin.peek()=='\n'){
            break;
        }
        
    }
    
    
    try{
        std::string s2=IzmijeniUPigLatin(recenica,brojfraza);
        std::cout<<s2;
    }
    
    catch(std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    
    
    
    
    std::cout<<"Recenica nakon obrtanja fraza: ";
    std::string s1=ObrniFraze(recenica,brojfraza);
    std::cout<<s1;
   
  
 
	return 0;
}