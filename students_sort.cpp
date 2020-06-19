#include "students_sort.h"

vector<Criteria> students_sort(
        vector<Criteria> students,
            vector<bool> crit, vector<string> sort_crit) {

    if (crit[0]) {
        if (sort_crit[0] == "asc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.pluses < right.pluses;
                      });
        } else if (sort_crit[0] == "desc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.pluses > right.pluses;
                      });
        }
    }

    if (crit[1]) {
        if (sort_crit[1] == "asc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.attendance < right.attendance;
                      });
        } else if (sort_crit[1] == "desc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.attendance > right.attendance;
                      });
        }
    }

    if (crit[2]) {
        if (sort_crit[2] == "asc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.marks < right.marks;
                      });
        } else if (sort_crit[2] == "desc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.marks > right.marks;
                      });
        }
    }

    if (crit[3]) {
        if (sort_crit[3] == "asc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.average < right.average;
                      });
        } else if (sort_crit[3] == "desc") {
            std::sort(students.begin(), students.end(),
                      [](Criteria &left, Criteria &right) {
                          return left.average > right.average;
                      });
        }
    }
    return students;
}