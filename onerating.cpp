#include "onecriteria.h"

OneCriteria::OneCriteria()
{
  unsigned long Rating::student_id(string student_name) {
    std::ifstream ifs(location + "/test.json");
    json j;
    ifs >> j;

    unsigned long i = 1, id;
    //cout << "id: " << id << "\n";
    for (auto a : j) {
        if(j["students"][i]["name"] == student_name) {
            //cout << i << '\n';
            id = i;
          }
        i++;
      }
    return id + 1;
  }

  unsigned long Rating::count_smth(unsigned long id, string thing) {
    std::ifstream ifs(location + "/attendance.json");
    json j;
    ifs >> j;

    unsigned long count_crit = 0;

    string s = std::to_string(id);

    j = j["progress"];


    for (auto& item : j.items()) {
        for (auto& it : item.value()) {
            if (it[thing] == true) {
                count_crit++;
              }
          }
      }
    return count_crit;
  }


  double Rating::count_marks(unsigned long id) {
    std::ifstream ifs(location + "/attendance.json");
    json j;
    ifs >> j;


    double count_marks = 0;

    string s = std::to_string(id);

    for (auto& a : j) {
        //cout << "test: " << a << '\n';
        for (auto& b : a) {
            //cout << "test: " << b << '\n';
          }
      }
    //cout << "count_att: " << count_att << '\n';
    return count_marks;
  }

}
