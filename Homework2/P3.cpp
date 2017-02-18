#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
     std::vector<int> e={7,6,9};
     std::vector<int> s={2,3,2};
     std::vector<int> b={0,2,4,6,7,7,1,1};
     std::vector<std::string> itms(3);
     std::string order;
     resrt:
     std::cout << "Please enter your order selection using the item identifiers seperated by spaces.\n";
     std::cin >> itms[0] >> itms[1] >> itms[2];
     if(itms.size()!=3){
          std::printf("Please enter three items with one from each category.\n");
          goto resrt;
     }
     
     int total=0;
     if((std::find(itms.begin(),itms.end(),"e1")!=itms.end())&&(std::find(itms.begin(),itms.end(),"s1")!=itms.end())){
          if((std::find(itms.begin(),itms.end(),"b1")!=itms.end())||(std::find(itms.begin(),itms.end(),"b2")!=itms.end())||(std::find(itms.begin(),itms.end(),"b7")!=itms.end())||(std::find(itms.begin(),itms.end(),"b8")!=itms.end())){
               total=8;
          }
     }
     if((std::find(itms.begin(),itms.end(),"e2")!=itms.end())&&(std::find(itms.begin(),itms.end(),"s2")!=itms.end())){
          if((std::find(itms.begin(),itms.end(),"b7")!=itms.end())||(std::find(itms.begin(),itms.end(),"b8")!=itms.end())){
               total=7;
          }
     }
     if(std::find(itms.begin(),itms.end(),"e3")!=itms.end()){
          if((std::find(itms.begin(),itms.end(),"b3")!=itms.end())||(std::find(itms.begin(),itms.end(),"b4")!=itms.end()
)||(std::find(itms.begin(),itms.end(),"b5")!=itms.end())||(std::find(itms.begin(),itms.end(),"b6")!=itms.end())){
               total=13;
          }
     }
     if(!total){
          for(int i=0; i<itms.size(); i++){
               std::string si=itms[i].substr(0,1);
               int ino=std::stoi(itms[i].substr(1,1))-1;
               if(si=="e"){total+=e[ino];}
               if(si=="s"){total+=s[ino];}
               if(si=="b"){total+=b[ino];}
          }
     }
     std::printf("Your total is $%i\n",total);
}
