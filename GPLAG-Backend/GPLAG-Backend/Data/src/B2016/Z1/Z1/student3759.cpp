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


/*std::vector<double> Razlozi(std::vector v){
	
}*/

/*std::vector<double> IzdvojiGadne(std::vector<double> v, bool tf){
	int br0(0), br1(0), br2(0), brEL(0);
	std::vector<double> povratni(v.size());
	
	for(int i=0;i<v.size();i++){
		int temp, temp2(999);
		temp=v[i];
		
		while(temp>0){ 
			temp2=temp%10;
			temp=temp/10;
			std::cout<<temp2<<" ";
			if(temp2==2) br2++;
			else if(temp2==1) br1++;
			else if(temp2==0) br0++;
		}
		if(br0%2==0 && br1%2==0 && br2%2==0){
			povratni[brEL]=v[i];
			brEL++;
		}
		else if((br0%2==1 || br0==0) && (br1%2==1 || br1==0) && (br2%2==1 || br2==0)){
			povratni[brEL]=v[i];
			brEL++;
		}
	}
	return povratni;	
}
*/

std::vector<int> IzdvojiGadne(std::vector<int> v, bool tf){
	
	long int save, save1(0), save2, br(0);
	std::vector<int> duplikati(50);
	int n=v.size();
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i]==duplikati[j]){
				for(int z=i;z<n-1;z++){
					v[z]=v[z+1];
				}
				n--;
			}
		}
		duplikati[i]=v[i];
	}*/
	
	for(int i=0;i<n;i++){
		int brojac(0);
		for(int j=i;j<n;j++){
			if(v[j]==v[i]){
				brojac++;
				if(brojac>1){
					for(int z=j;z<n-1;z++){
						v[z]=v[z+1];
					}
					n--;
					j--;
				}
			}
		}
	}
	
	std::vector<double> trisistem(n);
	for(int i=0;i<n;i++){
		save=v[i];
		while(save!=0){
			save2=fabs(save%3); 
			save=save/3;
			save1+=(save2*pow(10, br));
			br++;
		}
		trisistem[i]=save1;
		save1=0;
		br=0;
	}
	int br0(0), br1(0), br2(0);
	std::vector<int> parni;
	std::vector<int> neparni;
	for(int i=0;i<trisistem.size();i++){
		save=trisistem[i];
		while(save!=0){
			save1=fabs(save%10);
			if(save1==0) br0++;
			if(save1==1) br1++;
			if(save1==2) br2++;
			save/=10;
		}
		if((br0==0 || br0%2==0) && (br1==0 || br1%2==0) && (br2==0 || br2%2==0)){
			parni.push_back(v[i]);
			
		}
		else if((br0==0 || br0%2==1) && (br1==0 || br1%2==1) && (br2==0 || br2%2==1)) neparni.push_back(v[i]);
		br0=0;
		br1=0;
		br2=0;
	}
	if(tf) return parni;
	if(tf==false) return  neparni;
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	
	std::vector<int> v;
	double x;
	for(int i=0;i<1000;i++){
		std::cin>>x;
		if(x==0) break;
		v.push_back(x);
		n++;
	}
	
	
	/*for(int i=0;i<n;i++){
		std::cout<<"bd"<<v[i]<<" ";
	}*/
	std::vector<int>povratniOpak;
	std::vector<int>povratniOdvratan;
	bool tf(true);
	povratniOpak=IzdvojiGadne(v, tf);
	tf=false;
	povratniOdvratan=IzdvojiGadne(v, tf);
	
	std::cout<<"Opaki: ";
	for(int i=0;i<povratniOpak.size();i++){
		std::cout<<povratniOpak[i]<<" ";
	}
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0;i<povratniOdvratan.size();i++){
		std::cout<<povratniOdvratan[i]<<" ";
	}
	return 0;
}