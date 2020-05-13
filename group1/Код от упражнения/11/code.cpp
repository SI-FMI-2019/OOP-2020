#include <iostream>
#include <vector>
#include <string>

//SVG - rectangle, circle, line
// Rectangle - (x,y), (width, height), color
// Circle - (x,y), radius, color
// Line - (x1, y1), (x2, y2), color

// SVG - holds the shapes
// Ще използваме STL

class Shape{
public:
    Shape(): center_point({0, 0}), color("#000000") {}
    Shape(const std::pair<int, int>& points, const std::string& set_color): center_point(points), color(set_color) {}
    Shape(const int& x, const int& y, const std::string& set_color): center_point({x, y}), color(set_color) {}

    void set_color(const std::string& new_color)
    {
        this->color = new_color;
    }

    void set_points(const int& x, const int& y)
    {

        //Вариант 1
        //this->center_point = {x, y};

        //Вариант 2
        std::pair<int, int> temp(x, y);
        this->center_point = temp;

        //Вариант 3;
        //std::pair<int, int> temp;
        //temp.first = x;
        //temp.second = y;
        //this->center_point = temp;
    }

    std::string get_color() const
    {
        return this->color;
    }

    std::pair<int, int> get_point() const
    {
        return this->center_point;
    }
    virtual void print() = 0;

protected:
    std::pair<int, int> center_point; //По-добре да е клас Point
    std::string color;
};

class Rectangle: public Shape{
public:
    Rectangle(): Shape(), width(0), height(0) {}
    Rectangle(const int& x, const int& y, const std::string& set_color,
            const int& set_width, const int& set_height):
            Shape(x, y, set_color), width(set_width), height(set_height) {}

    void set_width(const int& width)
    {
        this->width = width;
    }

    void set_height(const int& height)
    {
        this->height = height;
    }

    void print() override
    {
        std::cout << "Shape: Rectangle" << std::endl;
        std::cout << "\tCenter point: (" << this->Shape::center_point.first
            << "," << this->Shape::center_point.second << ")" << std::endl;
        std::cout << "\tColor: " << this->Shape::color << std::endl;
        std::cout << "\tWidth: " << this->width << std::endl;
        std::cout << "\tHeight: " << this->height << std::endl;
    }
    int get_width() const
    {
        return this->width;
    }

    int get_height() const
    {
        return this->height;
    }
private:
    int width;
    int height;
};

class Circle: public Shape{
public:
    Circle(): Shape(), radius(0) {}
    Circle(const int& x, const int& y, const std::string& set_color, const int& radius): Shape(x, y, set_color), radius(radius){}

    void set_radius(const int& radius)
    {
        this->radius = radius;
    }

    void print() override
    {
        std::cout << "Shape: Rectangle" << std::endl;
        std::cout << "\tCenter point: (" << this->Shape::center_point.first
                  << "," << this->Shape::center_point.second << ")" << std::endl;
        std::cout << "\tColor: " << this->Shape::color << std::endl;
        std::cout << "\tRadius: " << this->radius << std::endl;
    }
    int get_radius() const
    {
        return this->radius;
    }
private:
    int radius;
};

class Line: public Shape{
public:
    Line(): Shape(), second_point({0, 0}) {}
    Line(const int& x, const int& y, const std::string& set_color, const int& second_x, const int& second_y):
    Shape(x, y, set_color), second_point({second_x, second_y}) {}

    void set_second_point(const int& second_x, const int& second_y)
    {
        this->second_point = {second_x, second_y};
    }

    void print() override
    {
        std::cout << "Shape: Rectangle" << std::endl;
        std::cout << "\tCenter point: (" << this->Shape::center_point.first
                  << "," << this->Shape::center_point.second << ")" << std::endl;
        std::cout << "\tColor: " << this->Shape::color << std::endl;
        std::cout << "\tSecond point: (" << this->second_point.first << ","
                  << this->second_point.second << ")" << std::endl;
    }
    std::pair<int, int> get_second_point() const
    {
        return this->second_point;
    }
private:
    std::pair<int, int> second_point;
};

class SVG{
public:
    SVG() = default;

    void add_rectangle(const Rectangle& to_add)
    {
        auto* non_const_rectangle_ptr = const_cast<Rectangle*>(&to_add);
        auto* shape_ptr = dynamic_cast<Shape*>(non_const_rectangle_ptr);
        this->shapes.push_back(shape_ptr);

        //this->shapes.push_back(dynamic_cast<Shape*>(const_cast<Rectangle*>(&to_add)));
    }

    void add_cirlce(const Circle& to_add)
    {
        auto* non_const_rectangle_ptr = const_cast<Circle*>(&to_add);
        auto* shape_ptr = dynamic_cast<Shape*>(non_const_rectangle_ptr);
        this->shapes.push_back(shape_ptr);
    }

    void add_line(const Line& to_add)
    {
        auto* non_const_rectangle_ptr = const_cast<Line*>(&to_add);
        auto* shape_ptr = dynamic_cast<Shape*>(non_const_rectangle_ptr);
        this->shapes.push_back(shape_ptr);
    }

    Shape* operator[](const int& index)
    {
        return this->shapes[index];
    }

    std::vector<Rectangle*> get_all_rectangle() const
    {
        std::vector<Rectangle*> result;

        for(Shape* shape: this->shapes)
        {
            auto* shape_as_rectangle = dynamic_cast<Rectangle*>(shape);
            if(shape_as_rectangle != nullptr)
            {
                result.push_back(shape_as_rectangle);
            }
        }
        return result;
    }
private:
    std::vector<Shape*> shapes;
};

int main(){
    return 0;
}