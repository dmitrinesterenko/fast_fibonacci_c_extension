Ruby on the ones, C on the twos
-------------------------------

This is an example C extension that calculates numbers in the Fibonacci sequence. For an example that prints out the first n numbers in the sequence consult compute_fibnacci.rb

Running
-------

The gem and the extension make use of the [rake-compiler](https://github.com/luislavena/rake-compiler) to build the native C code for your system. I could have pre-built it for most common systems because rake-compile is that awesome but that is for a future example with the virtual machine based approach of building.
    
```sh 
# Among other things this will install the rake-compiler
bundle install
# Do the compilation
rake compile # This should result in a new file in the ./lib folder it will have either the .so or .bundle extension
# Run the example
ruby compute_fibonacci.rb
```

Why?
----
I had a dream that Ruby code, itself being written in C would be very nice at integrating directly when needed with C built extensions. This dream turned out to be true. My first practical application thoughts turned to things that do cryptography and comparison based on the those results. However one tends to use things like the OpenSSL library and most of the purpose of that library is the provide native methods to run encryption, so clearly that area is already covered.  There could still be custom applications, for example when a few crypto functions are chained together and their results are passed around in Ruby code, that would benefit from being tightened with a dedicated extension. And simply put, any computations that use loops and are O(nlogn) or even (n^2) could probably be tightened up when the logic native to your applications becomes an extension.

Benchmark
---------
A simple Fibonacci benchmark was chosen first: calculate the sequences of Fibonacci numbers 0..40, Fib(0), Fib(1), Fib(2)...Each would calculate the sequence up to the number requestedwhich itself is a natural way to do a benchmark on multiple calculations of the same function.

The first result on MacOSX in seconds is below. 

C extension 5.054231
Ruby way 130.859602


Todo
----
* How would one test the whole thing from C to nuts?
* Haskel proxy to run functional problems in a functional language and use Ruby as a really nice sweet thing that does input / output and a mass of other libraries provide things like hosting websites.
 
