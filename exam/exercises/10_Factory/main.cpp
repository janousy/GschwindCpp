#include <iostream>
#include <list>
using namespace std;

class Shape {
public:
    virtual void show() {cout << "shape" << endl; }
};

class Rectangle : public Shape {
public:
    static Shape *make(const char *shape) {}
    virtual void show() override {cout << "rectangle" << endl; }
};

typedef Shape *makeType(const char *);

class ShapeFactory {
    //Maintain a list of function pointers
    //Cannot use virtual function of shape – would require an object
    static list<makeType *> make_funs; //static cause we dont want to intialize obj. in it
public:
    static void add(makeType *m) { make_funs.push_back(m); }

    static Shape *make(const char *shape) {
        for (makeType *make_fun : make_funs) { //loop over all makefunction until one found
            Shape *s = make_fun(shape);        //that can make the shape
            if (s) return s;
        }
        return NULL;
    }
};

template<class T>
struct ShapeFactoryHelper {
    //we get a function pointer to a make function as input, by default this is equale
    //to the make function of type T, which is then casted to a makeType pointer
    ShapeFactoryHelper(makeType *m = (makeType *) &T::make) {
        ShapeFactory::add(m);
    }
};

static ShapeFactoryHelper<Rectangle> registerRectangle;
//global variable only visible in rectangle

int main() {
    Shape *s1=ShapeFactory::make("R(0,0,3,2)");
    Shape *s2=ShapeFactory::make("C(1.5,1,0.75)");
    s1->show();
    s2->show();
    return 0;
}
