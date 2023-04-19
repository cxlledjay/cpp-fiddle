#include <iostream>
#include <list>


enum class ListState{
	EQUAL,
	SUBLIST,
	SUPERLIST,
	DIFFERENT
};

bool sublist(std::list<int>& sub,std::list<int>&  sup){
	auto it = sup.begin();
	for(int i = 0; i < sup.size()-sub.size() + 1; i++){
		// 1 2 3 4 5 6
		// 1 2 3 4
		//   1 2 3 4
		//     1 2 3 4
		auto it1 = sub.begin();
		auto it2 = it;
		for(int n = 0; n < sub.size(); n++){
			if(*it1 != *it2) break;
			if(n == sub.size()-1){
				return true;
			}
			it1++; it2++;
		}
		it++;
	}
	return false;
}

//returns ListState of list1 compared to list2
ListState compare_list(std::list<int> list1, std::list<int> list2){
	
	if(list1.size() < list2.size()){
		if(sublist(list1 , list2)) return ListState::SUBLIST;
	}
	
	if(list1.size() > list2.size()){
		if(sublist(list2 , list1)) return ListState::SUPERLIST;
	}
	
	if(list1.size() == list2.size()){
		auto it1 = list1.begin();
		auto it2 = list2.begin();
		for(int i = 0; i < list1.size(); i++){
			if(*it1 != *it2) break;
			if(i == list1.size() - 1) return ListState::EQUAL;
			it1++; it2++;
		}
	}
	
	return ListState::DIFFERENT;
	
}

void print_list(std::list<int> l, std::string name){
	std::cout << "Contents of " << name <<": \n";
	for(int n : l) std::cout << n << ' ';
	std::cout << "\n\n";
}


int main(){
	
	std::list<int> list1{0,1,2,3,4,5};
	std::list<int> list2{3,4,5};
	
	print_list(list1 , "Liste Nr.1");
	print_list(list2 , "Liste Nr.2");
	
	ListState ls = compare_list(list1 , list2);
	
	if(ls == ListState::SUBLIST) std::cout << "SUBLIST!\n";
	if(ls == ListState::SUPERLIST) std::cout << "SUPERLIST!\n";
	if(ls == ListState::EQUAL) std::cout << "EQUAL!\n";
	if(ls == ListState::DIFFERENT) std::cout << "UNEQUAL!\n";
	
	return 0;
}