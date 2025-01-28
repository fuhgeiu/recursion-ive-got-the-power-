#include <cassert>
#include <chrono>
#include <iostream>


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

double (*func) (int,int);

double print_elapsed_time_naive (int x, int n) {

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    naivePower(x,n);
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

double print_elapsed_time_unoptimized (int x, int n) {

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    unoptimizedDCPower(x,n);
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

double print_elapsed_time_optimized (int x, int n) {

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    optimizedDCPower(x,n);
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}



int main () {

    assert(naivePower(2,4) == 16);
    assert(unoptimizedDCPower(2,4) == 16);
    assert(optimizedDCPower(2,4) == 16);


    assert(naivePower(2,0) == 1);
    assert(unoptimizedDCPower(2,0) == 1);
    assert(optimizedDCPower(2,0) == 1);


// for large values of x
    print_elapsed_time_naive(100000,4);
    print_elapsed_time_unoptimized(100000,4);
    print_elapsed_time_optimized(100000,4);


// for large values of n
    print_elapsed_time_naive(9,100000);
    print_elapsed_time_unoptimized(9,100000);
    print_elapsed_time_optimized(9,100000);

    print_elapsed_time_optimized(9,9188888);

    print_elapsed_time_optimized(9,36999);
    print_elapsed_time_optimized(9,200000);


}
