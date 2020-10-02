function binarySearch(items, value) {
	var firstIndex = 0,
		lastIndex = items.length - 1,
		middleIndex = Math.floor((lastIndex + firstIndex) / 2);

	while (firstIndex < lastIndex) {
		let middleIndex = Math.floor((lastIndex + firstIndex) / 2);
		if (items[middleIndex] === value) return middleIndex;
		else if (value < items[middleIndex]) {
			lastIndex = middleIndex - 1;
		}
		else if (value > items[middleIndex]) {
			firstIndex = middleIndex + 1;
		}
	}

	return items[middleIndex] !== value ? -1 : middleIndex;
}

function main() {
	let items = [
		1,
		2,
		3,
		4,
		5,
		7,
		8,
		9
	];
	binarySearch(items, 1);
	binarySearch(items, 5);
}

main();
