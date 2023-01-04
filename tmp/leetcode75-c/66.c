static int compare(const void *pa, const void *pb) {
    int *a = *(int **)pa;
    int *b = *(int **)pb;
    if (a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if (intervalsSize <= 1)
        return 0;
    
    int ret = 0;
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    for (int i = 1, curr = 0; i < intervalsSize; ++i) {
        if (intervals[curr][1] <= intervals[i][0]) // Non overlapping
            curr = i;
        else if (intervals[curr][1] > intervals[i][0] && intervals[curr][1] < intervals[i][1]) // Chain
            ret += 1; 
        else { // Outer overlapping
            curr = i;
            ret += 1;
        }
    }   
        
    return ret;
}

// Alternate solution
static int compare(const void* a, const void* b) {
	return (*(int**)a)[1] - (*(int**)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
	if (intervalsSize <= 1)
		return 0;

	qsort(intervals, intervalsSize, sizeof(int*), compare);
	int non_overlapping = 1;
	for (int i = 1, curr = 0; i < intervalsSize; ++i) {
		if (intervals[i][0] >= intervals[curr][1]) {
			curr = i;
			non_overlapping += 1;
		}
	}

	return intervalsSize - non_overlapping;
}
