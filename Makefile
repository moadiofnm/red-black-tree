all:
	g++ -std=c++11 -Wall -g  RedBlackTreeTestsFirstStep.cpp RedBlackTree.cpp -o rbtTests
	g++ -std=c++11 -Wall -g RedBlackTreeTests.cpp RedBlackTree.cpp -o rbtTests2

run: 
	
	./rbtTests
	./rbtTests2
try: all run
	