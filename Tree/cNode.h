#pragma once
#define NULLNUMBER -1

class cNode
{
public:

	int m_data;
	int m_bf;
	cNode* m_left;
	cNode* m_right;


	cNode() 
	{
		m_data = NULLNUMBER;
		m_left = nullptr;
		m_right = nullptr;
		m_bf = 999;
	}
	~cNode() {}
};

