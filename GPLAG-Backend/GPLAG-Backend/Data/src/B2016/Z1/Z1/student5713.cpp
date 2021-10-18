/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


using std::endl;
using std::cout;
using std::vector;
using std::cin;


void IspisVectora (vector<int>  x){
   for(int i=0; i<x.size(); i++){
   if(i!=x.size()-1) cout<<x[i]<<" ";
   else cout<<x[i];}
   cout<<endl;
}


 vector<int> IzdvojiGadne (vector<int> a, bool iskaz){
 vector<int> b;
 if(a.size()==0){
     b.resize(0); return b;}
 
 int brojaci_0(0), brojaci_1(0), brojaci_2(0);

 for(int i=0; i<a.size(); i++){
    int temp(a[i]);
    brojaci_0=0;
    brojaci_1=0;
    brojaci_2=0;
    int ostatak;
if(temp<0)  temp=-temp;
if(temp==0  && iskaz==false) b.push_back(a[i]); 
 else{   while(temp!=0){
            ostatak=temp%3;
            if(ostatak==0) brojaci_0++;
            else if(ostatak==1) brojaci_1++;
            else if(ostatak==2) brojaci_2++;
            temp/=3;
    }

    if(iskaz==true && a[i]!=0){
        if(brojaci_0%2==0 && brojaci_1%2==0 && brojaci_2%2==0) b.push_back(a[i]);
    }
    else if(iskaz==false && a[i]!=0){
             if((brojaci_0%2!=0 && brojaci_1%2!=0 && brojaci_2%2!=0) ||
                (brojaci_0%2!=0 && brojaci_1%2!=0 && brojaci_2==0 )
                || (brojaci_0==0 && brojaci_1%2!=0 && brojaci_2%2!=0)
                || (brojaci_0%2!=0 && brojaci_1==0 && brojaci_2%2!=0 )
                || (brojaci_0==0 && brojaci_1==0 && brojaci_2%2!=0)
                || (brojaci_0==0 && brojaci_1%2!=0 && brojaci_2==0)
                || (brojaci_0%2!=0 && brojaci_1==0 && brojaci_2==0 ) )
                 b.push_back(a[i]);
    }
 }
     
 }

/*izbacivanje duplih elemenata*/
    for(int i=0; i<b.size(); i++){
        for(int j=i+1; j<b.size(); j++){
            if(b[i]==b[j]) {
          
                    b.erase(b.begin()+j);
                    i--;
                    break;
        }
    }
    }

    return b;
 }


int main(){
   int n;
	vector<int>x;
	vector<int>y;
	vector<int>z;
	bool iskaz(1);
	cout<<"Unesite brojeve (0 za prekid unosa): ";

	for(;;){
        cin>>n;
		if(n==0) break;
		else x.push_back(n);
	}
//if(x.size()==0) return 0;
	y=IzdvojiGadne(x, iskaz);

	cout<<"Opaki: ";
	//if(y.size()>0)
	IspisVectora(y);


    z=IzdvojiGadne(x, !iskaz);
	cout<<"\nOdvratni: ";
//	if(z.size()>0)
	IspisVectora(z);
	return 0;
}


