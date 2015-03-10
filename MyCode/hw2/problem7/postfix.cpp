 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: postfix.cpp 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw2:
 * 
 *  	Write a "calculator" program to solve arithmetic expressions
 * 		written in post-fix notation. Postfix notation does not
 * 		suffer from having to perform parenthesized subexpressions 
 *		first, and does not need to parse an arbitrarily larg amount
 *		of the expression before performing an operation. In postfix
 *		notation, operators are written after their two operands.
 *
 * 		Write a function to parse and calculate the result of a 
 *		postfix expresion passed as a text string and main() program.
 * 		You must use your StackDbl class to help solve this problem. 
 *		
 * 		Special Note:
 *		Read in expressions from a postfix.in file and output results
 * 		to a postfix.out file. Please make both files exist when this
 *		program is compiled and run with the above specified names. 
 *    
 */

#include "../problem5/lib/stackdbl.h"
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

/* Function prototypes */
double calculate (string& expr, bool& success);
void calculateExpressionsFromFile(ifstream& infile, ofstream& outfile); 
double applyOperator(double op1, double op2, string optr);
bool isOperator(string str);


/* Function: main
 * ========================================================
 * This programs takes in as arguments as input and output
 * files and determines if a given expression written in 
 * postfix notation is valid. If yes, it outputs to computed
 * results. Otherwise, it simply outputs "invalid". The 
 * StackDbl class is employed to help solve this problem. 
 */
int main (int argc, char *argv[]) {
	
	/* Initialize file streams */
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1]);
	outfile.open(argv[2]); 

	/* Check file success */
	if (infile.fail() || outfile.fail()) {
		cout << "Problems with input files." << endl;
		return 0;
	}

	/* Evaluate the expressions from 
	 * the given input file and output results
	 * to the given output file.  
	 */
	calculateExpressionsFromFile(infile, outfile); 

	/* Close file streams */
	infile.close();
	outfile.close();

	return 0; 
}


/* Function: calculateExpressionsFromFile
 * Usage: calculateExpressionsFromFile(infile, outfile)
 * ========================================================
 * This function calculates expressions from the given input
 * file stream and outputs results to the given output file 
 * stream. If an expression is written in valid postfix
 * notation, then program will display the calculated answer.
 * Otherwise, the pgoram will display "invalid". Success of 
 * a postfix expression is tracked using the boolean success
 * variable. This variable is used in following function
 * calculate(). 
 */
void calculateExpressionsFromFile(ifstream& infile, ofstream& outfile) {
	string line = "";
	while (getline(infile, line)) {
		cout << "Line: " << line << endl;
		bool success = false;
		double result = calculate(line, success); 
		if (success) {
			outfile << result << endl;
		} else {
			outfile << "invalid" << endl;
		}
	}
}


/* Function: calculate
 * Usage: calculate(line, success);
 * ========================================================
 * This function checks if a given line is written correctly
 * in postfix notation using a StackDbl object from Problem 5.
 */
double calculate (string& expr, bool& success) {

	/* If the expression is of length 1 
	 * and is a digit, then we can prematurely 
	 * return that the expression is successfully
	 * written in postfix notation and return the 
	 * digit itself. 
	 */
	if (expr.length() == 1) {
		if (isdigit(expr[0])) {
			double result = (double) atoi(expr.c_str()); 
			success = true;
			return result;
		}
	}

	/* Otherwise, create an istringstream
	 * and store the given expression into 
	 * the stringstream. Use the stringstream
	 * to tokenize digits and operators of 
	 * of the given expression as strings and 
	 * convert as needed. 
	 */
	istringstream strm;
	strm.clear();
	strm.str(expr); 
	string temp = "";

	/* Declare the StackDbl object */
	StackDbl s;

	/* While there are strings to tokenize,
	 * store the next available string into 
	 * the variable temp.
	 */
	while (strm >> temp) {

		/* If temp is an operator,
		 * pop off the top two elements
		 * and compute the result. 
		 */
		if (isOperator(temp)) {
			
			/* First popped element is 
			 * second operand.
			 */
			double operand2 = s.top();
			s.pop();

			/* If there are no more elements 
			 * to pop, then return false because
			 * there aren't enough operands for
			 * for the operator. 
			 */
			if (s.empty()) {
				success = false;
				return -1;
			}

			/* Second popped element is
			 * first operand.
			 */
			double operand1 = s.top();
			s.pop();

			/* Compute the result applying both 
			 * operands and operator. 
			 */
			double result = applyOperator(operand1, operand2, temp);
			
			/* If the stack is empty and there
			 * are no more expressions or operators
			 * to be tokenized, then return true
			 * because all elements have been seen
			 * and evaluated.
			*/
			if (s.empty() && strm.eof()) {
				success = true;
				return result;
			}

			/* Otherwise, push the result back
			 * onto the stack for further evaluation.
			 */
			s.push(result); 

		} else {
			/* Otherwise, we assume that temp
			 * is a digit value, so we convert
			 * it to a double. Converting from 
			 * a character array to double allows
			 * us to account for negative values and
			 * multiple-digit numbers, i.e., 134.
			 * The stringstream will tokenize the 
			 * current expression up until but not
			 * including the next whitespace. 
			 */
			double operand = (double) atoi(temp.c_str()); 
			
			/* Push the operand onto the stack. */
			s.push(operand); 
		}
	}
	/* By default, return false if 
	 * the above loop has not already
	 * return true. This accounts for 
	 * expressions that contain only 
	 * digits and no operators. 
	 */
	success = false;
	return -1;
}


/* Function: applyOperator
 * Usage: applyOperator(operand1, operand2, operator);
 * ========================================================
 * Returns the result of an arithmetic operator applied on two 
 * specified operands. 
 */
double applyOperator(double op1, double op2, string optr) { 
	if (optr == "+") return op1 + op2; 
	if (optr == "-") return op1 - op2; 
	if (optr == "*") return op1 * op2; 
	if (optr == "/") return op1 / op2; 
	return -1; 
}


/* Function: isOperator
 * Usage: isOperator(str);
 * ========================================================
 * Returns if the given string is an arithmetic operator. 
 */
bool isOperator(string str) {
	return (str == "+" || str == "-" || str == "*" || str == "/"); 
}