#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream infile("input.txt");
    ofstream outfile("avg.txt");


    int pid, arrivalTime;
    double serviceTime, completionTime;
    double totalTAT = 0, totalWT = 0;
    int count = 0;


    while (infile >> pid >> arrivalTime >> serviceTime >> completionTime) {
        int tat = completionTime - arrivalTime;
        int wt = tat - serviceTime;

        totalTAT += tat;
        totalWT += wt;
        count++;
    }


    double averageTAT = totalTAT / count;
    double averageWT = totalWT / count;

    outfile << averageTAT << " ";
    outfile << averageWT << endl;

    outfile.close();
    infile.close();

    return 0;
}