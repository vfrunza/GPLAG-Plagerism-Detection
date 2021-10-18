/*B 2016/2017, Zadaća 1, Zadatak 1 */

#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;
using std::endl;


vector<int> BrisanjeDuplikata(vector<int> dupli){
	//Dvostrukom for-petljom svaki element poredimo sa svakim i brisemo one koji su jednaki
	for(int i=0; i<dupli.size(); i++){
		for(int j=i+1; j<dupli.size(); j++){
			if(dupli[i]==dupli[j]){
				dupli.erase(dupli.begin() + j);
				j--;
			}
		}
	}
	
	return dupli;
}

int BrojiTernarneCifre(int broj){
	//Vektor u koji skladistimo pojedinacne cifre unesenog broja u ternarnom sistemu
	vector<int> pretvoreni;
	
	//
	if(broj==0)
	
	//Loop koji konvertuje broj u ternarni sistem, cije se cifre stavljaju u vektor "pretvoreni"
	while(broj){
		pretvoreni.push_back(broj%3);
		broj/=3;
	}
	
	// Za testiranje pravilnog funkcionisanja
	/*
	for(int i=pretvoreni.size()-1; i>=0; i--){
		cout << pretvoreni[i] << " ";
	}
	*/
	
	//Broji koliko se puta pojedine cifre javljaju u ternarnom zapisu
	vector<int> brojevi{0, 0, 0};
	for(int i=0; i<pretvoreni.size(); i++){
		if(pretvoreni[i]==0) brojevi[0]++;
		if(pretvoreni[i]==1 || pretvoreni[i]==-1) brojevi[1]++;
		if(pretvoreni[i]==2 || pretvoreni[i]==-2) brojevi[2]++;
	}
	
	//Uvod logickih vrijednosti na osnovu kojih vracamo adekvatan rezultat, bitno je da su FALSE po defaultu
	bool parni(false);
	bool neparni(false);
	
	/*  Sljedeci if-statements rade tako sto gledaju sljedece stvari:
		1) Da li se cifra ikako javlja u ternarnom zapisu broja?
		2) Ako se javlja, vidi ako se javlja paran ili neparan broj puta i postavi odgovarajucu logicku vrijednost na TRUE
		3) Ako su obje logicke vrijednosti postavljene na true, to znaci da imamo i parne i neparne, sto nama ne treba
	*/
	
	//Posmatra nule
	if(brojevi[0]){
		if(brojevi[0]%2) neparni=true;
		else parni=true; 
		
		if(parni){
			if(neparni) return 0;
		}
		
		if(neparni){
			if(parni) return 0;
		}
	}
	
	//Posmatra jedinice
	if(brojevi[1]){
		if(brojevi[1]%2) neparni=true;
		else parni=true; 
		
		if(parni){
			if(neparni) return 0;
		}
		
		if(neparni){
			if(parni) return 0;
		}
	}
	
	//Posmatra dvice
	if(brojevi[2]){
		if(brojevi[2]%2) neparni=true;
		else parni=true; 
		
		if(parni){
			if(neparni) return 0;
		}
		
		if(neparni){
			if(parni) return 0;
		}
	}
	
	//Nakon ovih provjera je broj SIGURNO ili odvratan ili opak, vracajuci "1" za odvratne ili "2" za opake:
	if(neparni) return 1;
	if(parni) return 2;
	
	//Ovo se vraca JEDINO ako se prizovu crne magije pa funkcija poludi, tako da vrati nesto i ne eksplodira, inace program zavrsi sa nulom
	return 0;
}

vector<int> IzdvojiGadne(vector<int> vek, bool opaki){
	//Vektor koji vracamo
	vector<int> noviVek;
	vek = BrisanjeDuplikata(vek);
	int rezultat;
	for(int i=0; i<vek.size(); i++){
		rezultat = BrojiTernarneCifre(vek[i]);
		
		//U slucaju da se traze opaki brojevi
		if(opaki){
			if(rezultat==2) noviVek.push_back(vek[i]);
			
		} //U slucaju da se traze odvratni brojevi
		else {
			if(rezultat==1) noviVek.push_back(vek[i]);
		}
		
		//if(rezultat==0) cout << "NESTO NE FERCERA ";
   }
   
	return noviVek;
}

int main ()
{
	//Unos brojeva
	int broj;
	vector<int> v;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	cin >> broj;
	while(broj){
		v.push_back(broj);
		cin >> broj;
	}
	
	vector<int> opaki = IzdvojiGadne(v, 1);
	vector<int> odvratni = IzdvojiGadne(v, 0);
	
	cout << "Opaki: ";
	for(int i=0; i<opaki.size(); i++){
		cout << opaki[i] << " ";
	}
	
	cout << endl;
	cout << "Odvratni: ";
	for(int i=0; i<odvratni.size(); i++){
		cout << odvratni[i] << " ";
	}
	
	return 0;
}

/*
vector<int> IzdvojiGadne(vector<int> vek, bool opaki){
	//Vektor koji vracamo
	vector<int> noviVek;
	vek = BrisanjeDuplikata(vek);
	int rezultat;
	for(int i=0; i<vek.size(); i++){
		rezultat = BrojiTernarneCifre(vek[i]);
		
		//U slucaju da se traze opaki brojevi
		if(opaki){
			if(rezultat==2) noviVek.push_back(vek[i]);
			
		} //U slucaju da se traze odvratni brojevi
		else {
			if(rezultat==1) noviVek.push_back(vek[i]);
		}
		
		//if(rezultat==0) cout << "NESTO NE FERCERA ";
   }
   
	return noviVek;
}
*/