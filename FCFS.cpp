#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int pid;
    int bt_time;
    int arr_time;
    int wt=0;
    int tat=0;

}process;


int comparator(process p1,process p2){
return p2.arr_time>p1.arr_time;
}
void CalculateWtTime(process * p,int count){
    p[0].wt=0;
    cout<<count<<endl;
    for(int i = 1; i < count; i++)
    {
        p[i].wt=p[i-1].bt_time+p[i-1].wt;
        cout<<p[i].pid<<"\t "<<p[i].wt<<endl;
    }
    

}
void CalculateTATTime(process *p,int count){
    for(int i = 0; i < count; i++)
    {
        p[i].tat=p[i].bt_time+p[i].wt;
    }
    
}

void FCFS(process * p,int n){

sort(p,p+n,comparator);


CalculateWtTime(p,n);
CalculateTATTime(p,n);

cout << "Processes  "<< " Burst time  "<<" Arrival Time "
         << " Waiting time  " << " Turn around time\n"; 
  int total_wt=0,total_tat=0;
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + p[i].wt; 
        total_tat = total_tat +p[i].tat; 
        cout << "   " << p[i].pid << "\t\t" << p[i].bt_time <<"\t    "<<p[i].arr_time<<"\t\t "
            << p[i].wt <<"\t\t  " << p[i].tat <<endl; 
    } 
  
    cout << "Average waiting time = " 
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " 
         << (float)total_tat / (float)n; 

}


int main(){
int n;
cout<<"Enter Number of Processes"<<endl;
cin>>n;

process p[n];
cout<<"Arrival Time \t burstTime"<<endl;
for(int i = 0; i < n; i++)
{
   p[i].pid=i+1;
    cin>>p[i].arr_time;
    cin>>p[i].bt_time;

}
FCFS(p,n);


}