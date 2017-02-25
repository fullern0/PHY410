#include<iostream>

unsigned long long int factorial(int x){
     unsigned long long int val=1;
     for(int i=2; i<=x; i++){
          val*=i;
     }
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
          if(val>20){
               val=-1;
               std::cout << "Numbers greater than 20! will result in arithmatic overflow. Enter an integer less than or equal to 20.\n";
          }
     }
     unsigned long long int f=factorial(val);
     std::printf("%i!=%llu\n",val,f);
}
