#include <iostream>
#include <string>
using namespace std;

int main() {


    const float x[16]={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6};
    const float z[16]={1.123,1.234,1.345,156.467,1.578,1.689,1.790,1.812,1.923,2.034,2.145,2.256,2.367,2.478,2.589,2.690};
    float y[16];
    for(int i=0;i<16;i++)
    {
        y[i]=x[i];
    }
    for(int j=0;j<9000000;j++)
    {
        for(int i=0;i<16;i++)
        {
            y[i]*=x[i];
            y[i]/=z[i];
            y[i]=y[i]+0.1f;
            y[i]=y[i]-0.1f;
/**
            y[i]=y[i]+0;
            y[i]=y[i]-0;
**/

        }
    }


    system("pause");
    return 0;
}
