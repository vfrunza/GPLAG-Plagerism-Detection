/*B 2016/2017, Zadaća 1, Zadatak 4 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::string;
using std::vector;

string ObrniFraze(string s, vector<string> fraze){
	// Uzimati podstring po podstring, od space do space i za svaki gledati ako se podudara sa jednom od rijeci iz vektora "FRAZE"
	// Ako su fraze, koristiti flip snippet iz tutorijala
	int pocetak, kraj;
	int isti;
	char temp;
	
	// Sve fraze
	for(int i=0; i<fraze.size(); i++){
		// Svi karakteri u unesenom stringu
		for(int k=0; k<s.size(); k++){
			isti=0;
			// Ako se trenutni karakter stringa podudara sa prvim karakterom fraze, mozda su isti pa se dalje provjerava
			if(s[k]==fraze[i][0]){
				// Indeks prvog clana podstringa koji se mozda podudara
				pocetak=k;
				// Svi karakteri u frazi
				for(int j=0; j<fraze[i].size(); j++){
					if(s[k]!=fraze[i][j]) break;
					// Pomicemo karakter u stringu
					k++;
					// Govorimo da su isti trenutni karakteri, ako su svi isti onda se stringovi podudaraju
					isti++;
				}
				
				if(isti==fraze[i].size()){
					// Indeks kraja podstringa koji se podudara
					kraj=k-1;
					// Loop koji izvrne trazenu frazu, prvi put se javlja na tutorijalu 4 u funkciji "IzvrniString"
					while(pocetak<kraj){
						// Izmjena
						temp=s[pocetak];
						s[pocetak]=s[kraj];
						s[kraj]=temp;
						
						// Inkrementacija/Dekrementacija pocetne i krajnje vrijednosti
						pocetak++;
						kraj--;
					}
				}
			}
		}
	}
	return s;
}

string IzmijeniUPigLatin(string s, vector<string> fraze){
	// Uzimati podstring po podstring, od space do space i za svaki gledati ako se podudara sa jednom od rijeci iz vektora "FRAZE"
	// Ako su fraze, koristiti flip snippet iz tutorijala
	int pocetak, kraj;
	int isti;
	char temp;
	
	// Sve fraze
	for(int i=0; i<fraze.size(); i++){
		// Svi karakteri u unesenom stringu
		for(int k=0; k<s.size(); k++){
			isti=0;
			// Ako se trenutni karakter stringa podudara sa prvim karakterom fraze, mozda su isti pa se dalje provjerava
			if(s[k]==fraze[i][0]){
				// Indeks prvog clana podstringa koji se mozda podudara
				pocetak=k;
				// Svi karakteri u frazi
				for(int j=0; j<fraze[i].size(); j++){
					if(s[k]!=fraze[i][j]) break;
					// Pomicemo karakter u stringu
					k++;
					// Govorimo da su isti trenutni karakteri, ako su svi isti onda se stringovi podudaraju
					isti++;
				}
				
				//Uslov da podstring nije dio neke druge rijeci, kako na pocetku, tako i na kraju
				if(isti==fraze[i].size() && ((s[k]<'A' || s[k]>'Z') && (s[k]<'a' || s[k]>'z')) && ((s[k-isti-1]<'A' || s[k-isti-1]>'Z') && (s[k-isti-1]<'a' || s[k-isti-1]>'z'))){
					// Indeks kraja podstringa koji se podudara
					kraj=k-1;
					
					// Prvi karakter postaje temp, prvi karakter se brise i dodaje na kraj
					temp=s[pocetak];
					s.erase(pocetak, 1);
					s.insert(kraj, " ");
					s[kraj]=temp;
					// Dodaje se "ay" koje je dio igre
					s.insert(kraj+1, "ay");
				}
			}
		}
	}
	
	return s;
}

int main(){
	// Unos recenice
	string recenica;
	cout << "Unesite recenicu: ";
	std::getline(cin, recenica);
	
	// Unos fraza
	vector<string> fraze;
	string fraza;
	cout << "Unesite fraze: ";
	for(;;){
		getline(cin, fraza);
		if(!fraza.length()) break;
		else fraze.push_back(fraza);
	}
	
	/*
	// Bacanje izuzetka
	for(int i=0; i<fraze.size(); i++){
		for(int j=0; i<fraze[i].size(); j++){
			if((fraze[i][j]<'A' || fraze[i][j]>'Z') && (fraze[i][j]<'a' || fraze[i][j]>'z')){
				throw std::domain_error("Nekorektan izbor riječi");
			}
		}
	}
	
	try{
		cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze) << std::endl;
	} catch (std::domain_error greska){
		cout << greska.what() << std::endl;
	}
	*/
	
	cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze) << std::endl;
	
	cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);
	
	return 0;
}