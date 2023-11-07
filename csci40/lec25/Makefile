# This is a Makefile comment

# every rule look like
# target: ingredient1 ingredient2 ...
# 	terminal commands to
#		make the target
#		from the ingredients

main: searching.o main.o
	g++ searching.o main.o -o main

searching.o: searching.cpp
	g++ -c searching.cpp

main.o: main.cpp
	g++ -c main.cpp

