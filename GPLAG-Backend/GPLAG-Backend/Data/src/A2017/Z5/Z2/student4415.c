#include <stdio.h>
#include <math.h>

int main() {
	int p = 89, g=3;
int t= 44, v = 1, w = 39, h = 30;
int x=0;
while(t % 2 == 0){
t = t/2; h = ((h*h) % p);
		if((pow(w,t) % p) != 1){
v = (v * g) % p;
w = (w * h) % p;
}
g = int(std::pow(w,2)) % p;
}
x = (v * int(std::pow(w, (t+1)/2))) % p;
std::cout « x « " " « p - x;
	return 0;
}
