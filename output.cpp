#include "output.h"

using std::cout;
using std::setprecision;


void table(vector<Criteria> students, vector<bool> _crit) {
  cout << "Name" << "\t";

  if (_crit[0])
      cout << "\t""Attendance";
  if (_crit[1])
      cout << "\t" << "Pluses";
  if (_crit[2])
      cout<< "\t" << "Marks";
  if (_crit[3])
      cout << "\t" << "Average" ;

  cout << "\n\n";

  cout << setprecision(2);

  for (const auto& i: students) {
      cout << i.names << "\t\t";

      if (i.attendance)
        cout << i.attendance << "\t";
      if (i.pluses)
        cout << i.pluses << "\t";
      if (i.marks)
        cout << i.marks << "\t";
      if (i.average)
        cout << i.average << '\n';
  }
}

void brackets(vector<Criteria> students) {

  cout << setprecision(2);
    for (const auto& i: students) {
      cout << i.names << ": (";

      if (i.attendance)
        cout << "attendance: " << i.attendance << ", ";
      if (i.pluses)
        cout << "pluses: " << i.pluses << ", ";
      if (i.marks)
        cout << "marks: " << i.marks << ", ";
      if (i.average)
        cout << "average: " << i.average;

      cout << ") \n";
  }
}
