#include <iostream>
#include <initializer_list>

class Node{
	public:
		int value;
		Node * next;
		
		Node(int value) : value (value) , next (nullptr) {}
};

class List{
	public:
		Node * head;
		
		List() : head(nullptr) {}
		
		List(int val){
			Node * newnode = new Node(val);
			head = newnode;
		}
		
		List(std::initializer_list<int> l){
			head = nullptr;
			const int* value = l.begin();
			for(int i = 0; i < l.size(); i++){
				add(*value);
				value++;
			}
		}
		
		int size(){
			int counter = 0;
			Node * curr = head;
			while(1){
				if(curr == nullptr) break;
				curr = curr->next;
				counter++;
			}
			return counter;
		}
		
		void add(int val){
			if(head == nullptr){
				Node * newnode = new Node(val);
				head = newnode;
				return;
			}
			Node* curr = head;
			while(1){
				if(curr->next == nullptr){
					Node * newnode = new Node(val);
					curr->next = newnode;
					return;					
				}
				curr = curr->next;
			}
			
		}
		
		bool isEmpty(){
			return head == nullptr;
		}
		
		void print(){
			if(head == nullptr) return;
			Node curr = *head;
			while(1){
				std::cout << curr.value << '\n';
				if(curr.next == nullptr) break;
				curr = *(curr.next);
			}
		}
		
		void reverse(){
			//a->b->c->d->e->null
			//
			//e->d->c->b->a->null
			int s = size();
			if(s < 2) return;
			Node * newhead;
			for(int i = s; i > 0 ; i--){
				//here counting down to 1 (not 0!!!)
				Node * curr = head;
				Node * prev = nullptr;
				for(int cnt = 1; cnt < i; cnt++){
					prev = curr;
					curr = curr->next;
				}
				curr->next = prev;
				if(i == s) newhead = curr;
			}
			head = newhead;
			
		}
};



int main(){
	
	List mylist({1,2,3,4,5,6,7,8,9,10});
	
	mylist.print();
	
	
	//reverse
	mylist.reverse();
	std::cout << '\n';
	mylist.print();
	
	return 0;
}

