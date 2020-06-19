#include "crit_lib.h"

struct Attendance {
    vector<double> get_crit(string course) {

        string path = "/home/pavel/.students-rating/";
        path.append(course);

        std::ifstream ifs(path);
        json j;
        ifs >> j;
        j = j["progress"];

        vector<double> students;

        for (auto& item : j.items()) {

            double att = 0;
            int lessons = 0;

            string _field = item.key(); // problems convert in double

        for (auto& it : item.value()) {
            if (it["attendance"] == true) {
                att++;
              }
            lessons++;
          }

        if (lessons) {
            att /= lessons;
          } else {
            att = 0;
          }
        students.push_back(att);
      }
    return students;
  }
};
