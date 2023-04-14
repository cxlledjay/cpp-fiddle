#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>


class Block{
	public:
		std::unordered_map<std::string , bool> buildings;
		
		Block(bool gym , bool school , bool shop) {
			buildings.clear();
			buildings.insert({"gym" , gym});
			buildings.insert({"school" , school});
			buildings.insert({"shop" , shop});
			//easy to add further pois
		}
};

int calculate_distance(int i , std::vector<Block>& blocks , std::string key){
	
		int distance = blocks.size(); //make distance max
		std::unordered_map<std::string , bool> map = blocks[i].buildings; //get map of current pois
		
		if(map[key]) return 0; //poi of key is in given block -> distance = 0;
		
		//calculate distance if poi is in blocks with higher indexes
		for(int bigger = i+1 ; bigger < blocks.size(); bigger++){
			map = blocks[bigger].buildings; //update map to currently watched block
			if(distance < bigger - i) continue; //only chanching distance if new value is lower (-> logic)
			if(map[key]) distance = bigger - i; //calculate distance
		}
		
		//same calculation for buildings with lower indexes
		for(int smaller = i-1 ; smaller >= 0; smaller--){
			map = blocks[smaller].buildings; //update map to currently watched block
			if(distance < i - smaller) continue; //only chanching distance if new value is lower (-> logic)
			if(map[key]) distance = i - smaller; //calculate distance
		}
		return distance; //lowest distance gets returned
}

int main(){
	//given
	//blocks
	std::vector<Block> blocks;
	blocks.push_back(Block{false, false, true }); //0
	blocks.push_back(Block{false, false, false}); //1
	blocks.push_back(Block{true , false, false}); //2
	blocks.push_back(Block{false, true , false}); //3
	blocks.push_back(Block{false, true , true }); //4
	blocks.push_back(Block{false, false, false}); //5
	blocks.push_back(Block{false, false, false}); //6
	//reqs
	std::list<std::string> reqs{"gym" , "shop"}; //gym school shop
	
	
	//problem solving
	
	int lowest = blocks.size();
	std::list<int> best;
	std::vector<int> all_min;
	
	//calculate minimal distances for each block
	for(int i = 0; i < blocks.size() ; i++){
		int max = 0;
		for(std::string key : reqs){ //iterating trough all given pois
			int distance = calculate_distance(i , blocks , key);
			if(distance > max) max = distance; //calculating highest distance to a poi out of given minimal distances
		}
		all_min.push_back(max);
	}
	
	//calculate lowest distance of all blocks
	for(int i = 0; i < all_min.size(); i++){
		if(all_min[i] < lowest){
			lowest = all_min[i];
		}
	}
	
	//get best index(es)
	for(int i = 0; i < all_min.size(); i++){
		if(all_min[i] == lowest) best.push_back(i);
	}
	
	//formated output
	if(best.size() == 1) { //only one block ist best
		std::cout << "The best block is (counting from 0 up): " << best.front() << std::endl;
		return 0;	
	} else { //multiple blocks fit given requirements
		std::cout << "The best blocks are (counting from 0 up): \n";
		for(int index : best){
			std::cout << index << '\n';
		}
	}
}