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


//za svaku frazu prolazi kroz recenicu
std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
	for(int i=0; i<fraze.size(); i++){
		std::string pomocna_fraza;
		pomocna_fraza=fraze[i];
		for(int j=0; j<recenica.length(); j++){
			if(pomocna_fraza[0]==recenica[j]){
				int pocetak;
				pocetak=j;
				int k(0);
				while(pomocna_fraza[k]==recenica[j] && k<pomocna_fraza.length() && j<recenica.length()){
					k++;
					j++;
				}
				if(k==pomocna_fraza.length()){ //pronadjen je
					int kraj;
					kraj=j-1;
					char pomoc;
					for(int s=0; s<pomocna_fraza.length()/2; s++){
						pomoc=recenica[pocetak];
						recenica[pocetak]=recenica[kraj];
						recenica[kraj]=pomoc;
						pocetak++;
						kraj--;
					}
				} else {
					j=pocetak;
				}
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci){
	for(int i=0; i<rijeci.size(); i++){
		std::string rijec;
		rijec=rijeci[i];
		for(int j=0; j<rijec.size(); j++){
			if(rijec[j]<'A' || (rijec[j]>'Z' && rijec[j]<'a') || rijec[j]>'z')
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	//ako se posalje prazan vector
	if(rijeci.size()==0){
		bool razmak(true);
		for(int i=0; i<recenica.size(); i++){
			if(recenica[i]<'A' || (recenica[i]>'Z' && recenica[i]<'a') || recenica[i]>'z'){
				razmak=true;
			}
			else if(razmak){
				razmak=false;
				int pocetak;
				pocetak=i;
				while(((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i<recenica.size())
					i++;
				i--;
				int kraj;
				kraj=i;
				char pomoc;
				pomoc=recenica[pocetak];
				while(pocetak!=kraj){
					recenica[pocetak]=recenica[pocetak+1];
					pocetak++;
				}
				recenica[pocetak]=pomoc;
				recenica=recenica.substr(0,pocetak+1) + "ay" + recenica.substr(pocetak+1,recenica.length());
			}
		}
	} else {
		for(int i=0; i<recenica.length(); i++){
			int spasi_i;
			spasi_i=i;
			for(int j=0; j<rijeci.size(); j++){
				std::string izdvojena_rijec;
				izdvojena_rijec=rijeci[j];
				int k(0);
				if(recenica[i]==izdvojena_rijec[k] && (i==0 || (recenica[i-1]<'A' || (recenica[i-1]>'Z' && recenica[i-1]<'a') || recenica[i]>'z'))){
					while(i<recenica.length() && k<izdvojena_rijec.length() && recenica[i]==izdvojena_rijec[k]){
						i++;
						k++;
					}
					if(k==izdvojena_rijec.length() && (recenica[i]<'A' || (recenica[i]>'Z' && recenica[i]<'a') || recenica[i]>'z')){
						int pocetak;
						int kraj;
						pocetak=spasi_i;
						kraj=i-1;
						//sad promijeni rijec u PigLatin
						char pomoc;
						pomoc=recenica[pocetak];
						while(pocetak!=kraj){
							recenica[pocetak]=recenica[pocetak+1];
							pocetak++;
						}
						recenica[pocetak]=pomoc;
						//dodaj ay
						recenica=recenica.substr(0,pocetak+1) + "ay" + recenica.substr(pocetak+1,recenica.length());
					} else {
						i=spasi_i;
						i++;
					}
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	std::vector <std::string> fraze;
	while(std::cin.peek()!='\n'){
		std::string unos;
		std::getline(std::cin,unos);
		fraze.push_back(unos);
		if(std::cin.peek()=='\n')
			break;
	}
	try{
		IzmijeniUPigLatin(recenica,fraze);
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,fraze);
	} catch (std::domain_error tekst){
		std::cout << "Izuzetak: " << tekst.what();
	}
	std::cout << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,fraze);
	return 0;
}