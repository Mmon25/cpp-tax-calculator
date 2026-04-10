STATE TAX FUNCTION (Conceptual Pseudocode)
------------------

```
//stateTaxFunc(state, income)
//double stateTaxOwed;

//switch(state)
  //case: stateName
        //if income <= X...
        //else if income <= Y...
        //return stateTaxOwed;

//case: stateName
      //return 0;

//case: stateName
      //if income <= X...
      //else if income <= Y...
      //return stateTaxOwed;
```






FED TAX FUNCTION (Conceptual Pseudocode)
----------------
```
//fedTaxFunc(status, income)
//double fedTaxOwed;

//switch(status):
  //case: married
    //if income <= X...
    //else if income <= Y...
    //return fedTaxOwed;

  //case: single
...
```





CITY TAX FUNCTION (Conceptual Pseudocode)
-----------------
```
//cityTaxFunc(city, income)
//double cityTaxOwed;

//switch(city)
  //case: cityName
      //cityTax = income * city tax rate
      //return cityTaxOwed;
...
```
  




MAIN FUNCTION (Conceptual Pseudocode)
-------------
```
// arrayofStates[SIZE] = {}
// arrayofCities[SIZE] = {}

//Request: Marital status, Annual income, State, and City

//Call state tax func - STATE and INCOME as args

//Call fed tax func - STATUS and INCOME as args

//Always call city tax func - CITY and INCOME as args
  //If not applicable, return 0;

//Output State tax, Federal tax, City tax (if applicable), Deductions, then total owed
```
