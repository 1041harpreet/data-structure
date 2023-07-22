//it mean provide a range in which atleast one element from every list exist
//1 using brute force check every node with other and get the range
//O(n2K2) as we aretraversing every element  with other 

// 2 store first element from list in separate array and stor min and max. after go to small element and update min and max 
//tc O(n*k*k) and space O(k)
// C++ program to finds out smallest range that includes
// elements from each of the given sorted lists.

#include <bits/stdc++.h>
using namespace std;

// array for storing the current index of list i
int ptr[501];

// This function takes an k sorted lists in the form of
// 2D array as an argument. It finds out smallest range
// that includes elements from each of the k lists.
void findSmallestRange(vector<vector<int> >& arr, int N,
					int K)
{
	int i, minval, maxval, minrange, minel, maxel, flag,
		minind;

	// initializing to 0 index;
	for (i = 0; i <= K; i++)
		ptr[i] = 0;

	minrange = INT_MAX;

	while (1) {
		// for maintaining the index of list containing the
		// minimum element
		minind = -1;
		minval = INT_MAX;
		maxval = INT_MIN;
		flag = 0;

		// iterating over all the list
		for (i = 0; i < K; i++) {
			// if every element of list[i] is traversed then
			// break the loop
			if (ptr[i] == N) {
				flag = 1;
				break;
			}
			// find minimum value among all the list
			// elements pointing by the ptr[] array
			if (ptr[i] < N && arr[i][ptr[i]] < minval) {
				minind = i; // update the index of the list
				minval = arr[i][ptr[i]];
			}
			// find maximum value among all the list
			// elements pointing by the ptr[] array
			if (ptr[i] < N && arr[i][ptr[i]] > maxval) {
				maxval = arr[i][ptr[i]];
			}
		}

		// if any list exhaust we will not get any better
		// answer, so break the while loop
		if (flag)
			break;

		ptr[minind]++;

		// updating the minrange
		if ((maxval - minval) < minrange) {
			minel = minval;
			maxel = maxval;
			minrange = maxel - minel;
		}
	}

	printf("The smallest range is [%d, %d]\n", minel,
		maxel);
}

// Driver's code
int main()
{
	vector<vector<int> > arr = { { 4, 7, 9, 12, 15 },
								{ 0, 8, 10, 14, 20 },
								{ 6, 12, 16, 30, 50 } };

	int K = arr.size();
	int N = arr[0].size();

	// Function call
	findSmallestRange(arr, N, K);

	return 0;
}


//3. approach
#include <limits.h>
#include <queue>

class node {
public:
    int data;
    int row;
    int col;
    node(int data, int r, int c) {
        this->data = data;
        col = c;
        row = r;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>>& a, int k, int n) {
    int ansMin = INT_MAX, ansMax = INT_MIN; // Corrected the initialization
    priority_queue<node*, vector<node*>, compare> minHeap;

    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        ansMin = min(element, ansMin); // Corrected the assignment
        ansMax = max(element, ansMax); // Corrected the assignment
        minHeap.push(new node(a[i][0], i, 0));
    }

    int start = ansMin, end = ansMax;
    while (!minHeap.empty()) {
        node* temp = minHeap.top();
        minHeap.pop();
        ansMin = temp->data;
        if (end - start > ansMax - ansMin) {
            start = ansMin; // Corrected the variable
            end = ansMax;
        }

        if (temp->col + 1 < n) {
            ansMax = max(ansMax, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1)); // Corrected the column index
        } else {
            break;
        }
    }

    return (end - start + 1);
}

