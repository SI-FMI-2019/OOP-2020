#include <iostream>
#include "JSON.hpp"
#include "JSONObject.hpp"
#include "JSONArray.hpp"

int main()
{
    JSONObject<int>* first = new JSONObject<int>;
    first->setKey("month");
    first->setValue(6);

    JSONObject<int>* second = new JSONObject<int>;
    second->setKey("year");
    second->setValue(2020);

    JSONArray<int>* jsonArray = new JSONArray<int>;
    jsonArray->insert(first);
    jsonArray->insert(second);
    jsonArray->insert("day", 3);
    jsonArray->insert(jsonArray);

    std::cout << jsonArray->getValue("day") << std::endl;
    return 0;
}