require_relative 'lib/mymath_fast_fibonacci'
sequence = 40
start_time = Time.now
0.upto(sequence) do |i|  
	n = MyMath::FastFibonacci.compute i
end 
end_time = Time.now
puts "C extension #{end_time-start_time}"

def fibonacci(n)
	#puts n
	if n == 0
		0
	elsif n==1
		1
	else
		fibonacci(n-1)+fibonacci(n-2)
	end
end

start_time = Time.now
0.upto(sequence) do |i|
	n = fibonacci(i)
end 
end_time = Time.now
puts "Ruby way #{end_time-start_time}"
