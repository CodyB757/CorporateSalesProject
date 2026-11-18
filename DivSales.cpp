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

int DivSales::getNumberOfPeriods() const {
    return numberOfPeriods;
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