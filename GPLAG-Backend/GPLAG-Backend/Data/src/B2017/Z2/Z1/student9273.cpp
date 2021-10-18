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
 #include <string>
 
enum class Polje{
 	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina 
 };

enum class Smjerovi{
	GoreLijevo,Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka{
	PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar	
};

enum class Komande{
	PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla ;

Tabla KreirajTablu(int n){
	Tabla Kreirana;
	std::vector<Polje> pomocna ;
	if(n<=0) throw std::domain_error("Ilegalna veličina");
	Polje opcija = Polje::Prazno;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j<n; j++){
			pomocna.push_back(opcija);
		}
		Kreirana.push_back(pomocna);
		pomocna.clear();
	}
return Kreirana;
}

void IspisiTablu(Tabla a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.at(0).size();j++){
			if(a.at(i).at(j) == Polje::Prazno)
				std::cout << "0" <<" ";
			else if(a.at(i).at(j)==Polje::Mina)
				std::cout << "1 ";	
			else if(a.at(i).at(j)==Polje::Posjeceno)
			std::cout << "2 ";
			else if(a.at(i).at(j)==Polje::BlokiranoPrazno)
			std::cout << "3 ";
			else if(a.at(i).at(j)==Polje::BlokiranoMina)
			std::cout << "4 " ;
			else if (a.at(i).at(j)==Polje::BlokiranoPosjeceno)
			std::cout << "5 " ;
		}
		std::cout<< std::endl;
	}
}

Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine){
	Tabla Kreirana=KreirajTablu(n);
	Polje mina=Polje::Mina;
	for (int i = 0; i < mine.size(); i++) {
		if(mine.at(i).size()>2 || mine.at(i).size()<2) throw std::domain_error("Ilegalan format zadavanja mina");
		int	pozicija_1=mine.at(i).at(0);
		int pozicija_2=mine.at(i).at(1);
		if(pozicija_1>(n-1) || pozicija_2>(n-1)) throw std::domain_error("Ilegalne pozicije mina");
	
		Kreirana.at(pozicija_1).at(pozicija_2)=mina;
	}
	
	return Kreirana;
}

int SumaMina(Tabla poslana,int x,int y){
	int suma(0);
	int start_x=x-1;
	if(start_x<0) start_x+=1;
	int start_y=y-1;
	if(start_y<0) start_y+=1;
	int end_x=x+1;
	if(end_x>poslana.size()-1) end_x-=1;
	int end_y=y+1;
	if(end_y>poslana.size()-1) end_y-=1;
	for(int i = start_x ; i <= end_x ; i++){
		for(int j = start_y ; j <= end_y ; j++){
				if(poslana.at(i).at(j)==Polje::Mina && !(i == x && j == y))
				suma+=1;
		}
	}
	return suma;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja,int x,int y){
	Tabla TriSaTri;
	if(x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size()) throw std::domain_error("Polje ("+ x + ','+ y + ') ne postoji');
	int start_x=x-1;
	int start_y=y-1;
	int end_x=x+1;
	int end_y=y+1;
	std::vector<int> vek_suma;
	std::vector<std::vector<int>> okolni;
	
	std::vector<Polje>pomocni ;
	for(int i=start_x;i<=end_x;i++){
		for(int j=start_y;j<=end_y;j++){
			vek_suma.push_back(SumaMina(polja, i, j));
		}
		okolni.push_back(vek_suma);
		vek_suma.clear();
	}
	/*
	for(int i = 0; i < TriSaTri.size() ; i++){
		for(int j = 0; j < TriSaTri.at(0).size(); j++){
			vek_suma.push_back(SumaMina(TriSaTri,i,j));
		}
		okolni.push_back(vek_suma);
		vek_suma.clear();
	}
	*/
	return okolni;
}


void BlokirajPolje(Tabla &polja,int x,int y){

		if(x<0 || y<0 || x>=polja.size() || y>=polja.size()){
			throw std::domain_error("Polje ("  + x +   ','   + y +  ') ne postoji');
		}
		else{
					if(polja.at(x).at(y)==Polje::Prazno){
						polja.at(x).at(y)=Polje::BlokiranoPrazno;
					}
					else if(polja.at(x).at(y)==Polje::Posjeceno){
						polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
					}
					else if(polja.at(x).at(y)==Polje::Mina){
						polja.at(x).at(y)=Polje::BlokiranoMina;
					}
		}
}

void DeblokirajPolje(Tabla &polja,int x,int y){

	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno)
		polja.at(x).at(y)=Polje::Posjeceno;
	
	else if(polja.at(x).at(y)==Polje::BlokiranoPrazno)
		polja.at(x).at(y)=Polje::Prazno;
	else if(polja.at(x).at(y)==Polje::BlokiranoMina)
		polja.at(x).at(y)=Polje::Mina;
}
 
