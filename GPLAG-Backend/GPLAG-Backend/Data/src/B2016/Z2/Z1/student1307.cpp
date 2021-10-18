#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>


enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

std::string ToString(int n){
	
	std::string rez;
	
	while(n != 0){
		
		rez.push_back('0'+n%10);
		n /= 10;
	}
	
	std::reverse(rez.begin(),rez.end());
	return rez;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	Tabla t(n, std::vector<Polje>(n,Polje::Prazno));
	
	for(auto i:mine){
		if (i.size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
		if(i[0]<0 || i[0]>=n || i[1]<0 || i[1]>=n) throw std::domain_error ("Ilegalne pozicije mina");
		
		t[i[0]][i[1]]=Polje::Mina;
	}
	
	return t;
}

int brojOkolnihMina (const Tabla &t, int x, int y){
	
	if(x<0 || y<0 || x>=t.size() || y>=t.size()) return 0;
	
	int br(0);
	
	for(int i(-1);i<=1;i++){
		for(int j(-1);j<=1;j++){
			
			if (x+i>=0 && x+i<t.size() && y+j>=0 && y+j<t.size() && !(i==0 && j==0) && t[x+i][y+j]==Polje::Mina) br++;
		}
	}
	
	return br;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()){
		
		 std::string A = "Polje (";
		 A += ToString(x) + "," + ToString(y) + ") ne postoji";
		 throw std::domain_error(A);
	}
	
	std::vector<std::vector<int>> okolina (3,std::vector<int>(3));
	
	for(int i(-1);i<=1;i++){
		for(int j(-1);j<=1;j++){
			okolina[i+1][j+1]=brojOkolnihMina(polja,x+i,y+j);
		}
	}
	
	return okolina;
}


void BlokirajPolje (Tabla &polja, int x, int y){
	
	std::string A = "Polje (";
	A += ToString(x) + "," + ToString(y) + ") ne postoji";
	
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error (A);
	if (int (polja[x][y])<3) polja[x][y]=Polje(int(polja[x][y])+3);
}

void DeblokirajPolje (Tabla &polja, int x, int y){
	
	std::string A = "Polje (";
	A += ToString(x) + "," + ToString(y) + ") ne postoji";
	
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error (A);
	if (int (polja[x][y])>2) polja[x][y]=Polje(int(polja[x][y])-3);
}


Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size())
	throw std::out_of_range ("Izlazak van igrace table");
	
	if(int(polja[novi_x][novi_y])>2) throw std::logic_error ("Blokirano polje");
	
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	
	if(polja[x][y]==Polje::Mina) {
		polja=Tabla(polja.size(),std::vector<Polje>(polja.size(),Polje::Prazno));
		return Status::KrajPoraz;
	}
	
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja.size();j++){
			
			if(!(i==x && j==y) && !(polja[i][j]==Polje::Mina || polja [i][j]==Polje::Posjeceno))
			return Status::NijeKraj;
			
		}
	}
	
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	std::vector<std::vector<int>> v{ {-1,-1}, {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}, {0,-1}};
	return Idi(polja,x,y,x+v[int(smjer)][0],y+v[int(smjer)][1]);
}

void PrijaviGresku (KodoviGresaka kod){
	
	std::string s[] {"Nerazumljiva komanda!","Komanda trazi parametar koji nije naveden!", "Zadan je suvisan parametar nakon komande!",
					"Parametar komande nije ispravan!"};
	
	std::cout<<s[int(kod)]<<std::endl;
}

bool PrazanTok(){
	
	while(std::cin.peek()==' ') std::cin.get();
	if(std::cin.peek()=='\n') return 1;
	
	return 0;
}

bool IspravanTok(){
	
	if(!std::cin){
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		return 0;
	}
	
	return 1;
}

bool ValidacijaKomandeP1 (KodoviGresaka &greska, std::string &kom, Komande &komanda, Smjerovi &smjer){
	
	std::vector<std::string> smjerovi {"GL","G","GD","D","DoD","Do","DoL","L"};
	
	if(PrazanTok()){
		
		greska=KodoviGresaka::NedostajeParametar;
		return 0;
	}
	
	std::cin>>kom;
	
	if(std::find(smjerovi.begin(),smjerovi.end(),kom)==smjerovi.end()) {
		
		greska=KodoviGresaka::NeispravanParametar;
		return 0;
	}
	
	
	if(!PrazanTok()){
		greska=KodoviGresaka::SuvisanParametar;
		std::cin.ignore(1000,'\n');
		return 0;
	}
	
	komanda=Komande::PomjeriJednoMjesto;
	
	smjer=Smjerovi(std::find(smjerovi.begin(),smjerovi.end(),kom)-smjerovi.begin());
	
	return 1;
}

