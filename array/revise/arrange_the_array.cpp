// TC : O(n)
//             vector<int>pos;
//             vector<int>neg;
//             for(int i =0;i < n;i++)
//             {
//                 if(arr[i] < 0)
//                 {
//                     neg.push_back(arr[i]);
//                 }
//                 else
//                 {
//                     pos.push_back(arr[i]);
//                 }
//             }
//             for(int i =0;i < neg.size();i++)
//             {
//                 arr[i] = neg[i];
//             }
//             int j=0;
//             for(int i = neg.size();i < n;i++)
//             {
//                 arr[i] = pos[j];
//                 j++;
//             }
