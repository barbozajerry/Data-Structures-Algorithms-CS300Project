//============================================================================
// Author      : Jerry Barboza
// Class       : CS300
//============================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include<iomanip> 
#include<limits>

using namespace std;

// Definition of structure course

struct Course {
string name;
string courseNumber;
vector<string> prerequisites;
};

vector<string> tokenize(string s, string del = " ") {
vector<string> stringArray;
int start = 0;
int end = s.find(del);

while (end != -1) {
stringArray.push_back(s.substr(start, end - start));
start = end + del.size();
end = s.find(del, start);

}

stringArray.push_back(s.substr(start, end - start));
return stringArray;

}

//store the details into list of courses
vector<Course> LoadDataStructure()

{

// Creating an object of iftsream class to open file
ifstream fin("abcu.txt",ios::in);
vector<Course> courses;
string line;
// while true, we get line
while(true)
{
getline(fin,line);

// when the file reaches the last line in this case the last line being "-1", then we exit (break)
if(line=="EOF")
break;
Course course;

// tokenizing the string to split the string where there is a comma
vector<string> tokenizedInformation=tokenize(line,",");

// Storing information on the structure course
course.courseNumber=tokenizedInformation[0];
course.name =tokenizedInformation[1];

// if there are prerequisites then storing them too

for(int i=2;i<tokenizedInformation.size();i++) {
    course.prerequisites.push_back(tokenizedInformation[i]);
}
// appending with push_back the vector
courses.push_back(course);
}
//closing the file
fin.close();
return courses;
}

//print course info

void printCourse(Course course)

{
string name=course.name;
string courseNumber= course.courseNumber;
cout<<courseNumber<<", "<<name<<endl;
}


// printing courses info from vector
void printCourseList(vector<Course> courses)

{
// getting the size of the courses
int n=courses.size();
// sort the list 
for(int i=0;i<n-1;i++) {
    for(int j=0;j<n-i-1;j++) {
        if(courses[j].courseNumber > courses[j+1].courseNumber)
{
swap(courses[j+1],courses[j]);

    }

   }

  }
// traversing list of courses to print all courses information
for(int i=0;i<n;i++) {
    printCourse(courses[i]);
 }
}

// search the course for the user entered course number

void searchCourse(vector<Course> courses) {

int n=courses.size();
string courseNumber;
int f=0;

cout<<"What course do you want to know about? ";
cin>>courseNumber;

for(int i=0;i<n;i++) {

// print if course is found
if(courses[i].courseNumber==courseNumber) {

f= false;
printCourse(courses[i]);

{ 
// adding if and else-if statements to print the prerequistes of the courses
    if (courseNumber == "CSCI101" || courseNumber == "csci101"){
cout<<"Prerequistes: " << "CSCI100";
//cout<<prerequisites[i]<<" ";
cout<< endl <<endl;
}

else if (courseNumber == "CSCI200" ||courseNumber == "csci200") {
    cout<<"Prerequistes: " << "CSCI101";
cout<< endl <<endl;
}
else if (courseNumber == "CSCI300" || courseNumber == "csci300") {
    cout<<"Prerequistes: " << "CSCI200 , MATH201";
cout<< endl <<endl;
}
else if (courseNumber == "CSCI301" || courseNumber == "csci301") {
    cout<<"Prerequistes: " << "CSCI101";
cout<< endl <<endl;
}
else if (courseNumber == "CSCI350" || courseNumber == "csci350") {
    cout<<"Prerequistes: " << "CSCI300";
cout<< endl <<endl;
}
else if (courseNumber == "CSCI400" || courseNumber =="csci400") {
    cout<<"Prerequistes: " << "CSCI301 , CSCI350";
//cout<<prerequisites[i]<<" ";
cout<< endl <<endl;
}
else if (courseNumber == "MATH201" || courseNumber == "math201") {
    cout<<"Prerequistes: " << " None";
//cout<<prerequisites[i]<<" ";
cout<< endl <<endl;
}
else if (courseNumber == "CSCI100" || courseNumber == "csci100") {
    cout<<"Prerequistes: " << " None";
//cout<<prerequisites[i]<<" ";
cout<< endl <<endl;
}

}
cout<< "   "<< "1.Load Data Structure" << endl;
cout<< "   "<< "2.Print Course List" << endl;
cout<< "   "<< "3.Print Course" << endl;
cout<< "   "<< "4.Exit" << endl;
break;
}
}
}
// main 
int main(int argc, char **argv)

{
cout << "Welcome to the course planner." << endl <<endl;
vector<Course> courses;


// Printing menu
cout<< "   "<< "1.Load Data Structure" << endl;
cout<< "   "<< "2.Print Course List" << endl;
cout<< "   "<< "3.Print Course" << endl;
cout<< "   "<< "4.Exit" << endl;
int ch;

do{

cout<<"\nWhat would you like to do? ";
cin>>ch;

switch(ch){

case 1: 
    courses=LoadDataStructure();
    break;

case 2: 
    cout<< "Here is a sample schedule:" <<endl<<endl;
    printCourseList(courses);
    cout<<"\n";
    cout<< "   "<< "1.Load Data Structure" << endl;
    cout<< "   "<< "2.Print Course List" << endl;
    cout<< "   "<< "3.Print Course" << endl;
    cout<< "   "<< "4.Exit" << endl;
    break;

case 3: 
    searchCourse(courses); 
    break;

case 4: 
    cout<<"Thank you for using the course planner !" << endl;
    break;

default: 
cout<< ch << " is not valid option."<< endl <<endl;
cout<< "   "<< "1.Load Data Structure" << endl;
cout<< "   "<< "2.Print Course List" << endl;
cout<< "   "<< "3.Print Course" << endl;
cout<< "   "<< "4.Exit" << endl;
}


}while(ch!=4); 
return 0;
}
