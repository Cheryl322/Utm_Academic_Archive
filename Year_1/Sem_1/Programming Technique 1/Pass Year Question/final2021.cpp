//FinalQ1.cpp
#include <iostream>
#include <string>
#define SIZE 3
using namespace std;
void getSpec(string caption, string *p_data) {
    cout << caption;
    cin >> *p_data;//1
}
void getSpec(string caption, int *p_data) {//2
    cout << caption;
    cin >> *p_data;
}
int fastestModel(string *m[], int *hp[], int *w[]) {//3
    float whp_ratio=0, whp_ratio_lowest = 999;//4
    int idx;

    cout << "Check weight and horsepower ratio: \n";

    for (int i = 0; i < SIZE; i++) {
        whp_ratio =(static_cast <float>(*w[i]) / *hp[i]);//5
        cout << *m[i] << " - " << whp_ratio << "\n";//6
        if (whp_ratio < whp_ratio_lowest) {//7
            whp_ratio_lowest = whp_ratio;//8
            idx = i;
        }
    }
    cout << "\n";
    return idx;
}
// Start main function
int main() {
    string *models [SIZE];
    int *horsepower [SIZE];
    int *weight [SIZE];//9

    // Examples of car's models, horse power and weight
    // Almera - 76 hp - 1035 Kg
    // City - 88 hp - 1110 Kg
    // Persona - 80 hp - 1210 Kg
    // Vios - 78 hp - 1112 Kg
    for (int i = 0; i < SIZE; i++) {
        models[i] = new string;
        getSpec("Car's model: ", models[i]); 

        horsepower[i] = new int;//10
        getSpec("Horsepower (hp): ", horsepower[i]);

        weight[i] = new int;//11
        getSpec("Weight (Kg): ", weight[i]);
        cout << "\n";
    }
    int idx_fastest = fastestModel(models, horsepower, weight);
    cout << "Fastest car's model is " << *models[idx_fastest]<< " with " << *horsepower[idx_fastest] << " horsepower and "<< *weight[idx_fastest] << " kg of weight\n\n";
    // delete array data from memory
    for (int i = 0; i < SIZE; i++) {
        delete models[i];
        delete horsepower[i];
        delete weight[i];
    }
    system("pause");
    return 0;
}