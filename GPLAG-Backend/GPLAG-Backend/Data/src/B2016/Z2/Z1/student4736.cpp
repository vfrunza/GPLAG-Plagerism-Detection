#include<iostream>
#include<stdexcept>
#include<vector>

using namespace std;

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
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2){
			throw domain_error("Ilegalan format zadavanja mina");
		}
		if(mine[i][0]<0||mine[i][0]>=n|| mine[i][1]<0 || mine[i][1]>=n){
			throw domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla tabla = vector<vector<Polje>>(n,vector<Polje>(n,Polje::Prazno));
	
	for(int i=0;i<mine.size();i++){
		tabla[ mine[i][0] ][ mine[i][1] ] = Polje::Mina;		
	}
	
	
	return tabla;
	
}


string int2string(int broj){
  string rezultat;
  bool negativan=false;
  
  
  if(broj<0) {
  	negativan = true;
  	broj*=-1;
  }
  
  while(broj!=0){
    int cifra = broj%10; 
    rezultat.push_back(cifra+'0');
    
    broj/=10;
  }
  
  for(int i=0,j=rezultat.size()-1; i<j;   i++,j--){
    char temp  = rezultat[i];
    rezultat[i]  = rezultat[j];
    rezultat[j]  = temp ;
  }
  
  
  if(negativan) rezultat = "-" + rezultat;
  
  return rezultat;
}


bool ispravneKoordinate(const Tabla& polja,int x, int y){
	return x>=0&&x<polja.size()&&y>=0&&y<polja.size();
}


int brojSusjednihMina(const Tabla&polja,int x, int y){
	int brojMina=0;
	//cout<<x<<"\t"<<y<<" OVDJE!"<<endl;
		
	if(!ispravneKoordinate(polja,x,y)) return 0;
	
	vector<vector<int>> susjedi ={{x-1,y-1},{x-1,y},{x-1,y+1},{x,y-1},{x,y+1},{x+1,y-1},{x+1,y},{x+1,y+1}};
	
	for(int i=0;i<susjedi.size();i++){
		if(ispravneKoordinate(polja,susjedi[i][0],susjedi[i][1]) ){
			if(polja[ susjedi[i][0] ][susjedi[i][1]] == Polje::Mina){
				brojMina++;
			}
		}
	}
	
	return brojMina;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	if(!ispravneKoordinate(polja,x,y)){
		throw domain_error("Polje ( "+int2string(x)+", "+int2string(y)+" ) ne postoji");
	}
	
	std::vector<std::vector<int>> okolina (3,std::vector<int>(3) );
	
	
	vector<vector<int>> susjedi ={
		{x-1,y-1},
	{x-1,y},
	{x-1,y+1},
	{x,y-1},
	{x,y},
	{x,y+1},
	{x+1,y-1},
	{x+1,y},
	{x+1,y+1}
		
	};
	
	
	for(int i=0;i<okolina.size();i++){
		for(int j=0;j<okolina.size();j++){
			
			okolina[i][j] = brojSusjednihMina(polja, susjedi[i*3+j][0],susjedi[i*3+j][1]);
		}
	}
	
	
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(!ispravneKoordinate(polja,x,y)){
		throw domain_error("Polje ( "+int2string(x)+", "+int2string(y)+" ) ne postoji");
	}
	
	if(polja[x][y]==Polje::Prazno){
		polja[x][y] = Polje::BlokiranoPrazno;
	}
	else if(polja[x][y]==Polje::Posjeceno){
		polja[x][y] = Polje::BlokiranoPosjeceno;
	}
	else if(polja[x][y]==Polje::Mina){
		polja[x][y] = Polje::BlokiranoMina;
	}
	
}




