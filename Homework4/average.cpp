#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<stdio.h>

class StudentRecord{
     public:
     std::string first_name, last_name;
     float score;
};

float calculate_average(std::vector<StudentRecord> *rost){
     float sum=0;
     int NoStds=(*rost).size();
     for(int i=0; i<NoStds; i++){
          sum+=(*rost)[i].score;
     }
     return sum/NoStds;
}

int main(int argc, char* argv[]){
     std::vector<StudentRecord> roster;
     std::ifstream infile(argv[1]);
     std::string ln;
     while(std::getline(infile, ln)){
          StudentRecord rec;
          std::string sval;
          std::istringstream stringstream(ln);
          std::getline(stringstream, sval, ',');
          rec.last_name=sval;
          std::getline(stringstream, sval, ',');
          rec.first_name=sval;
          std::getline(stringstream, sval, ',');
          rec.score=std::stof(sval);
          roster.push_back(rec);
     }
     float avg=calculate_average(&roster);
     printf("Student Average: %f%%\n",avg);
}
