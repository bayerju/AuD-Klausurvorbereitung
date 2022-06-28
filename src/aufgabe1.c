#include <stdio.h>
#include <stdlib.h>

double geoReihe(int n) {
    int i = 0;
    double sum = 1, q=0.5, ai = 1;
    while(i<n) {
        ai = q * ai;
        sum += ai;
        i++;
    }
    return sum;
}

int main() {
    double result = geoReihe(4);

    printf("Ergebnis: %f", result);
    return 0;
}
