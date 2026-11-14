#include <iostream>
#include <fstream>
#include <sstream>
#include "Sorts.h"
using namespace std;

void load(DynArray<Result>& a, string file) {
    ifstream in(file);
    string line;
    while (getline(in, line)) {         
        if (line == "") continue;     
        stringstream ss(line);        
        Result r;
        string m;
        getline(ss, r.RegNo, ',');       
        getline(ss, r.name, ',');       
        getline(ss, r.course, ',');
        getline(ss, m);                  
        r.marks = stoi(m);               
        a.add(r);
    }
}

void save(DynArray<Result>& a, string file) {
    ofstream out(file);
    for (int i = 0; i < a.size(); i++) {
        Result r = a.raw()[i];
        out << r.RegNo << "," << r.name << "," << r.course << "," << r.marks << "\n";
    }
}


void display(DynArray<Result>& a) {
    for (int i = 0; i < a.size(); i++) {         
        Result r = a.raw()[i];                 
        cout << i + 1 << ". " << r.RegNo << " | " << r.name << " | "
             << r.course << " | " << r.marks << endl;
    }
}

int main() {
   DynArray<Result> a;
load(a, "results.txt");
cout << "Loaded " << a.size() << " records, capacity " << a.capacity() << endl;

cout << "\nBefore sorting:" << endl;
display(a);                                 

auto byReg = [](const Result& x, const Result& y) { return x.RegNo < y.RegNo; };
mergeSort(a.raw(), 0, a.size() - 1, byReg);

cout << "\nAfter sorting by registration number:" << endl;
display(a);

    save(a, "results.txt");
    return 0;
}