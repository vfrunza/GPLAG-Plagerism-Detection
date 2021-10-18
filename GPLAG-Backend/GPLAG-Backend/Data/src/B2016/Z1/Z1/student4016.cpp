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


vector <int> IzdvojiGadne(vector <int> vecc, bool logicka){
	vector <int> pomocni;
	for (int i=0; i<vecc.size(); i++){
		
		int broj=abs(vecc[i]);
		vector<int> ternarni;
		for( int j{0}; broj>0; j++ ){
			ternarni.push_back(broj%3);
			broj=broj/3;
		}
		int b0(0), b1(0), b2(0);
		for( int j=0; j<ternarni.size(); j++ ){
			if(ternarni[j]==0 ) b0++;
			else if ( ternarni[j]==1 ) b1++;
			else if ( ternarni[j]==2) b2++;		} 
	
		
		if( (b0==0 || b0%2==0) && (b1==0 || b1%2==0 ) && (b2==0 || b2%2==0) && logicka==true ) {
			bool logicka2(true);
			for (int j=0; j<pomocni.size(); j++){
				int broj2(vecc[i]);
				if(broj2==pomocni[j]){
			 logicka2=false;
			 break;
			}
			}
			if(logicka2==true)
			pomocni.push_back(vecc[i]);
		}
		else if ((b0==0 || b0%2==1) &&(b1==0 || b1%2==1) && (b2==0 || b2%2==1) && logicka==false){
		bool logicka1(true);
		for (int k=0; k<pomocni.size(); k++){
			int broj2(vecc[i]);
			if(broj2==pomocni[k]){
				logicka1=false;
				break;
			}
		}
		if(logicka1==true)
		pomocni.push_back(vecc[i]);
	}
	
		
	}
	
	return pomocni;
}
int main ()
{
	cout <<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> vec3;
	for (int i=0; ; i++){
		int a; 
		cin >>a;
		if(a==0) break;
		vec3.push_back(a);
	}
	vector<int> vec4;
	vec4=IzdvojiGadne(vec3,true);
	cout <<"Opaki: ";
	for(int j=0; j<vec4.size(); j++){
		cout<< vec4[j]<<" ";
	}  
	vec4=IzdvojiGadne(vec3,false);
	cout<<endl;
	cout <<"Odvratni: ";
	for (int k=0; k<vec4.size(); k++){
		cout << vec4[k]<<" ";
	}
	
	
	return 0;
}