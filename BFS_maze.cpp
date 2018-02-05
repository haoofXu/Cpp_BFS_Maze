// BFS_maze.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int maze[8][8] = {
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,1,1,1,0,1,0 },
	{ 0,0,0,0,1,0,1,0 },
	{ 0,1,0,0,0,0,1,0 },
	{ 0,1,0,1,1,0,1,0 },
	{ 0,1,0,0,0,0,1,1 },
	{ 0,1,0,0,1,0,0,0 },
	{ 0,1,1,1,1,1,1,0 }
};
//�¡��ҡ��ϡ���
const int fx[4] = { 1,0,-1,0 };
const int fy[4] = { 0,1,0,-1 };
//maze[i][j] = 3;//��ʶ����
//maze[i][j] = 2;//��ʶ����ͬ
//maze[i][j] = 1;//��ʶǽ
//maze[i][j] = 0;//��ʶ������

//��ӡ·��
void printPath()
{
	for (int i = 0; i<8; ++i)
	{
		for (int j = 0; j<8; ++j)
		{
			if (3 == maze[i][j])
			{
				cout << "V";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void search(int i, int j)
{
	int newx;
	int newy;
	for (int k = 0; k<4; ++k)
	{
		newx = i + fx[k];
		newy = j + fy[k];
		//�������ǽ����û���߹�
		if (newx >= 0 && newx <8 && newy >= 0 && newy<8 && 0 == maze[newx][newy])
		{
			maze[newx][newy] = 3;
			if (7 == newx && 7 == newy)
			{
				printPath();
				maze[newx][newy] = 0;
			}
			else
			{
				search(newx, newy);
			}
		}
	}
	//���ݵ�ʱ�򽫴˵���δ���ʣ�������һ��·��Ҳ���Է���
		maze[i][j] = 0;
}

int main()
{
	maze[0][0] = 3;
	search(0, 0);
	int a;
	cin >> a;
	return 0;
}