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
typedef std::vector<std::string> StringVektor;

std::string ObrniFraze(std::string recenica, StringVektor fraze) {
	for(int i(0); i<fraze.size(); i++) {			//petljom idemo kroz vektor stringova, za svaku frazu provjera da li se pojavljuje u recenici
		for(int j(0); j<recenica.length(); j++) {	//petljom idemo kroz recenicu slovo po slovo
			int k(0);								//pomocni brojac k koji sluzi da idemo slovo po slovo kroz frazu u vektoru stringova
			if(fraze[i][k]==recenica[j]) {			//provjera da li se u recenici pojavljuje pocetno slovo fraze, ako ne da petlja nastavi dalje
				while(fraze[i][k]==recenica[j+k]) {  //ukoliko je pocetno slovo isto, provjeravaju se u while petlji i ostala slova fraze
					k++;							//uvećavamo brojac k svaki put u petlji
					if (k==fraze[i].length()) break; //kada brojac bude jednak duzini fraze prekidamo petlju i to je znak da se fraza javlja u recenici
				}
				int n(0);							//pomocni brojac koji će nam sluziti za obrtanje rijeci
				if(k==fraze[i].length()) {			//provjera da li je doslo do breaka u while petlji, ukoliko jeste obrćemo frazu
					 for(int l(j); l<j+k/2; l++) {	//posto fraza u recenici pocinje od j-te pozicije, brojac inicijaliziramo sa j i petlja ide do polovine fraze kako ne bi doslo do duplog obrtanja
					 	int pom(recenica[l]);       //l-ti char smjestamo u pomocnu varijablu(moze biti i tipa char)
					 	recenica[l]=recenica[j+k-1-n]; //posto k ima vrijednost duzine stringa umanjujemo za 1 jer indeksiranje krece od 0, pa posljednji clan ima indeks k-1
					 	recenica[j+k-1-n]=pom;		//na prvo mjesto stavljamo zadnji clan i obratno, na drugo predzadnji itd
					 	n++;		//uvećavamo brojac n kako bi se s kraja fraze priblizavali sredini
					 }
				}
			}
		}
	}
	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica, StringVektor fraze) {
	for(int i(0); i<fraze.size(); i++) 				//sa ugnijezdenom for petljom prolazimo kroz cijeli vektor fraze, i kroz svaku frazu znak po znak
		for(int j(0); j<fraze[i].length(); j++)     //kako bi provjerili da li ima nekih drugih znakova osim eng. alfabeta, ukoliko da baca se izuzetak
			if(!(fraze[i][j]>='A' && fraze[i][j]<='Z') && !(fraze[i][j]>='a' && fraze[i][j]<='z')) throw std::domain_error ("Nekorektan izbor rijeci");
	if(fraze.size()==0) {	//po tekstu zadatka ako je je vektor fraze prazan svaka rijec u recenici se mijenja po pig latinu
		for(int i(0); i<recenica.length(); i++) { //for petljom idemo kroz citavu recenicu u potrazi za rijecima
			int k(i);  // u pom brojacu k, pamtimo poziciju prvog slova u rijeci
			if((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) { //provjera da li recenica pocinje slovima
				while((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) i++; //idemo petljom kroz recenicu dok ne naiđemo na nesto sto nije slovo
				recenica.insert(recenica.begin()+i, recenica[k]); //prvo slovo sa pozicije k, insertujemo na poziciju i (i je na 1 poziciji iza rijeci)
				recenica.erase(recenica.begin()+k); //brisemo prvo slovo rijeci
				recenica.insert(recenica.begin()+i, 'a'); //posto smo koristili erase, i je idalje na 1 poziciji iza rijeci, tu insertujemo 'a'
				recenica.insert(recenica.begin()+i+1, 'y'); // i je sada na pozicij slova 'a', pa 'y' insertujemo na i+1 poziciju
				i+=2; //nakon 3 inserta i 1 erase i povećavamo za 2 kako bi i-ti indeks bio iza rijeci
			}
			if(i<recenica.length()) {  //ako nije kraj recenice idemou potragu za novom rijeci
				while(!(recenica[i]>='A' && recenica[i]<='Z') && !(recenica[i]>='a' && recenica[i]<='z')) { // sada u petlji povećavamo brojac dok
					i++;       // se ne naiđe na slovo
					if(i>=recenica.length()) break; //ako i prekoraci duzinu recenice, dolazi do breaka kako ne bi pristupali izvan stringa
				}  //na kraju while petlje na poziciji i je pocetno slovo neke rijeci (ukoliko nije doslo do breaka)
				i--; //s obzirom da će se brojac inkrementirati u for petlji pa će tada i biti indeks drugog slova, dekrementiramo i
			}
		}
	}
	for(int i(0); i<fraze.size(); i++) { //slicno kao i u obrni fraze uz dodatni uslov da se mijenjaju samo rijeci, a ne i podfraze
		for(int j(0); j<recenica.length(); j++) {
			int k(0);
			bool prekid(false);  //ovdje smo deklarisali logicku varijablu prekid kako bi znali je li doslo do prekida u while-petlji
			if(fraze[i][k]==recenica[j]) {
				while(fraze[i][k]==recenica[j+k]) {
					k++;
					if(k==fraze[i].length()) {prekid=true; break;} //ako se fraza iz vektora javlja u recenici dolazi do prekida
				}  //u sljedecoj liniji koda nalazi se uslov za provjeru da li je doslo do prekida i da li se fraza javlja kao rijec u recenici (a ne kao podfraza), uslov za to je da je rijec omeđena necim sto nije slovo ili da se radi o pocetku ili kraju recenice
				if(prekid && (j==0 || (!(recenica[j-1]>='A' && recenica[j-1]<='Z') && !(recenica[j-1]>='a' && recenica[j-1]<='z'))) && (j+k==recenica.length() || (!(recenica[j+k]>='A' && recenica[j+k]<='Z') && !(recenica[j+k]>='a' && recenica[j+k]<='z')))) {
					char pom(recenica[j]); //primjena pig latin pravila slicno kao i kada je vektor fraze prazan, uz malo drugaciji redoslijed
					recenica.erase(recenica.begin()+j); //prvo slovo rijeci na j-toj poziciji mozemo obrisati, jer ga cuvamo u varijabli pom
					recenica.insert(recenica.begin()+j+k-1, pom); //inace bi j+k bio indeks pozicije iza posljednjeg slova, ali zbog erase to je sada j+k-1 i na tu poziciju insertujemo prvo slovo
					recenica.insert(recenica.begin()+j+k, 'a');  //nakon prethodnog inserta sada je j+k pozicija iza posljednjeg slova i tu insertujemo 'a'
					recenica.insert(recenica.begin()+j+k+1, 'y'); //konacno na poziciju iza 'a' insertujemo i 'y'
				}
			}
			
		}
	}
	
	return recenica;
}
int main ()
{
	std::string recenica;
	StringVektor spisak_fraza;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::string fraza;
	for(;;) {								//beskonacna for petlja za unos fraza
		std::getline(std::cin, fraza);		//unosi se fraza
		if(fraza.length()==0) break;		//provjera da li je naprazno unesen enter, ukoliko jeste prekida se besk. petlja
		spisak_fraza.push_back(fraza);		//ukoliko je zaista unesena fraza ona se stavlja u vektor i petlja se ponavlja
	}
	try {				//pošto funkcija IzmijeniUPigLatin baca izuzetak ona se nalazi u try-catch bloku
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, spisak_fraza)<<std::endl;
	}
	catch (std::domain_error poruka) {
		std::cout<<"Izuzetak: "<<poruka.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, spisak_fraza); //funkcija ObrniFraze ne baca nikakve izuzetke i nalazi se van
	return 0;										//bloka, kako bi se izvrsila cak iako prva funkcija baci izuzetak
}