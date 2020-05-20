#include <iostream>
#include <string>
#include <vector>

using namespace std;

class JSONBase {
    virtual JSONBase* clone() const = 0;
};

class JSONObject : public JSONBase {
   public:
    string key;
    string value;

    virtual JSONBase* clone() const override {
        return new JSONObject(*this);
    }
};

class JSONArray : public JSONBase {
   public:
    vector<JSONBase*> objects;

    virtual JSONBase* clone() const override {
        return new JSONArray(*this);
    }

    // Assume the logic for polymorphism works as intended
};
