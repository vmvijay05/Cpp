#include<iostream>
using namespace std;

class addnum{
    public:
    int x,y,ans;
    int sum(int a,int b)
    {
        ans=a+b;
        return ans;
    }
};
int main()
{
    addnum addobj;
        int ans,a,b;
    addobj.sum(a,b);
        ans=addobj.sum(a,b);
cout << "The sum of two numbers is " << ans;
}