void DeblokirajPolje(Tabla &polja, int x, int y){
	if(!ispravneKoordinate(polja,x,y)){
		throw domain_error("Polje ( "+int2string(x)+", "+int2string(y)+" ) ne postoji");
	}
	
	if(polja[x][y]==Polje::BlokiranoPrazno){
		polja[x][y] = Polje::Prazno;
	}
	else if(polja[x][y]==Polje::BlokiranoPosjeceno){
		polja[x][y] = Polje::Posjeceno ;
	}
	else if(polja[x][y]==Polje::BlokiranoMina){
		polja[x][y] = Polje::Mina ;
	}
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int novoX=x,novoY=y;
	switch(smjer){
		case Smjerovi::GoreLijevo :
			novoX--;novoY--;
		break;
		case Smjerovi::Gore :
			novoX--;
		break;
		case Smjerovi::GoreDesno :
			novoX--;novoY++;
		break;
		case Smjerovi::Lijevo :
			novoY--;
		break;
		case Smjerovi::Desno :
			novoY++;
		break;
		case Smjerovi::DoljeLijevo :
			novoX++;novoY--;
		break;
		case Smjerovi::Dolje :
			novoX++;
		break;
		case Smjerovi::DoljeDesno :
			novoX++;novoY++;
		break;
	}
	if(!ispravneKoordinate(polja,novoX,novoY)){
		throw out_of_range("Izlazak van igrace table");
	}
	
	if( polja[novoX][novoY]==Polje::BlokiranoPosjeceno ||
	 	polja[novoX][novoY]==Polje::BlokiranoPrazno ||
	 	polja[novoX][novoY]==Polje::BlokiranoMina ){
	 		throw logic_error("Blokirano polje");
	 	}
	 	
	 
	 if( polja[novoX][novoY]==Polje::Mina ){
	 
	 	for (int i = 0; i < polja.size(); i++) {
	 		for (int j = 0; j < polja[i].size(); j++) {
	 			polja[i][j] = Polje::Prazno;
	 			
	 		}
	 	}
	 	return Status::KrajPoraz;
	 }
	 
	 
	 polja[novoX][novoY]=Polje::Posjeceno;
	 polja[x][y]=Polje::Posjeceno;
	 x=novoX;
	 y=novoY;
	 
 	for (int i = 0; i < polja.size(); i++) {
 		for (int j = 0; j < polja[i].size(); j++) {
 			if(polja[i][j] == Polje::Prazno)
 				return Status::NijeKraj;
 			
 		}
 	}
	 
	 return Status::KrajPobjeda;
	 	
}




Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){

	if(!ispravneKoordinate(polja,novi_x,novi_y)){
		throw out_of_range("Izlazak van igrace table");
	}
	
	if( polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||
	 	polja[novi_x][novi_y]==Polje::BlokiranoPrazno ||
	 	polja[novi_x][novi_y]==Polje::BlokiranoMina ){
	 		throw logic_error("Blokirano polje");
	 	}
	 	
	 
	 if( polja[novi_x][novi_y]==Polje::Mina ){
	 
	 	for (int i = 0; i < polja.size(); i++) {
	 		for (int j = 0; j < polja[i].size(); j++) {
	 			polja[i][j] = Polje::Prazno;
	 			
	 		}
	 	}
	 	return Status::KrajPoraz;
	 }
	 
	 
	 polja[novi_x][novi_y]=Polje::Posjeceno;
	 polja[x][y]=Polje::Posjeceno;
	 x=novi_x;
	 y=novi_y;
	 
 	for (int i = 0; i < polja.size(); i++) {
 		for (int j = 0; j < polja[i].size(); j++) {
 			if(polja[i][j] == Polje::Prazno)
 				return Status::NijeKraj;
 			
 		}
 	}
	 
	 return Status::KrajPobjeda;
	 	
}


/*
void ispisiTablu(const Tabla &t){
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t[i].size(); j++) {
			if(t[i][j]==Polje::Prazno)
				cout<<0<<" ";
			else if(t[i][j]==Polje::Mina){
				cout<<1<<" ";
			}
		}
		cout<<endl;
	}
}*/




