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


	//�տ��� �Ͼ ���� ����� ���� ���
	cNode* m_bf_node;

	

	//�θ� ������ �ϳ�����! ����Լ� �ȵ����� �ڵ� ©�Ÿ� �θ𺯼� �ϳ��־���� �θ��� Left�� Right�� NullPointeró��������� �ȱ׷��� ����Ʈ�����ͽ����
	//cNode* m_parent;

	void Push(int _data);
	cNode* Pop(int _data);

	cNode* FindParent(int _data);
	cNode* Search(int _data);

	cNode* RotateLL(cNode* A);
	void RotateRR(cNode* A);
	void RotateLR(cNode* A);
	void RotateRL(cNode* A);

	//��ü �� ��ȸ
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

