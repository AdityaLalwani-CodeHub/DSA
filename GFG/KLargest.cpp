/*
K largest elements 
Basic Accuracy: 53.45% Submissions: 17259 Points: 1
Given an array of N positive integers, print k largest elements from the array. 

Example 1:

Input:
N = 5, k = 2
arr[] = {12,5,787,1,23}
Output: 787 23
Explanation: First largest element in
the array is 787 and the second largest
is 23.
Example 2:

Input:
N = 7, k = 3
arr[] = {1,23,12,9,30,2,50}
Output: 50 30 23
Explanation: Three Largest element in
the array are 50, 30 and 23.
Your Task:
Complete the function kLargest() that takes the array, N and K as input parameters and returns a list of k largest element in descending order. 

Expected Time Complexity: O(N log K)
Expected Auxiliary Space: O(K)

Constraints:
1 ≤ N ≤ 104
K ≤ N
1 ≤ array[i] ≤ 105
*/

//Code 2

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        /*vector<int> result;
        priority_queue<int> maxHeap;
        for(int i = 0 ; i < n ; i++)
        {
            maxHeap.push(arr[i]);
        }
        for(int i = 0 ; i < k ; i++)
        {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;*/
        
        vector<int> result;
        priority_queue<int , vector<int> , std::greater<int> > minHeap;
        for(int i = 0 ; i < k ; i++)
        {
            minHeap.push(arr[i]);
        }
        for(int i = k ; i < n ; i++)
        {
            int minEle = minHeap.top();
            if(arr[i] > minEle)
            {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        
        for(int i = 0 ; i < k ; i++)
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        std::reverse(result.begin(),result.end());
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends


//Code 1

/*
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int> result;
        priority_queue<int> maxHeap;
        for(int i = 0 ; i < n ; i++)
        {
            maxHeap.push(arr[i]);
        }
        for(int i = 0 ; i < k ; i++)
        {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends
  */