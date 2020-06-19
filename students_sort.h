#ifndef STUDENTS_RATING_STUDENTS_SORT_H
#define STUDENTS_RATING_STUDENTS_SORT_H

#include "criteria.h"
#include "vector"
#include <algorithm>

using std::vector;

vector<Criteria> students_sort(
        vector<Criteria> students,
            vector<bool> crit, vector<string> sort_crit);

#endif //STUDENTS_RATING_STUDENTS_SORT_H
