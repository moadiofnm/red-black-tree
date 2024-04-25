all:
	# g++ -std=c++11 -Wall -g RedBlackTree.cpp RemoveCheckpointTests.cpp -o rbtTests3
	g++ -std=c++11 -Wall -g RedBlackTree.cpp SpeedTest.cpp -o rbtTests4
	# g++ -std=c++11 -Wall -g RedBlackTree.cpp failed_Tests.cpp -o rbtTests5
run: 
	# ./rbtTests3
	./rbtTests4
	# ./rbtTests5
	
try: all run
	