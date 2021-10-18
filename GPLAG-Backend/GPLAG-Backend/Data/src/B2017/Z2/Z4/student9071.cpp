#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
int BrojProstihFaktora(int n)
{
	int broj(0);
	for(int i=2; i<=n; i++) {
		while(n%i==0) {
			n/=i;
			broj++;
		}
	}
	return broj;
}

bool comp(int a, int b)
{
	if(BrojProstihFaktora(a)==BrojProstihFaktora(b)) {
		return(a>b);
	}
	return(BrojProstihFaktora(a)>BrojProstihFaktora(b));
}

template <typename TipPok1, typename TipPok2, typename TipPok3>
void SortirajPodrucjeVrijednosti(TipPok1 pok1, TipPok1 kraj1, TipPok2 pok2, TipPok3 pok3,
                                 typename std::remove_reference<decltype(*pok3)>::type
                                 foo(typename std::remove_reference<decltype(*pok1)>::type, typename std::remove_reference<decltype(*pok2)>::type),
                                 bool comp(int,int))
{
	int duzina=kraj1-pok1;
	auto p1(pok1);
	auto k1(kraj1);
	auto p2(pok2);
	auto k2(pok2+duzina);
	auto p3(pok3);
	std::sort(pok1,pok1+duzina,comp);
	std::sort(pok2,pok2+duzina,comp);
	std::sort(pok3,pok3+duzina);

	//Prvo provjerimo da li je vrijednost svaka pronadjena
	while(p1!=k1) {
		auto rezultat=foo(*p1,*p2);
		//cout<<rezultat<<" ";
		if(!std::binary_search(pok3,pok3+duzina,rezultat)) {
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		p1++;
		p2++;
	}
	//reset vrijednosti pokazivaca
	p1=pok1;
	p2=pok2;
	//Vrsimo zamijenu tako da redoslijed bude dobar
	while(p1!=k1) {
		auto rezultat=foo(*p1,*p2);
		auto temp=*p3;
		auto lokacija(std::find(pok3,pok3+duzina,rezultat));
		*p3=*lokacija;
		*lokacija=temp;

		p1++;
		p2++;
		p3++;
	}
}

int foo(int x,int y)
{
	return -2*x+y;
}

template <typename Tip>
void UnesiVektor(vector<Tip> &vektor, int n)
{
	Tip broj;
	for(int i=0;; i++) {
		if(vektor.size()==n) break;
		cin>>broj;
		if(std::find(vektor.begin(),vektor.end(),broj)==vektor.end()) {
			vektor.push_back(broj);
		}

	}
	cin.ignore(1000,'\n');
}
int main ()
{
	int n;
	cout<<"Unesite broj elemenata: ";
	cin>>n;
	vector<int> vektor1,vektor2,vektor3;
	cout<<"Unesite elemente prvog vektora: ";
	UnesiVektor(vektor1,n);
	cout<<"Unesite elemente drugog vektora: ";
	UnesiVektor(vektor2,n);
	cout<<"Unesite elemente treceg vektora: ";
	UnesiVektor(vektor3,n);
	cout<<"\n";

	try {
		SortirajPodrucjeVrijednosti(vektor1.begin(),vektor1.end(),vektor2.begin(),vektor3.begin(),foo,comp);
		cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
		for(int i=0; i<vektor1.size(); i++) {
			cout<<"f("<<vektor1[i]<<", "<<vektor2[i]<<") = "<<vektor3[i]<<"\n";
		}
	} catch (std::logic_error exc) {
		cout<<"Izuzetak: "<<exc.what();
	}
	return 0;
}
