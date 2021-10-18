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
#include <stdexcept>
#include <cctype>

std::string ObrniFraze(std::string s, std::vector<std::string> baza){
	// Pravi dio zadatka
	for(int i=0; i<baza.size() ; i++){
		for(int j=0; j<s.length() ; j++){
			if(	(s.substr(j, baza[i].length() ) == baza[i]) ) {
				for(int k=j ; k<j+baza[i].length() ; k++){
					s[k]=baza[i][baza[i].length() - 1 - k + j];
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> baza){
	try{
		// drugi throw
		for(int i=0; i<baza.size() ; i++){
			for(int j=0; j<baza[i].length(); j++){
				if(	!isalpha(baza[i][j]) ) throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
		if(baza.size()==0) throw s;
		// zadatak
		for(int i=0; i<baza.size() ; i++){
			for(int j=0; j<s.length() ; j++){
				if(	(s.substr(j, baza[i].length() ) == baza[i]) && (int(j+baza[i].length() - 1)== int(s.length()-1) || !isalpha(s[j+baza[i].length()]) )
				&& (j==0 || !isalpha(s[j-1] ) ) ) {
					char temp;
					temp=s[j];
					for(int k=j ; k<j+baza[i].length()-1 ; k++)  s[k]=s[k+1];
					s[j+baza[i].length()-1]=temp;
					
					int mjesto_inserta;
					mjesto_inserta = static_cast<int>(j+baza[i].length());
					if(mjesto_inserta == s.length()){
						s.push_back('a');
						s.push_back('y');
					}
					else{
						s.insert(s.begin() + mjesto_inserta, 'a');
						s.insert(s.begin() + mjesto_inserta + 1, 'y');
					}
				}
			}
		}
		
		
		return s;
	}
	catch(std::string s){
		s.push_back(' ');
		int pocetak(-1), kraj(-1), brojac(0);
		for(int i=0 ; i<s.length() ; i++){
			if(	(i==0 || !isalpha(s[i-1]) ) && isalpha(s[i])	) pocetak = i;
			else if(isalpha(s[i]) )brojac++;
			else if(pocetak != -1 ) kraj = i; // zbog recenice koja je pocela sa razmakom
			
			if(	(pocetak!=-1) && (kraj!=-1) && (brojac !=0) ){
				char temp;
				temp = s[pocetak];
				for(int j=0; j<brojac; j++) s[pocetak+j]=s[pocetak+j+1];
				s[i-1] = temp;
				
				pocetak = -1;
				brojac = 0;
				s.insert(s.begin() + kraj, 'a');
				i++;
				s.insert(s.begin() + kraj + 1, 'y');
				i++;
				kraj = -1;
			}
			// za samo jedno slovo
			if(	(pocetak!=-1) && (kraj!=-1) ){
				pocetak = -1;
				brojac = 0;
				s.insert(s.begin() + kraj, 'a');
				i++;
				s.insert(s.begin() + kraj + 1, 'y');
				i++;
				kraj = -1;
			}
		}
		
		
		
		s.erase(s.begin()+s.length()-1);
		return s;
	}
}

int main (){
	std::cout << "Unesite recenicu: ";
	std::string a;
	std::getline(std::cin, a);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> b;
	for(;;){
		char pomoc;
		pomoc = (std::cin.peek());
		std::string c;
		std::getline(std::cin , c);
		if(pomoc =='\n') break;
		b.push_back(c);
	}
	try{
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(a,b) << std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(a,b) << std::endl;
	return 0;
}