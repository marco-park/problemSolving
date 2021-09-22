class Solution {
    fun sumOfBeauties(nums: IntArray): Int {
        val prefix = IntArray(nums.size)
        val suffix = IntArray(nums.size)
        prefix[0] = nums.first()
        suffix[nums.size-1] = nums.last()

        for(i in 1 until nums.size)
            prefix[i] = maxOf(prefix[i-1], nums[i])

        for(i in nums.size-2 downTo 0)
            suffix[i] = minOf(suffix[i+1], nums[i])

        var ret = 0
        for(i in 1 .. nums.size-2) {
            if (nums[i] > prefix[i-1] && nums[i] < suffix[i+1]) ret+=2
            else if (nums[i] > nums[i-1] && nums[i] < nums[i+1]) ret+=1
        }

        return ret
    }
}