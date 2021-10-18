/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
using namespace std;
int Obrni(int n){
	int n1=0;
	while(n>0){
		n1=n1*10+(n%10);
		n/=10;
	}
	return n1;
	}

	int Pretvori(int n){
	//Pretvaranje dekadnog u ternarni
	
	int n3=0;
	int br=0;
	do{
	n3=(n3*10)+n%3;
	if(n3==0)br++;
	n=n/3;
	}
	while(n>0);
	
	n3=Obrni(n3);
	for(int i(0);i<br;i++){
	 n3*=10;
	}
	//Provjera pretvaranja
	//cout<<n3<<endl;
	return n3;
	}
	
	
	vector<int> SmjestiUVektor (int n){
		vector<int>v;
		while(n>0){
		int n1=n%10;
		n/=10;
		v.push_back(n1);
		}
		return v;
	}
	
	bool DaLiJeGadan (int n){
		vector<int>v;
		int n1=Pretvori(n);
		v=(SmjestiUVektor(n1));
		//Provjera smjestanja u vektor
	//for(int i(0);i<v.size();i++)
	//cout<<v[i]<<endl;
		int brojaci[3]{0};
		
		int l=v.size();
		for(int i(0);i<l;i++){
			for(int j(0);j<3;j++){
			if(v[i]==j) brojaci[j]++;
		}
		}
		//provjera brojaca
		//for(int i(0);i<3;i++){
		//	cout<<brojaci[i];
		//}
		
		bool parni=true;
		bool neparni=true;
		
	//Da li su svi parni
		for(int i(0);i<3;i++){
			if(brojaci[i]==0) continue;
			if(brojaci[i]%2!=0) parni=false; //ako naidjes na jedan neparan paran stavi na false
			else continue;
		}
		//Da li su svi neparni
		for(int i(0);i<3;i++){
			if(brojaci[i]==0) continue;
			if(brojaci[i]%2==0) neparni=false;  
			else continue;
		
		}
		if (parni==1 && neparni==0) return 1; //parni tj opaki
		 if( neparni==1 && parni==0) return 1; //neparni odvratni
		 return 0;
		 }
		int Pomocna (long long int n){
			vector<int>v;
		int n1=Pretvori(n);
		v=(SmjestiUVektor(n1));
		//Provjera smjestanja u vektor
	//for(int i(0);i<v.size();i++)
	//cout<<v[i]<<endl;
		int brojaci[3]{0};
		
		int l=v.size();
		for(int i(0);i<l;i++){
			for(int j(0);j<3;j++){
			if(v[i]==j) brojaci[j]++;
		}
		}
		int k=0;
		while(brojaci[k]==0 && k<3 ){
			k++;
		}
		return brojaci[k];
		}
		
	vector<int> IzbaciDuple (vector<int>v){
		
			
			for(int i(0);i<int(v.size());i++){ 
			for(int j(i+1);j<int(v.size());j++){
				if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
				}
				
			}
			}

			
			return v;
			
		}

vector<int> IzdvojiGadne (vector<int>v, bool a){
	vector<int>v1;
	int brojac;
	bool negativanbroj=false;
	
	if(a){
		for(int i(0);i<v.size();i++){
			if(v[i]<0){v[i]=(-1)*v[i]; negativanbroj=true;}
			if(DaLiJeGadan(v[i])==1){
				brojac=Pomocna(v[i]);
				if(brojac%2==0){
					if(negativanbroj==1) {v[i]=(-1)*v[i]; v1.push_back(v[i]); negativanbroj=false; }
					else v1.push_back(v[i]);
				}
			   else negativanbroj=false;
			}
			else negativanbroj=false;
		}
	}
	negativanbroj=false;
	if(!a){
		for(int i(0);i<v.size();i++){
			if(v[i]<0){v[i]=v[i]*(-1); negativanbroj=true;}
			if(DaLiJeGadan(v[i])==1){
				brojac=Pomocna(v[i]);
				if(brojac%2!=0){
				if(negativanbroj==1) {v[i]=-v[i]; v1.push_back(v[i]); negativanbroj=false;}
					else v1.push_back(v[i]);
				}
				else negativanbroj=false;
			}
			else negativanbroj=false;
			
		}
	}
	v1=IzbaciDuple(v1);
	return v1;
}

	int main()
{
	vector<int>v,opaki,odvratni;
	bool a=true,b=false;
	long long int n;

	
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	cin>>n;
	
	while(n!=0){
	//	if(n>2147483647)continue;
		//else{
	v.push_back(n);
	cin>>n;
		//}
	}
	opaki=IzdvojiGadne(v,a);
	odvratni=IzdvojiGadne(v,b);
	cout<<"Opaki: ";
	for(int i(0);i<opaki.size();i++)
	cout<<opaki[i]<<" ";
	cout<<endl<<"Odvratni: ";
	for(int i(0);i<odvratni.size();i++)
	cout<<odvratni[i]<<" ";


	return 0;
	}