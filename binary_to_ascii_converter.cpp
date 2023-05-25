#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>

char ascii(int num){
	char c = num; //high level maths
	return c;
}

int bitToInt(std::string s){
	int num = 0;
	int weight = 1;
	for(int i = s.length()-1; i >= 0; --i){
		num += ((int) s.at(i) - '0') * weight; // - '0' because s.at(i) casted to int returns ascii 0
		weight *= 2;
	}
	return num;
}

std::string convert(std::string s){
	std::vector<std::string> entrys;
	//fill entrys
	int lastPosOfSpace = -1;
	for(int i = 0; i < s.length(); ++i){
		if(s.at(i) == ' '){
			entrys.push_back(s.substr(lastPosOfSpace + 1, i - 1 - lastPosOfSpace));
			lastPosOfSpace = i;
		}
	}
	entrys.push_back(s.substr(lastPosOfSpace + 1,s.length() - 1 - lastPosOfSpace));
	
	//convert entrys to ascii string
	std::string asc = "";	
    for(std::string e : entrys){
    	asc += ascii(bitToInt(e));
	}
	return asc + '\n';
}

int main() {
	std::string input = "01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100000 00100001";
	std::cout << convert(input);
}