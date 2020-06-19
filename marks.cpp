#include "crit_lib.h"
using detail = nlohmann::detail::value_t; // short name for null in json

struct Marks {
  vector<double> get_crit() {

    string location = "/home/pavel/OS/os-asmt-students-rating-Pavivin/students-rating/";

        std::ifstream ifs(location + "/attendance.json");
    json j;
    ifs >> j;

    vector<double> students;

    j = j["progress"];

    for (auto& item : j.items()) {

        double mark = 0;
        int lessons = 0;

        for (auto& it : item.value()) {
            if (it["test"] != detail::null) { // null in json file
                auto _field = static_cast<double>(it["test"]); // problems convert in double
                mark += _field;
                lessons++;
              }
          }

        if (lessons)
          mark /= lessons;
        else
          mark = 0;


        students.push_back(mark);
      }
    return students;
  }
};
