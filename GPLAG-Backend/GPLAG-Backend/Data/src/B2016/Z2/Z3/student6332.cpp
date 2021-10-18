#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

bool jelprost(int x){
	for(int i=2;i<x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

int SumaDjelilaca(long long int x){
	int suma=0;
	for(int i=1;i<=x;i++){
		if(x%i==0) suma+=x;
	}
	
	return suma;
}

int BrojSavrsenihDjelilaca(long long int x){
	int brojac=0;
	for(int i=0;i<x;i++){
		if(x%i==0){
			int p=i;
			int suma=0;
			while(p!=0){
				suma+=p%10;
				p/=10;
			}
			if(suma=x) brojac++;	
		}
		return brojac;
	}
	
}

int BrojProstihFaktora(long long int x){
	int brojac=0;
	vector<int> v;
	for(int i=1;i<x;i++){
		if(x%i==0 && jelprost(i)) {v.push_back(i);}
	}
	
	long long p=x;
	for(int i=0;i<v.size();i++){
		while(p%v[i]){ p=p/v[i]; brojac++;}
		
	}
	if(p==0) return brojac;
	return 0;
	
}

template<typename Tip1, typename Tip2, typename Tip>

vector<vector<Tip>> UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip f(Tip))
{
	int brojac;

	for(int i=0; i<p2-p1; i++) {
		for(int j=0; i<p4-p3; j++) {
			if(f(p1[i])==f(p3[j])) brojac++;


		}
	}

	vector<vector<Tip>> niz(brojac, vector<Tip>(3));
	int b=0;
	for(int i=0; i<p2-p1; i++) {
		for(int j=0; i<p4-p3; j++) {
			if(f(p1[i])==f(p3[j])) {
				niz[b][0]=p1[i];
				niz[b][1]=p2[i];
				niz[b][2]=f(p1[i]);
				b++;
			}

		}

	}

	sort(niz.begin(), niz.end(), [](vector<Tip> x,vector<Tip> y) {
		if(x[2]>y[2]) return true;
		else if(x[0]>y[0]) return true;
		else if(x[1]>y[1]) return true;

	});

	return niz;


}


template<typename Tip1, typename Tip2, typename Tip>

vector<vector<Tip>> UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip f(Tip))
{
	int ima=0,brojac=0,b=0;

	for(int i=0; i<p2-p1; i++) {
		for(int j=0; j<p4-p3; j++) {
			if(f(p1[i])==f(p3[j])) ima=1;
		}
		if(ima==0) brojac ++;

	}
	vector<vector<Tip>> niz(brojac, vector<Tip>(2));

	for(int i=0; i<p2-p1; i++) {
		for(int j=0; j<p4-p3; j++) {
			if(f(p1[i])==f(p3[j])) ima=1;
		}
		if(ima==0) {
			niz[b][0]=p1[i];
			niz[b][1]=f(p1[i]);
		}
	ima=0;
	}
	
	ima=0;
	
	for(int i=0; i<p4-p3; i++) {
		for(int j=0; j<p2-p1; j++) {

			if(f(p3[i])==f(p1[j])) ima=1;
		}
		if(ima==0) {
			niz[b][0]=p3[i];
			niz[b][1]=f(p3[i]);
		}
ima=0;
	}
	return niz;

}

int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int broj:
	cin>>broj;
	
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int broj2:
	cin>>broj2;
	
	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	
	
	return 0;
}