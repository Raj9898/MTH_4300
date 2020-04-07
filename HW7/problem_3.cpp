#include <iostream>


int power(int x, int a){
int val = 1;
for (int i = 0; i < a; ++i){
  val *= x;
}
return val;
}

// recursive function for counting the number of swaps
int swaps(int n, int a, int first, int sum, int k, int minK){
 int val, count=0;
  val = power(first, a);
  // if the current sum is less than the assigned value we
 while (val + sum < n){
   minK = swaps(n, a, first+1, sum+val, k+1, minK);
   ++first;
   val = power(first, a);
 }

 // if the value matches the given sum we add one
 if (val + sum == n){
   if (k < minK){
     minK = k;
   }
 }

 return minK;
}

int main() {
int x, a, i, s, mK, k;
std::cin >> x >> a;
std::cout << swaps(x,a, i=1, s=0, k=1, mK=100) << "\n";
return 0;
}
