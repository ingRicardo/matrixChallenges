#include <iostream>
using namespace std;


  struct node
  {
    int data;
    node *next;
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

  void createnode(int value)
    {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
    }


  void display()
  {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  } 
    bool ExpreVal()
    {
        node *temp=new node;
        temp=head; 
        if (temp == NULL || temp->data < 0 )
        {
            return false;
        }
        if (tail == NULL || tail->data < 0)
        {
            return false;
        }
            
        if (temp != NULL && temp->data >0)
        {

            int current;
            while(temp!=NULL)
            {
                current = temp->data;
                //temp->data;
                temp=temp->next;
                if(current < 0 && temp->data < 0)
                    return false;    
                        
            }
        }
        return true;        
    }

  };	

list  populateList(list lt, int arr[], int size)
{

    int i,j;
    for(i=0; i<size; i++)
    {
      //  cout<< " "<< arr[i];
        lt.createnode(arr[i]);
    }
    return lt;
}

//function to print the array
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        cout<< " "<< arr[i];
    }
    cout<<endl;
}
//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//permutation function
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        list ls;
        ls =  populateList(ls,arr, end+1);
        printarray(arr, end+1);
        ls.display();
        cout<<endl;
        cout << ls.ExpreVal()<<endl;
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}
int main()
{
int * arr = new int[3];
arr[0] = 4;
arr[1] = 8;
arr[2] = -2;

   //calling permutation function
    permutation(arr, 0, 3-1);
return 0;
}
