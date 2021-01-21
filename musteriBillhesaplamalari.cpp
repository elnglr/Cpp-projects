#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>


using namespace std;

const int NUMBER_OF_CUSTOMERS=20;

//residential data:

const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;

//business data:

const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;


void calculateResident (int i, int premiumChanNum[], char customerType[], string customerID[], ofstream& outFile, double& totalResidential);
void calculateBusiness(int i, int premiumChanNum[], char customerType[], int basicServNum[], string customerID[],ofstream& outFile, double& totalBusiness);


int main()
{
    char customerType[NUMBER_OF_CUSTOMERS]; // either R,r or B,b before the ID
    string customerID[NUMBER_OF_CUSTOMERS]; // for example, 12345
    int premiumChanNum[NUMBER_OF_CUSTOMERS];
    int basicServNum[NUMBER_OF_CUSTOMERS];
    double averageRes;
    double averageBus;
    double totalResidential = 0.0;
    double totalBusiness = 0.0;
    ifstream inFile;
    ofstream outFile;

    
    inFile.open("customerData.txt");
    
    if (!inFile)
    {
        cout << "Error opening the input file." << endl;
        return 0;
    }
    
    outFile.open("billing.dat");
    
    if (!outFile)
    {
        cout << "Error opening the output file." << endl;
    }
    
    int numResidential = 0;
    int numBusiness= 0;
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    {
        inFile >> customerType[i];
        if (customerType[i] == 'r' || customerType[i] == 'R')
        {
            inFile >> customerID[i];
            inFile >> premiumChanNum[i];
            numResidential++;
            calculateResident(i, premiumChanNum,customerType,customerID, outFile, totalResidential);
        }
        else if (customerType[i] == 'b' || customerType[i] == 'B')
        {
            inFile >> customerID[i];
            inFile >> premiumChanNum[i];
            inFile >> basicServNum[i];
            numBusiness++;
            calculateBusiness(i, premiumChanNum,customerType,basicServNum,customerID,outFile, totalBusiness);
        }
        else
        {
            cout << "Error." << endl;
        }
    }
    averageRes = totalResidential / numResidential;
    averageBus = totalBusiness / numBusiness;
    
    
    outFile << "The average of residential customers' billing: " << averageRes << endl;
    outFile << "The average of business customers' billing: " << averageBus << endl;
    
    inFile.close();
    outFile.close();
    
}

void calculateResident(int i, int premiumChanNum[], char customerType[], string customerID[], ofstream& outFile, double& totalResidential)
{
    outFile << fixed << showpoint << setprecision(2);
    double bAmount = 0;
    outFile << "Account number: " << setw(20) <<customerType[i] << customerID[i] <<setw(16) << endl<< endl;
    
    outFile << "Premium channel number: " << premiumChanNum[i] << endl;
    
    bAmount= RES_BILL_PROC_FEES + RES_BASIC_SERV_COST + (premiumChanNum[i] * RES_COST_PREM_CHANNEL);
    outFile << "Billing amount: $" << bAmount << endl << endl;
    
    totalResidential = totalResidential + bAmount;
}

void calculateBusiness(int i, int premiumChanNum[], char customerType[], int basicServNum[], string customerID[], ofstream& outFile, double& totalBusiness)
{
    outFile << fixed << showpoint << setprecision(2);
    double bAmount = 0;
    
    outFile << "Account number: " << customerType[i] << customerID[i] << endl;
    
    outFile << "Premium channel number: " << premiumChanNum[i] << endl;
    
    outFile << "Basic connection number: " << basicServNum[i] << endl;
    
    if (basicServNum[i] <= 10)
    {
        bAmount = BUS_BILL_PROC_FEES
        + BUS_BASIC_SERV_COST
        + (premiumChanNum[i]) * BUS_COST_PREM_CHANNEL;
        
        outFile << "Billing amount: $" << bAmount << endl << endl;
    }
    else
    {
       bAmount = BUS_BILL_PROC_FEES
        + BUS_BASIC_SERV_COST
        + (basicServNum[i] - 10) * BUS_BASIC_CONN_COST
        + (premiumChanNum[i]) * BUS_COST_PREM_CHANNEL ;
        
        outFile << "Billing amount: $" << bAmount << endl << endl;
    }
    
    totalBusiness = totalBusiness + bAmount;
}

