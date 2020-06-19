#include "json.hpp"

#include <iostream>
#include <fstream>
#include <vector>

using json = nlohmann::json;
using detail = nlohmann::detail::value_t; // short name for null in json

using std::cout;
using std::string;
using std::vector;

struct Pluses {
  vector<double> get_crit() {

    string location = "/home/pavel/OS/os-asmt-students-rating-Pavivin/students-rating/";

    std::ifstream ifs(location + "/attendance.json");
    json j;
    ifs >> j;
    ifs.close();

    vector<double> students;

    j = j["plus"];


    for (auto& item : j.items()) {
        double plus = 0;
        int lessons = 0;

        for (auto& it : item.value()) {
            if (it["attendance"] == true) {
                plus++;
              }
            lessons++;
          }

        if (lessons) {
            plus /= lessons;
          } else {
            plus = 0;
          }

        students.push_back(plus);
      }
    // std::sort(students.begin(), students.end(),
    //     [](auto &left, auto &right) {
    //        return left.second < right.second;});

    cout << "AAAAAA";

    return students;
  }
};
