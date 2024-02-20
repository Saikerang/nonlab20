#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &name ,vector<int> &score, vector<char> &grades){
ifstream dest(filename);
string line;
int s1,s2,s3,total = 0;
char grade,student[100];
char format[] = "%[^:]: %d %d %d";
while(getline(dest,line))
{
    sscanf(line.c_str(), format, &student, &s1 ,&s2 ,&s3);
    name.push_back(student);
    total = s1 + s2 + s3;
    grade = score2grade(total);
    score.push_back(total);
    grades.push_back(grade);
    
}

}

void getCommand(string &command, string &key){
string temp;
char format[] = "%s %[^:]s";
char text1[10],text2[100];
cout << "Please input your command: ";
getline(cin,temp);
sscanf(temp.c_str(), format,&text1,text2);
command = text1;
key = text2;



}

void searchName(const vector<string> name, const vector<int> score,const vector<char> grades,string key){
    int j = 0;
    cout << "---------------------------------" << endl;
    for (unsigned int i=0 ; i < name.size() ; i++)
    {
        string temp = name.at(i);
        temp = toUpperStr(temp);
        if (key == temp)
        {
            cout << name.at(i) << "'s score = " << score.at(i) << endl;
            cout << name.at(i) << "'s grade = " << grades.at(i) << endl;
            j++;
        }
    }
    if (j == 0) cout << "Cannot found." << endl;
    cout << "---------------------------------" << endl;




}

void searchGrade(const vector<string> names,const vector<int> scores,const vector<char> grades, string key){
    int j = 0;
    
    cout << "---------------------------------" << endl;
    for (unsigned int i = 0; i < grades.size(); i++)
    {
        if (*key.c_str() == grades[i])
        {
            cout << names.at(i) << " (" << scores.at(i) << ")" << endl;
            j++;
        }
    }
    if (j == 0) cout << "Cannot found." << endl;
    cout << "---------------------------------" << endl;
}




int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;  
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}