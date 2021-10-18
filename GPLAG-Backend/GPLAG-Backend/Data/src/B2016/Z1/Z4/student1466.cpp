#include <iostream>
#include <string>
#include <vector>

std::string okreni(std::string rijec) {
   
std::string rijec_nova(rijec.length(),'*');
    int z=0; 
for (int b=rijec.length()-1; b>=0; b--) {
    rijec_nova[z]=rijec[b];
    z++; 

 }  
   
   return rijec_nova;
}
    
std::string pigi(std::string rijec) {
     std::string rijec_nova(rijec.length(),'*');
   
int g=0;
        for (int b=1; b<rijec.length(); b++) {
            rijec_nova[g]=rijec[b];
                g++;
 } 
 
 rijec_nova[g]=rijec[0];
    
  rijec_nova+="a";
  rijec_nova+="y";

    return rijec_nova;
}    


std::string ObrniFraze(std::string s, std::vector<std::string> a) {
 std::string rijec;
 
for (int i=0; i<s.length()-1; i++) 
    
for (int j=1; j<s.length(); j++) {
   
for (int k=0; k<a.size(); k++) {
                
                 if (a[k]==s.substr(i,j))   {
                    rijec=okreni(s.substr(i,j));
                    s.replace(i,j,rijec);
                  
                    }

                }

            }
  
    return s; 
    
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> a) {
 std::string rijec;


for (int i=0; i<s.length()-1; i++) 
    
for (int j=1; j<s.length(); j++) {
   
for (int k=0; k<a.size(); k++) {
                
                 if (a[k]==s.substr(i,j))   {
                    rijec=pigi(s.substr(i,j));
                    s.replace(i,j,rijec);
                  
                    }

                }

            }
  
    return s; 
    
}



int main ()
{

std::string recenica;
std::cout<<"Unesite recenicu: ";

std::getline(std::cin, recenica);

std::vector<std::string> fraze; 
std::cout<<"Unesite fraze: ";
std::string fraza;

while (getline(std::cin, fraza) && fraza.length() > 0)
    {
        if (fraza == "\n")
        {
            break;
        }
        fraze.push_back(fraza);
    }

std::cout<<"Recenica nakon PigLatin transformacije: ";
std::string am=IzmijeniUPigLatin(recenica,fraze);
       for (int i = 0; i<am.length(); i++) 
            std::cout<<am[i];


std::cout<<"\nRecenica nakon obrtanja fraza: ";
std::string rij=ObrniFraze(recenica,fraze);
        for (int i = 0; i<rij.length(); i++) 
            std::cout<<rij[i];

	return 0;
}