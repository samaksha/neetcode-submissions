class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int output;

        for(int i = 0;i < nums.length; i++) {
            if(minHeap.size() < k) {
                minHeap.add(nums[i]);
            }
            else if(minHeap.peek() < nums[i]) {
                minHeap.remove();
                minHeap.add(nums[i]);
            }
        }

        output = minHeap.poll();

        return output;
    }
}
