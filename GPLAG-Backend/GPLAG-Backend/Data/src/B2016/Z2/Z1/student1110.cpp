/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <complex>
#include <stdexcept>
#include <string>
#include <sstream>

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

template <typename T> std::string PretvoriUString(T x){ //funckija iz predavanja 3_b za pretvaranje broja u string
	std::ostringstream s; s << x; return s.str();
}

bool DaLiJeBroj(std::string a){ // funckija koja provjerava da li je string sastavljen samo od cifara; 
	for(std::string::iterator it=a.begin(); it<a.end(); it++){
		if(*it<48 || *it>57)return false;
	}
	return true;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla pocetnatabla (n, std::vector<Polje>(n, Polje::Prazno));
	//testira se ispravnost vektora mine koji sadrzi koordinate mina;
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]==0 && mine[i][1]==0)throw std::domain_error("Ilegalne pozicije mina"); //pocetni polozaj (0,0) ne smije biti miniran
		for(int j=0; j<mine[i].size(); j++){
			if(mine[i][j]>=n || mine[i][j]<0)throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	//koordinate mina se upisuju u pocetnutablu
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<mine.size(); k++){
				if(mine[k][0]==i && mine[k][1]==j)pocetnatabla[i][j]=Polje::Mina;
			}
		}
	}
	return pocetnatabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){ //polja je ovaj tabla na kojoj se igra koju dobijemo sa KreirajIgru npr.
	std::vector<std::vector<int>> okolina(3);
	//provjeravamo da li se (x,y) nalazi na tabli
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	//prolazim kroz sva polja oko (x,y) redom od gornjeg lijevog element po element, red po red ali bez da im pristupam jer ako je npr(x,y)=(0,0) 
	//doslo bi do greske
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			//sad za svako ovo polje prolazim kroz onih 8 polja oko njega i brojim mine
			int BrojMina(0);
			for(int k=i-1; k<=i+1; k++){
				for(int z=j-1; z<=j+1; z++){
					if(k==i && z==j)continue; // preskacemo to polje na kojem se nalazimo ono samo brojimo mine oko njega
					if(k<0 || z<0 || k>=polja.size() || z>=polja.size())continue; // ako se nalazimo izvan table ta polja ne gledamo racunamo da nema mina
					if(polja[k][z]==Polje::Mina)BrojMina++;
				}
			}
			okolina[i-x+1].push_back(BrojMina);//ovo i-x+1 da dobijem redom 0, 1, 2 jer je i=x-1, a i++ svaki krug
		}
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	//provjerimo da li se (x,y) nalazi na tabli
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	//provjerimo da li se (x,y) nalazi na tabli
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	Status RezultatPomjeranja;
	int x_novo(0), y_novo(0);
	if(smjer==Smjerovi::GoreLijevo){
		x_novo=x-1;
		y_novo=y-1;
	}
	else if(smjer==Smjerovi::Gore){
		x_novo=x-1;
		y_novo=y;
	}
	else if(smjer==Smjerovi::GoreDesno){
		x_novo=x-1;
		y_novo=y+1;
	}
	else if(smjer==Smjerovi::Desno){
		x_novo=x;
		y_novo=y+1;
	}
	else if(smjer==Smjerovi::DoljeDesno){
		x_novo=x+1;
		y_novo=y+1;
	}
	else if(smjer==Smjerovi::Dolje){
		x_novo=x+1;
		y_novo=y;
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		x_novo=x+1;
		y_novo=y-1;
	}
	else if(smjer==Smjerovi::Lijevo){
		x_novo=x;
		y_novo=y-1;
	}
	if(x_novo<0 || y_novo<0 || x_novo>=polja.size() || y_novo>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	if(polja[x_novo][y_novo]==Polje::BlokiranoPrazno || polja[x_novo][y_novo]==Polje::BlokiranoPosjeceno || polja[x_novo][y_novo]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=x_novo;
	y=y_novo;
	if(polja[x][y]==Polje::Mina){
		RezultatPomjeranja=Status::KrajPoraz;
		//cisti se odna i matrica ova polja, svako polje se stavlja na prazno
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
	}
	else{ // sad gledam da li je ostalo praznih polja jos ako nije --> pobjeda ako jeste --> nije kraj
		bool indikator(true);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				if(i==x && j==y)continue;
				if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno)indikator=false;
			}
		}
		if(indikator)RezultatPomjeranja=Status::KrajPobjeda;
		else RezultatPomjeranja=Status::NijeKraj;
	}
	return RezultatPomjeranja;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	Status RezultatPomjeranja;
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
    polja[x][y]=Polje::Posjeceno;
    x=novi_x;
    y=novi_y;
	if(polja[x][y]==Polje::Mina){
		RezultatPomjeranja=Status::KrajPoraz;
		//cisti se odma i matrica ova polja, svako polje se stavlja na prazno
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
	}
	else{ // sad gledam da li je ostalo praznih polja jos ako nije onda pobjeda ako jeste onda nije kraj 
		bool indikator(true);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				if(i==x && j==y)continue;
				if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno)indikator=false;
			}
		}
		if(indikator)RezultatPomjeranja=Status::KrajPobjeda;
		else RezultatPomjeranja=Status::NijeKraj;
	}
	return RezultatPomjeranja;
}

