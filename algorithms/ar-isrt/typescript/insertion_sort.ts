const swap = (arr: Array<number>, a: number, b: number) => {
	let temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
};
const insertionsort = (values: Array<number>) => {
	for (let i = 1; i < values.length; i++)
    {
        let j = i;
        while (j > 0 && values[j] <  values[j -1]) 
        {
            swap(values, j, j - 1);
            j--;
        }    
    }
	return values;
};
function main () {
	let input: number[] = [2, 3, 0, 4];
	let output: number[] = insertionsort(input);
	return output;
}

main();