#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1E-10;

typedef pair<double, double> Tacka;

class Trougao {
		Tacka tacke[3];
		static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
			return t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
		}

	public:
		Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
			if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
			tacke[0]=t1; tacke[1]=t2; tacke[2]=t3;
		}
		void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
			if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
			tacke[0].first=t1.first; tacke[1].first=t2.first; tacke[2].first=t3.first;
			tacke[0].second=t1.second; tacke[1].second=t2.second; tacke[2].second=t3.second;
		}
		void Postavi(int indeks, const Tacka &t) {
			if(indeks!=0 && indeks!=1 && indeks!=2) throw range_error("Nekorektan indeks");
			tacke[indeks]=t;
			if(Orijentacija(tacke[0],tacke[1],tacke[2])==0) throw domain_error("Nekorektne pozicije tjemena");
		}
		static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
			int izraz(Izraz(t1, t2, t3));
			if(izraz>0) return 1;
			else if(izraz<0) return -1;
			return 0;
		}
		Tacka DajTjeme(int indeks) const {
			if(indeks!=0 && indeks!=1 && indeks!=2) throw range_error("Nekorektan indeks");
			return tacke[indeks];
		}
		double DajStranicu(int indeks) const {
			if(indeks!=0 && indeks!=1 && indeks!=2) throw range_error("Nekorektan indeks");
			if(indeks==0) return sqrt((tacke[1].first-tacke[2].first)*(tacke[1].first-tacke[2].first)
				+ (tacke[1].second-tacke[2].second)*(tacke[1].second-tacke[2].second));
			else if(indeks==1) return sqrt((tacke[0].first-tacke[2].first)*(tacke[0].first-tacke[2].first)
				+ (tacke[0].second-tacke[2].second)*(tacke[0].second-tacke[2].second));
			return  sqrt((tacke[0].first-tacke[1].first)*(tacke[0].first-tacke[1].first)
				+ (tacke[0].second-tacke[1].second)*(tacke[0].second-tacke[1].second));
		}
		double DajUgao(int indeks) const {
			if(indeks!=0 && indeks!=1 && indeks!=2) throw range_error("Nekorektan indeks");
			double a, b, c;
			if(indeks==0) {
				a=DajStranicu(0); b=DajStranicu(1); c=DajStranicu(2);
			}
			else if(indeks==1) {
				a=DajStranicu(1); b=DajStranicu(0); c=DajStranicu(2);
			}
			else {
				a=DajStranicu(2); b=DajStranicu(1); c=DajStranicu(0);
			}
			return acos( (b*b+c*c-a*a) / (2*b*c) );
		}
		Tacka DajCentar() const {
			Tacka centar;
			centar.first=(tacke[0].first+tacke[1].first+tacke[2].first)/3;
			centar.second=(tacke[0].second+tacke[1].second+tacke[2].second)/3;
			return centar;
		}
		double DajObim() const {
			return DajStranicu(0)+DajStranicu(1)+DajStranicu(2);
		}
		double DajPovrsinu() const {
			return abs(Izraz(tacke[0], tacke[1], tacke[2]))/2;
		}
		bool DaLiJePozitivnoOrijentiran() const {
			if((Orijentacija(tacke[0], tacke[1], tacke[2]))==1) return true;
			return false;
		}
		bool DaLiJeUnutra(const Tacka &t) const {
			if( (Orijentacija(tacke[0],t ,tacke[2])==0) || (Orijentacija(tacke[0], t, tacke[1])==0) || (Orijentacija(t, tacke[1], tacke[2])==0))
				return false;
			double p1=abs(Izraz(tacke[0], tacke[1], t))/2, p2=abs(Izraz(tacke[0], t, tacke[2]))/2,
				p3=abs(Izraz(t, tacke[1], tacke[2]))/2, p=DajPovrsinu();
			if((p1+p2+p3)-p<eps) return true;
			return false;
		}
		void Ispisi() {
			cout << "((" << tacke[0].first << "," << tacke[0].second << "),("
				<< tacke[1].first << "," << tacke[1].second << "),("
				<< tacke[2].first << "," << tacke[2].second << "))";
		}
		void Transliraj(double delta_x, double delta_y) {
			tacke[0].first+=delta_x; tacke[0].second+=delta_y;
			tacke[1].first+=delta_x; tacke[1].second+=delta_y;
			tacke[2].first+=delta_x; tacke[2].second+=delta_y;
		}
		void Centriraj(const Tacka &t) {
			int delta_x=t.first, delta_y=t.second;
			tacke[0].first+=delta_x; tacke[0].second+=delta_y;
			tacke[1].first+=delta_x; tacke[1].second+=delta_y;
			tacke[2].first+=delta_x; tacke[2].second+=delta_y;
		}
		void Rotiraj(const Tacka &t, double ugao) {
			double stari_x=tacke[0].first, stari_y=tacke[0].second;
			tacke[0].first = t.first + (stari_x - t.first) * cos(ugao) - (stari_y - t.second) * sin(ugao);
			tacke[0].second = t.second + (stari_x - t.first) * sin(ugao) + (stari_y - t.second) * cos(ugao);
			
			stari_x=tacke[1].first, stari_y=tacke[1].second;
			tacke[1].first = t.first + (stari_x - t.first) * cos(ugao) - (stari_y - t.second) * sin(ugao);
			tacke[1].second = t.second + (stari_x - t.first) * sin(ugao) + (stari_y - t.second) * cos(ugao);
			
			stari_x=tacke[2].first, stari_y=tacke[2].second;
			tacke[2].first = t.first + (stari_x - t.first) * cos(ugao) - (stari_y - t.second) * sin(ugao);
			tacke[2].second = t.second + (stari_x - t.first) * sin(ugao) + (stari_y - t.second) * cos(ugao);
		}
		void Rotiraj(double ugao) {
			(*this).Rotiraj((*this).DajCentar(), ugao);
		}
		void Skaliraj(const Tacka &t, double faktor) {
			if(abs(faktor)<eps) throw domain_error("Nekorektan faktor skaliranja");
			if(faktor<0) (*this).Rotiraj(4*atan(1));
			if(tacke[0]!=t) {
				tacke[0].first=t.first+faktor*(tacke[0].first-t.first);
				tacke[0].second=t.second+faktor*(tacke[0].second-t.second);
			}
			if(tacke[1]!=t) {
				tacke[1].first=t.first+faktor*(tacke[1].first-t.first);
				tacke[1].second=t.second+faktor*(tacke[1].second-t.second);
			}
			if(tacke[2]!=t) {
				tacke[2].first=t.first+faktor*(tacke[2].first-t.first);
				tacke[2].second=t.second+faktor*(tacke[2].second-t.second);
			}
		}
		void Skaliraj(double faktor) {
			(*this).Skaliraj((*this).DajCentar(), faktor);
		}
		friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
		friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
		friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

