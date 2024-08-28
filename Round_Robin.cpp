#include <bits/stdc++.h>
using namespace std;

int main()
{
            int q;
            cout << "\nEnter the quantum time for processess : ";
            cin>>q; 
            cout << "Enter the number of processes : ";
            int n;
            cin >> n;
            cout << endl;
            vector<vector<int>> process;
            for (int i = 0; i < n; i++)
            {
                int at, bt;
                cout << "Enter the arrival time for process " << i << " : ";
                cin >> at;
                cout << "Enter the burst time for process " << i << " : ";
                cin >> bt;
                process.push_back({i, at, bt, 0, 0, 0});
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
            int total=n;
            int time=0;
            queue<int> pq;
            vector<int> process_entered;
            vector<int> brstime;
            vector<int> checked;
            for(int i=0;i<n;i++)
            {
                process_entered.push_back(0);
                brstime.push_back(process[i][2]);
                checked.push_back(1);
            }
            while(total!=0)
            {
                for(int j=0;j<q;j++)
                {
                    bool flag=true;
                    for(int i=0;i<n;i++)
                    {
                        if(time==process[i][1] && process_entered[i]==0)
                        {
                            pq.push(process[i][0]);
                            process_entered[i]=1;
                            flag=false;
                        }
                    }    
                    if(flag && pq.empty())
                    {
                        time++;            
                    }
                    else
                    {
                        // cout<<pq.front()<<endl;
                        int max = pq.front();
                        int current_process;
                        for(int i=0;i<n;i++)
                        {
                            if(process[i][0]==max)
                            current_process=i;
                            if(process[i][0]==max && brstime[i]!=0)
                            {
                                // cout<<time<<" "<<process[i][0]<<" "<<brstime[i]<<" "<<total<<endl;
                                brstime[i]--;
                                // max=process[i][0];
                                time++;
                            }
                        }
                        if(brstime[current_process]==0 && checked[current_process]==1)
                        {
                            process[current_process][3]=time;
                            total--;
                            process[current_process][4]=process[current_process][3]-process[current_process][1];
                            process[current_process][5]=process[current_process][4]-process[current_process][2];
                            checked[current_process]=0;
                        }
                    }
                }
                int max=pq.front();
                int current_process;
                for(int i=0;i<n;i++)
                {
                    if(max==process[i][0])
                    current_process=i;
                }
                for(int i=0;i<n;i++)
                {
                    if(time==process[i][1] && process_entered[i]==0)
                    {
                        pq.push(process[i][0]);
                        process_entered[i]=1;
                    }
                }    
                pq.pop();
                if(brstime[current_process]>0)
                pq.push(process[current_process][0]);
            }
            cout << "   Process Id   Arrival Time   Burst Time   Completion Time   Turn Around Time   Waiting Time" << endl;
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
                        << setw(19) << process[i][4]
                        << setw(15) << process[i][5]
                        << endl;
                        avgtat+=process[i][4];
                        avgwt+=process[i][5];  
                        flag=false;  
                    } 
                }
            }
            cout<<"\nAverage Turn Around Time : "<<(double)avgtat/(double)n<<endl;
            cout<<"Average Turn Around Time : "<<(double)avgwt/(double)n<<endl;

            return 0;
}
