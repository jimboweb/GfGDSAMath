#include <iostream>
using namespace std;

int numDigitsNaive(int n){
    int rtrn = 0;
    while(n>=1) {
        n /= 10;
        rtrn++;
    }
    return rtrn;
}



int countSetBitsNaive(int num){
    int count = 0;
    while(num>0){
        count = count + (num & 1);
        num = num>>1;
    }
    return count;
}


int countSetBits(int num){
    int count = 0;
    while(num>0){
        num = num & (num-1);
        count++;
    }
    return count;
}

int countSetBitsLookup(int n){
    int table[256];
    table[0]=0;
    for(int i=1;i<256;i++){
        table[i]=(i&1) + table[i/2];
    }
    int count = 0;
    for(int i=0;i<4;i++){
        count = count + table[n&0xff];
        n = n>>8;
    }
    return count;
}

bool isPowerOfTwo(int n){
    return n!=0 && (n&(n-1))==0;
}

void testIsPowerOfTwo(){
    int num = 4;
    string isOrIsNot = isPowerOfTwo(num)?" is ":" is not ";
    cout << num << isOrIsNot << "a power of 2" << endl;
    num = 6;
    isOrIsNot = isPowerOfTwo(num)?" is ":" is not ";
    cout << num << isOrIsNot << "a power of 2" << endl;
    num = 1024;
    isOrIsNot = isPowerOfTwo(num)?" is ":" is not ";
    cout << num << isOrIsNot << "a power of 2" << endl;
    num = 0;
    isOrIsNot = isPowerOfTwo(num)?" is ":" is not ";
    cout << num << isOrIsNot << "a power of 2" << endl;
    num = 5;
    isOrIsNot = isPowerOfTwo(num)?" is ":" is not ";
    cout << num << isOrIsNot << "a power of 2" << endl;
    num = 8;
    isOrIsNot = isPowerOfTwo(num)?" is ":" is not ";
    cout << num << isOrIsNot << "a power of 2" << endl;
}

/**
 * Checks if Kth bit is set
 * @param n the number you're checking
 * @param k the bit, where the first bit is 1
 * @return
 */
bool kthBitIsSet(int n, int k){
    return ((n>>(k))&1)!=0;
}


void testKthBitIsSet(){
    int num=5, bitNum=1;
    printf("kthBitIsSet(%d, %d) = %d\n",num,bitNum,kthBitIsSet(num,bitNum));
    bitNum=2;
    printf("kthBitIsSet(%d, %d) = %d\n",num,bitNum,kthBitIsSet(num,bitNum));
    num=6;
    printf("kthBitIsSet(%d, %d) = %d\n",num,bitNum,kthBitIsSet(num,bitNum));
    num=1024;
    bitNum=10;
    printf("kthBitIsSet(%d, %d) = %d\n",num,bitNum,kthBitIsSet(num,bitNum));
    num=1024;
    bitNum=11;
    printf("kthBitIsSet(%d, %d) = %d\n",num,bitNum,kthBitIsSet(num,bitNum));
    num=1024;
    bitNum=11;
    printf("kthBitIsSet(%d, %d) = %d\n",num,bitNum,kthBitIsSet(num,bitNum));

}

void testCountSetBits(){
    int num = 12;
    printf("%d has %d bits set\n", num, countSetBitsLookup(num));
    num = 0;
    printf("%d has %d bits set\n", num, countSetBitsLookup(num));
    num = 1024;
    printf("%d has %d bits set\n", num, countSetBitsLookup(num));
    num = 1023;
    printf("%d has %d bits set\n", num, countSetBitsLookup(num));
    num = 0x7FFFFFFF;
    printf("%d has %d bits set\n", num, countSetBitsLookup(num));
    num = 25;
    printf("%d has %d bits set\n", num, countSetBitsLookup(num));
}

int oddOccurringNumber(int n[],int size){
    int rtrn = 0;
    for(int i=0;i<size;i++){
        rtrn = rtrn^n[i];
    }
    return rtrn;
}

void testOddOccurringNumber(){
    int arr[] = {4,3,3,12,4,4,4,5,5};
    printf("%d",oddOccurringNumber(arr,9));
}

int missingNumber(int arr[], int size){
    int rtrn = 0;
    for(int i=1;i<=size+1;i++){
        rtrn = i^rtrn;
    }
    for(int i=0;i<size;i++){
        rtrn = rtrn ^ arr[i];
    }
    return rtrn;
}

int getFirstSetBit(int n){
    unsigned int rtrn = 0;
    if(n==0){
        rtrn = 0;
        return rtrn;
    }
    while((n&1)==0){
        rtrn++;
        n=n>>1;
    }
    return rtrn+1;
}

void testMissingNumber(){
    int arr[] = {3,1,4,2,6};
    printf("missing number is %d\n",missingNumber(arr,5));
}

int rightmostDifferentBit(int n, int m){
    int count = 0;
    while(((n^m)&1)==0){
        n=n>>1;
        m=m>>1;
        count++;
    }
    return count;
}

void testRightmostDifferentBit(){
    int n,m;
    n = 15, m=4;
    printf("rightmost different bit of %d and %d is %d\n",n,m,rightmostDifferentBit(n,m));
    n = 10, m=16;
    printf("rightmost different bit of %d and %d is %d\n",n,m,rightmostDifferentBit(n,m));
}

int maxConsecutiveOnes(int x)
{
    int max = 0;
    int count = 0;
    while(x>0){
        if(x&1==1){
            count++;
            if(count>max){
                max = count;
            }
        } else {
            count = 0;
        }
        x=x>>1;
    }
    return max;
}

int main() {
    testKthBitIsSet();
    return 0;
}