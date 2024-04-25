#include <cstdlib>
#include <ctime>
#include "RedBlackTree.h"
#include <iostream>

using namespace std;


int RandomNumGenerator(int lower, int upper){
	//https://stackoverflow.com/questions/59570015/how-can-i-generate-random-numbers-with-rand
	//used the formula to find random number 
	int random_number = lower + (rand() % (upper - lower + 1));
	return random_number; 
} 

int main(){

	// create a simulated 3.7 million ID number system.
	//ologn insert 
	const int N = 3700000;
	srand(static_cast<unsigned int>(time(nullptr)));

	clock_t start = clock();
	RedBlackTree rbt = RedBlackTree();
	for(int i = 0; i < N; i++){
	 	rbt.Insert(i);
	}
	clock_t stop = clock();

	double duration = (static_cast<double>(stop - start)) / CLOCKS_PER_SEC;
	cout << "Collected " << rbt.Size() << " ID numbers in " << (duration) << " seconds." << endl;


	// // Your code goes here to simulate leaving / joining.



	//ologn removal 
	cout << "Testing removing 5 ids ... " << endl; 
	for (int i = 0; i < 5; i++) {
        int idToRemove = RandomNumGenerator(0, N - 1); // range b/w 0 and 3699999
        clock_t startRemove = clock();
        rbt.Remove(idToRemove);
        clock_t stopRemove = clock();
        double durationRemove = static_cast<double>(stopRemove - startRemove) / CLOCKS_PER_SEC;
        cout << "Removing ID " << idToRemove << " took " << durationRemove << " seconds." << endl;
    }

	// ologn insert
	cout << "Testing adding 5 ids ... " << endl; 
	for (int i = 0; i < 5; i++) {
        int idToadd= RandomNumGenerator(0, N - 1); // range b/w 0 and 3699999
        clock_t startadd = clock();
        rbt.Remove(idToadd);
        clock_t stopadd = clock();
        double durationAdd = static_cast<double>(stopadd - startadd) / CLOCKS_PER_SEC;
        cout << "Removing ID " << idToadd << " took " << duration<< " seconds." << endl;
    }


	return 0;
}