double Funkcija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
			return t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
		}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
	int brojac(0);
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(t1.tacke[i]==t2.tacke[j]) {
				brojac++;
				break;
			}
		}
	}
	if(brojac==3) return true;
	return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
	if(DaLiSuIdenticni(t1,t2)==true) return true;
	int indeks(-1);
	for(int i=0; i<3; i++) {
		if(abs(t1.DajUgao(0)-t2.DajUgao(i))<eps) {
			indeks=i;
			break;
		}
	} 
	if(indeks==-1) return false;
	
	if(indeks==0) {
		if(t1.DaLiJePozitivnoOrijentiran()==true) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(a-x)<eps && abs(b-y)<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(b-x)<eps && abs(a-y)<eps) return true;
				return false;
			}
		}
		if(t1.DaLiJePozitivnoOrijentiran()==false) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(a-y)<eps && abs(b-x)<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(b-y)<eps && abs(a-x)<eps) return true;
				return false;
			}
		}
	}
	
	if(indeks==1) {
		if(t1.DaLiJePozitivnoOrijentiran()==true) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(a-x)<eps && abs(b-y)<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(b-x)<eps && abs(a-y)<eps) return true;
				return false;
			}
		}
		if(t1.DaLiJePozitivnoOrijentiran()==false) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(a-y)<eps && abs(b-x)<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(b-y)<eps && abs(a-x)<eps) return true;
				return false;
			}
		}
	}
	if(indeks==2) {
		if(t1.DaLiJePozitivnoOrijentiran()==true) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(a-x)<eps && abs(b-y)<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(b-x)<eps && abs(a-y)<eps) return true;
				return false;
			}
		}
		if(t1.DaLiJePozitivnoOrijentiran()==false) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(a-y)<eps && abs(b-x)<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(b-y)<eps && abs(a-x)<eps) return true;
				return false;
			}
		}
	}
	return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
	int indeks(-1);
	for(int i=0; i<3; i++) {
		if(abs(t1.DajUgao(0)-t2.DajUgao(i))<eps) {
			indeks=i;
			break;
		}
	} 
	if(indeks==-1) return false;
	
	if(indeks==0) {
		if(t1.DaLiJePozitivnoOrijentiran()==true) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(abs(a/x)-abs(b/y))<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(abs(b/x)-abs(a/y))<eps) return true;
				return false;
			}
		}
		if(t1.DaLiJePozitivnoOrijentiran()==false) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(abs(a/y)-abs(b/x))<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(1), b=t2.DajStranicu(2);
				if(abs(abs(b/y)-abs(a/x))<eps) return true;
				return false;
			}
		}
	}
	
	if(indeks==1) {
		if(t1.DaLiJePozitivnoOrijentiran()==true) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(abs(a/x)-abs(b/y))<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(abs(b/x)-abs(a/y))<eps) return true;
				return false;
			}
		}
		if(t1.DaLiJePozitivnoOrijentiran()==false) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(abs(a/y)-abs(b/x))<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(2), b=t2.DajStranicu(0);
				if(abs(abs(b/y)-abs(a/x))<eps) return true;
				return false;
			}
		}
	}
	if(indeks==2) {
		if(t1.DaLiJePozitivnoOrijentiran()==true) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(abs(a/x)-abs(b/y))<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(abs(b/x)-abs(a/y))<eps) return true;
				return false;
			}
		}
		if(t1.DaLiJePozitivnoOrijentiran()==false) {
			double x=t1.DajStranicu(1), y=t1.DajStranicu(2);
			if(t2.DaLiJePozitivnoOrijentiran()==true) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(abs(a/y)-abs(b/x))<eps) return true;
				return false;
			}
			else if(t2.DaLiJePozitivnoOrijentiran()==false) {
				double a=t2.DajStranicu(0), b=t2.DajStranicu(1);
				if(abs(abs(b/y)-abs(a/x))<eps) return true;
				return false;
			}
		}
	}
	return false;
}



