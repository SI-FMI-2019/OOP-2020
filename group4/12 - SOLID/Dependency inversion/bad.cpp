#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Grades {
    vector<int> my_grades;
   public:
    Grades(vector<int> new_grades) : my_grades(new_grades) {}
    // ^ Works but is not easily extendable

    int getGradeByIndex(size_t index) {
        return my_grades[index];
    }
};

int main() {
    vector<int> ints;
    ints.push_back(2);
    ints.push_back(3);
    ints.push_back(1);

    Grades myGrades(ints);
    std::cout << "My grade at position 0 is " << myGrades.getGradeByIndex(0) << "\n";
}
