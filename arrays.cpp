int main(){
    int sz = 10;
    int* arr = new int[sz];
    for(int i = 0 ; i < sz ; i++){ //expensive , linear use
        arr[i] = 0;
    }
    arr[8] = 100;
    arr[2] = 1026;

    //arr is too small
    int szBig = 1000;
    int* arr2 = new int[szBig];

    for(int i = 0 ; i < sz ; ++i){ 
        if (i < sz){
            arr2[i] = arr[i];
        }else{
            arr2[i] = 0;
        }
    }

    delete arr;
    delete arr2;

    //3x4 array
    //int** matrix[3][4];
    int rows = 3;
    int cols = 4;
    int** matrix = new int*[rows]; //outer array
    for (int row = 0 ; row < rows ; ++row){
        matrix[row] = new int[cols];
    }
    
    for (int i = 0; i < rows ; ++i){
        for (int j = 0 ; j < cols ; ++j){
            matrix[i][j] = 1;
        }
    }

    for (int i = 0; i < rows ; ++i){ //expensive , 4x , polynomial growth
        delete[] matrix[rows];
    }
    delete[] matrix;

    //3d arrays 8x , 4d arrays 16x

    return 1;
}