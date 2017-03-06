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
     int stdidx=std::stoi(argv[2]);
     if((stdidx<=roster.size())&&(stdidx>=0)){
          printf("Student Score: %f%%\n",roster[stdidx].score);
     }else{
          printf("Index out of range\n");
     }
}
