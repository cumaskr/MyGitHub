#pragma once
#include "cNode.h"
#include <stdio.h>
#include<iostream>
using namespace std;

class cTree
{
public:
	cNode* m_root;

	//cNode* m_balance_factor_last;


	//균열이 일어난 가장 가까운 조상 노드
	cNode* m_bf_node;

	

	//부모 변수를 하나쓰자! 재귀함수 안돌릴고 코드 짤거면 부모변수 하나있어야함 부모의 Left랑 Right를 NullPointer처리해줘야함 안그러면 스마트포인터써야함
	//cNode* m_parent;

	void Push(int _data);
	cNode* Pop(int _data);

	cNode* FindParent(int _data);
	cNode* Search(int _data);

	cNode* RotateLL(cNode* A);
	void RotateRR(cNode* A);
	void RotateLR(cNode* A);
	void RotateRL(cNode* A);

	//전체 다 조회
	void PreOrder(cNode* _node);
	void MidOrder(cNode* _node);
	void PostOrder(cNode* _node);

	int Get_Height(cNode* NODDE, bool isStart);
	void ReAVLTreeMake(cNode* cur, int bf);

	cTree() 
	{
		m_root = nullptr;
	}
	~cTree() {}
};

