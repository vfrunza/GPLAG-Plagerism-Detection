/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include <cmath>

std::vector<int>IzdvojiGadne (std::vector<int>v, bool paran) {
	
	int brojac1=0, brojac2=0, brojac3=0, brojac=0;
	paran=true;
	std::vector<int>opak;
	std::vector<int>odvratni;
	for(int i=0; i<v.size(); i++) {
	 if(v[i]<0)
	 v[i]= v[i]*(-1);
	 int temp=v[i];
	while(temp/3!=0) {
	   
	   if(temp%3==0) 
	   	brojac++;
	   	
	   if(temp%3==1)
	   brojac1++;
	   
	   if(temp%3==2)
	   brojac2++;
	   
	   if(temp%3==3)
	   brojac3++;
	}
    if(brojac==true && brojac1==true && brojac2==true && brojac3==true) {
   	opak.push_back(v[i]); 
		   }
    if(brojac==true && brojac1==true && brojac2==true && brojac3==0) {
    opak.push_back(v[i]);
    }
    if(brojac==true && brojac1==true && brojac3==true && brojac2==0) {
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac3==true && brojac2==true && brojac1==0) {
    opak.push_back(v[i]);
    }
    if(brojac3==true && brojac1==true && brojac2==true && brojac==0) {
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac1==true && brojac2==0 && brojac3==0) {
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac2==true && brojac1==0 && brojac3==0) {
    opak.push_back(v[i]);
     }
    if(brojac1==true && brojac2==true && brojac==0 && brojac3==0) {
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac3==true && brojac1==0 && brojac2==0) {
    opak.push_back(v[i]);
    }
    if(brojac1==true && brojac3==true && brojac==0 && brojac2==0) {
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac1==true && brojac3==0 && brojac2==0) {
    opak.push_back(v[i]);
     }
    if(brojac3==true && brojac2==true && brojac==0 && brojac1==0) {
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac3==true && brojac2==0 && brojac1==0){
    opak.push_back(v[i]);
     }
    if(brojac==true && brojac2==true && brojac3==0 && brojac1==0) {
    opak.push_back(v[i]);
     }
    if(brojac3==true && brojac2==true && brojac1==0 && brojac==0) {
    opak.push_back(v[i]);
    }
    if(brojac2==true && brojac1==true && brojac3==0 && brojac==0) {
    opak.push_back(v[i]);
    }
    if(brojac==true && brojac3==0 && brojac2==0 && brojac1==0) {
    opak.push_back(v[i]);
     }
     if(brojac2==true && brojac==0 && brojac3==0 && brojac1==0) {
    opak.push_back(v[i]);
     }
     if(brojac1==true && brojac==0 && brojac2==0 && brojac3==0) {
    opak.push_back(v[i]);
    }
     if(brojac3==true && brojac==0 && brojac2==0 && brojac1==0) {
    opak.push_back(v[i]);
     }
    
    if(brojac==false && brojac1==false && brojac2==false && brojac3==false) {
	odvratni.push_back(v[i]);
	 }
    if(brojac==false && brojac1==false && brojac2==false && brojac3==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac1==false && brojac3==false && brojac2==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac3==false && brojac2==false && brojac1==0) {
    odvratni.push_back(v[i]);
    }
    if(brojac3==false && brojac1==false && brojac2==false && brojac==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac1==false && brojac2==0 && brojac3==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac2==false && brojac1==0 && brojac3==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac1==false && brojac2==false && brojac==0 && brojac3==0) {
    odvratni.push_back(v[i]);
    }
    if(brojac==false && brojac3==false && brojac1==0 && brojac2==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac1==false && brojac3==false && brojac==0 && brojac2==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac1==false && brojac3==0 && brojac2==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac3==false && brojac2==false && brojac==0 && brojac1==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac3==false && brojac2==0 && brojac1==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac==false && brojac2==false && brojac3==0 && brojac1==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac3==false && brojac2==false && brojac1==0 && brojac==0) {
    odvratni.push_back(v[i]);
     }
    if(brojac2==false && brojac1==false && brojac3==0 && brojac==0) {
    odvratni.push_back(v[i]);
    }
    if(brojac==false && brojac3==0 && brojac2==0 && brojac1==0) {
    odvratni.push_back(v[i]);
     }
     if(brojac2==false && brojac==0 && brojac3==0 && brojac1==0) {
    odvratni.push_back(v[i]);
    }
     if(brojac1==false && brojac==0 && brojac2==0 && brojac3==0) {
    odvratni.push_back(v[i]);
     }
     if(brojac3==false && brojac==0 && brojac2==0 && brojac1==0) {
    odvratni.push_back(v[i]);
    }
}
 
if(brojac==true && brojac1==true && brojac2==true && brojac3==true) {
   
		  return opak; }
    if(brojac==true && brojac1==true && brojac2==true && brojac3==0) {
    
    return opak; }
    if(brojac==true && brojac1==true && brojac3==true && brojac2==0) {
    
    return opak; }
    if(brojac==true && brojac3==true && brojac2==true && brojac1==0) {
    
    return opak; }
    if(brojac3==true && brojac1==true && brojac2==true && brojac==0) {
    
    return opak; }
    if(brojac==true && brojac1==true && brojac2==0 && brojac3==0) {
   
    return opak; }
    if(brojac==true && brojac2==true && brojac1==0 && brojac3==0) {
    
    return opak; }
    if(brojac1==true && brojac2==true && brojac==0 && brojac3==0) {
    
    return opak; }
    if(brojac==true && brojac3==true && brojac1==0 && brojac2==0) {
    
    return opak; }
    if(brojac1==true && brojac3==true && brojac==0 && brojac2==0) {
    
    return opak; }
    if(brojac==true && brojac1==true && brojac3==0 && brojac2==0) {
    
    return opak; }
    if(brojac3==true && brojac2==true && brojac==0 && brojac1==0) {
   
    return opak; }
    if(brojac==true && brojac3==true && brojac2==0 && brojac1==0){
    
    return opak; }
    if(brojac==true && brojac2==true && brojac3==0 && brojac1==0) {
    
    return opak; }
    if(brojac3==true && brojac2==true && brojac1==0 && brojac==0) {
    
    return opak; }
    if(brojac2==true && brojac1==true && brojac3==0 && brojac==0) {
    
    return opak; }
    if(brojac==true && brojac3==0 && brojac2==0 && brojac1==0) {
    
    return opak; }
     if(brojac2==true && brojac==0 && brojac3==0 && brojac1==0) {
    
    return opak; }
     if(brojac1==true && brojac==0 && brojac2==0 && brojac3==0) {
    
    return opak; }
     if(brojac3==true && brojac==0 && brojac2==0 && brojac1==0) {
    return opak; }
    
    if(brojac==false && brojac1==false && brojac2==false && brojac3==false) {
	return odvratni; }
    if(brojac==false && brojac1==false && brojac2==false && brojac3==0) {
    return odvratni; }
    if(brojac==false && brojac1==false && brojac3==false && brojac2==0) {
    return odvratni; }
    if(brojac==false && brojac3==false && brojac2==false && brojac1==0) {
    return odvratni; }
    if(brojac3==false && brojac1==false && brojac2==false && brojac==0) {
    return odvratni; }
    if(brojac==false && brojac1==false && brojac2==0 && brojac3==0) {
    return odvratni; }
    if(brojac==false && brojac2==false && brojac1==0 && brojac3==0) {
    return odvratni; }
    if(brojac1==false && brojac2==false && brojac==0 && brojac3==0) {
    
    return odvratni; }
    if(brojac==false && brojac3==false && brojac1==0 && brojac2==0) {
    
    return odvratni; }
    if(brojac1==false && brojac3==false && brojac==0 && brojac2==0) {
    
    return odvratni; }
    if(brojac==false && brojac1==false && brojac3==0 && brojac2==0) {
    
    return odvratni; }
    if(brojac3==false && brojac2==false && brojac==0 && brojac1==0) {
    
    return odvratni; }
    if(brojac==false && brojac3==false && brojac2==0 && brojac1==0) {
    
    return odvratni; }
    if(brojac==false && brojac2==false && brojac3==0 && brojac1==0) {
    
    return odvratni; }
    if(brojac3==false && brojac2==false && brojac1==0 && brojac==0) {
    
    return odvratni; }
    if(brojac2==false && brojac1==false && brojac3==0 && brojac==0) {
    
    return odvratni; }
    if(brojac==false && brojac3==0 && brojac2==0 && brojac1==0) {
    
    return odvratni; }
     if(brojac2==false && brojac==0 && brojac3==0 && brojac1==0) {
    
    return odvratni; }
     if(brojac1==false && brojac==0 && brojac2==0 && brojac3==0) {
    
    return odvratni; }
     if(brojac3==false && brojac==0 && brojac2==0 && brojac1==0) {
    
    return odvratni;}
    
}
int main ()
{
	std::vector<int>z;
	int broj;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	   
   
    	std::cin>>broj;
    	while(broj!=0) {
    	 std::cin>>broj;
    	
    	z.push_back(broj);
    	
    }
	
	std::vector<int>opaki;
	std::vector<int>odvratni;
	
	odvratni=IzdvojiGadne(z, false);
	opaki=IzdvojiGadne(z,true);
	
	std::cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++) {
	 std::cout << opaki[i];
	 if(i!=opaki.size()-1)
	 std::cout<<" ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++) {
	 std::cout<<odvratni[i];
	 if(i!=odvratni.size()-1) 
	 std::cout<<" ";
	}
	
	
	
	
	
	
	
	
	return 0;
}