#include "crit_lib.h"

struct Attendance {
  vector<double> get_crit() {

    string location = "/home/pavel/OS/os-asmt-students-rating-Pavivin/students-rating/";

    std::ifstream ifs(location + "/attendance.json");
    json j;
    ifs >> j;
    ifs.close();

    vector<double> students;

    j = j["progress"];


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

    return students;
  }
};
