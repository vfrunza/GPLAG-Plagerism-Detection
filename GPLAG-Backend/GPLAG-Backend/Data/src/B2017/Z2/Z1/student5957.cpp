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
using std::cout;
using std::cin;
using std::vector;
using std::string;
enum class Polje{ Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi{ GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class KodoviGresaka{ PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande{ PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
enum class Status{ NijeKraj, KrajPoraz, KrajPobjeda};
typedef vector<vector<Polje>> Tabla;

void PrijaviGresku(KodoviGresaka kodovi){
	vector<string> v{{"Nerazumljiva komanda!"},{"Komanda trazi parametar koji nije naveden!"},
					{"Zadan je suvisan parametar nakon komande!"},{"Parametar komande nije ispravan!"}};
	for(int i(0);i<4;i++) if(kodovi==KodoviGresaka(i)){
		cout<<v.at(i)<<std::endl;
		break;
	}
}

vector<string> Unos(){
	vector<string> v(2);
	string s;
	getline(cin,s);
	for(int i(0);i<s.length();i++) if(s.at(i)==' ' || s.at(i)=='	') { s.erase(s.begin()+i); i--; }
	vector<string> v1{{"P1GL"},{"P1GD"},{"P1G"},{"P1D"},{"P1DoD"},{"P1Do"},{"P1DoL"},{"P1L"}};
	if(s.length()==0){
		v.at(0)="PogresnaKomanda";
		return v;
	}
	int duz=s.length(),i(0);
	if(s.at(i)=='K'){
		if(duz==i+1){
			v.at(0)=s; return v;
		}
		else{
			v.at(0)="SuvisanParametar";
			return v;
		}
	}
	else if(s.at(i)=='Z'){
		if(duz==i+1){
			v.at(0)=s; return v;
		}
		else{
			v.at(0)="PogresnaKomanda";
			return v;
		}
	}
	else if(s.at(i)=='D'){
		if(duz==1){
			v.at(0)="NedostajeParametar";
			return v;
		}
		else if(duz==3){
			if(s.at(i+1)>='0' && s.at(i+1)<='9' && s.at(i+2)>='0' && s.at(i+2)<='9'){
				v.at(i)=s.at(i);
				v.at(1).push_back(s.at(i+1));
				v.at(1).push_back(s.at(i+2));
				return v;
			}
			else{
				v.at(0)="NeispravanParametar";
				return v;
			}
		}
		else if(duz>3){
			if(s.at(i+1)>='0' && s.at(i+1)<='9' && s.at(i+2)>='0' && s.at(i+2)<='9'){
				v.at(i)="NeispravanParametar";
				return v;
			}
			else{
				v.at(0)="NeispravanParametar";
				return v;
			}
		}
		else{
			v.at(0)="NeispravanParametar";
			return v;
		}
	}
	else if(s.at(i)=='B'){
		if(duz==1){
			v.at(0)="NedostajeParametar";
			return v;
		}
		else if(duz==3){
			if(s.at(i+1)>='0' && s.at(i+1)<='9' && s.at(i+2)>='0' && s.at(i+2)<='9'){
				v.at(i)=s.at(i);
				v.at(1).push_back(s.at(i+1));
				v.at(1).push_back(s.at(i+2));
				return v;
			}
			else{
				v.at(0)="NeispravanParametar";
				return v;
			}
		}
		else if(duz>3){
			if(s.at(i+1)>='0' && s.at(i+1)<='9' && s.at(i+2)>='0' && s.at(i+2)<='9'){
				v.at(i)="NeispravanParametar";
				return v;
			}
			else{
				v.at(0)="NeispravanParametar";
				return v;
			}
		}
		else{
			v.at(0)="NeispravanParametar";
			return v;
		}
	}
	else if(s.at(i)=='P'){
		if(duz==1){
			v.at(0)="PogresnaKomanda";
			return v;
		}
		else if(s.at(i+1)=='O'){
			if(duz==i+2){
				v.at(0)=s;
				return v;
			}
			else{
				v.at(0)="PogresnaKomanda";
				return v;
			}
		}
		else if(s.at(i+1)=='>'){
			if(duz==2){
				v.at(0)="NedostajeParametar";
				return v;
			}
			else if(duz==4 && s.at(i+2)>='0' && s.at(i+2)<='9' && s.at(i+3)>='0' && s.at(i+3)<='9'){
				v.at(i).push_back(s.at(i));
				v.at(i).push_back(s.at(i+1));
				v.at(1).push_back(s.at(i+2));
				v.at(1).push_back(s.at(i+3));
				return v;
			}
			else{
				v.at(i)="NeispravanParametar";
				return v;
			}
		}
		else if(s.at(i+1)=='1'){
				if(duz==2){
					v.at(0)="NedostajeParametar";
					return v;
				}
				for(int i(0);i<v1.size();i++){
					if(s==v1.at(i)){
						v.at(0)=s;
						return v;
					}
				}
				v.at(0)="NeispravanParametar";
				return v;
		}
	}
	v.at(0)="PogresnaKomanda";
	return v;
}

int PretvoriUBroj(char znak){
	vector<char> v{{'0'},{'1'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'}};
	for(int i(0);i<=v.size();i++){
		if(znak==v.at(i)) return i;
	}
	return 10;
}

vector<vector<int>> UnesiMine(int n){
	vector<vector<int>> v;
	int i(0);
	while(true){
		string s;
		getline(cin,s);
		for(int i(0);i<s.length();i++) if(s.at(i)==' ' || s.at(i)=='	') { s.erase(s.begin()+i); i--; }
		if(s==".") break;
		else if(s.length()!=5) cout<<"Greska, unesite ponovo!"<<std::endl;
		else if(s.at(0)=='(' && s.at(4)==')' && s.at(2)==','){
			if(s.at(1)>='0' && s.at(1)<='9' && s.at(3)>='0' && s.at(3)<='9'){
				int prvi(PretvoriUBroj(s.at(1))),drugi(PretvoriUBroj(s.at(3)));
				if(prvi<0 || prvi>=n || drugi<0 || drugi>=n) cout<<"Greska, unesite ponovo!"<<std::endl;
				else{
					v.resize(v.size()+1);
					v.at(i).push_back(PretvoriUBroj(s.at(1)));
					v.at(i).push_back(PretvoriUBroj(s.at(3)));
					i++;
				}
			}
			else cout<<"Greska, unesite ponovo!"<<std::endl;
		}
		else cout<<"Greska, unesite ponovo!"<<std::endl;
	}
	return v;
}

void IzvrsiKomandu(Komande,Tabla &,int &,int &,Smjerovi,int,int);

bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	vector<string> unos(Unos());
	bool istina(false);
	if(unos.at(0)=="PogresnaKomanda") { greska=KodoviGresaka(0);}
	else if(unos.at(0)=="NedostajeParametar") { greska=KodoviGresaka(1);}
	else if(unos.at(0)=="SuvisanParametar") greska=KodoviGresaka(2);
	else if(unos.at(0)=="NeispravanParametar") greska=KodoviGresaka(3);
	else{
		if(unos.at(0)=="PO"){
			komanda=Komande(4);
			istina=true;
		}
		else if(unos.at(0)=="Z"){
			komanda=Komande(5);
			istina=true;
		}
		else if(unos.at(0)=="K"){
			komanda=Komande(6);
			istina=true;
		}
		else if(unos.at(0)=="D"){
			komanda=Komande(3);
			x=PretvoriUBroj(unos.at(1).at(0));
			y=PretvoriUBroj(unos.at(1).at(1));
			istina=true;
		}
		else if(unos.at(0)=="B"){
			komanda=Komande(2);
			x=PretvoriUBroj(unos.at(1).at(0));
			y=PretvoriUBroj(unos.at(1).at(1));
			istina=true;
		}
		else if(unos.at(0)=="P>"){
			komanda=Komande(1);
			x=PretvoriUBroj(unos.at(1).at(0));
			y=PretvoriUBroj(unos.at(1).at(1));
			istina=true;
		}
		else{
			komanda=Komande(0);
			vector<string> v1{{"P1GL"},{"P1G"},{"P1GD"},{"P1D"},{"P1DoD"},{"P1Do"},{"P1DoL"},{"P1L"}};
			for(int i(0);i<v1.size();i++){
				if(unos.at(0)==v1.at(i)){
					smjer=Smjerovi(i);
					i=10;
					istina=true;
				}
			}
		}
		return istina;
	}
	return istina;
}

Tabla KreirajIgru(int n,const vector<vector<int>> &mine){
	for(auto &red : mine) if(red.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	for(auto &red : mine)
		for(auto &x : red) if(x<0 || x>=n) throw std::domain_error("Ilegalne pozicije mina");
	if(n<=0) throw std::domain_error("Ilegalna veličina");
	Tabla mat(n,vector<Polje>(n,Polje(0)));
	for(auto &red : mine){
		mat.at(red.at(0)).at(red.at(1))=Polje(2);
	}
	return mat;
}

int BrMinaOkolinePolja(const Tabla &polja,int x,int y){
	int brmina(0);
	for(int i(x-1);i<=x+1;i++){
		for(int j(y-1);j<=y+1;j++){
			if(i<0 || j<0 || i>polja.size()-1 || j>polja.size()-1 || (i==x && j==y));
			else if(polja.at(i).at(j)==Polje(2)) brmina++;
		}
	}
	return brmina;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1)
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	vector<vector<int>> matmine(3,vector<int>(3));
	for(int i(0);i<3;i++){
		for(int j(0);j<3;j++){
			if(i+x-1<0 || j+y-1<0 || i+x>polja.size() || j+y>polja.size()) matmine.at(i).at(j)=0;
			else matmine.at(i).at(j)=BrMinaOkolinePolja(polja,i+x-1,j+y-1);
		}
	}
	return matmine;
}

void BlokirajPolje(Tabla &polja,int x,int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1)
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje(0)) polja.at(x).at(y)=Polje(3);
	else if(polja.at(x).at(y)==Polje(1)) polja.at(x).at(y)=Polje(4);
	else if(polja.at(x).at(y)==Polje(2)) polja.at(x).at(y)=Polje(5);
}

void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1)
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje(3)) polja.at(x).at(y)=Polje(0);
	else if(polja.at(x).at(y)==Polje(4)) polja.at(x).at(y)=Polje(1);
	else if(polja.at(x).at(y)==Polje(5)) polja.at(x).at(y)=Polje(2);
}

