/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <complex>
#include <string>
using namespace std;
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar,Null
};

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum  class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina,

};
enum  class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo

};
typedef vector<vector<int>> Matrica;
typedef vector<vector<Polje>>Tabla;
Tabla KreirajTablu(int broj_redova, int broj_kolona){
return Tabla(broj_redova, vector<Polje>(broj_kolona));	
}
Matrica KreirajMatricu(int broj_redova, int broj_kolona){
return Matrica(broj_redova, vector<int>(broj_kolona));	
}
int StringUInt(string s){
	int broj{};
	for(int i=s.size()-1;i>=0;i--)broj+=(s[i]-'0')*pow(10,s.size()-1-i);
	return broj;
}
bool Ispravnost(string x_y,int &x,int &y,KodoviGresaka &greska){
	int razmak{-1};
	for(unsigned int i=0;i<x_y.size();i++){
		if(x_y[i]==' ')razmak=i;
		else if(x_y[i]<'0' || x_y[i]>'9'){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	if(greska==KodoviGresaka::NeispravanParametar || razmak==-1){
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}
	else {
		string xS{x_y.substr(0,razmak)};
		string yS{x_y.substr(razmak+1)};
		x=StringUInt(xS);
		y=StringUInt(yS);
		
	}
	return true;
}
int SumaOkoline(const Tabla &polja,int x,int y){
	int suma=0;
	for(int k=0;k<3;k++){
		if(y>0 && y<polja[0].size()-1){
			if(x>0 && polja[x-1][y-1+k]==Polje::Mina)suma+=1;
			if(k!=1 && polja[x][y-1+k]==Polje::Mina)suma+=1;
			if(x<polja.size()-1 && polja[x+1][y-1+k]==Polje::Mina)suma+=1;
			
		}
		else if(y==polja[0].size()-1){
			if(x>0 && k>2 && polja[x-1][y-1+k]==Polje::Mina)suma+=1;
			if(k==0 && polja[x][y-1+k]==Polje::Mina)suma+=1;
			if(k<2 && x<polja.size()-1 && polja[x+1][y-1+k]==Polje::Mina)suma+=1;
			
		}
		else if(y==0){
			if(x>0 && k>0 && polja[x-1][y-1+k]==Polje::Mina)suma+=1;
			if(k>1 && polja[x][y-1+k]==Polje::Mina)suma+=1;
			if(k>0 && x<polja.size()-1 && polja[x+1][y-1+k]==Polje::Mina)suma+=1;
		}
	}
	return suma;

}
Tabla KreirajIgru(int n,const vector<vector<int> > &mine){
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[0].size();j++){
			if(mine[i].size()!=2)throw domain_error("Ilegalan format zadavanja mina");
			if(mine[i][j]>n-1 || mine[i][j]<0) throw domain_error("Ilegalne pozicije mina");
			
		}
	}
	Tabla v=KreirajTablu(n,n);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			v[i][j]=Polje::Prazno;
		}
	}
	for(int i=0;i<mine.size();i++){
		v[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return v;
}
void ZavrsiIgru(Tabla &polja){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	cout<<"Dovidjenja!";
}
Matrica PrikaziOkolinu(const Tabla &polja,int x,int y){
	Matrica v=KreirajMatricu(3,3);
	string prvi("Polje (");
	string zarez(",");
	string drugi(") ne postoji");
	string eror=prvi+(char)(x+48)+zarez+(char)(y+48)+drugi;
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw domain_error(eror);
	for(int k=0;k<3;k++){
		if(y>0 && y<polja[0].size()-1){
			if(x>0)v[0][k]=SumaOkoline(polja,x-1,y-1+k);
			v[1][k]=SumaOkoline(polja,x,y-1+k);
			if(x<polja.size()-1)v[2][k]=SumaOkoline(polja,x+1,y-1+k);
		}
		else if(y==0){
			if(x>0)v[0][k]=SumaOkoline(polja,x-1,y+k);
			if(k>1)v[1][k]=SumaOkoline(polja,x,y-1+k);
			if(x<polja.size()-1)v[2][k]=SumaOkoline(polja,x+1,y+k);
			
		}
		else if(y==polja.size()-1){
			if(x>0 && k<2)v[0][k]=SumaOkoline(polja,x-1,y-1+k);
			if(k==0)v[1][k]=SumaOkoline(polja,x,y-1+k);
			if(k<2 && x<polja.size()-1)v[2][k]=SumaOkoline(polja,x+1,y-1+k);
		}
	}
	return v;
}
void BlokirajPolje(Tabla &polja,int x,int y){
	string prvi("Polje (");
	string zarez(",");
	string drugi(") ne postoji");
	string eror=prvi+(char)(x+48)+zarez+(char)(y+48)+drugi;
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw domain_error(eror);
			if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
			if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
			if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja,int x,int y){
	string prvi("Polje (");
	string zarez(",");
	string drugi(") ne postoji");
	string eror=prvi+(char)(x+48)+zarez+(char)(y+48)+drugi;
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw domain_error(eror);
			if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
			if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
			if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
}
Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer){
	polja[x][y]=Polje::Posjeceno;
if(smjer==Smjerovi::GoreLijevo && x>0 && y>0){
	x=x-1;
	y=y-1;
}	
else if(smjer==Smjerovi::Gore && x>0)x=x-1;
else if(smjer==Smjerovi::GoreDesno && x>0 && y<polja.size()-1){
x=x-1;
y=y+1;
}	
else if(smjer==Smjerovi::Desno  && y<polja.size()-1){
	y=y+1;
}	
else if(smjer==Smjerovi::DoljeDesno && x<polja.size()-1 && y<polja[0].size()-1){
	x=x+1;
	y=y+1;
}	
else if(smjer==Smjerovi::Dolje && x<polja.size()-1){
	x=x+1;
}	
else if(smjer==Smjerovi::DoljeLijevo && x<polja.size()-1 && y>0){
	x=x+1;
	y=y-1;
}	
else if(smjer==Smjerovi::Lijevo && y>0){
	y=y-1;
}	
else throw out_of_range("Izlazak van igrace table");
if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
int br=0;
for(int i=0;i<polja.size();i++){
	for(int j=0;j<polja[0].size();j++){
		if(polja[i][j]!=Polje::Prazno || polja[i][j]==Polje::Posjeceno || polja[i][j]==Polje::Mina)br++;
}
}
if(polja[x][y]==Polje::Mina){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[0].size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	return Status::KrajPoraz;
}
else if(br==polja.size()*polja.size()-1)return Status::KrajPobjeda;
else return Status::NijeKraj;
}
Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size())throw out_of_range("Izlazak van igrace table");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno) throw logic_error("Blokirano polje");
	int br=0;
