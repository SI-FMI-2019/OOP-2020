#include "Cup.hpp"
#include "Picture.hpp"
#include <iostream>

Cup modifyCup(Cup& cup)
{
    cup.fill(125);
    return cup;
}

int main()
{
    // Cup cup;
    // cup.fill(125);
    // cup = modifyCup(cup);
    // cup = static_cast<Cup>(cup);
    // Cup cup2(0, 250, WHITE);

    Picture pic1;
    Picture pic2("Mona Lisa", 250, 320);
    Picture pic3;

    pic3 = pic1 = pic2;

    pic1.printInfo();
    pic2.printInfo();
    pic3.printInfo();

    return 0;
}