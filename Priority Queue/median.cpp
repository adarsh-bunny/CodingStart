You are given a stream of n integers. For every ith integer, 
add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.

Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4

Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

#include<queue>
using namespace std;
void findMedian(int arr[], int n){
    
    priority_queue <int> max;
    priority_queue <int, vector<int>, greater<int>> min;
    
    for(int i=0 ;i<n ;i++)
    {
        if(i==0)
        { max.push(arr[i]); }  //push is any of the heap  //max or min
        
        else
        {
            if(arr[i] < max.top())
                max.push(arr[i]);
            else 
                min.push(arr[i]);
         }
        //keeping in check that both heap are almost of same size
        if(int(max.size()-min.size() )> 1)
        {  int x=max.top();
           max.pop();
           min.push(x);
        }
        else if(int(min.size()-max.size()) > 1)
        {  int x=min.top();
           min.pop();
           max.push(x);
        }
        
        
        int c=max.size()+min.size();  //count
        
        //checking size of list to find median
        if(c%2==0)
            cout<<(max.top()+min.top())/2<<endl;
        else
        {
            if(max.size()>min.size())
                cout<<max.top()<<endl;
            else
                cout<<min.top()<<endl;
        }
    }
    

}