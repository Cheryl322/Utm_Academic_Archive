#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
using std::string;

class Customer {
public:
    Customer();
    void enterInformation();
    void selectPaymentMethod();
    void printReceipt(double &totalSales) ;
    void availability(int &numPremium, int &numTwin, int &numTriple, int &numFamily);
    int calcDays(string &checkInDate, string &checkOutDate);

private:
    string name;
    string email;
    string phone;
    int guests;
    bool loop;
    string checkInDate;
    string checkOutDate;
    int roomType;
    int numberOfRooms;
    int paymentMethod;
    int nights;
    double totalCost;
};

#endif