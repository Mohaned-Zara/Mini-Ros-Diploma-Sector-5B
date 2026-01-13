#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define pi 3.14159265359

using namespace std;

int main(){
    vector <int> nums;
    int n;

    for (int i = 0; i <= nums.size(); i++)
    {    
        cout<<"enter a number"<<endl;
        cin>>n;
        if (n==-1){
            break;
        }else{
            nums.push_back(n);
        }
    }

    //printing reverse
    int i = nums.size()-1;
    for (;i>=0;)
    {
        cout <<"number "<<i+1<<" is: "<<nums.at(i)<<endl;
    i--;
    }
    
    

    return 0;
}