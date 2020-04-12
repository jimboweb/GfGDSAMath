#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

bool isPal(std::string str, int s, int e){
    if(s>=e)
        return true;
    if(str[s]!=str[e])
        return false;
    return isPal(str,s+1,e-1);
}

void testIsPal(){
    std::string str;
    str = "aabebaa";
    std::cout<<isPal("aabebaax",0,6);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int factorialWithTailRecursion(int n,int val=1){
    if(n==0){
        return val;
    }
    return factorialWithTailRecursion(n-1,n*val);
}

int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int fibWTR(int n, int a=0, int b=1){
    if(n==0)
        return a;
    if(n==1)
        return b;
    return fibWTR(n-1,b,a+b);
}

int sumDigits(int n, int total=0){
    if(n==0)
        return total;
    div_t divrslt = std::div(n,10);
    return sumDigits(divrslt.quot,total+divrslt.rem);
}

/**
 * very inefficient method of finding the maximum cuts of a rope from 3 lengths
 * (I think this is the same as the backpack problem)
 * @param length length of rope
 * @param firstL first cut length
 * @param secondL second cut length
 * @param thirdL third cut length
 * @return
 */
int cutRope(int length, int firstL, int secondL, int thirdL){
    //std::cout<<"length = "<<length<<"\n";
    if(length==0){
        return 0;
    }
    if(length<0){
        return -1;
    }
    int max=-1;
    int withFirstL=cutRope(length-firstL,firstL,secondL,thirdL);
    if(withFirstL>=0&&max<withFirstL+1) {
        //printf("adding withFirstL: %d\n", withFirstL);
        max = withFirstL + 1;
    }
    int withSecondL=cutRope(length-secondL,firstL,secondL,thirdL);
    if(withSecondL>=0&&max<withSecondL+1) {
        max = withSecondL + 1;
        //printf("adding withSecondL: %d\n",withSecondL);
    }
    int withThirdL = cutRope(length-thirdL,firstL,secondL,thirdL);
    if(withThirdL>=0 && max<withThirdL+1){
        max= withThirdL+1;
        //printf("adding withThirdL: %d\n",withThirdL);
    }
    //std::cout<<"max = "<<max<<"\n";
    return max;
}

/**
 * tower of hanoi
 * @param N the height of the tower
 * @param from
 * @param to
 * @param aux
 * @param moves how many moves you've made
 */
void toh(int N, int from, int to, int aux, long long &moves) {
    if(N==1){
        moves++;
        printf("move disk %d from rod %d to rod %d\n", N, from, to);
        return;
    }
    toh(N-1,from,aux,to,moves);
    moves++;
    printf("move disk %d from rod %d to rod %d\n", N, from, to);
    toh(N-1,aux,to,from,moves);
}

void printList(const int list[],int size){
    for(int i=0;i<size;i++){
        cout<<list[i]<<" ";
    }
    cout<<"size = " << size;
    cout << "\n";
}

int subSetSum(const int list[], int n, int sum){
    if(n==0)
        return sum==0?1:0;
    return subSetSum(list,n-1,sum)+subSetSum(list,n-1,sum-list[n-1]);
}

// Complete the function
// n: Input n
// counter: variable has already been declared in driver code
//          you just have to use this variable.
// Return True if the given number is a lucky number else return False
int counter = 2;
bool isLucky(int n) {
    if(counter>n)
        return true;
    if(n%counter==0)
        return false;
    return isLucky(n-n/counter++);
}

/**
 * Josephus problem - I had to look up the formula for this
 * @param n number of people
 * @param k kill every k
 * @return
 */
int josephus(int n, int k)
{
    if(n==0){
        return 1;
    }
    return (josephus(n-1,k)+k-1)%n+1;


}


void powerSetString(string o, string s="", int i=0){
    auto l = (int)o.length();
    if(i==l) {
        cout << s << ", ";
        return;
    }
    powerSetString(o,s,i+1);
    powerSetString(o,s+o[i],i+1);
}

vector<string> powerSet(string s, string current = "", int index =0){
    int n = (int)s.length();
    vector<string> rtrn;
    if(index == n){
        rtrn.push_back(current);
        return rtrn;
    }

    vector<string> without = powerSet(s, current,index+1);
    rtrn.insert(rtrn.end(),without.begin(),without.end());
    vector<string> with = powerSet(s,current+s[index],index+1);
    rtrn.insert(rtrn.end(),with.begin(),with.end());
    return rtrn;
}

void print_vector(vector<string> v){
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}

void testPowerSet(){
    vector<string> set = powerSet("abc");
    print_vector(set);
}

int* insertAtEnd(int arr[],int sizeOfArray,int element)
{
    int newArray[sizeOfArray+1];
    for(int i=0;i<sizeOfArray;i++){
        newArray[i]=arr[i];
    }
    newArray[sizeOfArray]=element;
    return newArray;
}

vector<int> leaders(int arr[], int n) {

    vector<int> rtrn;
    rtrn.push_back(arr[n - 1]);
    int biggest = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > biggest) {
            biggest = arr[i];
            rtrn.push_back(arr[i]);
        }
    }
    return rtrn;
}

int stockBuSellNaive(int price[], int n){
    return 0;
}

