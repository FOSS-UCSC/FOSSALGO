const sleep = (time) => new Promise((res) => setTimeout(res, time * 1000));
const sleepSort = async (arr) => {
  const response = [];
  await Promise.all(
    arr.map(async (element) => {
      await sleep(element);
      response.push(element);
    })
  );
};
// Example
sleepSort([9, 1, 2, 3, 5, 4, 7]);
