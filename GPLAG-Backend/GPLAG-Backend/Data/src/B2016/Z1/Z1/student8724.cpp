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

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::abs;

vector<int>TernarniZapis(long long int i){
	int b, c;
	vector<int> D;
	i=abs(i);
	while(i!=0){
		b=i/3;
		c=i-b*3;
		D.push_back(c);
		i/=3;
		
	}
	return D;
} 

vector<int> IzdvojiGadne( vector<int> A, bool x){
		vector<int>C;
		if(x){
			
		for(int i : A){
			bool test(false);
				for(int j : C) 
					if(j==i){
						test=true;
						break;
				}
				if(test) continue;
				
				vector<int> D(TernarniZapis(i));
				int br0(0), br1(0), br2(0);
				for(int i=0;i<int(D.size());i++){
					if(D[i]==0) br0++;
					if(D[i]==1) br1++;
					if(D[i]==2) br2++;
				}
				
				if(br0%2==0 && br1%2==0 && br2%2==0){ 
				C.push_back(i);
					
				}
		}
		
			return C;
		}
		
		else{
			
					
		for(int i : A){
			bool test(false);
				for(int j : C) 
					if(j==i){
						test=true;
						break;
				}
				if(test) continue;
				vector<int> D(TernarniZapis(i));
				int br0(0), br1(0), br2(0);
				for(int i=0;i<(D.size());i++){
					if(D[i]==0) br0++;
					if(D[i]==1) br1++;
					if(D[i]==2) br2++;
				}
				
				if(br0%2!=0 && br1%2!=0 && br2%2!=0){ 
				C.push_back(i);
					
				}
				if(br0%2!=0 && br1%2!=0 && br2==0){ 
				C.push_back(i);
					
				}
				if(br0%2!=0 && br1==0 && br2%2!=0){ 
				C.push_back(i);
					
				}
				if(br0==0 && br1%2!=0 && br2%2!=0){ 
				C.push_back(i);
					
				}
				if(br0%2!=0 && br1==0 && br2==0){ 
				C.push_back(i);
					
				}
				if(br0==0 && br1%2!=0 && br2==0){ 
				C.push_back(i);
					
				}
				if(br0==0 && br1==0 && br2%2!=0){ 
				C.push_back(i);
					
				}
				
		}
		return C;	
		}
		
	
}

int main (){
	
	int a;
	vector<int> A;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1){
		cin>>a;
		if(a==0) break;
		A.push_back(a);
	}
    vector<int> Opaki(IzdvojiGadne(A, true));
	vector<int> Odvratni(IzdvojiGadne(A, false));
	cout<<"Opaki: ";
	for(int i : Opaki){
		cout<<i<<" ";
	}
	
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i : Odvratni){
		cout<<i<<" ";
	}
	
		
	return 0;
}