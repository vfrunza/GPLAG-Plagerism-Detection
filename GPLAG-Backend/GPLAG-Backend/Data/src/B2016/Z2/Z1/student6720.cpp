#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iomanip>
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

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla;	
	tabla.resize(n);
	for(int i=0;i<n;i++){
		tabla[i].resize(n);
		std::fill(tabla[i].begin(), tabla[i].end(), Polje(0));
	}
	for(auto kordinata: mine){
		if(!(kordinata.size()==2))
			throw std::domain_error("Ilegalan format zadavanja mina\n");
		if(kordinata[0]<0 || kordinata[1]<0 || kordinata[0]>=n || kordinata[1]>=n)
			throw std::domain_error("Ilegalne pozicije mina\n");
		tabla[kordinata[0]][kordinata[1]]=Polje(2);
	}
	return tabla;
}

int BrojMina(const Tabla &polja, int x, int y){
	if(x<0 || y<0 ||x>=polja.size() || y>=polja[x].size())
		return 0;
	int brojmina{};
	for(int red=x-1;red<=x+1;red++)
		for(int kolona=y-1;kolona<=y+1;kolona++)
			if(!(red<0 || kolona<0 || red>=polja.size() || kolona>=polja[red].size() ||  (red==x && kolona==y) ) && (polja[red][kolona]==Polje(2) || polja[red][kolona]==Polje(5)))
				brojmina++;
	return brojmina;
}                                                
bool DaLiJePobjeda(const Tabla &polja,int x,int y){
	int prazno{};
	for(auto red: polja)
		for(auto polje : red)
			if(polje==Polje::Prazno || polje==Polje::BlokiranoPrazno)
				prazno++;
	if(prazno==1 && (polja[x][y]==Polje::Prazno || polja[x][y]==Polje::BlokiranoPrazno))
		return true;
	return false;
}
Status StatusIgre(Tabla &polja, int x, int y){
	if(polja[x][y]==Polje(2)){
		for(int i=0;i<polja.size();i++)
				std::fill(polja[i].begin(), polja[i].end(), Polje(0));
		return Status::KrajPoraz;
	}
	if(DaLiJePobjeda(polja, x, y)) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
bool RijesiRazmak(char c){
	while(c==' ' && std::cin.peek()==' ')
		c=std::getchar();
	return true;
}
void OcistiInput(){
	std::cin.clear();
	std::cin.ignore(1000,'\n');
}
void UnosMine(std::vector<std::vector<int>> &mine, int br_polja){
	int pozicija{};
		OcistiInput();
	std::cout<<"Unesite pozicije mina: ";
	while(1){
		char c1,c2,c3;
		int p_x,p_y;
		if(std::cin>>c1 && c1=='.' && RijesiRazmak(std::cin.peek()) && std::cin.peek()=='\n'){
			OcistiInput();
			break;
		}
		if(std::cin && c1=='(' && std::cin.peek()!='\n' && std::cin.peek()!=' ' && (std::cin>>p_x && std::cin.peek()!='\n' && std::cin.peek()!=' ') && (std::cin>>c2 && c2==',' && std::cin.peek()!='\n' && std::cin.peek()!=' ') && (std::cin>>p_y && std::cin.peek()!='\n' && std::cin.peek()!=' ') && (std::cin>>c3 && c3==')' && RijesiRazmak(std::cin.peek()) && std::cin.peek()=='\n')){
			if(p_x<0 || p_y<0 || p_x>=br_polja || p_y>=br_polja){
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			mine.resize(pozicija+1);
			mine[pozicija].push_back(p_x);
			mine[pozicija++].push_back(p_y);
			continue;
		}
		OcistiInput();
		std::cout<<"Greska, unesite ponovo!"<<std::endl;
		continue;
	}
}
void Kraj(Tabla &polja, Status status){
	if(status==Status::KrajPobjeda)
		std::cout<<"Bravo, obisli ste sva sigurna polja\n";
	if(status==Status::KrajPoraz)
		std::cout<<"Nagazili ste na minu\n";
	if(status==Status::KrajPobjeda || status==Status::KrajPoraz){
		for(int i=0;i<polja.size();i++)
				std::fill(polja[i].begin(), polja[i].end(), Polje(0));
		throw std::runtime_error ("Igra zavrsena\n");
	}
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || y<0 ||x>=polja.size() || y>=polja[x].size())
		throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji\n");
	
	std::vector<std::vector<int>> okolina(3, std::vector<int> (3));
	for(int red=x-1, i=0;red<=x+1;red++,i++)
		for(int kolona=y-1, j=0;kolona<=y+1;kolona++,j++)
			okolina[i][j]=BrojMina(polja, red, kolona);
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 ||x>=polja.size() || y>=polja[x].size())
		throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji\n");
	if(polja[x][y]<Polje(3))
		polja[x][y]=Polje((int)polja[x][y]+3);
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 ||x>=polja.size() || y>=polja[x].size())
		throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji\n");
	if(polja[x][y]>=Polje(3))
		polja[x][y]=Polje((int)polja[x][y]-3);
}

