# this is a Makefile comment!

CXX=g++

main: main.o counter.o
	$(CXX) $^ -o $@

main.o: main.cpp
	$(CXX) -c $^

counter.o: counter.cpp
	$(CXX) -c $^

# clean doesn't make anything: it just removes all compiled files
clean:
	rm -f *.o main
