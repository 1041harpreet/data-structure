#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int buy=prices[0];
     int profit=0;
     for(int i=1;i<prices.size();i++){
         if(buy>prices[i] ){
             buy=prices[i];
         }
         else if(prices[i]-buy>profit){
             profit=prices[i]-buy;

         }
     }   
     return profit;
    }
};


// Stock Buy Sell to Maximize Profit using Local Maximum and Local Minimum:

// C++ Program to find best buying and selling days
#include <bits/stdc++.h>
using namespace std;

// This function finds the buy sell
// schedule for maximum profit
void stockBuySell(int price[], int n)
{
	// Prices must be given for at least two days
	if (n == 1)
		return;

	// Traverse through given price array
	int i = 0;
	while (i < n - 1) {

		// Find Local Minima
		// Note that the limit is (n-2) as we are
		// comparing present element to the next element
		while ((i < n - 1) && (price[i + 1] <= price[i]))
			i++;

		// If we reached the end, break
		// as no further solution possible
		if (i == n - 1)
			break;

		// Store the index of minima
		int buy = i++;

		// Find Local Maxima
		// Note that the limit is (n-1) as we are
		// comparing to previous element
		while ((i < n) && (price[i] >= price[i - 1]))
			i++;

		// Store the index of maxima
		int sell = i - 1;

		cout << "Buy on day: " << buy
			<< "\t Sell on day: " << sell << endl;
	}
}

// Driver code
int main()
{
	// Stock prices on consecutive days
	int price[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	// Function call
	stockBuySell(price, n);

	return 0;
}

// This is code is contributed by rathbhupendra


 //{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>& price) {
    int n = price.size();
    
    if (n <= 1) {
        return 0;
    }
    
    vector<int> leftProfit(n, 0); // Maximum profit for the first transaction
    vector<int> rightProfit(n, 0); // Maximum profit for the second transaction
    
    int minPrice = price[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, price[i]);
        leftProfit[i] = max(leftProfit[i - 1], price[i] - minPrice);
    }
    
    int maxPrice = price[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, price[i]);
        rightProfit[i] = max(rightProfit[i + 1], maxPrice - price[i]);
    }
    
    int maxP = 0;
    for (int i = 0; i < n; ++i) {
        maxP = max(maxP, leftProfit[i] + rightProfit[i]);
    }
    
    return maxP;
}


