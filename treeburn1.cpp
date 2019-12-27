#include <iostream>
using namespace std;

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

bool isValid(int **grid, int hw, bool **visited, Position pos){

	return pos.getX() > -1 && pos.getX() < hw && pos.getY() > -1
			&& pos.getY() < hw && grid[pos.getX()][pos.getY()]==1 
			&&!visited[pos.getX()][pos.getY()]; 
}


int** createaux(int ** grid, int hw){
	int **auxgrid = new int*[hw];
	for (int row =0; row < hw; row++){
		auxgrid[row] = new int[hw];
		for(int col =0; col<hw; col++){
			auxgrid[row][col] = grid[row][col];
		}
	}

return auxgrid;
}
int BFS (int **grid, int hw, Position pos, bool **visited)
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
int getAnswer(int **grid, int cutree, int hw, bool **visited){

	int total_t=0,burn_t=0;
	int tbt=0;	

	for(int row =0; row < hw; row ++){
		for(int col =0; col<hw; col++){

			if (grid[row][col] == 2){
				Position pos(row,col);
				burn_t = BFS(grid,hw, pos, visited);
				tbt += burn_t;
			}
			else if ( grid[row][col] == 1){
				total_t++;	

			}
		}
	}
	
	return total_t-tbt;
}

int getAnswerOne(int **grid, int hw, bool **visited, int max ){
    int **auxgrid = createaux(grid,hw);    
        	for(int row =0; row < hw; row ++){
		        for(int col =0; col<hw; col++){
                    if (auxgrid[row][col] == 1){
                        auxgrid[row][col] = 0;
                        int cutOneAns = getAnswer(auxgrid,0,hw,visited);
                        if(cutOneAns > max  ){
                            max = cutOneAns;
                        }
                        for (int i=0; i< hw; i++)
						{
							visited[i] = new bool[hw];
							for (int j = 0; j < hw; j++)
								visited[i][j] = false;
						}
                       auxgrid[row][col] = 1;     
                    }
                }
            }
	  return max;
}

int getAnswerTwo(int **grid, int hw, bool **visited, int max){
	int **auxgrid = createaux(grid,hw);
	for(int rowb =0; rowb< hw; rowb++){
		for(int colb =0; colb < hw; colb++ ){
				if (auxgrid[rowb][colb] == 1 ){
						auxgrid[rowb][colb] = 0;
					for(int row =0; row< hw; row++){
						for(int col =0; col < hw; col++ ){
							if(auxgrid[row][col] == 1){
								auxgrid[row][col] =0;
								int cutOneAns = getAnswer(auxgrid,0,hw,visited);
								if(cutOneAns > max  ){
									max = cutOneAns;
								}
								for (int i=0; i< hw; i++)
								{
									visited[i] = new bool[hw];
									for (int j = 0; j < hw; j++)
										visited[i][j] = false;
								}
								auxgrid[row][col] = 1;
							}// cut 2
						}
					}
					auxgrid[rowb][colb] = 1;
			}//cut 1
		}
	}
   return max;
}

int getMax(int a, int b){
	if (a>b)
		return a;
	return b;
}
int main(){

	freopen("input.txt", "r", stdin);

	int T, hw, num ,cuttree;
	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> hw;
		cin >> cuttree;
		bool **visited = new bool*[hw];
		Position pos(0,0);
		for (int i=0; i< hw; i++)
		{
			visited[i] = new bool[hw];
			for (int j = 0; j < hw; j++)
				visited[i][j] = false;
		}

		int **grid = new int*[hw];
		for (int row = 0; row < hw; row++){
			grid[row] = new int[hw];
			cout << endl;
			for (int col = 0; col < hw; col++){
				cin >> num;
				grid[row][col] = num;
				cout << " " << grid[row][col] ;
			}

		}
        cout << endl;
		int ans = 0;
		
		if(cuttree == 2){

			int ansZero =getAnswer(grid, cuttree, hw, visited);

			for (int i=0; i< hw; i++)
			{
				visited[i] = new bool[hw];
				for (int j = 0; j < hw; j++)
					visited[i][j] = false;
			}

			int max =0;

			int ansOne = getAnswerOne(grid,hw,visited, max);

			for (int i=0; i< hw; i++)
			{
				visited[i] = new bool[hw];
				for (int j = 0; j < hw; j++)
					visited[i][j] = false;
			}
			
			int ansTow = getAnswerTwo(grid,hw,visited,max);
			ans = getMax(getMax(ansZero,ansOne),ansTow);			
		}else if (cuttree == 1){

			int ansZero =getAnswer(grid, cuttree, hw, visited);

			for (int i=0; i< hw; i++)
			{
				visited[i] = new bool[hw];
				for (int j = 0; j < hw; j++)
					visited[i][j] = false;
			}

			int max =0;

			int ansOne = getAnswerOne(grid,hw,visited, max);

			ans =getMax(ansZero,ansOne);
		}
        
		cout << "#" << tc <<":"<< ans << endl;
	}

	return 0;
}