#include <iostream>


int prime(int n){
 int prime = 1;
 // checks to see if a number is prime (boolean indicator)
 for (int i = 2; i < n; ++i){
   if (n%i==0){
     return 1;
   }
 }
 return 0;
}


int main() {
 int alpha, p, q, temp;
 bool cont = true;
 std::cout << "insert alpha term\n";
 std::cin >> alpha;
 std::cout << "insert paired sequences\n";
 while (cont){
   std::cin >> p >> q;
   if ((p && q) > 0){
     if ((prime(p) == 1) || (prime(q) == 1)){
       std::cout << "This is not special\n";
     }
     else{
       temp = prime(p * p + q * q + alpha);
       if (temp == 0){
         std::cout << "This is an alpha couple\n";
       }
       else{
         std::cout << "This is not special\n";
       }
     }
   }
   else{
     cont = false;
     std::cout << "You have entered a negative term or 0, the program is terminated\n";
   }
 }
 return 0;
}
