/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string> // za to_string

//ako je polje 1x1 odma treba ispisat kraj igre jel???

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda	
};

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;


//MINA NE SMIJE BITI NA NULA NULA.. URADITI TO 
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){ //STA AKO SE PRAZAN VEKTOR MINE POSALJE, NE UDJE U PETLJU I ONDA VRATI SAMO TABLU BEZ MINA CISTU.. MOGUCA GRESKA, JA MSM DA BI TREBALO I ZA SIZE DA JE NULA DA BACI OVAJ IZIZETAK DODAT TO MOZDA PRIJE PETLJE
	//provjera za sve ove izuzetke  // jedino mozda raspored na koji testiram izuzetke nije kao u tekst ... MOZDA GRESKA
	if(n<=0)throw std::domain_error("Ilegalna velicina");
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]>=n || mine[i][1]>=n || (mine[i][0]==0 && mine[i][1]==0))throw std::domain_error("Ilegalne pozicije mina"); //MOGUCA GRESKA ovo sam mozda treba odvojeno u novu peltju da prvo pregleda citavu matricu dal je svaki red velicina 2 pa odna tek da gleda u novoj petli elemente...
	}
	//gotovi izuzetci
	Tabla kreirana_tabla(n, std::vector<Polje>(n, Polje::Prazno));//tabla n puta n sa svim poljima inicijaliziranim na prazno...
	for(int i=0; i<mine.size(); i++){
		kreirana_tabla[mine[i][0]][mine[i][1]]=Polje::Mina;//plantam mine
	}
	
	return kreirana_tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	//testiranje da li se polje nalazi van table
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size())throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	std::vector<std::vector<int>> okolina (3, std::vector<int> () );
	int pomocna(0); // treba mi dole kad dodajem u matricu okolina, da nakon svaka tri elementa predje u novi red da na kraju bude 3x3 matrica
	int velicina(polja.size()); // da bi mi mogle petlje ici od -1, jer je polja.size unsigned int i nmze se poredit sa int i=-1 i nikad ne udje u petlju dole
	for(int i=-1; i<=velicina; i++){
		for(int j=-1; j<=velicina; j++){
			if(i>=x-1 && i<=x+1 && j>=y-1 && j<=y+1){//ovo je onaj kvadrat 3 puta 3 za koji treba naci broj mina oko svakog polja i sad dole brojim mine za svaki i unosim
				int brojac_mina(0);
				for(int k=i-1; k<=i+1; k++){
					for(int z=j-1; z<=j+1; z++){
						if(k==i && z==j)continue; //ne broji se to polje koje se gleda nego samo polja oko njega,pa ga preskacemo
						if(k>=0 && k<polja.size() && z>=0 && z<polja.size()){//ako su legalne koordinate
							if(polja[k][z]==Polje::Mina)brojac_mina++;
						}
					}
				}
				if(okolina[pomocna].size()==3)pomocna++;
				okolina[pomocna].push_back(brojac_mina);
			}
		}
	}
	
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	//ispitujem da li je plje van table
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size())throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;  //ljepse ovo probat bez ovih ifova volkih napisat ako enum radi kako mislis a provjerit ono ako je polja x y izmedju 0 i 2 ukljucujuci onda +=3
	if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	//ispitujem da li je polje van table
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size())throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
} 

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	Status status_igre(Status::KrajPobjeda); // na ovo inicjaliziro, ispod dole cu sve ostlao provjerit i ako nista nije onda je pobjeda... valjda
	
	//napravimo nove varijable da ne bi mjenjali odma ove orginalne jer se po refereni mjenja onda i original i onda ako je polje na koje hocemo lelegalno bacice funkcija izuzeak ali 
	//ce koordinate na kojima se trenutno nalazi igrac biti promjenjene i to onda ne valja zato ttrebam ovako uvest ove pomocne pa tek nakon ispitivanja ispravnosti promjenit polozaj igracu
	int novi_x(x), novi_y(y);
	
	//promjenim koordinate
	
	if(smjer==Smjerovi::GoreLijevo){
		novi_x--;
		novi_y--;
	}
	else if(smjer==Smjerovi::Gore){
		novi_x--;
	}
	else if(smjer==Smjerovi::GoreDesno){
		novi_x--;
		novi_y++;
	}
	else if(smjer==Smjerovi::Desno){
		novi_y++;
	}
	else if(smjer==Smjerovi::DoljeDesno){
		novi_x++;
		novi_y++;
	}
	else if(smjer==Smjerovi::Dolje){
		novi_x++;
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		novi_x++;
		novi_y--;
	}
	else if(smjer==Smjerovi::Lijevo){
		novi_y--;
	}
	
	//provjerim jesul nove koordinate ispravne
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	//provjerava da li je polje vec blokirano
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
	
	//posjecemo stare koordinate
	polja[x][y]=Polje::Posjeceno;
	
	//promjenimo polozaj igraca
	x=novi_x;
	y=novi_y;
	
	//posjecemo novo to polje
	//polja[x][y]=Polje::Posjeceno;
	
	//provjeravam stanje table da vidim dal je kraj igre mozda ili nije
	if(polja[x][y]==Polje::Mina){
		status_igre=Status::KrajPoraz; //ovo je ako je polje na koje smo stali mina
		//treba sada ocistiti matricu, tj postaviti sva polja na prazno
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++)polja[i][j]=Polje::Prazno;
		}
	}
	else{ // gledamo jel ostalo mina jos ili blokiranih polja da nisu mine jer onda nije kraj igre
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				if(i==x && j==y)continue;
				if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno){
					status_igre=Status::NijeKraj;
					break; //ne mora dalje gledat
				}
			}
		}
		
	}

	
	return status_igre;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	Status status_igre(Status::KrajPobjeda);
	
	//provjera jesul nove koordinate isprvne
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	//provjerava da li je polje vec blokirano
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
	
	polja[x][y]=Polje::Posjeceno; // posijecemo staro polje
	
	//odemo na novo
	x=novi_x;
	y=novi_y;
	
	//stavimo novo na posjeceno
	//polja[x][y]=Polje::Posjeceno;
	
	//provjeravam stanje table da vidim dal je kraj igre mozda ili nije
	if(polja[x][y]==Polje::Mina){
		status_igre=Status::KrajPoraz; //ako je polje na koje smo stali mina ide kraj
		// sad moramo ocistiti tablu...
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++)polja[i][j]=Polje::Prazno;
		}
	}
	else{ // gledamo jel ostalo jos mina ili blokiranih polja ili praznih tj jel kraj pobjeda ili nije kraj
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				if(i==x && j==y)continue;
				if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno){
					status_igre=Status::NijeKraj;
					break;
				}
			}
		}
	}
	
	return status_igre;
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)std::cout << "Nerazumljiva komanda!\n";
	if(greska==KodoviGresaka::NedostajeParametar)std::cout << "Komanda trazi parametar koji nije naveden!\n";
	if(greska==KodoviGresaka::NeispravanParametar)std::cout << "Parametar komande nije ispravan!\n";
	if(greska==KodoviGresaka::SuvisanParametar)std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unos_korisnika, prepoznata_komanda;
	//std::cin.ignore(10000, '\n');
	std::getline(std::cin, unos_korisnika);
