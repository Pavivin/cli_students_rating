#include "strategy.h"
#include <iostream>

vector<bool> criteria_parsing (QString criteria) {
    QStringList list = criteria.split(',');

    vector<bool> crit (4);

    for(auto i: crit) {
        i = false;
    }
    bool is_average = true;

    for (auto i: list) {
        if (i == "attendance") {
            crit[0] = true;
            is_average = false;
        }
        if (i == "plus") {
            crit[1] = true;
            is_average = false;
        }
        if (i == "test") {
            crit[2] = true;
            is_average = false;
        }
    }
    if (is_average)
        for(auto i: crit) {
            i = true;
        }

    return crit;
}

vector<string> sort_parsing(QString sort, vector<bool> crit) {
    vector<string> sort_crit(4);
    QRegExp rx("[,=]"); //
    QStringList sort_list = sort.split(rx);

    bool is_average = crit[3];

    if (is_average) {
        sort_crit[3] = "desc";
    } else {
        if (sort_list.empty()) { // если не выбран параметр sort - ставится desc
            for (unsigned i = 0; i < crit.size(); i++)
                if (crit[i])
                    sort_crit[i] = "desc";
        } else {
            for (int i = 0; i < sort_list.size() - 1; i++) { // += 2

                string curr = sort_list.at(i).toStdString();
                string next = sort_list.at(i + 1).toStdString();

                if (curr == "attendance") {
                    sort_crit[0] = next;
                }
                if (curr == "plus") {
                    sort_crit[1] = next;
                }
                if (curr == "test") {
                    sort_crit[2] = next;
                }
                if (curr == "average") {
                    sort_crit[3] = next;
                }
            }
        }
    }

    return sort_crit;
}


vector<Criteria> get_data(vector<bool> _crit, const string& course) {
    vector<Criteria> students;
    vector<double> pluses, attendance, marks;

    if (_crit[0]) {
        Client<Attendance> firstCrit;
        attendance = firstCrit.useStrategy(course);
    }

    if (_crit[1]) {
        Client<Pluses> secondCrit;
        pluses = secondCrit.useStrategy(course);
    }

    if (_crit[2]) {
        Client<Marks> thirdCrit;
        marks = thirdCrit.useStrategy(course);
    }

    for (unsigned i = 0; i < n; i++) {
        Criteria crit;
        crit.names = names[i];

        if (_crit[0]) {
            crit.pluses = pluses[i];
        }
        if (_crit[1]) {
            crit.attendance = attendance[i];
        }
        if (_crit[2]) {
            crit.marks = marks[i];
        }
        if (_crit[3]) {
            crit.average = (pluses[i] + attendance[i] + marks[i]) / 3;
        }
        
        students.push_back(crit);
    }
    return students;
}

void data_output() {

}