#pragma once

#include <QString>
#include <QStringList>
#include <string>

#include "criteria.h"
#include "all_rating.h"

#include "attendance.h"
#include "pluses.h"
#include "marks.h"

using std::string;
using std::vector;

vector<bool> criteria_parsing (QString criteria);
vector<string> sort_parsing(QString sort, vector<bool> crit);

static vector<string> names = AllRating::get_names();
static auto n = names.size();

vector<Criteria> get_data(vector<bool> _crit, const string& course);

