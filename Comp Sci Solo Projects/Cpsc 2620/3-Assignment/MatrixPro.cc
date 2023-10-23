//CMatrixPro class implementaion
#include "assert.h"
#include "MatrixPro.h"

//constructers
//default constructer
CMatrixPro::CMatrixPro(int n ){
  dimension = n;
  //allocate memory
  matrix = AllocateMatrixMemory(dimension);
}
//copy constructer todo
CMatrixPro::CMatrixPro(const CMatrixPro &M){
  dimension = M.dimension;
  matrix = AllocateMatrixMemory(dimension);
  //setting elements of old matrix to new copy
  CopyMatrix(M);
}
//destructor
CMatrixPro::~CMatrixPro(){
  DeallocateMatrixMemory(matrix, GetDimension());
}

//memory management
//alocating memory
int **CMatrixPro::AllocateMatrixMemory(unsigned int n){
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
void CMatrixPro::DeallocateMatrixMemory(int **M, unsigned int n){
  for (size_t i = 0; i < n; i++) {
    delete[] M[i];
  }
  delete[] M;
}

//modifing elements of matrix
//making matrix into an identy matrix
void CMatrixPro::MakeIdentity(){
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
//replacing elment at pos (i,j) with newint
int CMatrixPro::ReplaceElementAt(int i, int j, int newInt){
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
int CMatrixPro::SetElementAt(int i, int j){
  return ReplaceElementAt(i, j, 1);
}
//deleting element at pos(i,j)
int CMatrixPro::ClearElementAt(int i, int j){
  return ReplaceElementAt(i, j, 0);
}
//swaping elment at pos(i1,j1) with elemnt at pos(i2,j2)
void CMatrixPro::SwapElementsAt(int i1, int j1, int i2, int j2){
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
void CMatrixPro::ResizeMatrix(int newSize){
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
void CMatrixPro::CopyMatrix(const CMatrixPro &M){
  assert(GetDimension() == M.dimension);

  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      matrix[i][j] = M.matrix[i][j];
    }
  }
}

//operator implementaion //fix
//copy opperator
CMatrixPro& CMatrixPro::operator=(const CMatrixPro& M){
  if (this != &M) {
    //this->DeallocateMatrixMemory(this->matrix, this->dimension)
    this->dimension = M.dimension;
    this->AllocateMatrixMemory(this->dimension);
    //setting elements of old matrix to new copy
    this->CopyMatrix(M);
  }
  return *this;
}

//math opperators
//add matrix to martirx
CMatrixPro& CMatrixPro::operator+(const CMatrixPro &M){
  assert(this->dimension == M.dimension);
  //CMatrixPro differnceMatrix = *this;
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      this->matrix[i][j] += M.matrix[i][j];
    }
  }

  return *this;
}
//add constant to matrix elements
CMatrixPro& CMatrixPro::operator+(int x){
  //CMatrixPro differnceMatrix = *this;
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      this->matrix[i][j] += x;
    }
  }

  return *this;
}
//subtarct matrix form matrix
CMatrixPro& CMatrixPro::operator-(const CMatrixPro &M){
  assert(this->dimension == M.dimension);
  //CMatrixPro differnceMatrix = *this;
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      this->matrix[i][j] -= M.matrix[i][j];
    }
  }

  return *this;
}
//subtract constant to matrix elements
CMatrixPro& CMatrixPro::operator-(int x){
  //CMatrixPro differnceMatrix = *this;
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      this->matrix[i][j] -= x;
    }
  }

  return *this;
}
//multiply matrix by matrix
CMatrixPro& CMatrixPro::operator*(const CMatrixPro &M){
  assert(this->dimension == M.dimension);
  //CMatrixPro differnceMatrix = *this;
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      this->matrix[i][j] *= M.matrix[i][j];
    }
  }

  return *this;
}
//multiply matrix elements by constant
CMatrixPro& CMatrixPro::operator*(int x){
  //CMatrixPro differnceMatrix = *this;
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      this->matrix[i][j] *= x;
    }
  }

  return *this;
}

//comparison opperators //check
//check if matrix is bigger
bool CMatrixPro::operator>(const CMatrixPro &M){
  if (this->dimension > M.dimension) {
    return true;
  }
  else  if (this->dimension == M.dimension) {
    for (int i = 0; i < this->dimension; i++) {
      for (int j = 0; j < this->dimension; j++) {
        if (this->matrix[i][j] <= M.matrix[i][j]) {
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
//check if matrix is smaller
bool CMatrixPro::operator<(const CMatrixPro &M){
  if (this->dimension < M.dimension) {
    return true;
  }
  else  if (dimension == M.dimension) {
    for (int i = 0; i < this->dimension; i++) {
      for (int j = 0; j < this->dimension; j++) {
        if (this->matrix[i][j] >= M.matrix[i][j]) {
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
//check if matrix is equal
bool CMatrixPro::operator==(const CMatrixPro &M){
  if (this->dimension == M.dimension) {
    for (int i = 0; i < this->dimension; i++) {
      for (int j = 0; j < this->dimension; j++) {
        if (this->matrix[i][j] != M.matrix[i][j]) {
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

//input/output opperators
//reading input and setting it to elemnts fo matrix
istream& operator>>(istream& inputSource, const CMatrixPro &M){
  int inputValue =0;

  //running through matrix
  for (int i = 0; i < M.dimension; i++) {
    for (int j = 0; j < M.dimension; j++) {
      cout << "> Input matrix element at (" << i << ", " << j << "): ";
      inputSource >> inputValue;
      M.matrix[i][j] = inputValue;
    }
  }
  cout<< "> done reading input for matrix elements." << endl<<endl;
  return inputSource;
}
//outputing matrix
ostream& operator<<(ostream& outputSource, const CMatrixPro &M){

  outputSource <<"> here is a " << M.dimension << " x " << M.dimension << " matrix." << endl;
  for (int i = 0; i < M.dimension; i++) {
    outputSource << "> ";
    for (int j = 0; j < M.dimension; j++) {
      outputSource << M.matrix[i][j] << " ";
    }
    outputSource << endl;
  }
  outputSource << endl;
  return outputSource;
}

//other functions
//getting info about matrix
int CMatrixPro::GetDimension(void){
  return dimension;
}
//get element at pos (i,j) in matrix
int CMatrixPro::GetElementAt(int i, int j){
  return matrix[i][j];
}

//checks to see if all elements not on the diagonal are 0
bool CMatrixPro::IsDiagonal(){
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
bool CMatrixPro::IsIdentity(){
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
