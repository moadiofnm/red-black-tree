all:
	
	g++ -std=c++11 -Wall -g RedBlackTree.cpp RemoveCheckpointTests.cpp -o rbtTests3

run: 
	./rbtTests3
	
try: all run
	