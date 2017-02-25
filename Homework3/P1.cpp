#include<iostream>
#include<stdio.h>
#include<sstream>
#include<vector>
#include<string>
#include<math.h>

int main(){
     std::vector< std::vector<float> > vec;
     float ival;
     std::string inpt;
     std::cout << "Enter a set of 2-D vectors as X1 Y1 X2 Y2 X3 Y3...\n";
     std::getline(std::cin, inpt); 
     std::stringstream istrm(inpt);
     while(istrm >> ival){
          std::vector<float> XYpair(2);
          XYpair[0]=ival;
          istrm >> ival;
          XYpair[1]=ival;
          vec.push_back(XYpair);
     }
     std::vector<float> mag(vec.size());
     for(int i=0;i<vec.size();i++){
          mag[i]=sqrt(pow(vec[i][0],2)+pow(vec[i][1],2));
     }
     float curmax=mag[0];
     float curmin=mag[0];
     int indxmax=0;
     int indxmin=0;
     for(int i=1;i<mag.size();i++){
          if(mag[i]>curmax){
               curmax=mag[i];
               indxmax=i;
          }
          if(mag[i]<curmin){
               curmin=mag[i];
               indxmin=i;
          }
     }
     std::printf("The vector with the minimum magnitude is (%f, %f) with magnitude %f.\n",vec[indxmin][0],vec[indxmin][1],curmin);
     std::printf("The vector with the maximum magnitude is (%f, %f) with magnitude %f.\n",vec[indxmax][0],vec[indxmax][1],curmax);
}
