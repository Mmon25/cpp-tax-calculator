#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

/*==============
     STATES
==============*/
vector<string> States = { // List of all 50 U.S. states
  "Alabama",
  "Alaska",
  "Arizona",
  "Arkansas",
  "California",
  "Colorado",
  "Connecticut",
  "Delaware",
  "Florida",
  "Georgia",
  "Hawaii",
  "Idaho",
  "Illinois",
  "Indiana",
  "Iowa",
  "Kansas",
  "Kentucky",
  "Louisiana",
  "Maine",
  "Maryland",
  "Massachusetts",
  "Michigan",
  "Minnesota",
  "Mississippi",
  "Missouri",
  "Montana",
  "Nebraska",
  "Nevada",
  "New Hampshire",
  "New Jersey",
  "New Mexico",
  "New York",
  "North Carolina",
  "North Dakota",
  "Ohio",
  "Oklahoma",
  "Oregon",
  "Pennsylvania",
  "Rhode Island",
  "South Carolina",
  "South Dakota",
  "Tennessee",
  "Texas",
  "Utah",
  "Vermont",
  "Virginia",
  "Washington",
  "West Virginia",
  "Wisconsin",
  "Wyoming"
};




/*=========================================================
STRUCTURES FOR TAXBRACKET, FILING STATUS, & STATE TAX RATE
=========================================================*/
struct TaxBracket { // Represents one tax bracket
  int threshold; // Income limit where this tax rate applies
  double rate; // Tax percentage (in decimal form) for this tax bracket
};

struct FilingStatus { // Represents filing status (Single or Married)
  string status; // Name of filing status ("Single" or "Married")
  vector<TaxBracket> brackets; // List of tax brackets for this status
};

struct StateTaxRate { // Represents all tax data for a state
  string state; // Name of state
  vector<FilingStatus> filingTypes; // Different filing statuses for this state
};

                      
                      

/*======================
FEDERAL & STATE TAX DATA
======================*/
vector<FilingStatus> FederalTaxRates = { // Federal tax brackets grouped by filing status
  {
    "Single", // Tax brackets for single filers
    {{0, .10}, {11926, .12}, {48475, .22}, {103351, .24}, {197301, .32}, {250526, .35}, {626351, .37}}
  },
  {
    "Married", // Tax brackets for married filers
    {{0, .10}, {23850, .12}, {96950, .22}, {206700, .24}, {394600, .32}, {501505, .35}, {751600, .37}}
  }
};

