#include <stdio.h>
#include <stdlib.h>

double geoReiheRekursiv(double summe, int n) {
    if (n <= 0) {
        return summe;
    }
    return summe + geoReiheRekursiv(summe * 0.5, n - 1);
}

int main() {
    int i = 0;
    int *pI = &i;
    double result = geoReiheRekursiv(1, 2);

    printf("Ergebnis: %f", result);
    return 0;
}
