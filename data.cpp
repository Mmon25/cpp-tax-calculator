#include <string>
#include <vector>
#include <utility>

std::vector<std::string> states = {
  {"Alabama", "AL"},
  {"Alaska", "AK"},
  {"Arizona", "AZ"},
  {"Arkansas", "AR"},
  {"California", "CA"},
  {"Colorado", "CO"},
  {"Connecticut", "CT"},
  {"Delaware", "DE"},
  {"Florida", "FL"},
  {"Georgia", "GA"},
  {"Hawaii", "HI"},
  {"Idaho", "ID"},
  {"Illinois", "IL"},
  {"Indiana", "IN"},
  {"Iowa", "IA"},
  {"Kansas", "KS"},
  {"Kentucky", "KY"},
  {"Louisiana", "LA"},
  {"Maine", "ME"},
  {"Maryland", "MD"},
  {"Massachusetts", "MA"},
  {"Michigan", "MI"},
  {"Minnesota", "MN"},
  {"Mississippi", "MS"},
  {"Missouri", "MO"},
  {"Montana", "MT"},
  {"Nebraska", "NE"},
  {"Nevada", "NV"},
  {"New Hampshire", "NH"},
  {"New Jersey", "NJ"},
  {"New Mexico", "NM"},
  {"New York", "NY"},
  {"North Carolina", "NC"},
  {"North Dakota", "ND"},
  {"Ohio", "OH"},
  {"Oklahoma", "OK"},
  {"Oregon", "OR"},
  {"Pennsylvania", "PA"},
  {"Rhode Island", "RI"},
  {"South Carolina", "SC"},
  {"South Dakota", "SD"},
  {"Tennessee", "TN"},
  {"Texas", "TX"},
  {"Utah", "UT"},
  {"Vermont", "VT"},
  {"Virginia", "VA"},
  {"Washington D.C.", "DC"},
  {"Washington", "WA"},
  {"West Virginia", "WV"},
  {"Wisconsin", "WI"},
  {"Wyoming", "WY"}
};


// AL - Alabama
std::vector<std::vector<std::pair<double, double>>> AL = {
  { // Index 0: Single
    {500, .02}, {2500, .04}, {3000, .05},
  },
  { // Index 1: Married Filing Jointly
    {1000, .02}, {5000, .04}, {6000, .05}, // Thresholds are doubled for MFJ
  }
};

// AK - Alaska
std::vector<std::vector<std::pair<double, double>>> AK = {
  { // Index 0: Single
    {0, .00}, // Alaska has no state income tax
  },
  { // Index 1: Married Filing Jointly
    {0, .00},
  }
};

// AZ - Arizona
std::vector<std::vector<std::pair<double, double>>> AZ = {
  { // Index 0: Single
    {0, .025}, // Arizona uses a flat tax of 2.5%
  },
  { // Index 1: Married Filing Jointly
    {0, .025},
  }
}

// AR - Arkansas
std::vector<std::vector<std::pair<double, double>>> AR = {
  { // Index 0: Single
    {5000, .00}, {10000, .02}, {14700, .03}, {87000, .044}
  },
  { // Index 1: Married Filing Jointly
    {10000, .00}, {20000, .02}, {29400, .03}, {174000, .044}
  }
};

// CA - California 
std::vector<std::vector<std::pair<double, double>>> CA = {
  { // Index 0: Single
    {10412, .01}, {24684, .02}, {38959, .04}, {54081, .06}, {68350, .08}, {349137, .093}
  },
  { // Index 1: Married Filing Jointly
    {20824, .01}, {49368, .02}, {77918, .04}, {108162, .06}, {136700, .08}, {698274, .093}
  }
};

// CO - Colorado
std::vector<std::vector<std::pair<double, double>>> CO = {
  { // Index 0: Single
    {0, .044}
  },
  { // Index 1: Married Filing Jointly
    {0, .044}
  }
};

// CT - Connecticut
std::vector<std::vector<std::pair<double, double>>> CT = {
  { // Index 0: Single
    {10000, .02}, {50000, .045}, {100000, .055}, {200000, .06}, {250000, .065}, {500000, .069}, {500001, .0699}
  },
  { // Index 1: Married Filing Jointly
    {20000, .02}, {100000, .045}, {200000, .055}, {400000, .06}, {500000, .065}, {1000000, .069}, {1000001, .0699}
  }
};

// DE - Delaware
std::vector<std::vector<std::pair<double, double>>> DE = {
  { // Index 0: Single
    {2000, .00}, {5000, .022}, {10000, .039}, {20000, .048}, {25000, .052}, {60000, .0555}, {60001, .066}
  },
  { // Index 1: Married Filing Jointly
    {2000, .00}, {5000, .022}, {10000, .039}, {20000, .048}, {25000, .052}, {60000, .0555}, {60001, .066}
  }
};

// FL - Florida
std::vector<std::vector<std::pair<double, double>>> FL = {
  { // Index 0: Single
    {0, .00}, // Florida has no state income tax
  },
  { // Index 1: Married Filing Jointly
    {0, .00},
  }
};

// GA - Georgia
std::vector<std::vector<std::pair<double, double>>> GA = {
  { // Index 0: Single
    {0, .0549}      // Flat 5.49% (scheduled to decrease annually)
  },
  { // Index 1: Married Filing Jointly
    {0, .0549}
  }
};

// HI - Hawaii
std::vector<std::vector<std::pair<double, double>>> HI = {
  { // Index 0: Single
    {2400, .014}, {4800, .032}, {9600, .055}, {14400, .064}, {19200, .068}, 
    {24000, .072}, {36000, .076}, {48000, .079}, {150000, .0825}, {175000, .09}, {200000, .10}, {200001, .11}
  },
  { // Index 1: Married Filing Jointly
    {4800, .014}, {9600, .032}, {19200, .055}, {28800, .064}, {38400, .068}, 
    {48000, .072}, {72000, .076}, {96000, .079}, {300000, .0825}, {350000, .09}, {400000, .10}, {400001, .11}
  }
};

// ID - Idaho
std::vector<std::vector<std::pair<double, double>>> ID = {
  { // Index 0: Single
    {0, .05695}   
  },
  { // Index 1: Married Filing Jointly
    {0, .05695}
  }
};
