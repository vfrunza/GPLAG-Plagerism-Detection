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
#include <string>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <complex>
using namespace std;
typedef vector<vector<int>>Matrica;
enum class Polje {Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef vector<vector<Polje>>Tabla;
Matrica KreirajMatricu(int broj_redova,int broj_kolona){
	return Matrica(broj_redova,vector<int>(broj_kolona));
}
void IspisiMatricu(Matrica mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat.at(i).size();j++) cout<<mat.at(i).at(j)<<" ";
		cout<<endl;
	}
}
void BrisiRazmake(string &s){
	int i(0);
	while((s.at(i)<'0' || s.at(i)>'9') && i<s.length()){
		if(s.at(i)>='0' && s.at(i)<='9') break;
		if(s.at(i)==' '){
			s.erase(s.begin()+i);
			i--;
		}
		i++;
	}
}
void PostaviXiY(string s,int &x,int &y){
	int i(0);
	while(s.at(i)>='0' && s.at(i)<='9') i++;
	s=s.substr(i,s.size()-i);
	BrisiRazmake(s);
	x=stoi(s.substr(0,i));
	y=stoi(s.substr(0));
}
Tabla KreirajIgru(int n,const vector<vector<int>>&mine){
	Tabla Mat;
	Mat.resize(n);
	for(int i=0;i<Mat.size();i++) Mat.at(i).resize(n);
	for(int i=0;i<Mat.size();i++){
		for(int j=0;j<Mat.at(i).size();j++) Mat.at(i).at(j)=Polje::Prazno;
	}
	for(int i=0;i<mine.size();i++){
		if(mine.at(i).size()!=2) throw domain_error("Ilegalan format zadavanja mina");
	}
	if(n<=0) throw domain_error("Ilegalna velicina");
	for(int i=0;i<Mat.size();i++){
		for(int j=0;j<Mat.at(i).size();j++){
			for(int k=0;k<mine.size();k++){
				if(mine.at(k).at(0)>=n || mine.at(k).at(1)>=n) throw domain_error("Ilegalne pozicije mina");
				if(mine.at(k).at(0)==i && mine.at(k).at(1)==j) Mat.at(i).at(j)=Polje::Mina;
			}
		}
	}
	return Mat;
}
Matrica PrikaziOkolinu(const Tabla &polja,int x,int y){
	for(int i=0;i<polja.size();i++){
		if(x>=polja.size() || y>=polja.at(i).size() || x<0 || y<0) throw domain_error("Polje ("+to_string(y)+","+to_string(x)+") ne postoji");
	}
	Matrica Polja(KreirajMatricu(polja.size(),polja.size()));
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.at(i).size();j++){
			if(polja.at(i).at(j)==Polje::Mina) Polja.at(i).at(j)=1;
		}
	}
	Matrica Mat(KreirajMatricu(3,3));
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			for(int k=-1;k<2;k++){
				for(int r=-1;r<2;r++){
					if(k==0 && r==0) continue;
					if(k+i+x<0 ||k+i+x>=Polja.size() || r+j+y<0 || r+j+y>=Polja.at(0).size()) continue;
					Mat.at(i+1).at(j+1)+=Polja.at(k+i+x).at(r+j+y);
				}
			}
		}
		
	}
	return Mat;
}
void BlokirajPolje(Tabla &polja,int x,int y){
	if(x>=polja.size() || x<0 || y<0 || y>=polja.at(0).size()) throw domain_error("Polje ("+to_string(y)+","+to_string(x)+") ne postoji");
	if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x>=polja.size() || x<0 || y<0 || y>=polja.at(0).size()) throw domain_error("Polje ("+to_string(y)+","+to_string(x)+") ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}
Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer){
	if(polja.size()==0 || (smjer==Smjerovi::GoreLijevo && (x==0 || y==0))) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Gore && x==0) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::GoreDesno && (x==0 || y==polja.at(0).size()-1)) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Desno && y==polja.at(0).size()-1) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::DoljeDesno && (x==polja.size()-1 || y==polja.at(0).size()-1)) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Dolje && x==polja.size()-1) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::DoljeLijevo && (x==polja.size()-1 || y==0)) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Lijevo && y==0) throw out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::GoreLijevo){
		if(polja.at(x-1).at(y-1)==Polje::BlokiranoMina || polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		x--; y--;
	}
	if(smjer==Smjerovi::Gore){
		if(polja.at(x-1).at(y)==Polje::BlokiranoMina || polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		x--;
	}
	if(smjer==Smjerovi::GoreDesno){
		if(polja.at(x-1).at(y+1)==Polje::BlokiranoMina || polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		x--; y++;
	}
	if(smjer==Smjerovi::Desno){
		if(polja.at(x).at(y+1)==Polje::BlokiranoMina || polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		y++;
	} 
	if(smjer==Smjerovi::DoljeDesno){
		if(polja.at(x+1).at(y+1)==Polje::BlokiranoMina || polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		x++; y++;
	} 
	if(smjer==Smjerovi::Dolje){
		if(polja.at(x+1).at(y)==Polje::BlokiranoMina || polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		x++;
	}
	if(smjer==Smjerovi::DoljeLijevo){
		if(polja.at(x+1).at(y-1)==Polje::BlokiranoMina || polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		x++; y--;
	}
	if(smjer==Smjerovi::Lijevo){
		if(polja.at(x).at(y-1)==Polje::BlokiranoMina || polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
		polja.at(x).at(y)=Polje::Posjeceno;
		y--;
	}
	if(polja.at(x).at(y)==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.at(i).size();j++){ polja.at(i).at(j)=Polje::Prazno;
		}
		}
		return Status::KrajPoraz;
	}
	if(polja.at(x).at(y)==Polje::Prazno){
		bool postoji(true);
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.at(i).size();j++){
				if(polja.at(i).at(j)==Polje::Prazno) postoji=false;
			}
		}
		if(postoji) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	if(novi_x>=polja.at(0).size() || novi_x<0 || novi_y<0 || novi_y>=polja.size()) throw out_of_range ("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y) == Polje::BlokiranoMina || polja.at(novi_x).at(novi_y)== Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y) == Polje::BlokiranoPrazno) throw logic_error ("Blokirano polje");
	else{
		x=novi_x;
		y=novi_y;
	}
	if(polja.at(x).at(y)==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.at(i).size();j++){
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	if(polja.at(x).at(y)==Polje::Prazno){
		bool postoji(true);
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.at(i).size();j++){
				if(polja.at(i).at(j)==Polje::Prazno) postoji=false;
			}
		}
		if(postoji) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan";
	if(greska==KodoviGresaka::NedostajeParametar)  cout<<"Komanda trazi parametar koji nije naveden";
	if(greska==KodoviGresaka::PogresnaKomanda)     cout<<"Nerazumljiva komanda";
	if(greska==KodoviGresaka::SuvisanParametar)    cout<<"Zadan je suvisan parametar nakon komande";
}
bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	string s;
	getline(cin,s);
	BrisiRazmake(s);
	if(s.substr(0,2)=="P1"){
		komanda=Komande::PomjeriJednoMjesto;
		s=s.substr(2,s.length()-2);
		BrisiRazmake(s);
		
		if(s.substr(0,s.length())=="G"){ smjer=Smjerovi::Gore; return true;}
	else if(s.substr(0,s.length())=="GL"){ smjer=Smjerovi::GoreLijevo; return true;}
	else if(s.substr(0,s.length())=="GD"){ smjer=Smjerovi::GoreDesno; return true;}
	else if(s.substr(0,s.length())=="Do"){ smjer=Smjerovi::Dolje; return true;}
	else if(s.substr(0,s.length())=="DoD"){ smjer=Smjerovi::DoljeDesno; return true;}
	else if(s.substr(0,s.length())=="DoL"){ smjer=Smjerovi::DoljeLijevo; return true;}
	else if(s.substr(0,s.length())=="D"){ smjer=Smjerovi::Desno; return true;}
	else if(s.substr(0,s.length())=="L"){ smjer=Smjerovi::Lijevo; return true;}
	else {
		if(s.length()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else{
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	}
else if(s.substr(0,2)=="P>"){
		s=s.substr(2,s.length()-2);
		if(s.length()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else{
			int i(0);
			while(i<s.length()){
				if((s.at(i)<'0' || s.at(i)>'9') && s.at(i)!=' '){
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				i++;
			}
		}
		komanda=Komande::PomjeriDalje;
		PostaviXiY(s,x,y);
		return true;
	}
else if(s.at(0)=='D'){
	s=s.substr(1,s.length()-1);
		if(s.length()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		int i(0);
		while(i<s.length()){
			if((s.at(i)<'0' || s.at(i)>'9') && s.at(i)!=' '){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			i++;
		}
		komanda=Komande::Deblokiraj;
		PostaviXiY(s,x,y);
		return true;
	}
else if(s.at(0)=='B'){
		s=s.substr(1,s.length()-1);
		if(s.length()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		int i(0);
		while(i<s.length()){
			if((s.at(i)<'0' || s.at(i)>'9') && s.at(i)!=' '){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			i++;
		}
		komanda=Komande::Blokiraj;
		PostaviXiY(s,x,y);
		return true;
	}
	else if(s.substr(0,2)=="PO"){
		komanda=Komande::PrikaziOkolinu;
		if(s.substr(0,2)=="PO" && s.length()!=2){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		
		return true;
	}
else if(s.at(0)=='K'){
		if(s.at(0)=='K' && s.length()!=1){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::KreirajIgru;
		return true;
	}
	else if(s.at(0)=='Z'){
		if(s.at(0)=='Z' && s.length()!=1){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::ZavrsiIgru;
		return true;
	}
	else{
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return false;
}
void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y,Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0){
	Status stanje(Status::NijeKraj);
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
			stanje=Idi(polja ,x ,y ,p_smjer);
		}
		catch(out_of_range e) 	{ cout << e.what(); }
		catch(logic_error e) 	{ cout << e.what(); }
		if(stanje==Status::KrajPoraz){
			cout<<"Nagazili ste minu";
			komanda=Komande::ZavrsiIgru;
		}
		if(stanje==Status::KrajPobjeda){
			cout<<"Bravo,obisli ste sva sigurna polja";
			komanda=Komande::ZavrsiIgru;
		}
		else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
	}
	if(komanda==Komande::PomjeriDalje){
		stanje=Idi(polja,x,y,p_x,p_y);
		if(stanje==Status::KrajPoraz){
			cout<<"Nagazili ste minu";
			komanda=Komande::ZavrsiIgru;
		}
		if(stanje==Status::KrajPobjeda){
			cout<<"Bravo,obisli ste sva sigurna polja";
			komanda=Komande::ZavrsiIgru;
		}
		else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
	}
	if(komanda==Komande::PrikaziOkolinu){
		Matrica mat=PrikaziOkolinu(polja,x,y);
		IspisiMatricu(mat);
	}
	if(komanda==Komande::Blokiraj) BlokirajPolje(polja,p_x,p_y);
	if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,p_x,p_y);
	if(komanda==Komande::ZavrsiIgru){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.at(i).size();j++) polja.at(i).at(j)=Polje::Prazno;
		}
		throw runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::KreirajIgru){
		cout<<"Unesite broj polja: ";
		int n;
		cin>>n;
		cout<<"Unesite pozicije mina: ";
		Matrica mine;
		complex<int>par;
		for(;;){
			cin.clear();
			cin.ignore(10000,'\n');
			cin>>par;
			if(!cin){
				cin.clear();
				if(cin.peek()=='.'){
					cin.ignore(100000,'\n');
					break;
				}
				else{
					cout<<"Greska,unesite ponovo"<<endl;
					continue;
				}
			}
			if(real(par)<0 || real(par)>=n || imag(par)<0 || imag(par)>=n){
				cout<<"Greska,unesite ponovo"<<endl;
				continue;
			}
			mine.push_back({real(par),imag(par)});
			x=0;y=0;
		}
		try{
			polja=KreirajIgru(n,mine);
		}
		catch(domain_error e){
			cout<<e.what();
		}
	}
}

int main (){
	Tabla tabla;
	Komande komanda;
	KodoviGresaka greska;
	Smjerovi smjer;
	int x(0),y(0),polje_x(0),polje_y(0);
	try{
		for(;;){
			cout<<"Unesite komandu: ";
			if(UnosKomande(komanda,smjer,x,y,greska)){
				IzvrsiKomandu(komanda,tabla,x,y,smjer,polje_x,polje_y);
			}
			else PrijaviGresku(greska);
		}
	}
	catch(domain_error e){
		cout<<e.what();
//		continue;
	}
	catch(std::logic_error e){
		cout<<e.what();
//		continue; 
	}
	catch(std::out_of_range e){
		cout<<e.what();
//		continue;
	} 
	catch(runtime_error){
		cout<<"Dovidjenja";
	}
	return 0;
}