//	std::cin.ignore(10000, '\n');
	// da pokusam prepoznat komande
	std::string::iterator it1(unos_korisnika.begin());
	while(it1!=unos_korisnika.end() && *it1==' ')it1++; // rijesim razmake na pocetku
	while(it1!=unos_korisnika.end()){
		
		if(*it1=='Z' || *it1=='K' || (*it1=='P' && it1+1!=unos_korisnika.end() && *(it1+1)=='O')){   //rjesim Z i K i PO
			if(*it1=='Z'){
				prepoznata_komanda="Z";
				it1++;
			}
			else if(*it1=='K'){
				prepoznata_komanda="K";
				it1++;
			}
			else{
				prepoznata_komanda="PO";
				it1+=2;
			}
			//prepoznata_komanda.push_back(*it1++);
			//sada trebam dalje gledatg dal ima ista drugo iza sm razmaka onda je to suvisan parametar ja msm
			while(it1!=unos_korisnika.end()){
				if(*it1!=' '){//onda imam suvisan parametar
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				it1++;
			}
		}
		else if(*it1=='B' || *it1=='D' || (*it1=='P' && it1+1!=unos_korisnika.end() && *(it1+1)=='>')){
			if(*it1=='B'){
				prepoznata_komanda="B";
				it1++;
			}
			else if(*it1=='D'){
				prepoznata_komanda="D";
				it1++;
			}
			else{
				prepoznata_komanda="P>";
				it1+=2;
			}
			
			//sada geldam dalje moraju biti dva broja iza rastavljena razmacima i samo razmaci mogu biti da bi bilo ispravno ako nije onda pogresan parametar (Isto ako je bilo sta osim 
			//razmaka iza drugog parametra)
			while(it1!=unos_korisnika.end() && *it1==' ')it1++; // razmaci 
			if(it1==unos_korisnika.end()){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(it1!=unos_korisnika.end() && (*it1<'0' || *it1>'9')){ //da li ide broj iza (prva koordinata)
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			x=*it1++-'0'; //prva koordinata
			while(it1!=unos_korisnika.end() && *it1==' ')it1++; // AKO JE DVOCIFREN BROJ ONDA OVO NECE NISTA DOBRO RADITI JER NEMA RAZMAKA DA PRESKOCI PA CE DRUGU CIFRU UZET ZA DRUGU KOORDINATU A ONO IZA CE ONDA SMATRAT KO POGRESNIM PARAMETROM ILI SUVISNIM ITD.
			while(it1!=unos_korisnika.end() && (*it1<'0' || *it1>'9')){ // da li ima druga koordinata
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			y=*it1++-'0'; //druga koordinata
			while(it1!=unos_korisnika.end() && *it1==' ')it1++; //dalje razmaci
			if(it1!=unos_korisnika.end()){ //ako nije doso do kraja znaci da ima nesto drugo sem razmaka iza drugog broja...
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		else if(*it1=='P' && (it1+1)!=unos_korisnika.end() && *(it1+1)=='1'){
			prepoznata_komanda="P1";
			it1+=2;
			
			//sada gledam dalje mora biti neka od onih legalnih naredbi iza i nista drugo da bi ipravno bilo
			while(it1!=unos_korisnika.end() && *it1==' ')it1++;//razmaci iza
			if(it1!=unos_korisnika.end()){
				int brojac_pomocni(0);
				if(*it1=='G'){
					smjer=Smjerovi::Gore;
					brojac_pomocni=1;
				}
				else if(*it1=='D'){
					smjer=Smjerovi::Desno;
					brojac_pomocni=1;
				}
				else if(*it1=='L'){
					smjer=Smjerovi::Lijevo;
					brojac_pomocni=1;
				}
				else{
					greska=KodoviGresaka::NeispravanParametar;
					return 0;
				}
				if((it1+1)!=unos_korisnika.end()){
					if(*it1=='G' && (*(it1+1)=='L')){
						smjer=Smjerovi::GoreLijevo;
						brojac_pomocni=2;
					}
					if(*it1=='G' && (*(it1+1)=='D')){
						smjer=Smjerovi::GoreDesno;
						brojac_pomocni=2;
					}
					if(*it1=='D' && (*(it1+1)=='o')){
						smjer=Smjerovi::Dolje;
						brojac_pomocni=2;
						if((it1+2)!=unos_korisnika.end()){
							if(*(it1+2)=='D'){
								smjer=Smjerovi::DoljeDesno;
								brojac_pomocni=3;
							}
							if(*(it1+2)=='L'){
								smjer=Smjerovi::DoljeLijevo;
								brojac_pomocni=3;
							}
						}
					}
				}
				it1+=brojac_pomocni;
			}
			else  {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			while(it1!=unos_korisnika.end() && *it1==' ')it1++;//razmaci iza komande
			if(it1!=unos_korisnika.end()){
				greska=KodoviGresaka::NeispravanParametar;
				return 0;
			}
		}
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		
		//if(it1==unos_korisnika.end())break;
		//it1++;
	}
	
	//ovo cu razdovjit napraviti novi string prepoznata komanda i i uzet i odvojeno one parametre odrediti proverit jel ve uspravno uneseno i onda dole u ifovima unos korisnika
	//zamjenit sa prepoznata pkomanda itd.
	
	
	if(prepoznata_komanda=="K")komanda=Komande::KreirajIgru;
	else if(prepoznata_komanda=="Z")komanda=Komande::ZavrsiIgru;
	else if(prepoznata_komanda=="PO")komanda=Komande::PrikaziOkolinu;
	else if(prepoznata_komanda=="B")komanda=Komande::Blokiraj;
	else if(prepoznata_komanda=="D")komanda=Komande::Deblokiraj;
	else if(prepoznata_komanda=="P>")komanda=Komande::PomjeriDalje;
	else if(prepoznata_komanda=="P1")komanda=Komande::PomjeriJednoMjesto;
	
	if(prepoznata_komanda.size()==0){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0){
	
	try{
	
		if(komanda==Komande::KreirajIgru){
			int n;
			std::vector<std::vector<int>> mine;
			
			//treba uradit provjeru ispravnosti unosa !!!!!!!!! URADITIIIII
			for(;;){  // mozda unos raditi ko string da b mogo ono razdvaja i kad unese tipa 2.4 da mi ne unese dva nego vidimd a ima iza broja nesto i kazem da ne valja unos
				std::cout << "Unesite broj polja: ";
				std::cin >> n;
				if(!std::cin || n<=0){
					std::cout << "Greska, unesite ponovo!\n"; // treba staviti clear steram ulazni inace nece radit ako je n nesto lijevo!!!!!!!!POGLEDAT
					if(!std::cin){
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}				
					
				}else break;
			}
			std::cin.ignore(10000, '\n');
			//i ovo treba uraditi unos kako treba string neki pa onda izdvajat brojeve iz stringa.... !!! URADITIIIII
			std::cout << "Unesite pozicije mina: ";
			
			for(;;){
				std::vector<int> koordinate_mine;
				std::string pomocna_mine;
				std::getline(std::cin,pomocna_mine);
				if(pomocna_mine==".")break; // unos zavrsava tackom
				auto it(pomocna_mine.begin());
				while(it!=pomocna_mine.end() && *it==' ')it++; // razmake na startu rijesim do otvorene zagrade
				if(it!=pomocna_mine.end() && *it++!='('){
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				while(it!=pomocna_mine.end() && *it==' ')it++;
				if(it!=pomocna_mine.end() && (*it<'0' || *it>'9')){
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				koordinate_mine.push_back(*it++-'0');
				while(it!=pomocna_mine.end() && *it==' ')it++;
				if(it!=pomocna_mine.end() && *it++!=','){
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				while(it!=pomocna_mine.end() && *it==' ')it++;
				if(it!=pomocna_mine.end() && (*it<'0' || *it>'9')){
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				koordinate_mine.push_back(*it++-'0');
				while(it!=pomocna_mine.end() && *it==' ')it++;
				if(it!=pomocna_mine.end() && *it++!=')'){
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				while(it!=pomocna_mine.end()){
					if(*it!=' '){
						std::cout << "Greska, unesite ponovo!\n";
						continue;
					}
					it++;
				}
			
			
				//URAADIT PROVJERU ISPRAVNOSTI OVDEEE
				//kad izdovim brojeve provjerit ispravnost koordinata da li su smislene uopste...
			
				if(koordinate_mine[0]<0 || koordinate_mine[0]>=n || koordinate_mine[1]<0 || koordinate_mine[1]>=n || (koordinate_mine[0]==0 && koordinate_mine[1]==0)){
				std::cout << "Greska, unesite ponovo!\n";
				continue;
				}
			
				if(koordinate_mine.size()==2)mine.push_back(koordinate_mine);
			}
			/*std::cout << "\nMINE:\n";
			for(int i=0; i<mine.size(); i++){
				for(int j=0; j<mine[i].size(); j++){
					std::cout << mine[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "________\n";*/
			
			polja=KreirajIgru(n, mine);
		}
		else if(komanda==Komande::ZavrsiIgru){
		
			//cisti tablu sve stavlja na prazno
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[i].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
		
			throw std::runtime_error("Igra zavrsena\n");
		}
		else if(komanda==Komande::PrikaziOkolinu){
			std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
			for(int i=0; i<okolina.size(); i++){
				for(int j=0; j<okolina[i].size(); j++){
					std::cout << okolina[i][j] << " ";
				}
				std::cout << "\n";
			}
		}
		else if(komanda==Komande::Blokiraj){
			BlokirajPolje(polja, p_x, p_y);
		}
		else if(komanda==Komande::Deblokiraj){
			DeblokirajPolje(polja, p_x, p_y);
		}
		else if(komanda==Komande::PomjeriDalje){
			Status trenutno_stanje_igre(Idi(polja, x, y, p_x, p_y));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if(trenutno_stanje_igre==Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
			if(trenutno_stanje_igre==Status::KrajPoraz){
				std::cout << "Nagazili ste na minu\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
		}
		else if(komanda==Komande::PomjeriJednoMjesto){
			Status trenutno_stanje_igre(Idi(polja, x, y, p_smjer));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if(trenutno_stanje_igre==Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
			if(trenutno_stanje_igre==Status::KrajPoraz){
				std::cout << "Nagazili ste na minu\n";
				IzvrsiKomandu(Komande::ZavrsiIgru,polja, x, y);
			}
		}
	
	}
	catch(std::domain_error &e){
		std::cout << e.what() << "\n";
	}
	catch(std::out_of_range &e){
		std::cout << e.what() << "\n";
	}
	catch(std::logic_error &e){ // loic error ide zadnji jer su ova dva iznad nejgovi podtipovi pa bi i njih fato
		std::cout << e.what() << "\n";
	}
}

int main ()
{
	Tabla polja; // ovdje sam izvan definiso da se ne bi svaki krug ponovo stvarala i brisala ono od prije ja msm
	int x(0), y(0); //i ovo vani da ne bu svaki put vratilo igrada na pocetni polozaj
	for(;;){
		std::cout << "Unesite komandu: ";
		Komande komanda;
		Smjerovi smjer;
		KodoviGresaka greska;
		int novo_x, novo_y;
		if(UnosKomande(komanda, smjer, novo_x, novo_y, greska)){
			try{
				IzvrsiKomandu(komanda, polja, x, y, smjer, novo_x, novo_y);
				if(komanda==Komande::KreirajIgru){
					Status trenutno_stanje_igre(Idi(polja, x, y, 0, 0));
					if(trenutno_stanje_igre==Status::KrajPobjeda){
						std::cout << "Bravo, obisli ste sva sigurna polja\n";
						IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
					}
				}
			}
			catch(std::runtime_error &e){
				std::cout << "Dovidjenja!";
				return 0;
			}
			
			/*std::cout << "\n\n";
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					std::cout << int(polja[i][j]) << "    ";
				}
				std::cout << "\n";
			}
			*/
		}
		else{
			PrijaviGresku(greska);
		}
	}
	
	
	return 0;
}