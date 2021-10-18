/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> Niz;

Niz RastuciPodnizovi (vector<double>v1){
	if(v1.size()==0){Niz nula(0);return nula;}
	double *p=v1.data(),*q=v1.data();
	p=&v1[0];q=&v1[v1.size()-1];
	int brojac(0);
	while(p<q){
		double *s(p),*r(s+1);
		int duzina_pom(0);
		while(*s<=*r){
			if(r==q){brojac++;break;}
			s++;r++;duzina_pom++;
			if(*s>*r)brojac++;
		}
		p=p+duzina_pom+1;
	}
	Niz rez(brojac,vector<double>(0));
	double *p1=v1.data(),*q1=v1.data();
	p1=&v1[0];q1=&v1[v1.size()-1];
	for(int i=0;i<int(rez.size());i++){
		bool b(false);
		while(p1<q1){
			double *s1(p1),*r1(s1+1);
			int duzina_pom1(0);
			bool a(false);
			while(*s1<=*r1){
				b=false;
				if(r1==q1 ){ rez[i].push_back(*s1); rez[i].push_back(*r1);b=true;break;}
				rez[i].push_back(*s1);
				s1++;r1++;duzina_pom1++;a=true;
			}
			if(q1==s1+1){if(*(s1-1)<=*s1 && r1==q1 && !b)rez[i].push_back(*s1);}
			else if(s1!=&v1[0]){if(*(s1-1)<=*s1 && r1!=q1)rez[i].push_back(*s1);}
			p1=p1+duzina_pom1+1;
			if(p1!=q1 && a)break;
		}
	}
	return rez;
	
}
Niz OpadajuciPodnizovi (vector<double>v2){
	if(v2.size()==0){Niz nula(0);return nula;}
	double *p3(v2.data()),*q3(v2.data());
	p3=&v2[0];q3=&v2[v2.size()-1];
	int brojac(0);
	while(p3<q3){
		double *s3(p3),*r3(s3+1);
		int duzina_pom(0);
		while(*s3>=*r3){
			if(r3==q3){brojac++;break;}
			s3++;r3++;duzina_pom++;
			if(*s3<*r3)brojac++;
		}
		p3=p3+duzina_pom+1;
	}
	Niz rez1(brojac,vector<double>(0));
	double *p4(v2.data()),*q4(v2.data());
	p4=&v2[0];q4=&v2[v2.size()-1];
	for(int i=0;i<int(rez1.size());i++){
		bool b(false);
		while(p4<q4){
			double *s4(p4),*r4(s4+1);
			int duzina_pom1(0);
			bool a(false);
			while(*s4>=*r4){
				if(r4==q4 && r4==s4+1){rez1[i].push_back(*s4);rez1[i].push_back(*r4);b=true;break;}
				rez1[i].push_back(*s4);
				s4++;r4++;duzina_pom1++;a=true;
			}
			if(q4==s4+1){if(*(s4-1)>=*s4 && r4==q4 && !b)rez1[i].push_back(*s4);}
			else if(s4!=&v2[0]){if(*(s4-1)>=*s4 && r4!=q4)rez1[i].push_back(*s4);}
			p4=p4+duzina_pom1+1;
			if(p4!=q4 && a)break;
		}
	}
	return rez1;
	
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
   int n;
    cin>>n;
    if(n<=0)return 0;
    vector<double>v(n);
    cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Niz konacni=RastuciPodnizovi(v);
    cout<<"Maksimalni rastuci podnizovi: "<<endl;
    for(int i=0;i<int(konacni.size());i++){
        for(int j=0;j<int(konacni[i].size());j++)cout<<setprecision(12)<<konacni[i][j]<<" ";
        cout<<endl;
    }
    Niz konacni1=OpadajuciPodnizovi(v);
    cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    for(int i=0;i<int(konacni1.size());i++){
    	for(int j=0;j<int(konacni1[i].size());j++)cout<<setprecision(12)<<konacni1[i][j]<<" ";
    	cout<<endl;
    }
	return 0;
}