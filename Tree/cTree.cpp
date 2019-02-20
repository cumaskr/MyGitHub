#include "cTree.h"

void cTree::Push(int _data)
{
	if (m_root == nullptr)
	{
		cNode* tmpNode = new cNode();
		tmpNode->m_data = _data;
		m_root = tmpNode;
	
	}
	else
	{
		cNode* iter = m_root;
		cNode* tmpNode = new cNode();
		tmpNode->m_data = _data;
		while (iter != nullptr)
		{
			if (tmpNode->m_data < iter->m_data)
			{
				if (iter->m_left == nullptr)
				{
					iter->m_left = tmpNode;
					Get_Height(m_root,true);
					if (m_bf_node != nullptr)
					{
						ReAVLTreeMake(m_bf_node,m_bf_node->m_bf);
						m_bf_node = nullptr;
					}
					break;
				}
				iter = iter->m_left;
			}
			else
			{
				if (iter->m_right == nullptr)
				{
					iter->m_right = tmpNode;
					Get_Height(m_root,true);
					if (m_bf_node != nullptr)
					{
						ReAVLTreeMake(m_bf_node, m_bf_node->m_bf);
						m_bf_node = nullptr;
					}
					break;
				}
				iter = iter->m_right;
			}
		}
	}
}

//POP�Լ� ȣ��ɶ� Parent�� ���Ǿ� ���´�.
cNode* cTree::Pop(int _data)
{
	cNode* tmpNode = Search(_data);;
	cNode* tmpParent = FindParent(tmpNode->m_data);

	if (tmpNode == nullptr) return nullptr;
	
	//�ܸ������ ���
	if (tmpNode->m_left == nullptr && tmpNode->m_right == nullptr)
	{
		if (tmpParent->m_data != tmpNode->m_data && tmpParent->m_data > tmpNode->m_data)
		{
			tmpParent->m_left = nullptr;
		}
		else if (tmpParent->m_data != tmpNode->m_data && tmpParent->m_data < tmpNode->m_data)
		{
			tmpParent->m_right = nullptr;
		}
		free(tmpNode);
	}
	//�ڽ� ��尡 2���� ���
	else if (tmpNode->m_left != nullptr && tmpNode->m_right != nullptr)
	{
		//���ο� �ĺ��� ���ο� ���纻
		cNode* newNode = new cNode();
		cNode* basic_tmpNode = tmpNode;
		cNode* parent = tmpParent;
		bool isLeft = false;		
		if (tmpNode->m_data < tmpParent->m_data)
		{
			isLeft = true;
		}
		else
		{
			isLeft = false;
		}
		
		if (isLeft)
		{
			while (tmpNode->m_right != nullptr)
			{
				tmpNode = tmpNode->m_right;
			}
			newNode->m_data = tmpNode->m_data;
			newNode->m_left = tmpNode->m_left;
			newNode->m_right = tmpNode->m_right;
			Pop(tmpNode->m_data);
		}
		else if (isLeft == false)
		{
			while (tmpNode->m_left != nullptr)
			{
				tmpNode = tmpNode->m_left;
			}
			newNode->m_data = tmpNode->m_data;
			newNode->m_left = tmpNode->m_left;
			newNode->m_right = tmpNode->m_right;
			Pop(tmpNode->m_data);
		}
       
		if (isLeft)
		{
			parent->m_left = newNode;
			newNode->m_left = basic_tmpNode->m_left;
			newNode->m_right = basic_tmpNode->m_right;
			free(basic_tmpNode);
		}
		else
		{
			parent->m_right = newNode;
			newNode->m_left = basic_tmpNode->m_left;
			newNode->m_right = basic_tmpNode->m_right;
			free(basic_tmpNode);
		}
	}
	//�ڽ� ��尡 1���� ���
	else
	{
		cNode* childNode = nullptr;
		//�ڽ� ��尡 1���ΰ��
		if (tmpNode->m_left != nullptr)
		{
			childNode = tmpNode->m_left;
		}
		else
		{
			childNode = tmpNode->m_right;
		}

		if (tmpParent->m_data != tmpNode->m_data && tmpParent->m_data > tmpNode->m_data)
		{
			tmpParent->m_left = childNode;
		}
		else if (tmpParent->m_data != tmpNode->m_data && tmpParent->m_data < tmpNode->m_data)
		{
			tmpParent->m_right = childNode;
		}
		free(tmpNode);
	}
}

cNode * cTree::FindParent(int _data)
{
	if (m_root == nullptr) return nullptr;

	cNode* iter = m_root;
	cNode* parent = nullptr;
	while (iter != nullptr)
	{
		if (iter->m_data == _data)
		{
			return parent;
		}
		if (iter->m_data > _data)
		{
			parent = iter;
			iter = iter->m_left;
		}
		else
		{
			parent = iter;
			iter = iter->m_right;
		}
	}
	return nullptr;
}

