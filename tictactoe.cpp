#include<iostream>
using namespace std;
class tictactoe{
    
    int a[3][3];
    int i=0,j=0;
public:
    tictactoe(){
        
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                a[m][n]=-1;
            }
        }
    }
    char crossornut(int i,int j){
        
        if(a[i][j]==-1)
          return ' ';
        if(a[i][j]==0)
            return 'O';
        if(a[i][j]==1)
            return 'X';
    }
    void displayboard();
    void game();
    bool winorlose();
    void clearboard();
};
void tictactoe::game(){
    
    int c=0;
    bool win=false;
    displayboard();
    do{
        
        P1:cout<<"player one enter your choice "<<endl;
        cout<<"enter the row:  ";
        cin>>i;
        i--;
        cout<<"enter the coloumn: ";
        cin>>j;
        j--;
        
        if(a[i][j]==0||a[i][j]==1){
            cout<<"already filled \n enter a valid place "<<endl;
            goto P1;
    }
    else{
        
        a[i][j]=0;
        c++;
    }
    displayboard();
    win=winorlose();
    
    if(win){
        
        cout<<"player one has won "<<endl;
        break;
    }
    if(c==9)
        break;
    P2:cout<<"player two enter your choice "<<endl;
    cout<<"enter the row:  ";
    cin>>i;
    i--;
    cout<<"enter the coloumn: ";
    cin>>j;
    j--;
     if(a[i][j]==0||a[i][j]==1){
        cout<<"already filled \n enter a valid place "<<endl;
        goto P2;
    }
    else{
        a[i][j]=1;
        c++;
    }
     displayboard();
     win=winorlose();
    if(win)
    {
        cout<<"player two has won "<<endl;
        break;
    }
    }
    while(1);
    /*cout<<"player two enter your choice "<<endl;
    cout<<"enter the row:  ";
    cin>>i;
    i--;
    cout<<"enter the coloumn: ";
    cin>>j;
    j--;
    a[i][j]=1;
    displayboard();
    winner();*/
    if(!win)
    {
        cout<<"it is a draw "<<endl;
    }
}
void tictactoe::displayboard()
{
cout<<"\t"<<crossornut(0,0)<<"|"<<crossornut(0,1)<<"|"<<crossornut(0,2)<<endl;
cout<<"      ---------"<<endl;
cout<<"\t"<<crossornut(1,0)<<"|"<<crossornut(1,1)<<"|"<<crossornut(1,2)<<endl;
cout<<"      ---------"<<endl;
cout<<"\t"<<crossornut(2,0)<<"|"<<crossornut(2,1)<<"|"<<crossornut(2,2)<<endl;
}
bool tictactoe::winorlose()
{
    if((a[0][0]==0&&a[0][1]==0&&a[0][2]==0)||(a[1][0]==0&&a[1][1]==0&&a[1][2]==0)||(a[2][0]==0&&a[2][1]==0&&a[2][2]==0)||
       (a[0][0]==0&&a[1][0]==0&&a[2][0]==0)||(a[0][1]==0&&a[1][1]==0&&a[2][1]==0)||(a[0][2]==0&&a[1][2]==0&&a[2][2]==0)||
       (a[0][0]==0&&a[1][1]==0&&a[2][2]==0)||(a[0][2]==0&&a[1][1]==0&&a[2][0]==0))
       {
        //cout<<"player one has won"<<endl;
        return true;
       }
    if((a[0][0]==1&&a[0][1]==1&&a[0][2]==1)||(a[1][0]==1&&a[1][1]==1&&a[1][2]==1)||(a[2][0]==1&&a[2][1]==1&&a[2][2]==1)||
       (a[0][0]==1&&a[1][0]==1&&a[2][0]==1)||(a[0][1]==1&&a[1][1]==1&&a[2][1]==1)||(a[0][2]==1&&a[1][2]==1&&a[2][2]==1)||
       (a[0][0]==1&&a[1][1]==1&&a[2][2]==1)||(a[0][2]==1&&a[1][1]==1&&a[2][0]==1))
       {
        //cout<<"player two has won"<<endl;
        return true;
       }
       else
        return false;


}
void tictactoe::clearboard()
{
     for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                a[m][n]=-1;
            }
        }
}
int main()
{
    tictactoe t;
    char c;
    do{
        t.game();
        cout<<"would you like to continue "<<endl;
        cin>>c;
        t.clearboard();
    }
    while(c=='y');
    return 0;
}
