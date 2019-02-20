
#include"cTree.h"
#include<Windows.h>




int main() 
{
	cTree t;

	/*t.Push(8);
	t.Push(3);
	t.Push(10);
	t.Push(2);
	t.Push(5);
	t.Push(14);
	t.Push(4);
	t.Push(11);
	t.Push(16);*/
	//t.PostOrder(t.m_root);

	/*t.Push(6);
	t.Push(5);
	t.Push(2);
	t.Push(1);
	t.Push(8);
	t.RotateLL(t.Search(5));*/

	/*t.Push(5);
	t.Push(10);
	t.Push(7);
	t.Push(6);
	t.RotateLL(t.Search(10));
*/
	/*
	t.Push(1);
	t.Push(3);
	t.Push(5);
	t.Push(4);
	t.Push(10);
	t.RotateRR(t.Search(3));*/
	
	/*t.Push(1);
	t.Push(3);
	t.Push(5);
	t.Push(6);
	t.RotateRR(t.Search(3));*/

	/*t.Push(12);
	t.Push(6);
	t.Push(7);
	t.Push(8);
	t.RotateRR(t.Search(6));*/

	//t.Push(10);
	//t.Push(2);
	//t.Push(5);
	//t.Push(12);
	//t.RotateLR(t.Search(10));

	//t.Push(5);
	//t.Push(8);
	//t.Push(10);
	//t.RotateRR(t.Search(5));

	/*t.Push(5);
	t.Push(10);
	t.Push(8);
	t.Push(3);
	t.RotateRL(t.Search(5));*/

	/*t.Push(5);
	t.Push(7);
	t.Push(6);
	t.RotateRL(t.Search(5));*/


	/*t.Push(70);
	t.Push(60);
	t.Push(80);
	t.Push(50);
	t.Push(73);
	t.Push(72);
	t.Push(75);
	t.Push(78);
	t.Push(90);
	t.RotateLR(t.Search(80));
	*/

	//cout << t.m_balance_factor_last->m_data << endl;

	t.PostOrder(t.m_root);

	//t.RotateLL()

	system("pause");
}