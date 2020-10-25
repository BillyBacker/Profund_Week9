#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
bool onCannon(int x, int y, int r) {
	return (pow(x - sqrt(r) - (sqrt(r) / 4), 2) + pow(y - sqrt(r) + (sqrt(r) / 2), 2) <= r / 8);
}
bool onBody(int x, int y, int r) {
	return (pow(x - sqrt(r), 2) + pow(y - sqrt(r), 2) <= r);
}
bool onEdge(int x, int y, int r) {
	return fabs((pow(x-sqrt(r), 2)+pow(y+(sqrt(r)/2),2))-3*r) <= r/5;
}
int main() {
	int a, r;
	while (true) {
		printf("Enter Sphere radius : ");
		scanf("%d", &a);
		r = a * a;
		if (a >= 9) {
			for (int y = 0; y < a * 2 + 1; y++) {
				for (int x = 0; x < a * 2 + 1; x++) {
					if (onCannon(x, y, r) && onBody(x, y, r)) {
						printf("##");
					}
					else if (onEdge(x, y, r) && onBody(x, y, r)) {
						printf("# ");
					}
					else if (!onCannon(x, y, r) && onBody(x, y, r)) {
						printf(". ");
					}
					else {
						printf("  ");
					}

				}
				printf("\n");
			}
			break;
		}
		else {
			printf("Radius %d is too small to form a Death star.\nTry again\n", a);
		}
	}
}