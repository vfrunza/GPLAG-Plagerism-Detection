#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string>SpisakRijeci){
    if(SpisakRijeci.size()!=0){
        //Provjera Spiska
        for(int i=0;i<SpisakRijeci.size();i++){
            for(int j=0;j<SpisakRijeci[i].size();j++){
                if(SpisakRijeci[i][j]<'A' ||(SpisakRijeci[i][j]>'Z' && SpisakRijeci[i][j]<'a') || SpisakRijeci[i][j]>'z')
                    throw std::domain_error("Nekorektan izbor rijeci");
            }
        }
        //Izmjena
        for(int i=0;i<SpisakRijeci.size();i++){
            for(int j=0;j<recenica.length();j++){
                if((j==0 && ((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z' ))) || (((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z' )) && !((recenica[j-1]>='A' && recenica[j-1]<='Z') || (recenica[j-1]>='a' && recenica[j-1]<='z' )))){
                    int k=j;
                    while(k<recenica.length() && (k-j)<SpisakRijeci[i].length() && recenica[k]==SpisakRijeci[i][k-j]){
                        k+=1;
                    }
                    if((k-j)==SpisakRijeci[i].length() && (k==recenica.length() || !((recenica[k]>='A' && recenica[k]<='Z') || (recenica[k]>='a' && recenica[k]<='z' )) )) {
                        char tmp(recenica[j]);
                        int l;
                        for(l=0;l<(k-j)-1;l++){
                            recenica[j+l]=recenica[j+l+1];
                        }
                        recenica[j+l]=tmp;
                        recenica=recenica.substr(0,j+l+1)+"ay"+recenica.substr(j+l+1,recenica.length());
                    }
                 
                }
            }
        }
        
        
        
        
        
    }
    
    else{
        for(int j=0;j<recenica.length();j++){
                if((j==0 && ((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z' ))) || (((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z' )) && !((recenica[j-1]>='A' && recenica[j-1]<='Z') || (recenica[j-1]>='a' && recenica[j-1]<='z' )))){
                    int k=j;
                    while(k<recenica.length()  && recenica[k]!=' '){
                        k+=1;
                    }
                    if(k==recenica.length() || !((recenica[k]>='A' && recenica[k]<='Z') || (recenica[k]>='a' && recenica[k]<='z' )) ) {
                        char tmp(recenica[j]);
                        int l;
                        for(l=0;l<(k-j)-1;l++){
                            recenica[j+l]=recenica[j+l+1];
                        }
                        recenica[j+l]=tmp;
                        recenica=recenica.substr(0,j+l+1)+"ay"+recenica.substr(j+l+1,recenica.length());
                    }
                 
                }
            }
    }
    return recenica;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> SpisakRijeci){
    for(int i=0;i<SpisakRijeci.size();i++){
        for(int j=0;j<recenica.length();j++){
           int k=j;
           while(k<recenica.length() && (k-j)<SpisakRijeci[i].length() && recenica[k]==SpisakRijeci[i][k-j]){
               k+=1;
           }
           if((k-j)==SpisakRijeci[i].length()){
               for(k=0;k<SpisakRijeci[i].length()/2;k++){
                   char znak(recenica[j+k]);
                   recenica[j+k]=recenica[j+SpisakRijeci[i].length()-k-1];
                   recenica[j+SpisakRijeci[i].length()-k-1]=znak;
                   
               }
           }
        }
    }
    
    return recenica;
}
int main ()
{
    
    std::cout << "Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin,recenica);
    
    std::cout << "Unesite fraze: ";
    std::vector<std::string> ListaFraza;
    std::string fraza;
 
 
   while(std::cin.peek()!='\n'){
    std::getline(std::cin,fraza);
    if(fraza.length()==0)
        break;
    ListaFraza.push_back(fraza);
    
   }
   
    
  try{
    std::string RecenicaUPigu(IzmijeniUPigLatin(recenica,ListaFraza));
    std::cout<< "Recenica nakon PigLatin transformacije: " << RecenicaUPigu << std::endl;    
    }
    catch(std::domain_error error){
        std::cout << "Izuzetak: "<< error.what()<< std::endl;
    }
  
    
    std::cout<<"Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,ListaFraza);
    
	return 0;
}

