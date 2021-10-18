#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::domain_error;
using std::logic_error;
using std::out_of_range;
using std::runtime_error;


enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina  };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef vector<vector<Polje>> Tabla;

//Dodatne funkcije
int StrToInt(string unos_komande, int &temp, bool &koo){
	int koordinata=1, suma=0, i=temp;
	while(unos_komande.at(temp)<='9' && unos_komande.at(temp)>='0')temp++;
	int temp2=temp;
	if(unos_komande.at(temp)!=' ' && temp!=unos_komande.size()-1){
		koo=false;
		return 0;
	}
	temp--;
	while(i!=temp){
		suma+=(unos_komande.at(temp)-'0') *koordinata;
		koordinata*=10;
		temp--;
	}
	koo=true;
	temp=temp2;
	return suma;
	
}
int StrToInt2(string unos){
	int koordinata=1, suma=0, temp=0;
	while(temp!=unos.size()-1){
		suma+=(unos.at(temp)-'0') *koordinata;
		koordinata*=10;
		temp++;
	}
	return suma;
	
}
int Izvidnica(Tabla polja, int x, int y){
	int br_mina=0;
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			if(i<0 || j<0 || i>polja.size() || j>polja.size())continue;
			if(i==x && j==y)continue;
			if(polja.at(i).at(j)==Polje::Mina)br_mina++;
		}
	}
	return br_mina;
}
//Neophodne funkcije
Tabla KreirajIgru(int n, const vector<vector<int>> &mine){
		//BACANJE IZUZETAKA
	if(n<=0) throw domain_error("Ilegalna veličina");
	for(int i=0; i<mine.size(); i++){
		if(mine.at(i).size()!=2) throw domain_error("Ilegalan format zadavanja mina.");
		for(int j=0; j<mine.at(i).size(); j++){
			if(mine.at(i).at(j)>n-1 || mine.at(i).at(j)<0) throw domain_error("Ilegalne pozicije mina");
		}
	}
	//AKO NE BACI IZUZETAK
	Tabla tabla_za_igru;
	tabla_za_igru.resize(n);
	for(int i=0; i<tabla_za_igru.size(); i++) tabla_za_igru.at(i).resize(n);
	//UBACIVANJE MINA U TABLU
	for(int i=0; i<mine.size(); i++){
		tabla_za_igru.at(mine.at(i)[0]).at(mine.at(i)[1])=Polje::Mina;	
	}
	
	return tabla_za_igru;
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	vector<vector<int>> okolina(3, vector<int>(3, 0));
	if(x<0 || y<0 || x>polja.size() || y>polja.size()) throw domain_error("Polje x, y ne postoji");
	//PROVJERA OKOLINE
	int temp=y;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			okolina.at(i).at(j)=Izvidnica(polja, x-1, y-1);
			y++;
			if(x<0 || y<0 || x>polja.size() || y>polja.size()) continue;
		}
		y=temp;
		x++;
		if(x<0 || y<0 || x>polja.size() || y>polja.size()) continue;
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw domain_error("Polje (x,y) ne postoji");
	else if(polja.at(x).at(y)==Polje::Mina)polja.at(x).at(y)=Polje::BlokiranoMina;
	else if(polja.at(x).at(y)==Polje::Prazno)polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y)==Polje::Posjeceno)polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno)polja.at(x).at(y)=Polje::Prazno;
	if(polja.at(x).at(y)==Polje::BlokiranoMina)polja.at(x).at(y)=Polje::Mina;
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno)polja.at(x).at(y)=Polje::Posjeceno;
}
void PrijaviGresku(KodoviGresaka info){
	if(info==KodoviGresaka::PogresnaKomanda) cout<<"Nerazumljiva komanda!";
	else if(info==KodoviGresaka::NedostajeParametar) cout<<"Komanda trazi parametar koji nije naveden!";
	else if(info==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan!";
	else if(info==KodoviGresaka::SuvisanParametar) cout<<"Zadan je suvisan parametar nakon komande!";
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja.at(x).at(y)=Polje::Posjeceno;
	//GORNJI RED
	if(smjer==Smjerovi::GoreLijevo){
		x--;
		y--;
	}
	if(smjer==Smjerovi::Gore)	x--;
	if(smjer==Smjerovi::GoreDesno){
		x--;
		y++;
	}
	//STRANE
	if(smjer==Smjerovi::Desno) y++;
	if(smjer==Smjerovi::Lijevo) x--;
	//DONJI RED
	if(smjer==Smjerovi::DoljeDesno){
		x++;
		y++;
	}
	if(smjer==Smjerovi::Dolje) x++;
	if(smjer==Smjerovi::DoljeLijevo){
		x--;
		y++;
	}
	
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw out_of_range("Izlazak van igrace table");
	if(polja.at(x).at(y)==Polje::BlokiranoMina || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	bool da_li_je_kraj=false;
	for(int i=0; i<polja.size(); i++){
		da_li_je_kraj=false;
		for(int j=0; j<polja.size(); j++){
			if(polja.at(i).at(j)==Polje::Posjeceno)da_li_je_kraj=true;
		}
	}
	
	if(da_li_je_kraj) return Status::KrajPobjeda;
	else return Status::NijeKraj;
	if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw out_of_range("Izlazak van igrace table");
	if(polja.at(x).at(y)==Polje::BlokiranoMina || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	bool da_li_je_kraj=false;
	for(int i=0; i<polja.size(); i++){
		da_li_je_kraj=false;
		for(int j=0; j<polja.size(); j++){
			if(polja.at(i).at(j)==Polje::Posjeceno)da_li_je_kraj=true;
		}
	}
	
	if(da_li_je_kraj) return Status::KrajPobjeda;
	else if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
	else return Status::NijeKraj;
}

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	string unos_komande;
	getline(cin, unos_komande);
	unos_komande.push_back(' ');
	int temp=0;
	while(unos_komande.at(temp)!=unos_komande.size()-1){
		while(unos_komande.at(temp)==' ')temp++;
		//Komanda P1
		if(unos_komande.at(temp)=='P' && unos_komande.at(temp+1)=='1'){
			temp+=2;
			while(unos_komande.at(temp)==' ')temp++;
			if(unos_komande.at(temp)=='G' && unos_komande.at(temp+1)=='L'){
				temp+=2;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::GoreLijevo;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
			}
		if(unos_komande.at(temp)=='G' && unos_komande.at(temp+1)=='D'){
				temp+=2;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::GoreDesno;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		}
		
		if(unos_komande.at(temp)=='D' && unos_komande.at(temp+1)=='o' && unos_komande.at(temp+2)=='L'){
				temp+=3;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::DoljeLijevo;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		
		}
		if(unos_komande.at(temp)=='D' && unos_komande.at(temp+1)=='o' && unos_komande.at(temp+2)=='D'){
				temp+=2;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::DoljeDesno;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		}
		
		if(unos_komande.at(temp)=='D' && unos_komande.at(temp+1)=='o'){
				temp+=2;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::Dolje;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		}
		
		if(unos_komande.at(temp)=='D'){
				temp++;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::Desno;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		}
		
		if(unos_komande.at(temp)=='L'){
				temp++;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::Lijevo;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		}
		
		if(unos_komande.at(temp)=='G'){
				temp++;
				while(unos_komande.at(temp)==' ')temp++;
				if(temp!=unos_komande.size()-1){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				else{
					smjer=Smjerovi::Gore;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
					
				}
		}
		
		}
		//Komanda P>
		else if(unos_komande.at(temp)=='P' && unos_komande.at(temp+1)=='>'){
			temp=+2;
			while(unos_komande.at(temp)==' ')temp++;
			bool koo1, koo2;
			int x1=StrToInt(unos_komande, temp, koo1);
			while(unos_komande.at(temp)==' ')temp++;
			if(temp==unos_komande.size()-1) greska=KodoviGresaka::NedostajeParametar;
			if((unos_komande.at(temp)>'9' || unos_komande.at(temp)<'0' || unos_komande.at(temp)!=' ')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			int y1=StrToInt(unos_komande, temp, koo2);
			while(temp!=unos_komande.size()-1){
				if(unos_komande.at(temp)!=' '){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			
		}
		//Komanda D
		else if(unos_komande.at(temp)=='D'){
			temp++;
			while(unos_komande.at(temp)==' ')temp++;
			bool koo1, koo2;
			int x1=StrToInt(unos_komande, temp, koo1);
			while(unos_komande.at(temp)==' ')temp++;
			if(temp==unos_komande.size()-1) greska=KodoviGresaka::NedostajeParametar;
			if((unos_komande.at(temp)>'9' || unos_komande.at(temp)<'0' || unos_komande.at(temp)!=' ')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			int y1=StrToInt(unos_komande, temp, koo2);
			while(temp!=unos_komande.size()-1){
				if(unos_komande.at(temp)!=' '){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			if(koo1 && koo2){
				x=x1;
				y=y1;
				komanda=Komande::Deblokiraj;
				return true;
			}
			
		}
		//Komanda B
		else if(unos_komande.at(temp)=='B'){
			temp++;
			while(unos_komande.at(temp)==' ')temp++;
			bool koo1, koo2;
			int x1=StrToInt(unos_komande, temp, koo1);
			while(unos_komande.at(temp)==' ')temp++;
			if(temp==unos_komande.size()-1) greska=KodoviGresaka::NedostajeParametar;
			if((unos_komande.at(temp)>'9' || unos_komande.at(temp)<'0' || unos_komande.at(temp)!=' ')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			int y1=StrToInt(unos_komande, temp, koo2);
			while(temp!=unos_komande.size()-1){
				if(unos_komande.at(temp)!=' '){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			if(koo1 && koo2){
				x=x1;
				y=y1;
				komanda=Komande::Blokiraj;
				return true;
			}
			
		}
		//Komanda PO
		else if(unos_komande.at(temp)=='P' && unos_komande.at(temp+1)=='O'){
			temp+=2;
			while(unos_komande.at(temp)==' ')temp++;
			if(temp==unos_komande.size()-1){
				 greska=KodoviGresaka::PogresnaKomanda;
				 return false;
			}
			else{
			komanda=Komande::PrikaziOkolinu;
			return true;
			}
		}
		//Komanda K
		if(unos_komande.at(temp)=='K'){
			temp++;
			while(unos_komande.at(temp)==' '){
				if(temp<unos_komande.size())break;
				temp++;
				
			}
			if(temp!=unos_komande.size()-1){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else{
				komanda=Komande::KreirajIgru;
				return true;
			}
		}
		//Komanda Z
		else if(unos_komande.at(temp)=='Z'){
			temp++;
			while(unos_komande.at(temp)==' ')temp++;
			if(temp!=unos_komande.size()-1){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else{
				komanda=Komande::ZavrsiIgru;
				return true;
			}
		}
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer= Smjerovi::Gore, int p_x= 0, int p_y= 0){
	vector<vector<int>>prazne_mine(0);
	switch(komanda){
		case(Komande::PomjeriJednoMjesto):{
			Status status=Idi(polja, x, y, p_smjer);
			cout<<"Tekuca poziciija igraca je ("<<x<<","<<y<<")"<<endl;
			if(status==Status::NijeKraj)break;
			if(status==Status::KrajPobjeda){
				cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
				KreirajIgru(polja.size(), prazne_mine);
				throw runtime_error("Igra zavrsena");
			}
			if(status==Status::KrajPoraz){
				cout<<"Nagazili ste na minu"<<endl;
				KreirajIgru(polja.size(), prazne_mine);
			}
			break;
		}
		case(Komande::PomjeriDalje):{
			Status status=Idi(polja, x, y, p_x, p_y);
			cout<<"Tekuca poziciija igraca je ("<<x<<","<<y<<")"<<endl;
			if(status==Status::NijeKraj)break;
			if(status==Status::KrajPobjeda){
				cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
				KreirajIgru(polja.size(), prazne_mine);
				throw runtime_error("Igra zavrsena");
			}
			if(status==Status::KrajPoraz){
				cout<<"Nagazili ste na minu"<<endl;
				KreirajIgru(polja.size(), prazne_mine);
			}
			break;
		}
		case(Komande::Deblokiraj):{
			try{ DeblokirajPolje(polja, p_x, p_y); }
			catch(domain_error hello){ cout<<hello.what(); }
		}
		case(Komande::Blokiraj):{
			try{ BlokirajPolje(polja, p_x, p_y); }
			catch(domain_error hello){ cout<<hello.what(); }
		}
		case(Komande::ZavrsiIgru):{
			KreirajIgru(polja.size(), prazne_mine);
			throw runtime_error("Igra zavrsena");
			break;
		}
		case(Komande::PrikaziOkolinu):{
			try{
				vector<vector<int>> okolina=PrikaziOkolinu(polja, x, y);
				for(int i=0; i<okolina.size(); i++){
					for(int j=0; j< okolina.size(); i++){
						cout<<okolina.at(i).at(j)<<" ";
					}
					cout<<endl;
				}
			}
			catch(domain_error hello){
				cout<<hello.what();
			}
			break;
		}
		case(Komande::KreirajIgru):{
			cout<<"Unesite broj polja: ";
			int n;
			cin>>n;
        	while( !cin || n<0 || n-int(n)>0.00000001){
	            cout<<"Greska, unesite ponovo!"<<endl;
	            std::cin.clear();
	            std::cin.ignore(10000, '\n');
	            cout<<"Unesite broj polja: ";
	            cin>>n;
        }
        while(1){
        	string s;
        	cout<<"Unesite pozicije mina: ";
        	char c;
        	bool xyx=false;
        	while(1){
        		
        		if(c=='.')break;
        		if(c==')'){ xyx=true; break;}
        		cin>>c;
        		s.push_back(c);
        	} //unos u string char po char 
        	
        	int setac=0;
        	int k=0, l=0;
        	if(s.at(setac)=='('){
        		setac++;
        		string broj;
        		while(s.at(setac)!=','){
        			if(s.at(setac)<'0' || s.at(setac)>'9'){
        				cout<<"Greska, unesite ponovo!"<<endl;
        			}
        			else{ broj.push_back(s.at(setac)); setac++;}
        		} //extrakcija koordinate;
        		int koordinata=StrToInt2(broj);
        		if(koordinata>n || koordinata<0) cout<<"Greska, unesite ponovo!"<<endl;
        		else{
        			prazne_mine.at(k).push_back(koordinata);
        		}
        		setac++;
        		broj.resize(0);
        		while(s.at(setac)!=')'){
        			if(s.at(setac)!='0' || s.at(setac)!='1' || s.at(setac)!='2' || s.at(setac)!='3' || s.at(setac)!='4' || s.at(setac)!='5' || s.at(setac)!='6' || s.at(setac)!='7' || s.at(setac)!='8' || s.at(setac)!='9'){
        				cout<<"Greska, unesite ponovo!"<<endl;
        			}
        			else broj.push_back(s.at(setac));
        		} //extrakcija koordinate;
        		koordinata=StrToInt2(broj);
        		if(koordinata>n || koordinata<0) cout<<"Greska, unesite ponovo!"<<endl;
        		else{
        			prazne_mine.at(k).push_back(koordinata);
        			k++;
        			l=0;
        		}
        	}
        	else cout<<"Greska, unesite ponovo!"<<endl;
        }
        
		}
		
		
		
		
	}
}

int main (){
		Status stats=Status::NijeKraj;
		Komande komanda;
		KodoviGresaka greska;
		Smjerovi smjer;
		Tabla tabla_za_igru;
		int novi_x=0, novi_y=0, x=0, y=0;
		vector<vector<int>> mine;
		while(stats==Status::NijeKraj){
			cout<<"Unesite komandu: ";
			if(UnosKomande(komanda, smjer, x, y, greska)){
				try{
					IzvrsiKomandu(komanda,  tabla_za_igru, x, y, smjer, novi_x, novi_y);
				}
			
				catch(domain_error izuzetak){
					cout<<izuzetak.what();
				}
				catch(out_of_range izuzetak){
					cout<<izuzetak.what();
				}
				catch(logic_error izuzetak){
					cout<<izuzetak.what();
				}
			}
			else{
				PrijaviGresku(greska);
			}
		}
	
	return 0;
}