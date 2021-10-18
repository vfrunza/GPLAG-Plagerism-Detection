#include<iostream>
#include<iomanip>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
typedef vector<vector<int>>Matrica;
int SumaDjelilaca(long long int n);
int BrojProstihFaktora(long long int n);
int BrojSavrsenihDjelilaca(long long int n);
int f(long long int C);

int SumaDjelilaca(long long int n){
	int suma(0);
	for(int i=1;i<=n;i++) { if(n%i==0) suma+=i; }
	return suma;
}

int BrojProstihFaktora(long long int n){
	int i,brojac(0);
	while(n!=1){
	for(i=2;i<=n;i++){
		if(n%i==0){
			n/=i;
			brojac++;
			break;}
	}
	}
	return brojac;
}

bool savrsen(int n){
	int suma=1;
	for(int i=2;i<n;i++){
		if(n%i==0)suma+=i;
	}
	return suma==n;
}

int BrojSavrsenihDjelilaca(long long int n){
	vector<int>p;
	for(int i=2;i<n;i++){
		if(n%i==0 && savrsen(i)) p.push_back(i);
	}
	return p.size();
}

int f(long long int C){
	int x,suma(0);
	while(C!=0){
		x=C%10;
		suma+=x;
		C/=10;
	}
return suma;
}

template<typename Tip1,typename Tip2, typename Tip3, typename Tip4> 
auto UvrnutiPresjek(Tip1 pocetak1, Tip1 iza_kraja1, Tip2 pocetak2, Tip2 iza_kraja2, Tip3 f(Tip4 C))->vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>{
	Matrica mat;
	int n(0);
	Tip2 refr;
	refr=pocetak2;
	while(pocetak1!=iza_kraja1){
		pocetak2=refr;
		while(pocetak2!=iza_kraja2){
			if(f(*pocetak1)==f(*pocetak2)) { 
			    n++;
				mat.resize(n);
				mat[n-1].resize(3);
				/*mat[n-1].push_back(*pocetak1);
				mat[n-1].push_back(*pocetak2);
				mat[n-1].push_back(f(*pocetak1));*/
				mat[n-1][0]=(*pocetak1);
				mat[n-1][1]=(*pocetak2);
				mat[n-1][2]=(f(*pocetak1));
			}
			pocetak2++;
		}
		pocetak1++;
	}
	return mat;
}
template<typename Tip1,typename Tip2> 
auto UvrnutiPresjek(Tip1 pocetak1, Tip1 iza_kraja1, Tip2 pocetak2, Tip2 iza_kraja2)->vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>{
	Matrica mat;
	int n(0);
	Tip2 refr;
	refr=pocetak2;
	while(pocetak1!=iza_kraja1){
		pocetak2=refr;
		while(pocetak2!=iza_kraja2){
			if((*pocetak1)==(*pocetak2)) {  
			    n++;
				mat.resize(n);
				mat[n-1].resize(3); 
				mat[n-1][0]=(*pocetak1);
				mat[n-1][1]=0;
				mat[n-1][2]=0;
			}
			pocetak2++;
		}
		pocetak1++;
	}
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			cout<<mat[i][j]<<setw(4);
		}
		cout<<endl;
	}
	return mat;
}

template<typename Tip1,typename Tip2, typename Tip3, typename Tip4> 
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 iza_kraja1, Tip2 pocetak2, Tip2 iza_kraja2, Tip3 f(Tip4 C))->vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>{
	Matrica mat;
	int n(0);
	Tip2 refr;
	refr=pocetak2;
	Tip1 referenca=pocetak1;
	while(pocetak1!=iza_kraja1){
		pocetak2=refr;
		bool ima=false;
		while(pocetak2!=iza_kraja2){
			//if((pocetak2==iza_kraja2-1)&&(f(*pocetak1)!=f(*iza_kraja2-1))){
			if(f(*pocetak1)==f(*pocetak2))ima=true;
			pocetak2++;
			}
			if(!ima){
				n++;
				mat.resize(n);
				mat[n-1].resize(2);
				mat[n-1][0]=(*pocetak1);
				mat[n-1][1]=(f(*pocetak1));
			}
			pocetak1++;
		}
		pocetak1=referenca;
	pocetak2=refr;
	while(pocetak2!=iza_kraja2){
		pocetak1=referenca;
		bool ima=false;
		while(pocetak1!=iza_kraja1){
			//if((pocetak2==iza_kraja2-1)&&(f(*pocetak1)!=f(*iza_kraja2-1))){
			if(f(*pocetak1)==f(*pocetak2))ima=true;
			pocetak1++;
			}
			if(!ima){
				n++;
				mat.resize(n);
				mat[n-1].resize(2);
				mat[n-1][0]=(*pocetak2);
				mat[n-1][1]=(f(*pocetak2));
			}
		pocetak2++;
	}
	return mat;
}

