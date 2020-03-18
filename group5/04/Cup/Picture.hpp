#ifndef PICTURE_HPP
#define PICTURE_HPP

class Picture
{
public:
    /* ============ Big Four ========== */
    Picture();
    Picture(const Picture&);
    Picture& operator=(const Picture&);
    ~Picture();
    /* ================================ */
    Picture(const char*, const unsigned, const unsigned);

    void printInfo() const;
private:
    char* name;
    unsigned heigth;
    unsigned width;
};

#endif