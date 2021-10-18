/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla Igraca_tabla(n, std::vector<Polje>(n, Polje::Prazno));		//pravimo tablu i inicijaliziramo sva polja na 'Prazno'
	if(mine.size()>Igraca_tabla.size()) throw std::domain_error("Ilegalne pozicije mina");
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()<2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<2; j++){
			Igraca_tabla[i][j]=Polje::Mina;		//stavljamo mine na tablu
		}
	}
	return Igraca_tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> Okolina(3, std::vector<int>(3)); //matrica formata 3x3
	
}
void BlokirajPolje(Tabla &polje, int x, int y){
	if(x<0 || y<0 || x>polje.size()) throw std::domain_error("Polje (x,y) ne postoji!");  //skontaj ovo
	if(polje[x][y]==Polje::Prazno) polje[x][y]=Polje::BlokiranoPrazno;
	else if(polje[x][y]==Polje::Posjeceno) polje[x][y]=Polje::BlokiranoPosjeceno;
	else if(polje[x][y]==Polje::Mina) polje[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polje, int x, int y){
	if(x<0 || y<0 || x>polje.size()) throw std::domain_error("Polje (x,y) ne postoji!");
	if(polje[x][y]==Polje::BlokiranoPrazno) polje[x][y]=Polje::Prazno;
	else if(polje[x][y]==Polje::BlokiranoPosjeceno) polje[x][y]=Polje::Posjeceno;
	else if(polje[x][y]==Polje::BlokiranoMina) polje[x][y]=Polje::Mina;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja[x][y]=Polje::Posjeceno;
	if(smjer<=Smjerovi::GoreDesno){
		if(x==0) throw std::out_of_range("Izlazak van igrace table");
		x--;  //pomjeramo se gore
		if(smjer==Smjerovi::GoreDesno && y<polja.size()) y++;
		else if(smjer==Smjerovi::GoreLijevo && y>0) y--;
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if(smjer>Smjerovi::Desno && smjer<Smjerovi::Lijevo){
		if(x==polja.size()) throw std::out_of_range("Izlazak van igrace table");
		x++;
		if(smjer==Smjerovi::DoljeDesno && y<polja.size()) y++;
		else if(smjer==Smjerovi::DoljeLijevo && y>0) y--;
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else{
		if(smjer==Smjerovi::Desno && y<polja.size()) y++;
		else if(smjer==Smjerovi::Lijevo && y>0) y--;
		else throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje::BlokiranoPosjeceno ||
		polja[x][y]==Polje::BlokiranoPrazno ||
		polja[x][y]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		
	if(polja[x][y]==Polje::Mina) return Status::KrajPoraz;
	bool svi_prazni=true;
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja.size(); j++){
			if(polja[i][j]!=Polje::Prazno){
				svi_prazni=false;
				break;
			}
		}
	}
	if(svi_prazni) return Status::KrajPobjeda;
	return Status::NijeKraj;
	
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja[x][y]=Polje::Posjeceno;
	if(novi_x<0 || novi_x>polja.size() || novi_y<0 || novi_y>polja.size()){
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||
		polja[x][y]==Polje::BlokiranoPrazno ||
		polja[x][y]==Polje::BlokiranoMina)  
			throw std::logic_error("Blokirano polje");
	
	if(polja[novi_x][novi_y]==Polje::Mina) return Status::KrajPoraz;
	bool svi_prazni=true;
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.size(); j++){
			if(polja[i][j]!=Polje::Prazno){
				svi_prazni=false;
				break;
			}
		}
	if(svi_prazni) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	//e za ovu cu se vec napatiti..........
}
int main ()
{
	/*try{ 
		pozovi KreirajIgru
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	catch(std::out_of_range van_opsega){
		std::cout<<van_opsega.what();
	}
	catch(std::logic_error ne_valja_ti_logika){
		std::cout<<ne_valja_ti_logika.what();
	}
	
	*/
	return 0;
}