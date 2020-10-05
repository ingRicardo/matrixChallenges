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

    int getSize()
    {
      node *temp=new node;
      temp=head;
      int s =0;
      while(temp!=NULL)
      {
        s++;
        temp=temp->next;
      }
      return s;
    } 


    void operaDetail()
    {
      node *temp=new node;
      temp=head;
      int current=0, acc=-1,opr=0,next=0,res=0,checkSize=0;
      while(temp!=NULL)
      {
        checkSize++;
        current = temp->data; 
        //cout<<temp->data<<"\t";
        temp=temp->next;
        next = temp->data;
        if(current < 0)
        {
          //is an operator
          opr = current;
        }else if(current >0)
        {
          if (acc >- 1)
            acc = acc * 10 + current;
        }
         if (next < 0)
         {
          opr = next;
         } else if (next > 0)
         {
           acc = next;

            if (acc >- 1)
              acc = acc * 10 + next;
          /*
          if (acc == -1)
              acc = current;
          else
            acc = acc * 10 + current;

          if (next < 0)
          {
            opr = next;
          }
          else
          {
            if (acc == -1)
                acc = next;
            else
              acc = acc * 10 + next;
          }
          */
        }
        if(acc > -1 && opr < 0)
        {
          cout << " close to oper "<<opr<< " acc "<< acc << endl;
            if(temp != NULL  )
            {
              cout << " enter "<< getSize()<<  endl;
              if ( opr == -1) res = res + (acc + temp->next->data);
              else if ( opr == -2) res = res + (acc - temp->next->data);
              else if ( opr == -3) res = res + (acc * temp->next->data);
              else if ( opr == -4) res = res + (acc / temp->next->data);
            }
        }
       
      }
      cout << "-> "<<res<<endl;
    } 

    int operation(int prio)
    {
      int res =0;
      if (prio == 1)
      {
      }
      else if (prio == 2)
      {
        /*
          4	-2	8 = 8-4 =4
          8	-2	4 = 4-8 =-4
        */
       reverse();
       cout << " print in reverse order -> ";
       display();
       cout<<endl;
      }
      operaDetail();
      return res;
    }
        /* Function to reverse the linked list */
    void reverse() 
    { 
        // Initialize current, previous and 
        // next pointers 
        node* current = head; 
        node *prev = NULL, *next = NULL; 
        while (current != NULL) { 
            // Store next 
            next = current->next; 
            // Reverse current node's pointer 
            current->next = prev; 
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 

    int getPriority()
    {
      node *temp=new node;
      temp=head; int prio=0;
      while(temp!=NULL)
      {
        if (temp->data < -2) prio =1;
        else prio=2;
        temp=temp->next;
      }
      return prio;
    }


    bool AreAllBalls()
    {
      node *temp=new node;
      temp=head;
      while(temp!=NULL)
      {
        if (temp->data < 0) return false;
        temp=temp->next;
      }
      return true;
    } 

    bool Has2AtMostOperatorBalls()
    {
      node *temp=new node;
      temp=head;int opera=0;
      while(temp!=NULL)
      {
        if (temp->data < 0) opera++;
        temp=temp->next;
      }
      if (opera > 0 && opera <= 2) return true;
      return false;
    } 
  
    bool hasMoreBalls()
    {
      node *temp=new node;
      temp=head;
      int balls=0,opera=0;
      while(temp!=NULL)
      {
        if (temp->data >0) balls++;
        else opera++;
        temp=temp->next;
      }
      if(balls > opera)
          return true;
      return false;
    } 

    bool ExpreVal()
    {
        node *temp=new node;
        temp=head; 
        if (temp == NULL || temp->data < 0 ) return false;
        if (tail == NULL || tail->data < 0) return false;
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
        //cout << "The expresion is valid -> "<< ls.ExpreVal()<<endl;
        if (ls.ExpreVal() && ls.hasMoreBalls() && ls.Has2AtMostOperatorBalls())
        {
          cout << "The expresion is valid -> "<< ls.ExpreVal()<<endl;
          ls.display();
          cout<<endl;
          cout <<" priority -> "<<  ls.getPriority()<<endl;
          cout << " has more balls -> "<<ls.hasMoreBalls()<<endl;
          cout << " has at most 2 operator balls -> "<< ls.Has2AtMostOperatorBalls()<<endl;
          cout << " Are all just balls -> "<< ls.AreAllBalls()<<endl;
          ls.operation(ls.getPriority());
         // ls.reverse();
         // cout << " print in reverse order -> ";
        //  ls.display();
        //  cout<<endl;
        }
    
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
bool *visited = new bool[10];

   //calling permutation function
    permutation(arr, 0, 3-1);
return 0;
}
