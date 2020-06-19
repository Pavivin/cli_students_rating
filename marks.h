#include "crit_lib.h"

using detail = nlohmann::detail::value_t; // short name for null in json
using std::pair;

struct Marks {
  vector<double> get_crit(string course) {

      string path = "/home/pavel/.students-rating/";
      path.append(course);

      std::ifstream ifs(path);
      json j;
      ifs >> j;
      j = j["progress"];

      vector<double> students;

      for (auto& item : j.items()) {

          double mark = 0.0;
          int lessons = 0;

          for (auto& it : item.value()) {
              if (it["test"] != detail::null) { // null in json file
                  auto _field = static_cast<double>(it["test"]); // problems convert in double
                  mark += _field;
                  lessons++;
              }
          }

          if (lessons) {
              mark /= 5;
              mark *= lessons;
          }
          else {
              mark = 0;
          }

          students.push_back(mark);
      }
      return students;
  }
};
