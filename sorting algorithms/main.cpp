#include "sorting_algorithms.hpp"
#include "tree.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace debug{
	template<class T>
	void print_vector(std::string description, vector<T>& v){

		std::cout << description;

		if(v.size() == 0) {
			std::cout << "[/]\n";
			return;
		}

		string delim = " | ";
		std::cout << "[ "; //vector start

		int i;
		for(i = 0; i < v.size()-1; ++i){
			std::cout << v[i];
			std::cout << delim;
		}
		std::cout << v[i];

		std::cout << " ]\n"; //vector end
	}
}

template <class T>
void sort_vector(vector<T>& v){ //CHANGE SORTING ALGORITM HERE!!!
	//sort(v.begin() , v.end());
	mysort::tree<T>(v);
}

string random_string(const unsigned int max_length){
	string s;
	for(int i = rand() % max_length; i >= 0; --i){
		s += (char) ('a' + (rand() % 26));
	}
	return s;
}

bool run_tests(){
	bool fail = false;

	//change value here:
	const unsigned int max_vector_size = 15;

	unsigned int v_size = rand() % max_vector_size;
	std::cout << "   :   vector size: " << v_size << endl; //display vector size in main

	vector<int> v_int(v_size), v_int_expected(v_size);
	vector<double> v_double(v_size), v_double_expected(v_size);
	vector<string> v_string(v_size), v_string_expected(v_size);

	for(int i = 0; i < v_size; ++i){ //filled with different values
		v_int[i] = ((int) rand() % 100);
		v_double[i] = ((double) (rand() % 100)/100.);
		v_string[i] = ((string) random_string(3));
	}

	//int
	debug::print_vector<int>(" > unsorted (int): " , v_int);
	v_int_expected = v_int;
	sort(v_int_expected.begin() , v_int_expected.end());
	debug::print_vector<int>(" > expected (int): " , v_int_expected);
	sort_vector<int>(v_int);
	debug::print_vector<int>(" > actual   (int): " , v_int);
	if(v_int != v_int_expected) fail = true;
	std::cout << endl;

	//double
	debug::print_vector<double>(" > unsorted (double): " , v_double);
	v_double_expected = v_double;
	sort(v_double_expected.begin() , v_double_expected.end());
	debug::print_vector<double>(" > expected (double): " , v_double_expected);
	sort_vector<double>(v_double);
	debug::print_vector<double>(" > actual   (double): " , v_double);
	if(v_double != v_double_expected) fail = true;
	std::cout << endl;

	//string
	debug::print_vector<string>(" > unsorted (string): " , v_string);
	v_string_expected = v_string;
	sort(v_string_expected.begin() , v_string_expected.end());
	debug::print_vector<string>(" > expected (string): " , v_string_expected);
	sort_vector<string>(v_string);
	debug::print_vector<string>(" > actual   (string): " , v_string);
	if(v_string != v_string_expected) fail = true;
	std::cout << endl;

	return !fail;
}

int main () {
	START:
	unsigned int tests;
	bool all_good = true;
	std::cout << "\nHow many tests should be done? (between 1 and 100): ";
	std::cin >> tests;
	if(tests < 1 || tests > 100) goto START;
	std::cout << "\n\n";
	bool succ;
	unsigned int vector_size;
	for(int i = 1; i <= tests; ++i){
		std::cout << "Test Nr. " << i;
		succ = run_tests();

		if(succ) std::cout << "Test was successfull!\n";
		else std::cout << "Test failed!\n";
		if(!succ) all_good = false;
	}
	if(all_good) std::cout << "------------------------------------------------------------------------\nAll tests were successfull!\n\n";
	else std::cout << "------------------------------------------------------------------------\nAt least one test failed!\n\n";
	return 0;
}

int main1() {
	vec<int> v({3,4,1,2});
	vec<int> l,r;

	mergesort::split(v,l,r);

	std::cout << "split: \n";
	for(auto x : l) std::cout << "left: " << x << endl;
	for(auto x : r) std::cout << "right: " << x << endl;

	v = mergesort::merge(l , r);

	std::cout << "merge: \n";
	for(auto x : v) std::cout << "merged: " << x << endl;

}