cNode* cTree::RotateLL(cNode* A)
{
	cNode* B = (A->m_left);
	// 1) B�� ������ �ڽ��� A�� ���� �ڽ����� �����.
	A->m_left = B->m_right;
	// 2) A�� B�� ������ �ڽ� ���� �����.
	B->m_right = A;
	cNode* parent = FindParent(A->m_data);
	if (parent == nullptr)
	{
		m_root = B;
	}
	else
	{	
		if (parent->m_data < B->m_data)
		{
			parent->m_right = B;
		}
		else
		{
			parent->m_left = B;
		}
		
	}
	return B;
}

void cTree::RotateRR(cNode * A)
{
	cNode* B = (A->m_right);
	// 1) B�� ���� �ڽ��� A�� ������ �ڽ����� �����.
	A->m_right = B->m_left;
	// 2) A�� B�� ���� �ڽ� ���� �����.
	B->m_left = A;
	cNode* parent = FindParent(A->m_data);
	//�̰Թ�����
	if (parent == nullptr)
	{
		m_root = B;
	}
	else
	{
		if (parent->m_data < B->m_data)
		{
			parent->m_right = B;
		}
		else
		{
			parent->m_left = B;
		}
	}
}

void cTree::RotateLR(cNode * A)
{
	cNode* B = A->m_left;
	RotateRR(B);
	RotateLL(A);
}

void cTree::RotateRL(cNode * A)
{
	cNode* B = A->m_right;
	RotateLL(B);
	RotateRR(A);
}

cNode* cTree::Search(int _data)
{
	if (m_root == nullptr) return nullptr;
	
	cNode* iter = m_root;
	//m_parent = iter;
	while (iter != nullptr)
	{
		if (iter->m_data == _data)
		{
			return iter;
		}
		if (iter->m_data > _data)
		{
			//m_parent = iter;
			iter = iter->m_left;
		}
		else
		{
			//m_parent = iter;
			iter = iter->m_right;
		}
	}
	
	cout << "�ش� " << _data << "��尡 �����ϴ�." << endl;
	return nullptr;
}

void cTree::PreOrder(cNode* _node)
{
	cNode* tmpNode = _node;
	cout << "[ " << tmpNode->m_data << " ]" << endl;

	if (tmpNode->m_left != nullptr)
	{
		PreOrder(tmpNode->m_left);
	}
	if (tmpNode->m_right != nullptr)
	{
		PreOrder(tmpNode->m_right);
	}
}

void cTree::MidOrder(cNode* _node)
{
	cNode* tmpNode = _node;
	if (tmpNode->m_left != nullptr)
	{
		MidOrder(tmpNode->m_left);
	}
	cout << "[ " << tmpNode->m_data << " ]" << endl;
	if (tmpNode->m_right != nullptr)
	{
		MidOrder(tmpNode->m_right);
	}
}

void cTree::PostOrder(cNode* _node)
{
	cNode* tmpNode = _node;
	if (tmpNode->m_left != nullptr)
	{
		PostOrder(tmpNode->m_left);
	}
	if (tmpNode->m_right != nullptr)
	{
		PostOrder(tmpNode->m_right);
	}
	cout << "[ " << tmpNode->m_data << " ]" << endl;
}

int cTree::Get_Height(cNode * cur, bool isStart)
{
	int _LCount = 0;
	int _RCount = 0;
	

	if (cur->m_left != nullptr)
	{
		_LCount = _LCount + Get_Height(cur->m_left,false);
		_LCount++;
	}
	if (cur->m_right != nullptr)
	{
		_RCount++;
		_RCount = _RCount + Get_Height(cur->m_right, false);
	}

	cur->m_bf = _LCount - _RCount;

	//������ �߻������� ���� �����ξ�(���� Input �Ǵ� ����� ���� ����� ������)
	if (cur->m_bf >=2 || cur->m_bf <= -2)
	{	
		if (m_bf_node == nullptr)
		{
			m_bf_node = cur;
			cout << "�տ��� �߻��� ���� �ֽų��� : " << m_bf_node->m_data << endl;

		}
		
		cout << "���� �߻� : " << cur->m_data << " - " << _LCount - _RCount << endl;
	}

	if (_LCount > _RCount)
	{
		if (isStart)
		{
			return _LCount + 1;
		}
		else
		{
			return _LCount;
		}
	}
	else
	{
		if (isStart)
		{
			return _RCount + 1;
		}
		else
		{
			return _RCount;
		}
	}


	cout << "����� �ѹ��� ȣ��ǳ���?" << endl;
}

void cTree::ReAVLTreeMake(cNode* cur, int bf)
{
	if (bf >= 2 && cur->m_left->m_bf > 0)
	{
		RotateLL(cur);
	}
	else if (bf >= 2 && cur->m_left->m_bf < 0)
	{
		RotateLR(cur);
	}
	else if (bf <= -2 && cur->m_right->m_bf < 0)
	{
		RotateRR(cur);
	}
	else if (bf <= -2 && cur->m_right->m_bf > 0)
	{
		RotateRL(cur);
	}


}