bool DaLiJePobjeda(Tabla &polja){
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja.at(0).size(); j++){
			if(polja.at(i).at(j)==Polje::Prazno)
				return false;
		}
	}
	return true;
}

Status Idi(Tabla &polja,int &x,int &y, Smjerovi smjer){
	 
	 int temp_x, temp_y;
	 temp_x = x;
	 temp_y = y;
	 
	 	switch(smjer){
	 		case Smjerovi::GoreLijevo: {
	 			x--;
	 			y--;
	 			break;
	 		}
	 		case Smjerovi::Gore:{
	 			x--;
	 			break;
	 		}
	 		case Smjerovi::GoreDesno:{
	 			x--;
	 			y++;
	 			break;
	 		}
	 		case Smjerovi::Desno:{
	 			y++;
	 			break;
	 		}
	 		case Smjerovi::DoljeDesno:{
	 			x++;
	 			y++;
	 			break;
	 		}
	 		case Smjerovi::Dolje:{
	 			x++;
	 			break;
	 		}
	 		case Smjerovi::DoljeLijevo:{
	 			y--;
	 			x++;
	 			break;
	 		}
	 		case Smjerovi::Lijevo:{
	 			y--;
	 			break;
	 		}
	 	}
	
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.at(0).size()-1){
		x=temp_x;
		y=temp_y;
			
		throw std::out_of_range("Izlazak van igrace table");
	
	}
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoMina) {
		x=temp_x;
		y=temp_y;
		
		throw std::logic_error("Blokirano polje");
	
	}
	
	if(polja.at(x).at(y)==Polje::Mina)
		return Status::KrajPoraz;
	else polja.at(x).at(y)=Polje::Posjeceno;
	
	if(DaLiJePobjeda(polja)) return Status::KrajPobjeda;
	return Status::NijeKraj;
}


Status Idi(Tabla &polja,int &x,int &y, int novi_x, int novi_y){
	
	 
	 if(novi_x<0 || novi_x>polja.size()-1 || novi_y<0 ||novi_y>polja.size()) throw std::out_of_range("Izlazak van igrace table");
	 if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	 
	 x=novi_x;
	 y=novi_y;
	 
	 if(polja.at(x).at(y)==Polje::Mina)
	 	return Status::KrajPoraz;
	 else polja.at(x).at(y)=Polje::Posjeceno;
	 
	 if(DaLiJePobjeda(polja)) return Status::KrajPobjeda;
	 return Status::NijeKraj;	
	 
} 

void IspisiStatus( Status status){
	switch(status){
		case Status::KrajPoraz: {
			std::cout << "Poraz" << std::endl;
			break;
		}
		case Status::KrajPobjeda:{
			std::cout << "Pobjeda" << std::endl;
			break;
		}
		case Status::NijeKraj:{
			std::cout << "Nije kraj" << std::endl;
			break;
		}
	}	
}

void PrijaviGresku(KodoviGresaka greske){
	switch(greske){
		case KodoviGresaka::PogresnaKomanda:{
			std::cout << "Nerazumljiva komanda!" << std::endl;
			break;
		}
		case KodoviGresaka::NedostajeParametar:{
			std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
			break;
		}
		case KodoviGresaka::NeispravanParametar:{
			std::cout << "Parametar komande nije ispravan!" << std::endl;
			break;
		}
		case KodoviGresaka::SuvisanParametar:{
			std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
			break;
		}
	} 
}
bool DaLiJeBroj(char c){
	if(c>='0' && c<='9')
		return true;
	return false;
}


