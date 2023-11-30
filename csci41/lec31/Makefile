# every Makefile rule has a target name
# requirements come after the :
# then you tab over and give the "body" of the rule

main: a.o b.o
	g++ a.o b.o -o main

a.o: a.cpp
	g++ -c a.cpp

b.o: b.cpp
	g++ -c b.cpp

# a "clean" rule usually removes all the compiled files
clean:
	rm -f a.o b.o main
