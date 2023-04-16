#include <iostream>
#include <list>


enum class ListState{
	EUQAL,
	SUBLIST,
	SUPERLIST,
	DIFFERENT
};

//returns ListState of list1 compared to list2
ListState compare_list(std::list<int> list1, std::list<int> list2){
	
	if(list1.size() < list2.size()){
		// list1 can be sublist
	}
	
	if(list1.size() > list2.size()){
		// list1 can be superlist
	}
	
	if(list1.size() == list2.size()){
		// list1 can be equal
	}
	
	return ListState::DIFFERENT;
	
}

void print_list(std::list<int> l, std::string name){
	std::cout << "Contents of " << name <<": \n";
	for(int n : l) std::cout << n << ' ';
	std::cout << "\n\n";
}


int main(){
	
	std::list<int> list1{1,2,3,4,5};
	std::list<int> list2{1,2,3,4,5};
	
	print_list(list1 , "Liste Nr.1");
	print_list(list2 , "Liste Nr.2");
	
	compare_list(list1 , list2);
	
	return 0;
}