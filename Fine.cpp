#include "Fine.h"
#include <iostream>
#include <ctime>

using namespace std;

const float FINE_PER_DAY = 5.0; // Rs. 5 per day

Fine::Fine() : fineID(""), memberID(""), circulationID(""), amount(0), 
               overdueDays(0), paymentStatus("Unpaid"), fineDate(0), paymentDate(0), paidAmount(0) {}

Fine::Fine(string fid, string mid, string cid, int days)
    : fineID(fid), memberID(mid), circulationID(cid), overdueDays(days), 
      paymentStatus("Unpaid"), paidAmount(0) {
    fineDate = time(nullptr);
    paymentDate = 0;
    calculateFine(days);
}

void Fine::calculateFine(int days) {
    overdueDays = days;
    amount = days * FINE_PER_DAY;
    if (amount == 0) {
        paymentStatus = "Paid";
    }
}

void Fine::makePayment(float payAmount) {
    paidAmount += payAmount;
    if (paidAmount >= amount) {
        paymentStatus = "Paid";
        paymentDate = time(nullptr);
        paidAmount = amount;
    } else if (paidAmount > 0) {
        paymentStatus = "Partial";
    }
}

void Fine::waiverFine(float waiverAmount) {
    amount -= waiverAmount;
    if (paidAmount >= amount) {
        paymentStatus = "Paid";
        paymentDate = time(nullptr);
    }
}

void Fine::display() const {
    cout << "\n========== FINE DETAILS ==========" << endl;
    cout << "Fine ID: " << fineID << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "Circulation ID: " << circulationID << endl;
    cout << "Overdue Days: " << overdueDays << endl;
    cout << "Total Fine Amount: Rs. " << amount << endl;
    cout << "Paid Amount: Rs. " << paidAmount << endl;
    cout << "Outstanding: Rs. " << getOutstandingAmount() << endl;
    cout << "Payment Status: " << paymentStatus << endl;
    cout << "===================================" << endl;
}

string Fine::toCSV() const {
    return fineID + "," + memberID + "," + circulationID + "," 
           + to_string(amount) + "," + to_string(overdueDays) + "," 
           + paymentStatus + "," + to_string(fineDate) + "," 
           + to_string(paymentDate) + "," + to_string(paidAmount);
}