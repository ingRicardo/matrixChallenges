#include <iostream>

using namespace std;

/*

 CUT THE FIRST TREE and combine it cutting another tree

 example max trees that can be cut down = 2

1 0 1 0 0 0 0	X 0 X 0 0 0 0
1 1 1 1 0 0 1	V V V V 0 0 V
0 0 1 2 1 0 1	0 0 V 2 V 0 V
0 0 2 0 0 1 1	0 0 2 0 0 V V
1 0 0 1 0 2 0	1 0 0 1 0 2 0
0 1 1 0 0 1 0	0 1 1 0 0 V 0
0 0 0 1 0 0 0	0 0 0 1 0 0 0

tota trees = 18
2 trees cut down
11 burnt trees
5 trees alive

trees alive = 	    tota trees - trees cut down	 - burnt trees
	5	       18       - 2              - 11


-------------------------------------
1 0 1 0 0 0 0	X 0 1 0 0 0 0
1 1 1 1 0 0 1	X V V V 0 0 V
0 0 1 2 1 0 1	0 0 V 2 V 0 V
0 0 2 0 0 1 1	0 0 2 0 0 V V
1 0 0 1 0 2 0	1 0 0 1 0 2 0
0 1 1 0 0 1 0	0 1 1 0 0 V 0
0 0 0 1 0 0 0	0 0 0 1 0 0 0

total = 18 - 2 - 10
6
---------
---------



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




bool isValid(int **grid, int row, int col, bool **visited, int h, int w )
{
	
	return row >-1 && row < h && col >-1 &&  col < w && !visted[row][col]; 
}

int BFS(int **grid,int row, int col, bool **visited)
{

int burn_t=0;
	
int deltaCol[]= {1,0,-1, 0};
int deltaRow[]= {0,1, 0,-1};

int deltaSize = sizeof(deltaRow)/ sizeof(deltaRow[0]);

	visited[pos.getX()][pos.getY()]=true;

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
			Position newPos(nextRow, nextCol);

			if(isValid(grid,hw,visited,newPos) ){
				link.createnode(newPos);
				visited[newPos.getX()][newPos.getY()] =  true;
				burn_t++;
			}

		}

	}

	return burn_t;
	
}

void func1(int **grid, bool ** visited, int MAX_CUT_DOWN, int res_trees ){

	bool cuttree1 =false;
	bool cuttree2 =false;
	int burnt_trees_acc=0, current=0,current1 =0;
	int total_burnt_trees=0, total_trees=0;
	for (int row =0 ; row < h; row++) //loop start from postion 0,0
	{	
		for (int col =0; col < w; col++)
		{	burnt_trees_acc =0;
			current = grid[row][col];
			if (current == 1 && !visited[row][col])
			{
				total_trees+=1;
				visited[row][col] = true;
				for (int row1 =row ; row1 < h; row1++) //loop start from position 0,1
				{
					for (int col1 =col+1; col1 < w; col1++)	
					{
						current1 = grid[row1][col1];
						if (current2 == 1 && !visited[row1][col1])
						{
							total_trees+=1;
							visited[row1][col1] = true;

						} //end if
				
						if (current2 == 2)
						{
							int burnt_trees = BFS(grid,row1,col1,visited); 
							burnt_trees_acc += burnt_trees;
							total_burnt_trees += burnt_trees_acc;
						}

					}// end col1
				 }//end row1
			}//end if
		}//end col
	}//end row
	res_trees = total_trees - total_burnt_trees - MAX_CUT_DOWN ;

}
*/

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

	//	Position pos(2,3);
	//	int burn_t = BFS(grid,hw, pos, visited);
	//	cout << " bfs "<< burn_t<<endl;

	bool cuttree1 =false;
	bool cuttree2 =false;
	int burnt_trees_acc=0, current1=0,current2 =0;
	int total_burnt_trees=0, total_trees=0;
	/*for (int row =0 ; row < hw; row++) //loop start from postion 0,0
	{	
		for (int col =0; col < hw; col++)
		{	//burnt_trees_acc =0;
			current1 = grid[row][col];
			if  (current1 == 1)
				total_trees+=1;

			if (current1 == 1 && !visited[row][col])
			{
				//grid[row][col] = 0;
				//visited[row][col] = true;
				for (int row1 =row ; row1 < hw; row1++) //loop start from position 0,1
				{
					for (int col1 =col+1; col1 < hw; col1++)	
					{
						current2 = grid[row1][col1];

						if (current2 == 1 &&  !visited[row1][col1]){
							//grid[row1][col1] = 0;	
							//visited[row1][col1] = true;
						}
							

						if (current2 == 2 && !visited[row1][col1])
						{
							
							Position pos(row1,col1);
							int burnt_trees =BFS(grid, hw, pos,visited);
							cout << " burnt_trees -> "<< burnt_trees<<endl; 
							burnt_trees_acc += burnt_trees;
			
						}

					}// end col1
				 }//end row1
			}//end if
			//grid[row][col] = 1;
		}//end col
	}//end row
	*/
	
	// auxgrid to get values from original grid
	int** auxgrid = new int*[hw];
	for (int row = 0; row < hw; row++)
	{
		auxgrid[row] = new int[hw];
		for (int col = 0; col < hw; col++)
			auxgrid[row][col] = grid[row][col];
	}

	cout << "print the aux grid " << endl;
	printAux(auxgrid, hw);
	int down = 0;

	/*
 1 0 1 0 0 0 0
 1 1 1 1 0 0 1
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 0 0 0 0 0
 1 1 1 1 0 0 1
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 1 0 0 0 0
 0 1 1 1 0 0 1
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 1 0 0 0 0
 1 0 1 1 0 0 1
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 1 0 0 0 0
 1 1 0 1 0 0 1
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 1 0 0 0 0
 1 1 1 0 0 0 1
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 1 0 0 0 0
 1 1 1 1 0 0 0
 0 0 1 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0

 0 0 1 0 0 0 0
 1 1 1 1 0 0 1
 0 0 0 2 1 0 1
 0 0 2 0 0 1 1
 1 0 0 1 0 2 0
 0 1 1 0 0 1 0
 0 0 0 1 0 0 0




	*/
	/*int down = 0;
	for (int row = 0; row < hw; row++)
	{
		for (int col = 0; col < hw; col++)
		{
			down = 0;
			if (auxgrid[row][col] == 1)
			{
				down++;
				auxgrid[row][col] = 0;
				for (int row1 = row; row1 < hw; row1++)
				{

					for (int col1 = col+1; col1 < hw; col1++)
					{
						if (auxgrid[row1][col1] == 1 && down < max_tree)
						{
							down++;
							auxgrid[row1][col1] = 0;
							cout << "-----" << endl;
							printAux(auxgrid, hw);
							auxgrid[row1][col1] = 1;
						}
						else if (auxgrid[row1][col1] == 2)
						{
							Position pos(row1, col1);
							int burnt_trees = BFS(auxgrid, hw, pos, visited);


						}
					}


				}
				//break;



			}


		}

		//break;
	}
	*/
	
	/*
		steps
		-find a tree and cut down
		-find next tree and cut down
		-find the fire and starts the BFS
		-find next fire and starts the BFS and so on.
		-bring back the cut down tree(N) and cut the next one(N) and starts again.


		1 0 1 0 0 0 0
		1 1 1 1 0 0 1
		0 0 1 2 1 0 1
		0 0 2 0 0 1 1
		1 0 0 1 0 2 0
		0 1 1 0 0 1 0
		0 0 0 1 0 0 0

		step 1 - found max trees in this case 2 trees where cut down and use the BFS when 2 is found
		0 0 0 0 0 0 0
		v v v v 0 0 v
		0 0 v 2 v 0 v
		0 0 2 0 0 v v
		1 0 0 1 0 2 0
		0 1 1 0 0 v 0
		0 0 0 1 0 0 0

		5 saved trees

		step 2- bring back the trees that where cut down, bring back the visited rows to no visited and cut the next trees

		0 0 v 0 0 0 0
		0 v v v 0 0 v
		0 0 v 2 v 0 v
		0 0 2 0 0 v v
		1 0 0 1 0 2 0
		0 1 1 0 0 v 0
		0 0 0 1 0 0 0

		5 saved trees


		X 0 X 0 0 0 0
		1 1 1 1 0 0 1
		0 0 1 2 1 0 1
		0 0 2 0 0 1 1
		1 0 0 1 0 2 0
		0 1 1 0 0 1 0
		0 0 0 1 0 0 0

		int cc_down=0,acc=0;
		int tmp_row=0,tmp_col=0,saved_trees=-1;
		for row=0
			for col=0
			{		cc_down=0
					if acc>saved_trees
						saved_trees=acc

					if current == 1
						auxgrid = 0
						cc_down+=1;
					for row1= row
					{
						for col1= col+1
						{
							if current == 1 && cc_down < max_tree
								auxgrid = 0
								cc_down+=1;
								//save position
								tmp_row = row1
								tmp_col = col1
							if current == 2
								acc+=BFS(auxgrid,row1,col1,visited);
						}
					}
					//return 1 on the saved position
					auxgrid[tmp_row][tmp_col] = 1;
					//return visited to none visited
					for(int r=0; r<hw; r++)
						for(int c=0; c<hw; c++)
							visited[r][c] = false;
			}
		return saved_trees;
	*/
