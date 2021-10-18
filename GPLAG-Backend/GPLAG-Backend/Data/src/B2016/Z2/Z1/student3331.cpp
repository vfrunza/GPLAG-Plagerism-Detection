/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

enum class Polje { Prazno = 0, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo = 0, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj = 0, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda = 0, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto = 0, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };




typedef std::vector<std::vector<Polje>> Tabla;

bool NijeDva( std::vector<std::vector<int>> mine ) {
	for( int i=0; i< mine.size(); i++ ) {
		if( mine[i].size() != 2 ) return true;
	}
	return false;
}

bool IzlazilIzOpsega(std::vector<std::vector<int>> mine, int n) {
	for(int i=0; i< mine.size(); i++) {
		for(int j=0; j<mine[i].size(); j++)
		if(!(mine[i][j] >= 0 && mine[i][j] < n)) return true;
}
return false;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if(NijeDva(mine)) throw std::domain_error("Ilegalan format zadavanja mina");
	if(IzlazilIzOpsega(mine,n)) throw std::domain_error("Ilegalne pozicije mina");
	Tabla igraca (n, std::vector<Polje>(n,Polje::Prazno)) ;
	
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j< mine[0].size()-1; j++)
			igraca[mine[i][j]][mine[i][j+1]] = Polje::Mina;
	}
		
		
		return igraca;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if( x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> mjestaMina(3,std::vector<int>(3,0));
	
	int brojacMina=0,red=0,kolona=0;
    int vel=x+2,kol=y+2,vel1=0,kol1=0;
   //donji rubni
	for(int i=x-1; i<vel; i++ ) {
		if(i < 0 ) i+= std::abs(i);
	//	if( i >= polja.size()){ i = polja.size()-1; vel = polja.size();}
		for(int j=y-1; j< kol; j++) {
		
			brojacMina =0;
			if( j < 0) j+= std::abs(j);
		//	if( j >= polja[0].size()){ j = polja[0].size()-1; kol = polja[0].size(); }
	       // else if(i == polja.size() || j == polja[0].size()) break;
		    vel1 = i+2;
		    kol1 = j+2;
			for(int k=i-1; k<vel1; k++) {
				if(k < 0) k+= std::abs(k);
			//	if(k >= polja.size()){ k= polja.size()-1; vel1 = polja.size();}
				for(int l = j-1; l <kol1; l++) {
					
					if( l < 0)  l+= std::abs(l);
				//	if(l >= polja[0].size()){ l = polja[0].size()-1; kol1 = polja[0].size(); }
				  
					
					 if(k == i && l== j) continue;
				//	 else if(k == polja.size() || l == polja[0].size()) break;
				   	 else if(polja[k][l] == Polje::Mina) brojacMina++;
				}
			}
			mjestaMina[red][kolona] = brojacMina;
			kolona++;
			
		}
		red++;
		kolona=0;
	
		
	}
	
	return mjestaMina;
	
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if( x< 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if( polja[x][y] == Polje::Posjeceno )   polja[x][y] = Polje::BlokiranoPosjeceno;
	else if( polja[x][y] == Polje::Mina )   polja[x][y] = Polje::BlokiranoMina;
	else if( polja[x][y] == Polje::Prazno ) polja[x][y] = Polje::BlokiranoPrazno;
	
} // porbat blkirat blkirano

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if( x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size() ) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if( polja[x][y] == Polje::BlokiranoPosjeceno )   polja[x][y] = Polje::Posjeceno;
	else if( polja[x][y] == Polje::BlokiranoPrazno ) polja[x][y] = Polje::Prazno;
	else if( polja[x][y] == Polje::BlokiranoMina )   polja[x][y] = Polje::Mina;
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	Status update = Status::NijeKraj;
	
	if( smjer == Smjerovi::Gore ) { 
		if( x-1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x-1][y] == Polje::BlokiranoPosjeceno || polja[x-1][y] == Polje::BlokiranoPrazno || polja[x-1][y] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x-1; 
	}
	else if( smjer == Smjerovi::GoreDesno ) {
		if( x-1 < 0 || y+1 >= polja[0].size() ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x-1][y+1] == Polje::BlokiranoPosjeceno || polja[x-1][y+1] == Polje::BlokiranoPrazno || polja[x-1][y+1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x-1; y = y+1;
	}
	else if( smjer == Smjerovi::GoreLijevo ) {
		if( x-1 < 0 || y-1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x-1][y-1] == Polje::BlokiranoPosjeceno || polja[x-1][y-1] == Polje::BlokiranoPrazno || polja[x-1][y-1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x-1; y = y-1;
	}
	else if( smjer == Smjerovi::Desno ) {
		if( y+1 >= polja[0].size() ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x][y+1] == Polje::BlokiranoPosjeceno || polja[x][y+1] == Polje::BlokiranoPrazno || polja[x][y+1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y = y+1;
	}
	else if( smjer == Smjerovi::Lijevo ) {
		if( y-1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x][y-1] == Polje::BlokiranoPosjeceno || polja[x][y-1] == Polje::BlokiranoPrazno || polja[x][y-1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y = y-1;
	}
	else if( smjer == Smjerovi::Dolje ) {
		if( x+1 >= polja.size() ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x+1][y] == Polje::BlokiranoPosjeceno || polja[x+1][y] == Polje::BlokiranoPrazno || polja[x+1][y] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x+1;
		
	}
	else if( smjer == Smjerovi::DoljeLijevo ) {
		if( x+1 >= polja.size() || y-1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x+1][y-1] == Polje::BlokiranoPosjeceno || polja[x+1][y-1] == Polje::BlokiranoPrazno || polja[x+1][y-1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x+1; y = y-1;
	}
	else if( smjer == Smjerovi::DoljeDesno ) {
		if( x+1 >= polja.size() || y+1 >= polja[0].size() ) throw std::out_of_range("Izlazak van igrace table");
		if( polja[x+1][y+1] == Polje::BlokiranoPosjeceno || polja[x+1][y+1] == Polje::BlokiranoPrazno || polja[x+1][y+1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x+1; y = y+1;
	}
	
	int suma = 0;
	for(auto red = polja.begin(); red != polja.end(); red++) {
	auto br = std::count_if(red->begin(), red->end(), [](Polje v) { return v == Polje::Prazno;});
	suma += br;
	}
	
	if( polja[x][y] == Polje::Mina ) update = Status::KrajPoraz;
	else if( suma == 0 ) update = Status::KrajPobjeda;
	else update = Status::NijeKraj;
	
	return update;
	
} //provjerit kad su sva pređena

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	Status status = Status::NijeKraj;
	if( novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja[0].size() ) throw std::out_of_range("Izlazak van igrace table");
	if( polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	
	
	int suma = 0;
	for( auto red = polja.begin(); red != polja.end(); red++ ) {
		auto br = std::count_if(red->begin(), red->end(), [](Polje v) { return v == Polje::Prazno;});
		suma+=br;
	}
	if( polja[x][y] == Polje::Mina ) status = Status::KrajPoraz;
	else if( suma == 0 ) status = Status::KrajPobjeda;
	else status = Status::NijeKraj;
	
	return status;
}

void PrijaviGresku( KodoviGresaka greska ) {
	
	if( greska == KodoviGresaka::PogresnaKomanda ) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if( greska == KodoviGresaka::NedostajeParametar ) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if( greska == KodoviGresaka::NeispravanParametar ) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if( greska == KodoviGresaka::SuvisanParametar ) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

/*bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	
	std::string s; // P1 2 3
	std::cin>>s;
	int i=0;
	while( i< s.length()) {
		if(s[i] == ' ') i++;
		if( i!= 0 && s[i] >= 'a' && s[i] <= 'z' && s[i-1] != 'D' ) { kod_greske = KodoviGresaka::NeispravanParametar; break; }
		if( i == 0 && s[i]>= 'a' && s[i] <= 'z' ) { kod_greske = KodoviGresaka::NeispravanParametar; break; }
	//	if( !( (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' ' ) ) { kod_greske = KodoviGresaka::SuvisanParametar; break; }
		if( s[i] = 'P' && i+1 < s.length() && (s[i+1] == '>'  || s[i+1] == '1' ) ) {
			std::string kom;
			kom.push_back(s[i]);
			kom.push_back(s[i+1]);
			if( kom == "P1" ){
			    std::string cijel;
			    i+=2;
			    while ( i < s.length() ) {
			        if( ( s[i]>='A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ){
			        while( ( s[i]>='A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ){ cijel.push_back(s[i]); i++; }
			        std::cout<<cijeli;
			        }
			        if( s[i] == ' ') {i++; cijel.resize(0); }
			        else kod_greske = KodoviGresaka::NeispravanParametar;
			    }
		}
		else if( kom == "P>") {
			std::string nov;
			i+=2;
			while (i < s.length() ) { // jedan razmak između parametara
				if( s[i] != ' ' && !(s[i] >= '0' && s[i] <= '9')) kod_greske = KodoviGresaka::NedostajeParmetar;
			}
		}
		
	}
	else if( s[i] == 'P' && i+1 < s.length() && s[i+1] == 'O' ) {
		i+=2;
		while (i < s.length() ) {
			if(s[i] != ' ' ) kod_greske = KodoviGresaka::NeispravanParametar;
			
		}
		//inace sve sto treba
	}
	else if( s[i] == 'Z' ){
		i++;
		while (i < s.length() ) {
			if(s[i] != ' ') kod_greske = KodoviGresaka::NeispravanParametar;
		}
	}
	else if( s[i] == 'K') {
		i++;
		while (i < s.length() ) {
			if(s[i] != ' ') kod_greske = KodoviGresaka::NeispravanParametar;
		}	
	}else if( s[i] == 'B')
	
	
		
	}
	else {
		kod_greske == KodoviGresaka::NeispravanParametar;
	}
}*/



int main ()
{
	try{
	std::cout<<"Unesite broj polja: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite pozicije mina: ";
	std::vector<std::vector<int>> mine(n, std::vector<int>(2));

	for(int i=0; i<n; i++) {
		std::cout<<"Iduca mina: ";
		for(int j=0; j<2; j++ )
		std::cin>>mine[i][j];
		
	}
	
	auto plocica = KreirajIgru(n,mine);
	for(std::vector<Polje> red: plocica){
	for(Polje p : red) std::cout<<(int)p<<" ";
	std::cout<<std::endl;
	}
	
/*	auto minee = PrikaziOkolinu(plocica,2,2);
	for(std::vector<int> red: minee){
	for(int p : red) std::cout<<p<<" ";
	std::cout<<std::endl;
	}*/
/*	BlokirajPolje(plocica,2,2);
	for(std::vector<Polje> red: plocica){
		for(Polje p : red) std::cout<<(int)p<<" ";
		std::cout<<std::endl;
	}
	DeblokirajPolje(plocica,2,2);
	for(std::vector<Polje> red: plocica){
		for(Polje p : red) std::cout<<(int)p<<" ";
		std::cout<<std::endl;
	}*/
	int x=2,y=2;
	auto st = Idi(plocica,x,y,Smjerovi::Gore);
	for( std::vector<Polje> red : plocica) {
		for( Polje p : red) std::cout<<(int)p<<" ";
		std::cout<<std::endl;
	}
	std::cout<<(int)st<<x<<"-"<<y;
	
	
	
	
	
	
	}catch( std::domain_error d ) {
		std::cout << d.what() << std::endl;
	}catch( std::logic_error e ) {
		std::cout << e.what() << std::endl;
		
	}
	
	
	
	
	
	return 0;
}