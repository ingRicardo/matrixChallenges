//
#include<iostream>
using namespace std;

void print(int ai[], int s){

    for (int i = 0; i < s; i++)
    cout << "" << ai[i];

    cout << endl;
}

int twister(int start, int bi[], int ai[], int size, int r, bool visited[], int &ditmp){

    if (r>size)
        return 0;

    for (int i = start; i < size; i++){

        if (bi[r] == ai[i] && !visited[bi[r]]){
            visited[bi[r]] = true;
            ditmp = ditmp + 1;
        }

    twister(i + 1, bi, ai, size, r, visited, ditmp);

    }

    return ditmp;
}

int* splitNumb(int num){

int n = num;
int *bi = new int[5], bisize = sizeof(bi) / sizeof(bi[0]) - 1;
int  mod = 0, base = 10, i = 4;
    while (n > 0){
        mod = n % base;
        bi[i] = mod;
        n = n / base;
        i--;
    }
return bi;

}


void compare(int ai[], int **grid, int &numbs, int h, int w){
    
   int ans =0;
    for (int i =0; i<h; i++){

        int ci = grid[i][1], di = grid[i][2];
        int *bi = splitNumb(grid[i][0]);
        int citmp = 0;
        bool visited[10];
        for (int x = 0; x < 10; x++)
            visited[x] = false;

        for (int j = 0; j < h; j++){

            if (bi[j] == ai[j]){
                citmp++;
                visited[bi[j]] = true;

            }
        }

        int start = 0, r = 0;
        int ditmp = 0;
        for (int r = 0; r < h; r++)
            ditmp = twister(start, bi, ai, h, r, visited, ditmp);

        if(ci == citmp && di == ditmp)
            ans++;

    }
    if (ans == h){
        numbs++;
//         print(ai,5);
    }    
}

void getAnswer(int start, int n, int r, int ai[], int **grid,int &numbs, int h, int w){

    if (r == 5){
      compare(ai,grid, numbs, h, w);    
    return;
    }

    for (int i = start; i < n; i++){
       if (r == 0 && i == 0)
            continue;
        else
            ai[r] = i;

        getAnswer(start, n, r + 1, ai, grid, numbs, h, w);

    }
  
}

int getTotalAns(int **grid, int h, int w ){

int n = 10;
int start = 0;
int r = 0, numbs=0;
int ai[5]{0, 0, 0, 0, 0};
    
    getAnswer(start, n, r,  ai, grid, numbs,  h,  w);

return numbs;
}

int main()
{

    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    int h=0,w=0, nu=0;
    for (int tc =1; tc<=T; ++tc){
        cin >> h;
        cin >> w;
        int **grid = new int*[h];
        for (int i =0; i < h; i++){
            grid[i] = new int[w];
            for (int j=0; j< w; j++){
                    cin>> nu;
                    grid[i][j] = nu;
            }
        }
        int ans =getTotalAns(grid, h,w); 
        cout <<"#"<<tc<<":"<<ans<< endl;
    }
    

return 0;
}
