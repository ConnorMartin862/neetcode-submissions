func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	storage := make(map[rune]int)
	for _, val := range s {
		storage[val]++
	}

	for _, val := range t {
		if storage[val] == 0 {
			return false
		} else {
			storage[val]--
		}
	}
	return true
}
