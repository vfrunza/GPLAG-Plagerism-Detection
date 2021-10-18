#include <iostream>
#include <stdexcept>
#include <new>


int **KreirajTrougao(int n){
	if (n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	try {
		int **a(new int *[n]);
		try {
			a[0]=new int[1];
				for(int i=1;i<n;i++){
				a[i]=a[i-1]+2*i+1;
				}
				for(int i=0;i<2*i+1;i++)
				for(int j=0;j<2*i+1;j++){
				if(j<(2*i+2)/2) 
				a[i][j]=(2*i+2-j-1-i);
				else{
					a[i][j]=j+1-i;
				}
			}
			return a;
		}
		catch(...){
			delete[] a;
			throw;
		}
	}
	catch(...){
		throw;
	}
}
int main ()
{
	try{
		int n;
		std::cout<<"Koliko zelite redova: ";
		std::cin>>n;
		auto mat=KreirajTrougao(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<2*i+1;j++){
				std::cout<<mat[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	/*	for(int i=0;i<n;i++)
		{
			delete mat[i];
		}
		delete  mat[0];
		delete mat;*/
		delete [] mat[0];
		delete [] mat;
	}
	catch(std::domain_error poruka){
		std::cout<<"Izuzetak: "<<poruka.what();
	}
	catch(...){
		std::cout<<"Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}