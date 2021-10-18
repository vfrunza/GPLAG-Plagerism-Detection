/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>  IzdvojiGadne(vector<int> vek,bool tn) {
	vector<unsigned long long int> vek_terc(vek.size(),0);
	vector<int> opaki, odvratni;
	for(int i = 0 ;i < vek.size(); i++){
		int temp(vek[i]);
		int br(0);
		do {
		int temp1;
		temp1 = abs(temp)%3;
		vek_terc[i] += temp1*pow(10,br);
		temp = temp/3;
		br++;
		}while(temp != 0);
	
	
	int bra(0) , brb(0), brc(0);
	long long int tempt(vek_terc[i]);
	do{
		int a(0) ,b(1) ,c(2);
		int temp1;
		temp1=tempt%10;
		if(temp1==a) bra++;
		else if(temp1==b) brb++;
		else if(temp1==c) brc++;
		tempt/=10;
	}while(tempt!=0);
	if(bra%2==0 && brb%2==0 && brc%2==0){
		int br1(0);
	for(int j = i-1 ;j >= 0 ;j-- )
		if(vek[i]==vek[j]) br1++;
	
	if(br1==0) opaki.push_back(vek[i]);
	}
		else if((bra%2!=0 && brb%2!=0 && brc%2!=0) || (bra==0 && brb%2!=0 && brc%2!=0) || (bra%2!=0 && brb==0 && brc%2!=0) || (bra%2!=0 && brb%2!=0 && brc==0) || (bra==0 && brb==0 && brc%2!=0) || (bra==0 && brb%2!=0 && brc==0) || (bra%2!=0 && brb==0 && brc==0)) {
			int br1(0);
			for(int j = i-1 ;j >= 0 ;j-- )
				if(vek[i]==vek[j]) br1++;
				
		if(br1==0)	odvratni.push_back(vek[i]);
		}
	else continue;
	}
	if(tn==true) return opaki;
	
	else return odvratni;

}

int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> vek;
	int a;
	do{
		cin>>a;
		if(a==0) continue;
		vek.push_back(a);
	}while(a != 0);
	
	vector<int> opaki (IzdvojiGadne(vek,true)) , odvratni (IzdvojiGadne(vek,false));
	cout<<"Opaki: ";
	for(int i = 0 ;i < opaki.size() ;i++ ) cout<<opaki[i]<<" ";
	cout<<endl<<"Odvratni: ";
	for(int i = 0 ;i < odvratni.size() ;i++ ) cout<<odvratni[i]<<" ";
	

	return 0;
}









