all:
	
	g++ -std=c++11 -Wall -g RedBlackTree.cpp failed_tests.cpp -o rbtTests3

run: 
	./rbtTests3
	
try: all run
	