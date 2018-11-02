int matrixFirstOne(){
    int matrix[5][4] = {{0,0,0,0},{0,0,1,1},{0,0,1,1},{0,0,0,1},{0,0,0,0}};
    int i=0, j=3;
    int firstOneIndex = -1;

    while(i<5 && j>=0){
        if(matrix[i][j] == 0) i++;
        else if(matrix[i][j] == 1){
            firstOneIndex = j;
            j--;
        }
    }
    return (firstOneIndex == -1)?firstOneIndex:4;
}