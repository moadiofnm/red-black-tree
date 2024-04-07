all:
	g++ -std=c++11 -Wall -g  RedBlackTreeTestsFirstStep.cpp RedBlackTree.cpp -o rbtTests

run: 
	./rbtTests

try: all run
	