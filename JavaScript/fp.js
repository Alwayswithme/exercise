function forEach(array, action) {
  for (var i = 0; i < array.length; i++)
    action(array[i]);
}

forEach(["Wampeter", "Foma", "Granfalloon"], print);

/* making use of an anonymous function */
function sum(numbers) {
  var total = 0;
  forEach(numbers, function (number) {
    total += number;
  });
  return total;
}

show(sum([1, 10, 100]));

/* Another useful type of higher-order function modifies the function
   value it is given */
function negate(func) {
  return function() {
    return !func.apply(null, arguments);
  };
}

var isNotNaN = negate(isNaN);
show(isNotNaN(NaN));

/* reduce */
function reduce(combine, base, array) {
  forEach(array, function (element) {
    base = combine(base, element);
  });
  return base;
}
function add(a, b) {
  return a + b;
}
function sum(numbers) {
  return reduce(add, 0, numbers);
}

/**
 * Write a function countZeroes, which takes an array of numbers
 * as its argument and returns the amount of zeroes that occur
 * in it, Use reduce.
 */
function countZeroes(array) {
  function counter(total, element) {
    return total + (element === 0 ? 1 : 0);
  }
  return reduce(counter, 0, array);
}

/**
 * Then, write the higher-order function count, which takes an array
 * and a test function as arguments, and returns the amount of elements
 * in the array for which the test function returned true. Re-implement
 * countZeroes using this function.
 */
function count(test, array) {
  return reduce(function(total, element) {
    return total + (test(element) ? 1 : 0);
  }, 0, array);
}

function equals(x) {
  return function(element) {return x === element;};
}

function countZeros(array) {
  return count(equals(0), array);
}

function isEven(num) {
  return (num & 1) != 1;
}
function pow(x, exp) {
  if (exp == 0)
    return 1;
  else if (isEven(n))
    return pow(x * x, n >> 1);
  else
    return pow(x * x, n >> 1) * x;
}
function loop(x, m, exp) {
  if (exp == 0)
    return 1;
  if (exp == 1)
    return m * x;
  if (!isEven(exp))
    m *= x;
  return loop(x * x, m, exp >> 1);
}