int BrojPraznihPolja(Tabla &polja){
	int brojac(0);
	for(auto &red : polja)
		for(auto &polje : red) if(polje==Polje(0)) brojac++;
	return brojac;
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer){
	int i(0);
	vector<vector<int>> v{{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	for(i=0;i<8;i++) if(smjer==Smjerovi(i)) break;
	int iks(x+v.at(i).at(0)),ipsilon(y+v.at(i).at(1));
	if(iks<0 || ipsilon<0 || iks>polja.size()-1 || ipsilon>polja.size()-1)
		throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(iks).at(ipsilon)==Polje(3) || polja.at(iks).at(ipsilon)==Polje(4) || polja.at(iks).at(ipsilon)==Polje(5))
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje(1); x=iks; y=ipsilon;
	if(polja.at(iks).at(ipsilon)==Polje(2)){
		for(auto &red : polja)
			for(auto &polje : red) polje=Polje(0);
		return Status(1);
	}
	if(polja.at(iks).at(ipsilon)==Polje(0) && BrojPraznihPolja(polja)==1) return Status(2);
	return Status(0);
}

Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>polja.size()-1 || novi_y>polja.size()-1)
		throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje(3) || polja.at(novi_x).at(novi_y)==Polje(4) || polja.at(novi_x).at(novi_y)==Polje(5))
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje(1); x=novi_x; y=novi_y;
	if(polja.at(novi_x).at(novi_y)==Polje(2)){
		for(auto &red : polja)
			for(auto &polje : red) polje=Polje(0);
		return Status(1);
	}
	if(polja.at(novi_x).at(novi_y)==Polje(0) && BrojPraznihPolja(polja)==1) return Status(2);
	return Status(0);
}