bool ProvjeraStringa(std::string s, Komande &komanda, Smjerovi &smjer,int &x,int &y, KodoviGresaka &greska){
	int duzina=s.length();	
	switch(s.at(0)){
		case 'P':{
			switch(s.at(1)){
				case '>':{
					if(duzina==4){
						if(DaLiJeBroj(s.at(2)) && DaLiJeBroj(s.at(3)))
						{
							x=s.at(2)-'0';
						//	*y=std::stoi(s.at(3));
							y=s.at(3)-'0';
							komanda=Komande::PomjeriJednoMjesto;
						}
					}
					break;
				}
				
				case '1':{
					if(duzina>=3 && duzina<=5){
						if(s.substr(2,(duzina-2))=="GD"){
								smjer=Smjerovi::GoreDesno;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="GL"){
								smjer=Smjerovi::GoreLijevo;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="G"){
								smjer=Smjerovi::Gore;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="DoD"){
								smjer=Smjerovi::DoljeDesno;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="Do"){
								smjer=Smjerovi::Dolje;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="DoL"){
								smjer=Smjerovi::DoljeLijevo;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="L"){
								smjer=Smjerovi::Lijevo;
								komanda=Komande::PomjeriDalje;
								break;
							}
						else if(s.substr(2,(duzina-2))=="D"){
								smjer=Smjerovi::Desno;
								komanda=Komande::PomjeriDalje;
								break;
							}
							
						else{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
							break;
						}
					}
				}
				case 'O':{
					komanda=Komande::PrikaziOkolinu;
					break;
				}
				default:{
					greska=KodoviGresaka::PogresnaKomanda;
					break;
				}
			}
			
		}
			
		case 'B':{
			if(duzina==3){
				if(DaLiJeBroj(s.at(1)) && DaLiJeBroj(s.at(2))){
					x=s.at(1)-'0';
					y=s.at(2)-'0';
					komanda=Komande::Blokiraj;
				}
			}
			break;
		}
		case 'Z':{
			komanda=Komande::ZavrsiIgru;
			break;
		}
		case 'K':{
			komanda=Komande::KreirajIgru;
			break;
		}
		case 'D':{
			if(duzina==3){
				if(DaLiJeBroj(s.at(1)) && DaLiJeBroj(s.at(2))){
					x=s.at(1)-'0';
					y=s.at(2)-'0';
					komanda=Komande::Deblokiraj;
				}
			}
			break;
		}
		default:{
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
			break;
		}
		
	}
	return true;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer,int &x,int &y, KodoviGresaka &greska){
	std::string novi;
	std::string temp;
	std::string uneseni_s;
	std::getline(std::cin,uneseni_s);
	for(int i=0;i<uneseni_s.length();i++){
		if(uneseni_s.at(i)!=' ') temp.push_back(uneseni_s.at(i));	
	}
	if(ProvjeraStringa(temp,komanda,smjer,x,y,greska)){
		return true;
	}
	return false;
}

void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y, Smjerovi p_smjer=Smjerovi::Gore,int p_x=0, int p_y=0){
		switch(komanda){
			case Komande::PomjeriDalje:{
				if(Idi(polja,x,y,p_smjer)==Status::KrajPoraz) std::cout<<"Nagazili ste na minu";
				else std::cout << "Bravo obisli ste sva sigurna polja";
				break;
			}
			case Komande::PomjeriJednoMjesto:{
				if(Idi(polja,x,y,p_x,p_y)==Status::KrajPoraz) std::cout << "Nagazili ste na minu";
				else std::cout << "Bravo obisli ste sva sigurna polja";
				break;
			}
			case Komande::Blokiraj:{
				BlokirajPolje(polja,x,y);
				break;
			}
			case Komande::Deblokiraj:{
				DeblokirajPolje(polja,x,y);
				break;
			}
			case Komande::PrikaziOkolinu:{
				PrikaziOkolinu(polja,x,y);
				break;	
			}
			
				
			default:{
				break;
			}
		}
}

int main ()
{
	int n;
	std::vector<std::vector<int>> pozicije_mina;
	std::cout << "Unesite broj polja: " ;
	std::cin >> n;
	while(!n){
		std::cout << "Greska, unesite ponovo!" << std::endl;
		std::cout << "Unesite broj polja: " ;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		
		std::cin>>n;
	}
	
	
/*	std::vector<std::vector<int>> pozicije{{0,0},{1,1},{2,1},{4,4}} ;
	Tabla moja;
	IspisiTablu(KreirajIgru(5,pozicije));
	moja=KreirajIgru(5,pozicije);
	std::cout <<"Suma  "<< SumaMina(KreirajIgru(5,pozicije),4,4) << std::endl;
	
	std::vector<std::vector<int>> okolni=PrikaziOkolinu(moja,2,2);
	std::cout << "okolni" << std::endl;
	for (int i = 0; i < okolni.size(); i++) {
		for(int j=0; j< okolni.at(i).size(); j++){
			std::cout <<okolni.at(i).at(j);
		}
	}
	//Smjer opcija=Smjer::Lijevo;
	 BlokirajPolje(moja,2,2);
	 IspisiTablu(moja);
	 std::cout<<std::endl;
	 DeblokirajPolje(moja,2,2);
	 IspisiTablu(moja);
	 int pozicija(4);
	 try{
	 if(Idi(moja,pozicija,pozicija,Smjerovi::Desno)==Status::KrajPoraz) std::cout<<"Poraz";
	 else  std::cout<<"Nije poraz";
	 }
	 catch(std::exception &e){
	 	std::cout<<e.what();
	 }
	int x=2;
	int y=2;
	int s=2;
	int d=1;
	IspisiStatus(Idi(moja,x,y,s,d));
	*/
	 
	return 0;
}