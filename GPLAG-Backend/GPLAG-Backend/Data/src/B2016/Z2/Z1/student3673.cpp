/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <string>

using namespace std;

enum class Polje {Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
typedef vector<vector<Polje>>Tabla;
enum class Smjerovi {GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status {NijeKraj,KrajPoraz,KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar};
enum class Komande{PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru};

Tabla KreirajIgru(int n, const vector<vector<int>> &mine){
	Tabla t(n,vector<Polje>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)t[i][j]=Polje::Prazno;
	}
	for(int i=0;i<int(mine.size());i++){
	if(int(mine[i].size())>2 || mine[i].size()<2) throw domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0;i<int(mine.size());i++){
		for(int j=0;j<int(mine[i].size())-1;j++){
			if(mine[i][j]>n || mine[i][j+1]>n)throw domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0;i<int(mine.size());i++){
			int x(mine[i][0]),y(mine[i][1]);
			t[x][y]=Polje::Mina;
	}
	return t;
}

int Okolina(const Tabla &polje,int x,int y){
	int velicina(polje.size()),brojac(0);
	//prvi red
	if(x==0 && y==0){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
	    }
    }
	
	else if(x==0 && y!=velicina-1){
		for(int i=0;i<2;i++){
			for(int j=y-1;j<y+2;j++){
			if(i==x && j==y)continue;
			if(polje[i][j]==Polje::Mina)brojac++;
	        }	
	    }
	}
	else if(x==0 && y==velicina-1){
		for(int i=0;i<2;i++){
			for(int j=y-1;j<velicina;j++){
			if(i==x && j==y)continue;
			if(polje[i][j]==Polje::Mina)brojac++;
		}
	}
}
	//prva kolona
	else if(x!=0 &&  y==0 && x!=velicina-1){
		for(int i=x-1;i<x+2;i++){
			for(int j=0;j<2;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
		}
	}
	else if(x==velicina-1 && y==0){
		for(int i=x-1;i<velicina;i++){
			for(int j=0;j<2;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
		}
	}
	//zadnji red
	else if(x==velicina-1 && y!=velicina-1){
		for(int i=velicina-2;i<velicina;i++){
			for(int j=y-1;j<y+2;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
		}
	}
	else if(x==velicina-1 && y==velicina-1){
		for(int i=x-1;i<velicina;i++){
			for(int j=y-1;j<velicina;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
		}
	}
	//zadnja kolona
	else if(x!=velicina-1 && y==velicina-1){
		for(int i=x-1;i<x+2;i++){
			for(int j=y-1;j<velicina;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
		}
	}
	else {
		for(int i=x-1;i<x+2;i++){
			for(int j=y-1;j<y+2;j++){
				if(i==x && j==y)continue;
				if(polje[i][j]==Polje::Mina)brojac++;
			}
		}
	}
	return brojac;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y){
	int opseg_table(polja.size());
	if(x>opseg_table-1 || y>opseg_table-1){string s="Polje ("+to_string(x)+","+to_string(y)+") ne postoji";throw domain_error(s);}
	vector<vector<int>>Matrica(3,vector<int>(3));
	//prvi red
	if(x==0 && y==0){
		int x_kor(0);
		for(int i=0;i<2;i++){
			int y_kor(0);
			for(int j=0;j<2;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
	}	
}
	else if(x==0 && y!=opseg_table-1){
		int x_kor(0);
		for(int i=0;i<2;i++){
			int y_kor(0);
			for(int j=y-1;j<y+2;j++){
			int element=Okolina(polja,i,j);
			Matrica[x_kor][y_kor]=element;
			y_kor++;
			}
	x_kor++;
		}
		
	}
		else if(x==0 && y==opseg_table-1){
		int x_kor(0);
		for(int i=0;i<2;i++){
			int y_kor(0);
			for(int j=y-1;j<opseg_table;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
	}
		//prva kolona
	else if(x!=0  && y==0 && x!=opseg_table-1){
		int x_kor(0);
		for(int i=x-1;i<x+2;i++){
			int y_kor(0);
			for(int j=0;j<2;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
	}
		else if(x==opseg_table-1 && y==0){
		int x_kor(0);
		for(int i=x-1;i<opseg_table;i++){
			int y_kor(0);
			for(int j=0;j<2;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
	}
	//zadnji red
		else if(x==opseg_table-1 && y!=opseg_table-1){
		int x_kor(0);
		for(int i=opseg_table-2;i<opseg_table;i++){
			int y_kor(0);
			for(int j=y-1;j<y+2;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
	}
		else if(x==opseg_table-1 && y==opseg_table-1){
		int x_kor(0);
		for(int i=x-1;i<opseg_table;i++){
			int y_kor(0);
			for(int j=y-1;j<opseg_table;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
	}
		//zadnja kolona
	else if(x!=opseg_table-1 && y==opseg_table-1){
		int x_kor(0);
		for(int i=x-1;i<x+2;i++){
			int y_kor(0);
			for(int j=y-1;j<opseg_table;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
	}
	else {
	int x_kor(0);
	for(int i=x-1;i<x+2;i++){
			int y_kor(0);
			for(int j=y-1;j<y+2;j++){
				int element=Okolina(polja,i,j);
				Matrica[x_kor][y_kor]=element;
				y_kor++;
			}
			x_kor++;
		}
		
	}
		return Matrica;
}

void BlokirajPolje(Tabla &polja,int x,int y){
	int opseg_table(polja.size());
	if(x>opseg_table-1 || y>opseg_table-1){string s="Polje ("+to_string(x)+","+to_string(y)+") ne postoji";throw domain_error(s);}
	if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;//cout<<"&&&"<<int(polja[x][y])<<"&&&";}
	else if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja,int x,int y){
	int opseg_table(polja.size());
	if(x>opseg_table-1 || y>opseg_table-1){string s="Polje ("+to_string(x)+","+to_string(y)+") ne postoji";throw domain_error(s);}
	if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)cout<<"Nerazumljiva komanda!"<<endl;;
	if(greska==KodoviGresaka::NedostajeParametar)cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	if(greska==KodoviGresaka::NeispravanParametar)cout<<"Parametar komande nije ispravan!"<<endl;
	if(greska==KodoviGresaka::SuvisanParametar)cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}

string IzbaciRazmak(string s){
	string novi="";
	for(int i=0;i<s.length();i++){
		if(s[i]!=' ')novi+=s[i];
	}
	return novi;
}

bool DaLiJeCifra(char c){
	if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')return true;
	return false;
}

int PretvoriUInt(string s,int poz){
	int broj(0);
		int cifra=s[poz]-'0';
		broj=broj*10+cifra;
	return broj;
}

bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	string s;
	getline(cin,s);
	s=IzbaciRazmak(s);
	if(s.length()==1){
		if(s[0]=='Z'){komanda=Komande::ZavrsiIgru;return true;}
		else if(s[0]=='K'){komanda=Komande::KreirajIgru;return true;}
		else if(s[0]=='B'){greska=KodoviGresaka::NedostajeParametar;return false;}
		else if(s[0]=='D'){greska=KodoviGresaka::NedostajeParametar;return false;}
		else{greska=KodoviGresaka::PogresnaKomanda;return false;}
		
	}
	if(s.length()==2){
		if(s[0]=='P' && s[1]=='O'){komanda=Komande::PrikaziOkolinu;return true;}
		else if(s[0]=='P' && s[1]=='1'){greska=KodoviGresaka::NedostajeParametar;return false;}
		else if(s[0]=='P' && s[1]=='>'){greska=KodoviGresaka::NedostajeParametar;return false;}
		else{greska=KodoviGresaka::PogresnaKomanda;return false;}
	}
	if(s.length()==3){
	if(s[0]=='P' && s[1]=='1'){
		if(s[2]=='G'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Gore;return true;}
		else if(s[2]=='D'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Desno;return true;}
		else if(s[2]=='L'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Lijevo;return true;}
		else {greska=KodoviGresaka::NeispravanParametar;return false;}
	}
	else if(s[0]=='B'){
			if(DaLiJeCifra(s[1]) && DaLiJeCifra(s[2])){x=PretvoriUInt(s,1);y=PretvoriUInt(s,2);komanda=Komande::Blokiraj;return true;}
			else{greska=KodoviGresaka::NeispravanParametar;return false;}
		}
	else if(s[0]=='D'){
		if(DaLiJeCifra(s[1]) && DaLiJeCifra(s[2])){x=PretvoriUInt(s,1);y=PretvoriUInt(s,2);komanda=Komande::Deblokiraj;return true;}
		else{greska=KodoviGresaka::NeispravanParametar;return false;}
	}
	else if(s[0]=='P' && s[1]=='>'){
		if (DaLiJeCifra(s[2])){greska=KodoviGresaka::NedostajeParametar;return false;}
		else {greska=KodoviGresaka::NeispravanParametar;return false;}
	}
	else{greska=KodoviGresaka::PogresnaKomanda;return false;}
	}
	if(s.length()==4){
		if(s[0]=='P' && s[1]=='1'){
		if(s[2]=='G' && s[3]=='L'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::GoreLijevo;return true;}
		else if(s[2]=='G' && s[3]=='D'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::GoreDesno;return true;}
		else if(s[2]=='D' && s[3]=='o'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Dolje;return true;}
		else{greska=KodoviGresaka::NeispravanParametar;return false;}
	} 
	else if(s[0]=='P' && s[1]=='>'){
			if(DaLiJeCifra(s[2]) && DaLiJeCifra(s[3])){
				x=PretvoriUInt(s,2);
				y=PretvoriUInt(s,3);
				komanda=Komande::PomjeriDalje;return true;
			}else{greska=KodoviGresaka::NeispravanParametar;return false;}
		}
	
	else {greska=KodoviGresaka::PogresnaKomanda;return false;}
	}
	if(s.length()==5){
			if(s[0]=='P' && s[1]=='1'){
			if(s[2]=='D' && s[3]=='o' && s[4]=='D'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::DoljeDesno;return true;}
			else if(s[2]=='D' && s[3]=='o' && s[4]=='L'){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::DoljeLijevo;return true;}
			else{greska=KodoviGresaka::NeispravanParametar;return false;}
			}else {greska=KodoviGresaka::PogresnaKomanda;return false;}
	      }
	if(s.length()>5){
		if(s[0]=='P' && s[1]=='1'){
		if(DaLiJeCifra(s[2]) && DaLiJeCifra(s[3])){	greska=KodoviGresaka::SuvisanParametar;return false;}
		else {greska=KodoviGresaka::NeispravanParametar;return false;}
		}
		if(s[0]=='P' && s[1]=='>'){
		//if(DaLiJeCifra(s[2]) && DaLiJeCifra(s[3])){greska=KodoviGresaka::SuvisanParametar;return false;}
		greska=KodoviGresaka::NeispravanParametar;return false;	
		}
	}
	return true;
}

bool IspravanIndeks(Tabla &polja,int x,int y){
	int opseg_table(polja.size());
	bool a(false),b(false);
	for(int i=0;i<opseg_table;i++){
		if (x==i)a=true;
		if (y==i)b=true;
	}
	if(a==true && b==true)return true;
	return false;
}
void OcistiMatricu(Tabla &polja){
	int opseg_table(polja.size());
	for(int i=0;i<opseg_table;i++){
		for(int j=0;j<opseg_table;j++)polja[i][j]=Polje::Prazno;
	}
}

bool PraznoPolje(Tabla &polja,int x,int y){
	bool a(false);
	for(int i=0;i<polja[0].size();i++){
		for(int j=0;j<polja[0].size();j++){
			if(i==x && j==y)continue;
			if(polja[i][j]==Polje::Prazno)
				a=true;
		}
	}
	return a;
}

Status Idi (Tabla &polja,int &x,int &y,Smjerovi smjer){
	int trenutni_x(x),trenutni_y(y);
	if(smjer==Smjerovi::GoreLijevo){
		trenutni_x=trenutni_x-1;trenutni_y=trenutni_y-1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;y=y-1;
		if(polja[x][y]==Polje::Mina){OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::Gore){
		trenutni_x=trenutni_x-1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
		if(polja[x][y]==Polje::Mina) {OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::GoreDesno){
		trenutni_x=trenutni_x-1;trenutni_y=trenutni_y+1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;y=y+1;
		if(polja[x][y]==Polje::Mina) {OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::Desno){
		trenutni_y=trenutni_y+1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y=y+1;
		if(polja[x][y]==Polje::Mina){ OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::DoljeDesno){
		trenutni_x=trenutni_x+1;trenutni_y=trenutni_y+1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;y=y+1;
		if(polja[x][y]==Polje::Mina){ OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::Dolje){
		trenutni_x=trenutni_x+1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
		if(polja[x][y]==Polje::Mina){ OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::DoljeLijevo){
		trenutni_x=trenutni_x+1;trenutni_y=trenutni_y-1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;y=y-1;
		if(polja[x][y]==Polje::Mina) {OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	if(smjer==Smjerovi::Lijevo){
		trenutni_y=trenutni_y-1;
		if(IspravanIndeks(polja,trenutni_x,trenutni_y)==false)throw out_of_range("Izlazak van igrace table");
		if(polja[trenutni_x][trenutni_y]==Polje::BlokiranoPosjeceno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoPrazno || polja[trenutni_x][trenutni_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y=y-1;
		if(polja[x][y]==Polje::Mina){ OcistiMatricu(polja);return Status::KrajPoraz;}
		if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	}
	return Status:: NijeKraj;
}

Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	if(IspravanIndeks(polja,novi_x,novi_y)==false){throw out_of_range ("Izlazak van igrace table");}
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)throw logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;y=novi_y;
	if(polja[x][y]==Polje::Mina) {OcistiMatricu(polja);return Status::KrajPoraz;}
	if(PraznoPolje(polja,x,y)==false)return Status::KrajPobjeda;
	return Status::NijeKraj;
}

int Broj(char c){
	int broj(0);
		int cifra=c-'0';
		broj=broj*10+cifra;
	return broj;
}

bool DaLiJeCifra(char c,int opseg_table){
	if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9'){if(Broj(c)<opseg_table)return true;}
  return false;
}

void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y, Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0){
	try {
	if(komanda==Komande::Blokiraj)BlokirajPolje(polja,p_x,p_y);
	if(komanda==Komande::Deblokiraj)DeblokirajPolje(polja,p_x,p_y);
	if(komanda==Komande::PomjeriDalje){
		Status s;
		s=Idi(polja,x,y,p_x,p_y);
		if(s==Status::NijeKraj)cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
		if(s==Status::KrajPobjeda){cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl<<"Bravo,obisli ste sva sigurna polja"<<endl;OcistiMatricu(polja);throw runtime_error("Igra zavrsena");}
		if(s==Status::KrajPoraz){cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl<<"Nagazili ste na minu"<<endl;OcistiMatricu(polja);throw runtime_error("Igra zavrsena");}
	}
	if(komanda==Komande::PomjeriJednoMjesto){
		Status s;
		s=Idi(polja,x,y,p_smjer);
		if(s==Status::NijeKraj)cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
		if(s==Status::KrajPobjeda){cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl<<"Bravo,obisli ste sva sigurna polja"<<endl;OcistiMatricu(polja);throw runtime_error("Igra zavrsena");}
		if(s==Status::KrajPoraz){cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl<<"Nagazili ste na minu"<<endl;OcistiMatricu(polja);throw runtime_error("Igra zavrsena");}
	}
	if(komanda==Komande::PrikaziOkolinu){
		vector<vector<int>>Mat(3,vector<int>(3));
		Mat=PrikaziOkolinu(polja,x,y);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)cout<<Mat[i][j]<<" ";
			cout<<endl;
		}
	}
  if(komanda==Komande::ZavrsiIgru){OcistiMatricu(polja);throw runtime_error ("Igra zavrsena");}
  if(komanda==Komande::KreirajIgru){
  	cout<<"Unesite broj polja: ";
  	int n;cin>>n;
  	cout<<"Unesite pozicije mina: ";
  	vector<int>pom;
  	cin.ignore(10000,'\n');
  	for(;;){
  		string c;
  		getline(cin,c);
  		if(c.length()==5 && c[0]=='(' && c[2]==',' && c[4]==')'){
  		if(DaLiJeCifra(c[1],n) && DaLiJeCifra(c[3],n)){
  			pom.push_back(Broj(c[1]));
  			pom.push_back(Broj(c[3]));
  		}
 }
 if(c.length()==5 && c[0]=='(' && c[2]==',' && c[4]==')' && (DaLiJeCifra(c[1],n)==false || DaLiJeCifra(c[3],n)==false))cout<<"Greska, unesite ponovo!"<<endl;
 if(c.length()==5 && (c[0]!='(' || c[2]!=',' || c[4]!=')'))cout<<"Greska, unesite ponovo!"<<endl;
 if(c==".")break;
 if(c.length()!=5)cout<<"Greska, unesite ponovo!"<<endl;
  	}
  	int redovi(0);
  	if(pom.size()%2==0){ redovi=pom.size()/2;}
  	vector<vector<int>>v(redovi,vector<int>(2));
  	int brojac(0);
  	for(int i=0;i<redovi;i++){
  		for(int j=0;j<2;j++){v[i][j]=pom[brojac];brojac++;}
  	}
  	polja=KreirajIgru(n,v);
  	x=0;y=0;
  }
}
  
  catch(domain_error c){
  	 cout<<c.what()<<endl;
  }
  catch(out_of_range o){
  	cout<<o.what()<<endl;
  }
  catch(runtime_error r){
  	cout<<r.what()<<endl; throw;
  }
  catch(logic_error l){
  	cout<<l.what()<<endl;
  }
  
}
int main ()
{
	try{
	int x,y,x_n(0),y_n(0);
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla polja;
	for(;;){
		cout<<"Unesite komandu: ";
		if(UnosKomande(komanda,smjer,x_n,y_n,greska)){
			if(komanda==Komande::ZavrsiIgru){OcistiMatricu(polja);cout<<"Dovidjenja!"<<endl;break;}
			IzvrsiKomandu(komanda,polja,x,y,smjer,x_n,y_n);
		}
		else {
			PrijaviGresku(greska);
		}
	}
		
	}
	catch(runtime_error){
		cout<<"Dovidjenja!";
	}
	return 0;
}