int main(){
	int n1;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n1;
	deque<int>p(n1);
	cout<<"Unesite elemente prvog kontejnera: ";
	int i2=0, k2=0; 
	while(i2<n1){
		cin>>p[i2];
		int t2=0;
		int pom2=i2;
		while(i2!=0){
			if(p[pom2]==p[i2-1]) t2=1;
			i2--;
		}
		i2=pom2;
		if(t2){ i2--; k2--; }
		i2++;
		k2++;
	}
	deque<int>::iterator it1=p.begin();
	deque<int>::iterator it2=p.end(); 
	
	int n2;
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n2;
	deque<int>v(n2);
	cout<<"Unesite elemente drugog kontejnera: ";
	int i1=0, k1=0; 
	while(i1<n2){
		cin>>v[i1];
		int t1=0;
		int pom1=i1;
		while(i1!=0){
			if(v[k1]==v[i1-1]) t1=1;
			i1--;
		}
		i1=pom1;
		if(t1){ i1--; k1--; }
		i1++;
		k1++;
	}
	deque<int>::iterator it3=v.begin();
	deque<int>::iterator it4=v.end();
	
	Matrica a;
	a=UvrnutiPresjek(it1,it2,it3,it4,f); //saljem li funkciju???
/*	//SORTIRANJE:
	for(int i=0;i<a.size();i++){
		sort(a[i],a[i+1],
		[](int red1[], int red2[])->bool {
			if(red1[i][2]==red2[i][2]){
				if(red1[i][0]==red2[i][0]) return red1[i][1]>red2[i][1];
				else return red1[i][0]>red2[i][0];
			}
			else return red1[i][2]>red2[i][2];
		}
		}
	});
	*/
	int bla=6,q=0;
	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			cout<<setw(bla+q);
			cout<<a[i][j];
		}
		cout<<endl;
	}
	Matrica b;
	b=UvrnutaRazlika(it1,it2,it3,it4,f);
	/*if(red1[i][2]==red2[i][2]){
				if(red1[i][0]==red2[i][0]) return red1[i][1]>red2[i][1];
				else return red1[i][0]>red2[i][0];
			}
			else return red1[i][2]>red2[i][2];*/
	/*	int pomocna;
	for(int i=0;i<b.size();i++){
       // for(int j=i+1;j<b.size();j++){
            if(b[i][2]==b[i+1][2]){ 
            	if(b[i][0]==b[i+1][0]){
            		if(b[i][1]>b[i+1][1]){
            pomocna=b[i][1];
            b[i][1]=b[i+1][1];
            b[i+1][1]=pomocna;
            }
            else{
            	pomocna=b[i][0];
            b[i][0]=b[i+1][0];
            b[i+1][0]=pomocna;
            }}
            else if(b[i][2]>b[i+1][2]){
            pomocna=b[i][2];
            b[i][2]=b[i+1][2];
            b[i+1][2]=pomocna;
            }
       // }
}
}*/
	//SORTIRANJE:
	/*for(int i=0;i<b.size();i++){
		sort(b[i],b[i+1],
		[](int red1[], int red2[])->bool {
			if(red1[i][0]==red2[i][0]){
				return red1[i][1]>red2[i][1];
			}
			else return red1[i][0]>red2[i][0];
		}
		}
	});
	*/
	int pomocna1;
	for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i][j]==a[i+1][j]){ 
            	if(a[i][j+1]>a[i+1][j+1]){
            pomocna1=a[i][j+1];
            a[i][j+1]=a[i+1][j+1];
            a[i+1][j+1]=pomocna1;
            }
            else if(a[i][j]>a[i+1][j]){
            pomocna1=a[i][j];
            a[i][j]=a[i+1][j];
            a[i+1][j]=pomocna1;
            }
        }
}
}
	int bla1=6, q1=0;
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[i].size();j++){
			cout<<setw(bla1+q1);
			cout<<b[i][j];
		}
		cout<<endl;
		q++;
	}
	cout<<"Dovidjenja!";
	return 0;
}