/*
int cc_down = 0, acc = 0;
int tmp_row = 0, tmp_col = 0, saved_trees = -1;
int tmp_row1 = 0, tmp_col1 = 0;
	for (int row = 0; row<hw; row++)
		for(int col = 0; col<hw; col++)
		{ 
			cc_down = 0;
			int current = auxgrid[row][col];
			if(acc > saved_trees)
				saved_trees = acc;
			acc = 0;
			
			if (current == 1)
			{
				
				auxgrid[row][col] = 0;
				cc_down += 1;
				tmp_row1 = row; tmp_col1 = col;
			}
			for (int row1 = row; row1<hw;row1++)
			{
				for(int col1 = col + 1; col1<hw;col1++)
				{
					int current = auxgrid[row1][col1];
					if (current == 1 && cc_down < max_tree)
					{
						//cout << "cc_down " << cc_down << endl;
						auxgrid[row1][col1] = 0;
						cc_down += 1;
						//save position
						tmp_row = row1;
						tmp_col = col1;
					}
						
					if (current == 2)
					{
						Position pos(row1,col1);
						acc += BFS(auxgrid, hw,pos,visited );
						

					}
						
				}
			}
			//return 1 on the saved position
			auxgrid[tmp_row][tmp_col] = 1;
			auxgrid[tmp_row1][tmp_col1] = 1;


			//cout << "-----------------"<<endl;
			//printVist(visited,hw);


			//return visited to none visited
			for (int r = 0; r < hw; r++)
				for (int c = 0; c < hw; c++)
					visited[r][c] = false;
			
			//cout << "acc "<< acc<<endl;
			acc=0;
		}
	cout << "saved_trees -> " << saved_trees << endl;
	int res_trees = total_trees - burnt_trees_acc - max_tree ;

	cout << " total trees "<<total_trees <<" tota burnt "<< burnt_trees_acc << " max tree "<< max_tree << endl;
		cout << "\n print visited "<<endl;

		printVist(visited, hw);
		
		cout<<endl;  */

	//cut down just one tree

	//THIS SOLUTION IS JUST TO CUT ONE TREE DOWN , IT NEEDS TO BE WITH TWO TREES CUT DOWN
	int burnt =0;
	int minBurnt =1000;
	bool isCut= false;
	int totaltrees =0;
	for (int row =0; row<hw; row++)
	{
		for(int col =0; col<hw; col++)
		{
			int current = auxgrid[row][col];
			if (current == 1 )
			{
				totaltrees++;
				auxgrid[row][col] = 0;
				cout << "----aux----"<<endl;
				printAux(auxgrid, hw);
				for (int row1 =0; row1<hw; row1++)
				{
					for(int col1 =0; col1<hw; col1++)
					{
						int current2 = auxgrid[row1][col1];
						if (current2 == 2)
						{
							Position pos(row1,col1);
							int b = BFS(auxgrid,hw,pos,visited);
							burnt+= b;
								cout << "---BFS----- "<<endl;
								printVist(visited, hw);
								cout << "b -> "<<b<<endl;
						}
					}	
				}
				cout << "burnt "<<burnt<<endl;
				if(burnt < minBurnt)
					minBurnt = burnt;
				cout<<" minBurnt "<<minBurnt<<endl;	
				auxgrid[row][col] = 1;
				burnt=0;
				for (int r = 0; r < hw; r++)
					for (int c = 0; c < hw; c++)
						visited[r][c] = false;

			}//END IF 1 tree
		}
	}

	cout << "totaltrees -> "<<totaltrees<<endl;
	int ans = totaltrees -1 - minBurnt;
	cout << "trees alive "<< ans <<endl;
	return 0;
}



void wildFire()
{
	//freopen("C:\\Users\\SRT\\Repositories\\SoftCer\\matrixChallenges\\visualTests\\Project1\\in.txt","r", stdin);
	freopen("in.txt","r", stdin);
	int T = 0;
	int res =0;
	cin >> T;
	cout << "Test T --->"<< T << endl;
	for (int test_case = 1; test_case <=1; ++test_case)
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

	cout << " start wildFire " << endl;

}
int main()
{
	
	
	 cout << "test riky   mac AAAA  " << endl;
	wildFire();
	return 0;
}

