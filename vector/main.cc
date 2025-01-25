#include <iostream>
#include <vector>

// this class is used to demonstrate the behavior of std::vector
class A {
public:
  // Default constructor
  A(int data = 0) : data_(data) { std::cout << "A::A()\n"; }
  // Copy constructor
  A(const A &a) : data_(a.data_) { std::cout << "A::A(const A&)\n"; }
  // Copy assignment operator
  A &operator=(const A &a) {
    data_ = a.data_;
    std::cout << "A::operator=(const A&)\n";
    return *this;
  }
  // Move constructor
  A(A &&a) : data_(std::move(a.data_)) { std::cout << "A::A(A&&)\n"; }
  // Destructor
  ~A() { std::cout << "A::~A()\n"; }

private:
  int data_;
};

// this function demonstrates the behavior of std::vector
// when adding elements to it using push_back and emplace_back
int main() {
  int n = 3;
  // push_back is used to add an element to the end of the vector
  // not efficient because it creates a temporary object
  // and then copies it to the vector
  {
    std::cout << "> push_back\n" << std::endl;
    std::vector<A> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(A(i));
    }
  }

  // emplace_back is used to add an element to the end of the vector
  // efficient because it constructs the object in place
  {
    std::cout << "\n> emplace_back\n" << std::endl;
    std::vector<A> v;
    for (int i = 0; i < n; ++i) {
      v.emplace_back(i);
    }
  }

  // if the size of the vector is known, the best way to add elements to a
  // vector is to reserve the memory and then use emplace_back
  {
    std::cout << "\n> reserve + emplace_back\n" << std::endl;
    std::vector<A> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
      v.emplace_back(i);
    }
  }

  // initialize a vector with a given size will create temporary objects
  {
    std::cout << "\n> initialize with size\n" << std::endl;
    std::vector<A> v(n);
  }

  // initalization list also creates temporary objects
  {
    std::cout << "\n> initialize with list\n" << std::endl;
    std::vector<A> v{A(0), A(1), A(2)};
  }
  return 0;
}