for(int i=0;i<polja.size();i++){
	for(int j=0;j<polja[0].size();j++){
		if(polja[i][j]!=Polje::Prazno || polja[i][j]==Polje::Posjeceno || polja[i][j]==Polje::Mina)br++;
}
}
if(polja[x][y]==Polje::Mina){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[0].size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	return Status::KrajPoraz;
}
else if(br==polja.size()*polja.size()-1)return Status::KrajPobjeda;
else return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)cout<<"Nerazumljiva komanda!"<<endl;
	else if(greska==KodoviGresaka::NedostajeParametar)cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	else if(greska==KodoviGresaka::NeispravanParametar)cout<<"Parametar komande nije ispravan!"<<endl;
	else if(greska==KodoviGresaka::SuvisanParametar)cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}
bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	string unos;
	getline(cin>>ws,unos);
	if(unos[0]=='K'){
		if(unos.size()==1)komanda=Komande::KreirajIgru;
		else greska=KodoviGresaka::SuvisanParametar;
	}
	else if(unos[0]=='Z'){
		if(unos.size()==1)komanda=Komande::ZavrsiIgru;
		else greska=KodoviGresaka::SuvisanParametar;
	}
	else if(unos.substr(0,2)=="PO"){
		if(unos.size()==2)komanda=Komande::PrikaziOkolinu;
		else greska=KodoviGresaka::SuvisanParametar;
	}
	else if(unos.substr(0,2)=="B " || unos.substr(0,2)=="D "){
		if(unos.size()>2){
			string x_y{unos.substr(2)};
			if(isspace(x_y[3]) && x_y.length()>3)greska=KodoviGresaka::SuvisanParametar;
			else if(Ispravnost(x_y,x,y,greska)){
				if(unos[0]=='B')komanda=Komande::Blokiraj;
				else if(unos[0]=='D')komanda=Komande::Deblokiraj;
			}
		}
		else greska=KodoviGresaka::NedostajeParametar;
	}
	else if(unos.substr(0,1)=="B" || unos.substr(0,1)=="D"){
		if(unos.substr(1,1)!=" " || unos.substr(1,1)!=" ")greska=KodoviGresaka::NedostajeParametar;
	}
	else if(unos[0]=='P'){
		if(unos[1]=='>'){
			if(unos.size()==2)greska=KodoviGresaka::NedostajeParametar;
			else{
				string x_y{unos.substr(3)};
				if(isspace(x_y[3]) && x_y.length()>3)greska=KodoviGresaka::SuvisanParametar;
				else if(Ispravnost(x_y,x,y,greska))komanda=Komande::PomjeriDalje;
			}
		}
		else if(unos[1]=='1'){
			komanda=Komande::PomjeriJednoMjesto;
			if(unos.size()==2)greska=KodoviGresaka::NedostajeParametar;
		else{
			string pravac{unos.substr(3)};
			pravac+="abc";
			if((isspace(pravac[1]) || isspace(pravac[2]) || isspace(pravac[3])) && pravac.length()>3)greska=KodoviGresaka::SuvisanParametar;
			pravac={unos.substr(3)};
			if(pravac=="GL")smjer=Smjerovi::GoreLijevo;
			else if(pravac=="G")smjer=Smjerovi::Gore;
			else if(pravac=="GD")smjer=Smjerovi::GoreDesno;
			else if(pravac=="D")smjer=Smjerovi::Desno;
			else if(pravac=="DoD")smjer=Smjerovi::DoljeDesno;
			else if(pravac=="Do")smjer=Smjerovi::Dolje;
			else if(pravac=="DoL")smjer=Smjerovi::DoljeLijevo;
			else if(pravac=="L")smjer=Smjerovi::Lijevo;
			else greska=KodoviGresaka::NeispravanParametar;
		}
			
		}
		else if(unos[1]!='1' || unos[1]!='>')greska=KodoviGresaka::PogresnaKomanda;
		else greska=KodoviGresaka::NedostajeParametar;
		
	}
	else greska=KodoviGresaka::PogresnaKomanda;
	if((int)greska<4)return false;
	else return true;
}
void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y,Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0){
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
		Status idi=Idi(polja,x,y,p_smjer);
		if(idi==Status::KrajPobjeda){
			
		cout<<"Bravo,obisli ste sva sigurna polja"<<endl;
		ZavrsiIgru(polja);
		throw runtime_error("Igra zavrsena");
		}
	else if(idi==Status::KrajPoraz){
		cout<<"Nagazili ste na minu"<<endl;
		ZavrsiIgru(polja);
		throw runtime_error("Igra zavrsena");
	}
	else {
		cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"""<<endl;
	}
		}
		catch(out_of_range vani){
			cout<<vani.what()<<endl;
		}
		catch(logic_error izuzetak){
			cout<<izuzetak.what()<<endl;
		}
	}

else if(komanda==Komande::PomjeriDalje){
	try{
	Status idi=Idi(polja,x,y,p_x,p_y);
	if(idi==Status::KrajPobjeda){
		cout<<"Bravo,obisli ste sva sigurna polja"<<endl;	
		ZavrsiIgru(polja);
		throw runtime_error("Igra zavrsena");
	}
	else if(idi==Status::KrajPoraz){
		cout<<"Nagazili ste na minu"<<endl;
		ZavrsiIgru(polja);
		throw runtime_error("Igra zavrsena");
	}
	else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"""<<endl;
	}
	catch(out_of_range vani){
		cout<<vani.what()<<endl;
	}
	catch(logic_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
}

else if(komanda==Komande::Blokiraj){
	try{
		BlokirajPolje(polja,p_x,p_y);
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
}
else if(komanda==Komande::Deblokiraj){
	try{
		DeblokirajPolje(polja,p_x,p_y);
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
}
else if(komanda==Komande::PrikaziOkolinu){
	Matrica v=PrikaziOkolinu(polja,x,y);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
else if(komanda==Komande::ZavrsiIgru){
	ZavrsiIgru(polja);
    throw runtime_error("Igra zavrsena");
	
}
else if(komanda==Komande::KreirajIgru){
	int n;
	Matrica zadnja;
	cout<<"Unesite broj polja: ";
	cin>>n;
	int a,b;
	cout<<"Unesite pozicije mina: ";
	char znak1,znak2,znak3;
	while(1){
		vector<int>v;
		v={};
		cin>>znak1;
		if(znak1=='.')break;
		else if(znak1!='('){
			cin.ignore(1000,'\n');
			cout<<"Greska, unesite ponovo!"<<endl;
			continue;
		}
		cin>>a;
		if(!cin || a>=n || a<0){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Greska, unesite ponovo!"<<endl;
			continue;
		}
		cin>>znak2;
		if(znak2!=','){
			cin.ignore(1000,'\n');
			cout<<"Greska, unesite ponovo!"<<endl;
			continue;
		}
		cin>>b;
		if(!cin || b>=n || b<0){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Greska, unesite ponovo!"<<endl;
			continue;
		}
		cin>>znak3;
		if(znak3!=')'){
			cin.ignore(1000,'\n');
			cout<<"Greska, unesite ponovo!"<<endl;
			continue;
		}
		v.push_back((int)a);
		v.push_back((int)b);
		zadnja.push_back(v);
}
polja=KreirajIgru(n,zadnja);
}
}
int main ()
{
	int x=0,y=0,p_x,p_y;
	Smjerovi smjer=Smjerovi(0);
	Tabla polja;
	Komande komanda=Komande(0);
	int br=0;
	while(1){
		cout<<"Unesite komandu: ";
		KodoviGresaka greska=KodoviGresaka(4);
		if(UnosKomande(komanda,smjer,p_x,p_y,greska)){
			if(komanda==Komande::ZavrsiIgru){
				try{IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
				}
				catch(runtime_error kraj){
				break;
				}
			}
			if(komanda==Komande::PomjeriDalje || komanda==Komande::PomjeriJednoMjesto){
				try{
					IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
				}
				catch(runtime_error kraj){
					break;
				}
			}
			else IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
		}
		else{
			PrijaviGresku(greska);
			continue;
		}
		if(br==0){
		cin.ignore(1000,'\n');
	}
		
	br++;
	}

	return 0;
}