int stockBuySell(int price[], int n){
    int totalProfit = 0;
    int currentProfit = 0;
    int prevLowPos = 0;
    int prevHiPos =0;
    for(int i=1;i<n;i++){
        if(price[i]<price[i-1]){
            prevHiPos=i-1;
            if(prevHiPos>prevLowPos)
                printf("(%d, %d) ",prevLowPos, prevHiPos);
            totalProfit+=currentProfit;
            currentProfit=0;
            prevLowPos=i;
        } else if(price[i]>price[i-1]) {
            prevHiPos=i;
            currentProfit+=(price[i]-price[i-1]);
        } else {
            prevLowPos = i;
        }
    }
    if(currentProfit>0)
        printf("(%d, %d) ",prevLowPos, prevHiPos);
    totalProfit+=currentProfit;
    if(totalProfit == 0)
        printf("No Profit");
    return totalProfit;
}

void generateStockBuySellInputs(int num, int maxSize, int maxStockVal){
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        int size = rand()%maxSize;
        printf("%d\n",size);
        for(int j=0;j<size;j++){
            printf("%d ",(rand()%maxStockVal));
        }
        printf("\n");
    }
}


int trappingRainWater(int arr[], int n){
    int rtrn=0;
    int lMax[n],rMax[n];
    lMax[0]=arr[0];
    for(int i=1;i<n;i++){
        lMax[i]=arr[i]>lMax[i-1]?arr[i]:lMax[i-1];
    }
    rMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rMax[i]=arr[i]>rMax[i+1]?arr[i]:rMax[i+1];
    }
    for(int i=0;i<n;i++){
        int min = rMax[i]<lMax[i]?rMax[i]:lMax[i];
        rtrn+=min-arr[i];
    }
    return rtrn;
}

int maxConsOnes(int arr[],int n){
    int count = 0;
    int max=0;
    for(int i=0; i<n; i++){
        if(arr[i]==1) {
            count++;
            if(count>max)
                max=count;
        } else
            count=0;
    }
    return max;
}

int maxSubArraySum(int arr[], int num){
    int curMaxSum = -500000000, maxMaxSum = -500000000;
    for(int i=0;i<num;i++){
        curMaxSum = arr[i]>arr[i]+curMaxSum?arr[i]:arr[i]+curMaxSum;
        if(curMaxSum>maxMaxSum)
            maxMaxSum=curMaxSum;
    }
    return maxMaxSum;
}

int maxCircularSubarray(int arr[], int num){
    int curMaxSum = -500000000, maxMaxSum = -500000000;
    int curMinSum=500000000, minMinSum = 500000000;
    int totalSum=0;
    for(int i=0;i<num;i++){
        totalSum+=arr[i];
        curMaxSum = arr[i]>arr[i]+curMaxSum?arr[i]:arr[i]+curMaxSum;
        if(curMaxSum>maxMaxSum)
            maxMaxSum=curMaxSum;
        curMinSum = arr[i]<arr[i]+curMinSum?arr[i]:arr[i]+curMinSum;
        if(curMinSum<minMinSum)
            minMinSum=curMinSum;
    }
    if(maxMaxSum<0)
        return maxMaxSum;
    int circularMaxSum = totalSum-minMinSum;
    return circularMaxSum>maxMaxSum?circularMaxSum:maxMaxSum;
}

int longestEvenOddSub(int arr[], int n){
    if(n==0)
        return 0;
    int max = 1;
    bool lastEven=arr[0]%2==0;
    for(int i=1;i<n;i++){
        if(lastEven^(arr[0]%2==0))
            max++;
        else
            max=0;
    }
    return max;
}

int maxKSizeContSum(int *arr, int n, int k){
    int max = -5000000;
    int sum = 0;
    for(int i=0;i<n-k;i++){
        sum+=arr[i];
        if(i>=k){
            sum-=arr[i-k];
        }
        max=sum>max?sum:max;
    }
    return max;
}

//positive numbers only
bool isContSumEqualToK(int *arr, int n, int k){
    int sum = 0;
    int contSetSize = 0;
    for(int i=0;i<n-k;i++){
        if(arr[i]>k){
            contSetSize=0;
            continue;
        }
        sum+=arr[i];
        contSetSize++;
        while(sum>k){
            sum-=arr[i-contSetSize];
            contSetSize--;
        }
        if(sum==k)
            return true;
    }
    return false;

}

int testWindowSlide(){
    int arr1[] = {1,8,30,-5,20,7};
    int n = 6;
    int k = 3;
    cout<< maxKSizeContSum(arr1, n, k)<<endl;
}

std::vector<int> multiQuerySum(const int arr[], int arrn, int q[][2], int qn){
    int sums[arrn];
    sums[0]=arr[0];
    vector<int> rtrn;
    for(int i=1;i<arrn;i++){
        sums[i]=arr[i]+sums[i-1];
    }
    for(int i=0;i<qn;i++){
        int start=q[i][0];
        int end = q[i][1];
        if(start==0){
            rtrn.push_back(sums[end]);
        } else {
            rtrn.push_back(sums[start]-sums[end-1]);
        }
    }
    return rtrn;
}

int main() {
    testWindowSlide();
//    int array[]={0,0,0,0,1,1,0,1,1,1,1,0,0,1};
//    printf("%d\n",maxConsOnes(array,14));
    //generateStockBuySellInputs(20,20,10000);
//    int array[] = {100, 180, 260, 310, 40, 535, 695};
//    printf("%d\n",trappingRainWater(array,7));
//    int array2[] = {23, 13, 25, 29, 33, 19, 34, 45, 65, 67};
//    printf("%d\n",trappingRainWater(array2,10));
//    int array3[] = {4, 2, 2, 2, 4};
//    printf("%d\n",trappingRainWater(array3,5));
//    int array4[] = {5,5,5,5,5};
//    printf("%d\n",trappingRainWater(array4,5));
//    int array5[] = {1,5,3,1,2,8};
//    printf("%d\n",trappingRainWater(array5,6));
}