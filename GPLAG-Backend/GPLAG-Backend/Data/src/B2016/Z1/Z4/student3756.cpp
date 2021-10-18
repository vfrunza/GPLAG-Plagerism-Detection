/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream> 
#include <vector>
#include <string>

void mijenjaj (std::string &recenica, std::string rijec){
	std::string nova_recenica; 
	for(int i=0; i < recenica.length(); i++){
		if(recenica[i] != rijec[0]) nova_recenica.push_back(recenica[i]);
	}
}



std::string ObrniRijec(std::string recenica, int pocetak, int VelicinaRijeci ){
	char znak; 
	for(int i = pocetak; i < (VelicinaRijeci) /2; i++){
		znak = recenica[VelicinaRijeci - i - 1];
		recenica[VelicinaRijeci - i - 1] = recenica[i];
		recenica[i] = znak; 
	}
	return recenica; 
} 


int JeLiToTa(std::string rijec, std::string recenica){
	int pocetna(-1);
	for(int i=0; i < recenica.length(); i++){
		if(recenica[i] == rijec[0]){
		for(int j=0; j < rijec.length(); j++){
			if(recenica[i] == rijec[j]){ 
				i++; 
				if(j == rijec.length()-1) pocetna = i - rijec.length()-1; }
			
			else break;
		}
		}
	}
return pocetna; 
}


std::string ObrniFraze(std::string recenica, std::vector<std::string> vs){
	
	int k;
	for(int i = 0; i < vs.size(); i++){
		k = JeLiToTa(vs[i], recenica);
		if(k == -1) continue; 
		
	gotovarecenica = ObrniRijec(recenica, k, vs[i].length());
	}
	
	return gotovarecenica;
}


int main ()
{ 
	std::string recenica;
	std::cout << "Unesite recenicu: "; 
	std::getline(std::cin, recenica);

	std::cout << "Unesite fraze:";
	std::vector<std::string> fraze;
	std::string fraza; 
	while(true){
		std::getline(std::cin, fraza);
		if(std::cin.peek() == '\n') break;
		
		fraze.push_back(fraza);
	}
	
	std::string s(ObrniFraze(recenica, fraze)); 
	std::cout << s; 

return 0;
}