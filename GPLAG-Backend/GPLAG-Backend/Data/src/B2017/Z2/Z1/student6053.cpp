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
#include <iostream>
#include <stdexcept>
#include <complex>
#include <vector>

using namespace std;

enum class Polje{Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoMina,BlokiranoPosjeceno};
enum class Smjerovi{GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status {NijeKraj,KrajPoraz,KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef vector<vector<Polje>> Tabla;
typedef vector<vector<int>> Matrica;

bool Slovo(char a){
	return ((a>='A' || a<='Z') || (a>='a' || a<='z')) ;
}
bool Broj(char a){
	a-='0';
	return a>=0 && a<=9; 
}
Tabla KreirajIgru(int n,Matrica &mine){
	Tabla d;
	d.resize(n);
	for(int i=0;i<n;i++){
		d[i].resize(n);
		for(int j=0;j<n;j++)
		d[i][j]=Polje::Prazno;
	}
	for(int i=0;i<mine.size();i++)
	if(mine[i].size()!=2)
			throw domain_error("Ilegalan format zadavanja mina\n");
	for(int i=0;i<d.size();i++)
	{
		for(int j=0;j<d[i].size();j++)
		{
			for(int k=0;k<mine.size();k++)
			{
					if(mine[k][0]>=n || mine[k][1]>=n)
						throw domain_error("Ilegalne pozicije mina\n");
					if(i==mine[k][0] || j==mine[k][1])
						d[i][j]=Polje::Mina;
			}
		}
}
return d;
}

Matrica PrikaziOkolinu(const Tabla &polja,int x,int y){
	Matrica m;
	m.resize(3);
	for(int i=0;i<3;i++)
	m[i].resize(3);
	int k=0;
	int red(0);
	int kol(0);
	for(int i=x-1;i<x-1+3;i++){
    kol=0;
		for(int j=y-1;j<y-1+3;j++)
		{
			int br;
			if(x>=polja.size() || x<0 || y<0 || y>=polja[k].size())
				throw domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji\n");
			if(i-1<polja.size() || j>-2 || j-1<polja[k].size() || i>-2 || polja[i-1][j-1]==Polje::Mina) br++;
			if(i<polja.size() || j>-2 || j+1<polja[k].size() && i>-1 && polja[i][j+1]==Polje::Mina) br++;
			if(i-1<polja.size() && j>-2 && j+1<polja[k].size() && i>0 && polja[i-1][j+1]==Polje::Mina) 	br++;
			if(i+1<polja.size() && j>-2 && j+1<polja[k].size() && i>-2 && polja[i+1][j+1]==Polje::Mina) br++;
			if(i+1<polja.size() && j>-1 && j<polja[k].size() && i>-2 && polja[i+1][j]==Polje::Mina)	br++;
			if(i<polja.size() && j>0 && j-1<polja[k].size()  && i>-1 && polja[i][j-1]==Polje::Mina)	br++;
			if(i+1<polja.size() && j>0 && j-1<polja[k].size() && i>-2 && polja[i+1][j-1]==Polje::Mina)	br++;
			if(i-1<polja.size() && j>-1 && j<polja[k].size() && i>0 && polja[i-1][j]==Polje::Mina)	br++;
			m[red][kol]=br;
			kol++;
		}
		red++;
		k++;
	}

	return m;
}
void BlokirajPolje(Tabla &polja,int a,int b) {
	if(a>=polja.size() || a<0 || b<0 || b>=polja[0].size()) throw domain_error("Polje ("+std::to_string(a)+","+std::to_string(b)+") ne postoji\n");
	if(polja[a][b]==Polje::Prazno) polja[a][b]=Polje::BlokiranoPrazno;
	if(polja[a][b]==Polje::Posjeceno) polja[a][b]=Polje::BlokiranoPosjeceno;
	if(polja[a][b]==Polje::Mina) polja[a][b]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja,int a,int b) {
	if(a>=polja.size() || a<0 || b<0 || b>=polja[0].size()) throw domain_error("Polje ("+std::to_string(a)+","+std::to_string(b)+") ne postoji\n");
	if(polja[a][b]==Polje::BlokiranoPrazno) polja[a][b]=Polje::Prazno;
	if(polja[a][b]==Polje::BlokiranoPosjeceno) polja[a][b]=Polje::Posjeceno;
	if(polja[a][b]==Polje::BlokiranoMina) polja[a][b]=Polje::Mina;
}
Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer) {
	if(polja.size()==0 || (smjer==Smjerovi::GoreLijevo and (y==0 || x==0)) || (smjer==Smjerovi::Gore and x==0) || (smjer==Smjerovi::GoreDesno and (y==polja[0].size()-1 || x==0)) || (smjer==Smjerovi::Desno and y==polja[0].size()-1) || (smjer==Smjerovi::DoljeDesno and (y==polja[0].size()-1 || x==polja.size()-1)) || (smjer==Smjerovi::Dolje and x==polja.size()-1) || (smjer==Smjerovi::DoljeLijevo and (x==polja.size()-1 || y==0)) || (smjer==Smjerovi::Lijevo and y==0))
		throw out_of_range("Izlazak van igrace table\n");
	if(smjer==Smjerovi::GoreLijevo) {
		if(polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		x--;
		y--;
	}
	if(smjer==Smjerovi::Gore) {
		if(polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		x--;
	}
	if(smjer==Smjerovi::GoreDesno) {
		if(polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		x--;
		y++;
	}
	if(smjer==Smjerovi::Desno) {
		if(polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		y++;
	}
	if(smjer==Smjerovi::DoljeDesno)
	{
		if(polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		x++;
		y++;
	}
	if(smjer==Smjerovi::Dolje)	{
		if(polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		x++;
	}
	if(smjer==Smjerovi::DoljeLijevo) {
		if(polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		x++;
		y--;
	}
	if(smjer==Smjerovi::Lijevo)	{
		if(polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoMina)
			throw logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		y--;
	}
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja[i].size();j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
for(int i=0;i<polja.size();i++) {
		for(int j=0;j<polja[i].size();j++){
			if(i==x and j==y) continue;
			bool kraj;
			kraj= (polja[i][j]!=Polje::Posjeceno and polja[i][j]!=Polje::Mina);
			if(kraj)
				return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y) {
	if(novi_x<0 or novi_y<0 or novi_x>polja.size() or novi_y>polja[x].size())
		throw out_of_range("Izlazak van igrace table\n");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja[i].size();j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	if(polja[x][y]==Polje::BlokiranoPosjeceno or polja[x][y]==Polje::BlokiranoPrazno or polja[x][y]==Polje::BlokiranoMina)
		throw logic_error("Blokirano polje\n");
	polja[x][y]=Polje::Posjeceno;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			bool kraj;
			kraj= (polja[i][j]!=Polje::Posjeceno and polja[i][j]!=Polje::Mina);
			if(kraj)
				return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) cout<<"Nerazumljiva komanda!\n";
	else if(greska==KodoviGresaka::NedostajeParametar) cout<<"Komanda trazi parametar koji nije naveden!\n";
	else if(greska==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan!\n";
	else if(greska==KodoviGresaka::SuvisanParametar) cout<<"Zadan je suvisan parametar nakon komande!\n";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	string s;
	getline(cin,s);
	while(s.length()!=0 and s[0]==' ') s.erase(s.begin()+0);
	while(s.length()!=0 and s[s.length()-1]==' ') s.erase(s.begin()+s.length()-1);
	if(!s.length()) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(!Slovo(s[0])){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(s=="K"){
		komanda=Komande::KreirajIgru;
		return true;
	}
	if(s[0]=='K' and s.length()!=1){
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}
	if(s=="Z"){
		komanda=Komande::ZavrsiIgru;
		return true;
	}
	if(s=="PO"){
		komanda=Komande::PrikaziOkolinu;
		return true;
	}
	if(s[0]=='D'){
		while(s.length()!=1 and s[1]==' ') s.erase(s.begin()+1);
		if(s.length()<3) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(s[1]!='-' and !Broj(s[1])) {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(!Broj(s[s.length()-1])) {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		int i=1;
		bool negativan;
		negativan=s[1]=='-';
		int duzina(0);
		if(negativan){
			i++;
			duzina++;
		}
		while(Broj(s[i])){
			i++;
			duzina++;
		}
		string a=s.substr(1,duzina);
		x=std::stoi(a);
		auto pomoc=i+1;
		if(!Broj(s[pomoc]) and s[pomoc]!='-') {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		negativan=s[i+1]=='-';
		i=i+1;
		duzina=0;
		if(negativan){
			i++;
			duzina++;
		}
		while(Broj(s[i])){
			i++;
			duzina++;
		}
		if(pomoc+duzina!=s.length()){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		a=s.substr(pomoc,duzina);
		y=std::stoi(a);
		komanda=Komande::Deblokiraj;
		return true;
	}
	if(s[0]=='B') {
		while(s.length()!=1 and s[1]==' ') s.erase(s.begin()+1);
		if(s.length()<3) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(s[1]!='-' and !Broj(s[1])) {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		if(!Broj(s[s.length()-1])) {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		int i=1;
		bool negativan;
		negativan=s[1]=='-';
		int duzina(0);
		if(negativan){
			i++;
			duzina++;
		}
		while(Broj(s[i])) {
			i++;
			duzina++;
		}
		string a=s.substr(1,duzina);
		x=std::stoi(a);
		auto pomoc=i+1;
		if(!Broj(s[pomoc]) and s[pomoc]!='-') {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		negativan=s[i+1]=='-';
		i=i+1;
		duzina=0;
		if(negativan){
			i++;
			duzina++;
		}
		while(Broj(s[i])){
			i++;
			duzina++;
		}
		if(pomoc+duzina!=s.length()){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		a=s.substr(pomoc,duzina);
		y=std::stoi(a);
		komanda=Komande::Blokiraj;
		return true;
	}
	if(s[0]=='P' and s[1]=='>'){
		while(s.length()!=2 and s[2]==' ') s.erase(s.begin()+2);
		if(s.length()<4)
		{
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(s[2]!='-' and !Broj(s[2])){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(!Broj(s[s.length()-1])){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		int i=2;
		bool negativan;
		negativan=s[2]=='-';
		int duzina(0);
		if(negativan){
			i++;
			duzina++;
		}
		while(Broj(s[i])){
			i++;
			duzina++;
		}
		string a=s.substr(2,duzina);
		x=std::stoi(a);
		auto pomoc=i+1;
		if(!Broj(s[pomoc]) and s[pomoc]!='-'){
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		negativan=s[i+1]=='-';
		i=i+1;
		duzina=0;
		if(negativan){
			i++;
			duzina++;
		}
		while(Broj(s[i])){
			i++;
			duzina++;
		}
		if(pomoc+duzina!=s.length()){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		a=s.substr(pomoc,duzina);
		y=std::stoi(a);
		komanda=Komande::PomjeriDalje;
		return true;
	}
	if(s[0]=='P' and s[1]=='1'){
		while(s.length()!=2 and s[2]==' ')
			s.erase(s.begin()+2);
		if(s.length()<3){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!Slovo(s[2])){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(s.length()>5){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(s[2]=='G'){
			if(s[3]=='L'){
				smjer=Smjerovi::GoreLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(s[3]=='D'){
				smjer=Smjerovi::GoreDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(s.length()==3){
				smjer=Smjerovi::Gore;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
		}
		if(s[2]=='L' and s.length()==3){
			smjer=Smjerovi::Lijevo;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		}
		if(s[2]=='D'){
			if(s[3]=='o'){
				if(s[4]=='D'){
					smjer=Smjerovi::DoljeDesno;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
				if(s[4]=='L'){
					smjer=Smjerovi::DoljeLijevo;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
				if(s.length()==4){
					smjer=Smjerovi::Dolje;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
			}
			if(s.length()==3){
				smjer=Smjerovi::Desno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
		}
		if(s[2]=='L' and s.length()==3){
			smjer=Smjerovi::Lijevo;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		}
	}
	greska=KodoviGresaka::PogresnaKomanda;
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	Status f=Status::NijeKraj;
	if(komanda==Komande::PomjeriJednoMjesto) {
		f=Idi(polja,x,y,p_smjer);
		if(f==Status::KrajPobjeda){
			cout<<"Bravo, obisli ste sva sigurna polja\n";
			komanda=Komande::ZavrsiIgru;
		}
		else if(f==Status::KrajPoraz){
			cout<<"Nagazili ste minu\n";
			komanda=Komande::ZavrsiIgru;
		}
		else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	}
	if(komanda==Komande::PomjeriDalje) {
		f=Idi(polja,x,y,p_x,p_y);
		if(f==Status::KrajPobjeda) {
			cout<<"Bravo, obisli ste sva sigurna polja\n";
			komanda=Komande::ZavrsiIgru;
		}
		if(f==Status::KrajPoraz) {
			cout<<"Nagazili ste minu\n";
			komanda=Komande::ZavrsiIgru;
		}
		else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	}
	if(komanda==Komande::Blokiraj) BlokirajPolje(polja,p_x,p_y);
	if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,p_x,p_y);
	if(komanda==Komande::PrikaziOkolinu) {
		auto frk=PrikaziOkolinu(polja,x,y);
		for(auto a:frk) {
			for(auto b:a)
				cout<<b<<" ";
			cout<<"\n";
		}
	}
	if(komanda==Komande::ZavrsiIgru) {
		for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja[i].size();j++)
				polja[i][j]=Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::KreirajIgru) {
		cout<<"Unesite broj polja: ";
		int t;
		cin>>t;
		while(!cin) {
			cout<<"Greska, unesite ponovo!\n";
			cin.clear();
			cin.ignore(10000,'\n');
			cin>>t;
		}
		cin.ignore(10000,'\n');
		Matrica mine;
		cout<<"Unesite pozicije mina: ";
		int j=0;
		for(;;)
		{
			if(cin.peek()=='.') {
				cin.ignore(10000,'\n'); break;
			}
			string o;
			getline(cin,o);
			if(o.length()<5) {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			if(o[0]!='(' or (!Broj(o[1]) and o[1]!='-') or o[o.length()-1]!=')') {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			bool negativan=false;
			if(o[0]=='-' and Broj(o[1])) negativan=true;
			if(o[0]=='-' and !Broj(o[1])) {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			int duzina=0;
			int i=1;
			if(negativan) {
				i++;
				duzina++;
			}
			while(Broj(o[i])) {
				i++;
				duzina++;
			}
			if(o[i]!=',') {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			auto r=o.substr(1,duzina);
			auto a=std::stoi(r);
			duzina=0;
			i++;
			if(o[i]=='-' and Broj(o[i+1])) negativan=true;
			if(o[0]=='-' and !Broj(o[i+1])) {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			auto pomoc=i;
			if(negativan){
				i++;
				duzina++;
			}
			while(Broj(o[i])){
				i++;
				duzina++;
			}
			if(o[i]!=')') {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			r=o.substr(pomoc,duzina);
			auto b=std::stoi(r);
			if(a<0 or a>=t or b<0 or b>=t) {
				cout<<"Greska, unesite ponovo!\n";
				continue;
			}
			if(a==0 and b==0) {
				cout<<"Greska, unesite ponovo!\n"; continue;
			}
			j++;
			mine.resize(j);
			mine[j-1].push_back(a);
			mine[j-1].push_back(b);
		}
		try	{
			polja=KreirajIgru(t,mine);
		}
		catch(std::domain_error e) {
			cout<<e.what();
		}
	}
}

int main () {
	Smjerovi smjer;
	Komande komanda;
	KodoviGresaka greska;
	int x=0;
	int y=0;
	int p_x=0;
	int p_y=0;;
	Tabla polja;
	try {
		for(;;) {
			try {
				cout<<"Unesite komandu: ";
				bool mo=UnosKomande(komanda,smjer,p_x,p_y,greska);
				if(mo){
					IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
				}
				else {
					PrijaviGresku(greska);
				}
			}
			catch(std::domain_error e) {
				cout<<e.what(); continue;
			}
			catch(std::out_of_range e) {
				cout<<e.what(); continue;
			}
			catch(std::logic_error e) {
				cout<<e.what(); continue;
			}
		}
	}
	catch(std::runtime_error) { cout<<"Dovidjenja!\n"; }
	return 0;
}