void BaciIzuzetak(Tabla &polja, int x, int y){
	if((int)(polja.at(x)).at(y)>=3)
		throw std::logic_error("Blokirano polje\n");
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	try{
		int temp_x{x}, temp_y{y};
		if((int)smjer<=2) temp_x--;
		if((int)smjer>=4 && (int)smjer<=6) temp_x++;
		if((int)smjer>=2 && (int)smjer<=4) temp_y++;
		if((int)smjer>=6 || (int)smjer==0) temp_y--;
		BaciIzuzetak(polja, temp_x, temp_y);
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno){
			polja[x][y]=Polje::BlokiranoPosjeceno;
		}else{
			polja[x][y]=Polje::Posjeceno;
		}
		x=temp_x; y=temp_y;
		return StatusIgre(polja, x, y);
	} catch(std::out_of_range){
			throw std::out_of_range("Izlazak van igrace table\n");
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	try{
		BaciIzuzetak(polja,novi_x, novi_y);
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno){
			polja[x][y]=Polje::BlokiranoPosjeceno;
		}else{
			polja[x][y]=Polje::Posjeceno;
		}
		x=novi_x; y=novi_y;
		return StatusIgre(polja, x, y);
	} catch(std::out_of_range){
		throw std::out_of_range("Izlazak van igrace table\n");
	}
}

void PrijaviGresku(KodoviGresaka kod){
	if(kod==KodoviGresaka::PogresnaKomanda)
		std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(kod==KodoviGresaka::NedostajeParametar)
		std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(kod==KodoviGresaka::NeispravanParametar)
		std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(kod==KodoviGresaka::SuvisanParametar)
		std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::cin.clear();
	std::vector<std::string> komande{"P1","P>","B","D","PO","Z","K"},slova{"B","D","Z","K"}, smjerovi{"GL","G","GD","D","DoD","Do","DoL","L"};
	std::string temp_komanda, temp_smjer;
	int temp_x,temp_y;
	if(std::cin>>std::setw(1)>>temp_komanda && ((temp_komanda=="P" && (std::cin.peek()=='1' || std::cin.peek()=='>' || std::cin.peek()=='O')) || find(slova.begin(), slova.end(), temp_komanda)!=slova.end())){
		if(temp_komanda=="P"){
			char slovo2=getchar();
			temp_komanda.push_back(slovo2);
		}
		auto element_kom=find(komande.begin(),komande.end(),temp_komanda);	
		
		if(element_kom>komande.begin()+3 && element_kom<komande.end()){
			if(RijesiRazmak(std::cin.peek()) && std::cin.peek()!='\n'){
				OcistiInput();
				greska=KodoviGresaka::SuvisanParametar; return false;
			}
			komanda=Komande(element_kom-komande.begin());
			return true;
		}
		
		if(RijesiRazmak(std::cin.peek()) && std::cin.peek()!='\n' ){
			
			if(element_kom==komande.begin() && std::cin>>temp_smjer && RijesiRazmak(std::cin.peek())){
				auto p_smjerovi=find(smjerovi.begin(),smjerovi.end(), temp_smjer);
				if(p_smjerovi==smjerovi.end()){
					OcistiInput();
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				if(std::cin.peek()!='\n'){OcistiInput();greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi(p_smjerovi-smjerovi.begin());
				komanda=Komande(element_kom-komande.begin());
				return true;
			}
			
			if(element_kom>komande.begin() && element_kom<=komande.begin()+3 && std::cin>>temp_x && std::cin.peek()==' ' && RijesiRazmak(std::cin.peek()) && std::cin.peek()!='\n' && std::cin>>temp_y && RijesiRazmak(std::cin.peek())){
				if(std::cin.peek()!='\n'){OcistiInput();greska=KodoviGresaka::SuvisanParametar; return false;}
				x=temp_x; y=temp_y;
				komanda=Komande(element_kom-komande.begin());
				return true;
			}else{if(std::cin.peek()=='\n'){OcistiInput();greska=KodoviGresaka::NedostajeParametar; return false;}}
			
		}else{OcistiInput();greska=KodoviGresaka::NedostajeParametar; return false;}
		
		OcistiInput();
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}
	OcistiInput();
	greska=KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	Status status;
	try{
	switch(komanda){
		case Komande(0):
			status=Idi(polja, x,y, p_smjer);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			Kraj(polja, status);
			break;
		case Komande(1):
			status=Idi(polja,x,y,p_x,p_y);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			Kraj(polja, status);
			break;
		case Komande(2):
			BlokirajPolje(polja,p_x,p_y);
			break;
		case Komande(3):
			DeblokirajPolje(polja,p_x,p_y);
			break;
		case Komande(4):
			for(auto red: PrikaziOkolinu(polja,x,y)){
				for(auto mina:red)
					std::cout<<mina<<" ";
				std::cout<<std::endl;
			}
			break;
		case Komande(5):
			for(int i=0;i<polja.size();i++)
				std::fill(polja[i].begin(), polja[i].end(), Polje(0));
			throw std::runtime_error ("\nIgra zavrsena");
		case Komande(6):
			std::cout<<"Unesite broj polja: ";
			int br_polja;
			std::cin>>br_polja;
			std::vector<std::vector<int>> mine;
			UnosMine(mine, br_polja);
			polja=KreirajIgru(br_polja,mine);
			break;
	}
	}catch(std::domain_error izuzetak){std::cout<<izuzetak.what();}
	catch(std::out_of_range izuzetak){std::cout<<izuzetak.what();}
	catch(std::logic_error izuzetak){std::cout<<izuzetak.what();}	
}






























int main (){
	
	bool war{1};
	
	Komande komanda; Smjerovi smjer; Status status=Status::NijeKraj; KodoviGresaka greska; Tabla polja;
	int x{},y{},p_x,p_y;
	
	while(status==Status::NijeKraj){
		std::cout<<"Unesite komandu: ";
		while(!(UnosKomande(komanda,smjer,p_x,p_y,greska))){
			PrijaviGresku(greska);
			std::cout<<"Unesite komandu: ";
		}
		try{
		IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
		}
		catch(std::runtime_error izuzetak){break;}
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
















