void PrijaviGresku (KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)std::cout << "Nerazumljiva komanda!\n";
	else if(greska==KodoviGresaka::NedostajeParametar)std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(greska==KodoviGresaka::NeispravanParametar)std::cout << "Parametar komande nije ispravan!\n";
	else if(greska==KodoviGresaka::SuvisanParametar)std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string jelikomanda;
	std::getline(std::cin, jelikomanda);
	
	std::vector<std::string>str; //izdvojit cu sve razmake i one karaktere sve ostale smjestiti u ovaj vektor stringova
	int i(0), pocetni_indeks(0);
	for(std::string::iterator it=jelikomanda.begin(); it<jelikomanda.end(); it++, i++){
		bool indikator(true);
		while(*it!=' '){
			if(indikator)pocetni_indeks=i;
			indikator=false;
			it++;
			i++;
			if(it==jelikomanda.end())break;
		}
		if(!indikator)str.push_back(jelikomanda.substr(pocetni_indeks, i-pocetni_indeks));
	}
	
	//ako samo enter udari korisnik
	
	if(str.size()==0){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	//
	
	if(str.size()==1 && (str[0]=="K" || str[0]=="Z" || str[0]=="PO")){
		if(str[0]=="K"){
			komanda=Komande::KreirajIgru;
			return true;
		}
		else if(str[0]=="Z"){
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		else if(str[0]=="PO"){
			komanda=Komande::PrikaziOkolinu;
			return true;
		}
	}
	
	else if(str.size()==2 && str[0]=="P1"){                // 17.4 11:50 dodo else 
		if(str[1]=="GL"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::GoreLijevo;
			return true;
		}
		else if(str[1]=="G"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Gore;
			return true;
		}
		else if(str[1]=="GD"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::GoreDesno;
			return true;
		}
		else if(str[1]=="D"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Desno;
			return true;
		}
		else if(str[1]=="DoD"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::DoljeDesno;
			return true;
		}
		else if(str[1]=="Do"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Dolje;
			return true;
		}
		else if(str[1]=="DoL"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::DoljeLijevo;
			return true;
		}
		else if(str[1]=="L"){
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Lijevo;
			return true;
		}
		else{
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
	}
	
	else if(str.size()==3 && DaLiJeBroj(str[1]) && DaLiJeBroj(str[2])){    // isto dodo else
		if(str[0]=="P>"){
			komanda=Komande::PomjeriDalje;
			x=std::stoi(str[1]);
			y=std::stoi(str[2]);
			return true;
		}
		else if(str[0]=="B"){
			komanda=Komande::Blokiraj;
			x=std::stoi(str[1]);
			y=std::stoi(str[2]);
			return true;
		}
		else if(str[0]=="D"){
			komanda=Komande::Deblokiraj;
			x=std::stoi(str[1]);
			y=std::stoi(str[2]);
			return true;
		}
	}
	else if(str[0]!="K" && str[0]!="Z" && str[0]!="PO" && str[0]!="P1" && str[0]!="P>" && str[0]!="B" && str[0]!="D"){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	else if(  ((str[0]=="K" || str[0]=="Z" || str[0]=="PO") && str.size()>1) || ((str[0]=="P>" || str[0]=="B" || str[0]=="D") && str.size()>3) || (str[0]=="P1" && str.size()>2) ){
		greska=KodoviGresaka::SuvisanParametar;	
		return false;
	}
	else if( ((str[0]=="P>" || str[0]=="B" || str[0]=="D") && str.size()==1) || (str[0]=="P1" && str.size()==1) ){ //DODO mijenjo ovo 
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
	else if( ((str[0]=="P>" || str[0]=="B" || str[0]=="D") && str.size()<=3) || (str[0]=="P1" && str.size()==2) ){//DODO i ovo mijenjao
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}
	
	greska=KodoviGresaka::PogresnaKomanda;
	
	//KADA SU NEISPRAVNI PARAMETRI I KADA SE VRACA FALSE NISAM DEFINIO 
	
	return false; // OVO OVDE MOZE STAJAT JER ONO GORE SU SVI SLUCAJEVI GDJE MOZE BITI TRUE A AKO NIJE TRUE I DODJE DOVDE NROAMLNO AD JE FALSE SAMO STO NE UBACIM U GRESKU ONAJ KOD GRESKE TEKST
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	
	if(komanda==Komande::KreirajIgru){
		int n;
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		
		//DODO 28.4 NAVECE
	/*	if(n==1){
			std::cout << "Bravo, obisli ste sva sigurna polja\n";
			IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, p_smjer, p_x, p_y);
		}*/
		//
		
		std::vector<std::vector<int>> mine;
		std::cout << "Unesite pozicije mina: ";
		for(;;){ // unos mi nije dobar za dosta slucajeva (samo jeadn broj) 0.nesto uzme tacku ko da je kraj; nisam provejrio za npr 12ab ili (2abc);
			std::complex<int> a;
			std::cin >> a;
			bool indikator(true);
			if(!std::cin || std::cin.peek()!='\n'){ //DODO drugi uslov ovaj 
				indikator=false;
				bool JeLiTokZablokiro(std::cin);//DODO
				std::cin.clear();
				if(std::cin.peek()=='.' && !JeLiTokZablokiro){  //DODO drugi usloc ovaj !std::cin
					std::cin.ignore();  //DODO ___ CIN.IGNORE() BIRSE JEDAN KARAKTER SAMO
					if(std::cin.peek()=='\n')break; //DODO bilo samo break
				}
				std::cout << "Greska, unesite ponovo!\n";
				std::cin.ignore(10000, '\n');
				continue; //DODO
			}
			if(a.real()>=n || a.real()<0 || a.imag()>=n || a.imag()<0)std::cout << "Greska, unesite ponovo!\n";
			else if(indikator)mine.push_back({a.real(), a.imag()});
		}
		std::cin.ignore(10000, '\n'); // jer poslije ima getline gore u unesi komandu pa bi samo povuklo \n;
		try{
			polja=KreirajIgru(n, mine);
			//DODO
			bool NemaSlobodnihPolja(true);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(i==0 && j==0)continue;
					if(polja[i][j]!=Polje::Mina)NemaSlobodnihPolja=false;
				}
			}
			if(NemaSlobodnihPolja){
				std::cout << "Bravo, obisli ste sva sigurna polja\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
			//---DODO dovde
		} catch(const std::domain_error& e){
			std::cout << e.what() << std::endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru){
		//treba ocistiti matricu i postaviti sve na prazno
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::PrikaziOkolinu){
		try{
			std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
			for(int i=0; i<okolina.size(); i++){
				for(int j=0; j<okolina.size(); j++){
					std::cout << okolina[i][j] << " ";
				}
				std::cout << std::endl;
			}
		} catch(const std::domain_error& e){
			std::cout << e.what() << std::endl;
		}	
	}
	else if(komanda==Komande::PomjeriJednoMjesto){
		try{
			Status RezultatPomjeranja(Idi(polja, x, y, p_smjer));
			//ubacit provjeru ovog statusa rezlutat pomjeranja
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			
			//
			if(RezultatPomjeranja==Status::KrajPoraz){
				std::cout << "Nagazili ste na minu\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, p_smjer, p_x, p_y);
			}
			else if(RezultatPomjeranja==Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, p_smjer, p_x, p_y);
			}
			// ovo je ta provjera i isto ide dole za pomjeri dalje
			
		} 
		catch(const std::out_of_range& e){
			std::cout << e.what() << std::endl;
		}
		catch(const std::logic_error& e){
			std::cout << e.what() << std::endl;
		}
	}
	else if(komanda==Komande::PomjeriDalje){
		try{
			Status RezultatPomjeranja(Idi(polja, x, y, p_x, p_y));
			// ubacit provjeru ovog statusa RezultatPomjeranja
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			
			//
			if(RezultatPomjeranja==Status::KrajPoraz){
				std::cout << "Nagazili ste na minu\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, p_smjer, p_x, p_y);
			}
			else if(RezultatPomjeranja==Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, p_smjer, p_x, p_y);
			}
			// ovo je ta provjera ko gore isto sto sam dodo za kraj igre kad pobijedi ili izgubi
			
		} 
		catch(const std::out_of_range& e){
			std::cout << e.what() << std::endl;
		}
		catch(const std::logic_error& e){
			std::cout << e.what() << std::endl;
		}
	}
	else if(komanda==Komande::Blokiraj){
		try{
			BlokirajPolje(polja, p_x, p_y);
		} catch(const std::domain_error& e){
			std::cout << e.what() << std::endl;
		}
	}
	else if(komanda==Komande::Deblokiraj){
		try{
			DeblokirajPolje(polja, p_x, p_y);
		} catch(const std::domain_error& e){
			std::cout << e.what() << std::endl;
		}
	}
	
	
	
}

int main ()
{
	int x(0), y(0); // startna pozicija je 0,0
	Tabla polja; // pocetna velicina table je 0x0
	
	//int p_x(0), p_y(0); //nez ovi sta su valjda koordinate ono kad se pomjera dalje negdje igrac...
	
	for(;;){
		Komande komanda;
		Smjerovi smjer;
		KodoviGresaka greska;
		std::cout << "Unesite komandu: ";
		int p_x, p_y;
		bool komandaispravna(UnosKomande(komanda, smjer, p_x, p_y, greska));
		
		if(komandaispravna){
			try{
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			}
			catch(std::runtime_error){
				std::cout << "Dovidjenja!";
				return 0;
			}	
			/*catch(const std::logic_error& e){
				std::cout << e.what() << std::endl;
			}
			catch(const std::out_of_range& e){
				std::cout << e.what() << std::endl;
			}
			catch(const std::domain_error& e){
				std::cout << e.what() << std::endl;
			}*/
		}
		else {
			PrijaviGresku(greska);
		    continue; // ovo continue nako jer nisam nsita drugo bio stavio a i ne terba nsita ne radi svakako al et
		}
	}
	return 0;
}