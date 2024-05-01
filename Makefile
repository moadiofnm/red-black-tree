all:
	g++ -g -Wall linked_list.h linked_list_tests.cpp -o ll-tests
run: 
	./ll-tests
try: all run 