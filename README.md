# Bignumber

## What's that ?
This is a naive attempt to implement a C++ library supporting addition and multiplication of unlimited integers*. 

## Simple usage

```cpp
#include "bignumber.h"

using T = unsigned char;
Number<T> a(StringConversion<T> ("1337"), b(StringConversion<T>("1")), c;

c = a + b;

NumberConversion<T> result(c);

std::cout << "Here is the result: " << c.getValue() << std::endl;
```


## Theory under

Each unlimited number is create by conversion of string to a vector of bit chunks. 

### Operations
Every operation is performed over these vectors. Therefore the time complexity depends on the length of vector, which depends on the count of
digits and the size of chunk word, according to this relation: [TODO - add image]

### Conversions
Conversion is the weakest part of chain in this library. It's rather expensive - for a string number with N digits, it takes at least log2(N) steps to convert a string
to chunks using division by two approach.

The same applies vice versa. To generate a string from chunks, it takes NxV steps, where N is the count of chunks and V is the width of a single chunk.

## Performace

To be done soon (hopefully).

## Footnote
\* everythig is limited, at least by the amount of available RAM
