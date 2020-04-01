#pragma once
/**
 * Create a Paragraph which holds one paragraph of text
 * i.e text which has no new lines
 */

#include <iostream>

class Paragraph {
   private:
    int len;
    char* data;

   public:
    Paragraph(const char* data = "");
    Paragraph(const Paragraph& rhs);
    Paragraph& operator=(const Paragraph& rhs);
    ~Paragraph();

    friend std::ostream& operator<<(std::ostream& out, const Paragraph& para);
    friend std::istream& operator>>(std::istream& in, Paragraph& para);
};
