/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<ctime>

using namespace std;

int const L=30;
int N=0;

bool checkNumber(int num,bool which) {
	int b=3;
	int count=0;
	int arr[1000];
	while(num!=0) {
		int x=num % b;
		num/=b;
		if(x<0)
		     num+=1;
		arr[count++]=x;
	   }
	   int counters[30]= {0,0,0};
	   for(int i=0;i<count;i++) {
	   	if (arr[i] == 0) {
	   		counters[0]++;
	   	}
	   	if(arr[i] == 1) {
	   		counters[1]++;
	   	}
	   	if(arr[i] == 2) {
	   		counters[2]++;
	   		}
	   }
	   count=0;
	   for(int i=0;i<3;i++) {
	   	if(counters[i] !=0) {
	   		arr[count++] = counters [i];
	   	}
	   	
	   }
	   switch(which) {
	   	case true:
	   	
	   	        for(int i=0;i<count;i++) {
	   	        	if(arr[i] % 2 !=0) {
	   	        		return false;
	   	        	}
	   	        }
	   	        return true;
	   	        
	   	case false:
	   	
	   	        for(int i=0;i<count;i++) {
	   	        	if(arr[i] % 2== 0) {
	   	        		return false;
	   	        		
	   	        	}
	   	        }
	   	        return true;
	   	default:           return false;
	   }
}
bool isNumExits(int num,int* arr) {
	for(int i=0;i<N;i++) {
		if(arr[i] ==  num) {
			return true;
		}
	}
	return false;
}
int* IzdvojiGadne(int* arr,bool which) {
	int newArr[1000];
	for(int i=0;i<L;i++) {
		if(checkNumber(arr[i],which) && !( isNumExits(arr[i],arr))) {
			newArr[N++] = arr[i];
		}
	}
	return newArr;
}
void check(int N) {
	cout<< N <<"-";
	int b=3;
	while(N !=0) {
		int x= N % b;
		N /=b;
		if(x<0)
		     N +=1;
		cout<<x<<"";
	}
}

int main ()
{
	int arr[L];
	int* newArr;
	int x;
	bool which;
	cout<<"Unesite brojeve(0 za prekid unosa : Opaki: Odvratni: "<<endl;
	
	srand(time(NULL));
	for(int i=2;i<L;i++) {
		x=rand() % 99;
		arr[i]=x;
	}
	arr[0]=56;
	arr[1]=67;
	newArr= IzdvojiGadne(arr,which);
	for(int i=0;i<N;i++) {
		cout<<newArr[i]<<endl;
	}
	cout<<endl;
	
	return 0;
	
	
	
}