// The above problem can be easily solved if O(n) extra space is allowed.

// We can store the positive values and negative values in two separate data structures.
// We will start filling the original array with alternating negative and positive values in the same order 
// in which it appears in the original array.

//but we specified it in O(1) sapace
// void altNegPos(vector<int>& v, int n){
//     sort(v.begin(), v.end());
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         if(v[i]>=0)
//             break;
//         cnt++;
//     }
//     int i=1;
//     int t = cnt;
//     if(cnt%2){
//         while(i<cnt){
//             swap(v[i],v[t+i]);
//             i+=2;
//         }
//     }
//     else{
//         while(i<cnt){
//             swap(v[i],v[t]);
//             i+=2;t+=2;
//         }
//     }
// }