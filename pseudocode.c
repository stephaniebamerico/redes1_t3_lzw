






  1     Initialize table with single character strings
  2     P = first input character
  3     WHILE not end of input stream
  4          C = next input character
  5          IF P + C is in the string table
  6            P = P + C
  7          ELSE
  8            output the code for P
  9               add P + C to the string table
  10           P = C
  11         END WHILE
  12    output code for P



1    Initialize table with single character strings
2    OLD = first input code
3    output translation of OLD
4    WHILE not end of input stream
5        NEW = next input code
6        IF NEW is not in the string table
7               S = translation of OLD
8               S = S + C
9       ELSE
10              S = translation of NEW
11       output S
12       C = first character of S
13       OLD + C to the string table
14       OLD = NEW
15   END WHILE








Read OLD_CODE

output OLD_CODE

WHILE there are still input characters DO

Read NEW_CODE

STRING = get translation of NEW_CODE

output STRING

CHARACTER = first character in STRING

add OLD_CODE + CHARACTER to the translation table

OLD_CODE = NEW_CODE

END of WHILE