void PrijaviGresku(KodoviGresaka kodGreske){
	if(kodGreske == KodoviGresaka::PogresnaKomanda){
		cout<<"Nerazumljiva komanda!";
	}
	else if(kodGreske == KodoviGresaka::NedostajeParmetar){
		cout<<"Komanda trazi parametar koji nije naveden!";
	}
	else if(kodGreske == KodoviGresaka::NeispravanParametar){
		cout<<"Parametar komande nije ispravan!";
	}
	else if(kodGreske == KodoviGresaka::SuvisanParametar){
		cout<<"Zadan je suvisan parametar nakon komande!";
	}
}



int string2int(string s){
	for (auto z : s) {
		if(z<'0'||z>'9') throw invalid_argument("Neispravan Parametar");
	}
	int broj=0;
	for (auto z : s) {
		int cifra = z-'0';
		broj = broj*10+cifra;
	}
	
	return broj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	
	string unos;
	string k,p1,p2,ostatak;

	getline(cin,unos);
	int i=0;
	while(unos[i]==' '&&i<unos.size())i++; //razmaci na pocetku
	while(unos[i]!=' '&&i<unos.size()){ // komanda
		k.push_back(unos[i]);
		i++;
	}
	while(unos[i]==' '&&i<unos.size())i++; //razmaci poslije komande
	while(unos[i]!=' '&&i<unos.size()){ // prvi parametar
		p1.push_back(unos[i]);
		i++;
	}
	
	while(unos[i]==' '&&i<unos.size())i++; //razmaci poslije prvog parametra
	while(unos[i]!=' '&&i<unos.size()){ // drugi parametar
		p2.push_back(unos[i]);
		i++;
	}
	
	while(unos[i]==' '&&i<unos.size())i++; //razmaci poslije drugog parametra
	while(unos[i]!=' '&&i<unos.size()){ // ostatak
		ostatak.push_back(unos[i]);
		i++;
	}
	
	/*
	cout<<k<<"\n";
	cout<<p1<<"\n";
	cout<<p2<<"\n";
	cout<<ostatak<<"\n";
	cout<<"KRAJ"
	*/
	
	if(k=="P1"){
		if(p1=="GL"){
			smjer = Smjerovi::GoreLijevo;
		}
		else if(p1=="G"){
			smjer = Smjerovi::Gore;
		}
		else if(p1=="GD"){
			smjer = Smjerovi::GoreDesno;
		}
		else if(p1=="D"){
			smjer = Smjerovi::Desno;
		}
		else if(p1=="DoD"){
			smjer = Smjerovi::DoljeDesno;
		}
		else if(p1=="Do"){
			smjer = Smjerovi::Dolje;
		}
		else if(p1=="DoL"){
			smjer = Smjerovi::DoljeLijevo;
		}
		else if(p1=="L"){
			smjer = Smjerovi::Lijevo;
		}
		else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		if(p2 != ""){
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
	}
	else if(k=="P>"){
		
		
		if(p1==""||p2==""){
			greska = KodoviGresaka::NedostajeParmetar;
			return false;
		}
		
		if(ostatak!=""){
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
		try{
			int prvi  = string2int(p1);
			int drugi = string2int(p2);
			
			x= prvi;
			y=drugi;
		}
		catch(invalid_argument e){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	else if(k=="B"){
		
	}
	else if(k=="D"){
		
	}
	else if(k=="PO"){
		
	}
	else if(k=="Z"){
		
	}
	else if(k=="K"){
		
	}
	else{
	
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	return true;
}

int main ()
{
	try{
/*	Tabla mojaTabla = KreirajIgru(4,{{0,1},{1,3},{2,0},{2,1},{2,3}});
	
	//ispisiTablu(mojaTabla);
	
	
	std::vector<std::vector<int>> OKO = PrikaziOkolinu(mojaTabla,2,2);
	
	for(vector<int>v:OKO){
		for(int e:v){
			cout<<e<<" ";
		}
		cout<<endl;
	}*/
	Komande komanda;
	Smjerovi smjer;
	int x,y;
	KodoviGresaka greska;
	
	UnosKomande(komanda,smjer,x,y,greska);
	}
	catch(domain_error e){
		cout<<e.what()<<endl;
	}
	return 0;
}