void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y,Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0){
	if(komanda==Komande(6)){
		int n(0);
		cout<<"Unesite broj polja: "; cin>>n;
		while(!cin || n<=0){
			cout<<"Greska, unesite ponovo!";
			cin.clear(); cin.ignore(1000,'\n');
			cout<<std::endl<<"Unesite broj polja: ";
			cin>>n;
		}
		cin.clear(); cin.ignore(1000,'\n');
		cout<<"Unesite pozicije mina: ";
		vector<vector<int>> v(UnesiMine(n));
		polja=KreirajIgru(n,v);
	}
	else if(komanda==Komande(0)){
		Status status(Idi(polja,x,y,p_smjer));
		if(status==Status(2)){
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			throw 2;
		}
		else if(status==Status(1)){
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			throw 1;
		}
		else{
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
	}
	else if(komanda==Komande(4)){
		vector<vector<int>> v(PrikaziOkolinu(polja,x,y));
		for(auto &red : v){
			for(auto &x : red) cout<<x<<" ";
			cout<<std::endl;
		}
	}
	else if(komanda==Komande(2)){
		BlokirajPolje(polja,p_x,p_y);
	}
	else if(komanda==Komande(3)){
		DeblokirajPolje(polja,p_x,p_y);
	}
	else if(komanda==Komande(1)){
		Status status(Idi(polja,x,y,p_x,p_y));
		if(status==Status(2)){
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			throw 2;
		}
		else if(status==Status(1)){
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			throw 1;
		}
		else{
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
	}
	else{
		for(auto &red : polja)
			for(auto &x : red) x=Polje(0);
		throw std::runtime_error("Dovidjenja!");
	}
}

int main ()
{
	int x(0),y(0),p_x(0),p_y(0),komanda_x(0),komanda_y(0);
	Tabla polja;
	bool pocetna(true);
	while(true){
		cout<<"Unesite komandu: ";
		try{
			Komande komanda; Smjerovi smjer; KodoviGresaka greska=KodoviGresaka(0);
			bool pomocna(UnosKomande(komanda,smjer,komanda_x,komanda_y,greska));
			if(pocetna==true && komanda==Komande(6)){
				x=komanda_x; y=komanda_y;
				IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y); pocetna=false;
			}
			else if(pocetna==false && pomocna==true){
				if(komanda==Komande(1)){
					p_x=komanda_x; p_y=komanda_y;
				}
				else if(komanda==Komande(2)){
					p_x=komanda_x; p_y=komanda_y;
				}
				else if(komanda==Komande(3)){
					p_x=komanda_x; p_y=komanda_y;
				}
				IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
			}
			else{
				if(greska==KodoviGresaka(0)) cout<<"Pogresna Komanda"<<std::endl;
				else if(greska==KodoviGresaka(1)) cout<<"Nedostaje Parametar"<<std::endl;
				else if(greska==KodoviGresaka(2)) cout<<"Suvisan Parametar"<<std::endl;
				else if(greska==KodoviGresaka(3)) cout<<"Neispravan Parametar"<<std::endl;
			}
		}
		catch(int n){
			if(n==0){
				cout<<"Dovidjenja!"; return 0;
			}
			else if(n==2) cout<<"Bravo, obisli ste sva sigurna polja";
			else if(n==1){
				cout<<"Nagazili ste na minu"; return 0;
			}
		}
		catch(std::logic_error izuzetak){
			cout<<izuzetak.what()<<std::endl;
		}
		catch(std::runtime_error izuzetak){
			cout<<izuzetak.what()<<std::endl;
			return 0;
		}
	}

	return 0;
}