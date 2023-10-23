//name: Keagan Rieder

//program purpose:read in data from a bill to e computed and
//display the out onto the screen

#include "iostream"
#include "string"
#include "iomanip"
#include "fstream"

using namespace std;

const string FILE_NAME = "bill.in";
const double GST_MULTIPLE = 0.05; // value to multiply with each pretaxTotal to later add to totalGst
const int LINE_SPACEING = 20; //set spacing between lines to be modifed later

int main()
{
  ifstream inData;
  double itemQuantity, unitPrice, itemTotal;
  double totalGst, grandTotal;

  inData.open(FILE_NAME);

  //making stirng bill format
  cout << "Item Number--------Unit Price-----------Quantity---------Item Total \n\n";

  //processing first line in file
  inData >> unitPrice >> itemQuantity;

  itemTotal = itemQuantity * unitPrice;
  grandTotal = itemTotal;//setting grand total to the value of the first item Price
  //to later be added to total value

  //displaying data
  cout << setw(5) << right << "1" << setw(LINE_SPACEING) << right
  << setprecision(2)<< right << fixed << unitPrice
  << setw(LINE_SPACEING) << right << setprecision(0) << itemQuantity
  << setw(LINE_SPACEING) << left <<setprecision(2)<< right << fixed<< itemTotal
  << "\n\n";

  //processing second line in file

  inData >> unitPrice >> itemQuantity;

  itemTotal = itemQuantity * unitPrice;
  grandTotal = grandTotal + itemTotal;//adding up total value price

  //displaying data
  cout << setw(5) << right << "2" << setw(LINE_SPACEING) << right
  << setprecision(2)<< right << fixed << unitPrice
  << setw(LINE_SPACEING) << right << setprecision(0) << itemQuantity
  << setw(LINE_SPACEING) << left <<setprecision(2)<< right << fixed<< itemTotal
  << "\n\n";

  //processing thrid line in file
  inData >> unitPrice >> itemQuantity;

  itemTotal = itemQuantity * unitPrice;
  grandTotal = grandTotal + itemTotal;//adding up total value price

  //displaying data
  cout << setw(5) << right << "3" << setw(LINE_SPACEING) << right
  << setprecision(2)<< right << fixed << unitPrice
  << setw(LINE_SPACEING) << right << setprecision(0) << itemQuantity
  << setw(LINE_SPACEING) << left <<setprecision(2)<< right << fixed<< itemTotal
  << "\n\n";

  //caculating total cost
  totalGst = (grandTotal * GST_MULTIPLE);
  grandTotal = grandTotal + totalGst;

  //display data
  cout << setw(LINE_SPACEING + 20) << right << "GST" <<setw(LINE_SPACEING + 5) << right
  << setprecision(2)<< right << fixed << totalGst << "\n\n"
  << setw(LINE_SPACEING + 28) << right << "Grand Total" <<setw(LINE_SPACEING -2 ) << right
  <<setprecision(2)<< right << fixed << grandTotal;

  inData.close();

  return 0;
}
