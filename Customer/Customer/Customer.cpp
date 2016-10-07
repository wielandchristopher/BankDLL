// Customer.cpp : Defines the exported functions for the DLL application.
// Compile by using: cl /EHsc /DCUSTOMER_EXPORTS /LD Customer.cpp

#include "stdafx.h"
#include "stdio.h"
#include "Customer.h"

void print()
{
	printf("Das ist eine Textausgabe aus der DLL Customer");
}
