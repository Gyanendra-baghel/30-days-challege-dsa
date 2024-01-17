class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int[][] arr = new int[rows*cols][2];
        // variable to traverse through the array
        int cntr = 0;
        //  STEP-1
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                arr[cntr][0] = i;
                arr[cntr++][1] = j;
            } 
        }
        // STEP-2
        insertionSort(arr, rCenter, cCenter);
        return arr;
    }

    public void insertionSort(int[][] arr, int rC, int cC){
        for(int i = 0; i < arr.length - 1; i++){
            for(int j = i + 1; j > 0; j--){
                // STEP-3
                if((Math.abs(arr[j][0] - rC) + Math.abs(arr[j][1] - cC)) < (Math.abs(arr[j - 1][0] - rC) + Math.abs(arr[j - 1][1] - cC))){
                    swap(arr, j, j - 1);
                }
            }
        }
    }

    public void swap(int[][] arr, int n1, int n2){
        int[] temp = arr[n1];
        arr[n1] = arr[n2];
        arr[n2] = temp;
    }
}