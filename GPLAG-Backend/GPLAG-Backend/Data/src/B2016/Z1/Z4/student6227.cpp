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

using std::cout;
using std::cin;
using std::endl;
using std::string;


string PigLatin (string rijec){
	if (rijec.length()==0) return "ay";
	if (rijec.length()==1) return (rijec+string{"ay"});
	string rezultat=rijec.substr(1,rijec.length()-1)+rijec[0]+string{"ay"};
	return rezultat;
}
bool daLiSadrzi (string recenica, string fraza, bool cijelaRijec, int &pocetak){
	bool flag= false;
	if (fraza == " ") return false;
	int j=0;
	pocetak = 0;
	for (int i=0;i<recenica.length();i++){
		if (j< fraza.length()){
			if (recenica[i]==fraza[j] || flag){
				if (cijelaRijec && j== 0 && i>0 && recenica[i-1] != ' '){
					j=0;
					pocetak=i+1;
				}
				else{
					flag = recenica[i] == fraza[j];
					if (!flag){
						j=0;
						pocetak=i+1;
					}
					else j++;
					}
				}
			else{
				//flag=false;
				j=0;
				pocetak=i+1;
			}
		}
	}
	if (j<fraza.length()) return false;
	return flag;
}
string okrenislova (string fraza){
	if (fraza.length()==1) return fraza;
	string rezultat;
	for (int i=fraza.length()-1;i>=0;i--){
		rezultat+=fraza[i];
	}
	return rezultat;
}
std::vector<string> OcistiRijeci(std::vector<string> rijeci,bool tretrirajObrnuteRijeci){
	std::vector<string> cisteRijeci;
	for (auto rijec:rijeci){
		bool rijecPostoji =false;
		for (auto cistaRijec:cisteRijeci){
			if (cistaRijec ==rijec || (tretrirajObrnuteRijeci && cistaRijec== okrenislova(rijec))){
				rijecPostoji=true;
				break;
			}
		}
	if (rijecPostoji==false) cisteRijeci.push_back (rijec);
	}
	return cisteRijeci;
}
string IzmijeniUPigLatin (string recenica, std::vector<string> fraze){
	fraze=OcistiRijeci(fraze,true);
	for(auto rijec:fraze)
	{
		int pocetak=0;
		if (rijec.size()==0) continue;
		bool flag=true;
		for (auto slovo:rijec){
			if ((slovo >= 'A' && slovo <= 'Z') || (slovo >= 'a' && slovo <='z')) continue;
			else {
				flag=false;
				break;
			}
			}
		if (flag)
		{
			while (daLiSadrzi(recenica, rijec,true, pocetak)){
				recenica =recenica+string {"  "};
				string novaRijec =PigLatin(rijec);
				recenica=recenica.substr(0,pocetak)+novaRijec+recenica.substr(pocetak + rijec.length(), recenica.length()-(pocetak + novaRijec.length()));
			}
		}	
		else throw std::domain_error ("Nekorektan izbor rijeci");
	}
	return recenica;
}
string ObrniFraze (string recenica, std::vector<string> fraze){
	fraze=OcistiRijeci(fraze,true);
	std::string OkrSlo;
	int pocetak =-1;
	for (auto fraza:fraze){
		while (daLiSadrzi(recenica,fraza,false,pocetak)){
		//	OkrSlo=okrenislova(fraza);
			//recenica = recenica.substr(0,pocetak+fraza.length())+OkrSlo+recenica.substr(pocetak+fraza.length()+1,recenica.length()+OkrSlo.length());
			recenica = recenica.substr(0, pocetak) + okrenislova(fraza) + recenica.substr(pocetak + fraza.length(), recenica.length() - ( pocetak + fraza.length()));
		}
	}
	return recenica;
}
int main (){
	//int pocetak = -1;
	cout << "Unesite recenicu: ";
	string recenica;
	getline (cin, recenica);
	cout << "Unesite fraze: ";
	std::vector <string> fraze;
	string rijec;
	getline (cin,rijec);
	while (rijec != ""){
		fraze.push_back(rijec);
		getline(cin, rijec);
	}
	try{
		string rezultat = IzmijeniUPigLatin(recenica,fraze);
		cout << "Recenica nakon PigLatin transformacije: " << rezultat;
	}
	catch (std::domain_error izuzetak){
		cout<< "Izuzetak: " << izuzetak.what();
	}
	string rezultat=ObrniFraze(recenica,fraze);
	cout<< "\nRecenica nakon obrtanja fraza: " << rezultat;
	return 0;
}