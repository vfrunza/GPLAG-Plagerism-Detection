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
#include <stdexcept>

std::vector<std::string> Unos_vektora_stringova () {			//funkcija za unos fraza (stringova u vektore)
	std::vector<std::string> v_stringova;
	std::string pom;
	for (int i=0;;i++) {
		std::getline(std::cin,pom);
		if (pom.length()==0) break;
		v_stringova.push_back(pom);
	}
	return v_stringova;
}

std::string Obrnuta_fraza (std::string normalna) {				//funkcija vraca obrnutu rijec
	std::string obrnuta;
	for (int i=normalna.length()-1; i>=0; i--)
		obrnuta+=normalna[i];
	return obrnuta;
}

bool Jedna_rijec (std::string fraza) {
	for (int i=0; i<fraza.length(); i++)
		if (fraza[i]==' ') return false;
	return true;
}

std::string ObrniFraze (std::string rec, std::vector<std::string> fraze) {		//funkcija okrece sve fraze koje se pojavljuju u recenici
	std::string pomocni;
	for (int k=0; k<fraze.size(); k++) {
		if (Jedna_rijec(fraze[k])) {
			for (int i=0; i<rec.length(); i++) {
				pomocni.resize(0);
				if (rec[i]!=' '){
					for (int j=i,p=0; rec[j]!=' ' && j<rec.length() && pomocni!=fraze[k]; j++,i++)
						if (rec[j]==fraze[k][p]) { pomocni+=rec[j]; p++;}
				//		std::cout<<"pomocni "<<pomocni<<"\n";
					if (pomocni==fraze[k]) {
						rec=rec.substr(0,i-pomocni.size())+Obrnuta_fraza(pomocni)+rec.substr(i,rec.size());
						i--;
					}
				}
			}
		}
		else {
			for (int i=0; i<rec.length(); i++) {
				pomocni.resize(0);
				if (rec[i]==fraze[k][0]){
					for (int j=i,p=0; j<rec.length() && pomocni.length()<=fraze[k].length() && rec[j]==fraze[k][p]; j++,i++,p++)
						pomocni+=rec[j];
					if (pomocni==fraze[k]) {
						rec=rec.substr(0,i-pomocni.size())+Obrnuta_fraza(pomocni)+rec.substr(i,rec.size());
						i--;
					}
				}
			}
		}
	}
	return rec;
}

std::string Pig_latin (std::string normalna) {				//funkcija od obicne rijeci pravi pig.latin rijec
	std::string s;
	for (int i=1; i<normalna.length(); i++) 
		s+=normalna[i];
	s+=normalna[0];
	s+="ay";
	return s;
}

std::string IzmijeniUPigLatin (std::string rec, std::vector<std::string> rijeci) {
	for (int i=0; i<rijeci.size(); i++) 							//IZUZECI
		for (int j=0; j<rijeci[i].size(); j++) 
			if (rijeci[i][j]==' ' || (rijeci[i][j]<'A' || (rijeci[i][j]>'Z' && rijeci[i][j]<'a') || rijeci[i][j]>'z')) 
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
				
	std::string pomocni;			//dodati uslov da ako je vektor prazan, svaku rijec izmijeni u Pig latin
	for (int k=0; k<rijeci.size(); k++) {
		for (int i=0; i<rec.length(); i++) {
			pomocni.resize(0);
			if (rec[i]!=' ') {
				for (int j=i; rec[j]!=' ' && j<rec.length() && pomocni!=rijeci[k]; j++,i++)
					pomocni+=rec[j];
				if (pomocni==rijeci[k] && (rec[i]<'A' || (rec[i]>'Z' && rec[i]<'a') || rec[i]>'z')) {
					rec=rec.substr(0,i-pomocni.size())+Pig_latin(pomocni)+rec.substr(i,rec.size());
					i--;
				}
			}
		}
	}
		if (rijeci.size()==0) {			//pokusaj uslova haha
			for (int i=0; i<rec.size(); i++){
				pomocni.resize(0);
				if (rec[i]!=' ') {
					for (int j=i; rec[j]!=' ' && j<rec.size() ;j++,i++)
						pomocni+=rec[j];
					rec=rec.substr(0,i-pomocni.size())+Pig_latin(pomocni)+rec.substr(i,rec.size());
					i++;
				}
			}
		}
	
	return rec;
}

int main ()
{	
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string>fraze;
	std::cout<<"Unesite fraze: ";
	fraze=Unos_vektora_stringova();
	try {
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,fraze)<<std::endl;
	}
	catch (std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze)<<std::endl;
	return 0;
}