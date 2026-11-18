#include "DivSales.h"
#include <iostream>
#include <stdexcept>

using namespace std;

double DivSales::totalCorpSales = 0.0;

double& DivSales::operator[](int index) {
    if (index < 0 || index >= numberOfPeriods) {
        throw out_of_range("Sales period index out of bounds.");
    }
    return sales[index];
}

const double& DivSales::operator[](int index) const {
    if (index < 0 || index >= numberOfPeriods) {
        throw out_of_range("Sales period index out of bounds.");
    }
    return sales[index];
}

double DivSales::getTotalSales() const {
    double total = 0.0;
    for (int i = 0; i < numberOfPeriods; ++i) {
        total += sales[i];
    }
    return total;
}

void DivSales::addToCorpSales() const {
    totalCorpSales += getTotalSales();
}

double DivSales::getCorpSales() {
    return totalCorpSales;
}

void DivSales::resetCorpSales() {
    totalCorpSales = 0.0;
}