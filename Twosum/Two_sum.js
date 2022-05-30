
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

const twoSum = function (nums, target) {
  let hash = {};
  for (let i = 0; i < nums.length; i++) {
    const j = target - nums[i];
    if (typeof (hash[j]) !== 'undefined') {
      return [hash[j], i];
    }
    hash[nums[i]] = i;
  }
  return [];
};
