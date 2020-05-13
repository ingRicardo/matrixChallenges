#include <iostream>
using namespace std;
bool isValid(int **grid, int row, int col, bool **visited, int h, int w )
{
	
	return row >-1 && row < h && col >-1 &&  col < w && !visited[row][col] && grid[row][col] == 1; 
}

class Position{
	public:
	int x,y;
	Position(int xx, int yy)
	{
		x=xx;
		y=yy;
	}
	Position(){}
	int getX(){
		return x;
	}

	int getY(){
		return y;
	}

};

struct node
{
	Position data;
	node *next;

	node(): data(data) {}	

};

class list
{
	private:
	node *head, *tail;
	public:
	list()
	{
		head=NULL;
		tail=NULL;

	}


void createnode(Position value)
{

	node *temp = new node;
	temp->data=value;
	temp->next=NULL;
	if(head == NULL)
	{
		head= temp;
		tail = temp;
		temp = NULL;
	}
	else 
	{
		tail->next=temp;
		tail=temp;
	}
}
bool isEmpty()
{
	node *temp = new node;
	temp=head;
	if (temp == NULL)
		return true;

return false;
}
void display()
{
	node *temp = new node;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data.getX()<< "\t"<<temp->data.getY()<<endl;
		temp=temp->next;
	}
}

void insert_start(Position value)
{
	node *temp = new node;
	temp->data=value;
	temp->next=head;
	head=temp;

}

void insert_position(int pos, Position value)
{

	node *pre = new node;
	node *cur= new node;
	node *temp= new node;
	cur = head;
	for(int i=1;i<pos;i++)
	{

		pre=cur;
		cur=cur->next;

	}
	temp->data=value;
	pre->next=temp;
	temp->next=cur;
}

void delete_first()
{
	node *temp= new node;
	temp=head;
	head=head->next;
	delete temp;
}

void delete_last()
{

	node *current= new node;
	node *previous= new node;
	current=head;

	while(current->next!= NULL)
	{
		previous=current;
		current=current->next;
	}
	tail=previous;
	previous->next = NULL;
	delete current;
}

void delete_position(int pos)
{

	node *current= new node;
	node *previous= new node;
	current= head;
	for(int i=1; i<pos; i++)
	{
		previous = current;
		current=current->next;

	}
	previous->next = current->next;
}

   node front()
   {
	   node *temp = new node;
	   temp = head;

	   return *temp;
   }
};

void printVist(bool **visited, int hw)
{

	for(int row =0; row<hw; row++)
	{

		for(int col=0; col<hw; col++)
		{

			cout << " "<<visited[row][col];
		}
		cout <<endl;

	}
}

void printAux(int** auxgrid, int hw)
{

	for (int row = 0; row < hw; row++)
	{

		for (int col = 0; col < hw; col++)
		{

			cout << " " << auxgrid[row][col];
		}
		cout << endl;

	}
}


int BFS (int **grid, int hw, Position pos, bool **visited)
{
  int burn_t=0;
	
int deltaCol[]= {1,0,-1, 0};
int deltaRow[]= {0,1, 0,-1};

int deltaSize = sizeof(deltaRow)/ sizeof(deltaRow[0]);

	//visited[pos.getX()][pos.getY()]=true;

	list link;
	link.createnode(pos);
	int nextCol =0,nextRow =0;

	while(!link.isEmpty())
	{
		node curr = link.front();
		Position current = curr.data;
		link.delete_first();
	
		for(int indx =0; indx < deltaSize; indx++ ){

			nextCol = current.getY() + deltaCol[indx];
			nextRow = current.getX() + deltaRow[indx];
			
			if(isValid(grid, nextRow, nextCol, visited, hw, hw ) ){
				Position newPos(nextRow, nextCol);
				link.createnode(newPos);
				visited[newPos.getX()][newPos.getY()] =  true;
				burn_t++;
			}

		}

	}

	return burn_t;
}

