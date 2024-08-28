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
            int lastct = 0;
            for (int i = 0; i < n; i++)
            {
                if(process[i][1]>lastct)
                lastct=process[i][1];
                process[i][3] = lastct + process[i][2];
                lastct = process[i][3];
                process[i][4] = process[i][3] - process[i][1];
                process[i][5] = process[i][4] - process[i][2];
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
