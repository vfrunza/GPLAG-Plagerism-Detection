/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> IzdvojiGadne(vector<int> c, bool logvri){
	vector<int>a;
	if(logvri==1){
		for(int i=0;i<c.size();i++){
		   int pomocna(fabs(c[i])),x,brojac1(0),brojac2(0),brojac0(0);
		   while(pomocna!=0){
		   x=pomocna%3;
		   if(x==0) brojac0++;
		   else if(x==1) brojac1++;
		   else if(x==2) brojac2++;
	       pomocna/=3;
		   }
		   if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0) a.push_back(c[i]);
		 }
		
		 for(int i=0; i<a.size();i++){
		 	for(int j=i+1;j<a.size();j++){
		 		if(a[i]==a[j]){
		 			for(int k=j;k<a.size()-1;k++){
		 				a[k]=a[k+1];
		 			}
		 			j--;
		 		    a.resize(a.size()-1);
		 		}
		 		
		 	}
		 }
		 return a;
		 
	}
	else
	for(int i=0;i<c.size();i++){
		   int pomocna(fabs(c[i])),x,brojac1(0),brojac2(0),brojac0(0);
		   while(pomocna!=0){
		   x=pomocna%3;
		   if(x==0) brojac0++;
		   else if(x==1) brojac1++;
		   else if(x==2) brojac2++;
	       pomocna/=3;
		   }
		   if(brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0) a.push_back(c[i]);
		   else if(brojac0==0 && brojac1%2!=0 && brojac2%2!=0) a.push_back(c[i]);
		   else if(brojac0%2!=0 && brojac1==0 && brojac2%2!=0) a.push_back(c[i]);
		   else if(brojac0%2!=0 && brojac1%2!=0 && brojac2==0) a.push_back(c[i]);
		   else if(brojac0==0 && brojac1==0 && brojac2%2!=0) a.push_back(c[i]);
		   else if(brojac0%2!=0 && brojac1==0 && brojac2==0) a.push_back(c[i]);
		   else if(brojac0==0 && brojac1%2!=0 && brojac2==0) a.push_back(c[i]);
	}

		 for(int i=0; i<a.size();i++){
		 	for(int j=i+1;j<a.size();j++){
		 		if(a[i]==a[j]){
		 			for(int k=j;k<a.size()-1;k++){
		 				a[k]=a[k+1];
		 			}
		 			j--;
		 		    a.resize(a.size()-1);
		 		}
		 		
		 	}
		 }
	return a;
}

int main (){
     int br;
     vector<int>a;
     cout<<"Unesite brojeve (0 za prekid unosa): ";
     do{
     	cin>>br;
     	if(br==0) break;
     	a.push_back(br);
     }while(br!=0);
     vector<int>b(IzdvojiGadne(a,1));
     cout<<"Opaki: ";
     for(int i=0; i<b.size();i++) cout<<b[i]<<" ";
     cout<<endl;
     vector<int>c(IzdvojiGadne(a,0));
     cout<<"Odvratni: ";
     for(int i=0; i<c.size();i++) cout<<c[i]<<" ";
	return 0;
}