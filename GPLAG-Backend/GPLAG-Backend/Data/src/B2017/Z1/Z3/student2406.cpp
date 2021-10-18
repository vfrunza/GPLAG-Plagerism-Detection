#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>


enum Smjer {Rastuci, Opadajuci} cond;


bool StepenDvojke (int n) {
    if (n == 0) return 0;
    while (n != 1) {
        if (n % 2 != 0) return 0;
    n = n / 2;
    }
    return 1;
}


std::deque <std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector <int> vektor, Smjer cond) {
   std::vector <int> temp;
   std::deque <std::vector<int>> result;
   int stepen (0); // zbog brojeva koji su stepeni dvojke
   bool kreni = false;
   int remember;
   int end;
   bool proslistepen;
   bool prvi;
   
    if (cond == Rastuci) {
        
        bool prvi = true;
        
        for (int i = 0; i < vektor.size(); i++) {
            
            if (stepen > 0 && kreni == true) {
            for (int i = remember; i <= end; i++) temp.push_back (vektor.at(i));
                kreni == false;
                result.push_back (temp);
                temp.resize(0);
            
            if (prvi == true && StepenDvojke (vektor.at(i))) {
                remember = i;
                proslistepen = true;
                prvi = true;
            } 
            
            if (prvi == false && StepenDvojke (vektor.at(i)) && (vektor.at(i) > vektor.at(i - 1))) {
                end = i;
                prvi = false;
                stepen ++;
            }    
            else {
                proslistepen = false;
                prvi = true;
                kreni = true;
            }
            
        }
    }      
}
    return result;   
}



int main () {
    int a;
    int n;
    std::vector <int> brojevi;
    
    std::cout << "Unesite brojeve";
    std::cin >> n;
    std::cout << "Unesite brojeve";
    
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        brojevi.push_back (a);
    }
    
    std::deque <std::vector<int>> rezultat = MaksimalniPodnizoviStepenaDvojke (brojevi, Rastuci);
    
    for (int i = 0; i < rezultat.size(); i++) 
        for (int j = 0; j < rezultat.at(i).size(); j++) std::cout << rezultat.at(i).at(j);
    
	return 0;
}