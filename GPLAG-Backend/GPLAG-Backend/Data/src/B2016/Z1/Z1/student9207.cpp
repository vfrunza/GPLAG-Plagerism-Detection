//B 2016/2017, Zadaća 1, Zadatak 1
#include<iostream>
#include<vector>
#include<cmath>


std::vector<int>IzdvojiGadne (std::vector<int> v,bool b){
	int br_0(0),br_1(0),br_2(0);
     std::vector<int>opaki;
     std::vector<int>odvratni;
     
  	for(int i=0;i<int(v.size());i++){
  		int a=v[i];
  		 br_0=0,br_1=0,br_2=0;
	   do{
		
		int ostatak;
        ostatak=(std::abs(v[i]))%3; 
		
		if(ostatak==0) br_0++; 
		if(ostatak==1) br_1++;
		if(ostatak==2) br_2++;
		
		v[i]/=3;

} while((v[i])!=0 );
                     /*ODVRATNI */
if (((br_0%2!=0 && br_1%2!=0 && br_2%2!=0) ||((br_0==0 && br_2==0)&&br_1%2!=0) ||((br_0==0 && br_1==0)&&(br_2%2!=0)) || ((br_2==0)&&(br_0%2!=0 && br_1%2!=0)) || ((br_1==0)&&(br_2%2!=0 && br_0%2!=0)) || ((br_0==0)&&(br_2%2!=0 && br_1%2!=0))))    { odvratni.push_back(a);}

                       /*OPAKI*/	
                         
else  if  (br_0 %2==0 && br_1 %2==0 && br_2 %2==0) {
	opaki.push_back(a);}



}

for(int i=0;i<int(odvratni.size());i++){
	for(int j=0;j<i;j++)  if (odvratni[i]==odvratni[j]){ odvratni.erase(odvratni.begin()+i);i--; }
}

for(int i=0;i<int(opaki.size());i++){
for(int j=0;j<i;j++) if(opaki[i]==opaki[j]) {opaki.erase(opaki.begin()+i); i--;}

}

if (b==true) return opaki;
else   return odvratni; 

}

int main(){
	int br;
	std::vector<int>v(0);
	std::vector<int>opaki(0);
	std::vector<int>odvratni(0);
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		
		std::cin>>br;
		if(br!=0) v.push_back(br);
		
	} while(br!=0);
	
	opaki=IzdvojiGadne(v,true);
	odvratni=IzdvojiGadne(v,false);

	   std::cout<<"Opaki: ";
	  for(int i=0;i<int(opaki.size());i++ ){
	      std::cout<<opaki[i]<<" ";
	   
	} 
	
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: "; 
	for(int i=0;i<int(odvratni.size());i++){
	  std::cout<<odvratni[i]<<" ";
	
	}
	

return 0;
	
	}
	

 










