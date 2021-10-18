/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> IzdvojiGadne(vector<int>a,bool t){
	vector<int> b; 
	vector<int> c; 

	int br_0=0;
	int br_1=0;
	int br_2=0;
	int temp_1=0;
	
 for(int i=0;i<a.size();i++){
	
	int m=a[i];
	
	while(m!=0){
		if(m%3==0 ) br_0 ++;
		if(m%3==1 || m%3==-1) br_1 ++;
		if(m%3==2 || m%3==-2) br_2 ++;
		m/=3;
	}
	
	if((br_0%2==0 && br_1%2==0 && br_2%2==0) && t==1){ if(a.size()==0)  b.push_back(a[i]);
	else { for(int j=0;j<b.size();j++){
		if(b[j]==a[i]) {temp_1=1; break;}
		else temp_1=0;
	}
	if(temp_1==0) b.push_back(a[i]);
	}
		}
	if((br_0%2==1 && br_1%2==1 && br_2%2==1)  && t==0){if(a.size()==0) c.push_back(a[i]);
	else{ for(int j=0;j<c.size();j++){
		if(c[j]==a[i]) {temp_1=1; break;}
		else temp_1=0;
	}
	if(temp_1==0) c.push_back(a[i]);
	}
	}
	if((br_0==0 && br_1%2==1 && br_2%2==1) || (br_0%2==1 && br_1==0 && br_2%2==1) || (br_0%2==1 && br_1%2==1 && br_2==0)) {if(a.size()==0) c.push_back(a[i]);
	else{ for(int j=0;j<c.size();j++){
		if(c[j]==a[i]) {temp_1=1; break;}
		else temp_1=0;
	}
	if(temp_1==0) c.push_back(a[i]);
	}
	}
	if((br_0==0 && br_1==0 && br_2%2==1) || (br_0==0 && br_1%2==1 && br_2==0) || (br_0%2==1 && br_1==0 && br_2==0)) {if(a.size()==0) c.push_back(a[i]);
	else{ for(int j=0;j<c.size();j++){
		if(c[j]==a[i]) {temp_1=1; break;}
		else temp_1=0;
	}
	if(temp_1==0) c.push_back(a[i]);
	}
	}
	br_0=0;
	br_1=0;
	br_2=0;
	
}

if(t) return b;
return c;


}

int main ()
{
	vector<int> a;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int element;
	do {
		cin >> element;
		if(element!=0) a.push_back(element);
	}while(element!=0);
	vector<int>opaki = IzdvojiGadne(a,1);
	vector<int>odvratni = IzdvojiGadne(a,0);
	cout << "Opaki: ";
	for(int x : opaki)
	cout << x << " ";
	cout << endl;
	cout << "Odvratni: ";
	for(int x : odvratni)
	cout << x << " ";
	return 0;
}