#include <cassert>


int naivePower(int x, int n) {

    if (x == 0) return 0;
    if (n == 0) return 1;

    return x * naivePower(x, n - 1);
}


int unoptimizedDCPower(int x, int n) {

    if (x == 0) return 0;
    if (n == 0) return 1;

    if (n%2 == 0) return unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);

    else return x * unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);
}


int optimizedDCPower(int x, int n) {

    if (x == 0) return 0;
    if (n  == 0) return 1;

    int temp = optimizedDCPower(x, n / 2);

    if (n%2 == 0) return temp * temp;

    else return x * temp * temp;
}

int main () {

    assert(naivePower(2,3) == 8);
    assert(unoptimizedDCPower(2,3) == 8);
    assert(optimizedDCPower(2,3) == 8);

    assert(naivePower(2,4) == 16);
    assert(unoptimizedDCPower(2,4) == 16);
    assert(optimizedDCPower(2,4) == 16);

    assert(naivePower(2,0) == 1);
    assert(unoptimizedDCPower(2,0) == 1);
    assert(optimizedDCPower(2,0) == 1);
}
