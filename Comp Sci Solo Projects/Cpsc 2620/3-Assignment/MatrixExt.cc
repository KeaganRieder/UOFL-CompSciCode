//CMatrixExt class implementaion
#include "assert.h"
#include "MatrixExt.h"

//constructers
//default constructer
CMatrixExt::CMatrixExt(int n ){//Add = 2
  dimension = n;
  //allocate memory
  matrix = AllocateMatrixMemory(dimension);
}
//copy constructer todo
CMatrixExt::CMatrixExt(const CMatrixExt &M){
  dimension = M.dimension;
  matrix = AllocateMatrixMemory(dimension);
  //setting elements of old matrix to new copy
  CopyMatrix(M);
}
//destructor
CMatrixExt::~CMatrixExt(){
  DeallocateMatrixMemory(matrix, GetDimension());
}

//memory management
//alocating memory
int **CMatrixExt::AllocateMatrixMemory(unsigned int n){
  int** newMatrix = new int*[n];
  for (size_t i = 0; i < n; i++) {
    newMatrix[i] = new int[n];
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      newMatrix[i][j] = 0;
    }
  }

  return newMatrix;
}
//deallocating memory
void CMatrixExt::DeallocateMatrixMemory(int **M, unsigned int n){
  for (size_t i = 0; i < n; i++) {
    delete[] M[i];
  }
  delete[] M;
}

//performing modifcations on class members
//replacing elment at pos (i,j) with newint
int CMatrixExt::ReplaceElementAt(int i, int j, int newInt){
  //checking to see if i or j are out of index
  assert(i >= 0);
  assert(i <= dimension);
  assert(j >= 0);
  assert(j <= dimension);

  int oldValue = GetElementAt(i,j);
  matrix[i][j] = newInt;
  return oldValue;
}
//set element at pos (i,j) to be 1
int CMatrixExt::SetElementAt(int i, int j){
  return ReplaceElementAt(i, j, 1);
}
//deleting element at pos(i,j)
int CMatrixExt::ClearElementAt(int i, int j){
  return ReplaceElementAt(i, j, 0);
}
//swaping elment at pos(i1,j1) with elemnt at pos(i2,j2)
void CMatrixExt::SwapElementsAt(int i1, int j1, int i2, int j2){
  //checking to see if i1 or j1 are out of index
  assert(i1 >= 0);
  assert(i1 <= dimension);
  assert(j1 >= 0);
  assert(j1 <= dimension);
  //checking to see if i2 or j2 are out of index
  assert(i2 >= 0);
  assert(i2 <= dimension);
  assert(j2 >= 0);
  assert(j2 <= dimension);
  //repalces value at i1,j1 and then sets value at i2,j2
  // to i1,j1 old value
  matrix[i2][j2] = ReplaceElementAt(i1, j1, matrix[i2][j2]);
}
//resizing matrix
void CMatrixExt::ResizeMatrix(int newSize){
  //checking for miss input, to see if newSize = dimension
    //cheacking to make sure that newSize != the matrixs current size.
    //doing this to avoid running unesccery process if there was a mis input
    if (newSize != GetDimension()) {
      //create a temp 2 dimensional array
      int **tempArray = new int*[newSize]; //rows
      for (int i = 0; i < newSize; i++) {
        tempArray[i] = new int[newSize];//coloums
      }

      //setting temps elments to be equal to that of matrix elemnts
      //but first checking to see if temp is smaller or bigger to
      //know how long for needs to run.
      //new array is bigger then then old
      if (newSize > GetDimension()) {
        //intaizling all elements to 0 and then setting them to elements
        //in old matrix
        for (int i = 0; i < newSize; i++) {
          for (int j = 0; j < newSize; j++) {
            tempArray[i][j] = 0 ;
          }
        }
        for (int i = 0; i < GetDimension(); i++) {//running rows
          for (int j = 0; j < GetDimension(); j++) {//running coloums
            tempArray[i][j] = GetElementAt(i,j);
          }
        }
        cout << "> the matrix's size has grown from " <<  GetDimension() << endl
        << "> to " << newSize << endl;
      }

      //new array is smaller then old array
      else{
        //intaizling all elements to 0 and then setting them to elements
        //in old matrix
        for (int i = 0; i < newSize; i++) {
          for (int j = 0; j < newSize; j++) {
            tempArray[i][j] = 0 ;
          }
        }
        for (int i = 0; i < newSize; i++) {//running rows
          for (int j = 0; j < newSize; j++) {//running coloums
            tempArray[i][j] = GetElementAt(i,j);
          }
        }
        cout << "> the matrix's size has Shrunk from " <<  GetDimension() << endl
        << "> to " << newSize << endl;
      }
      //setting matrix to new tempArray
      //and dimension to newSize
      //first dealcoating memory used by old matrix array
      DeallocateMatrixMemory(matrix,dimension);
      matrix = tempArray;
      dimension = newSize;
    }
    else{
      cout<<"> matrix is already size"<<newSize<<endl;
    }
}

