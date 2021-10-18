#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
typedef std::vector<std::vector<int>> Matrica;
enum class Polje {
	Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;
enum class Smjerovi{
	GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class Status{
	NijeKraj,KrajPoraz,KrajPobjeda
};
enum class KodoviGresaka{
	PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar	
};
enum class Komande{
	PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru	
};
Tabla KreirajIgru(int n,Matrica mine){
	
	for(int i(0);i < mine.size();i++)
		if(mine[i].size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
			
	for(int i(0);i < mine.size();i++)
		for(int j(0);j < mine[i].size();j++)
			if(!(mine[i][j] >= 0 && mine[i][j] < n))
				throw std::domain_error("Ilegalne pozicije mina");
			
			
	Tabla ploca(n,std::vector<Polje>(n,Polje::Prazno));
	
	for(int i(0);i < mine.size();i++){
		ploca[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	
	return ploca;
}
bool Razmaci(){
	char znak;
		while(znak = std::cin.get(),znak != '\n'){
				if(znak != ' '  && znak != '\t'){
					return false;
				}
			}
	return true;
}
Matrica PrikaziOkolinu(Tabla ploca,int x,int y){
	
	Matrica okolina(3,std::vector<int>(3,0));
	if(!(x >= 0 && x < ploca.size() && y >= 0 && y < ploca.size()))
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	for(int i(x-1);i < x + 2;i++){
		for(int j(y-1);j < y + 2;j++){
		
		
		for(int k(i-1);k < i + 2;k++){
			for(int l(j-1);l < j+ 2;l++){
				if(!(k >= 0 && k < ploca.size() && l >= 0 && l < ploca.size()) || (k == i && l ==j))
					continue;
				
				if(ploca[k][l] == Polje::Mina){
					okolina[abs(x-i-1)][abs(y-j-1)]++;
				}
				
			}
		}	
		
			
		if(!(i >= 0 && i < ploca.size() && j >= 0 && j < ploca.size()))
			continue;	
		}
	}
	
	
	return okolina;
}

void BlokirajPolje(Tabla &ploca,int x,int y){
	
	if(!(x >= 0 && x < ploca.size() && y >= 0 && y < ploca.size()))
			throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	if(ploca[x][y] == Polje::Prazno)
		ploca[x][y] = Polje::BlokiranoPrazno;
	else if(ploca[x][y] == Polje::Posjeceno)
		ploca[x][y] = Polje::BlokiranoPosjeceno;
	else if(ploca[x][y] == Polje::Mina)
		ploca[x][y] = Polje::BlokiranoMina;
	
	
}

void DeblokirajPolje(Tabla &ploca,int x,int y){
	
	if(!(x >= 0 && x < ploca.size() && y >= 0 && y < ploca.size()))
			throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
			
	if(ploca[x][y] == Polje::BlokiranoPrazno)
		ploca[x][y] = Polje::Prazno;
	else if(ploca[x][y] == Polje::BlokiranoPosjeceno)
		ploca[x][y] = Polje::Posjeceno;
	else if(ploca[x][y] == Polje::BlokiranoMina)
		ploca[x][y] = Polje::Mina;
}
Status Idi(Tabla &ploca,int &pozx,int &pozy,Smjerovi smjer){
	
	bool kraj(true);
	int x(0),y(0);
	
	if(smjer == Smjerovi::GoreLijevo){
		x=pozx-1;y=pozy-1;
	}else if(smjer == Smjerovi::Gore){
		x=pozx-1;y=pozy;
	}else if(smjer == Smjerovi::GoreDesno){
		x=pozx-1;y=pozy+1;
	}else if(smjer == Smjerovi::Desno){
		x=pozx;y=pozy+1;
	}else if(smjer == Smjerovi::DoljeDesno){
		x=pozx+1;y=pozy+1;
	}else if(smjer == Smjerovi::Dolje){
		x=pozx+1;y=pozy;
	}else if(smjer == Smjerovi::DoljeLijevo){
		x=pozx+1;y=pozy-1;
	}else if(smjer == Smjerovi::Lijevo){
		x=pozx;y=pozy-1;
	}
		if(!(x >= 0 && x < ploca.size() && y >= 0 && y < ploca.size()))
			throw std::out_of_range("Izlazak van igrace table");
		if(ploca[x][y] == Polje::BlokiranoPosjeceno || ploca[x][y] == Polje::BlokiranoPrazno || ploca[x][y] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
			
		ploca[pozx][pozy] = Polje::Posjeceno;	
		pozx = x;pozy = y;
		if(ploca[x][y] == Polje::Mina){
			for(int i(0);i < ploca.size();i++){
				for(int j(0);j < ploca[i].size();j++){
					ploca[i][j] = Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		
		for(int i(0);i < ploca.size();i++){
			for(int j(0);j < ploca[i].size();j++){
				if(ploca[i][j] == Polje::Prazno) kraj = false;break;
			}
		}
		
		if(kraj) return Status::KrajPobjeda;
		return Status::NijeKraj;	
		
}

Status Idi(Tabla &ploca,int &pozx,int &pozy,int x,int y){
	
		bool kraj(true);
		if(!(x >= 0 && x < ploca.size() && y >= 0 && y < ploca.size()))
			throw std::out_of_range("Izlazak van igrace table");
		if(ploca[x][y] == Polje::BlokiranoPosjeceno || ploca[x][y] == Polje::BlokiranoPrazno || ploca[x][y] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
			
		ploca[pozx][pozy] = Polje::Posjeceno;	
		pozx = x;pozy = y;
		if(ploca[x][y] == Polje::Mina){
			for(int i(0);i < ploca.size();i++){
				for(int j(0);j < ploca[i].size();j++){
					ploca[i][j] = Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		
		for(int i(0);i < ploca.size();i++){
			for(int j(0);j < ploca[i].size();j++){
				if(ploca[i][j] == Polje::Prazno) kraj = false;break;
			}
		}
		
		if(kraj) return Status::KrajPobjeda;
		return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka a){
	if(a == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!\n";
	else if(a == KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(a == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!\n";
	else if(a == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

/*bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	std::cin >> std::ws;
	char znak;
	
	znak = std::cin.get();
	
	if(znak == 'P'){
		
		
		if(std::cin.peek()=='1'){
			std::string a;
			std::cin.get();
		
			std::getline(std::cin,a);
			
			if(a == "GL"){
				if(Razmaci()){smjer=Smjerovi::GoreLijevo;komanda = Komande::PomjeriJednoMjesto;return true;}
				else greska = KodoviGresaka::NeispravanParametar;return false;
			}else if(a == "G"){
				if(Razmaci()){smjer=Smjerovi::Gore;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;return false;}
			}else if(a == "GD"){
				if(Razmaci()){smjer=Smjerovi::GoreDesno;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;
				return false;}
			}else if(a == "D"){
				if(Razmaci()){smjer=Smjerovi::Dolje;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;return false;}
			}else if(a == "DoD"){
				if(Razmaci()){smjer=Smjerovi::DoljeDesno;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;return false;}
			}else if(a == "Do"){
				if(Razmaci()){smjer=Smjerovi::Dolje;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;return false;}
			}else if(a == "DoL"){
				if(Razmaci()){smjer=Smjerovi::DoljeLijevo;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;return false;}
			}else if(a == "L"){
				if(Razmaci()){smjer=Smjerovi::Lijevo;komanda = Komande::PomjeriJednoMjesto;return true;}
				else {greska = KodoviGresaka::NeispravanParametar;return false;}
				
			}else{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			
		}else if(std::cin.peek() == '>'){
			int A,B;
			std::cin.get();
			std::cin >> A >> B;
			
			if(!std::cin){
				greska=KodoviGresaka::PogresnaKomanda;return false;
			}
			
			if(Razmaci()){
				x=A;
				y=B;
				komanda = Komande::PomjeriDalje;
				return true;
			}else{
				greska=KodoviGresaka::SuvisanParametar;return false;
			}
		}else if(std::cin.peek() == 'O'){
			std::cin.get();
			if(Razmaci()){
				komanda=Komande::PrikaziOkolinu;
				return true;
			}else{
				greska=KodoviGresaka::SuvisanParametar;return false;
			}
			
		}else{
			greska=KodoviGresaka::PogresnaKomanda;return false;
		}
	}else if(znak == 'B' || znak == 'D'){
		int A,B;
		std::cin >> A >> B;
		if(!std::cin){
				greska=KodoviGresaka::PogresnaKomanda;
				
				return false;
			}
		if(Razmaci()){
				x=A;
				y=B;
				if(znak == 'B'){
					komanda=Komande::Blokiraj;
				}else{
					komanda=Komande::Deblokiraj;
				}
				return true;
			}else{
				greska=KodoviGresaka::NeispravanParametar;return false;
			}
		
		
	}else if(znak == 'Z'){
		if(Razmaci()){
			komanda=Komande::ZavrsiIgru;
			return true;
		}else{
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}else if(znak == 'K'){
		if(Razmaci()){
			komanda=Komande::KreirajIgru;
			return true;
		}else{
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}else{
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
}	*/



int main ()
{
	
	Tabla a{{Polje::BlokiranoPrazno,Polje::Posjeceno,Polje::Prazno,Polje::Prazno,Polje::Mina},{Polje::Mina,Polje::Mina,Polje::Prazno,Polje::Mina,Polje::Mina},{Polje::Mina,Polje::Mina,Polje::Prazno,Polje::Mina,Polje::Prazno,},{Polje::Prazno,Polje::Prazno,Polje::Prazno,Polje::Prazno,Polje::Prazno},{Polje::Prazno,Polje::Prazno,Polje::Prazno,Polje::Prazno,Polje::Prazno,}};
	
	
	
	
	return 0;
}