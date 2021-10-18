#include <iostream>
#include <vector>

// Ostalo:
// Prazni vektori -> vratiti
// Fcija provjere ima li uopste RASTUCEG, OPADAJUCEG

// OPADAJUCI NIZOVI 
std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> niz){
    // prazan vektor
    std::vector<std::vector<double>> grbava_matrica(100);
    int br(1), rsz(0);
    for(int i=0; i<niz.size()-2; i++){
    	// upisuje sve opad
        if(niz[i] >= niz[i+1]){
            while(niz[i] >= niz[i+1]){
                if(i == niz.size()-2 ){
                    break;
                }
                grbava_matrica[br].push_back(niz[i]);
                i++;
            }
            if(i == niz.size()-2){
                grbava_matrica[br].push_back(niz[i]);
                i++;
            }
            grbava_matrica[br].push_back(niz[i]);
            br++;
            rsz++;

        }
        // ako je kraj -> kraj
        if(i == niz.size()-1){
            break;
        }
        // preskace sve opadajuce
        if(niz[i] < niz[i+1]){
            while(niz[i] < niz[i+1]){
            	if(i == niz.size()-2){
            		break;
            	}
                i++;
            }
            if(i == niz.size()-2){
                if(niz[i] < niz[i+1]){
                    break;
                } else {
                    grbava_matrica[br].push_back(niz[i]);
                    grbava_matrica[br].push_back(niz[i+1]);
                    break;
                }
            }
            i--; // zbog for petlje
        }
    }
    grbava_matrica.resize(br+1); // neocekivano radi ??
    return grbava_matrica;
}

// RASTUCI NIZOVI
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> niz){
    // prazan vektor
    std::vector<std::vector<double>> grbava_matrica(100);
    int br(1), rsz(0);
    for(int i=0; i<niz.size()-2; i++){
    	// upisuje sve rastuce
        if(niz[i] <= niz[i+1]){
            while(niz[i] <= niz[i+1]){
                if(i == niz.size()-2 ){
                    break;
                }
                grbava_matrica[br].push_back(niz[i]);
                i++;
            }
            if(i == niz.size()-2){
                grbava_matrica[br].push_back(niz[i]);
                i++;
            }
            grbava_matrica[br].push_back(niz[i]);
            br++;
            rsz++;

        }
        // ako je kraj -> kraj
        if(i == niz.size()-1){
            break;
        }
        // preskace sve opadajuce
        if(niz[i] > niz[i+1]){
            while(niz[i] > niz[i+1]){
            	if(i == niz.size()-2){
            		break;
            	}
                i++;
            }
            if(i == niz.size()-2){
                if(niz[i] > niz[i+1]){
                    break;
                } else {
                    grbava_matrica[br].push_back(niz[i]);
                    grbava_matrica[br].push_back(niz[i+1]);
                    break;
                }
            }
            
            
            
            i--; // zbog for petlje
        }
    }
    grbava_matrica.resize(br); // neocekivano radi ??
    return grbava_matrica;
}

int main(){
    std::vector<double> niz;
    int n;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    for(int i=0; i<n; i++){
		double element;
		std::cin >> element;
        niz.push_back(element);
    }

    std::vector<std::vector<double>> test_fcije = RastuciPodnizovi(niz);
    std::cout << "Maksimalni rastuci podnizovi: ";
    for(int i=0; i<test_fcije.size(); i++){
        for(int j=0; j<test_fcije[i].size(); j++){
            std::cout << test_fcije[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<double>> opadajuci_nizovi = OpadajuciPodnizovi(niz);
    std::cout << "Maksimalni opadajuci podnizovi: ";
    for(int i=0; i<opadajuci_nizovi.size(); i++){
        for(int j=0; j<opadajuci_nizovi[i].size(); j++){
            std::cout << opadajuci_nizovi[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}