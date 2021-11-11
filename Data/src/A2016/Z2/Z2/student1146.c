#include <stdio.h>
#include <math.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

#define PI 3.1415926

int main() {
	double x[500], d, m, s, u;
	int n, i, j;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) scanf("%lf", &x[i]);
	
	for (i = 0; i < n; i++) {
		u = abs(x[i]);
		d = u * 180 / PI;
		m = (d - (int)d)*60;
		s = round((m - (int)m)*60);
		if (s > 30 && s < 59.99) {
			for (j = i; j < n - 1; j++) x[j] = x[j+1];
			n--;
			i--;
		}
	}
	
	printf("Uglovi su:\n");
		
	for (i = 0; i < n; i++) {
		u = abs(x[i]);
		d = u * 180 / PI;
		m = (d - (int)d)*60;
		s = round(((m - (int)m)*60));
		if (s > 59.99) {
			s = 0;
			m++;
			if (m > 59.99) {
				m = 0;
				d++;
			}
		}
		if (x[i] < 0) printf("-");
		printf("%d stepeni %d minuta %d sekundi\n", (int)d, (int)m, (int)s);
	}
	
	return 0;
}
