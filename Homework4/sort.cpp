#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<algorithm>

class StudentRecord{
     public:
     std::string first_name, last_name;
     float score;
     bool operator<(const StudentRecord& rec)const{
          return this->score<rec.score;
     }
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
     std::sort(roster.begin(),roster.end());
     std::ofstream ofile;
     ofile.open("sorted.txt");
     for(int i=0;i<roster.size();i++){
          ofile << roster[i].last_name << "," << roster[i].first_name << "," << roster[i].score << std::endl;
     }
     ofile.close();
}
