#include <iostream>
#include <string>
#include <vector>

std::string ObrniFraze(std::string s,std::vector<std::string> v){
    std::string nova=s;
    for(int i=0;i<v.size();i++){
       int duzina(v[i].length());
       for(int j=0;j<s.length();j++){
           bool jest(true);
           std::string pomocni(v[i]);
           if(s[j]==pomocni[0]){
              int brj(0);
              for(int k=j;k<j+duzina;k++){
                  if(s[k]!=pomocni[brj]) {
                      jest=false;
                      break;
                  }
                  brj++;
              }
              if(jest=false) break;
           int kraj=j+duzina;
           int broj(0);
             for(int g=j;g<kraj/2;g++){
               int pom(s[g]);
               s[g]=s[kraj-1-broj];
               s[kraj-1-broj]=pom;
               broj++;
           }
           }
           j+=duzina;
          
       }
    }
    return nova;
    
}

int main ()
{
    std::string s,nesto,novistr;
    std::vector<std::string> fraze;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,s);
    std::cout<<"Unesite fraze: ";
    do{
        std::getline(std::cin,nesto);
        if(nesto!="") fraze.push_back(nesto);
    }
    while(nesto!="");
    novistr=ObrniFraze(s,fraze);
    if(s.length()!=0){
        for(int i=0;i<s.length();i++){
            std::cout<<novistr[i];
        }
    }








	return 0;
}