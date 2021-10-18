/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

vector <int> ternarni_zapis (int n) {
	if (n<0) n*=-1;
	vector<int> v_t(0);
	int c(0);
	do {
		c=n%3;
		n/=3;
		v_t.push_back(c);
	} while(n!=0);
return v_t;	
}

int f1 (vector<int> v_t) {
	int n_ct[3]={0};
	for (int x: v_t) {
		if (x==0) n_ct[0]++;
		else if (x==1) n_ct[1]++;
		else if (x==2) n_ct[2]++;
	}
	if (n_ct[0]%2 ==0 && n_ct[1]%2==0 && n_ct[2]%2==0)
		return 1;
	else if ((n_ct[0]!=0 && n_ct[1]!=0 && n_ct[2]!=0) &&(n_ct[0]%2 !=0 && n_ct[1]%2 !=0 && n_ct[2]%2 !=0))
		return 0;
	else if ((n_ct[0]==0 && n_ct[1]%2!=0 && n_ct[2]%2!=0)||(n_ct[0]%2!=0 && n_ct[1]==0 && n_ct[2]%2!=0)||(n_ct[0]%2!=0 && n_ct[1]%2!=0 && n_ct[2]==0))
		return 0;
	else if ((n_ct[0]==0 && n_ct[1]==0 && n_ct[0]%2!=0)||(n_ct[0]==0 && n_ct[1]%2!=0 && n_ct[2]==0)||(n_ct[0]%2!=0 && n_ct[1]==0 && n_ct[2]==0))
		return 0;
	else 
		return 3;
}

vector <int> IzdvojiGadne (vector<int> v, bool tacnost) {
	vector<int> izdvojeni(0);
	vector<int> ve(v);
	
	for(int i(0); i<v.size();i++) {
		for(int j(i+1); j<ve.size();j++) {
			
			if(v[i]==ve[j]) {
				if(j==ve.size()-1) {
					ve.resize(ve.size()-1);
					j--;
				}
				else {	
				int k(j);
				for( k=j;k<ve.size()-1;k++) 
					ve[k]=ve[k+1];
				ve.resize(ve.size()-1);
				k--;
				}
				j--;
			}
		}
	}
	for(int i=0; i<ve.size();i++) {
		if(tacnost==f1(ternarni_zapis(ve[i])))
			izdvojeni.push_back(ve[i]);
	} 
return izdvojeni;	
}


int main () {
	int n;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> vektor(0);
	for(;;) {
		cin>>n;
		if(n==0)	break;
		vektor.push_back(n);
	}
	cout <<"Opaki: ";
	for(int x: IzdvojiGadne(vektor,true)) cout<<x <<" ";
	cout<<std::endl;
	cout<< "Odvratni: ";
	for(int x: IzdvojiGadne(vektor,false)) cout<<x <<" ";
	cout<<std::endl;
	
	return 0;
}

