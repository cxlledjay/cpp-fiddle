#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "tree.hpp"

template<class type>
using vec = std::vector<type>;

namespace mysort{
	
	template <class T>
	void tree(vec<T>& sorted);
	
	template <class T>
	void insertion(vec<T>& sorted);
	
	template <class T>
	void selection(vec<T>& sorted);
	
	template <class T>
	void bubble(vec<T>& sorted);
	
	template <class T>
	void merge(vec<T>& sorted);
	
	template <class T>
	void quick(vec<T>& sorted);
	
	template <class T>
	void heap(vec<T>& sorted);
	
}


//sorting algorithms ----------------------------------------------------------------------------------------------------

//tree sort
template <class T>
void mysort::tree(vec<T>& v){
	bst::Node<T> binary_search_tree;
	for(auto entry : v) binary_search_tree.insert(entry);
	v.clear();
	bst::inorder(&binary_search_tree , v);
}

//insertion sort
template <class T>
void mysort::insertion(vec<T>& v){
	T temp;
	int sorted;
	for(int pos = 1; pos < v.size(); ++pos){ //current position of element being selected, v[0] is seen as sorted
		temp = v[pos];
		sorted = pos;
		while(sorted > 0 && v[sorted - 1] > temp){
			v[sorted] = v[sorted - 1];
			sorted--;
		}
		v[sorted] = temp;
	}
}

//selection sort
template <class T>
void mysort::selection(vec<T>& v){
	int index_max, i, j;
	T temp;
	for(i = v.size() - 1; i >= 0; --i){
		index_max = i;
		for(j = i; j >= 0; --j){
			if(v[j] > v[index_max]) index_max = j;
		}
		temp = v[i];
		v[i] = v[index_max];
		v[index_max] = temp;
	}
}

//bubble sort
template <class T>
void mysort::bubble(vec<T>& v){
	if(v.size() < 2) return;
	T temp;
	for(int i = v.size() - 1; i >= 0; --i){
		for(int j = 1; j <= i; ++j){
			//biggest bubble up each time
			if(v[j-1] > v[j]){
				//swap
				temp = v[j];
				v[j] = v[j-1];
				v[j-1] = temp;
			}
		}
	}
}


//merge sort
namespace mergesort {

	template <class T>
	void split(vec<T>& start, vec<T>& left, vec<T>& right){
		vec<T> l,r;
		const unsigned int half = start.size()/2;
		for(int i = 0; i < start.size(); ++i){
			if(i < half) l.push_back(start.at(i));
			else r.push_back(start.at(i));
		}
		left = l; right = r;
	}

	template <class T>
	vec<T> merge(vec<T>& left, vec<T>& right){
		unsigned int l,r,size;
		l = r = 0;
		size = left.size() + right.size();
		vec<T> result(size);

		for(int i = 0; i < size; ++i){
			if(l >= left.size()){ //left vector done
				result[i] = right[r];
				++r;
			} else if(r >= right.size()){ //right vector done
				result[i] = left[l];
				++l;
			} else if(left[l] < right[r]){ //left element smaller
				result[i] = left[l];
				++l;
			} else{ //right element smaller
				result[i] = right[r];
				++r;
			}
		}
		return result;
	}
}

template <class T>
void mysort::merge(vec<T>& v){
	if(v.size() < 2) return; //recursion end
	vec<T> l,r;
	mergesort::split(v,l,r);
	mysort::merge(l);
	mysort::merge(r);
	v = mergesort::merge(l,r);
}