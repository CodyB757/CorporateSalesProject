#include "DivSales.h"
#include <iostream>
#include <stdexcept>

using namespace std;

double DivSales::totalCorpSales = 0.0;

DivSales::DivSales(const DivSales& other) {
    numberOfPeriods = other.numberOfPeriods;
    sales = new double[numberOfPeriods];
    for (int i = 0; i < numberOfPeriods; ++i) {
        sales[i] = other.sales[i];
    }
}

DivSales& DivSales::operator=(const DivSales& other) {
    if (this == &other) {
        return *this;
    }

    delete[] sales;

    numberOfPeriods = other.numberOfPeriods;
    sales = new double[numberOfPeriods];
    for (int i = 0; i < numberOfPeriods; ++i) {
        sales[i] = other.sales[i];
    }

    return *this;
}