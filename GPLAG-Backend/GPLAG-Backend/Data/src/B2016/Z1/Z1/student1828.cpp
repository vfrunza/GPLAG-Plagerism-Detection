#include <iostream>
#include <vector>
#include <string>
 
std::vector<int>IzdvojiGadne(std::vector<int>Brojevi,bool konj){    
	     for (int i=0;i<Brojevi.size();i++){
	     	for (int l=i+1;l<Brojevi.size();l++){
	     		if (Brojevi[i]==Brojevi[l]){
	     			Brojevi.erase(Brojevi.begin()+l);
	     			l--;
	     		}
	     	}
	     }
	     std::vector<long long int>brojke;
	    std::vector<int>Opaki;
	    std::vector<int>Odvratni;
	    for (int i=0;i<Brojevi.size();i++)   {
	    		 long long int k=1;
	    		long long int suma=0;
	    		long long int p=Brojevi[i];
	    	while(p!=0 ) {
	    		if (p<0) {(p=-p);}
	    		long long int Ostatak=(p%3); 
                suma=suma + (k*Ostatak);
               	p=p/3;
                k=k*10;
	    			}
	    	 brojke.push_back(suma);
	    	}
	    	for (int i=0; i<brojke.size();i++ ){
	    		long long int s=brojke[i];
	    		std::vector<int>sa1;
	    			std::vector<int>sa2;
	    			std::vector<int>sa0;
	    		while (s>0){
	    			int broj=s%10;
	    			 if (broj==0){sa0.push_back(broj); }
	    			 else if (broj==1){sa1.push_back(broj); }
	    			 else if (broj==2){sa2.push_back(broj); }
	    			 s=s/10;
	    		}	
	    		if ((sa1.size()%2==0) && (sa2.size()%2==0) && (sa0.size()%2==0)){
	    			 	     Opaki.push_back(Brojevi[i]);
	    			 }
	    			 else if ((sa1.size()%2!=0) && (sa2.size()%2!=0) && (sa0.size()%2!=0) || (sa1.size()%2!=0) && (sa2.size()==0) && (sa0.size()==0) || (sa1.size()==0) && (sa2.size()%2!=0) && (sa0.size()==0) || (sa1.size()==0) && (sa2.size()==0) && (sa0.size()%2!=0) || (sa1.size()%2!=0) && (sa2.size()%2!=0) && (sa0.size()==0) || (sa1.size()==0) && (sa2.size()%2!=0) && (sa0.size()%2!=0) || (sa1.size()%2!=0) && (sa2.size()==0) && (sa0.size()%2!=0)){
	    			 	Odvratni.push_back(Brojevi[i]);
	    			 }
	            sa1.resize(0);
	            sa2.resize(0);
	            sa0.resize(0);
	    	}  
	    	 	if (konj==true){
	    		return Opaki;
	    	}
	    	else if (konj==false){
	    		return Odvratni;
	    	}
}
 	

int main ()
{ 
	int b,brojevi;
std::vector< int>Brojevi;
  

	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(int i=0;i<100;i++){
		std::cin>>brojevi;
		if (brojevi==0){ break; }
		Brojevi.push_back(brojevi);
	}
	     std::vector<int>Opaki1;
     Opaki1=IzdvojiGadne(Brojevi,true);
     std::vector<int>Odvratni2;
     Odvratni2=IzdvojiGadne(Brojevi,false);
	std::cout<<"Opaki: ";
	for (int i=0;i<Opaki1.size();i++){
		std::cout<<Opaki1[i] <<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for (int i=0;i<Odvratni2.size();i++){
		std::cout<<Odvratni2[i]<<" ";
	}
	return 0;
}