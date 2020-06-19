#include "arg_parser.h"
#include "strategy.h"
#include "output.h"

#include "criteria.h"
#include "students_sort.h"

#include <iostream>
#include <QCoreApplication>

using std::string;
using std::cout;

int main(int argc, char** argv) {

  try {

    auto parser = parse_args(QCoreApplication(argc, argv));

    auto sort = parser->value("sort");
    auto criteria = parser->value("criteria");
    auto course = parser->value("course").toStdString();

    bool isTable = parser->isSet("table");

    vector<bool> parse_crit = criteria_parsing(criteria);
    if (parser->isSet("course"))
        course = "пми-22.json";
    vector<string> parse_sort = sort_parsing(sort, parse_crit);

    auto students = get_data(parse_crit, course);
    students = students_sort(students, parse_crit, parse_sort);

    if (isTable) {
        table(students, parse_crit);
    } else {
        brackets(students);
    }

  }
  catch (const std::exception& ex) {
    std::cout << "ERROR: " << ex.what() << std::endl;
  }
}























//struct Output {
//  vector<double>  att;
//  vector<double> plus;
//  vector<double>  mark;
//  vector<pair<int, string>> name;
//};





//  vector<pair<int, string>> name;
//  name = rating.get_names();

//  for (auto i: name) {
//      cout << i.second;
//    }


// vector<Criteria> students;


//  cout << "Name" << "\t\t"<< "Attendance" << "\t\t" << "Pluses" << "\t\t" << "Marks" << "\n\n";
//  for (auto i: students) {
//      cout << i.name.second << ' ';
//      cout << '\t' << i.attendance;
//      cout << '\t' << i.pluses;
//      cout << '\t' << i.marks << '\n';
//  }

//for (auto i: students) {
//    cout << i.name.second << ' ';
//    cout << " " << "(attendance: " << i.attendance;
//    cout << ", " << "pluses: "     << i.pluses;
//    cout << ", " << "marks: "      << i.marks      << ')' <<'\n';
//}




//  vector<int> students_att;
//  students_att = rating.get_attendance();

//  for (auto i: students_att) {
//      cout << "attendance: " << i << '\n';
//  }


//  vector<int> students_pluses = rating.get_pluses();

//  for (auto i: students_att) {
//      cout << "plus: " << i << '\n';
//  }

//  vector<double> students_marks = rating.get_marks();

//  for (auto i: students_marks) {
//      cout << "marks: " << i << '\n';
//  }



//#include <sys/types.h>
//#include <dirent.h>
//#include<iostream>
//#include<stdio.h>


//int main(void)
//{
//    DIR *dir = opendir(".");
//    if(dir)
//    {
//        struct dirent *ent;
//        while((ent = readdir(dir)) != NULL)
//        {
//            puts(ent->d_name);
//        }
//    }
//    else
//    {
//        fprintf(stderr, "Error opening directory\n");
//    }
//    return 0;
//}