bool ValidacijaKomandiPBD(KodoviGresaka &greska, std::vector<std::string> &komande, Komande &komanda, std::string kom, int &x, int &y){
	
	for(int i(0); i<2; i++){
		
		if(PrazanTok()){
			greska = KodoviGresaka::NedostajeParametar;
			return 0;
		}
		
		int br;
		std::cin >> br;
		
		if( !IspravanTok() || (std::cin.peek() != ' ' && std::cin.peek() != '\n') ){
			greska = KodoviGresaka::NeispravanParametar;
			return 0;
		}
		
		if(i==0) x = br;
		else y = br;
	}
	
	if(!PrazanTok()){
		greska = KodoviGresaka::SuvisanParametar;
		std::cin.ignore(1000,'\n');
		return 0;
	}
	
	komanda = Komande(std::find(komande.begin(), komande.end(), kom) - komande.begin());
	return 1;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	std::vector<std::string> komande {"P1","P>","B","D","PO","Z","K"};
	std::string kom;
	std::cin >> kom;
	
	if( std::find(komande.begin(), komande.end(), kom) == komande.end() ){
		greska = KodoviGresaka::PogresnaKomanda;
		return 0;
	}
	
	if(kom == "P1") return ValidacijaKomandeP1(greska, kom, komanda, smjer);
	
	else if(kom == "P>" || kom == "B" || kom == "D") return ValidacijaKomandiPBD(greska, komande, komanda, kom, x, y);
	
	else{
		
		if(!PrazanTok()){
			std::cin.ignore(1000,'\n');
			greska = KodoviGresaka::SuvisanParametar;
			return 0;
		}
		
		komanda = Komande(std::find(komande.begin(), komande.end(), kom) - komande.begin());
		return 1;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
	if(komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje) {																																																																																																																																																			
		
		Status a;
		if(komanda == Komande::PomjeriJednoMjesto) a = Idi(polja,x,y,p_smjer);
		else  a = Idi(polja,x,y,p_x,p_y);
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		
		if(a == Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
		
		else if(a == Status::KrajPoraz){
			
			std::cout << "Nagazili ste na minu" << std::endl;
			polja = Tabla(polja.size(), std::vector<Polje>(polja.size(), Polje::Prazno));
			throw std::runtime_error("Igra zavrsena");
		}
	}
	
	else if(komanda == Komande::Blokiraj) BlokirajPolje(polja,p_x,p_y);
	else if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja,p_x,p_y);
	
	else if(komanda == Komande::PrikaziOkolinu){
		
		auto mat = PrikaziOkolinu(polja,x,y);
		
		for(auto i: mat){
			for(auto j: i) std::cout << j << " ";
			std::cout << std::endl;
		}
	}
	
	else if(komanda == Komande::ZavrsiIgru){
		
		polja = Tabla(polja.size(), std::vector<Polje>(polja.size(),Polje::Prazno));
		throw std::runtime_error("Igra zavrsena");
	}
	
	else{
		
		std::cout << "Unesite broj polja: ";
		std::vector<std::vector<int>> v;
		int brojPolja;
		std::cin >> brojPolja;
		
		char c(' ');
		int r,k;
		std::cout << "Unesite pozicije mina: ";
		
		while(1){
			
			std::cin >> c;
			if(c == '.') break;
			
			if(PrazanTok() || c != '('){
				std::cout << "Greska, unesite ponovo!" << std::endl;
				std::cin.ignore(1000,'\n');
				continue;
			}
			
			std::cin >> r;
			if(!IspravanTok() || PrazanTok()) {std::cout << "Greska, unesite ponovo!" << std::endl; continue;}
			std::cin >> c;
			if(PrazanTok() || c != ',' ) { std::cout << "Greska, unesite ponovo!" << std::endl; continue; }
			std::cin >> k;
			if(!IspravanTok() || PrazanTok()) { std::cout << "Greska, unesite ponovo!" << std::endl; continue; }
			std::cin >> c;
			if(c != ')') { std::cout << "Greska, unesite ponovo!" << std::endl; continue; }
			
			if(r<0 || k<0 || r>=brojPolja || k>=brojPolja) {std::cout << "Greska, unesite ponovo!" << std::endl; continue;}
			v.push_back({r,k});
		}
		
		polja = KreirajIgru(brojPolja,v);
	}
}

void IspisiTablu (std::vector<std::vector<Polje>> polja){
	
	for (int i(0);i<polja.size();i++){
		for(int j(0);j<polja[i].size();j++){
			std::cout<< int(polja[i][j])<<" ";
		}
		std::cout<<std::endl;
	}
	
}

int main ()
{
	int x(0),y(0);
	int x1(0),y1(0);
	Tabla t;
	
	while(1){
		
		try{
			Komande komanda;
			Smjerovi smjer;
			KodoviGresaka kodGreske;
			
			std::cout << "Unesite komandu: ";
			bool a = UnosKomande(komanda, smjer, x1, y1, kodGreske);
			
			if(a) IzvrsiKomandu(komanda, t, x, y, smjer, x1, y1);
		}
		catch(std::runtime_error e){
			std::cout << "Dovidjenja!" << std::endl;
			break;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	
	return 0;
}