/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar	
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

void PreskociRazmake(){
	while(std::cin.peek()==' '){
		std::cin.get();
	}
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	for(int i=0;i<mine.size();i++)
		if(mine[i].size()!=2)
			throw std::domain_error("Ilegalan format zadavanja mina");
	
	for(int i=0;i<mine.size();i++)
		if(mine[i][0] < 0 || mine[i][0] >=n || mine[i][1] < 0 || mine[i][1] >= n)
			throw std::domain_error("Ilegalne pozicije mina");

	Tabla tabla(n, std::vector<Polje>(n,Polje::Prazno));
	
	for(int i=0;i<mine.size();i++)
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	
	return tabla;
}

std::string ts(int x){
	std::string broj;
	do{
		broj.push_back('0'+x%10);
		x/=10;
	}
	while(x);
	
	std::string broj2;
	for(int i=broj.size()-1;i>=0;i--){
		broj2.push_back(broj[i]);
	}
	return broj2;
}

bool JeLegalan(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) 
		return false;
	return true;
}

int BrojMina(Tabla &polja, int x, int y){
	int brojac(0);
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(i==x && j==y)
				continue;
			else if(JeLegalan(polja,i,j) && (polja[i][j]==Polje::Mina||polja[i][j]==Polje::BlokiranoMina))
				brojac++;
		}
	}
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	std::vector<std::vector<int>> okolina (3, std::vector<int>(3));
	
	auto polje=polja;
	
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()){
		std::string xx=ts(x), yy=ts(y);
		std::string izuzetak="Polje ("+xx+","+yy+") ne postoji";
		throw std::domain_error(izuzetak);
	}
	
	int a=0;
	for(int i=x-1;i<=x+1;i++){
		int b=0;
		for(int j=y-1;j<=y+1;j++){ 
			
			okolina[a][b]=BrojMina(polje,i,j);
			
			b++;
		}
		a++;
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
	if(!JeLegalan(polja, x, y)) 
		 {
		 	std::string xx=ts(x), yy=ts(y), izuzetak="Polje ("+xx+","+yy+") ne postoji";
		 	throw std::domain_error(izuzetak);
		 }
	
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	else if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
	if(!JeLegalan(polja,x,y))
	 	{
	 		std::string xx=ts(x), yy=ts(y), izuzetak="Polje ("+xx+","+yy+") ne postoji";
	 		throw std::domain_error(izuzetak);
	 	}
		
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

bool SvePosjeceno(Tabla &Polja, int x, int y){
	for(int i=0;i<Polja.size();i++){
		for(int j=0;j<Polja[i].size();j++){
			if(i==x && j==y) continue;
			if(Polja[i][j]==Polje::Prazno || Polja[i][j]==Polje::BlokiranoPrazno)
				return false;
		}
	}
	return true;
}

void ResetujTablu(Tabla &polja){
	for(int i=0; i<polja.size();i++){
		for(int j=0; j<polja[i].size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	polja[x][y]=Polje::Posjeceno;
	
	int px=x, py=y;
	
	switch(int(smjer)){
		case 0:{
			x--; y--;
			break;}
		case 1:{
			x--;
			break;}
		case 2:{
			x--; y++;
			break;}
		case 3:{
			y++;
			break;}
		case 4:{
			x++; y++;
			break;}
		case 5:{
			x++;
			break;}
		case 6:{
			y--; x++;
			break;}
		case 7:{
			y--;
			break;}
	}
	
	if(!JeLegalan(polja,x,y)){
		x=px;
		y=py;
		throw std::out_of_range("Izlazak van igrace table");}
	if(int(polja[x][y])>=3&&int(polja[x][y])<=5){
		x=px;
		y=py;
		throw std::logic_error("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina){
		ResetujTablu(polja);
		return Status::KrajPoraz;
	}
		
	if(SvePosjeceno(polja,x,y)){
		ResetujTablu(polja);
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
} 

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	polja[x][y]=Polje::Posjeceno;
	
	int px=x, py=y;
	
	x=novi_x; y=novi_y;
	
	if(!JeLegalan(polja, x, y)){
		x=px;y=py;
		throw std::out_of_range("Izlazak van igrace table");}
	if(int(polja[x][y])>=3 && int(polja[x][y])<=5){
		x=px; y=py;
		throw std::logic_error("Blokirano polje");}
	
	if(polja[x][y]==Polje::Mina){
		ResetujTablu(polja);
		return Status::KrajPoraz;
	}
	
	if(SvePosjeceno(polja,x,y)){
		ResetujTablu(polja);
		return Status::KrajPobjeda;
	}
	
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska){
	
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	char znak;
	int k1, k2;
	
	PreskociRazmake();
	std::cin>>znak;
	
	if(znak=='Z'){
		
		if(std::cin.peek()!=' '&&std::cin.peek()!='\n'){
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek()!='\n'){
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		else {
			komanda=Komande::ZavrsiIgru;
			return true;
		}
	}
	else if(znak=='K'){
		
		if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek()!='\n'){
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		else{
			komanda=Komande::KreirajIgru;
			return true;
		}
	}
	else if(znak=='P'){
		
		if(std::cin.peek()=='\n'){
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		std::cin>>znak;
		
		if(znak=='1'){
		
			PreskociRazmake();
			if(std::cin.peek()=='\n'){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			std::string par;
			
			std::cin>>par;
			if(par=="GL"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(1000,'\n');
					return false;
				}
				smjer=Smjerovi::GoreLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="G"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(1000, '\n');
					return false;
				}
				smjer=Smjerovi::Gore;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="GD"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
				smjer=Smjerovi::GoreDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="D"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
				smjer=Smjerovi::Desno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="DoD"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
				smjer=Smjerovi::DoljeDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="Do"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
				smjer=Smjerovi::Dolje;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="DoL"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
				smjer=Smjerovi::DoljeLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(par=="L"){
				PreskociRazmake();
				if(std::cin.peek()!='\n'){
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000, '\n');
					return false;
				}
				smjer=Smjerovi::Lijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else {
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
		}
		
		else if(znak=='>'){
			
			PreskociRazmake();
			
			if(std::cin.peek()=='\n'){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			std::cin>>k1;
			if(!std::cin){
				std::cin.clear();
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			PreskociRazmake();
			
			if(std::cin.peek()=='\n'){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			std::cin>>k2;
			if(!std::cin){
				std::cin.clear();
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			if(std::cin.peek()!=' '&& std::cin.peek()!='\n'){
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000, '\n');
				return false;
			}
			PreskociRazmake();
			if(std::cin.peek()!='\n'){
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(10000, '\n');
				return false;
			}
			x=k1;
			y=k2;
			komanda=Komande::PomjeriDalje;
			return true;
		}
		
		else if(znak=='O'){
			PreskociRazmake();
			if(std::cin.peek()!='\n' ){
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			
			komanda=Komande::PrikaziOkolinu;
			return true;
		}
		
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			std::cin.ignore(10000,'\n');
			return false;
		}
	}
	else if(znak=='D'){
		
		PreskociRazmake();
		
		if(std::cin.peek()=='\n'){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		std::cin>>k1;
		if(!std::cin){
			std::cin.clear();
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		if(std::cin.peek()!=' ' && std::cin.peek()!='\n' ){
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek()=='\n'){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		std::cin>>k2;
		
		if(!std::cin){
			std::cin.clear();
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		
		if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		
		PreskociRazmake();
		
		if(std::cin.peek()!='\n'){
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		
		x=k1;
		y=k2;
		komanda=Komande::Deblokiraj;
		return true;
	}
	
	else if(znak=='B'){
		
		PreskociRazmake();
		
		if(std::cin.peek()=='\n'){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		std::cin>>k1;
		if(!std::cin){
			std::cin.clear();
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek()=='\n'){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		std::cin>>k2;
		
		if(!std::cin){
			std::cin.clear();
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		
		if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(1000,'\n');
			return false;
		}
		
		PreskociRazmake();
		
		if(std::cin.peek()!='\n'){
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(1000,'\n');
			return false;
		}
		
		x=k1;
		y=k2;
		komanda=Komande::Blokiraj;
		return true;
		
	}
	
	else {
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(1000,'\n');
		return false;
	}
} 

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0){
	
	if(komanda==Komande::PomjeriJednoMjesto){
		
		try{
		Status q=Idi(polja, x, y, p_smjer);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		if(q==Status::KrajPobjeda){
			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			ResetujTablu(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		else if(q==Status::KrajPoraz){
			std::cout<<"Nagazili ste na minu"<<std::endl;
			ResetujTablu(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		}
		catch(std::out_of_range izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
		catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
		
	}
	else if(komanda==Komande::PomjeriDalje){
		try{Status q = Idi(polja, x , y , p_x, p_y);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(q==Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				ResetujTablu(polja);
				throw std::runtime_error("Igra zavrsena");
			}
			else if(q==Status::KrajPoraz){
				std::cout<<"Nagazili ste na minu"<<std::endl;
				ResetujTablu(polja);
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
		catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::Blokiraj){
		try{
			BlokirajPolje(polja, p_x, p_y);
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::Deblokiraj){
		try{
			DeblokirajPolje(polja, p_x, p_y);
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::PrikaziOkolinu){
		try{
			std::vector<std::vector<int>> okolina=PrikaziOkolinu(polja,x,y);
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					std::cout<<okolina[i][j]<<" ";
				}
				std::cout<<std::endl;
			}
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::KreirajIgru){
		int br_p, k1,k2;
		char znak;
		std::cout<<"Unesite broj polja: ";
		std::cin>>br_p;
		std::vector<std::vector<int>> mine;
		std::vector<int> tacka;
		std::cout<<"Unesite pozicije mina: ";
		for( ; ; ){
			std::vector<int> tacka;
			std::cin>>znak;
			if(znak=='.'){
				PreskociRazmake();
				if(std::cin.peek()=='\n'){
				break;}
				
				else {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.ignore(1000,'\n');
					continue;
				}
			}
			if(std::cin.peek()=='\n'){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			if(znak!='('){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(1000,'\n');
				continue;
			}
			if(std::cin.peek()=='\n'){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			std::cin>>k1;
			if(!std::cin){
				std::cin.clear();
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(10000,'\n');
				continue;
			}
			if(std::cin.peek()=='\n'){
				std::cout << "Greska, unesite ponovo!" << std::endl;
				continue;
			}
			std::cin>>znak;
			if(std::cin.peek()=='\n'){
				std::cout<< "Greska, unesite ponovo!" << std::endl;
				continue;
			}
			if(znak!=','){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(10000,'\n');
				continue;
			}
			if(std::cin.peek()=='\n'){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			std::cin>>k2;
			if(!std::cin){
				std::cin.clear();
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(10000,'\n');
				continue;
			}
			if(std::cin.peek()=='\n'){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			std::cin>>znak;
			if(znak!=')'){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(10000,'\n');
				continue;
			}
			if(std::cin.peek()!='\n'){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(10000,'\n');
				continue;
			}
			
			if(k1<0 || k2<0 || k1>=br_p || k2>=br_p){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			
			tacka.push_back(k1);
			tacka.push_back(k2);
			mine.push_back(tacka);
		}
		try{
		polja=KreirajIgru(br_p, mine);}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru){
		ResetujTablu(polja);
		throw std::runtime_error("Igra zavrsena");
	}
	
}


int main (){
	
Tabla polja;
int x,y,t_x=0,t_y=0;
Komande komanda;
Smjerovi smjer;
KodoviGresaka greska;

try{
for ( ; ; ){
	
		std::cout<<"Unesite komandu: ";
		if(UnosKomande(komanda, smjer, x, y, greska)){
		IzvrsiKomandu(komanda, polja, t_x, t_y, smjer, x, y);
	}
	else{
		PrijaviGresku(greska);
	}
}}
catch(std::runtime_error izuzetak){
	std::cout<<"Dovidjenja!"<<std::endl;
}
	
	return 0;
}