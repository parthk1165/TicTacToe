#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

char sample[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row;
int coloum;
int lower=1;
int upper=9;
char token = 'x';
bool tie = false;
string s1 =" ";
string s2 ="comp";


void function1 ()
{
    cout<<"     |     |     \n";
    cout<<"  "<<sample[0][0]<<"  |  "<<sample[0][1]<<"  |  "<<sample[0][2]<<"  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<sample[1][0]<<"  |  "<<sample[1][1]<<"  |  "<<sample[1][2]<<"  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<sample[2][0]<<"  |  "<<sample[2][1]<<"  |  "<<sample[2][2]<<"  \n";
    cout<<"     |     |     \n";
}

void function2 ()
{
    //cout<<"\n in function 2 \n\n";
    int digit;
    if (token=='x')
    {
        cout<<"Enter the digit of player "<<s1<<endl;
        cin>>digit;
    }
    if (token=='0')
    {
        cout<<"Played by "<<s2<<endl;
        srand(time(0));
        digit= (rand() % (upper - lower + 1)) + lower;
        cout<<"digit is"<<digit<<endl;
    }
    if (digit==1)
    {
        row=0;
        coloum=0;
    }
    if (digit==2)
    {
        row=0;
        coloum=1;
    }
    if (digit==3)
    {
        row=0;
        coloum=2;
    }
    if (digit==4)
    {
        row=1;
        coloum=0;
    }
    if (digit==5)
    {
        row=1;
        coloum=1;
    }
    if (digit==6)
    {
        row=1;
        coloum=2;
    }
    if (digit==7)
    {
        row=2;
        coloum=0;
    }
    if (digit==8)
    {
        row=2;
        coloum=1;
    }
    if (digit==9)
    {
        row=2;
        coloum=2;
    }
    else if ( digit<1 || digit>10)
    {
        cout<<"Invalid !!!!!";
    }
    //cout<<"\nrow is "<<row<<"coloumn is "<<coloum<<"\n";
    if (token=='x' &&  sample[row][coloum]!='x' && sample[row][coloum] !='0')
    {
        //cout<<"\nmaking it x"<<endl;
        sample[row][coloum]='x';
        token='0';
    }
    else   if (token=='0' &&  sample[row][coloum]!='x' && sample[row][coloum]!='0')
    {
        //cout<<"\nmaking it 0"<<endl;
        sample[row][coloum]='0';
        token='x';
    }
    else
    {
        //cout<<"in else";
        function2();
    }
}

bool function3 ()
{
    //cout<<"\n in function 3 \n\n";
    int i , j, a;
    for (i= 0;i<3;i++)
    {
        //cout<<"in for loop"<<endl;
        //cout<<"i is "<<i<<endl;
        if (sample[i][0]==sample[i][1] && sample[i][1]==sample[i][2] || sample[0][i]==sample[1][i] && sample[1][i]==sample[2][i] )
        {
            //cout<<"in coloumn if"<<endl;
            return true ;
        }
    }
    if (sample[0][0]==sample[1][1] && sample[1][1]==sample[2][2] || sample[0][2]==sample[1][1] && sample[1][1]==sample[2][0])
    {
        //cout<<"in digonal if loop"<<endl;
        return true;
    }

   for (int x = 0; x < 3; x++)
    {
        for (j=0;j<3;j++)
        {
            //cout<<"i is "<<x<<" j is "<<j<<endl;
            //cout<<"Sample is "<<sample[x][j]<<endl;
            if ( sample[x][j]!='0' && sample[x][j]!='x' )
            {
                //cout<<"in 2nd if loop"<<endl;
                return false; 
            }
        }
    }
    cout<<"near tie"<<endl;
    tie=true;
    return true;
}

int main()
{
    cout<<"Enter 1st player name : ";
    getline(cin,s1);
    //cout<<"Enter 2nd player name";
    //getline(cin,s2);
    cout<<s1<<" Plays first";
    cout<<"\n";
    cout<<s2<<" Plays Second\n";
    while(!function3())
    {
        function1();
        function2();
        function3();
    }

    if (token=='0'&& tie==false)
    {
        cout<<s1<<" wins";
    }

    else if (token=='x'&& tie==false)
    {
        cout<<s2<<" wins";
    }

    else
    {
        cout<<"It is draw"<<endl;
    }
}



