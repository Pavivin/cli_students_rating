#ifndef RATING_H
#define RATING_H

#include <string>
#include <vector>

#include "criteria.h"
#include <QCommandLineParser>

using std::string;
using std::vector;

class AllRating
{
public:
  string location = "/home/pavel/OS/os-asmt-students-rating-Pavivin/students-rating/";

  vector<pair<int, string>> get_names();

  vector<double> get_crit(string crit);
  vector<double> get_marks();

  vector<Criteria> average();

  const std::string& select_alphabet(const QCommandLineParser& parser);
};

#endif // RATING_H
