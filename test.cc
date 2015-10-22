#include <iostream>
#include <cmath>

using namespace std;


    int gcd(int a, int b)
    {
        while(b){
            a %= b;
            a ^= b;
            b ^= a;
            a ^= b;
        }
        return a;
    }
    int getInitial(int n) {
        // write code here
        long a = pow(n, n);
        long b = pow(n-1, n), c = gcd(a, b);
        cout << a << endl << b << endl << c << endl;
        a /= c;
        b /= c;
        c = b;
         
        while(c<n-1)
            c += b;
         
        return c/b*a-n+1;
    }

int main(int argc, char const *argv[])
{
    int n;
    while(cin >> n){
        double a = pow(n, n);
        long b = a;
        long c = pow(n, n);
        cout << b << endl << c << endl;
        cout << sizeof(double) << endl << sizeof(long) << endl;
        cout << sizeof(pow(n, n)) << endl;
    }
    return 0;
}