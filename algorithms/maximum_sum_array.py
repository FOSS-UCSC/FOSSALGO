class max_sum_array(object):
   def maxSubArray(self, nums):

      num_array = [0 for i in range(len(nums))]
      num_array[0] = nums[0]
      for i in range(1,len(nums)):
         num_array[i] = max(num_array[i-1]+nums[i],nums[i])

      return max(num_array)
nums = [-13, -3, -25, -20,2,1,-3,7,-2,2,1,-5, -3, -16] 
ob1 = max_sum_array()
print(ob1.maxSubArray(nums))
