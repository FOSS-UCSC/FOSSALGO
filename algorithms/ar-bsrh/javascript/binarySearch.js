const binarySearch = (array, target) => {
	// Define Start and End Index
	let startIndex = 0;
	let endIndex = array.length - 1;
	// While Start Index is less than or equal to End Index
	while (startIndex <= endIndex) {
		// Define Middle Index (This will change when comparing )
		let middleIndex = Math.floor((startIndex + endIndex) / 2);
		// Compare Middle Index with Target for match
		if (target === array[middleIndex]) {
			return console.log('Target was found at index ' + middleIndex);
		}
		// Search Right Side Of Array
		if (target > array[middleIndex]) {
			console.log('Searching the right side of Array');
			// Assign Start Index and increase the Index by 1 to narrow search
			startIndex = middleIndex + 1;
		}
		// Search Left Side Of Array
		if (target < array[middleIndex]) {
			// Assign End Index and increase the Index by 1 to narrow search
			console.log('Searching the left side of array');
			endIndex = middleIndex - 1;
		}
		else {
			// Not found in this iteration of the loop. Looping again.
			console.log('Not Found this loop iteration. Looping another iteration.');
		}
	}
	// If Target Is Not Found
	console.log('Target value not found in array');
};
