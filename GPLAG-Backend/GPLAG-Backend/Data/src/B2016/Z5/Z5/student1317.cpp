/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <functional>
#include <algorithm>
#include <list>
#include <utility>
#include <stdexcept>
#include <iterator>
#include <vector>

using namespace std;

class Temperature
{
    list<int> minimum;
    list<int> maksimum;
    int maks, min;
    
    public:
        explicit Temperature(int minimum, int maksimum) : maks(maksimum), min(minimum) { if(minimum>maksimum) throw range_error("Nekorektne temperature"); }
        void RegistrirajTemperature(pair<int, int> par);
        void BrisiSve();
        void BrisiNegativneTemperature();
        int DajBrojRegistriranihTemperatura() const { return count_if(minimum.begin(), minimum.end(), bind(greater<int>(), placeholders::_1, min)); };
        int DajMinimalnuTemperaturu() const;
        int DajMaksimalnuTemperaturu() const;
        int DajBrojTemperaturaVecihOd(int temp) const;
        int DajBrojTemperaturaManjihOd(int temp) const;
        friend bool operator !(const Temperature &t);
        friend Temperature &operator ++(Temperature &t);
		friend Temperature operator ++(Temperature &t, int);
		friend Temperature &operator --(Temperature &t);
		friend Temperature operator --(Temperature &t, int);
		friend vector<int> operator *(const Temperature &t);
		friend vector<int> operator +(const Temperature &t);
		friend vector<int> operator -(const Temperature &t);
		const pair<int, int> operator [](int indeks) const;
		friend Temperature operator +(const Temperature &t, int y);
		friend Temperature operator -(const Temperature &t, int y);
		/*friend Temperature &operator +=(int y);
		friend Temperature &operator -=(int y);*/
		friend Temperature operator +(const Temperature &t1, const Temperature &t2);
		friend Temperature operator -(const Temperature &t1, const Temperature &t2);
		friend bool operator ==(const Temperature &t1, const Temperature &t2);
		friend bool operator !=(const Temperature &t1, const Temperature &t2);
		friend ostream &operator <<(ostream &tok, const Temperature &t2);
};

void Temperature::RegistrirajTemperature(pair<int, int> par)
{
    if(par.first>par.second || par.first<min || par.second<min || par.first>maks || par.second>maks) throw range_error("Nekorektne temperature");
    
    minimum.push_back(par.first);
    maksimum.push_back(par.second);
}

void Temperature::BrisiSve()
{
    minimum.clear();
    maksimum.clear();
}

void Temperature::BrisiNegativneTemperature()
{
    auto pom(minimum.begin());
    ponovo:
    auto pom1(find_if(pom, minimum.end(), bind(less<int>(), placeholders::_1, 0)));
    
    if(pom1==minimum.end()) return;
    int n(distance(minimum.begin(), pom1));
    
    auto pom2(maksimum.begin());
    advance(pom2, n);
    if(*pom2<0 && *pom1<0)
    {
        pom=minimum.erase(pom1);
        pom2=maksimum.erase(pom2);
        goto ponovo;
    }
    if(pom1!=minimum.end()) pom1++;
    else return;
    pom=pom1;
    goto ponovo;
}

int Temperature::DajMinimalnuTemperaturu() const
{
    if(distance(minimum.begin(), minimum.end())==0) throw logic_error("Nema registriranih temperatura");
    
    return *min_element(minimum.begin(), minimum.end());
}

int Temperature::DajMaksimalnuTemperaturu() const
{
    if(distance(minimum.begin(), minimum.end())==0) throw logic_error("Nema registriranih temperatura");
    
    return *max_element(maksimum.begin(), maksimum.end());
}

int Temperature::DajBrojTemperaturaVecihOd(int temp) const
{
    if(distance(minimum.begin(), minimum.end())==0) throw logic_error("Nema registriranih temperatura");
    
    return count_if(minimum.begin(), minimum.end(), bind(greater<int>(), placeholders::_1, temp))+count_if(maksimum.begin(), maksimum.end(), bind(greater<int>(), placeholders::_1, temp));
}

int Temperature::DajBrojTemperaturaManjihOd(int temp) const
{
    if(distance(minimum.begin(), minimum.end())==0) throw logic_error("Nema registriranih temperatura");
    
    return count_if(minimum.begin(), minimum.end(), bind(less<int>(), placeholders::_1, temp))+count_if(maksimum.begin(), maksimum.end(), bind(less<int>(), placeholders::_1, temp));
}

bool operator !(const Temperature &t)
{
    if(distance(t.minimum.begin(), t.minimum.end())==0) return true;
    return false;
}

