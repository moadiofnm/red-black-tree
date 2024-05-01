all:
	g++ -g -Wall linked_list.h linked_list_tests.cpp -o ll-tests
try: 
	./ll-tests
run: all run 