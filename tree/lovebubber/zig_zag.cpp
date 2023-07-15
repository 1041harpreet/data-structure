// // // C++ implementation of a O(n) time method for
// // // Zigzag order traversal
// // #include <iostream>
// // #include <stack>
// // using namespace std;

// // // Binary Tree node
// struct Node {
// 	int data;
// 	struct Node *left, *right;
// };

// // // function to print the zigzag traversal
// // void zigzagtraversal(struct Node* root)
// // {
// // 	// if null then return
// // 	if (!root)
// // 		return;

// // 	// declare two stacks
// // 	stack<struct Node*> currentlevel;
// // 	stack<struct Node*> nextlevel;

// // 	// push the root
// // 	currentlevel.push(root);

// // 	// check if stack is empty
// // 	bool lefttoright = true;
// // 	while (!currentlevel.empty()) {

// // 		// pop out of stack
// // 		struct Node* temp = currentlevel.top();
// // 		currentlevel.pop();

// // 		// if not null
// // 		if (temp) {

// // 			// print the data in it
// // 			cout << temp->data << " ";

// // 			// store data according to current
// // 			// order.
// // 			if (lefttoright) {
// // 				if (temp->left)
// // 					nextlevel.push(temp->left);
// // 				if (temp->right)
// // 					nextlevel.push(temp->right);
// // 			}
// // 			else {
// // 				if (temp->right)
// // 					nextlevel.push(temp->right);
// // 				if (temp->left)
// // 					nextlevel.push(temp->left);
// // 			}
// // 		}

// // 		if (currentlevel.empty()) {
// // 			lefttoright = !lefttoright;
// // 			swap(currentlevel, nextlevel);
// // 		}
// // 	}
// // }

// // // A utility function to create a new node
// // struct Node* newNode(int data)
// // {
// // 	struct Node* node = new struct Node;
// // 	node->data = data;
// // 	node->left = node->right = NULL;
// // 	return (node);
// // }

// // // driver program to test the above function
// // int main()
// // {
// // 	// create tree
// // 	struct Node* root = newNode(1);
// // 	root->left = newNode(2);
// // 	root->right = newNode(3);
// // 	root->left->left = newNode(7);
// // 	root->left->right = newNode(6);
// // 	root->right->left = newNode(5);
// // 	root->right->right = newNode(4);
// // 	cout << "ZigZag Order traversal of binary tree is \n";

// // 	zigzagtraversal(root);

// // 	return 0;
// // }
// #include<iostream>
// #include<vector>
// #include<queue>

// using namespace std;
//    vector <int> zigZagTraversal(Node* root)
//     {
//         vector<int> vec;
//     	if(root==NULL){
//     	    return  vec;
//     	}
//     	queue<Node*>q;
//     	q.push(root);
//     	bool flag=false;
//     	while(!q.empty()){
//     	    int size=q.size();
//     	    vector<int> level;
//     	    for(int i=0; i<size;i++){
//     	         Node* node=q.front();
//     	         q.pop();
//     	        level.push_back(node->data) ;
 
//             if(node->left != NULL) {q.push(node->left) ;}
//             if(node->right != NULL) {q.push(node->right) ;} 
            
//     	    }
//     	    flag = !flag ;  
//            if(flag == false){
//             reverse(level.begin() , level.end()) ;           
//         }
//         for(int i = 0 ; i < level.size() ; i++){
//           vec.push_back(level[i]) ;
//         }
//     	}
//     	return vec;
//     }
