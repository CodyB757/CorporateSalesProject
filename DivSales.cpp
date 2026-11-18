#include "DivSales.h"
#include <iostream>
#include <stdexcept>

using namespace std;

double DivSales::totalCorpSales = 0.0;

DivSales::DivSales(int numPeriods) {
    if (numPeriods <= 0) {
        cout << "Invalid period count. Defaulting to 1." << endl;
        numberOfPeriods = 1;
    }
    else {
        numberOfPeriods = numPeriods;
    }

    sales = new double[numberOfPeriods];
    for (int i = 0; i < numberOfPeriods; ++i) {
        sales[i] = 0.0;
    }
}

DivSales::~DivSales() {
    delete[] sales;
    sales = nullptr;
}

int DivSales::getNumberOfPeriods() const {
    return numberOfPeriods;
}
