#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

class StudentRecord{
     public:
     std::string first_name, last_name;
     float score1, score2, score3;
     virtual float stdavg(void) =0;
};

class StudentRecordPhysics:public StudentRecord{
     public:
     float stdavg(void){
          return 0.8*score1+0.2*score2;
     }
};

class StudentRecordHistory:public StudentRecord{
     public:
     float stdavg(void){
          float hg=score1;
          float lg=score2;
          if(score1<score2){
               hg=score2;
               lg=score1;
          }
          return 0.6*hg+0.4*lg;
     }
};

class StudentRecordLiterature:public StudentRecord{
     public:
     float stdavg(void){
          return 0.4*score1+0.4*score2+0.2*score3;
     }
};

float calculate_average(std::vector<StudentRecord*> *rost){
     float sum=0;
     int NoStds=(*rost).size();
     for(int i=0; i<NoStds; i++){
          sum+=(*rost)[i]->stdavg();
     }
     return sum/NoStds;
}

int main(int argc, char* argv[]){
     std::vector<StudentRecord*> roster;
     std::vector<StudentRecord*> PhyRos;
     std::vector<StudentRecord*> HisRos;
     std::vector<StudentRecord*> LitRos;
     std::ifstream infile(argv[1]);
     std::string ln;
     while(std::getline(infile, ln)){
          StudentRecord* rec;
          std::string sval;
          std::istringstream stringstream(ln);
          std::getline(stringstream, sval, ',');
          if(sval=="Physics"){
               rec=new StudentRecordPhysics;
               PhyRos.push_back(rec);
          }
          if(sval=="History"){
               rec=new StudentRecordHistory;
               HisRos.push_back(rec);
          }
          if(sval=="Literature"){
               rec=new StudentRecordLiterature;
               LitRos.push_back(rec);
          }
          std::getline(stringstream, sval, ',');
          rec->last_name=sval;
          std::getline(stringstream, sval, ',');
          rec->first_name=sval;
          std::getline(stringstream, sval, ',');
          rec->score1=std::stof(sval);
          std::getline(stringstream, sval, ',');
          rec->score2=std::stof(sval);
          std::getline(stringstream, sval, ',');
          if(sval!=""){rec->score3=std::stof(sval);}
          roster.push_back(rec);
          std::cout <<rec->last_name<<","<<rec->first_name<<" -- Final Grade: "<<rec->stdavg()<<"%"<<std::endl;
     }
     std::cout <<"Physics Class Average: "<<calculate_average(&PhyRos)<<"%"<<std::endl;
     std::cout <<"History Class Average: "<<calculate_average(&HisRos)<<"%"<<std::endl;
     std::cout <<"Literature Class Average: "<<calculate_average(&LitRos)<<"%"<<std::endl;
}