vector<StateTaxRate> StateTaxRates = {  //State tax data: each state contains filing statuses, each with its own tax brackets
  {
    "Alabama", 
    {
      {"Single", {{500, .02}, {2500, .04}, {3000, .05}}}, // Tax brackets for single filers in Alabama
      {"Married", {{1000, .02}, {5000, .04}, {6000, .05}}} // Tax brackets for married filers in Alabama
                                                          //...
    },
  },
  {
    "Alaska", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "Arizona", 
    {
      {"Single", {{0, .025}}},
      {"Married", {{0, .025}}}
    },
  },
  {
    "Arkansas", 
    {
      {"Single", {{0, .02}, {4700, .039}}},
      {"Married", {{0, .02}, {4700, .039}}}
    }
  },
  {
    "California", 
    {
      { "Single", 
        {{11079, .01}, {26264, .02}, {41452, .04}, {57542, .06}, {72724, .08}, {371479, .093}, {445771, .103}, {742953, .113}, {1000000, .123}}
      },
      { "Married", 
        {{22158, .01}, {52528, .02}, {82904, .04}, {115084, .06}, {145448, .08}, {742958, .093}, {891542, .103}, {1485906, .113}, {2000000, .123}}
      }
    }
  },
  {
    "Colorado", 
    {
      {"Single", {{0, .044}}},
      {"Married", {{0, .044}}}
    },
  },
  {
    "Connecticut", 
    {
      {"Single", {{0, .02}, {10000, .045}, {50000, .055}, {100000, .06}, {200000, .065}, {250000, .069}, {500000, .0699}}},
      {"Married", {{0, .02}, {20000, .045}, {100000, .055}, {200000, .06}, {400000, .065}, {500000, .069}, {1000000, .0699}}}
    },
  },
  {
    "Delaware", 
    {
      {"Single", {{0, .00}, {2000, .021}, {5000, .038}, {10000, .047}, {20000, .051}, {25000, .0545}, {60000, .066}, {150000, .0675}, {250000, .0685}, {500000, .0695}}},
      {"Married", {{0, .00}, {2000, .021}, {5000, .038}, {10000, .047}, {20000, .051}, {25000, .0545}, {60000, .066}, {150000, .0675}, {250000, .0685}, {500000, .0695}}}
    },
  },
  {
    "Florida", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "Georgia", 
    {
      {"Single", {{0, .0499}}},
      {"Married", {{0, .0499}}}
    },
  },
  {
    "Hawaii", 
    {
      {"Single", {{0, .014}, {2400, .032}, {4800, .055}, {9600, .064}, {14400, .068}, {19200, .072}, {24000, .076}, {36000, .079}, {48000, .0825}, {150000, .09}, {175000, .10}, {200000, .11}}},
      {"Married", {{0, .014}, {4800, .032}, {9600, .055}, {19200, .064}, {28800, .068}, {38400, .072}, {48000, .076}, {72000, .079}, {96000, .0825}, {300000, .09}, {350000, .10}, {400000, .11}}}
    },
  },
  {
    "Idaho", 
    {
      {"Single", {{0, .053}}},
      {"Married", {{0, .053}}}
    },
  },
  {
    "Illinois", 
    {
      {"Single", {{0, .0495}}},
      {"Married", {{0, .0495}}}
    },
  },
  {
    "Indiana", 
    {
      {"Single", {{0, .0295}}},
      {"Married", {{0, .0295}}}
    },
  },
  {
    "Iowa", 
    {
      {"Single", {{0, .038}}},
      {"Married", {{0, .038}}}
    },
  },
  {
    "Kansas", 
    {
      {"Single", {{0, .052}, {23000, .0558}}},
      {"Married", {{0, .052}, {46000, .0558}}}
    },
  },
  {
    "Kentucky", 
    {
      {"Single", {{0, .035}}},
      {"Married", {{0, .035}}}
    },
  },
  {
    "Louisiana", 
    {
      {"Single", {{0, .03}}},
      {"Married", {{0, .03}}}
    },
  },
  {
    "Maine", 
    {
      {"Single", {{0, .058}, {27400, .0675}, {64850, .0715}}},
      {"Married", {{0, .058}, {54850, .0675}, {129750, .0715}}}
    },
  },
  {
    "Maryland", 
    {
      {"Single", {{0, .02}, {1000, .03}, {2000, .04}, {3000, .0475}, {100000, .05}, {125000, .0525}, {150000, .055}, {250000, .0575}, {500000, .0625}, {1000000, .065}}},
      {"Married", {{0, .02}, {1000, .03}, {2000, .04}, {3000, .0475}, {150000, .05}, {175000, .0525}, {225000, .055}, {300000, .0575}, {600000, .0625}, {1200000, .065}}}
    },
  },
  {
    "Massachusetts", 
    {
      {"Single", {{0, .05}, {1083150, .09}}},
      {"Married", {{0, .05}, {1083150, .09}}}
    },
  },
  {
    "Michigan", 
    {
      {"Single", {{0, .0425}}},
      {"Married", {{0, .0425}}}
    },
  },
  {
    "Minnesota", 
    {
      {"Single", {{0, .0535}, {32570, .068}, {106990, .0785}, {198630, .0985}}},
      {"Married", {{0, .0535}, {47620, .068}, {189180, .0785}, {330410, .0985}}}
    },
  },
  {
    "Mississippi", 
    {
      {"Single", {{0, .00}, {10000, .044}}},
      {"Married", {{0, .00}, {10000, .044}}}
    },
  },
  {
    "Missouri", 
    {
      {"Single", {{0, .00}, {1313, .02}, {2626, .025}, {3939, .03}, {5252, .035}, {6565, .04}, {7878, .045}, {9191, .047}}},
      {"Married", {{0, .00}, {1313, .02}, {2626, .025}, {3939, .03}, {5252, .035}, {6565, .04}, {7878, .045}, {9191, .047}}}
    },
  },
  {
    "Montana", 
    {
      {"Single", {{0, .047}, {21100, .059}}},
      {"Married", {{0, .047}, {42200, .059}}}
    },
  },
  {
    "Nebraska", 
    {
      {"Single", {{0, .0246}, {3500, .0351}, {22000, .0501}, {35000, .052}}},
      {"Married", {{0, .0246}, {7000, .0351}, {44000, .0501}, {70000, .052}}}
    },
  },
  {
    "Nevada", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "New Hampshire", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "New Jersey", 
    {
      {"Single", {{0, .014}, {20000, .0175}, {35000, .035}, {40000, .05525}, {75000, .0637}, {400000, .0897}, {1000000, .1075}}},
      {"Married", {{0, .014}, {20000, .0175}, {50000, .0245}, {70000, .035}, {80000, .05525}, {150000, .0637}, {400000, .0897}, {1000000, .1075}}}
    },
  },
  {
    "New Mexico", 
    {
      {"Single", {{0, .017}, {5500, .032}, {11000, .047}, {16000, .049}, {210000, .059}}},
      {"Married", {{0, .017}, {8000, .032}, {16000, .047}, {24000, .049}, {315000, .059}}}
    },
  },
  {
    "New York", 
    {
      {"Single", {{0, .04}, {8500, .045}, {11700, .0525}, {13900, .0585}, {21400, .0625}, {80650, .0685}, {215400, .0965}, {1077550, .103}, {5000000, .109}, {25000000, .114}}},
      {"Married", {{0, .04}, {17150, .045}, {23600, .0525}, {27900, .0585}, {43000, .0625}, {161550, .0685}, {323200, .0965}, {2155350, .103}, {5000000, .109}, {25000000, .114}}}
    },
  },
  {
    "North Carolina", 
    {
      {"Single", {{0, .0399}}},
      {"Married", {{0, .0399}}}
    },
  },
  {
    "North Dakota", 
    {
      {"Single", {{0, .00}, {48475, .0195}, {244825, .025}}},
      {"Married", {{0, .00}, {80975, .0195}, {298075, .025}}}
    },
  },
  {
    "Ohio", 
    {
      {"Single", {{0, .00}, {26050, .0275}, {100000, .03125}}},
      {"Married", {{0, .00}, {26050, .0275}, {100000, .03125}}}
    },
  },
  {
    "Oklahoma", 
    {
      {"Single", {{0, .0025}, {1000, .0075}, {2500, .0175}, {3750, .0275}, {4900, .0375}, {7200, .0475}}},
      {"Married", {{0, .0025}, {2000, .0075}, {5000, .0175}, {7500, .0275}, {9800, .0375}, {14400, .0475}}}
    },
  },
  {
    "Oregon", 
    {
      {"Single", {{0, .0475}, {4300, .0675}, {10750, .0875}, {125000, .099}}},
      {"Married", {{0, .0475}, {8600, .0675}, {21500, .0875}, {250000, .099}}}
    },
  },
  {
    "Pennsylvania", 
    {
      {"Single", {{0, .0307}}},
      {"Married", {{0, .0307}}}
    },
  },
  {
    "Rhode Island", 
    {
      {"Single", {{0, .0375}, {82050, .0475}, {186550, .0599}}},
      {"Married", {{0, .0375}, {82050, .0475}, {186550, .0599}}}
    },
  },
  {
    "South Carolina", 
    {
      {"Single", {{0, .00}, {3560, .03}, {17830, .06}}},
      {"Married", {{0, .00}, {3560, .03}, {17830, .06}}}
    },
  },
  {
    "South Dakota", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "Tennessee", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "Texas", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "Utah", 
    {
      {"Single", {{0, .045}}},
      {"Married", {{0, .045}}}
    },
  },
  {
    "Vermont", 
    {
      {"Single", {{0, .0335}, {47150, .066}, {114150, .076}, {220000, .0875}}},
      {"Married", {{0, .0335}, {78750, .066}, {190450, .076}, {284600, .0875}}}
    },
  },
  {
    "Virginia", 
    {
      {"Single", {{0, .02}, {3000, .03}, {5000, .05}, {17000, .0575}}},
      {"Married", {{0, .02}, {3000, .03}, {5000, .05}, {17000, .0575}}}
    },
  },
  {
    "Washington", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
  {
    "West Virginia", 
    {
      {"Single", {{0, .0211}, {10000, .0281}, {25000, .0316}, {40000, .0422}, {60000, .0458}}},
      {"Married", {{0, .0211}, {10000, .0281}, {25000, .0316}, {40000, .0422}, {60000, .0458}}}
    },
  },
  {
    "Wisconsin", 
    {
      {"Single", {{0, .035}, {14680, .044}, {50480, .053}, {323290, .0765}}},
      {"Married", {{0, .035}, {19580, .044}, {67300, .053}, {431060, .0765}}}
    },
  },
  {
    "Wyoming", 
    {
      {"Single", {{0, .00}}},
      {"Married", {{0, .00}}}
    },
  },
};




/*=======================
TAX CALCULATION FUNCTIONS
=======================*/
double calculateTax(double income, vector<TaxBracket> brackets) { // Tax calculation function w/ income & tax bracket as parameters
    double tax = 0.0; // Tax initialized to $0;

    for (int i = 0; i < brackets.size(); i++) { // Look through each tax bracket
        double lower = brackets[i].threshold; // Current bracket starting point holds upper limit for this bracket
        double upper; // Will hold upper limit for this bracket

        if (i == brackets.size() - 1) { // If current bracket is the last bracket
            upper = income; // Upper limit is the user's income
        } else {
            upper = brackets[i + 1].threshold; // Else, next bracket is upper limit
        }

        if (income > lower) { // If user's income reaches this bracket
            double taxable = min(income, upper) - lower; // Income only within this bracket is taxed
            tax += taxable * brackets[i].rate; // Add tax for this portion
        }
    }

    return tax; // Return total tax
}


double getFederalTax(double income, string filingStatus) { // Federal tax function w/ income and filing status as parameters
    for (auto status : FederalTaxRates) { // Loop through all federal filing statuses
        if (status.status == filingStatus) { // If there is a match with user's filing status
            return calculateTax(income, status.brackets); // Calculate tax using that bracket's set
        }
    }

    return 0.0; // Return 0 if no match found
}


double getStateTax(double income, string stateName, string filingStatus) { // State tax function (income, state name, and filing status as parameters)
    for (auto state : StateTaxRates) { // Loop through vector of states
        if (state.state == stateName) { // If there is a match with user's state
            for (auto status : state.filingTypes) { // Loop through state filing types
                if (status.status == filingStatus) { // Find matching filing status
                    return calculateTax(income, status.brackets); // Calculate tax for that state and filing status (if applicable)
                }
            }
        }
    }

    return 0.0; // Return 0 if no match found
}




/*===============
HELPER FUNCTIONS
===============*/
string normalizeTitle(string s) { // Capitalizes first letter of each word ("new york" -> "New York")
    bool capitalize = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            capitalize = true;
        } else if (capitalize) {
            s[i] = toupper(s[i]);
            capitalize = false;
        } else {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}



/*===========
MAIN FUNCTION
===========*/
int main() {
    double income;
    string filingStatus;
    string state;

    // Get income
    cout << "Please enter your gross annual income: $";
    while (!(cin >> income) || income < 0) {
        cout << "  Invalid input. Please enter a positive number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter your gross annual income: $";
    }

    cin.ignore(); // Clears leftover newline

    // Get filing status
    cout << "Please enter your filing status (Single/Married): ";
    getline(cin, filingStatus);
    filingStatus = normalizeTitle(filingStatus);
    while (filingStatus != "Single" && filingStatus != "Married") {
        cout << "  Invalid status. Please enter Single or Married." << endl;
        cout << "Please enter your filing status (Single/Married): ";
        getline(cin, filingStatus);
        filingStatus = normalizeTitle(filingStatus);
    }

    // Get state
    cout << "Please enter your state of residence: ";
    getline(cin, state);
    state = normalizeTitle(state);
    while (find(States.begin(), States.end(), state) == States.end()) {
        cout << "  Invalid state. Please enter a valid U.S. state." << endl;
        cout << "Please enter your state of residence: ";
        getline(cin, state);
        state = normalizeTitle(state);
    }

    // Calculate taxes
    double federal = getFederalTax(income, filingStatus);
    double stateTax = getStateTax(income, state, filingStatus);

    double totalTax = federal + stateTax;
    double takeHome = income - totalTax;

    // Output results
    cout << fixed << setprecision(2);
    /*------------------------------------------
                    TAX SUMMARY
    ------------------------------------------*/
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "              TAX SUMMARY                 " << endl;
    cout << "------------------------------------------" << endl;
    cout << "  Gross Income:       $" << income << endl;
    cout << "  Federal Tax:        $" << federal << endl; // Output Federal Tax owed
    cout << "  State Tax:          $" << stateTax << endl; // Output State Tax owed
    cout << "------------------------------------------" << endl;
    cout << "  Total Tax:          $" << totalTax << endl; // Output Total Taxes owed
    cout << "  Take-Home Pay:      $" << takeHome << endl;
    cout << "------------------------------------------" << endl;

    return 0; 
}
