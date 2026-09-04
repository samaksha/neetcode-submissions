class Solution {
    public record Point(int r, int c){}

    private static Point convertToCordinates(int index, int m) {
        return new Point(index / m, index % m);
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int noOfRows = matrix.length;
        int noOfColumns = matrix[0].length;

        int left = 0, right = noOfRows*noOfColumns - 1;

        while(left <= right) {
            int mid = (left + right + 1) / 2;
            Point cordinates = convertToCordinates(mid, noOfColumns);

            int midValue = matrix[cordinates.r][cordinates.c];

            if(midValue == target) {
                return true;
            }
            else if(midValue < target) {
                left = mid+1;
            }
            else right = mid - 1;
        }

        return false;
    }
}
