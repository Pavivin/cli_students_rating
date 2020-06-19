#include "all_rating.h"

vector<string> AllRating::get_names() {

 std::ifstream ifs("/home/pavel/.students-rating/test.json");
 json j;
 ifs >> j;
 ifs.close();

 vector<string> students;
 string name;

 j = j["students"];
    for (auto &item : j.items()) {
        int _id = item.value()["id"];
        string str_id = std::to_string(_id);
        name = item.value()["name"];
        students.push_back(name);
}
 return students;
}