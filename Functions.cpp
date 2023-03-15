#include <bits/stdc++.h>

using namespace std;

namespace sortlib 
{

    template<typename T>

    T sum (T x , T y){
        return x + y;
    }

};






int main(){


    using namespace sortlib;
    int x = 10 , y=45 ;
    cout<< sum(x,y)<<endl;

}