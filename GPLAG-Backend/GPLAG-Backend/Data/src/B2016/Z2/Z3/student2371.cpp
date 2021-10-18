/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	“ SumaDjelilaca ”: Funkcija vraća sumu svih djelilaca broja koji joj je prenesen kao parametar.
	“ BrojProstihFaktora ”: Funkcija vraća broj svih prostih faktora broja koji joj je prenesen kao
		parametar. Recimo, za ulaz 21 funkcija treba da vrati 2, jer 27 ima 2 prosta faktora (3 i 7).
	“ BrojSavrsenihDjelilaca ”: Funkcija vraća broj savršenih djelilaca broja, tj. djelilaca koji su
		savršeni brojevi (npr. za broj 168 funkcija treba da kao rezultat vrati 2, jer broj 168 ima dva
		prosta djelioca: 6 i 28). Podsjetimo se da su savršeni brojevi oni koji su jednaki sumi svih svojih
		djelilaca, ne računajući njih same.
	
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<string>
#include<deque>
using std::cin;
using std::cout;
using std::endl;
typename std::vector<std::vector<int>> Matrica;

int f(long long int n){
	int suma=0;
	int b;
	while(n!=0){
		b=abs(n%10);
		n=n/10;
		suma+=b;
	}
	return suma;
}
int BrojProstihFaktora(long long int n){
	int brojac=0;
	long long int m=abs(n);
	for (int i=2; i<m; i++){
		if(m%i==0)
		while(m%i==0){
			brojac++;
			m/=i;
		}
	}
	return brojac;
}
int SumaDjelilaca(long long int n){
	int suma=0;
	long long int m=abs(n);
	for (int i=1; i<=m; i++){
		if(m%i==0) suma+=i;
	}
	return suma;
}
int BrojSavrsenihDjelilaca(long long int n){
	int brojac=0;
	long long int m=abs(n);
	for (int i=1; i<=m; i++){
		int suma=0;
		if(m%i==0 ) 
		
		for(int j=1; j<i; j++){
			if (i%j==0)
			suma+=j;
		}
		if (suma==i) brojac++;
	}
	return brojac;
}


template <typename tip1, typename tip2, typename tipfun>
std::vector<std::vector<int>> UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tipfun f) {
	tip1 p1=pocetak1;
	tip2 p2=pocetak2;
	std::vector<int> prvi;
	std::vector<int>drugi;
	std::vector<int> treci;
	for (int i=0; i<kraj1-pocetak1; i++){
		p2=pocetak2;
		for (int j=0; j<kraj2-pocetak2; j++){
			if(f(*p1)==f(*p2)){
				prvi.push_back(*p1);
				drugi.push_back(*p2);
				treci.push_back(f(*p1));
			}
			p2++;
		}
		p1++;
	}

	std::vector<std::vector<int>> m;
	m.resize(prvi.size());
	for (int i=0; i<prvi.size(); i++) m[i].resize(3);
	for(int i=0; i<prvi.size(); i++){
		for (int j=0; j<3; j++){
			if(j==0) m[i][j]=prvi[i];
			if(j==1) m[i][j]=drugi[i];
			if(j==2) m[i][j]=treci[i];
		}
	}
	std::sort(m.begin(), m.end(), [](std::vector<int> v1, std::vector<int> v2){if (v1[2]==v2[2] && v1[0]==v2[0]) return v1[1]<v2[1]; else if(v1[2]==v2[2] && v1[0]!=v2[0]) return v1[0]<v2[0];else return v1[2]<v2[2];});
	
return m;	
}

template <typename tip1, typename tip2, typename tipfun>
std::vector<std::vector<int>> UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tipfun f ){
	tip1 p1=pocetak1, p11=pocetak1;
	tip2 p2=pocetak2, p22=pocetak2;
	std::vector<int> prvi;
	std::vector<int> treci;
	
	for (int i=0; i<kraj1-pocetak1; i++){
		p2=pocetak2;
		bool molim=false;
		for (int j=0; j<kraj2-pocetak2; j++){
			if(f(*p1)==f(*p2)) molim=true;
			p2++;
		}
		
		if (molim==false){
			
			prvi.push_back(*p1);
			treci.push_back(f(*p1));
		}
		p1++;
	}
	
	for (int i=0; i<kraj2-pocetak2; i++){
		p11=pocetak1;
		bool molim1=false;
		
		for (int j=0; j<kraj1-pocetak1; j++){
			if(f(*p11)==f(*p22)) molim1=true;
			p11++;
		}
		
		if (molim1==false){
			
			prvi.push_back(*p22);
			treci.push_back(f(*p22));
		}
		p22++;
	}
	std::vector<std::vector<int>> m;
	m.resize(prvi.size());
	for (int i=0; i<prvi.size(); i++) m[i].resize(2);
	for(int i=0; i<prvi.size(); i++){
		for (int j=0; j<2; j++){
			if(j==0) m[i][j]=prvi[i];
			if(j==1) m[i][j]=treci[i];
		}
	}
	std::sort(m.begin(), m.end(), [](std::vector<int> v1, std::vector<int> v2){if (v1[0]==v2[0]) return v1[1]>v2[1]; else return v1[0]>v2[0];});
	
return m;	
}

int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	cin>>n1;
	std::vector<int> d1;
	cout<<"Unesite elemente prvog kontejnera: ";
	for (int i=0; i<n1; i++){
		bool ponovo=false;
		int b;
		cin>>b;
		for (int j=0; j<i; j++){
		if (b==d1[j]){
			ponovo=true;
			break;
		}
		
		}
		if(ponovo==true) {i--;continue;}
		d1.push_back(b);
	}
	int n2;
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n2;
	std::vector<int>d2;
	cout<<"Unesite elemente drugog kontejnera:";
	for (int i=0; i<n2; i++){
		bool ponovo(false);
		int b;
		cin>>b;
		for (int j=0; j<i; j++){
			if (b==d2[j]){
				ponovo=true;
				break;
			}
		}
		if(ponovo==true) {i--;continue;}
		d2.push_back(b);
	}

	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	std::vector<std::vector<int>> m2=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), f);
	for(int i=0; i<m2.size(); i++){
		for (int j=0; j<m2[0].size(); j++){
			cout<<std::setw(3)<<m2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	std::vector<std::vector<int>> m1=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
		for(int i=0; i<m1.size(); i++){
		for (int j=0; j<m1[0].size(); j++){
			cout<<std::setw(5)<<m1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}