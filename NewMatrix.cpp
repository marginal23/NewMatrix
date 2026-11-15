/*********************************
* Автор:   Сатин Владимир        *
* Группа:  ПИ-261                *
* Задание: Обработка массивов    *
* Вариант: 10                    *
*********************************/

#include <iostream>

using namespace std;

int main() {
  const int maxSize = 20;
  const int maxMagnitude = 1000;
  int matrix[maxSize][maxSize];
  int originalMatrix[maxSize][maxSize];
  int rowCount;
  int columnCount;
  int maxColumnIndex;
  int minColumnIndex;
  int temporaryValue;
  int elementValue;
  bool isRowCountValid;
  bool isColumnCountValid;
  bool isElementValid;

  // Input: sizes first, then the elements row by row
  cout << "Rows and columns (1-" << maxSize << "): ";
  if (!(cin >> rowCount >> columnCount)) {
    cout << "INVALID" << endl;
    return 1;
  }

  isRowCountValid = rowCount >= 1 && rowCount <= maxSize;
  isColumnCountValid = columnCount >= 1 && columnCount <= maxSize;
  if (!isRowCountValid || !isColumnCountValid) {
    cout << "INVALID" << endl;
    return 1;
  }

  cout << "Matrix elements (from " << -maxMagnitude << " to " << maxMagnitude << "):" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (!(cin >> elementValue)) {
        cout << "INVALID" << endl;
        return 1;
      }

      isElementValid = elementValue >= -maxMagnitude && elementValue <= maxMagnitude;
      if (!isElementValid) {
        cout << "INVALID" << endl;
        return 1;
      }

      matrix[rowIndex][columnIndex] = elementValue;
    }
  }

  // Calculation: the source matrix is kept to print it next to the result
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      originalMatrix[rowIndex][columnIndex] = matrix[rowIndex][columnIndex];
    }
  }

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    maxColumnIndex = 0;
    minColumnIndex = 0;

    // Strict comparison keeps the first extreme element if values repeat
    for (int columnIndex = 1; columnIndex < columnCount; ++columnIndex) {
      if (matrix[rowIndex][columnIndex] > matrix[rowIndex][maxColumnIndex]) {
        maxColumnIndex = columnIndex;
      }
      if (matrix[rowIndex][columnIndex] < matrix[rowIndex][minColumnIndex]) {
        minColumnIndex = columnIndex;
      }
    }

    temporaryValue = matrix[rowIndex][maxColumnIndex];
    matrix[rowIndex][maxColumnIndex] = matrix[rowIndex][minColumnIndex];
    matrix[rowIndex][minColumnIndex] = temporaryValue;
  }

  // Output: both matrices, elements are separated by a tab
  cout << endl << "Original matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (columnIndex > 0) {
        cout << '\t';
      }

      cout << originalMatrix[rowIndex][columnIndex];
    }
    cout << endl;
  }

  cout << endl << "Modified matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (columnIndex > 0) {
        cout << '\t';
      }

      cout << matrix[rowIndex][columnIndex];
    }
    cout << endl;
  }

  return 0;
}
