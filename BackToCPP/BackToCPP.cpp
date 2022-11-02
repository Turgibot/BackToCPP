/*
  Why use const
		a.) Guard against inadvertent write to the variable.
		b.) Self documenting
		c.) Enable compiler to do more optimiztion, making code tighter.
		d.) const usually means the variable is put in ROM.
*/

#include <iostream>
using namespace std;

constexpr int a() {
	return 8;
}


int main()
{
	const int i = 1;
	//i = 4; //impossible i is const at compile time
	int x = 4;
	// const and pointers
	// it all depends where the const is located in reference to the type:
	//1. before the type - this means that the value of the referenced variable cant be changed.
	const int* ptr = &x;
	//*ptr = 2; 
	ptr = &i; //the pointer itself can be reassigned

	//2. in the middle - after the type same thing as 1

	int const* ptr2 = &x; // data is const - pointer is not
	//*ptr2 = 3;

	int* const ptr1 = &x; // now pointer is const - data is not
	//ptr1 = &i;

	// summary - it all referes to where the const is in reference to the *
	// If const is on the left  of *, data is const
	// If const is on the right of *, pointer is const

	int j = 4;
	//now these two are the same and mean that the value cannot be changed using the pointer
	const int* ptr3 = &j;
	int const* ptr4 = &j;
	//*ptr3 = 4;

	// when the const is after the * than the pointer itself is const

	int* const ptr5 = &x; // must be initialized
	//ptr5 = &j; 

	//now both:

	const int* const both_ptr = &x;
	//or
	int const* const both_ptr2 = &x;

	// we can remove the const referece to a value and still change it with a const pointer using const_cast
	int k = 4;
	const int* ptr_k = &k;
	cout << "old value is :" << *ptr_k << endl;
	// force changing the value using const_cast
	*(const_cast<int*>(ptr_k)) = 99;
	cout << "new value is :" << *ptr_k << endl;

	// we can also add constantness

	int l = 400;

	(static_cast<const int&>(l));
	

	const int y = 8;
	int arr[a()];



}
