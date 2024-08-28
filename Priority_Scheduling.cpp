#include <bits/stdc++.h>
using namespace std;

int main()
{
            cout << "\nEnter the number of processes : ";
            int n;
            cin >> n;
            cout << endl;
            vector<vector<int>> process;
            for (int i = 0; i < n; i++)
            {
                int at, bt,prior;
                cout << "Enter the arrival time for process " << i << " : ";
                cin >> at;
                cout << "Enter the burst time for process " << i << " : ";
                cin >> bt;
                cout << "Enter priority of the process "<< i <<" : ";
                cin>>prior;
                process.push_back({i, at, bt, prior, 0, 0, 0});
                cout << endl;
            }

            bool swapped;
            for (int i = 0; i < n - 1; i++)
            {
                swapped = false;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (process[j][1] > process[j + 1][1])
                    {
                        swap(process[j], process[j + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false)
                    break;
            }
            int lastct = 0;
            int hole=0;
            int total=n;
            int time=0;
            priority_queue<int> pq;
            vector<int> process_entered;
            int process_enetered=0;
            for(int i=0;i<n;i++)
            {
                process_entered.push_back(0);
            }
            while(total!=0)
            {
                bool flag=true;
                for(int i=0;i<n && process_enetered!=n;i++)
                {
                    if(time>=process[i][1] && process_entered[i]==0)
                    {
                        pq.push(process[i][3]);
                        process_entered[i]=1;
                        process_enetered++;
                        flag=false;
                    }
                }    
                if(flag && pq.empty())
                {
                    // cout<<hole<<endl;
                    hole++;
                    time++;            
                }
                else
                {
                    // cout<<pq.top()<<endl;
                    int max = pq.top();
                    pq.pop();
                    int p;
                    for(int i=0;i<n;i++)
                    {
                        if(process[i][3]==max)
                        p=i;
                    }
                    process[p][4]=hole+lastct+process[p][2];
                    process[p][5]=process[p][4]-process[p][1];
                    process[p][6]=process[p][5]-process[p][2];
                    hole=0;
                    total--;
                    time=process[p][4];
                    lastct=process[p][4];
                }
            }
            cout << "   Process Id   Arrival Time   Burst Time   Priority   Completion Time   Turn Around Time   Waiting Time" << endl;
            int avgtat=0;
            int avgwt=0;
            for(int j=0;j<n;j++)
            {
                bool flag=true;
                for (int i = 0; i < n && flag; i++)
                {
                    if(process[i][0]==j)
                    {
                        cout << setw(12) << process[i][0]
                        << setw(15) << process[i][1]
                        << setw(13) << process[i][2]
                        << setw(18) << process[i][3]                        
                        << setw(12) << process[i][4]
                        << setw(19) << process[i][5]
                        << setw(15) << process[i][6]
                        << endl;
                        avgtat+=process[i][5];
                        avgwt+=process[i][6];  
                        flag=false;  
                    } 
                }
            }
            cout<<"\nAverage Turn Around Time : "<<(double)avgtat/(double)n<<endl;
            cout<<"Average Turn Around Time : "<<(double)avgwt/(double)n<<endl;
            return 0;
}
