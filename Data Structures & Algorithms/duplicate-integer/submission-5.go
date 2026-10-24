func hasDuplicate(nums []int) bool {
    storage := make(map[int]bool)
	for _, num := range nums {
		if storage[num] {
			return true
		}
		storage[num] = true
	}
	return false
}
