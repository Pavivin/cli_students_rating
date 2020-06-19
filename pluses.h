#include "crit_lib.h"

struct Pluses {
    vector<double> get_crit(string course) {

        string path = "/home/pavel/.students-rating/";
        path.append(course);

        std::ifstream ifs(path);
        json j;
        ifs >> j;
        j = j["progress"];

        vector<double> students;

        for (auto& item : j.items()) {
            double plus = 0;
            int lessons = 0;

        for (auto& it : item.value()) {
            if (it["plus"] == true) {
                plus++;
              }
            lessons++;
          }

        if (lessons) { // division by zero
            plus /= lessons;
          } else {
            plus = 0;
          }
        students.push_back(plus);
      }
    return students;
  }
};
