#ifndef __STACK__
#define __STACK__

#include "LinkedList.h"
#include <stdio.h>
using namespace std;


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T> {
public:
    // LinkedList 클래스의 Delete 함수를 오버라이딩하여 재정의
    bool Delete(T &element) {
        // first가 0이면 false 반환
		// Stack의 특성상 맨 앞에서만 삭제하면 되므로 LinkedList와 다르게 작성
		if (this->first == NULL)
			return false; // 리스트의 노드의 개수가 0일 때, false 반환

		Node<T> *temp = LinkedList<T>::first;
		LinkedList<T>::first = LinkedList<T>::first->link; // 첫 번째 노드를 다음 노드로 이동
		element = temp->data;							   // 삭제한 노드의 데이터를 전달
		delete temp;									   // 삭제한 노드의 메모리 반환
		this->current_size--;
        return true;
    }
};

#endif