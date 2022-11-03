/*
  Why use const
		a.) Guard against inadvertent write to the variable.
		b.) Self documenting
		c.) Enable compiler to do more optimiztion, making code tighter.
		d.) const usually means the variable is put in ROM.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;



class B {

public:
	string val;
	B() = default;
	B(const string& val) : val(val) {}
	B(const B& other) {
		if (*this == other) {
			return;
		}
		this->val = other.val;
	}

	bool operator== (const B& other) const {
		return this->val == other.val;
	}

	B& operator= (B&& other) noexcept {
		this->val = other.val;
		return *this;
	}

};

class A {
public:
	A() = default;
	A(B b) {
		cout << "A Created" << endl;
	}
	void print() {
		cout << "ptr" << endl;
	}
	~A() {
		cout << "A Destroyed" << endl;

	}
};

void f(shared_ptr<A> a) {
	a->print();
}
int main()
{
	B b("hello");
	//B v = b; //copy because creation
	//B b2 = string("Bye");
	//b2 = move(v); // assignment operator

	//A a(b);

	 vector<int> v = {1, 2, 3, 4, 5};
   int cnt;

   cnt = count_if(v.begin(), v.end(), [](int x) {x > 10; });

   cout << "There are " << cnt << " numbers are greater that 3." << endl;

	shared_ptr<A> a_ptr(new A(b));
	f(a_ptr);
	

}
