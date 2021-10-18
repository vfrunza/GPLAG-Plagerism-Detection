/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<string>
#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
typedef vector<string> Vektor;

bool Slovo(char znak){
	if( (znak >='A' && znak<='Z') || (znak >='a' && znak<='z') ) return true;
	return false;
}

string ObrniFraze( string recenica, Vektor fraze ){
	//Dio ide frazu po frazu
	for(int i{0}; i<fraze.size(); i++){
		//Trazimo svako pojavljivanje i-te fraze u recenici
		
		for(int j{0}; j<recenica.length(); j++){
			//Logicki uslov pronalaska
			bool found{true};
			if(fraze[i][0]==recenica[j] ){
				//Trazenje poklapanja svih elemenata
				if( j+fraze[i].length()>recenica.length() || recenica.substr(j,fraze[i].length())!=fraze[i] ) {
					found = false; 
				}
				//Ukoliko su identicni substring i fraza, obrcemo frazu u recenici
				
			if(found){
				//Mijenjanje fraze u recenici, slijeva nadesno
				for(int l{j+(int)fraze[i].length()-1}, m{0}; l>=j; l--,m++){
					recenica[l]=fraze[i][m];
				}
			}
			
			}
			
		}
		
	}
	
	return recenica;
}
string IzmijeniUPigLatin ( string recenica, Vektor fraze ){
	//Test korektnosti fraza
	for(int i{0}; i<fraze.size(); i++){
		for(int j{0}; j<fraze[i].length(); j++) if(!Slovo(fraze[i][j])) throw domain_error("Nekorektan izbor rijeci");
	}
	//Uslov za izmjenu svih rijeci
	bool izmijeni_sve{false};
	if(fraze.size()==0) izmijeni_sve=true; 
	//Dio ide frazu po frazu
	for(int i{0}; i<fraze.size(); i++){
		//Trazimo svako pojavljivanje i-te fraze u recenici
		
		for(int j{0}; j<recenica.length(); j++){
			//Logicki uslov pronalaska i-te fraze pocev od j-tog indeksa recenica nadalje
			bool found{true}, skok{false};
			if(izmijeni_sve || fraze[i][0]==recenica[j]){
				//Trazenje poklapanja svih elemenata
				if(!izmijeni_sve && (j+fraze[i].length()>recenica.length() || recenica.substr(j,fraze[i].length())!=fraze[i])  /* Uslov omedjenja*/  ) {
					found = false; 
				}
				
				if(j>0 && Slovo(recenica[j-1])) found=false;
				//Ukoliko kontraprimjer nije prosao, obradjujemo recenicu!
				
				if(found){
					//Zamjena slova 
					int x,z;
					char pomocni_znak{recenica[j]};
					for( x=j+1, z=j; x<j+fraze[i].length(); x++, z++){
						recenica[z]=recenica[x];
					}
					recenica[z]=pomocni_znak;
					//Dodavanje "ay"
					string do_dodavanja{recenica.substr(0, j+fraze[i].length())};
					string od_dodavanja{recenica.substr(j+fraze[i].length(), recenica.length()-j)};
					recenica=do_dodavanja+"ay"+od_dodavanja;
					
				}
				if (found) skok=true;
				
			}
			if (found && skok) j=j+fraze[i].length()-1;
		}
	}
	return recenica;
}



int main (){
	
	string recenicaMain;
	cout<<"Unesite recenicu: ";
	getline(cin, recenicaMain);
	cout<<"Unesite fraze: ";
	Vektor frazeMain;
	while(cin.peek()!='\n'){
		string fraza;
		getline(cin,fraza);
		frazeMain.push_back(fraza);
	}
	
	
	try{
	cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenicaMain, frazeMain)<<endl;
	} catch (domain_error nekorektnoPigLatin) {
		cout<<"Izuzetak: "<<nekorektnoPigLatin.what()<<endl;
		cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenicaMain, frazeMain);
		return 0;
	}
	
	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenicaMain, frazeMain);
	
	
	return 0;
}