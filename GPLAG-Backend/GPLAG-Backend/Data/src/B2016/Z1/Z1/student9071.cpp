/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;

long long int toTern(int broj) //Funkcija toTern konvertuje broj iz dec u tern. Moze se modifikovati i za binarne samo treba promijeniti (1) da dijeli sa dva.
{

	vector<int> buffer;
	int i=0,remain=0;
	long long int rezultat=0;
	while(broj!=0) {
		remain=broj%3;	//(1)
		buffer.push_back(remain);
		broj=broj/3;

	}

	for(i=(int)buffer.size()-1; i>0; i--) {
		rezultat+=buffer[i];
		rezultat*=10;
	}
	rezultat+=buffer[i];

	return rezultat;
}

vector<int> IzdvojiGadne(vector<int>vektor,bool logika)
{
	vector<int>rezultat;
	vector<int>lista;

	for(int i=0; i<(int)vektor.size(); i++) {


		int preconversion=vektor[i];	//Uzima se abs vrijednost i salje se u toTern funkciju
		int returnvalue=vektor[i];	//U slucaju da je sve OK ovo pakujemo u vektor, nece znak biti promijenjen

		vector<int>histogram(10,0);
		long long int ternarni=0;



		if (preconversion<0) {		//Absolutnu vrijednost uzima od preconversion broja, da ga proslijedi kao takav u fiju.
			preconversion*=-1;
		}

		ternarni=toTern(preconversion);
		int cifra=0;



		while(ternarni>0) {		//"Puni" histogram sa ciframa
			cifra=ternarni%10;
			histogram[cifra]++;
			ternarni/=10;
		}

		{
			if(logika) {			//Tl;dr provjerava za slucaj da je logika true da li SVAKI clan histograma se pojavljuje paran broj puta,
				bool flag=true;		//u suprotnom breaka i nista se ne desava.
				int i;				// a ako se radi o false uslovu gleda da li je SVAKI neparan, u suprotnom breaka i ne puni se vektor.
				for(i=0; i<10; i++) {
					if(histogram[i]%2!=0&&histogram[i]!=0) {
						flag=false;
						break;
					}
				}
				if(i==10) {
					rezultat.push_back(returnvalue);
				}

			} else {
				bool flag=true;
				int i;
				for(i=0; i<10; i++) {
					if(histogram[i]%2==0&&histogram[i]!=0) {
						flag=false;
						break;
					}
				}
				if(i==10) {
					rezultat.push_back(returnvalue);
				}
			}

		}
		lista.push_back(returnvalue);

	}

	for(int i=0; i<rezultat.size()-1; i++) {		//izbacivanje duplikata
		for(int j=i+1; j<rezultat.size(); j++) {
			if(rezultat[i]==rezultat[j]) {
				rezultat.erase(rezultat.begin()+j);
				j--;
				
			}
			
		}
	}

	return rezultat;

}


int main ()
{
		cout<<"Unesite brojeve (0 za prekid unosa): ";
		vector<int>v;
		vector<int>ispis;
		int n=1,i;
		while(n!=0){
			cin>>n;
			if(n==0){
				break;
			}
			v.push_back(n);
		}
		cout<<"Opaki: ";
		ispis=IzdvojiGadne(v,true);
		for(auto i: ispis){
			cout<<i<<" ";
		}
			cout<<"\nOdvratni: ";
		ispis=IzdvojiGadne(v,false);
			for(auto i: ispis){
			cout<<i<<" ";
		}
return 0;
}