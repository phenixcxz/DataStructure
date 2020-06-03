#include"Vector/Vector.h"

using namespace std;

int main(void){
    Vector<int> num(10,10,10);
    num.printAll();
    Vector<int> numb(num);
    Vector<int> numc(numb,0,10);
    Vector<int> numd = numc;
    numd.printAll();


    numb.printAll();
    numc.printAll();
    // for(auto i:numc){
    //     cout << i << endl;
    // }
    
    cout << numc[5] << endl;
    return 0;

}