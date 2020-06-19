#include "allrating.h"
#include "json.hpp"
#include "criteria.h"

#include <iostream>
#include <fstream>
#include <vector>

#include <QCommandLineParser>
#include <error.h>

using json = nlohmann::json;
using detail = nlohmann::detail::value_t; // short name for null in json

using std::cout;
using std::string;
using std::vector;

vector<pair<int, string>> AllRating::get_names() {
 std::ifstream ifs(location + "/test.json");
 json j;
 ifs >> j;
 ifs.close();

 vector<pair<int, string>> names;
 pair<int, string> name;

 j = j["students"];

 for (auto& item : j.items()) {
     name.first = item.value()["id"];
     name.second = item.value()["name"];
     names.push_back(name);
   }
 return names;
}






template <class Operation>
struct Client: public Operation
{
  void useStrategy()
  {
    this->get_crit();
  }
};

vector<Criteria> AllRating::average() {

  std::ifstream ifs(location + "/attendance.json");
  json j;
  ifs >> j;

 vector<Criteria> students;

 j = j["progress"];

 Criteria crit;

 for (auto& item : j.items()) {
     crit.attendance = 0;
     crit.pluses = 0;
     crit.marks = 0;
     for (auto& it : item.value()) {
         if (it["attendance"] == true) {
             crit.attendance++;
           }
         if (it["plus"] == true) {
             crit.pluses++;
           }
         if (it["test"] != detail::null) { // null in json file
             auto _field = static_cast<double>(it["test"]); // problems convert in double
             crit.marks += _field;
           }
       }
//      if (!crit.attendance)
//        crit.marks /= crit.attendance;

     students.push_back(crit);
   }
 return students;
}

//const std::string& select_alphabet(const QCommandLineParser& parser) {
//    auto medium_set = parser.isSet("medium");
//    auto strong_set = parser.isSet("strong");
//    auto simple_set = parser.isSet("simple");

//    if ((simple_set && (strong_set || medium_set || (medium_set && strong_set))) || (strong_set && medium_set))
//        error("You cannot specify more than one complexity level. Choose one of: --simple, --medium or --strong");

//    if (medium_set)
//        return "alphabet_medium";
//    else if (strong_set)
//        return "alphabet_strong";
//    else
//        return "alphabet_simple";
//}
