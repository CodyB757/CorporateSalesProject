#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "DivSales.h"

using namespace std;

bool loadAndDisplayFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Could not open file " << filename << endl;
        return false;
    }

    int numberOfPeriods = 0;
    if (!(inFile >> numberOfPeriods) || numberOfPeriods <= 0) {
        cout << "Error: Invalid number of periods in " << filename << endl;
        return false;
    }

    const int NUM_DIVISIONS = 6;
    DivSales divisions[NUM_DIVISIONS] = {
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods)
    };

    DivSales::resetCorpSales();

    for (int div = 0; div < NUM_DIVISIONS; ++div) {
        for (int p = 0; p < numberOfPeriods; ++p) {
            if (!(inFile >> divisions[div][p]) || divisions[div][p] <= 0.0) {
                cout << "Error: Invalid or missing sales data for Division " << (div + 1) << endl;
                return false;
            }
        }
        divisions[div].addToCorpSales();
    }

    inFile.close();

    cout << "\n=== SALES REPORT: " << filename << " ===" << endl;
    cout << fixed << setprecision(2);

    for (int div = 0; div < NUM_DIVISIONS; ++div) {
        cout << "Division " << (div + 1) << ": ";
        for (int p = 0; p < numberOfPeriods; ++p) {
            cout << "$" << divisions[div][p] << "  ";
        }
        cout << "| Total: $" << divisions[div].getTotalSales() << endl;
    }

    cout << "Total Corporate Sales: $" << DivSales::getCorpSales() << endl;
    return true;
}

int main() {
    loadAndDisplayFile("Corporate_Sales_Quarterly_Test_Data.txt");
    loadAndDisplayFile("Corporate_Sales_Monthly_Test_Data.txt");
    return 0;
}

void runClassTests() {
    cout << "\n=== RULE OF THREE & OPERATOR[] TESTS ===" << endl;
    cout << fixed << setprecision(2);

    DivSales::resetCorpSales();
    DivSales orig(3);
    orig[0] = 1000.00;
    orig[1] = 2000.00;
    orig[2] = 3000.00;
    orig.addToCorpSales();

    
    DivSales copyObj(orig);
    copyObj[0] = 9999.00;
    cout << "Copy Constructor -> Original[0]: $" << orig[0]
        << " | Copy[0]: $" << copyObj[0] << endl;

   
    DivSales assignObj(1);
    assignObj = orig;
    assignObj[1] = 8888.00;
    cout << "Copy Assignment  -> Original[1]: $" << orig[1]
        << " | Assigned[1]: $" << assignObj[1] << endl;

    assignObj = assignObj;
    cout << "Self-Assignment  -> Assigned[0]: $" << assignObj[0] << endl;

   
    cout << "Corporate Total after copies: $" << DivSales::getCorpSales() << endl;

    try {
        cout << orig[5] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Bounds Check Caught: " << e.what() << endl;
    }
}