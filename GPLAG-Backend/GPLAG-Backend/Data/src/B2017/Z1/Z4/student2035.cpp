#include <iostream>
#include <string>
#include <vector>



std::string IzvrniString(std::string s) {
      std::string novi; 
      for(int i=s.size()-1; i>=0; i--) 
            novi.push_back(s.at(i));
      
      return novi;
}

bool JelSlovo(char znak) {
      if(znak>='A' && znak<='Z' || znak>='a' && znak<='z') return true;
      return false;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> lista) {
      std::string rezultat(recenica); 
      if(lista.size()==0) return recenica; 
      if(recenica.size()==0) return recenica;
      int j(0); 
   //   std::cout << "bio sam u fiji"; 
      for(int i=0; i<lista.size(); i++) {
            j=0;
            if(lista.at(i).size()>rezultat.size()) continue;
            while(j<=rezultat.size()-lista.at(i).size()) { // NOTE TO SELF JA MISLIM DA OVDJE MNOZES STROGU NEJEDNAKOST JER VO J POCINJE OD NULE ALI NISAM SIGURNA
                  std::string pomocni;
                  
                  pomocni=rezultat.substr(j, lista.at(i).size());
               //   std::cout << "pomocni je " << pomocni << std::endl; 
                  if(pomocni==lista.at(i)) {
                        if(j>0) {
                              
                              if(JelSlovo(rezultat.at(j-1))) {
                                  /*  std::cout << "ukinuti cu ti ovu pomocnu " << pomocni  << std::endl;*/ j++; continue;}
                        }
                        if(j<rezultat.size()-lista.at(i).size()) { //za ovaj uslov nisam sigurna
                        
                            if(JelSlovo(rezultat.at(j+lista.at(i).size()))) { //ovaj uslov vidi malo
                                  /*std::cout << "Ukinuti cu ti ovu pomocnu " << pomocni << std::endl ;*/ j++; continue;}
                        }
              // std::cout << "nasao sam neki da je isti" << std::endl;
               rezultat=rezultat.substr(0, j) + pomocni + IzvrniString(pomocni) + rezultat.substr(j+pomocni.size(), rezultat.size()-j); 
                  //DOPUNI JE INACE IDI DALJE
                  }
                  j++; 
            }
            
      }
      
      
      return rezultat;
}


std::string ModificirajString(std::string fraza) { //provjeri u obe ove petlje granice, tj procitaj lepo zadatak pa onda zakljuci kako da postupis
      std::string rezultat; 
      for(int i=0; i<fraza.size()/2; i++)
      rezultat.push_back(fraza.at(i)); 
      for(int i=(fraza.size()-1)/2; i>=0; i--)
      rezultat.push_back(fraza.at(i)); 
      return rezultat; //ovdje provjeri dimenziju ovu da li je ok
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> lista) {
      std::string rezultat(recenica); 
      if(recenica.size()==0) return recenica; 
      if(lista.size()==0) return recenica; 
      int j(0); 
      for(int i=0; i<lista.size(); i++) {
            if(lista.at(i).size()>rezultat.size()) continue; 
            j=0; 
            while(j<=rezultat.size()-lista.at(i).size()) {
                  std::string pomocni;
                  
                  pomocni=rezultat.substr(j, lista.at(i).size());
                  if(pomocni==lista.at(i)) {
                        if(j>0) {
                              if(JelSlovo(rezultat.at(j-1))) {
                                    j++; continue;
                              }
                              
                        }
                        
                        if(j<rezultat.size()-lista.at(i).size()) {
                              if(JelSlovo(rezultat.at(j+lista.at(i).size()))) {j++; continue; }
                        }
                        rezultat=rezultat.substr(0, j) + ModificirajString(pomocni) + rezultat.substr(j+pomocni.size(), rezultat.size()-j);
                  }
                  j++;
            }
            
            
            
      }
      
      return rezultat; 
}

int main ()
{
      std::cout << "Unesite recenicu: "; 
      std::string A; 
      std::getline(std::cin, A); 
     // std::cin.ignore(1000, '\n'); 
      std::cout << "Unesite fraze: "; 
      std::vector<std::string> dek;
      int kontrolna(0); 
      for(;;) {
            kontrolna++; 
            dek.resize(kontrolna); 
            std::string neka; 
            std::getline(std::cin, neka); 
            
            if(neka.size()!=0) 
            dek.at(kontrolna-1)=neka; 
            else break; 
      }
      std::cout << "Recenica nakon Palindrom transformacije: ";
      std::cout << NapraviPalindrom(A, dek); 
      std::cout << std::endl << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(A, dek);
	return 0;
}