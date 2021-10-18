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
#include <algorithm>

bool daLiJeBroj(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void vratiRedneBrojeveZadataka(long idx){
    std::vector<int>cifre; 
    std::vector<int>brojPonavljanja(10);
    while(idx >= 1){
        int cifra = idx % 10;
        cifre.push_back(cifra);
        brojPonavljanja[cifra]++;
        idx = idx / 10;
    }
    for(unsigned int i = 0; i < cifre.size(); i++){
        for(int j = 1; j < brojPonavljanja[cifre[i]]; j++){
            bool nadjenZamjenskiZadatak = false;
            for(unsigned int k = cifre[i]; k < brojPonavljanja.size(); k++){
                if(brojPonavljanja[k] == 0){
                    nadjenZamjenskiZadatak = true;
                    brojPonavljanja[k] = 1;
                    brojPonavljanja[cifre[i]]--;
                    break;
                }
            }
            if(!nadjenZamjenskiZadatak){
                for(int k = 0; k < cifre[i]; k++){
                    if(brojPonavljanja[k] == 0){
                        brojPonavljanja[k] = 1;
                        brojPonavljanja[cifre[i]]--;
                        break;   
                    }    
                }    
            }
        }
    }
    std::cout << "Redni brojevi zadataka za zadacu: ";
    for(unsigned int i = 0; i < brojPonavljanja.size(); i++){
        if(brojPonavljanja[i] == 0)
            continue;
         std::cout << i << " ";
    }
}

int main()
{
  std::string brojIndeksa;
  std::cout << "Unesite broj indeksa: ";
  getline (std::cin, brojIndeksa);
  brojIndeksa.erase(remove_if(brojIndeksa.begin(), brojIndeksa.end(), isspace), brojIndeksa.end());
  if(!daLiJeBroj(brojIndeksa))
     std::cout << "Uneseni string nije broj indeksa!";
  else{
    try{
        vratiRedneBrojeveZadataka(stol(brojIndeksa));
    }
    catch(...){
        std::cout << "Uneseni string nije broj indeksa!";
    }
  }
}