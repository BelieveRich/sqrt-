#include <iostream>
#include <cstdint>

// Date: 2018/12/22
// Arthur: Richard Chen

using namespace std;

// Int type definition
#define int32 int32_t
#define uint8 uint8_t
#define uint16 uint16_t

// Forward declaration
float sqrt(int);

// Main entry function
int main()
{
restart:
	uint16 input;
	cout << "sqrt input: ";
    cin >> input;
	
	float result = sqrt(input);
	printf("result = %d\n", (uint16)result);

	goto restart;
	return 0;
}

float sqrt(int input)
{
	 printf("\n Taking sqrt of %d ...", input);
	 // Do binary search
	 // range: 0 to max = input
	 // goal is to find the biggest number not exceeding input
	 // Binary search needs to have upper bound and lower bound
	 // next to each other
	 int upbound=input, lowbound=0;
	 int med = 0;
	 int medsquare = 0;

	 do {
	 	med = (upbound+lowbound)/2;
	 	medsquare = med*med;
	 	if (medsquare == input || lowbound == upbound)
	 	{
			return med;
	 	} 
		else {
			if (medsquare > input){
				if (upbound != med)
				{
					upbound = med;
				} else {
					med -=1;
					break;
				}
	 		} else {
				if (lowbound != med){
					// medsquare < input, need bigger med
					lowbound = med;
				} else {
					break;
				}
	 		}
		}
		printf("low =%d, high=%d, med=%d, med^2=%d\n", lowbound, upbound,med,medsquare);
	 } while(1);
	return med;
}
