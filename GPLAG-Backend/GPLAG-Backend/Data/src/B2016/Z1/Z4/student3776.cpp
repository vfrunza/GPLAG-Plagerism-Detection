#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>




bool DalIma(std::string recenica,std::string rijec){
    if(rijec.length()>recenica.length())
    return false;
    for(int i=0;i<recenica.length();i++){
        int j=0;
        if(recenica[i]==rijec[j]){
            while(recenica[i]==rijec[j] and j<rijec.length()){
                j++;
                i++;
            }
            if(j==rijec.length())
            return true;
        }
    }
    return false;
}

void  IzdvojiPoc (std::string recenica,std::string rijec,int &poc,int &kr){
  if(rijec.length()>recenica.length())  std::cout<<"greska";
    for(int i=0;i<recenica.length();i++){
        int j=0;
        if(recenica[i]==rijec[j]){
            while(recenica[i]==rijec[j] and j<rijec.length()){
                j++;
                i++;
            }
            if(j==rijec.length())
     kr=i-1;   poc=kr-rijec.length()+1;
        }
        
    }
     
}





void IzvrniString (std::string &recenica,std::string rijec){
    int pocetak,kraj;
    IzdvojiPoc(recenica,rijec,pocetak,kraj);
   for(int j=kraj,k=pocetak;j>=pocetak,k<j;j--,k++)
      std::swap(recenica[j],recenica[k]);

}

std::string ObrniFraze(std::string recenica,std::vector<std::string>rijeci){
  
    std::string Obrnuta=recenica;
        for(int j=0;j<rijeci.size();j++){
            if(DalIma(Obrnuta,rijeci[j])) 
          IzvrniString(Obrnuta,rijeci[j]);
        }
        return Obrnuta;
}

void Kmee (std::string &recenica, std::string rijec){
    int pocetak,kraj;
    std::string krm{"ay"};
    IzdvojiPoc(recenica,rijec,pocetak,kraj);
    std::string prvi;
    prvi.push_back(recenica[pocetak]);
    for(int i=pocetak;i<=kraj;i++){
        recenica[i]=recenica[i+1];
    }
    recenica[kraj]=prvi[0];
    for(int q=kraj+1,i=0;q<=kraj+2,i<=1;q++,i++){
    recenica.insert(recenica.begin() + q, krm[i]);
    }
    }


std::string IzmijeniUPigLatin (std::string recenica,std::vector<std::string>rijeci){
std::string b;
for (const auto &piece : rijeci) b += piece;
for(int j=0;j<b.size();j++){
    if((b[j]>='A' and b[j]<='Z') or( b[j]>='a' and b[j]<='z'))  {continue;}  
   else {throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");}
}
 
    std::string Obrnuta=recenica;
        for(int j=0;j<rijeci.size();j++){
            if(DalIma(Obrnuta,rijeci[j])) 
          Kmee(Obrnuta,rijeci[j]);
        }
        return Obrnuta;

}

int main ()
{
    std::cout<<"Unesite recenicu: ";
    std::string recenica1;
    std::getline(std::cin,recenica1);
     std::string recenica2;
    recenica2=recenica1;
    std::vector<std::string>rijeci(4);
    std::cout<<"Unesite fraze: ";
     std::string Kmeee;
      std::string Obrnuta;
   
    try{
         
        for(int i=0;i<rijeci.size();i++){
        std::getline(std::cin,rijeci[i]);
    }
    Kmeee=IzmijeniUPigLatin(recenica2,rijeci);
    
    std::cout<<"Recenica nakon PigLatin transformacije: ";
     std::cout<<Kmeee<<std::endl;
     
    }
    catch(std::domain_error izuzetak){
         std::cout<<izuzetak.what()<<std::endl;
        
    }
    Obrnuta=ObrniFraze(recenica1,rijeci);
     std::cout<<"Recenica nakon obrtanja fraza: ";
      std::cout<<Obrnuta<<std::endl;
      
   
	return 0;
}