#include<iostream>
using namespace std;


int insideAmount(int currentX, int currentY, int nextX, int nextY)
{

    if (currentX >= nextX  && currentY >= nextY)
        return 1;

        return 0;
}

void rec(int ** blocks_arr, int size, int &indx, int ac)
{
 
    if (indx > size)
        return;

    int startX = blocks_arr[indx][0], startY=blocks_arr[indx][1];
    cout << " start "<< startX << ", "<< startY <<endl;
    for(int i=0; i< size; i++)
    {
        int nextX = blocks_arr[i][0], nextY = blocks_arr[i][1];
        // cout << blocks_arr[i][0] << ", "<< blocks_arr[i][1]<<endl;
        if (indx != i)
            ac+= insideAmount(startX, startY, nextX, nextY);
    }
    cout << " inside "<< ac <<endl;
    indx+=1;
    cout << " indx "<< indx <<endl;
    rec(blocks_arr,size,indx , ac);

 }

void fun(int ** blocks_arr, int size)
{
    /*
    int indx =0;
    int startX = blocks_arr[indx][0], startY=blocks_arr[indx][0], ac=0;
    cout << " start "<< startX << ", "<< startY <<endl;
    for(int i=0; i< size; i++)
    {
        int nextX = blocks_arr[i][0], nextY = blocks_arr[i][0];
       // cout << blocks_arr[i][0] << ", "<< blocks_arr[i][1]<<endl;
       if (indx != i)
            ac+= insideAmount(startX, startY, nextX, nextY);
    }
     cout << " inside "<< ac <<endl;
     */
    int indx =0,ac=0;


    rec(blocks_arr,size, indx, ac);


 }

int main()
{

  freopen("input.txt","r",stdin);

    int t,blocks=0,x,y;
    cin>>t;
    cout <<"test  cases "<<t<<endl;
    for (int tc =1; tc<=1; ++tc)
    {

        cin>> blocks;
        int **blocks_arr = new int*[blocks];
        for (int b =0; b<blocks; ++b)
        {
            cin>> x;
            cin>> y;
            blocks_arr[b] = new int [2];
            blocks_arr[b][0]=x;
            blocks_arr[b][1]=y;

           
        }
        fun(blocks_arr, blocks);
    }

    cout <<"test"<<endl;
    return 0;
}