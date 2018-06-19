#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<queue>



using namespace std;

template<typename T, typename Container = deque<T> >
class iterable_queue : public queue<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

class Instance
{
public:
	string Ins;
	int Heuristic;
	Instance()
	{
		Heuristic = 0;
	}

};


class Suduku
{
public:
	string move;
	//---------------------------------------------------------------child
	//----------------------------------------face
	int face[3][3];

	//----------------------------------------left
	int left[3][3];

	//----------------------------------------right
	int right[3][3];

	//----------------------------------------down
	int down[3][3];

	//----------------------------------------up
	int up[3][3];
	//----------------------------------------back
	int back[3][3];
	//---------------------------------------------------------------Parent
	//----------------------------------------face
	int pface[3][3];

	//----------------------------------------left
	int pleft[3][3];

	//----------------------------------------right
	int pright[3][3];

	//----------------------------------------down
	int pdown[3][3];

	//----------------------------------------up
	int pup[3][3];
	//----------------------------------------back
	int pback[3][3];
	//--------------------------------------------------------------------------default Constructor
	Suduku()
	{
		//----------------------------------------------------------------filling face
		int value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				face[i][j] = value;
				value++;
			}
		}

		//----------------------------------------------------------------filling left
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				left[i][j] = value;
				value++;
			}
		}

		//----------------------------------------------------------------filling right
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				right[i][j] = value;
				value++;
			}
		}


		//----------------------------------------------------------------filling down
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				down[i][j] = value;
				value++;
			}
		}

		//----------------------------------------------------------------filling up
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				up[i][j] = value;
				value++;
			}
		}

		//----------------------------------------------------------------filling back
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				back[i][j] = value;
				value++;
			}
		}
		//------------------------------------------------------------------------------------


		//----------------------------------------------------------------filling face
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pface[i][j] = -1;
				value++;
			}
		}

		//----------------------------------------------------------------filling left
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pleft[i][j] = -1;
				value++;
			}
		}

		//----------------------------------------------------------------filling right
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pright[i][j] = -1;
				value++;
			}
		}


		//----------------------------------------------------------------filling down
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pdown[i][j] = -1;
				value++;
			}
		}

		//----------------------------------------------------------------filling up
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pup[i][j] = -1;
				value++;
			}
		}

		//----------------------------------------------------------------filling back
		value = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pback[i][j] = -1;
				value++;
			}
		}
	}//--------------------------------------------end of Sukodu constructor

	void showState()
	{
		cout << "------------face------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << face[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------left------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << left[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------right------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << right[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------down------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << down[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------up------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << up[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------back------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << back[i][j] << " ";
			}
			cout << endl;
		}
	}//---------------------------------------------------------------end of states printing

	 //------------------------------------------------------------------------------------------
	void showpState()
	{
		cout << "------------face------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << pface[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------left------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << pleft[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------right------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << pright[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------down------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << pdown[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------up------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << pup[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------back------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << pback[i][j] << " ";
			}
			cout << endl;
		}
	}//---------------------------------------------------------------end of states printing parent

	 //------------------------------------------------------- moves
	 //-------------------------------------------------------------------rotation anticlockwise

	void rotateMatrixanti(int mat[][3])
	{
		// Consider all squares one by one
		int N = 3;
		for (int x = 0; x < N / 2; x++)
		{
			// Consider elements in group of 4 in 
			// current square
			for (int y = x; y < N - x - 1; y++)
			{
				// store current cell in temp variable
				int temp = mat[x][y];

				// move values from right to top
				mat[x][y] = mat[y][N - 1 - x];

				// move values from bottom to right
				mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

				// move values from left to bottom
				mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

				// assign temp to left
				mat[N - 1 - y][x] = temp;
			}
		}
	}
	//--------------------------------------------------------------------------------rotation clockwise
	void rotateMatrix(int arr[][3])
	{
		int temp = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				temp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = temp;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3 / 2; j++)
			{
				temp = arr[i][j];
				arr[i][j] = arr[i][3 - 1 - j];
				arr[i][3 - 1 - j] = temp;
			}
		}
	}//----------------------------------------------------------end of rotation

	 //((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((



	 //-------------------------------------------------------------face turing move
	void faceTurnClockwise(Suduku & s)
	{



		//Suduku temp;

		ParentChange(s);
		move = "fc";
		int temp2[3];
		rotateMatrix(s.face);
		temp2[0] = left[0][2];
		temp2[1] = left[1][2];
		temp2[2] = left[2][2];

		//-------------------------
		left[0][2] = down[0][0];
		left[1][2] = down[0][1];
		left[2][2] = down[0][2];
		//------------------------
		down[0][0] = right[2][0];
		down[0][1] = right[1][0];
		down[0][2] = right[0][0];

		//------------------------
		right[0][0] = up[2][0];
		right[1][0] = up[2][1];
		right[2][0] = up[2][2];

		//------------------------
		up[2][0] = temp2[2];
		up[2][1] = temp2[1];
		up[2][2] = temp2[0];


	}//----------------------------------------------------------------end of face turn clockwise



	 //-------------------------------------------------------------face turing move Anti
	void faceTurnAntiClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "fi";
		int temp2[3];
		rotateMatrixanti(s.face);
		temp2[0] = left[0][2];
		temp2[1] = left[1][2];
		temp2[2] = left[2][2];

		//-------------------------
		left[0][2] = up[2][2];
		left[1][2] = up[2][1];
		left[2][2] = up[2][0];
		//------------------------
		up[2][2] = right[2][0];
		up[2][1] = right[1][0];
		up[2][0] = right[0][0];

		//------------------------

		right[2][0] = down[0][0];
		right[1][0] = down[0][1];
		right[0][0] = down[0][2];

		//------------------------


		down[0][0] = temp2[0];
		down[0][1] = temp2[1];
		down[0][2] = temp2[2];



	}//----------------------------------------------------------------end of face turn Anti clockwise



	 //-------------------------------------------------------------left turing move
	void leftTurnClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "lc";
		int temp2[3];
		rotateMatrix(s.left);
		temp2[0] = back[0][2];
		temp2[1] = back[1][2];
		temp2[2] = back[2][2];

		//-------------------------

		back[0][2] = down[2][0];
		back[1][2] = down[1][0];
		back[2][2] = down[0][0];


		//------------------------

		down[2][0] = face[2][0];
		down[1][0] = face[1][0];
		down[0][0] = face[0][0];



		//------------------------
		face[2][0] = up[2][0];
		face[1][0] = up[1][0];
		face[0][0] = up[0][0];
		//------------------------
		up[2][0] = temp2[0];
		up[1][0] = temp2[1];
		up[0][0] = temp2[2];


	}//----------------------------------------------------------------end of left turn clockwise


	 //-------------------------------------------------------------left turing move
	void leftTurnAntiClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "li";
		int temp2[3];
		rotateMatrixanti(s.left);
		temp2[0] = back[0][2];
		temp2[1] = back[1][2];
		temp2[2] = back[2][2];

		//-------------------------

		back[0][2] = up[2][0];
		back[1][2] = up[1][0];
		back[2][2] = up[0][0];


		//------------------------

		up[2][0] = face[2][0];
		up[1][0] = face[1][0];
		up[0][0] = face[0][0];



		//------------------------

		face[2][0] = down[2][0];
		face[1][0] = down[1][0];
		face[0][0] = down[0][0];


		//------------------------

		down[2][0] = temp2[0];
		down[1][0] = temp2[1];
		down[0][0] = temp2[2];

	}//----------------------------------------------------------------end of left turn Anti clockwise

	 //-------------------------------------------------------------right turing move
	void rightTurnClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "rc";
		int temp2[3];
		rotateMatrix(s.right);
		temp2[0] = face[0][2];
		temp2[1] = face[1][2];
		temp2[2] = face[2][2];

		//-------------------------
		face[0][2] = down[0][2];
		face[1][2] = down[1][2];
		face[2][2] = down[2][2];



		//------------------------

		down[0][2] = back[2][0];
		down[1][2] = back[1][0];
		down[2][2] = back[0][0];



		//------------------------

		back[2][0] = up[0][2];
		back[1][0] = up[1][2];
		back[0][0] = up[2][2];


		//------------------------
		up[0][2] = temp2[0];
		up[1][2] = temp2[1];
		up[2][2] = temp2[2];


	}//----------------------------------------------------------------end of right turn clockwise



	 //-------------------------------------------------------------right turing move
	void rightTurnAntiClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "ri";
		int temp2[3];
		rotateMatrixanti(s.right);
		temp2[0] = face[0][2];
		temp2[1] = face[1][2];
		temp2[2] = face[2][2];

		//-------------------------
		face[0][2] = up[0][2];
		face[1][2] = up[1][2];
		face[2][2] = up[2][2];



		//------------------------

		up[0][2] = back[2][0];
		up[1][2] = back[1][0];
		up[2][2] = back[0][0];



		//------------------------

		back[2][0] = down[0][2];
		back[1][0] = down[1][2];
		back[0][0] = down[2][2];

		//------------------------

		down[0][2] = temp2[0];
		down[1][2] = temp2[1];
		down[2][2] = temp2[2];

	}//----------------------------------------------------------------end of right turn Anti clockwise

	 //-------------------------------------------------------------back turing move
	void backTurnClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "bc";
		int temp2[3];
		rotateMatrix(s.back);
		temp2[0] = right[0][2];
		temp2[1] = right[1][2];
		temp2[2] = right[2][2];

		//-------------------------
		right[0][2] = down[2][2];
		right[1][2] = down[2][1];
		right[2][2] = down[2][0];



		//------------------------

		down[2][2] = left[2][0];
		down[2][1] = left[1][0];
		down[2][0] = left[0][0];


		//------------------------

		left[2][0] = up[0][0];
		left[1][0] = up[0][1];
		left[0][0] = up[0][2];


		//------------------------
		up[0][0] = temp2[0];
		up[0][1] = temp2[1];
		up[0][2] = temp2[2];


	}//----------------------------------------------------------------end of back turn clockwise


	 //-------------------------------------------------------------back turing move
	void backTurnAntiClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "bi";
		int temp2[3];
		rotateMatrixanti(s.back);
		temp2[0] = right[0][2];
		temp2[1] = right[1][2];
		temp2[2] = right[2][2];

		//-------------------------
		right[0][2] = up[0][0];
		right[1][2] = up[0][1];
		right[2][2] = up[0][2];



		//------------------------

		up[0][0] = left[2][0];
		up[0][1] = left[1][0];
		up[0][2] = left[0][0];


		//------------------------

		left[2][0] = down[2][2];
		left[1][0] = down[2][1];
		left[0][0] = down[2][0];


		//------------------------

		down[2][2] = temp2[0];
		down[2][1] = temp2[1];
		down[2][0] = temp2[2];


	}//----------------------------------------------------------------end of back turn Anti clockwise

	 //-------------------------------------------------------------up turing move
	void upTurnClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "uc";
		int temp2[3];
		rotateMatrix(s.up);
		temp2[0] = left[0][0];
		temp2[1] = left[0][1];
		temp2[2] = left[0][2];

		//-------------------------

		left[0][0] = face[0][0];
		left[0][1] = face[0][1];
		left[0][2] = face[0][2];



		//------------------------

		face[0][0] = right[0][0];
		face[0][1] = right[0][1];
		face[0][2] = right[0][2];


		//------------------------

		right[0][0] = back[0][0];
		right[0][1] = back[0][1];
		right[0][2] = back[0][2];


		//------------------------

		back[0][0] = temp2[0];
		back[0][1] = temp2[1];
		back[0][2] = temp2[2];


	}//----------------------------------------------------------------end of up turn clockwise

	 //-------------------------------------------------------------up turing move
	void upTurnAntiClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "ui";
		int temp2[3];
		rotateMatrixanti(s.up);
		temp2[0] = left[0][0];
		temp2[1] = left[0][1];
		temp2[2] = left[0][2];

		//-------------------------

		left[0][0] = back[0][0];
		left[0][1] = back[0][1];
		left[0][2] = back[0][2];



		//------------------------

		back[0][0] = right[0][0];
		back[0][1] = right[0][1];
		back[0][2] = right[0][2];


		//------------------------

		right[0][0] = face[0][0];
		right[0][1] = face[0][1];
		right[0][2] = face[0][2];


		//------------------------

		face[0][0] = temp2[0];
		face[0][1] = temp2[1];
		face[0][2] = temp2[2];


	}//----------------------------------------------------------------end of up turn Anti clockwise



	 //-------------------------------------------------------------down turing move
	void downTurnClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "dc";
		int temp2[3];
		rotateMatrix(s.down);
		temp2[0] = left[2][2];
		temp2[1] = left[2][1];
		temp2[2] = left[2][0];

		//-------------------------

		left[2][2] = back[2][2];
		left[2][1] = back[2][1];
		left[2][0] = back[2][0];



		//------------------------

		back[2][2] = right[2][2];
		back[2][1] = right[2][1];
		back[2][0] = right[2][0];


		//------------------------

		right[2][2] = face[2][2];
		right[2][1] = face[2][1];
		right[2][0] = face[2][0];


		//------------------------

		face[2][2] = temp2[0];
		face[2][1] = temp2[1];
		face[2][0] = temp2[2];


	}//----------------------------------------------------------------end of down turn clockwise



	 //-------------------------------------------------------------down turing move
	void downTurnAntiClockwise(Suduku & s)
	{
		//Suduku temp;
		ParentChange(s);
		move = "di";
		int temp2[3];
		rotateMatrixanti(s.down);
		temp2[0] = left[2][2];
		temp2[1] = left[2][1];
		temp2[2] = left[2][0];

		//-------------------------

		left[2][2] = face[2][2];
		left[2][1] = face[2][1];
		left[2][0] = face[2][0];


		//------------------------

		face[2][2] = right[2][2];
		face[2][1] = right[2][1];
		face[2][0] = right[2][0];


		//------------------------

		right[2][2] = back[2][2];
		right[2][1] = back[2][1];
		right[2][0] = back[2][0];


		//------------------------

		back[2][2] = temp2[0];
		back[2][1] = temp2[1];
		back[2][0] = temp2[2];


	}//----------------------------------------------------------------end of down turn Anti clockwise
	void ParentChange(Suduku & s)
	{

		//________________________________________________________

		//----------------------------------------------------------------filling face

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pface[i][j] = s.face[i][j];

			}
		}

		//----------------------------------------------------------------filling left

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pleft[i][j] = s.left[i][j];

			}
		}

		//----------------------------------------------------------------filling right

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pright[i][j] = s.right[i][j];

			}
		}


		//----------------------------------------------------------------filling down

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pdown[i][j] = s.down[i][j];

			}
		}

		//----------------------------------------------------------------filling up

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pup[i][j] = s.up[i][j];

			}
		}

		//----------------------------------------------------------------filling back

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pback[i][j] = s.back[i][j];

			}
		}


		//________________________________________________________

	}

	bool isGoal(Suduku & s)
	{
		bool t1, t2, t3, t4, t5, t6;
		//----------------------------checking face

		if ((s.face[0][0] == 1 && s.face[0][1] == 2 && s.face[0][2] == 3 && s.face[1][0] == 4 && s.face[1][1] == 5 && s.face[1][2] == 6 && s.face[2][0] == 7 && s.face[2][1] == 8 && s.face[2][2] == 9) || (s.face[2][0] == 1 && s.face[1][0] == 2 && s.face[0][0] == 3 && s.face[2][1] == 4 && s.face[1][1] == 5 && s.face[0][1] == 6 && s.face[2][2] == 7 && s.face[1][2] == 8 && s.face[0][2] == 9) || (s.face[0][2] == 1 && s.face[1][2] == 2 && s.face[2][2] == 3 && s.face[0][1] == 4 && s.face[1][1] == 5 && s.face[2][1] == 6 && s.face[0][0] == 7 && s.face[1][0] == 8 && s.face[2][0] == 9) || (s.face[2][2] == 1 && s.face[2][1] == 2 && s.face[2][0] == 3 && s.face[1][2] == 4 && s.face[1][1] == 5 && s.face[1][0] == 6 && s.face[0][2] == 7 && s.face[0][1] == 8 && s.face[0][0] == 9))
		{
			t1 = true;
		}
		else
		{
			t1 = false;
		}

		//----------------------------checking left

		if ((s.left[0][0] == 1 && s.left[0][1] == 2 && s.left[0][2] == 3 && s.left[1][0] == 4 && s.left[1][1] == 5 && s.left[1][2] == 6 && s.left[2][0] == 7 && s.left[2][1] == 8 && s.left[2][2] == 9) || (s.left[2][0] == 1 && s.left[1][0] == 2 && s.left[0][0] == 3 && s.left[2][1] == 4 && s.left[1][1] == 5 && s.left[0][1] == 6 && s.left[2][2] == 7 && s.left[1][2] == 8 && s.left[0][2] == 9) || (s.left[0][2] == 1 && s.left[1][2] == 2 && s.left[2][2] == 3 && s.left[0][1] == 4 && s.left[1][1] == 5 && s.left[2][1] == 6 && s.left[0][0] == 7 && s.left[1][0] == 8 && s.left[2][0] == 9) || (s.left[2][2] == 1 && s.left[2][1] == 2 && s.left[2][0] == 3 && s.left[1][2] == 4 && s.left[1][1] == 5 && s.left[1][0] == 6 && s.left[0][2] == 7 && s.left[0][1] == 8 && s.left[0][0] == 9))
		{
			t2 = true;
		}
		else
		{
			t2 = false;
		}

		//----------------------------checking right

		if ((s.right[0][0] == 1 && s.right[0][1] == 2 && s.right[0][2] == 3 && s.right[1][0] == 4 && s.right[1][1] == 5 && s.right[1][2] == 6 && s.right[2][0] == 7 && s.right[2][1] == 8 && s.right[2][2] == 9) || (s.right[2][0] == 1 && s.right[1][0] == 2 && s.right[0][0] == 3 && s.right[2][1] == 4 && s.right[1][1] == 5 && s.right[0][1] == 6 && s.right[2][2] == 7 && s.right[1][2] == 8 && s.right[0][2] == 9) || (s.right[0][2] == 1 && s.right[1][2] == 2 && s.right[2][2] == 3 && s.right[0][1] == 4 && s.right[1][1] == 5 && s.right[2][1] == 6 && s.right[0][0] == 7 && s.right[1][0] == 8 && s.right[2][0] == 9) || (s.right[2][2] == 1 && s.right[2][1] == 2 && s.right[2][0] == 3 && s.right[1][2] == 4 && s.right[1][1] == 5 && s.right[1][0] == 6 && s.right[0][2] == 7 && s.right[0][1] == 8 && s.right[0][0] == 9))
		{
			t3 = true;
		}
		else
		{
			t3 = false;
		}

		//----------------------------checking up

		if ((s.up[0][0] == 1 && s.up[0][1] == 2 && s.up[0][2] == 3 && s.up[1][0] == 4 && s.up[1][1] == 5 && s.up[1][2] == 6 && s.up[2][0] == 7 && s.up[2][1] == 8 && s.up[2][2] == 9) || (s.up[2][0] == 1 && s.up[1][0] == 2 && s.up[0][0] == 3 && s.up[2][1] == 4 && s.up[1][1] == 5 && s.up[0][1] == 6 && s.up[2][2] == 7 && s.up[1][2] == 8 && s.up[0][2] == 9) || (s.up[0][2] == 1 && s.up[1][2] == 2 && s.up[2][2] == 3 && s.up[0][1] == 4 && s.up[1][1] == 5 && s.up[2][1] == 6 && s.up[0][0] == 7 && s.up[1][0] == 8 && s.up[2][0] == 9) || (s.up[2][2] == 1 && s.up[2][1] == 2 && s.up[2][0] == 3 && s.up[1][2] == 4 && s.up[1][1] == 5 && s.up[1][0] == 6 && s.up[0][2] == 7 && s.up[0][1] == 8 && s.up[0][0] == 9))
		{
			t4 = true;
		}
		else
		{
			t4 = false;
		}

		//----------------------------checking down

		if ((s.down[0][0] == 1 && s.down[0][1] == 2 && s.down[0][2] == 3 && s.down[1][0] == 4 && s.down[1][1] == 5 && s.down[1][2] == 6 && s.down[2][0] == 7 && s.down[2][1] == 8 && s.down[2][2] == 9) || (s.down[2][0] == 1 && s.down[1][0] == 2 && s.down[0][0] == 3 && s.down[2][1] == 4 && s.down[1][1] == 5 && s.down[0][1] == 6 && s.down[2][2] == 7 && s.down[1][2] == 8 && s.down[0][2] == 9) || (s.down[0][2] == 1 && s.down[1][2] == 2 && s.down[2][2] == 3 && s.down[0][1] == 4 && s.down[1][1] == 5 && s.down[2][1] == 6 && s.down[0][0] == 7 && s.down[1][0] == 8 && s.down[2][0] == 9) || (s.down[2][2] == 1 && s.down[2][1] == 2 && s.down[2][0] == 3 && s.down[1][2] == 4 && s.down[1][1] == 5 && s.down[1][0] == 6 && s.down[0][2] == 7 && s.down[0][1] == 8 && s.down[0][0] == 9))
		{
			t5 = true;
		}
		else
		{
			t5 = false;
		}

		//----------------------------checking back

		if ((s.back[0][0] == 1 && s.back[0][1] == 2 && s.back[0][2] == 3 && s.back[1][0] == 4 && s.back[1][1] == 5 && s.back[1][2] == 6 && s.back[2][0] == 7 && s.back[2][1] == 8 && s.back[2][2] == 9) || (s.back[2][0] == 1 && s.back[1][0] == 2 && s.back[0][0] == 3 && s.back[2][1] == 4 && s.back[1][1] == 5 && s.back[0][1] == 6 && s.back[2][2] == 7 && s.back[1][2] == 8 && s.back[0][2] == 9) || (s.back[0][2] == 1 && s.back[1][2] == 2 && s.back[2][2] == 3 && s.back[0][1] == 4 && s.back[1][1] == 5 && s.back[2][1] == 6 && s.back[0][0] == 7 && s.back[1][0] == 8 && s.back[2][0] == 9) || (s.back[2][2] == 1 && s.back[2][1] == 2 && s.back[2][0] == 3 && s.back[1][2] == 4 && s.back[1][1] == 5 && s.back[1][0] == 6 && s.back[0][2] == 7 && s.back[0][1] == 8 && s.back[0][0] == 9))
		{
			t6 = true;
		}
		else
		{
			t6 = false;
		}

		return (t1&t2&t3&t4&t5&t6);
	}
	//-------------------------------------------------------------------------------------------is equal
	bool isIqual(Suduku & s1, Suduku & s2)
	{



		//________________________________________________________

		//----------------------------------------------------------------Checking face

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1.face[i][j] != s2.face[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking left

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1.left[i][j] != s2.left[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking right

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1.right[i][j] != s2.right[i][j])
				{
					return false;
				}

			}
		}


		//----------------------------------------------------------------Checking down

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1.down[i][j] != s2.down[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking up

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1.up[i][j] != s2.up[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking back

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1.back[i][j] != s2.back[i][j])
				{
					return false;
				}

			}
		}


		//________________________________________________________

		return true;

	}

	//-------------------------------------------------------------------------------------------existed
	bool existbefore(iterable_queue<Suduku> & q, vector<Suduku> & exp, Suduku & s)
	{
		bool t1, t2 = false;
		//-------------------------------------------------------------------vector
		for (int i = 0; i < exp.size(); i++)
		{
			if (isIqual(exp[i], s) == true)
			{
				t1 = true;
				break;
			}
			else
			{
				t1 = false;
			}

		}

		//-------------------------------------------------------------------queue
		if (t1 == true)
		{
			return t1;
		}

		for (auto it = q.begin(); it != q.end(); ++it)
		{


			if (isIqual(*it, s) == true)
			{
				t2 = true;
				break;
			}
			else
			{
				t2 = false;
			}
		}

		return (t1 | t2);

	}
	//-------------------------------------------------------------------------------------------end of existed

	void BreathFirstSearch(Suduku & s)
	{
		iterable_queue<Suduku> que;
		//queue<Suduku> que;
		vector<Suduku> explored;
		s.move = "";
		//________________________________________________________

		//----------------------------------------------------------------filling face

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pface[i][j] = -1;

			}
		}

		//----------------------------------------------------------------filling left

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pleft[i][j] = -1;

			}
		}

		//----------------------------------------------------------------filling right

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pright[i][j] = -1;

			}
		}


		//----------------------------------------------------------------filling down

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pdown[i][j] = -1;

			}
		}

		//----------------------------------------------------------------filling up

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pup[i][j] = -1;

			}
		}

		//----------------------------------------------------------------filling back

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s.pback[i][j] = -1;

			}
		}


		//________________________________________________________

		que.push(s);
		Suduku temp;
		bool found = false;
		//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ

		while (que.size() != 0)
		{
			temp = que.front();
			que.pop();
			explored.push_back(temp);
			if (isGoal(temp) == true)
			{
				found = true;
				break;
			}
			//++++++++++++++++++++++
			s = temp;
			//----------------------------------------------------------face
			faceTurnClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);

			faceTurnAntiClockwise(s);

			faceTurnAntiClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			faceTurnClockwise(s);

			//----------------------------------------------------------back
			backTurnClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			backTurnAntiClockwise(s);

			backTurnAntiClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			backTurnClockwise(s);
			//----------------------------------------------------------left
			leftTurnClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			leftTurnAntiClockwise(s);

			leftTurnAntiClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			leftTurnClockwise(s);
			//----------------------------------------------------------right
			rightTurnClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			rightTurnAntiClockwise(s);

			rightTurnAntiClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			rightTurnClockwise(s);
			//-----------------------------------------------------------up 
			upTurnClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			upTurnAntiClockwise(s);

			upTurnAntiClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			upTurnClockwise(s);
			//----------------------------------------------------------down
			downTurnClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			downTurnAntiClockwise(s);

			downTurnAntiClockwise(s);
			if (existbefore(que, explored, s) == false)
				que.push(s);
			downTurnClockwise(s);


		}//----------------------------------------end of while que.size()

		if (found == true)
		{
			string path;
			int face1[3][3];
			int left1[3][3];
			int right1[3][3];
			int up1[3][3];
			int down1[3][3];
			int back1[3][3];

			int index = explored.size() - 1;
			copy_p_in_a(explored[index], face1, left1, right1, up1, down1, back1);

			path = path + explored[index].move;

			while (index > 0)
			{
				index = index - 1;
				if (check_p_s(explored[index], face1, left1, right1, up1, down1, back1) == true)
				{
					path = path + explored[index].move;
					copy_p_in_a(explored[index], face1, left1, right1, up1, down1, back1);
				}
			}
			cout << path;
		}

		//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
		/*string path;
		Suduku temp5;
		Suduku Parent;
		Suduku Son;
		bool t5 = true;
		bool t6 = false;
		if(found == true)
		{
		if(explored.size() == 1)
		{
		t5 = false;
		}
		int k = explored.size()-1;
		temp5 = explored[k];

		while(t6 == false && t5 != false)
		{
		if(temp5.pface[0][0] == -1)
		{
		break;
		}

		else
		{
		path = path + (temp5.move);
		}

		}

		}
		cout<<path;*/

		//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
	}

	//------------------------------------------------parentcopyinarr

	void copy_p_in_a(Suduku & s, int face1[][3], int left1[][3], int right1[][3], int up1[][3], int down1[][3], int back1[][3])
	{
		//________________________________________________________

		//----------------------------------------------------------------filling face

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				face1[i][j] = s.pface[i][j];

			}
		}

		//----------------------------------------------------------------filling left

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				left1[i][j] = s.pleft[i][j];

			}
		}

		//----------------------------------------------------------------filling right

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				right1[i][j] = s.pright[i][j];

			}
		}


		//----------------------------------------------------------------filling down

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				down1[i][j] = s.pdown[i][j];

			}
		}

		//----------------------------------------------------------------filling up

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				up1[i][j] = s.pup[i][j];

			}
		}

		//----------------------------------------------------------------filling back

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				back1[i][j] = s.pback[i][j];

			}
		}


		//________________________________________________________

	}

	bool check_p_s(Suduku & s, int face1[][3], int left1[][3], int right1[][3], int up1[][3], int down1[][3], int back1[][3])
	{
		//________________________________________________________

		//----------------------------------------------------------------Checking face

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s.face[i][j] != face1[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking left

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s.left[i][j] != left1[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking right

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s.right[i][j] != right1[i][j])
				{
					return false;
				}

			}
		}


		//----------------------------------------------------------------Checking down

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s.down[i][j] != down1[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking up

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s.up[i][j] != up1[i][j])
				{
					return false;
				}

			}
		}

		//----------------------------------------------------------------Checking back

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s.back[i][j] != back1[i][j])
				{
					return false;
				}

			}
		}


		//________________________________________________________

		return true;
	}


	//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

	//9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
	void iBFS(Suduku & s)
	{
		iterable_queue<Instance> que;
		Instance I;

		//queue<Suduku> que;
		vector<Instance> explored;
		if (isGoal(s))
		{
			return;
		}
		I.Ins = "f";
		que.push(I);

		I.Ins = "g";
		que.push(I);

		I.Ins = "b";
		que.push(I);

		I.Ins = "n";
		que.push(I);

		I.Ins = "l";
		que.push(I);

		I.Ins = "k";
		que.push(I);

		I.Ins = "r";
		que.push(I);

		I.Ins = "t";
		que.push(I);

		I.Ins = "u";
		que.push(I);

		I.Ins = "i";
		que.push(I);

		I.Ins = "d";
		que.push(I);

		I.Ins = "s";
		que.push(I);
		Instance temp;
		string mover;
		string imover;
		while (que.size() != 0)
		{
			I = que.front();
			que.pop();
			mover = "";
			imover = "";
			for (int i = 0; i < I.Ins.size(); i++)
			{
				//---------------------------------1
				if (I.Ins[i] == 'f')
				{
					faceTurnClockwise(s);
					imover = imover + "g";
				}
				//---------------------------------2
				else if (I.Ins[i] == 'b')
				{
					backTurnClockwise(s);
					imover = imover + "n";
				}
				//---------------------------------3
				else if (I.Ins[i] == 'l')
				{
					leftTurnClockwise(s);
					imover = imover + "k";
				}
				//---------------------------------4
				else if (I.Ins[i] == 'r')
				{
					rightTurnClockwise(s);
					imover = imover + "t";
				}
				//---------------------------------5
				else if (I.Ins[i] == 'u')
				{
					upTurnClockwise(s);
					imover = imover + "i";
				}
				//---------------------------------6
				else if (I.Ins[i] == 'd')
				{
					downTurnClockwise(s);
					imover = imover + "s";
				}
				//---------------------------------7
				else if (I.Ins[i] == 'g')
				{
					faceTurnAntiClockwise(s);
					imover = imover + "f";
				}
				//---------------------------------8
				else if (I.Ins[i] == 'n')
				{
					backTurnAntiClockwise(s);
					imover = imover + "b";
				}
				//---------------------------------9
				else if (I.Ins[i] == 'k')
				{
					leftTurnAntiClockwise(s);
					imover = imover + "l";
				}
				//---------------------------------10
				else if (I.Ins[i] == 't')
				{
					rightTurnAntiClockwise(s);
					imover = imover + "r";
				}
				//---------------------------------11
				else if (I.Ins[i] == 'i')
				{
					upTurnAntiClockwise(s);
					imover = imover + "u";
				}
				//---------------------------------12
				else if (I.Ins[i] == 's')
				{
					downTurnAntiClockwise(s);
					imover = imover + "d";
				}
				//-------------------------------


			}//--------------------------end of for
			if (isGoal(s) == true)
			{
				cout << I.Ins;
				break;
			}
			else
			{
				//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
				for (int i = imover.size() - 1; i >= 0; i--)
				{
					//---------------------------------1
					if (imover[i] == 'f')
					{
						faceTurnClockwise(s);

					}
					//---------------------------------2
					else if (imover[i] == 'b')
					{
						backTurnClockwise(s);

					}
					//---------------------------------3
					else if (imover[i] == 'l')
					{
						leftTurnClockwise(s);

					}
					//---------------------------------4
					else if (imover[i] == 'r')
					{
						rightTurnClockwise(s);

					}
					//---------------------------------5
					else if (imover[i] == 'u')
					{
						upTurnClockwise(s);

					}
					//---------------------------------6
					else if (imover[i] == 'd')
					{
						downTurnClockwise(s);

					}
					//---------------------------------7
					else if (imover[i] == 'g')
					{
						faceTurnAntiClockwise(s);

					}
					//---------------------------------8
					else if (imover[i] == 'n')
					{
						backTurnAntiClockwise(s);

					}
					//---------------------------------9
					else if (imover[i] == 'k')
					{
						leftTurnAntiClockwise(s);

					}
					//---------------------------------10
					else if (imover[i] == 't')
					{
						rightTurnAntiClockwise(s);

					}
					//---------------------------------11
					else if (imover[i] == 'i')
					{
						upTurnAntiClockwise(s);

					}
					//---------------------------------12
					else if (imover[i] == 's')
					{
						downTurnAntiClockwise(s);

					}
					//-------------------------------


				}//--------------------------end of for

				 //00000000000000000000000000

				I.Ins = I.Ins + "f";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "g";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "b";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "n";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "l";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "k";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "r";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "t";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "u";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "i";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "d";
				que.push(I);

				I.Ins.pop_back();
				I.Ins = I.Ins + "s";
				que.push(I);

				//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
			}


		}//----------------------------------end of while

	}//--------------------------------------------end of function
};


