#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

class IntContainer {
   public:
    virtual void add(int newInt) = 0;
    virtual int at(size_t index) const = 0;
    virtual IntContainer* clone() const = 0;
    virtual ~IntContainer() {}
};

class UnorderedIntContainer : public IntContainer {
    vector<int> data;

   public:
    void add(int newInt) {
        data.push_back(newInt);
    }
    int at(size_t index) const {
        return data.at(index);
    }
    IntContainer* clone() const {
        return new UnorderedIntContainer(*this);
    }
};

class OrderedIntContainer : public IntContainer {
    set<int> data;

   public:
    void add(int newInt) {
        data.insert(newInt);
    }
    int at(size_t index) const {
        auto iterator = data.begin();
        advance(iterator, index);
        return *iterator;
    }
    IntContainer* clone() const {
        return new OrderedIntContainer(*this);
    }
};

class Grades {
    IntContainer* my_grades;

   public:
    Grades(IntContainer* new_grades) : my_grades(new_grades->clone()) {}

    int getGradeByIndex(size_t index) {
        return my_grades->at(index);
    }

    // Assume the copy,operator= and destructor are implemented properly
};

int main() {
    IntContainer* unordered_ints = new UnorderedIntContainer();
    unordered_ints->add(2);
    unordered_ints->add(3);
    unordered_ints->add(1);
    Grades myUnorderedGrades(unordered_ints);
    std::cout << "Unordered int at position 0 is " << myUnorderedGrades.getGradeByIndex(0) << "\n";

    IntContainer* ordered_ints = new OrderedIntContainer();
    ordered_ints->add(2);
    ordered_ints->add(3);
    ordered_ints->add(1);
    Grades myOrderedGrades(ordered_ints);
    std::cout << "Ordered int at position 0 is " << myOrderedGrades.getGradeByIndex(0) << "\n";
}
