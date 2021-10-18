#include <iostream>
#include <vector>
#include <stdexcept>

//GLOBALNE DEKLARACIJE 
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
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;


//FUNKCIJE...
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<2;j++){
			if(mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla Tabla1(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i=0; i< mine.size();i++){
		int x=mine[i][0];
		int y=mine[i][1];
		Tabla1[x][y]=Polje::Mina;
	}
	
	return Tabla1;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	
	std::vector<std::vector<int>>  StatusMine(3);
	int i=0;
	for(int X1=x-1;X1<=x+1;X1++){
		for(int Y1=y-1;Y1<=y+1;Y1++){
				int UkupnoMina(0);
			for(int X2=X1-1;X2<=X1+1;X2++){
				for(int Y2=Y1-1;Y2<=Y1+1;Y2++){
					if(X2>=0 && X2< polja.size() && Y2>=0 && Y2<polja.size() && !(X2==X1 && Y2==Y1))																									//------
						if (polja[X2][Y2]==Polje::Mina)
							UkupnoMina++;
				}
				
			}
			
			StatusMine[i].push_back(UkupnoMina);
			
		}
		i++;
	}
	
	return StatusMine;
	
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if(polja[x][y]==Polje::Prazno)
		polja[x][y]=Polje::BlokiranoPrazno;
	else if (polja[x][y]==Polje::Posjeceno)
		polja[x][y]=Polje::BlokiranoPosjeceno; 
	else if (polja[x][y]==Polje::Mina)
		polja[x][y]=Polje::BlokiranoMina;
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if(polja[x][y]==Polje::BlokiranoPrazno)
		polja[x][y]=Polje::Prazno;
	else if (polja[x][y]==Polje::BlokiranoPosjeceno)
		polja[x][y]=Polje::Posjeceno; 
	else if (polja[x][y]==Polje::BlokiranoMina)
		polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	int novi_x;
	int novi_y;
	
	switch(smjer){
		case Smjerovi::GoreLijevo:
			
			novi_x=x-1;novi_y=y-1;
				if(novi_x<0 || novi_x>=polja.size() ||  novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
				if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
				polja[x][y]=Polje::Posjeceno;
			x=novi_x;y=novi_y;
			
			break;
		case Smjerovi::Gore:
			
			novi_x=x-1;
			if( novi_x<0 ||  novi_x>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
			if(polja[novi_x][y]==Polje::BlokiranoPosjeceno ||polja[novi_x][y]==Polje::BlokiranoMina || polja[novi_x][y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=novi_x;
			
			break;
		case Smjerovi::GoreDesno:
			
			novi_x=x-1;novi_y=y+1;
			if(novi_x<0 || novi_x>=polja.size() ||  novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
			if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=novi_x;y=novi_y;		
			break;
		case Smjerovi::Desno: 
			
			novi_y=y+1;
			if( novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
			if(polja[x][novi_y]==Polje::BlokiranoPosjeceno ||polja[x][novi_y]==Polje::BlokiranoMina || polja[x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			y=novi_y;
			break;
		case Smjerovi::DoljeDesno:
				
				novi_x=x+1;novi_y=y+1;
					if(novi_x<0 || novi_x>=polja.size() ||  novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
			if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=novi_x;y=novi_y;
			break;
		case Smjerovi::Dolje:
				
				novi_x=x+1;
				if( novi_x<0 ||  novi_x>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
			if(polja[novi_x][y]==Polje::BlokiranoPosjeceno ||polja[novi_x][y]==Polje::BlokiranoMina || polja[novi_x][y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=novi_x;
			break;
		case Smjerovi::DoljeLijevo:
				
				novi_x=x+1;novi_y=y+1;
					if(novi_x<0 || novi_x>=polja.size() ||  novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
					if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=novi_x;y=novi_y;
			break;
		case Smjerovi::Lijevo:
				
				novi_y=y-1;
					if( novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
					if(polja[x][novi_y]==Polje::BlokiranoPosjeceno ||polja[x][novi_y]==Polje::BlokiranoMina || polja[x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			y=novi_y;
			break;
	}
	
	
	//Provjera novog polja
	if(polja[x][y]==Polje::Mina){
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja[i].size();j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno)
			return Status::NijeKraj;
		else if(polja[x][y]==Polje::Posjeceno){
			bool ImaPrazno(false);
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja.size();j++){
					if(polja[i][j]==Polje::Prazno)
						ImaPrazno=true;
				}
			}
			if(ImaPrazno==true)
				return Status::NijeKraj;
			else
				return Status::KrajPobjeda;
		}
	
}


Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
		if(novi_x<0 || novi_x>=polja.size() ||  novi_y<0 ||  novi_y>=polja.size()) throw std::out_of_range  ("Izlazak van igrace table");
		if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
		
		polja[x][y]=Polje::Posjeceno;
		
		x=novi_x;
		y=novi_y;
		
		if(polja[x][y]==Polje::Mina){
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja[i].size();j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno)
			return Status::NijeKraj;
		else if(polja[x][y]==Polje::Posjeceno){
			bool ImaPrazno(false);
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja.size();j++){
					if(polja[i][j]==Polje::Prazno)
						ImaPrazno=true;
				}
			}
			if(ImaPrazno==true)
				return Status::NijeKraj;
			else
				return Status::KrajPobjeda;
		}
}

void PrijaviGresku (KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(greska== KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	else
		std::cout << "Parametar komande nije ispravan!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	char znak;
	for(;;){
	
		std::cin.get(znak);
		while(znak!='\n' && znak== ' ') std::cin.get(znak);
		if(znak=='K'){
			//Kreiraj
			std::cin.get(znak);
			while(znak!='\n'){
				if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
			}
			komanda=Komande::KreirajIgru;
			return true;
		}
		
		else if( znak=='Z'){
			std::cin.get(znak);
			while(znak!='\n'){
				if((znak>='a' && znak <='z')|| (znak>='A' && znak<='Z')){ greska =KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);		
			}
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		
		else if(znak=='P' && std::cin.peek()=='O'){
			std::cin.get(znak); std::cin.get(znak);
			while(znak!='\n'){
				if((znak >='a' && znak <='z') || (znak >='A' && znak<='Z')){greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
			}
			komanda=Komande::PrikaziOkolinu;
			return true;
		}
		
		else if(znak=='P' && std::cin.peek()=='1'){
			std::cin.get(znak); std::cin.get(znak);
			while(znak!='\n' && znak!='G' && znak!='D' && znak!='L') std::cin.get(znak);
			if(znak=='\n'){greska=KodoviGresaka::NedostajeParametar; return false;}
			else if(znak=='G'){
				if(std::cin.peek()=='L'){
					std::cin.get(znak);std::cin.get(znak);
				while(znak!='\n'){
					if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
					std::cin.get(znak);
				}
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::GoreLijevo;
			return true;
				
				}
				
				else if(std::cin.peek()=='D'){
					std::cin.get(znak);std::cin.get(znak);
			while(znak!='\n'){
				if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
			}
					komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::GoreDesno;
			return true;
			}
			else if(std::cin.peek()==' ' || std::cin.peek()=='\n'){
				std::cin.get(znak);
				while(znak!='\n'){
				if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
			}
					komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Gore;
			return true;
			}
			
			}
			else if(znak=='D'){
				
			if(std::cin.peek()==' ' || std::cin.peek()=='\n'){
				std::cin.get(znak);
				while(znak!='\n'){
					if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
				}
				komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Desno;
			return true;
			}
			else if(std::cin.peek()=='o'){
				std::cin.get(znak);
				if(std::cin.peek()=='D'){
					std::cin.get(znak); std::cin.get(znak);
					while(znak!='\n'){
						if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeDesno;
				}
				else if(std::cin.peek()=='L'){std::cin.get(znak); std::cin.get(znak);
					while(znak!='\n'){
						if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Lijevo;}
				else if(std::cin.peek()==' '|| std::cin.peek()=='\n'){
					std::cin.get(znak);
					while(znak!='\n'){
						if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Dolje;
					return true;
				}
				else {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
			}
			else{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		
		
		
		
		
			
			
			}
			else if(znak=='L'){
					std::cin.get(znak);
			while(znak!='\n'){
				if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				std::cin.get(znak);
			}
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Lijevo;
			return true;
			}
		
			else {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			
		}
		
		
			else if(znak=='P' && std::cin.peek()=='>'){
				int X(0),  Y(0),broj(0);
				while (znak!='\n') {
						if(znak>='0' && znak <='9'){
							broj++;
							if(broj==1){
								while(znak>='0' && znak <='9'){
									X=(int)znak-48;
									if(std::cin.peek()>='0' && std::cin.peek() <='9') X=X*10;
								}}
							else 	if(broj==2){
								while(znak>='0' && znak <='9'){
									Y=(int)znak-48;
									if(std::cin.peek()>='0' && std::cin.peek() <='9') Y=Y*10;
								}
							}
							else if(broj >2 ){greska =KodoviGresaka::SuvisanParametar; return false;}
						}
						if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				}
			komanda=Komande::PomjeriDalje;	x=X;y=Y;return true;
			}
			else if(znak=='B' ){	int X(0),  Y(0),broj(0);
				while (znak!='\n') {
						if(znak>='0' && znak <='9'){
							broj++;
							if(broj==1){
								while(znak>='0' && znak <='9'){
									X=(int)znak-48;
									if(std::cin.peek()>='0' && std::cin.peek() <='9') X=X*10;
								}}
							else 	if(broj==2){
								while(znak>='0' && znak <='9'){
									Y=(int)znak-48;
									if(std::cin.peek()>='0' && std::cin.peek() <='9') Y=Y*10;
								}
							}
							else if(broj >2 ){greska =KodoviGresaka::SuvisanParametar; return false;}
						}
						if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				}
					komanda=Komande::Blokiraj;
							x=X;y=Y;return true;
			}
			else if(znak=='D'  ){	int X(0),  Y(0),broj(0);
				while (znak!='\n') {
						if(znak>='0' && znak <='9'){
							broj++;
							if(broj==1){
								while(znak>='0' && znak <='9'){
									X=(int)znak-48;
									if(std::cin.peek()>='0' && std::cin.peek() <='9') X=X*10;
								}}
							else 	if(broj==2){
								while(znak>='0' && znak <='9'){
									Y=(int)znak-48;
									if(std::cin.peek()>='0' && std::cin.peek() <='9') Y=Y*10;
								}
							}
							else if(broj >2 ){greska =KodoviGresaka::SuvisanParametar; return false;}
						}
						if((znak>='a' && znak <='z') || (znak>='A' && znak<='Z')) {greska=KodoviGresaka::SuvisanParametar; return false;}
				}	komanda=Komande::Deblokiraj;
							x=X;y=Y;return true;
			}
		else {
				greska=KodoviGresaka::PogresnaKomanda; 
				return false;
			
			
		}
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y =0){
	if(komanda==Komande::)
	
}

//MAIN...
int main ()
{
	
	Tabla polja;

	int x(0),y(0);
	Smjerovi smjer;
	Komande cmd;
	KodoviGresaka greska;
	try  {
	for(;;){
		std::cout << "Unesite komandu: ";
	
	
		if(!UnosKomande(cmd,smjer,x,y,greska))
		{	PrijaviGresku(greska); std::cout << "GRESKA" << std::endl;
		std::cin.ignore(10000,'\n');
		}
		
		else {std::cout << "Radi!" << std::endl; IzvrsiKomandu(cmd,polja,x,y,smjer);
	
	
		}
			
	}
	}
	catch(std::runtime_error ){
		std::cout<<"Dovidjenja!";
	}
	
	

	
	return 0;
}