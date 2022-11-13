#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int getWeight(string temp) {
	if (temp == "^") {
		return 3;
	}
	else if (temp == "*" || temp == "/" || temp == "%") {
    return 2;
  }
  else if (temp == "+" || temp == "-") {
    return 1;
  }
  else {
    return 0;
  }
}

string noSpace(string infix) {
  string fixed; 
  int a;
  for (a = 0; a < infix.length(); a++) {
    if (infix[a] == ' ') {
      continue;
    }
    else {
      fixed += infix[a];
    }
  }
  return fixed;
}

void infix2postfix(string infix, string postfix[], int size) {
  stack<string> optr;
  stack<string> oprnd;
	int weight;
	int i = 0;
	int k = 0;
  string otemp;
	string temp;

  do {
    temp = infix[i];

    if (temp == " ") {
      i++;
      continue;
    }

    if (temp == "(") {
      optr.push(temp);
      i++;
      continue;
    }

    if (temp == ")") {
      while (!optr.empty() && optr.top() != "(") {
        postfix[k++] = optr.top();
        optr.pop();
      }

      if (optr.top() == "(") {
				optr.pop();
			}
      i++;
      continue;
    }

    weight = getWeight(temp);
		if (weight == 0) {
      postfix[k++] = temp;
      //oprnd.push(temp);
		}

    else {
      /*if (!oprnd.empty()) {
        otemp += oprnd.top();
        oprnd.pop();
      }
      if (oprnd.empty()) {
        otemp == "";
      }*/
      if (optr.empty()) {
				optr.push(temp);
			}

      else {
				while (!optr.empty() && optr.top() != "(" && weight <= getWeight(optr.top())) {
					postfix[k++] = optr.top();
					optr.pop();

				}
				// push the current operator onto stack
				optr.push(temp);
			}
    }
    i++;
  } while (i < size);

  while (!optr.empty()) {
		postfix[k++] = optr.top();
		optr.pop();
	}
	k = 0;
}



int main() {
  string infix;
  char loop;


  cout << "\n\nInfix to Postfix/ Suffix Calculator" << endl;
  cout << "Input the infix expression :: ";
  getline(cin, infix);
  //infix = noSpace(infix);
  string postfixArray[infix.length()];


  cout << "\n<<--------------------------->>\n";
  cout << "Infix\t\t::\t" << infix << endl;
  infix2postfix(infix, postfixArray, infix.length());
  cout << "\nPostfix expression ::\t";
  int k;
  for (k = 0; k < sizeof(postfixArray); k++) {
    cout << postfixArray[k] << " ";
  }


  //cout << "<<--------------------------->>";

  return 0;
}