//copying matrix object of a matrix class to another  // todo
void CMatrixExt::CopyMatrix(const CMatrixExt &M){
  assert(GetDimension() == M.dimension);

  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      matrix[i][j] = M.matrix[i][j];
    }
  }
}
//change all elements on diagoanl to 1, with rest being set to 0
void CMatrixExt::MakeIdentity(){
  //run the diagoal which is hwer i and j should equal
  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      if (i == j) {
        SetElementAt(i,j);
      }
      //if i and j don't equal means not on Diagonal
      //then set to 0
      else{
        ClearElementAt(i,j);
      }
    }
  }
}

//performing math on class
//doing math with other matrixs
//returns the CMatrixExe object resulting from the sum of two
//matrix objs
CMatrixExt CMatrixExt::AddMatrix(const CMatrixExt &M){
  assert(GetDimension() ==  M.dimension);
  CMatrixExt matrixSum(M);
  //CopyMatrix(M);

  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      matrixSum.matrix[i][j] += matrix[i][j];
    }
  }
  return matrixSum;
}
//returns the CMatrixExe object that is the differnce between
// two matrixs
CMatrixExt CMatrixExt::SubtractMatrix(const CMatrixExt &M){
  //int differnce = 0;
  assert(GetDimension() ==  M.dimension);
  CMatrixExt matrixDifference(M);

  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      matrixDifference.matrix[i][j] -= matrix[i][j];
    }
  }
  return matrixDifference;
}
//perfoming multiplication of two matrixs
CMatrixExt CMatrixExt::MultiplyMatrix(const CMatrixExt &M){
  //int product = 0;
  assert(GetDimension() ==  M.dimension);
  CMatrixExt matrixProduct(M);

  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      matrixProduct.matrix[i][j] *= matrix[i][j];
    }
  }
  return matrixProduct;
}

//need a check cause right now won't work
//doing math with constants check
//adding x to each element of the matrix
CMatrixExt CMatrixExt::AddMatrix(int x){
  //creating a temp matrix object
  CMatrixExt tempMatrix(GetDimension());
  //CopyMatrix(tempMatrix);

  //perfoming additsion operation on each element
  for (int i = 0; i < tempMatrix.GetDimension(); i++) {
    for (int j = 0; j < tempMatrix.GetDimension(); j++) {
      tempMatrix.ReplaceElementAt(i,j,matrix[i][j] + x);
    }
  }
  return tempMatrix;
}
//subtracting x from each element
CMatrixExt CMatrixExt::SubtractMatrix(int x){
  //creating a temp matrix object
  CMatrixExt tempMatrix(GetDimension());
  //setting elements of temp object to old object
  //CopyMatrix(tempMatrix);

  //perfoming additsion operation on each element
  for (int i = 0; i < tempMatrix.GetDimension(); i++) {
    for (int j = 0; j < tempMatrix.GetDimension(); j++) {
      tempMatrix.ReplaceElementAt(i,j,matrix[i][j] - x);
    }
  }
  return tempMatrix;
}
//multiply each element by x
CMatrixExt CMatrixExt::MultiplyMatrix(int x){

  //creating a temp matrix object
  CMatrixExt tempMatrix(GetDimension());

  //perfoming additsion operation on each element
  for (int i = 0; i < tempMatrix.GetDimension(); i++) {
    for (int j = 0; j < tempMatrix.GetDimension(); j++) {
      tempMatrix.ReplaceElementAt(i,j,matrix[i][j]* x);
    }
  }
  return tempMatrix;
}

