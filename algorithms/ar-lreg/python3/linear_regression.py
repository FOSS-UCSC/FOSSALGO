import warnings

# A simple linear regression algorithm of the form y = a + bx.
# This function takes in a list of tuple of integers or floats.
# It will output estimators a and b from y = a + bx.


def linear_regression(dataset):
    validate_dataset(dataset)
    sumX = sumX2 = sumY = sumXY = 0
    dataset_length = len(dataset)
    for x, y in dataset:
        sumX = sumX + x
        sumX2 = sumX2 + (x * x)
        sumY = sumY + y
        sumXY = sumXY + (x * y)

    b = safe_division(
        (dataset_length * sumXY) - (sumX * sumY),
        (dataset_length * sumX2) - (sumX * sumX),
    )

    a = safe_division((sumY - b * sumX), dataset_length)
    return {"a": a, "b": b}


def safe_division(dividend, divisor):
    if divisor == 0:
        return 0.0
    else:
        return dividend / divisor


def validate_dataset(dataset, check_tuples=False):
    if not isinstance(dataset, list):
        raise Exception("Must provide a list.")
    else:
        warnings.warn("Dataset is a list, but was not checked for tuples.")

    if check_tuples:
        for element in dataset:
            if not isinstance(element, tuple):
                raise Exception("List must contain tuples.")
            if not isinstance(element, int) or not isinstance(element, float):
                raise Exception("List element is not float or int.")


def main():
    dataset = [
        (1.47, 52.21),
        (1.50, 53.12),
        (1.52, 54.48),
        (1.55, 55.84),
        (1.57, 57.20),
        (1.60, 58.57),
        (1.63, 59.93),
        (1.65, 61.29),
        (1.68, 63.11),
        (1.70, 64.47),
        (1.73, 66.28),
        (1.75, 68.10),
        (1.78, 69.92),
        (1.80, 72.19),
        (1.83, 74.46),
    ]
    result = linear_regression(dataset)
    print("** Result for y = a + bx linear regression **\n", result)


if __name__ == "__main__":
    main()
