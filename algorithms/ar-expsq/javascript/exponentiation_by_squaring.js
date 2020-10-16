function exponentiationSquaring(base, power) {
	let result = 1; //to store result
	while(power > 0) {  //when power is greater than 0
		if(power & 1) { //check if power is ODD
			result = result * base; //if power is ODD multiply by base
		}
		base = Math.pow(base, 2); //square the base 
		power >>= 1; //right-shift to make power half
	}
	return result;
}

function main() {
	let power = 2; 
	let base = 6;

	console.log(exponentiationSquaring(base, power));
}

main();