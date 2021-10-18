#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string recenica, std::vector<std::string> s) {
    
    
	for(int i=0; i<s.size(); i++) {
        std::string pomocni = s[i];
        for(int j=0; j<recenica.length(); j++) {
            
            if(recenica[j]==pomocni[0]) {
            	//std::cout << "Slovo recenice: " << recenica[j] << "Slovo pomocno: " << pomocni[0] << std::endl;
                int cuvaj_j = j;
                //std::cout << "Cuvaj j: " << cuvaj_j;
                int a(0);
                
                while(recenica[a+j]==pomocni[a] && a<pomocni.length() && pomocni[a]) { a++; }
                //std::cout << "a=" << a << std::endl;
                if(a==pomocni.length()) {
                    a--;
                    
                    while(a) {
                        recenica[cuvaj_j++]=pomocni[a--];
                    }
                    recenica[cuvaj_j]=pomocni[0];
                }
            }
        }
        
	}
	return recenica;
}


std::string IzmijeniSve(std::string recenica) {
    
    for(int i=0; i<recenica.length(); i++) {
        if(i==0 || recenica[i-1]==' ') {
            std::string pomocni;
            int cuvaj_i=i;
            //std::cout << "cuvaj i=" << cuvaj_i;
            while( ((recenica[i]<=90 && recenica[i]>=65) || (recenica[i]>=97 && recenica[i]<=122)) && i<recenica.length()-1) {
                pomocni.push_back(recenica[i]);
                i++;
            }
            
            if(i==recenica.length()-1 && recenica[i]!='!' && recenica[i]!='.' && recenica[i]!=',' && recenica[i]!=' ') pomocni.push_back(recenica[i]);
            //std::cout << "pomocni: " << pomocni << std::endl; //Dan
        if(pomocni.length()>0) {
            pomocni=pomocni+pomocni[0]+"ay";
            //std::cout << "pomocni: " << pomocni << std::endl; //Danday
            
            for(int a=0; a<pomocni.length()-1; a++) pomocni[a]=pomocni[a+1];
            pomocni.resize(pomocni.length()-1);
            //std::cout << "pomocni: " << pomocni << std::endl; //anDay
            
            recenica.resize(recenica.length()+2);
            int k;
            //std::cout << "i+2=" << i+2;
            for(k=recenica.length()-1; k>cuvaj_i; k--) recenica[k]=recenica[k-2];
            //std::cout << "recenica: " << recenica << std::endl;
            
            for(int t=0; t<pomocni.length(); t++) {
                recenica[cuvaj_i++]=pomocni[t];
            } 
            //std::cout << "recenica nakon promjene: " << recenica;
        }
        }
    }
    return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> s) {
    
    for(int i=0; i<s.size(); i++) {
       for(int j=0; j<s[i].size(); j++) {
         if(!((s[i][j]<=90 && s[i][j]>=65) || (s[i][j]>=97 && s[i][j]<=122))) {
                //std::cout << int(s[i][j]) << s[i][j];
                throw std::domain_error("Nekorektan izbor rijeci");
         }
     }
    }
    
    for(int i=0; i<s.size(); i++) {
        std::string pomocni = s[i];

        for(int j=0; j<recenica.length(); j++) {
            
            if((recenica[j]==pomocni[0]) && (j==0 || recenica[j-1]==' ')) {
            	//std::cout << "Slovo recenice: " << recenica[j] << "Slovo pomocno: " << pomocni[0] << std::endl;
                int cuvaj_j = j;
                //std::cout << "Cuvaj j: " << cuvaj_j;
                int a(1);

                //if(recenica[a+j]+('a'-'A')==pomocni[a]) recenica[a+j]=pomocni[a];
                //if(recenica[a+j]-('a'-'A')==pomocni[a]) recenica[a+j]=recenica[a];
                while(recenica[a+j]==pomocni[a] && a<pomocni.length()) {
                   // std::cout << "rec[a+j]:" << recenica[a+j] << "\npomocni[a]:" << pomocni[a];
                    a++; 
                }
                //std::cout << "a=" << a << std::endl;
                
                if(a==pomocni.length() && (recenica[j+a]==' ' || j+a-1==recenica.length()-1 || recenica[j+a]==',' || recenica[j+a]=='.')) {
                    
                    std::string obrnuti=pomocni;
                    obrnuti = obrnuti + obrnuti[0] + "ay";
                    //std::cout << "sa zbrajanjem: " << obrnuti << std::endl;
                    for(int k=1; k<obrnuti.length(); k++) obrnuti[k-1]=obrnuti[k];
                    obrnuti.resize(obrnuti.length()-1);
                    //std::cout << "a sad: " << obrnuti << std::endl;
                    
                    
                    recenica.resize(recenica.length()+2);
                    for(int k=recenica.length()-1; k>cuvaj_j+2; k--) recenica[k]=recenica[k-2];
                    //std::cout << "Recenica: " << recenica << std::endl;
                    for(int k=0; k<obrnuti.length(); k++) {
                        recenica[cuvaj_j++]=obrnuti[k];
                    }
                    
                }
            }
        }
	}
	
	if(s.size()==0) {
	    recenica=IzmijeniSve(recenica);
	    
	}
    return recenica;
}

int main () {

	std::string rec;
	std::cout << "Unesite recenicu: ";
	getline(std::cin, rec);
	std::vector<std::string> spisak;
	std::cout << "Unesite fraze: ";
	
  std::string line;
  do {
    getline(std::cin, line);
    spisak.push_back(line);
  } 
  while (!line.empty());
  
    spisak.resize(spisak.size()-1);
	
	try{
	    std::string novi(IzmijeniUPigLatin(rec, spisak));
	    std::cout << "Recenica nakon PigLatin transformacije: " << novi << std::endl;
	} 
    catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	catch(...) {
	    std::cout << "Nekorektno";
	}
	
	try{
	    std::string test(ObrniFraze(rec, spisak));
	    std::cout << "Recenica nakon obrtanja fraza: " << test << std::endl;
    } 
    catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
    catch(...) {
		std::cout << "Ne valja" << std::endl;
	}


	return 0;
}
