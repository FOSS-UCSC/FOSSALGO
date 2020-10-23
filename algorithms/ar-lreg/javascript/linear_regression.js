// Using the Least Squares Method
function linearRegression (points) {
  const n = points.length;
  const x_points = points.map(([x, _]) => x);
  const y_points = points.map(([_, y]) => y);

  // Calculate the average of each axis for the input points
  const x_average = x_points.reduce((x_0, x_1) => x_0 + x_1, 0)/n;
  const y_average = y_points.reduce((y_0, y_1) => y_0 + y_1, 0)/n;

  // Calculate cross products
  const cross_product_xy = crossProduct(y_points, x_points) - n * y_average * x_average;
  const cross_product_xx = crossProduct(x_points, x_points) - n * x_average * x_average;

  // Calculate Regression Coefficients
  const slope = cross_product_xy / cross_product_xx;
  const offset = y_average - slope * x_average;

  return [slope, offset];
}

function crossProduct (array_0, array_1) {
  let result = 0;

  for (let i = 0; i < array_0.length; i++) {
    result += array_0[i] * array_1[i];
  }

  return result;
} 

function main () {
	let points = [
    [0, 1],
    [1, 3],
    [2, 2],
    [3, 5],
    [4, 7],
    [5, 8],
    [6, 8],
    [7, 9],
    [8, 10],
    [9, 12]
  ];
	const [slope, offset] = linearRegression(points);
	console.log(`Linear Regression result: y = ${slope} x + ${offset}`);
}

main();