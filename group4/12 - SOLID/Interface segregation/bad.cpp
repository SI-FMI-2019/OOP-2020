#include <iostream>
#include <vector>
#include <string>

using namespace std;

class JSONObject {
   public:
    string key;
    string value;

    virtual JSONObject* clone() const {
        return new JSONObject(*this);
    }
};

// Inherit JSONObject to have a vector of JSONObject*
// ^ Bad idea because JSONArray is polluted with the JSONObject properties and
// methods, when it doesn't use or need them
class JSONArray : private JSONObject {
   public:
    vector<JSONObject*> objects;

    virtual JSONObject* clone() const override {
        return new JSONArray(*this);
    }

    // Assume the logic for polymorphism works as intended
};
