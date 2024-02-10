-------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    double amountPaid;
};

int main() {
    
    const int MIN_SENIOR_CITIZENS = 10;
    const int MAX_SENIOR_CITIZENS = 36;
    const int MIN_CARERS = 2;
    const int EXTRA_CARER_THRESHOLD = 24;

    
    int numSeniorCitizens;
    int numCarers = MIN_CARERS;
    double costPerSeniorCitizen = 0.0;
    double totalCost = 0.0;
    Person participants[MAX_SENIOR_CITIZENS + MIN_CARERS]; 

    
    cout << "Enter the number of senior citizens interested in the outing: ";
    cin >> numSeniorCitizens;

    if (numSeniorCitizens < MIN_SENIOR_CITIZENS || numSeniorCitizens > MAX_SENIOR_CITIZENS) {
        cout << "The outing cannot proceed with the given number of senior citizens." << endl;
        return 1;
    }

    if (numSeniorCitizens > EXTRA_CARER_THRESHOLD) {
        numCarers++;
    }

    
    costPerSeniorCitizen = 50.0; 
    totalCost = numSeniorCitizens * costPerSeniorCitizen;

    
    for (int i = 0; i < numSeniorCitizens; ++i) {
        cout << "Enter the name of senior citizen #" << i + 1 << ": ";
        cin >> participants[i].name;
        cout << "Enter the amount paid by " << participants[i].name << ": $";
        cin >> participants[i].amountPaid;
    }

    for (int i = numSeniorCitizens; i < numSeniorCitizens + numCarers; ++i) {
        participants[i].name = "Carer " + to_string(i - numSeniorCitizens + 1);
        participants[i].amountPaid = 0.0; 
    }

    
    double totalCollected = 0.0;
    for (int i = 0; i < numSeniorCitizens + numCarers; ++i) {
        totalCollected += participants[i].amountPaid;
    }
    cout << "Total amount collected: $" << totalCollected << endl;

   
    cout << "List of participants:" << endl;
    cout << "---------------------" << endl;
    cout << "Name\t\tAmount Paid" << endl;
    for (int i = 0; i < numSeniorCitizens + numCarers; ++i) {
        cout << participants[i].name << "\t\t$" << participants[i].amountPaid << endl;
    }

    return 0;
}