int main ()
{ 
	try { 
	cout << "Koliko zelite kreirati trouglova: ";
	int n;
	cin >> n;
	vector<shared_ptr<Trougao>> vec(n);
	double x1,y1,x2,y2,x3,y3;
	for(int i=1; i<=n; i++) { 
		ponovo:
		cout << "Unesite podatke za " << i << ". trougao (x1 y1 x2 y2 x3 y3): ";
		try {
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			Trougao pomocni=Trougao(make_pair(x1,y1),make_pair(x2,y2),make_pair(x3,y3));
			vec[i-1]=make_shared<Trougao>(pomocni);
		}
		catch(domain_error) {
			cout << "Nekorektne pozicije tjemena, ponovite unos! \n";
			goto ponovo;
		}
	}
	cout << "Unesite vektor translacije (dx dy): ";
	double dx, dy;
	cin >> dx >> dy;
	cout << "Unesite ugao rotacije: ";
	double ugao;
	cin >> ugao;
	cout << "Unesite faktor skaliranja: ";
	double faktor;
	cin >> faktor;
	transform(vec.begin(), vec.end(), vec.begin(), [dx,dy,ugao,faktor](shared_ptr<Trougao> trokutic) ->shared_ptr<Trougao> {
		trokutic->Transliraj(dx,dy);
		trokutic->Rotiraj(ugao);
		trokutic->Skaliraj((*trokutic).DajTjeme(0), faktor);
		return trokutic;
	});
	sort(vec.begin(), vec.end(), [](shared_ptr<Trougao> trokutic_1, shared_ptr<Trougao> trokutic_2) {
		return trokutic_1->DajPovrsinu() < trokutic_2->DajPovrsinu();
	});
	cout << "Trouglovi nakon obavljenih transformacija: " << endl;
	for_each(vec.begin(), vec.end(), [](shared_ptr<Trougao> trokutic) {
		trokutic->Ispisi();
		cout << endl;
	});
	auto min = min_element(vec.begin(), vec.end(), [](shared_ptr<Trougao> trokutic_1, shared_ptr<Trougao> trokutic_2) {
		return trokutic_1->DajObim() < trokutic_2->DajObim();
	});
	cout << "Trougao sa najmanjim obimom: ";
	if(!vec.empty()) 5(*min)->Ispisi();
	vector<pair<Trougao,Trougao>> identicni, podudarni, slicni;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(DaLiSuIdenticni(*vec[i], *vec[j])==true) identicni.push_back(make_pair(*vec[i],*vec[j]));
			if(DaLiSuPodudarni(*vec[i], *vec[j])==true) podudarni.push_back(make_pair(*vec[i],*vec[j]));
			if(DaLiSuSlicni(*vec[i], *vec[j])==true) slicni.push_back(make_pair(*vec[i],*vec[j]));
		}
	}
	if(identicni.empty()) cout << "\nNema identicnih trouglova!" << endl;
	else {
		cout << "\nParovi identicnih trouglova: " << endl;
		for(int i=0; i<identicni.size(); i++) {
			identicni[i].first.Ispisi();
			cout << " i ";
			identicni[i].second.Ispisi();
			cout << endl;
		}
	}
	if(podudarni.empty()) cout << "Nema podudarnih trouglova!" << endl;
	else {
		cout << "Parovi podudarnih trouglova: " << endl;
		for(int i=0; i<podudarni.size(); i++) {
			podudarni[i].first.Ispisi();
			cout << " i ";
			podudarni[i].second.Ispisi();
			cout << endl;
		}
	}
	if(podudarni.empty()) cout << "Nema slicnih trouglova!" << endl;
	else {
		cout << "Parovi slicnih trouglova: " << endl;
		for(int i=0; i<slicni.size(); i++) {
			slicni[i].first.Ispisi();
			cout << " i ";
			slicni[i].second.Ispisi();
			cout << endl;
		}
	}
	}
	catch(range_error re) {
		cout << re.what();
	}
	catch(domain_error de) {
		cout << de.what();
	}
	return 0;
}