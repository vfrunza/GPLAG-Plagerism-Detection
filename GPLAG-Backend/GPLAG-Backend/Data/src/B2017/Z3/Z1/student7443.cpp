/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
bool BinarnoPretrazivanje(double x, double y, double broj){
	bool ima=false;
	int d,g;
	g=y/2;
	while(x<=g){
    int i((d+g)/2)
    	if(i==broj){
    		ima=true;
    		break;
    		}
    		else if(i<broj) y=i-1;
    		else d=i+1;
	}
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> parovi){


	for(int i=0; i<parovi.size(); i++)
		for(int j=i+1; j<parovi.size(); j++){
			if(parovi[i].first==parovi[j].second) // ako su sa istim x 
				throw std::domain_error("Neispravni cvorovi");
			if(parovi[i].first<parovi[j].first) {
				std::pair temp;
				//sortiranje parova po x-u
	temp.first=parovi[i]first; temp.second=parovi[i].second;
				parovi[i].first=parovi[j].first; parovi[i].second=parovi[j].second;
				parovi[j].first=temp.first; parovi[j].second=temp.second;
			}


return [parovi](double x){
	if(x<parovi[0].first || x>std::end(parovi).first) throw std::range_error("Argument izvan opsega");
	std::pair interval;
	int i(0),j(1);
	while(parvi[i].first!=parovi.end().first){
		// treba tip promjeniti kod funkcije
		if(Binarno pretrazivanje(parovi[i].first,parovi[j].first,x))
		{
		interval.first=parovi[i].first; interval.second=parovi[j].first; break;}
		i++;
		j++;
	}
	x=parovi[i].second+((parovi[j].second-parovi[i].second)/(parovi[j].first-parovi[i].first))*(x-parovi[i].first);
	
	return x;

}

LinearnaInterpolacija(std::function<double(double)> f,double Xmin,double Xmax,double deltaX){
	std::vector<std::pair<double,double>> v;
	if(Xmin>Xmax || deltaX<=0) std::domain_error("Neispravni parametri");
	while (Xmin!=Xmax) {
		double y;
		y=f(Xmin);
		v.push_back(std::make_pair(Xmin,y));
		Xmin=Xmin+deltaX;
	}
	return [v](double x){
	if(x<parovi[0].first || x>std::end(parovi).first) throw std::range_error("Argument izvan opsega");
	std::pair interval;
	int i(0),j(1);
	while(parvi[i].first!=parovi.end().first){
		// treba tip promjeniti kod funkcije
		if(Binarno pretrazivanje(parovi[i].first,parovi[j].first,x))
		{
		interval.first=parovi[i].first; interval.second=parovi[j].first; break;}
		i++;
		j++;
	}
	x=parovi[i].second+((parovi[j].second-parovi[i].second)/(parovi[j].first-parovi[i].first))*(x-parovi[i].first);
	
	return x;

}
		
	
	}
}
int main ()
{
	return 0;
}
/*
#include <iostream>
#include <cmath>
#include <iomanip>

#define epsilon 0.0000001
class Ugao
{
	double radijani;

public:
	Ugao (double radijani = 0) {
		Postavi(radijani);
	}
	Ugao (int stepeni, int minute, int sekunde) {
		Postavi(stepeni, minute, sekunde);
	}
	void Postavi(double r) {
		while (r<0) r+=2*4.*atan(1);
		while (r>2*4.*atan(1)) r-=2*4.*atan(1);
		radijani=r;
	}
	void Postavi(int stepeni, int minute, int sekunde);

	double DajRadijane() const {
		return radijani;
	}

	void OcitajKalsicneJedinice(int &stepeni, int &minute, int &sekunde);

	int DajStepene() const {
		
		int step=static_cast<int>((radijani*180.)/(4.*atan(1)));
		return step;
	}
	int DajMinute() const {
		return static_cast<int>(((radijani*180.)/(4.*atan(1))-DajStepene())*60.);
	}
	int DajSekunde() const {
		return static_cast<int> ((((radijani*180.)/(4.*atan(1))-DajStepene())*60. - DajMinute() ) *60. + epsilon);
	}

	void Ispisi() const {
		std::cout<<std::fixed<<std::setprecision(5)<<DajRadijane();
	}
	void IspisiKlasicno() const {
	
		std::cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec";
	}

	Ugao &SaberiSa (const Ugao &u) {
		radijani+=u.radijani;
		this->Postavi(radijani);
		return *this;
	}
	Ugao &PomnoziSa( double x) {
		radijani*=x;
		this->Postavi(radijani);
		return *this;
	}
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProdukUglaSaBrojem (const Ugao &u, double x);
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2)
{
	Ugao u3;
	u3=u1.DajRadijane() + u2.DajRadijane();
	u3.Postavi(u3.DajRadijane());
	return u3;
}
Ugao ProduktUglaSaBrojem (const Ugao &u, double x)
{
	Ugao u3;
	u3=u.DajRadijane() * x;
	u3.Postavi(u3.DajRadijane());
	return u3;
}

void Ugao::Postavi(int stepeni, int minute, int sekunde)
{
	while(sekunde>=60) {
		sekunde-=60;
		minute++;
	}
	while (sekunde < 0) {
		sekunde+=60;
		minute--;
	}
	while(minute>=60) {
		minute-=60;
		stepeni++;
	}
	while (minute < 0) {
		minute+=60;
		stepeni--;
	}

	while (stepeni>=360) stepeni-=360;
	while (stepeni<0) stepeni+=360;

	Ugao::radijani=(((stepeni+minute/60. + sekunde/3600.) * 4.*atan(1)) / 180.);
}
void Ugao::OcitajKalsicneJedinice(int &stepeni, int &minute, int &sekunde)
{
	stepeni=DajStepene();
	minute=DajMinute();
	sekunde=DajSekunde();
}

int main ()
{
	Ugao u(90, 0, 0);

u = ProduktUglaSaBrojem(u, 5);
u.IspisiKlasicno(); std::cout << std::endl;
ProduktUglaSaBrojem(u, -5).IspisiKlasicno(); std::cout << std::endl;
	return 0;
}