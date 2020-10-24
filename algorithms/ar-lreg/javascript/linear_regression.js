function crossProduct (xArray, yArray) {
  let result = 0;

  for (let i = 0; i < xArray.length; i++) {
    result += xArray[i] * yArray[i];
  }

  return result;
} 

// Using the Least Squares Method
function linearRegression (points) {
  const n = points.length;
  const xPoints = points.map(([x, _]) => x);
  const yPoints = points.map(([_, y]) => y);

  // Calculate the average of each axis for the input points
  const xAverage = xPoints.reduce((x0, x1) => x0 + x1, 0)/n;
  const yAverage = yPoints.reduce((y0, y1) => y0 + y1, 0)/n;

  // Calculate cross products
  const crossProductXY = crossProduct(yPoints, xPoints) - n * yAverage * xAverage;
  const crossProductXX = crossProduct(xPoints, xPoints) - n * xAverage * xAverage;

  // Calculate Regression Coefficients
  const slope = crossProductXY / crossProductXX;
  const offset = yAverage - slope * xAverage;

  return [slope, offset];
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
  /* eslint-disable no-console */
  console.log(`Linear Regression result: y = ${slope} x + ${offset}`);
  /* eslint-enable no-console */
}

main();