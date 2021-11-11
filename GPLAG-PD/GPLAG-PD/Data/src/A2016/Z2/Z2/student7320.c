#include <stdio.h>
#include <math.h>

#define PI 3.1415926
#define eps 0.000000000001
int main() {
	int n, i, j;
	double arr[510], trenutni_ugao, sekunde;
	int deg, min, sec;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
		scanf("%lf", &arr[i]);
	
	printf("Uglovi su: \n");
	for (i = 0; i < n; i++) {
		trenutni_ugao = 180. / PI * arr[i];
		if (trenutni_ugao > 0) {
			sekunde = trenutni_ugao * 3600;
			sekunde = (int)(sekunde + 0.5);
			deg = min = sec = 0;
			deg = sekunde / 3600;
			min = (sekunde - deg * 3600) / 60;
			sec = sekunde - (deg * 3600 + min * 60);
			if (sec >= 60) {
				sec -= 60;
				min++;
			}
			if (min >= 60) {
				min -= 60;
				deg++;
			}
			if (fabs(sec) > 30) 
			{
				for (j = i; j < n - 1; j++)
					arr[j] = arr[j + 1];
				n--;
				i--;
				//printf("%d stepeni %d minuta %d sekundi\n", deg, min, sec);
			}
		}
		else {
			double sekunde = trenutni_ugao * -3600.;
			sekunde = (int)(sekunde + 0.5);
			deg = min = sec = 0;
			deg = sekunde / 3600;
			min = (sekunde - deg * 3600) / 60;
			sec = sekunde - (deg * 3600 + min * 60);
			if (sec <= -60) {
				sec += 60;
				min--;
			}
			if (min <= -60) {
				min += 60;
				deg++;
			}
			if (fabs(sec) > 30) {
				for (j = i; j < n - 1; j++)
					arr[j] = arr[j + 1];
				n--;
				i--;
				
			}
		}
	}
	for (i = 0; i < n; i++) {
		int minus = 0;
		trenutni_ugao = 180. / PI * arr[i];
		if (trenutni_ugao > 0) {
			sekunde = trenutni_ugao * 3600;
		}
		else {
			minus = 1;
			sekunde = trenutni_ugao * -3600;
		}
		sekunde = (int)(sekunde + 0.5);
		deg = min = sec = 0;
		deg = sekunde / 3600;
		min = (sekunde - deg * 3600) / 60;
		sec = sekunde - (deg * 3600 + min * 60);
		if (sec >= 60) {
			sec -= 60;
			min++;
		}
		if (min >= 60) {
			min -= 60;
			deg++;
		}
		if (minus) {
			if (deg == 0) printf("%d stepeni %d minuta %d sekundi\n", deg, min, sec);
			else printf("-%d stepeni %d minuta %d sekundi\n", deg, min, sec);
		}
		else printf("%d stepeni %d minuta %d sekundi\n", deg, min, sec);
	}
	return 0;
}
