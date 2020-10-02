function binarySearch(items, value) {
	var firstIndex = 0,
		lastIndex = items.length - 1,
		middleIndex = Math.floor((lastIndex + firstIndex) / 2);

	while (items[middleIndex] !== value && firstIndex < lastIndex) {
		if (value < items[middleIndex]) {
			lastIndex = middleIndex - 1;
		}
		else if (value > items[middleIndex]) {
			firstIndex = middleIndex + 1;
		}
		middleIndex = Math.floor((lastIndex + firstIndex) / 2);
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
	binary_Search(items, 1);
	binary_Search(items, 5);
}

main();
