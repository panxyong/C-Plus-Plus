
/* 2016.1.10 panxyong */

#include "date.h"
#define N 10

int main(int argc, char *argv[]) 
{
    Date dates[N];
    
    cout<<"CreatePoints"<<endl;
    CreatePoints(dates,N);
    for (int i = 0; i < N; ++i)
    {
    	dates[i].print();
    }

    cout<<endl<<"Sort"<<endl;
    Sort(dates,N);
    for (int i = 0; i < N; ++i)
    {
    	dates[i].print();
    }
}