Temperature &operator ++(Temperature &t)
{
    transform(t.minimum.begin(), t.minimum.end(), t.minimum.begin(), bind(plus<int>(), placeholders::_1, 1));
    transform(t.maksimum.begin(), t.maksimum.end(), t.maksimum.begin(), bind(plus<int>(), placeholders::_1, 1));
    if(t.DajBrojTemperaturaVecihOd(t.maks)>0) throw logic_error("Ilegalna opcija");
    
    return t;
}

Temperature operator ++(Temperature &t, int)
{
    Temperature pomocna(t);
    
    transform(t.minimum.begin(), t.minimum.end(), t.minimum.begin(), bind(plus<int>(), placeholders::_1, 1));
    transform(t.maksimum.begin(), t.maksimum.end(), t.maksimum.begin(), bind(plus<int>(), placeholders::_1, 1));
    
    if(t.DajBrojTemperaturaVecihOd(t.maks)>0) throw logic_error("Ilegalna opcija");
    
    return pomocna;
}

Temperature &operator --(Temperature &t)
{
    transform(t.minimum.begin(), t.minimum.end(), t.minimum.begin(), bind(minus<int>(), placeholders::_1, 1));
    transform(t.maksimum.begin(), t.maksimum.end(), t.maksimum.begin(), bind(minus<int>(), placeholders::_1, 1));
    if(t.DajBrojTemperaturaManjihOd(t.min)>0) throw logic_error("Ilegalna opcija");
    
    return t;
}

Temperature operator --(Temperature &t, int)
{
    Temperature pomocna(t);
    
    transform(t.minimum.begin(), t.minimum.end(), t.minimum.begin(), bind(minus<int>(), placeholders::_1, 1));
    transform(t.maksimum.begin(), t.maksimum.end(), t.maksimum.begin(), bind(minus<int>(), placeholders::_1, 1));
    if(t.DajBrojTemperaturaManjihOd(t.min)>0) throw logic_error("Ilegalna opcija");
    
    return pomocna;
}

vector<int> operator *(const Temperature &t)
{
    vector<int> v(distance(t.minimum.begin(), t.minimum.end()));
    transform(t.maksimum.begin(), t.maksimum.end(), t.minimum.begin(), &v[0], minus<int>());
    
    return v;
}

vector<int> operator +(const Temperature &t)
{
    vector<int> v(distance(t.maksimum.begin(), t.maksimum.end()));
    transform(t.maksimum.begin(), t.maksimum.end(), &v[0], bind(minus<int>(), t.maks, placeholders::_1));
    
    return v;
}

vector<int> operator -(const Temperature &t)
{
    vector<int> v(distance(t.minimum.begin(), t.minimum.end()));
    transform(t.minimum.begin(), t.minimum.end(), &v[0], bind(minus<int>(), placeholders::_1, t.min));
    
    return v;
}

const pair<int, int> Temperature::operator [](int indeks) const
{
    if(indeks<1 || indeks>distance(minimum.begin(), minimum.end())) throw range_error("Neispravan indeks");
    
    auto it1(minimum.begin());
    advance(it1, indeks-1);
    auto it2(maksimum.begin());
    advance(it2, indeks-1);
    
    return make_pair(*it1, *it2);
}