//input/output
//taking input form user to for each element of
//matrix
void CMatrixExt::ReadMatrix(){
  int inputNum = 0;
  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      cout << "> Input matrix element at (" << i
      << ", " << j <<"): ";
      cin >> inputNum;
      matrix[i][j] = inputNum;
    }
  }
  cout<< "> done reading input for matrix elements." << endl<<endl;
}
//outputing matrix to user
void CMatrixExt::PrintMatrix(){
  cout <<"> here is a " << GetDimension() << " x " << GetDimension() << " matrix." << endl;
  for (int i = 0; i < GetDimension(); i++) {
    cout <<"> ";
    for (int j = 0; j < GetDimension(); j++) {
      cout<< GetElementAt(i,j) << " ";
    }
    cout<<endl;//make new row after coloum has finished for current row
  }
  cout<<endl;
}

//other
//getting info about matrix
int CMatrixExt::GetDimension(void){
  return dimension;
}
//get element at pos (i,j) in matrix
int CMatrixExt::GetElementAt(int i, int j){
  return matrix[i][j];
}

//checks to see if all elements not on the diagonal are 0
bool CMatrixExt::IsDiagonal(){
  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      if (i != j) {
        //ends the loop if on elemnt not on diagonal
        // isn't equal to 0
        if (GetElementAt(i,j) != 0) {
          return false;
        }
      }
    }
  }
  return true;
}
//checks to see if all element along the diagonal are ones
//and all other elements are 0
bool CMatrixExt::IsIdentity(){
//first checks to see if diagonal, meaning all element not
//on diagaonl are equal to 0
  if (IsDiagonal()) {
    for (int i = 0; i < GetDimension(); i++) {
      for (int j = 0; j < GetDimension(); j++) {
        if (i == j) {
          if (GetElementAt(i,j) != 1) {
            return false;
            break;
          }
        }
      }
    }
    return true;
  }
  //there is a element that isn't on the Diagona thats not 0
  //meaning it can't be an identity
  else{
    return false;
  }
}

//check
//checks if given matrix is bigger
bool CMatrixExt::IsBigger(const CMatrixExt &M){
  //see if they have the same dimenions
  if (GetDimension() == M.dimension) {
    for (int i = 0; i < GetDimension(); i++) {
      for (int j = 0; j < GetDimension(); j++) {
        if (GetElementAt(i,j) <= M.matrix[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  else if (GetDimension() > M.dimension) {
    return true;
  }
  //given matrix has smaller dimenions
  else{
    return false;
  }
}

//checks if given matrix is smaller
bool CMatrixExt::IsSmaller(const CMatrixExt &M){
  //see if they have the same dimenions
  if (GetDimension() == M.dimension) {
    for (int i = 0; i < GetDimension(); i++) {
      for (int j = 0; j < GetDimension(); j++) {
        if (GetElementAt(i,j) >= M.matrix[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  else if (GetDimension() < M.dimension) {
    return true;
  }
  //given matrix has smaller dimenions
  else{
    return false;
  }
}

//checks if given matrix is equal
bool CMatrixExt::IsEqual(const CMatrixExt &M){
  if (GetDimension() == M.dimension) {
    for (int i = 0; i < GetDimension(); i++) {
      for (int j = 0; j < GetDimension(); j++) {
        if (GetElementAt(i,j) != M.matrix[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  else{
    return false;
  }
}
