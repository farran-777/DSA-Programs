#include <iostream>
using namespace std;

class CoffeeMaker {
public:

    void brew() {
        warmWater();
        crushBeans();
        blendIngredients();
        serveBrew();
    }

private:
    void warmWater() {
        cout << "Warming the water..." << endl;
    }

    void crushBeans() {
        cout << "Crushing the coffee beans..." << endl;
    }

    void blendIngredients() {
        cout << "Blending coffee with water..." << endl;
    }

    void serveBrew() {
        cout << "Your coffee is ready to enjoy!" << endl;
    }
};

int main() {
    CoffeeMaker myCoffeeMaker;
    myCoffeeMaker.brew(); 

    return 0;
}
