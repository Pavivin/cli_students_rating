#ifndef RATING_H
#define RATING_H

#include <QCommandLineParser>

#include <string>
#include <vector>
#include <fstream>

#include "json.hpp"

using std::string;
using std::vector;
using json = nlohmann::json;

struct AllRating
{
  static vector<string> get_names();
};

template <class Operation>
struct Client: public Operation {
  vector<double> useStrategy(string course) {
      return this -> get_crit(course);
  }
};

#endif // RATING_H
