#include <iostream>
#include <vector>
#include <random>

using std::cout;
using std::endl;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

vector<vector<int>> A;
vector<vector<int>> sums;
const int SIZE = 8;

// initialize a size x size matrix with either random numbers
// (either 0 or 1) or zeros
void initialize_matrix(vector<vector<int>>& M, bool random = true) {
	// set up random number generation
	default_random_engine pseudo_rng;
	uniform_int_distribution<short int> bin_dist(0, 1);

	// for each row number
 for (int row = 0; row < SIZE; row++) {
		// create empty row
		M.push_back({});
		// for each column number
		for (int col = 0; col < SIZE; col++) {
			// set item to either random or 0
			int item;
			if (random) {
				item = bin_dist(pseudo_rng);
			}
			else {
				item = 0;
			}
			// add item to row
			M[row].push_back(item);
		}
	}
}

// print out a matrix
void display_matrix(vector<vector<int>>& vec) {
	// for each row
	for (auto row : vec) {
		// for each item in the row
		for (auto i : row) {
			// print out item followed by space
			cout << i << ' ';
		}
		// print newline after each row
		cout << endl;
	}
}

// returns the sum of the neighbours (up to 4, diagonals not included)
// of an item in matrix A, given its row and column
int sum_neighbours(unsigned int row, unsigned int col) {

	int sum = 0;

	// add vertical neighbours if possible
	if (row > 0) {
		// upper neighbour
		sum += A[row - 1][col];
	}
	if (row < SIZE - 1) {
		// lower neighbour
		sum += A[row + 1][col];
	}

	// add horizontal neighbours if possible
	if (col > 0) {
		// left neighbour
		sum += A[row][col - 1];
	}
	if (col < SIZE - 1) {
		// right neighbour
		sum += A[row][col + 1];
	}

	return sum;
}

// loop across rows of matrix A, calculating the sum of the neighbours
// (not including diagonal) of each item and storing it in sums matrix
void calculate_sums() {
	// for each row
	for (unsigned int row = 0; row < SIZE; row++) {
		// for each item in the row
		for (unsigned int col = 0; col < SIZE; col++) {
			// calculate sum of neighbours and store in sums matrix
			sums[row][col] = sum_neighbours(row, col);
		}
	}
}

int main() {
	// initialize matrix A with random numbers, either 0 or 1
	initialize_matrix(A, true);
	// initialize matrix of sums with zeros
	initialize_matrix(sums, false);
	// calculate the sums of the neighbours of each item in matrix A
	calculate_sums();
	// display the matrix A
	display_matrix(A);
	// display the sums matrix
	display_matrix(sums);

	return 0;
}