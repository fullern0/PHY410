#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main(){
     std::string pnt;
     const double prec = std::numeric_limits<double>::epsilon();
     std::vector<float> coor(4);
     std::cout << "Enter two points as X1 Y1 X2 Y2: ";
     std::cin >> coor[0] >> coor[1] >> coor[2] >> coor[3];
     if(((coor[2]-coor[0])<prec)||((coor[3]-coor[1])<prec)){
          std::cout << "Warning: The difference between the points enetered is below the current machine working precision.\n";
     }
     float m=(coor[3]-coor[1])/(coor[2]-coor[0]);
     float b=coor[1]-m*coor[0];
     float Xm=(coor[0]+coor[2])/2;
     float Ym=(coor[1]+coor[3])/2;
     float pm=-1/m;
     float pb=coor[1]-pm*coor[0];
     std::printf("The slope is %f\nThe y-intercept is %f\nThe midpoint is (%f,%f)\n",m,b,Xm,Ym);
     std::printf("The equation of the line is y=%fx%+f\nThe equation of the line perpendicular to this and passing through the first point is y=%fx%+f\n",m,b,pm,pb);
} 
