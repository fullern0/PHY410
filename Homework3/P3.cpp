#include<iostream>
#include<math.h>

unsigned long long int factorial(int x){
     unsigned long long int val=1;
     for(int i=2; i<=x; i++){
          val*=i;
     }
     return val;
}

double stirling(int x){
     double val=x*log(x)-x;
     return val;
}

int main(){
     int val=-1;
     while(val<0){
          std::cout << "Enter a value to compute its factorial: ";
          std::cin >> val;
          if(val<0){
               std::cout << "Please enter a positive integer.\n";
          }
     }
     if(val<=20){
          unsigned long long int f=factorial(val);
          std::printf("%i!=%llu\n",val,f);
     }
     else{
          double f=stirling(val);
          std::printf("%i! is approximately Exp(%f)\n",val,f);
     }
}
