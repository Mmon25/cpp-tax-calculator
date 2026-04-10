# Data Required
                

- Single filer federal tax bracket ranges AND rates
- Married filer federal tax bracket ranges AND rates
- Flat tax rate for each state for state tax
- Additional city tax if applicable





# TAX BRACKETS FOR SINGLE & MARRIED

Single Filer:

              Bracket 1:
                Range 0 - _____: %
                
              Bracket 2:
                Range _____ - _____: %
                
              Bracket 3:
                Range _____ - _____: %
                
              Bracket 4:
                Range _____+: %

Married Filing Jointly (Fed Tax):

              Bracket 1:
                Range 0 - _____: %
                
              Bracket 2:
                Range _____ - _____: %
                
              Bracket 3:
                Range _____ - _____: %
                
              Bracket 4:
                Range _____+: %





State tax rates
-
```
State 1:

State 2:

State 3:

...
```




City Tax Rates
-
```
City 1:

City 2:

City 3:

...
```





# FORMULAS

State Tax
-
```
income * state tax rate
```


Federal Tax (B = Bracket Number)
-
```
B1 = portion of income that lies within B1 range * B1 rate

B2 = portion of income that lies within B2 range * B2 rate

B3 = portion of income that lies within B3 range * B3 rate

B4 = portion of income that lies within B4 range * B4 rate

fedTax = B1 + B2 + B3 + B4

Note:
Only the income within each bracket’s range is taxed at that bracket’s rate.
```


City tax (if applicable)
-
```
income * cityrate
```


Total Tax
-
```
federalTax + stateTax + cityTax
```
