#include <stdio.h>
#include <stdlib.h>

void exponentiationSquaring(long base, long power) {
	long result = 1;

	while(power > 0) { //run loop till power is greater than zero
		if(power % 2 != 0) { //if power is ODD multiply result by base
			result = result * base;
		}
		base = base * base; //squaring base
		power /= 2; //reduce power to half
	}
	
	printf("%li\n", result);
}

int main() {
	long base = 3;
	long power = 2;

	exponentiationSquaring(base, power);
	return 0;
}
