#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
	for (auto e : fraze) {
        int limit (recenica.size() -e.length());
        for (int i = 0; i <= limit; i++) {
            std::string rijec(recenica.substr(i, e.length()));
            
            
            if (rijec == e){
                for (int j = 0; j < rijec.length()/2; j++) {
                    char tempy = rijec[j];
                    rijec[j] = rijec[rijec.length()-j-1];
                    rijec[rijec.length()-j-1] = tempy;
                }
                recenica = recenica.substr(0, i) + rijec + recenica.substr(i+e.length(), recenica.size());
            }
        }
    }
	
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> rijeci){
	//Ako rijeci prazan, mijenjaj sve
	if (rijeci.size()==0) {
	    
	    bool jeRijec=false;
	    int pocetak;
        for (int i = 0; i <= recenica.size(); i++) {
            
            if (!jeRijec && (recenica[i] != ' ' && recenica[i] != '\n' && recenica[i] != '\t')){
                pocetak = i;
                jeRijec=true;
            }
            else if(jeRijec && (recenica[i] == ' ' || recenica[i] == '\n' || recenica[i] == '\t'||recenica[i] == ',' ||recenica[i] == '.' ||recenica[i] == '!' ||recenica[i] == '?' || i == recenica.size())){
                
                
                std::string rijec(recenica.substr(pocetak, i-pocetak));
                
                char tempy = rijec[0];
                rijec=rijec.substr(1, rijec.length()-1);
                rijec = rijec + tempy +"ay";
                
                recenica = recenica.substr(0, pocetak) + rijec + recenica.substr(i, recenica.size());
             
                
                i+=2;
                jeRijec = false;
            }
        }
	}
	else{
    	for (auto e : rijeci) {
            int limit (recenica.size() - e.length());
            for (int i = 0; i <= limit; i++) {
                std::string rijec(recenica.substr(i, e.length()));
                if (rijec == e && ( recenica[i+e.length()] == ' ' || (i == limit) || recenica[i+e.length()] == '\n' ||recenica[i+e.length()] == '\t' ||recenica[i+e.length()] == ',' ||recenica[i+e.length()] == '.' ||recenica[i+e.length()] == '!' ||recenica[i+e.length()] == '?') && (((i == 0)  || recenica[i-1] == ' '  || recenica[i-1] == '\n' ||recenica[i-1] == '\t'))){
                    char tempy = rijec[0];
                    rijec=rijec.substr(1, rijec.length()-1);
                    rijec = rijec + tempy +"ay";
                    
                    recenica = recenica.substr(0, i) + rijec + recenica.substr(i+e.length(), recenica.size());
                }
            }
        }
	}
	

	
	return recenica;
}
int main ()
{
   
	std::string recenica, temp;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);


	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	while (std::getline(std::cin, temp), temp.size()!=0) {
		fraze.push_back(temp);
	}

    try{
        for (auto i : fraze) {
            for (int j = 0; j < i.length(); j++) {
                if (!((i[j]>= 'A' && i[j]<='Z')||(i[j]>= 'a' && i[j]<='z'))) {
                    throw std::domain_error("Nekorektan izbor rijeci");
                }
            }
        }
        std::cout << "Recenica nakon PigLatin transformacije: ";
	    std::cout << IzmijeniUPigLatin(recenica, fraze)<<std::endl;
    }
    catch(std::domain_error e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }

	
	
	
	
	std::cout << "Recenica nakon obrtanja fraza: ";
	std::cout << ObrniFraze(recenica, fraze);

	return 0;
}

//Pojacani uslovi sa znakovima interpunkcije, poslati sutra ako ne bude radilo