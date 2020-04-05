#include <iostream>

int numDigitsNaive(int n){
    int rtrn = 0;
    while(n>=1) {
        n /= 10;
        rtrn++;
    }
    return rtrn;
}

int main() {
    printf("%d has %d digits\n",17,(numDigitsNaive(17)));
    printf("%d has %d digits\n",5,(numDigitsNaive(5)));
    printf("%d has %d digits\n",1265,(numDigitsNaive(1265)));
    printf("%d has %d digits\n",100,(numDigitsNaive(100)));

    return 0;
}