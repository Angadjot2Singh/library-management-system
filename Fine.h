#ifndef FINE_H
#define FINE_H

#include <string>
#include <ctime>

using namespace std;

class Fine {
private:
    string fineID;
    string memberID;
    string circulationID;
    float amount;
    int overdueDays;
    string paymentStatus; // "Unpaid", "Partial", "Paid"
    time_t fineDate;
    time_t paymentDate;
    float paidAmount;

public:
    Fine();
    Fine(string fid, string mid, string cid, int days);
    
    // Getters
    string getFineID() const { return fineID; }
    string getMemberID() const { return memberID; }
    string getCirculationID() const { return circulationID; }
    float getAmount() const { return amount; }
    int getOverdueDays() const { return overdueDays; }
    string getPaymentStatus() const { return paymentStatus; }
    float getPaidAmount() const { return paidAmount; }
    float getOutstandingAmount() const { return amount - paidAmount; }
    
    // Fine Operations
    void calculateFine(int days);
    void makePayment(float payAmount);
    void waiverFine(float waiverAmount);
    
    // Display
    void display() const;
    string toCSV() const;
};

#endif