//bool operator<(const Suduku& lhs, const Suduku& rhs)
//{
//  return lhs.age < rhs.age;
//}
//
//struct LessThanByAge
//{
//  bool operator()(const Person& lhs, const Person& rhs) const
//  {
//    return lhs.age < rhs.age;
//  }
//};



void menu()
{
	cout << endl;
	cout << "face clockwise      represented by f" << endl;
	cout << "back clockwise      represented by b" << endl;
	cout << "left clockwise      represented by l" << endl;
	cout << "right clockwise     represented by r" << endl;
	cout << "up   clockwise      represented by u" << endl;
	cout << "down clockwise      represented by d" << endl;
	//---
	cout << "face ANticlockwise  represented by g" << endl;
	cout << "back ANticlockwise  represented by n" << endl;
	cout << "left ANticlockwise  represented by k" << endl;
	cout << "right ANticlockwise represented by t" << endl;
	cout << "up   ANticlockwise  represented by i" << endl;
	cout << "down ANticlockwise  represented by s" << endl;
	cout << endl;
}

void main()
{
	menu();
	Suduku a, b;
	a.faceTurnClockwise(a);
	a.faceTurnClockwise(a);

	a.backTurnClockwise(a);
	a.faceTurnAntiClockwise(a);
	a.leftTurnClockwise(a);
	a.upTurnAntiClockwise(a);
	a.upTurnAntiClockwise(a);

	a.iBFS(a);

	//a.BreathFirstSearch(a);
	//a.showState();
}