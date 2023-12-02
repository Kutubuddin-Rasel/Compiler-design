#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <set>
using namespace std;

int main() {
    ifstream input_file("sample.cpp");
    if (!input_file.is_open()) {
        cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    string line;
    string code;

    // Read the content of the file into a single string
    while (getline(input_file, line)) {
        code += line + "\n";
    }

    // Define regular expressions 
    regex function_regex("\\b[a-zA-Z_]\\w*\\s+([a-zA-Z_]\\w*)\\([^)]*\\)\\s*\\{");
    regex operator_regex("[\\+\\-\\*\\/=]");

    set<string> uniqueOperators;
    
    set<string> uniqueFunctions;  

    // Tokenize the code using regular expressions for functions
    sregex_iterator it(code.begin(), code.end(), function_regex);
    sregex_iterator end;
    while (it != end  ) {
        smatch match = *it;
        if(match.str()!="int main(){")
        {
            uniqueFunctions.insert(match[1].str());
        }
        ++it;
    }
   it = sregex_iterator(code.begin(), code.end(), operator_regex);
    while (it != end) {
        std::smatch match = *it;
        uniqueOperators.insert(match.str());
        ++it;
    }

    // Display 
     int count=1;
    for (const string& function : uniqueFunctions) {   
        cout <<"Function-"<<count<<": "<<function<<endl;
         count++;
    }
    cout <<"Total number of the user defined function: "<<count-1<<endl;
    
    int operatorCount = 1;
     for (const string& op : uniqueOperators) {
        cout << "Operator-" << operatorCount++ << ": ";
        switch (op[0]) {
            case '+':
                cout << "addition";
                break;
            case '-':
                cout << "subtraction";
                break;
            case '*':
                cout << "multiplication";
                break;
            case '/':
                cout << "division";
                break;
            case '=':
                cout << "assignment";
                break;  
        }
        cout << endl;
    }
   cout <<"Total number of the operators: "<<operatorCount-1<<endl;

    input_file.close();

    return 0;
}
