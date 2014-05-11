#include <ruby.h>

// Allocate a variable for the factorial module. Ruby values are all of type VALUE. Qnil is the C representation of Ruby's nil.
// The Ruby module where the fast_fibonacci will reside is called egotistically MyMath
VALUE MyMath = Qnil;
// This is the module that will be responsible for fast computation of Fibonacci sequence
VALUE FastFibonacci = Qnil;
// This is run when the file is loaded and performa initialization
void Init_mymath_fast_fibonacci();
// Functions that operate on Ruby values all take and return VALUE as parameters
// Compute the fibonacci sequence up to fibonacci_to_compute, this binds the ruby method and types to C function and types
VALUE method_fast_fibonacci(VALUE self, VALUE fibonacci_to_compute);
// The C recursive method that will compute the fibonacci_number in location fibonacci_to_compute, i.e. get me the fibonacci_to_compute's sequence in the series
unsigned long fast_fibonacci(unsigned long fibonacci_to_compute);
// rb_define_module() defines a ruby module
// rb_define_module_under() creates a module under one that is provided, this is your namespacing way to go about these things
// rb_define_singleton_method(), well guess what it does, it binds a c method to a module and a method, this effectively exposes the C function a method on the module, the last parameter is the method's arity, which for us is just 1
void Init_mymath_fast_fibonacci(){
	// Defines a Ruby module MyMath
	MyMath = rb_define_module("MyMath");
	// Defines a module within MyMath::FastFibonacci
	FastFibonacci = rb_define_module_under(MyMath, "FastFibonacci");
	// Defines a method in FastFibonacci called compute, use as MyMath::FastFibonacci.compute(number_in_sequence)
	rb_define_singleton_method(FastFibonacci, "compute", method_fast_fibonacci, 1);
}
// Pass through function that will cast the parameters from their C types to Ruby
VALUE method_fast_fibonacci(VALUE self, VALUE fibonacci_to_compute){
	// Without converting to C int type the results here are very strange, the casting will attempt to do something but it CAN NOT be trusted
      	// For example in the below printout implicitly casting a Ruby value into an unsigned long C type
	// The result when fibonacci_to_compute is 1 the prinf statement will print 3
	//printf("Input to %s %lu\n", self, fibonacci_to_compute); 

	// Cast to C INT and call the recursive Fibonacci function
	unsigned long computed = fast_fibonacci(NUM2INT(fibonacci_to_compute));
	// Same when converting back the C type to Ruby number, always do it explicitly
	return INT2NUM(computed);
}

// Standard recursive function to compute a fibonacci number 
unsigned long fast_fibonacci(unsigned long fibonacci_to_compute){
	//printf("%lu\n", fibonacci_to_compute);
	if(fibonacci_to_compute == 0){
		return 0;
	}
	else if (fibonacci_to_compute == 1){
		return 1;
	}
	else{
		return (fast_fibonacci(fibonacci_to_compute-1) + fast_fibonacci(fibonacci_to_compute-2));
	}
}

  


