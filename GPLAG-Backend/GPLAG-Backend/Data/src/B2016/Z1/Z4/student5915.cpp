#include <iostream>
#include <vector>
#include <string>


  std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
    for(unsigned int i = 0; i < fraze.size(); i++){
         for(unsigned int j = 0; j < recenica.length(); j++){a
            int duzina(0);
           if(fraze[i][duzina] == recenica[j])
               while(fraze[i][duzina] == recenica[j]){
           duzina++;
           j++;
               }
           if(duzina == fraze[i].length())
               for(int l = 0; l < duzina; l++){
                 recenica[j - duzina] = fraze[i][l];
                 duzina++;
               }
           
           
           
         }
         
         
       }
  
            
    }





















int main ()
{
	return 0;
}