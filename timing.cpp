
#include <iostream>
#include <fstream>
#include <chrono>      
#include <cstdlib>     
#include "Sorts.h"
using namespace std;

const int RUNS = 3;        
const int START_N = 1000;   
const int MAX_N = 64000; 


void makeData(Result a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].RegNo = "VU-" + to_string(rand() % 100000);
        a[i].name = "Student";
        a[i].course = "Course";
        a[i].marks = rand() % 101;
    }
}

int main() {
    srand(12345); 
    auto byMarks = [](const Result& x, const Result& y) { return x.marks < y.marks; };

    ofstream csv("timing.csv"); 
    csv << "n,insertion_ms,merge_ms,insertion_ratio,merge_ratio\n";

    cout << "n\tinsertion(ms)\tratio\tmerge(ms)\tratio" << endl;
    double prevIns = 0, prevMer = 0;

    for (int n = START_N; n <= MAX_N; n *= 2) {
        double insTotal = 0, merTotal = 0;

        for (int run = 0; run < RUNS; run++) {
            Result* master = new Result[n];
            makeData(master, n);
            Result* a = new Result[n];     
            Result* b = new Result[n];     
            for (int i = 0; i < n; i++) { a[i] = master[i]; b[i] = master[i]; }

            auto t1 = chrono::high_resolution_clock::now();
            insertionSort(a, n, byMarks);
            auto t2 = chrono::high_resolution_clock::now();
            mergeSort(b, 0, n - 1, byMarks);
            auto t3 = chrono::high_resolution_clock::now();

            insTotal += chrono::duration<double, milli>(t2 - t1).count();
            merTotal += chrono::duration<double, milli>(t3 - t2).count();

            delete[] master; delete[] a; delete[] b;
        }

        double ins = insTotal / RUNS;     
        double mer = merTotal / RUNS;
        double insRatio = prevIns > 0 ? ins / prevIns : 0;   
        double merRatio = prevMer > 0 ? mer / prevMer : 0;

        cout << n << "\t" << ins << "\t\t" << insRatio << "\t" << mer << "\t\t" << merRatio << endl;
        csv << n << "," << ins << "," << mer << "," << insRatio << "," << merRatio << "\n";
        prevIns = ins; prevMer = mer;
    }
    cout << "Saved timing.csv" << endl;
    return 0;
}