int resfun(int **grid, bool **visited, int max_tree, int hw)
{
	// auxgrid to get values from original grid
	int** auxgrid = new int*[hw];
	for (int row = 0; row < hw; row++)
	{
		auxgrid[row] = new int[hw];
		for (int col = 0; col < hw; col++)
			auxgrid[row][col] = grid[row][col];
	}



	//THIS SOLUTION IS JUST TO CUT ONE TREE DOWN , IT NEEDS TO BE WITH TWO TREES CUT DOWN
	int burnt =0;
	int minBurnt =1000;
	bool isCut= false;
	int totaltrees =0;


	for (int row =0; row<hw; row++)
	{
		for(int col =0; col<hw; col++)
		{
			int currone = auxgrid[row][col];
			//cout << "currentone "<< currone<<endl;
			if (currone == 1)
			{
				//cout << "currentone "<< currone<<endl;
				totaltrees++;
				for(int t1 =0; t1<2; t1++)   // cut or not cut the tree 
				{
						//auxgrid[row][col] = 0;
						if(t1 == 0)
						{
						//	cout << " tree cut down ";
								auxgrid[row][col] = 0;
						}
						else
						{
						//	cout << " tree NOT cut down ";
							auxgrid[row][col] = 1;
						}
						for (int row1 =row; row1<hw; row1++)
						{
							for(int col1 =col; col1<hw; col1++)
							{

								int current = auxgrid[row1][col1];
								if (current == 1 )
								{
								//	totaltrees++;

									for(int t =0; t<2; t++)   // cut or not cut the tree 
									{
										if(t == 0)
										{
										//	cout << " tree cut down ";
											auxgrid[row1][col1] = 0;
										}
										else
										{
										//	cout << " tree NOT cut down ";
											auxgrid[row1][col1] = 1;
										}
											

									//	cout << "----aux----"<<endl;
									//	printAux(auxgrid, hw);
										for (int rowx =0; rowx<hw; rowx++)
										{
											for(int colx =0; colx<hw; colx++)
											{
												int current2 = auxgrid[rowx][colx];
												if (current2 == 2)
												{
													Position pos(rowx,colx);
													int b = BFS(auxgrid,hw,pos,visited);
													burnt+= b;
											//			cout << "---BFS----- "<<endl;
											//			printVist(visited, hw);
											//			cout << "b -> "<<b<<endl;
												}
											}	
										}
									//	cout << "burnt "<<burnt<<endl;
										if(burnt < minBurnt)
											minBurnt = burnt;
									//	cout<<" minBurnt "<<minBurnt<<endl;	

										if(t == 0) //if cut down  it brings back 
											auxgrid[row1][col1] = 1;


										burnt=0;
										for (int r = 0; r < hw; r++)
											for (int c = 0; c < hw; c++)
												visited[r][c] = false;
									}
								}//END IF 1 tree


							}//for col1
						}//for row1
						if(t1 == 0) //if cut down  it brings back 
							auxgrid[row][col] = 1;
							//auxgrid[row1][col1] = 1;
													
				}//for t1
				
			}//END IF
		}//for col
	}//for row

	cout << "totaltrees -> "<<totaltrees<< " minBurnt "<< minBurnt<< endl;

	if (minBurnt == 0)
		max_tree=0;
	int ans = totaltrees -max_tree - minBurnt;
	cout << "trees alive "<< ans <<endl;  
	return ans;
}



void wildFire()
{

	freopen("input.txt","r", stdin);
	int T = 0;
	int res =0;
	cin >> T;
	cout << "Test T --->"<< T << endl;
	for (int test_case = 1; test_case <=4; ++test_case)
	{	

		int h,w=0,val=0,max_tree=0;
		cin >> h;
		cin >> max_tree;
		w =h;
		int **grid = new int*[h];
		bool **visited = new bool*[h]; 
		for(int row =0; row<h; row++)
		{
			grid[row] = new int[w];
			visited[row] = new bool[w];
			cout<<endl;
			for(int col=0; col<w; col++)
			{
				cin >> val;

				grid[row][col] = val;
				visited[row][col] = false;
				cout <<val<<" ";

			}

		}
		cout << endl;
		res = resfun(grid, visited,max_tree,w);
		cout << "#" << test_case <<":"<<res<< endl;

	}

	//cout << " start wildFire " << endl;

}
int main()
{
	

	wildFire();
	return 0;
}