Temperature operator +(const Temperature &t, int y)
{
    Temperature zbir(t.min, t.maks);
    
    transform(t.minimum.begin(), t.minimum.end(), zbir.minimum.begin(), bind(plus<int>(), placeholders::_1, y));
    transform(t.maksimum.begin(), t.maksimum.end(), zbir.maksimum.begin(), bind(plus<int>(), placeholders::_1, y));
    if(zbir.DajBrojTemperaturaVecihOd(zbir.maks)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(zbir.DajBrojTemperaturaManjihOd(zbir.min)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return zbir;
}

Temperature operator -(const Temperature &t, int y)
{
    Temperature razlika(t);
    
    transform(t.minimum.begin(), t.minimum.end(), razlika.minimum.begin(), bind(minus<int>(), placeholders::_1, y));
    transform(t.maksimum.begin(), t.maksimum.end(), razlika.maksimum.begin(), bind(minus<int>(), placeholders::_1, y));
    if(razlika.DajBrojTemperaturaVecihOd(razlika.maks)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(razlika.DajBrojTemperaturaManjihOd(razlika.min)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return razlika;
}

/*Temperature &operator +=(int y)
{
    auto it1(this->minimum.begin());
    auto it2(this->maksimum.begin());
    it1++; it2++;
    
    transform(it1, minimum.end(), it1, bind(plus<int>(), placeholders::_1, y));
    transform(it2, maksimum.end(), it2, bind(plus<int>(), placeholders::_1, y));
    if(this->DajBrojTemperaturaVecihOd(*maksimum.begin())>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(this->DajBrojTemperaturaManjihOd(*minimum.begin())>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return *this;
}

Temperature &operator -=(int y)
{
    auto it1(minimum.begin());
    auto it2(maksimum.begin());
    it1++; it2++;
    
    transform(it1, minimum.end(), it1, bind(minus<int>(), placeholders::_1, y));
    transform(it2, maksimum.end(), it2, bind(minus<int>(), placeholders::_1, y));
    if(this->DajBrojTemperaturaVecihOd(*maksimum.begin())>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(this->DajBrojTemperaturaManjihOd(*minimum.begin())>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return *this;
}*/

Temperature operator +(const Temperature &t1, const Temperature &t2)
{
    if(distance(t1.minimum.begin(), t1.minimum.end())!=distance(t2.minimum.begin(), t2.minimum.end())) throw logic_error("Nemaju isti broj registrovanih temperatura");
    Temperature zbir(t1);
    
    transform(zbir.minimum.begin(), zbir.minimum.end(), t2.minimum.begin(), zbir.minimum.begin(), plus<int>());
    transform(zbir.maksimum.begin(), zbir.maksimum.end(), t2.maksimum.begin(), zbir.maksimum.begin(), plus<int>());
    if(zbir.DajBrojTemperaturaVecihOd(zbir.maks)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(zbir.DajBrojTemperaturaManjihOd(zbir.min)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return zbir;
}

Temperature operator -(const Temperature &t1, const Temperature &t2)
{
    if(distance(t1.minimum.begin(), t1.minimum.end())!=distance(t2.minimum.begin(), t2.minimum.end())) throw logic_error("Nemaju isti broj registrovanih temperatura");
    Temperature razlika(t1);
    
    transform(razlika.minimum.begin(), razlika.minimum.end(), t2.minimum.begin(), razlika.minimum.begin(), minus<int>());
    transform(razlika.maksimum.begin(), razlika.maksimum.end(), t2.maksimum.begin(), razlika.maksimum.begin(), minus<int>());
    if(razlika.DajBrojTemperaturaVecihOd(razlika.maks)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(razlika.DajBrojTemperaturaManjihOd(razlika.min)>0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return razlika;
}

bool operator ==(const Temperature &t1, const Temperature &t2)
{
    if(distance(t1.minimum.begin(), t1.minimum.end())==distance(t2.minimum.begin(), t2.minimum.end()) && equal(t1.minimum.begin(), t1.minimum.end(), t2.minimum.begin()) && equal(t1.maksimum.begin(), t1.maksimum.end(), t2.maksimum.begin())) return true;
    
    return false;
}

bool operator !=(const Temperature &t1, const Temperature &t2)
{
    if(distance(t1.minimum.begin(), t1.minimum.end())==distance(t2.minimum.begin(), t2.minimum.end()) && equal(t1.minimum.begin(), t1.minimum.end(), t2.minimum.begin()) && equal(t1.maksimum.begin(), t1.maksimum.end(), t2.maksimum.begin())) return false;
    
    return true;
}

ostream &operator <<(ostream &tok, const Temperature &t)
{
    ostream_iterator<int> izlaz(tok, " ");
    copy(t.minimum.begin(), t.minimum.end(), izlaz);
    tok << endl;
    copy(t.maksimum.begin(), t.maksimum.end(), izlaz);
    return tok;
}


int main ()
{
	Temperature t(-10, 20);
	pair<int, int> par;
	par.first=-2;
	par.second=-1;
	t.RegistrirajTemperature(par);
	pair<int, int> par1;
	par1.first=-5;
	par1.second=-2;
	t.RegistrirajTemperature(par1);
	pair<int, int> par2;
	par2.first=-9;
	par2.second=-1;
	t.RegistrirajTemperature(par2);
	pair<int, int> par3;
	par3.first=-4;
	par3.second=-3;
	t.RegistrirajTemperature(par3);
	pair<int, int> par4;
	par4.first=-3;
	par4.second=-2;
	t.RegistrirajTemperature(par4);
	
	cout << t.DajBrojRegistriranihTemperatura() << endl;
/*	vector<int> v1(*t);
	for(auto x: v1) cout << x << " ";
	cout << endl << t.DajMinimalnuTemperaturu() << endl << t.DajMaksimalnuTemperaturu() << endl << t.DajBrojTemperaturaVecihOd(8) << endl << t.DajBrojTemperaturaManjihOd(12) << endl;
	t=t-2;
	cout << endl << t.DajMinimalnuTemperaturu() << endl << t.DajMaksimalnuTemperaturu() << endl << t.DajBrojTemperaturaVecihOd(8) << endl << t.DajBrojTemperaturaManjihOd(12) << endl;
	par1=t[2];
	cout << t[2].first << " " << t[2].second << endl;*/

    cout << t << endl;
	   
	t.BrisiNegativneTemperature();
	cout << t;
	
	return 0;
}