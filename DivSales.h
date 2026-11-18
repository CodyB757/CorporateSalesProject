#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales {
private:
    double* sales;
    int numberOfPeriods;
    static double totalCorpSales;

public:
    DivSales(int numberOfPeriods = 1);
    ~DivSales();
    DivSales(const DivSales& other);
    DivSales& operator=(const DivSales& other);

    double& operator[](int index);
    const double& operator[](int index) const;

    int getNumberOfPeriods() const;
    double getTotalSales() const;

    void addToCorpSales() const;
    static double getCorpSales();
    static void resetCorpSales();
};

#endif