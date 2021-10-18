/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector> 
#include <stdexcept>
#include <string>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeipravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2)
		 throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<mine[i].size(); j++){
			if(mine[i][j]>=n || mine[i][j]<=0)
			  throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	Tabla igra(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<n; i++){
	  for(int j=0; j<n; j++){
	  	for(int k=0; k<mine.size();k++){
	  		if(i==mine[k][0] && j==mine[k][1])
	  		  igra[i][j] = Polje::Mina;
	  	}
	  }
	}
return igra;
}




void BlokirajPolje (Tabla &polja, int x, int y){
	if(x>polja.size() || x<0 || y>polja.size() || y<0){
		std::string s("Polje (");
		s+=std::to_string(x);
		s+=",";
		s+=std::to_string(y);
		s+=") ne postoji";
		throw std::domain_error(s);
	}
	
	int a = int(polja[x][y]);
	if(a<3){
		a+=3;
		polja[x][y] = Polje(a);
	}
}

void DeblokirajPolje (Tabla &polja, int x, int y){
	if(x>polja.size() || x<0 || y>polja.size() || y<0){
		std::string s("Polje (");
		s+=std::to_string(x);
		s+=",";
		s+=std::to_string(y);
		s+=") ne postoji";
		throw std::domain_error(s);
	}
	int a = int(polja[x][y]);
	if(a>=3){
		a-=3;
		polja[x][y] = Polje(a);
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int matrica[8][2] = { {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1} };
	for(int i=0; i<8; i++){
		if(int(smjer)==i){
			int a = x + matrica[i][0];
			int b = y + matrica[i][1];
			if(a>=polja.size() || a<0 || b>=polja.size() || b<0)
			  throw std::out_of_range("Izlazak van igrace table");
			else if(int(polja[a][b])>=3)
			  throw std::logic_error("Blokirano polje");
			else{
				polja[x][y] = Polje::Posjeceno;
				x = a;
				y = b;
				if(polja[x][y]==Polje::Mina)
				  return Status::KrajPoraz;
			}
		break;
		}
		
	}
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja.size(); j++){
			if(polja[i][j]==Polje::Prazno)
			  return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x>=polja.size() || novi_x<0 || novi_y>=polja.size() || novi_y<0)
	  throw std::out_of_range("Izlazak van igrace table");
	if(int(polja[novi_x][novi_y])>=3)
	  throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	if(polja[x][y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++)
		  for(int j=0; j<polja.size(); j++)
		    polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	for(int i=0; i<polja.size(); i++)
	  for(int j=0; j<polja.size(); j++){
	  	 if(polja[i][j] == Polje::Prazno)
	  	   return Status::NijeKraj;
	  }
	return Status::KrajPobjeda;
}


bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::vector<std::string> komande{"P1", "P>", "B", "D", "PO", "Z", "K"} ;
	std::string s;
	std::getline(std::cin, s);
	for(int i=0; i<s.length(); i++)
	  if(s[i]==' ')
	    s.erase(s.begin() + i);
	int i(0);
	for(i=0; i<komande.size(); i++){
		if(komande[i]==s){
			komanda = Komande(i);
			break;
		}
	}
	if(i==komande.size()){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(s=="P1"){
		std::vector<std::string> prvi_parametar{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
		std::string s2;
		std::getline(std::cin, s2);
		for(int i=0; i<s2.length(); i++){
			if(s2[i]==' ')
			  s2.erase(s2.begin() +i);
		}
		int i(0);
		for(int i=0; i<8; i++){
			if(prvi_parametar[i]==s2){
				smjer = Smjerovi(i);
				return true;
			}
		}
		if(i==prvi_parametar.size()){
			if(s2.size()==0)
			  greska = KodoviGresaka::NedostajeParametar;
			else
			  greska = KodoviGresaka::SuvisanParametar;
		}
	}
	for(int i=1; i<=3; i++){
		if(s==komande[i]){
			komanda = Komande(i);
			int a, b;
			std::cin>>a>>b;
			x = a; y = b;
			return true;
		}
	}
	for(int i=4; i<7; i++){
		if(s==komande[i]){
			komanda = Komande(i);
			return true;
		}
	}
	return false;
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande(0)){
		auto s(Idi(polja, x, y, p_smjer));
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
		if(s==Status(1)){
			std::cout<<"Nagazili ste na minu";
			IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, p_smjer, p_x, p_y);
			return;
		}
		if(s==Status(2)){
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y , p_smjer, p_x, p_y);
			return;
		}
		
	}
	if(komanda==Komande(1)){
		auto k(Idi(polja, x, y, p_x, p_y));
		std::cout<<"Trenutna pozicija igraca je ("<<x<<","<<y<<")";
		if(k==Status(1)){
			std::cout<<"Nagazili ste na minu";
			IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			return;
		}
		if(k==Status(2)){
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			return;
		}
	}
	if(komanda==Komande(2)){
		BlokirajPolje(polja, p_x, p_y);
		return;
	}
	if(komanda==Komande(3)){
		DeblokirajPolje(polja, p_x, p_y);
		return;
	}
	if(komanda==Komande(4)){
		auto v(PrikaziOkolinu(polja, x, y));
		for(int i=0; i<v.size(); i++){
		  for(int j=0; j<v[i].size(); j++)
		    std::cout<<v[i][j]<<" ";
		 std::cout<<std::endl;
		}  
		return;
	}
	if(komanda==Komande(5)){
		for(int i=0; i<polja.size(); i++)
		  for(int j=0; j<polja.size(); j++)
		    polja[i][j] = Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
/*	if(komanda==Komande(6)){
		KreirajIgru(0, )
	}*/
}




int main ()
{
	try{
		//std::std::vector<T> ;
	}
	catch(...){
		
	}
	return 0;
}