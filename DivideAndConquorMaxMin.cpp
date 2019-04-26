#include <stdio.h>

struct pair{
	int max = -3200;
	int min = 3200;
}; 

pair maxmin;

pair findMaxMin(int* arr, int x, int y) {
	pair mm;

	if (y - x <= 1) {
		if (arr[x] > arr[y]) {
			mm.max = arr[x];
			mm.min = arr[y];
		} else {
			mm.max = arr[y];
			mm.min = arr[x];
		}
		return mm;
	} else {
		pair mm1, mm2;
		mm1 = findMaxMin(arr, x, (x+y)/2);
		mm2 = findMaxMin(arr, (x+y)/2 + 1, y);
		
		mm1.max > mm2.max? 
			mm.max = mm1.max: mm.max = mm2.max;
		
		mm1.min < mm2.min? 
			mm.min = mm1.min: mm.min = mm2.min;
			
		return mm;	
	}
}

int main(){
	int arr[] = {15, 27, 16, 20, 29, 18, 57};
	
	maxmin = findMaxMin(arr, 0, 6);
	printf("Max: %5d, Min: %5d", maxmin.max, maxmin.min);	
}
