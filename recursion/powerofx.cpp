/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
/* //using brute force approach ,time complexity - o(n)
//

int power(int x,int n)
{
    
    if (n==0)
    
    {
        return 1  ;
    }
    int ans= x*power(x,n-1);
    return ans;
}
*/
// using smart approachtimecomplexity big O(logn)
int power(int x,int n)
{
    if (n==0)
    {
        return 1;

    }
     if (n%2==0)
     {
        return   x*power(x,n/2);


     }
     else{

        return x*power(x,n-1);
     }
}


int main()
{
  cout<<power(5,3);



    return 0;
}
