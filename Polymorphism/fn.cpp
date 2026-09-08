// Function Overlaoding in C++ is a feature that allows you to have more than one function with the same name but different parameters. This can be useful for creating functions that perform similar tasks but with different types or numbers of inputs. 
#include<iostream>
using namespace std;

class calculator{
    public:
    int add(int a, int b){
            return a + b;
        }
        double add(double a, double b){
            return a + b;
        }
        int add(int a, int b, int c){
            return a + b + c;
        }
};
int main(){
    calculator calc;
    cout << "Sum of 2 and 3: " << calc.add(2, 3) << endl; // Calls add(int, int)
    cout << "Sum of 2.5 and 3.5: " << calc.add(2.5, 3.5) << endl; // Calls add(double, double)
    cout << "Sum of 1, 2 and 3: " << calc.add(1, 2, 3) << endl; // Calls add(int, int, int)
    return 0;
}