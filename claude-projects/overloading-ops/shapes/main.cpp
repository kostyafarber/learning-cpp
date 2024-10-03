#include <iostream>

class Shape {
private:
  static int num_shapes;

public:
  Shape() { num_shapes++; }
  ~Shape() { num_shapes--; }
  static int get_num_shapes() { return num_shapes; }
};

class Rectangle : Shape {
public:
  Rectangle() {}
};

class Circle : Shape {};

int Shape::num_shapes = 0;

using namespace std;

int main() {
  Rectangle r1;

  cout << format("Created one Rectangle that is derived from Shape class\n");
  cout << format("Number of Shapes is now {}\n", Shape::get_num_shapes());

  Shape s1;
  cout << "Created Shape Object\n";

  {
    cout << "Created Circle Object inside a block\n";
    Circle c1;
    cout << format("Number of Shapes is now {}\n", Shape::get_num_shapes());
  }

  cout << "Circle Object should of been destroyed and static shapes "
          "decremented\n";
  cout << format("Number of Shapes is now {}\n", Shape::get_num_shapes());
}